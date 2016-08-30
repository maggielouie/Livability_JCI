<?php
/**
 * @file
 * hide_profile.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hide_profile_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_hide_profile'
  $field_bases['field_hide_profile'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hide_profile',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'public',
        1 => 'private',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 1,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
