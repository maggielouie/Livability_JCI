<?php
/**
 * @file
 * liv_blog.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function liv_blog_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog_post|search_results';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog_post';
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
        'ft' => array(),
      ),
    ),
    'author' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'author',
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
    'post_date' => array(
      'weight' => '6',
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
    'body' => array(
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
  );
  $export['node|blog_post|search_results'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function liv_blog_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_post|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_post';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'two_column__6633';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_author',
        2 => 'field_deck',
        3 => 'body',
        4 => 'group_meta',
        18 => 'field_page_title',
        19 => 'field_meta_description',
      ),
      'right' => array(
        5 => 'group_publishing_options',
        6 => 'field_publish_on',
        7 => 'field_pull_quote',
        8 => 'field_publish_now',
        9 => 'field_blog_category',
        10 => 'field_source_notes',
        11 => 'field_quote_attribution',
        12 => 'field_image',
        13 => 'field_professional_title',
        14 => 'field_highlights',
        15 => 'group_pull_quote',
      ),
      'hidden' => array(
        16 => 'path',
        17 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_author' => 'left',
      'field_deck' => 'left',
      'body' => 'left',
      'group_meta' => 'left',
      'group_publishing_options' => 'right',
      'field_publish_on' => 'right',
      'field_pull_quote' => 'right',
      'field_publish_now' => 'right',
      'field_blog_category' => 'right',
      'field_source_notes' => 'right',
      'field_quote_attribution' => 'right',
      'field_image' => 'right',
      'field_professional_title' => 'right',
      'field_highlights' => 'right',
      'group_pull_quote' => 'right',
      'path' => 'hidden',
      '_add_existing_field' => 'hidden',
      'field_page_title' => 'left',
      'field_meta_description' => 'left',
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
  $export['node|blog_post|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog_post|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog_post';
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
        3 => 'body',
      ),
      'bottom' => array(
        4 => 'author',
        5 => 'post_date',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'field_image' => 'middle',
      'read_more_url' => 'middle',
      'body' => 'middle',
      'author' => 'bottom',
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
  $export['node|blog_post|search_results'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function liv_blog_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'blog_home';
  $ds_view_mode->label = 'Blog home';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['blog_home'] = $ds_view_mode;

  return $export;
}
