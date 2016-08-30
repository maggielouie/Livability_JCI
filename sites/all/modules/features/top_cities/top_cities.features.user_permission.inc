<?php
/**
 * @file
 * top_cities.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function top_cities_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create top_cities_list content'.
  $permissions['create top_cities_list content'] = array(
    'name' => 'create top_cities_list content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any top_cities_list content'.
  $permissions['delete any top_cities_list content'] = array(
    'name' => 'delete any top_cities_list content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own top_cities_list content'.
  $permissions['delete own top_cities_list content'] = array(
    'name' => 'delete own top_cities_list content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any top_cities_list content'.
  $permissions['edit any top_cities_list content'] = array(
    'name' => 'edit any top_cities_list content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own top_cities_list content'.
  $permissions['edit own top_cities_list content'] = array(
    'name' => 'edit own top_cities_list content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
