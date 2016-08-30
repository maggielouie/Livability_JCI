<?php
/**
 * @file
 * content_card.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function content_card_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|content_card';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'content_card';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_field',
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'image-icon',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article|content_card'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function content_card_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|content_card';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'content_card';
  $ds_layout->layout = 'content_cards';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'field_image',
      ),
      'category' => array(
        1 => 'field_category',
      ),
      'title' => array(
        2 => 'title',
      ),
      'summary' => array(
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'top',
      'field_category' => 'category',
      'title' => 'title',
      'body' => 'summary',
    ),
    'limit' => array(
      'field_image' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'category' => 'div',
      'title' => 'div',
      'summary' => 'div',
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
  $export['node|article|content_card'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function content_card_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'content_card';
  $ds_view_mode->label = 'Content Card';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['content_card'] = $ds_view_mode;

  return $export;
}
