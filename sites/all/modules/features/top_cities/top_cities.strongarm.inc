<?php
/**
 * @file
 * top_cities.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function top_cities_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_top_cities_list';
  $strongarm->value = 0;
  $export['comment_anonymous_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_top_cities_list';
  $strongarm->value = 1;
  $export['comment_default_mode_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_top_cities_list';
  $strongarm->value = '50';
  $export['comment_default_per_page_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_top_cities_list';
  $strongarm->value = 1;
  $export['comment_form_location_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_top_cities_list';
  $strongarm->value = '1';
  $export['comment_preview_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_top_cities_list';
  $strongarm->value = 1;
  $export['comment_subject_field_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_top_cities_list';
  $strongarm->value = '0';
  $export['comment_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__top_cities_list';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'content_card' => array(
        'custom_settings' => FALSE,
      ),
      'featured' => array(
        'custom_settings' => FALSE,
      ),
      'marquee' => array(
        'custom_settings' => TRUE,
      ),
      'related' => array(
        'custom_settings' => FALSE,
      ),
      'tile' => array(
        'custom_settings' => TRUE,
      ),
      'blog_home' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'search_results' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '2',
        ),
        'xmlsitemap' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_top_cities_list';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_top_cities_list';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_top_cities_list';
  $strongarm->value = array();
  $export['node_options_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_top_cities_list';
  $strongarm->value = '1';
  $export['node_preview_top_cities_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_top_cities_list';
  $strongarm->value = 0;
  $export['node_submitted_top_cities_list'] = $strongarm;

  return $export;
}
