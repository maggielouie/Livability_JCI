<?php
/**
 * @file
 * best_places.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function best_places_ctools_plugin_api($module = NULL, $api = NULL) {
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
function best_places_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function best_places_node_info() {
  $items = array(
    'best_places' => array(
      'name' => t('Best Places'),
      'base' => 'node_content',
      'description' => t('f.k.a. Top Tens, A ranked list of cities with areas for item descriptions'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
