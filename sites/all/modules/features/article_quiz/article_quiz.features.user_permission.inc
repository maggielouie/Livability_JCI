<?php
/**
 * @file
 * article_quiz.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function article_quiz_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create article_quiz content'.
  $permissions['create article_quiz content'] = array(
    'name' => 'create article_quiz content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any article_quiz content'.
  $permissions['delete any article_quiz content'] = array(
    'name' => 'delete any article_quiz content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own article_quiz content'.
  $permissions['delete own article_quiz content'] = array(
    'name' => 'delete own article_quiz content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any article_quiz content'.
  $permissions['edit any article_quiz content'] = array(
    'name' => 'edit any article_quiz content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own article_quiz content'.
  $permissions['edit own article_quiz content'] = array(
    'name' => 'edit own article_quiz content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
