<?php
/**
 * @file
 * global_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function global_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_vd';
  $strongarm->value = 1;
  $export['ds_extras_vd'] = $strongarm;

  return $export;
}
