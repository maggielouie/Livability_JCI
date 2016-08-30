<?php
/**
 * @file
 * livability_states.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livability_states_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
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
 * Implements hook_views_api().
 */
function livability_states_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function livability_states_node_info() {
  $items = array(
    'state' => array(
      'name' => t('State'),
      'base' => 'node_content',
      'description' => t('A geographic area encompassing Counties, Cities and Areas'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
