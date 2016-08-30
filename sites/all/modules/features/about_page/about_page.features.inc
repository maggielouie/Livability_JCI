<?php
/**
 * @file
 * about_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function about_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function about_page_node_info() {
  $items = array(
    'about_page' => array(
      'name' => t('About Page'),
      'base' => 'node_content',
      'description' => t('A special content type for the About page to make it conveniently editable while support a truly unique layout.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
