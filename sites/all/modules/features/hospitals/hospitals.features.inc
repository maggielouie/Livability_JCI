<?php
/**
 * @file
 * hospitals.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hospitals_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hospitals_node_info() {
  $items = array(
    'hospitals' => array(
      'name' => t('Hospitals'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
