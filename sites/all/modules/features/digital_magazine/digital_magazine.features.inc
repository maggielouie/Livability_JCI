<?php
/**
 * @file
 * digital_magazine.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function digital_magazine_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function digital_magazine_image_default_styles() {
  $styles = array();

  // Exported image style: digital_magazine.
  $styles['digital_magazine'] = array(
    'label' => 'Digital Magazine',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 216,
          'height' => 298,
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
function digital_magazine_node_info() {
  $items = array(
    'digital_magazine' => array(
      'name' => t('Digital Magazine'),
      'base' => 'node_content',
      'description' => t('Integration of third-party provider, digital versions of print publications'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('enter some random characters.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
