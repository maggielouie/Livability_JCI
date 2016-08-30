<?php
/**
 * @file
 * city2.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function city2_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function city2_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function city2_image_default_styles() {
  $styles = array();

  // Exported image style: 898x505.
  $styles['898x505'] = array(
    'label' => '898x505',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 898,
          'height' => 505,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 898x505d.
  $styles['898x505d'] = array(
    'label' => '898x505d',
    'effects' => array(
      2 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 898,
            'height' => 505,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => -10,
      ),
    ),
  );

  return $styles;
}
