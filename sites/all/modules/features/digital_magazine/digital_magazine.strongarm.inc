<?php
/**
 * @file
 * digital_magazine.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function digital_magazine_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_digital_magazine';
  $strongarm->value = 0;
  $export['comment_anonymous_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_digital_magazine';
  $strongarm->value = 1;
  $export['comment_default_mode_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_digital_magazine';
  $strongarm->value = '50';
  $export['comment_default_per_page_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_digital_magazine';
  $strongarm->value = '0';
  $export['comment_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_digital_magazine';
  $strongarm->value = 1;
  $export['comment_form_location_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_digital_magazine';
  $strongarm->value = '1';
  $export['comment_preview_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_digital_magazine';
  $strongarm->value = 1;
  $export['comment_subject_field_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__digital_magazine';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
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
      'featured' => array(
        'custom_settings' => FALSE,
      ),
      'marquee' => array(
        'custom_settings' => FALSE,
      ),
      'related' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'content_card' => array(
        'custom_settings' => FALSE,
      ),
      'search_results' => array(
        'custom_settings' => FALSE,
      ),
      'tile' => array(
        'custom_settings' => FALSE,
      ),
      'blog_home' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '10',
        ),
        'xmlsitemap' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_digital_magazine';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_digital_magazine';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_digital_magazine';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_digital_magazine';
  $strongarm->value = '1';
  $export['node_preview_digital_magazine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_digital_magazine';
  $strongarm->value = 1;
  $export['node_submitted_digital_magazine'] = $strongarm;

  return $export;
}
