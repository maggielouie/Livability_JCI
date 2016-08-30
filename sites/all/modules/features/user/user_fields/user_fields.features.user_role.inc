<?php
/**
 * @file
 * user_fields.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function user_fields_user_default_roles() {
  $roles = array();

  // Exported role: Author.
  $roles['Author'] = array(
    'name' => 'Author',
    'weight' => 3,
  );

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 5,
  );

  // Exported role: Proof Reader.
  $roles['Proof Reader'] = array(
    'name' => 'Proof Reader',
    'weight' => 4,
  );

  return $roles;
}
