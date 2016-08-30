<?php
/**
 * @file
 * gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function gallery_image_default_styles() {
  $styles = array();

  // Exported image style: gallery.
  $styles['gallery'] = array(
    'label' => 'gallery',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 921,
          'height' => 536,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function gallery_node_info() {
  $items = array(
    'gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('A collection of images, relatable to a City or Area.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
