<?php
/**
 * @file
 * liv_airports.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function liv_airports_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function liv_airports_node_info() {
  $items = array(
    'airports' => array(
      'name' => t('Airports'),
      'base' => 'node_content',
      'description' => t('Airports and their locations provided by openflights'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
