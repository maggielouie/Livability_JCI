<?php
/**
 * @file
 * special_section.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function special_section_ctools_plugin_api($module = NULL, $api = NULL) {
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
function special_section_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function special_section_image_default_styles() {
  $styles = array();

  // Exported image style: special_edition_hero.
  $styles['special_edition_hero'] = array(
    'label' => 'Special Edition Hero',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 992,
          'height' => 315,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: sponsor_logo.
  $styles['sponsor_logo'] = array(
    'label' => 'Sponsor Logo',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
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
function special_section_node_info() {
  $items = array(
    'special_section' => array(
      'name' => t('Special Section'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'special_section_article' => array(
      'name' => t('Special Section Article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
