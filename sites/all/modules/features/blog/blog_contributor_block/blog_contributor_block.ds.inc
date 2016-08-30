<?php
/**
 * @file
 * blog_contributor_block.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function blog_contributor_block_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'mini';
  $ds_view_mode->label = 'Mini';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['mini'] = $ds_view_mode;

  return $export;
}
