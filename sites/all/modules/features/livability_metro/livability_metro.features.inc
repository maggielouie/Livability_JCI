<?php
/**
 * @file
 * livability_metro.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livability_metro_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function livability_metro_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function livability_metro_node_info() {
  $items = array(
    'metro_area' => array(
      'name' => t('Metro Area'),
      'base' => 'node_content',
      'description' => t('A Metropolitan area imported from Census data.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
