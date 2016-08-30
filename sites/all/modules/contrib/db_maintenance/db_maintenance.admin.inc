<?php

/**
 * @file
 * Module db_maintenance admin section.
 */

use Drupal\db_maintenance\Module\Hook\AdminHookHandler;

/**
 * Administration settings.
 *
 * Options: log each optimization, multi-select list of tables to optimize.
 *
 * @return array
 *   An array containing form items to place on the module settings page.
 */
function db_maintenance_admin_settings() {
  return AdminHookHandler::hookAdminSettings();
}
