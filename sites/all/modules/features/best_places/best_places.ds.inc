<?php
/**
 * @file
 * best_places.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function best_places_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|best_places|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'best_places';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|best_places|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|best_places|related';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'best_places';
  $ds_fieldsetting->view_mode = 'related';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|best_places|related'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|best_places|search_results';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'best_places';
  $ds_fieldsetting->view_mode = 'search_results';
  $ds_fieldsetting->settings = array(
    'read_more_url' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'more',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'author' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'author',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' | ',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'ds_post_date_m_d_y_notime',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'date',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'search-snippet',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|best_places|search_results'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function best_places_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_list_item|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_list_item';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_city',
        1 => 'group_details',
        2 => 'field_quote_attribution',
        3 => 'field_image_single',
        4 => 'field_pull_quote',
        5 => 'field_bp_body',
        6 => 'field_professional_title',
        7 => 'field_source_notes',
        8 => 'group_pull_quote',
        9 => 'field_highlights',
        10 => 'group_meta',
        11 => '_add_existing_field',
      ),
      'hidden' => array(
        12 => 'redirect',
      ),
    ),
    'fields' => array(
      'field_city' => 'ds_content',
      'group_details' => 'ds_content',
      'field_quote_attribution' => 'ds_content',
      'field_image_single' => 'ds_content',
      'field_pull_quote' => 'ds_content',
      'field_bp_body' => 'ds_content',
      'field_professional_title' => 'ds_content',
      'field_source_notes' => 'ds_content',
      'group_pull_quote' => 'ds_content',
      'field_highlights' => 'ds_content',
      'group_meta' => 'ds_content',
      '_add_existing_field' => 'ds_content',
      'redirect' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_list_item|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|best_places|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'best_places';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_publish_on',
        2 => 'field_publish_now',
        3 => 'field_page_title',
        4 => 'field_meta_description',
        5 => 'field_list_item',
        6 => 'field_deck',
        7 => 'body',
        8 => 'field_bp_category',
        9 => 'field_source_notes',
        10 => 'field_pull_quote',
        11 => 'field_quote_attribution',
        12 => 'field_internal_category',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_publish_on' => 'ds_content',
      'field_publish_now' => 'ds_content',
      'field_page_title' => 'ds_content',
      'field_meta_description' => 'ds_content',
      'field_list_item' => 'ds_content',
      'field_deck' => 'ds_content',
      'body' => 'ds_content',
      'field_bp_category' => 'ds_content',
      'field_source_notes' => 'ds_content',
      'field_pull_quote' => 'ds_content',
      'field_quote_attribution' => 'ds_content',
      'field_internal_category' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|best_places|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|best_places|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'best_places';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'two_column__6633';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_year',
        1 => 'field_bp_category',
        2 => 'title',
        3 => 'field_short_description',
        4 => 'field_deck',
        5 => 'body',
        6 => 'field_list_item',
        7 => 'group_meta',
        8 => 'path',
        9 => '_add_existing_field',
        18 => 'field_page_title',
        19 => 'field_meta_description',
      ),
      'right' => array(
        10 => 'field_publish_on',
        11 => 'group_publishing_options',
        12 => 'field_publish_now',
        13 => 'field_internal_category',
        14 => 'field_source_notes',
        15 => 'field_image',
        16 => 'field_ranking_criteria',
        17 => 'group_pull_quote',
        20 => 'field_pull_quote',
        21 => 'field_quote_attribution',
        22 => 'field_professional_title',
      ),
    ),
    'fields' => array(
      'field_year' => 'left',
      'field_bp_category' => 'left',
      'title' => 'left',
      'field_short_description' => 'left',
      'field_deck' => 'left',
      'body' => 'left',
      'field_list_item' => 'left',
      'group_meta' => 'left',
      'path' => 'left',
      '_add_existing_field' => 'left',
      'field_publish_on' => 'right',
      'group_publishing_options' => 'right',
      'field_publish_now' => 'right',
      'field_internal_category' => 'right',
      'field_source_notes' => 'right',
      'field_image' => 'right',
      'field_ranking_criteria' => 'right',
      'group_pull_quote' => 'right',
      'field_page_title' => 'left',
      'field_meta_description' => 'left',
      'field_pull_quote' => 'right',
      'field_quote_attribution' => 'right',
      'field_professional_title' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|best_places|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|best_places|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'best_places';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_deck',
        1 => 'field_image',
      ),
      'left' => array(
        2 => 'field_ranking_criteria',
        3 => 'field_pull_quote',
        4 => 'field_quote_attribution',
        5 => 'group_pull_quote',
      ),
      'right' => array(
        6 => 'body',
      ),
    ),
    'fields' => array(
      'field_deck' => 'header',
      'field_image' => 'header',
      'field_ranking_criteria' => 'left',
      'field_pull_quote' => 'left',
      'field_quote_attribution' => 'left',
      'group_pull_quote' => 'left',
      'body' => 'right',
    ),
    'limit' => array(
      'field_image' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|best_places|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|best_places|related';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'best_places';
  $ds_layout->view_mode = 'related';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|best_places|related'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|best_places|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'best_places';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'search_results';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'title',
      ),
      'middle' => array(
        1 => 'field_image',
        2 => 'read_more_url',
        3 => 'body',
      ),
      'bottom' => array(
        4 => 'author',
        5 => 'post_date',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'field_image' => 'middle',
      'read_more_url' => 'middle',
      'body' => 'middle',
      'author' => 'bottom',
      'post_date' => 'bottom',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'left_above' => 'div',
      'right_above' => 'div',
      'middle' => 'div',
      'left_below' => 'div',
      'right_below' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|best_places|search_results'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|best_places|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'best_places';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'field_deck',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
      'field_deck' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|best_places|teaser'] = $ds_layout;

  return $export;
}
