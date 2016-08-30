<?php
/**
 * @file
 * livability_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function livability_article_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_image_default_styles().
 */
function livability_article_image_default_styles() {
  $styles = array();

  // Exported image style: city_slider.
  $styles['city_slider'] = array(
    'label' => 'City Slider',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 907,
          'height' => 500,
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
function livability_article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article - Standard'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
