<?php
/**
 * @file
 * city2.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function city2_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-liv-main.
  $menus['menu-liv-main'] = array(
    'menu_name' => 'menu-liv-main',
    'title' => 'Liv Main',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Liv Main');

  return $menus;
}
