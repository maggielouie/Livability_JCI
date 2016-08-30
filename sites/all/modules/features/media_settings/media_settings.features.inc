<?php
/**
 * @file
 * media_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function media_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_type") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function media_settings_image_default_styles() {
  $styles = array();

  // Exported image style: 148px_wide.
  $styles['148px_wide'] = array(
    'label' => '148px wide',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 148,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: article_top.
  $styles['article_top'] = array(
    'label' => 'Article top',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 870,
          'height' => 506,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: place_banner_-_1400x453.
  $styles['place_banner_-_1400x453'] = array(
    'label' => 'Place Banner - 1400x453',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1400,
          'height' => 453,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
