<?php
/**
 * @file
 * livability_counties.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livability_counties_ctools_plugin_api($module = NULL, $api = NULL) {
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
function livability_counties_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function livability_counties_node_info() {
  $items = array(
    'county' => array(
      'name' => t('County'),
      'base' => 'node_content',
      'description' => t('A geographic area imported from the Census'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
