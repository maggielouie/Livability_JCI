<?php
/**
 * @file
 * liv_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function liv_blog_ctools_plugin_api($module = NULL, $api = NULL) {
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
function liv_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function liv_blog_image_default_styles() {
  $styles = array();

  // Exported image style: blog_feed.
  $styles['blog_feed'] = array(
    'label' => 'blog_feed',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function liv_blog_node_info() {
  $items = array(
    'blog_post' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => t('Posts for the blog'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => t('65 Maximum recommended characters - including spaces'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
