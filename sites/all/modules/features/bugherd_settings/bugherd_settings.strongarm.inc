<?php
/**
 * @file
 * bugherd_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bugherd_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bugherd_disable_on_admin';
  $strongarm->value = 0;
  $export['bugherd_disable_on_admin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bugherd_project_key';
  $strongarm->value = 'rgykh1yhqjhzkfqyxccsgw';
  $export['bugherd_project_key'] = $strongarm;

  return $export;
}
