<?php

/**
 * @file
 * Processor for grouping support.
 */

/**
 * Processor for grouping up items on behalf of user defined fields.
 */
class SearchApiDenormalizedEntityGrouping extends SearchApiAbstractProcessor {

  /**
   * Check if the index is supports this feature.
   */
  public function supportsIndex(SearchApiIndex $index) {
    return $index->server() ? $index->server()->supportsFeature('search_api_grouping') : FALSE;
  }

  /**
   * Return the settings form for this processor.
   */
  public function configurationForm() {
    $form = parent::configurationForm();

    $supported_fields = $this->getSupportedFields();

    $form['fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Fields to collapse on'),
      '#options' => $supported_fields['field_options'],
      '#default_value' => $supported_fields['default_fields'],
      '#attributes' => array('class' => array('search-api-checkboxes-list')),
      '#description' => t('Choose the fields upon which to collapse the results into groups. Note that while selecting multiple fields is technicially supported, it may result in unexpected behaviour.'),
    );

    // Apache solr specific options.
    if ($this->index->server()->class == 'search_api_solr_service' || is_subclass_of($this->index->server()->class, 'search_api_solr_service')) {

      $default_sort = isset($this->options['group_sort']) ? $this->options['group_sort'] : '';
      $form['group_sort'] = array(
        '#type' => 'select',
        '#title' => t('Group sort'),
        '#options' => $supported_fields['field_sorts'],
        '#default_value' => $default_sort,
        '#description' => t('Choose the field by to sort within each group, the groups themselves will be sorted by the main query sorts.'),
      );

      $default_sort_direction = isset($this->options['group_sort_direction']) ? $this->options['group_sort_direction'] : '';
      $form['group_sort_direction'] = array(
        '#type' => 'select',
        '#title' => t('Group sort direction'),
        '#options' => array('asc' => t('Ascending'), 'desc' => t('Descending')),
        '#default_value' => $default_sort_direction,
      );

      $default_facetting = $this->getFacettingBehavior();
      $form['facetting'] = array(
        '#type' => 'select',
        '#title' => t('Facetting behavior'),
        '#description' => t('Decide how facets should be handled for grouped results. Should the facets be based on the results that will be displayed to the user, or based on the just displayed result from each group of results, or should they ignore grouping and be based on the un-grouped results?'),
        '#options' => array(
          'results' => t('Based on the displayed groups'),
          'first_document' => t('Based on the first result of each group'),
          'documents' => t('Based on the un-grouped results'),
        ),
        '#default_value' => $default_facetting,
      );

      $form['group_limit'] = array(
        '#type' => 'textfield',
        '#title' => t('Results per group'),
        '#description' => t('The number of results are limited per group. By default, 1 result per group is returned.'),
        '#default_value' => isset($this->options['group_limit']) ? $this->options['group_limit'] : 1,
        '#element_validate' => array('element_validate_integer_positive'),
        '#size' => 3,
      );

    }

    return $form;
  }

  /**
   * Determines the effective value for the "facetting" option.
   *
   * Depending on whether the legacy "truncate" option was explicitly set by the
   * user, this will choose the right default if the "facetting" option itself
   * is not present.
   *
   * @return string
   *   A legal value for this processor's "facetting" option.
   */
  protected function getFacettingBehavior() {
    // Apply legacy behavior of "truncate" option, if available.
    if (isset($this->options['facetting'])) {
      return $this->options['facetting'];
    }
    return !isset($this->options['truncate']) || $this->options['truncate'] ? 'first_document' : 'documents';
  }

  /**
   * Returns an array of supported fields to choose of.
   *
   * This function respects the server behind the index to provide only valid
   * fields.
   *
   * @return array
   *   An associative array with child arrays for the supported fields for each
   *   feature:
   *   array(
   *    'field_options' => array(),
   *    'field_sorts' => array(),
   *    'field' => array(),
   *   );
   */
  protected function getSupportedFields() {
    $this->index->server()->class;
    $fields = $this->index->getFields();
    $supported_fields = array(
      'field_options' => array(),
      'field_sorts' => array(
        '' => t('None'),
        'search_api_relevance' => t('Score/Relevance'),
      ),
      'default_fields' => array(),
    );

    // Adding random sorting, if server supports it.
    if ($this->index->server()->supportsFeature('search_api_random_sort')) {
      $supported_fields['field_sorts']['search_api_random'] = t('Random sorting');
    }

    if (isset($this->options['fields'])) {
      $supported_fields['default_fields'] = drupal_map_assoc(array_keys($this->options['fields']));
    }

    foreach ($fields as $name => $field) {
      // We can only rely on indexed fields.
      if ($field['indexed']) {
        // @TODO Add other supported servers.
        switch (TRUE) {
          // Apache solr server.
          case ($this->index->server()->class == 'search_api_solr_service' || is_subclass_of($this->index->server()->class, 'search_api_solr_service')):
            // Currently Solr is only compatible with single valued, indexed,
            // string/integer fields.
          default:
            if (!search_api_is_list_type($field['type'])) {
              if ($field['type'] == 'string' || $field['type'] == 'integer') {

                $conversion_msg = ($field['type'] != 'string') ? ' (' . t('Converted to string for indexing') . ')' : NULL;
                $supported_fields['field_options'][$name] = $field['name'] . $conversion_msg;
                if (!empty($default_fields[$name]) || (!isset($this->options['fields']) && $this->testField($name, $field))) {
                  $supported_fields['default_fields'][$name] = $name;
                }
              }
              // We can only sort according to single-valued fields.
              if ($field['type'] == search_api_extract_inner_type($field['type'])) {
                $supported_fields['field_sorts'][$name] = $field['name'];
              }
            }
            break;
        }
      }
    }
    return $supported_fields;
  }

  /**
   * Returns the fields to group on.
   *
   * @return array
   *   The list of fields to use for grouping.
   */
  public function getGroupingFields() {
    return isset($this->options['fields']) ? drupal_map_assoc(array_keys($this->options['fields'])) : array();
  }

  /**
   * Set the options so the server adapter can use the to implement grouping.
   */
  public function preprocessSearchQuery(SearchApiQuery $query) {
    $grouping_fields = $this->getGroupingFields();
    if (!empty($grouping_fields)) {
      // We move the options from our options array into where the Solr Service
      // is expecting them.
      $options = array(
        'use_grouping' => TRUE,
        'fields' => $grouping_fields,
        'group_sort' => array(),
        'group_limit' => isset($this->options['group_limit']) ? $this->options['group_limit'] : NULL,
      );
      if (!empty($this->options['group_sort'])) {
        $options['group_sort'][$this->options['group_sort']] = isset($this->options['group_sort_direction']) ? $this->options['group_sort_direction'] : 'asc';
      }
      switch ($this->getFacettingBehavior()) {
        case 'results':
          $options += array(
            'truncate' => FALSE,
            'group_facet' => TRUE,
          );
          break;

        case 'documents':
          $options += array(
            'truncate' => FALSE,
            'group_facet' => FALSE,
          );
          break;

        case 'first_document':
        default:
          $options += array(
            'truncate' => TRUE,
            'group_facet' => FALSE,
          );
      }
      $query->setOption('search_api_grouping', $options);
    }
  }
}
