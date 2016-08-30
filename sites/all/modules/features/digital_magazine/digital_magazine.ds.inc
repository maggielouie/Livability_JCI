<?php
/**
 * @file
 * digital_magazine.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function digital_magazine_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|digital_magazine|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'digital_magazine';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'two_column__6633';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_city',
        2 => 'field_description',
        3 => 'field_mag_pdf',
        6 => 'field_mag_cover',
      ),
      'hidden' => array(
        4 => 'path',
        8 => 'field_calamaeo_id',
        9 => 'xmlsitemap',
        10 => 'redirect',
        11 => '_add_existing_field',
      ),
      'right' => array(
        5 => 'field_internal_category',
        7 => 'field_image',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_city' => 'left',
      'field_description' => 'left',
      'field_mag_pdf' => 'left',
      'path' => 'hidden',
      'field_internal_category' => 'right',
      'field_mag_cover' => 'left',
      'field_image' => 'right',
      'field_calamaeo_id' => 'hidden',
      'xmlsitemap' => 'hidden',
      'redirect' => 'hidden',
      '_add_existing_field' => 'hidden',
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
    'layout_disable_css' => 0,
  );
  $export['node|digital_magazine|form'] = $ds_layout;

  return $export;
}
