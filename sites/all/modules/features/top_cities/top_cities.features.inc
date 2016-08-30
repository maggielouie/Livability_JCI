<?php
/**
 * @file
 * top_cities.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function top_cities_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
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
function top_cities_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function top_cities_node_info() {
  $items = array(
    'top_cities_list' => array(
      'name' => t('Top Cities List'),
      'base' => 'node_content',
      'description' => t('A yearly list of top cities in a variety of different categories'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
