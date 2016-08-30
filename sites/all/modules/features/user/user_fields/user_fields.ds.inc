<?php
/**
 * @file
 * user_fields.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function user_fields_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'article_bottom';
  $ds_view_mode->label = 'Article Bottom';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['article_bottom'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'sidebar_block_bottom';
  $ds_view_mode->label = 'Sidebar block bottom';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['sidebar_block_bottom'] = $ds_view_mode;

  return $export;
}
