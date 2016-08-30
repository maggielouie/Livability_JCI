<?php
/**
 * @file
 * image_editor_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function image_editor_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageeditor_inline_access_check';
  $strongarm->value = '0';
  $export['imageeditor_inline_access_check'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageeditor_inline_aviary_feather_enabled';
  $strongarm->value = 1;
  $export['imageeditor_inline_aviary_feather_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageeditor_inline_aviary_feather_position';
  $strongarm->value = '11';
  $export['imageeditor_inline_aviary_feather_position'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageeditor_inline_file_ownership';
  $strongarm->value = '0';
  $export['imageeditor_inline_file_ownership'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageeditor_inline_icons_position';
  $strongarm->value = '1';
  $export['imageeditor_inline_icons_position'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageeditor_inline_ignore';
  $strongarm->value = '.admin-menu-icon, .stack-image, .imageeditor-inline-revert';
  $export['imageeditor_inline_ignore'] = $strongarm;

  return $export;
}
