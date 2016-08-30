<?php
/**
 * @file
 * article_quiz.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function article_quiz_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_article_quiz';
  $strongarm->value = 0;
  $export['comment_anonymous_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_article_quiz';
  $strongarm->value = '0';
  $export['comment_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_article_quiz';
  $strongarm->value = 1;
  $export['comment_default_mode_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_article_quiz';
  $strongarm->value = '50';
  $export['comment_default_per_page_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_article_quiz';
  $strongarm->value = 1;
  $export['comment_form_location_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_article_quiz';
  $strongarm->value = '1';
  $export['comment_preview_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_article_quiz';
  $strongarm->value = 1;
  $export['comment_subject_field_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__article_quiz';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
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
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
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
          'weight' => '10',
        ),
        'redirect' => array(
          'weight' => '18',
        ),
        'xmlsitemap' => array(
          'weight' => '17',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_article_quiz';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_article_quiz';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article_quiz';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_article_quiz';
  $strongarm->value = '1';
  $export['node_preview_article_quiz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_article_quiz';
  $strongarm->value = 0;
  $export['node_submitted_article_quiz'] = $strongarm;

  return $export;
}
