<?php
/**
 * @file
 * data_tracking.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function data_tracking_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "data" && $api == "data_default") {
    return array("version" => "1");
  }
}
