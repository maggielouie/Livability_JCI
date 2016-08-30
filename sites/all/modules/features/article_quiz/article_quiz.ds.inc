<?php
/**
 * @file
 * article_quiz.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function article_quiz_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article_quiz|content_card';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article_quiz';
  $ds_fieldsetting->view_mode = 'content_card';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'image-icon',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article_quiz|content_card'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article_quiz|search_results';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article_quiz';
  $ds_fieldsetting->view_mode = 'search_results';
  $ds_fieldsetting->settings = array(
    'read_more_url' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'more',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'ds_post_date_m_d_y_notime',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'date',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'search-snippet',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_author' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' | ',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_short_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article_quiz|search_results'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function article_quiz_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article_quiz|content_card';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article_quiz';
  $ds_layout->view_mode = 'content_card';
  $ds_layout->layout = 'content_cards';
  $ds_layout->settings = array(
    'regions' => array(
      'summary' => array(
        0 => 'body',
      ),
      'title' => array(
        1 => 'title',
      ),
      'top' => array(
        2 => 'field_image',
      ),
      'category' => array(
        3 => 'field_category',
      ),
    ),
    'fields' => array(
      'body' => 'summary',
      'title' => 'title',
      'field_image' => 'top',
      'field_category' => 'category',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'category' => 'div',
      'title' => 'div',
      'summary' => 'div',
      'left_below' => 'div',
      'right_below' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article_quiz|content_card'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article_quiz|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article_quiz';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'two_column__6633';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_byline',
        2 => 'field_author',
        3 => 'field_deck',
        4 => 'field_short_description',
        5 => 'body',
        6 => 'field_place',
        7 => 'field_category',
        8 => 'field_featured_homepage',
        9 => 'group_meta',
        10 => 'field_page_title',
        11 => 'path',
        13 => 'field_meta_description',
      ),
      'right' => array(
        12 => 'group_publishing_options',
        14 => 'field_publish_on',
        15 => 'field_internal_category',
        16 => 'field_publish_now',
        17 => 'field_source_notes',
        18 => 'field_image',
        22 => 'field_article_thumbnail',
      ),
      'hidden' => array(
        19 => 'field_tags',
        20 => 'xmlsitemap',
        21 => 'redirect',
        23 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_byline' => 'left',
      'field_author' => 'left',
      'field_deck' => 'left',
      'field_short_description' => 'left',
      'body' => 'left',
      'field_place' => 'left',
      'field_category' => 'left',
      'field_featured_homepage' => 'left',
      'group_meta' => 'left',
      'field_page_title' => 'left',
      'path' => 'left',
      'group_publishing_options' => 'right',
      'field_meta_description' => 'left',
      'field_publish_on' => 'right',
      'field_internal_category' => 'right',
      'field_publish_now' => 'right',
      'field_source_notes' => 'right',
      'field_image' => 'right',
      'field_tags' => 'hidden',
      'xmlsitemap' => 'hidden',
      'redirect' => 'hidden',
      'field_article_thumbnail' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article_quiz|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article_quiz|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article_quiz';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'search_results';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'title',
      ),
      'middle' => array(
        1 => 'field_image',
        2 => 'read_more_url',
        3 => 'field_short_description',
      ),
      'bottom' => array(
        4 => 'field_author',
        5 => 'post_date',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'field_image' => 'middle',
      'read_more_url' => 'middle',
      'field_short_description' => 'middle',
      'field_author' => 'bottom',
      'post_date' => 'bottom',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'left_above' => 'div',
      'right_above' => 'div',
      'middle' => 'div',
      'left_below' => 'div',
      'right_below' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article_quiz|search_results'] = $ds_layout;

  return $export;
}
