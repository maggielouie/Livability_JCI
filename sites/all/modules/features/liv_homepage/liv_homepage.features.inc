<?php
/**
 * @file
 * liv_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function liv_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function liv_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: home_slider.
  $styles['home_slider'] = array(
    'label' => 'Home Slider',
    'effects' => array(
      1 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 975,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
