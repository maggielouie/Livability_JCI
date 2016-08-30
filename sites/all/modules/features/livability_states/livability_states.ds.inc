<?php
/**
 * @file
 * livability_states.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function livability_states_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|state|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'state';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'cities_in_a_state' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'counties_in_a_state' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|state|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|state|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'state';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'cities_in_a_state' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'counties_in_a_state' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|state|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function livability_states_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cities_in_a_state';
  $ds_field->label = 'Cities in a State';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'state|*';
  $ds_field->properties = array(
    'block' => 'views|cities-block_1',
    'block_render' => '2',
  );
  $export['cities_in_a_state'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'counties_in_a_state';
  $ds_field->label = 'Counties in a State';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'state|*';
  $ds_field->properties = array(
    'block' => 'views|counties-block_1',
    'block_render' => '2',
  );
  $export['counties_in_a_state'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function livability_states_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|state|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'state';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'body',
        1 => 'field_population',
        2 => 'field_fips_state_code',
      ),
    ),
    'fields' => array(
      'body' => 'header',
      'field_population' => 'header',
      'field_fips_state_code' => 'header',
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
  $export['node|state|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|state|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'state';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_state_code',
        3 => 'counties_in_a_state',
      ),
      'header' => array(
        1 => 'field_population',
        2 => 'field_fips_state_code',
      ),
      'right' => array(
        4 => 'cities_in_a_state',
      ),
    ),
    'fields' => array(
      'field_state_code' => 'left',
      'field_population' => 'header',
      'field_fips_state_code' => 'header',
      'counties_in_a_state' => 'left',
      'cities_in_a_state' => 'right',
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
  $export['node|state|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|state|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'state';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_3col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'middle' => array(
        0 => 'counties_in_a_state',
      ),
      'header' => array(
        1 => 'title',
      ),
      'left' => array(
        2 => 'field_population',
      ),
      'right' => array(
        3 => 'cities_in_a_state',
        4 => 'field_fips_state_code',
      ),
    ),
    'fields' => array(
      'counties_in_a_state' => 'middle',
      'title' => 'header',
      'field_population' => 'left',
      'cities_in_a_state' => 'right',
      'field_fips_state_code' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|state|teaser'] = $ds_layout;

  return $export;
}
