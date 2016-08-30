<?php
/**
 * @file
 * livability_citys.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livability_citys_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function livability_citys_node_info() {
  $items = array(
    'city' => array(
      'name' => t('City'),
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
