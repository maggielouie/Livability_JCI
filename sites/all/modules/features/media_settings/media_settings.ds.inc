<?php
/**
 * @file
 * media_settings.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function media_settings_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'file',
        1 => 'field_description',
        2 => 'field_byline',
      ),
    ),
    'fields' => array(
      'file' => 'ds_content',
      'field_description' => 'ds_content',
      'field_byline' => 'ds_content',
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
  $export['file|image|default'] = $ds_layout;

  return $export;
}
