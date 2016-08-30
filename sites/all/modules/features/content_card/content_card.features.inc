<?php
/**
 * @file
 * content_card.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_card_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
