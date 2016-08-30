<?php
/**
 * @file
 * article_slideshow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function article_slideshow_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_article_slideshow';
  $strongarm->value = 0;
  $export['comment_anonymous_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_article_slideshow';
  $strongarm->value = '0';
  $export['comment_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_article_slideshow';
  $strongarm->value = 1;
  $export['comment_default_mode_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_article_slideshow';
  $strongarm->value = '50';
  $export['comment_default_per_page_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_article_slideshow';
  $strongarm->value = 1;
  $export['comment_form_location_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_article_slideshow';
  $strongarm->value = '1';
  $export['comment_preview_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_article_slideshow';
  $strongarm->value = 1;
  $export['comment_subject_field_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__article_slideshow';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
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
        'custom_settings' => TRUE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'marquee' => array(
        'custom_settings' => TRUE,
      ),
      'related' => array(
        'custom_settings' => TRUE,
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
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '12',
        ),
        'redirect' => array(
          'weight' => '22',
        ),
        'xmlsitemap' => array(
          'weight' => '21',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_article_slideshow';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_article_slideshow';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article_slideshow';
  $strongarm->value = array();
  $export['node_options_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_article_slideshow';
  $strongarm->value = '1';
  $export['node_preview_article_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_article_slideshow';
  $strongarm->value = 1;
  $export['node_submitted_article_slideshow'] = $strongarm;

  return $export;
}
