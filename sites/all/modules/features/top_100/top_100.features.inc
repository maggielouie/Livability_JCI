<?php
/**
 * @file
 * top_100.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function top_100_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function top_100_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function top_100_image_default_styles() {
  $styles = array();

  // Exported image style: 200x130.
  $styles['200x130'] = array(
    'label' => '200x130',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 325x216.
  $styles['325x216'] = array(
    'label' => '325x216',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 325,
          'height' => 216,
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
function top_100_node_info() {
  $items = array(
    'top_100' => array(
      'name' => t('Top 100'),
      'base' => 'node_content',
      'description' => t('A yearly list of top rated Cities (and areas).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
