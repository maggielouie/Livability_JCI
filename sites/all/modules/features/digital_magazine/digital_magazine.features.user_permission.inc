<?php
/**
 * @file
 * digital_magazine.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function digital_magazine_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create digital_magazine content'.
  $permissions['create digital_magazine content'] = array(
    'name' => 'create digital_magazine content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_description'.
  $permissions['create field_description'] = array(
    'name' => 'create field_description',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'delete any digital_magazine content'.
  $permissions['delete any digital_magazine content'] = array(
    'name' => 'delete any digital_magazine content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own digital_magazine content'.
  $permissions['delete own digital_magazine content'] = array(
    'name' => 'delete own digital_magazine content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any digital_magazine content'.
  $permissions['edit any digital_magazine content'] = array(
    'name' => 'edit any digital_magazine content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_description'.
  $permissions['edit field_description'] = array(
    'name' => 'edit field_description',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own digital_magazine content'.
  $permissions['edit own digital_magazine content'] = array(
    'name' => 'edit own digital_magazine content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_description'.
  $permissions['edit own field_description'] = array(
    'name' => 'edit own field_description',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_description'.
  $permissions['view field_description'] = array(
    'name' => 'view field_description',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_description'.
  $permissions['view own field_description'] = array(
    'name' => 'view own field_description',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
