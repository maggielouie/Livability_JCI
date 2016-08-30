<?php
/**
 * @file
 * global_search.ds_extras.inc
 */

/**
 * Implements hook_ds_vd_info().
 */
function global_search_ds_vd_info() {
  $export = array();

  $ds_vd = new stdClass();
  $ds_vd->api_version = 1;
  $ds_vd->vd = 'global_search-page';
  $ds_vd->label = 'Global_search: Page (Views template)';
  $export['global_search-page'] = $ds_vd;

  return $export;
}
