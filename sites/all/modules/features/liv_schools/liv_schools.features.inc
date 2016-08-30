<?php
/**
 * @file
 * liv_schools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function liv_schools_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function liv_schools_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function liv_schools_node_info() {
  $items = array(
    'school_districts' => array(
      'name' => t('School Districts'),
      'base' => 'node_content',
      'description' => t('Organizations that run a group of schools associated with a City or Area, imported'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'schools' => array(
      'name' => t('Schools'),
      'base' => 'node_content',
      'description' => t('An educational or learning facility  associated with a City or Area, imported'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
