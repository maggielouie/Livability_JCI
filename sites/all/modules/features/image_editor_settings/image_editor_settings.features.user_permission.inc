<?php
/**
 * @file
 * image_editor_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function image_editor_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer imageeditor'.
  $permissions['administer imageeditor'] = array(
    'name' => 'administer imageeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imageeditor',
  );

  // Exported permission: 'administer imageeditor_inline'.
  $permissions['administer imageeditor_inline'] = array(
    'name' => 'administer imageeditor_inline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imageeditor_inline',
  );

  // Exported permission: 'edit all images'.
  $permissions['edit all images'] = array(
    'name' => 'edit all images',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imageeditor_inline',
  );

  // Exported permission: 'edit own images'.
  $permissions['edit own images'] = array(
    'name' => 'edit own images',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imageeditor_inline',
  );

  // Exported permission: 'use imageeditor'.
  $permissions['use imageeditor'] = array(
    'name' => 'use imageeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imageeditor',
  );

  // Exported permission: 'use imageeditor_inline'.
  $permissions['use imageeditor_inline'] = array(
    'name' => 'use imageeditor_inline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imageeditor_inline',
  );

  return $permissions;
}
