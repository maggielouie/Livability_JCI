<?php
/**
 * @file
 * liv_airports.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function liv_airports_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_faa_code'
  $field_bases['field_faa_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faa_code',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 5,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
