<?php
/**
 * @file
 * media_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function media_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format photo_byline'.
  $permissions['use text format photo_byline'] = array(
    'name' => 'use text format photo_byline',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
