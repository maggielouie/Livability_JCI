<?php
/**
 * @file
 * date_formats.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function date_formats_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_m_d_y_notime';
  $strongarm->value = 'M d, Y';
  $export['date_format_m_d_y_notime'] = $strongarm;

  return $export;
}
