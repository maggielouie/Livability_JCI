<?php
/**
 * @file
 * global_search.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function global_search_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'content_type';
  $ds_field->label = 'Content Type';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<span class="guide">[node:type]</span>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['content_type'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'read_more_url';
  $ds_field->label = 'Read More URL';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php $alias = drupal_get_path_alias("node/".$entity->nid);print l(\'http://\'.$_SERVER[\'HTTP_HOST\'].\'/\'.$alias,$alias); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['read_more_url'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'suggested_entity';
  $ds_field->label = 'Suggested Entity';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'ds_views' => 'ds_views',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php print global_search_suggested_entity($entity); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['suggested_entity'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function global_search_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'ds_views|global_search-page|default';
  $ds_layout->entity_type = 'ds_views';
  $ds_layout->bundle = 'global_search-page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'header',
        2 => 'exposed',
        3 => 'suggested_entity',
        4 => 'empty',
        5 => 'rows',
        6 => 'footer',
        7 => 'pager',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'header' => 'ds_content',
      'exposed' => 'ds_content',
      'suggested_entity' => 'ds_content',
      'empty' => 'ds_content',
      'rows' => 'ds_content',
      'footer' => 'ds_content',
      'pager' => 'ds_content',
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
  $export['ds_views|global_search-page|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function global_search_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search_results';
  $ds_view_mode->label = 'Search Results';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search_results'] = $ds_view_mode;

  return $export;
}
