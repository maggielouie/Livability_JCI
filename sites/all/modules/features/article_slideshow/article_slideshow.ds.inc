<?php
/**
 * @file
 * article_slideshow.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function article_slideshow_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article_slideshow|search_results';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article_slideshow';
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
  $export['node|article_slideshow|search_results'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function article_slideshow_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_list_item_art_ss|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_list_item_art_ss';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_headline_ss',
        1 => 'group_details',
        2 => '_add_existing_field',
        3 => 'field_image_single',
        4 => 'field_bp_body',
        6 => 'field_source_notes',
        7 => 'group_pull_quote',
        8 => 'field_quote_attribution',
        9 => 'field_pull_quote',
        10 => 'field_highlights',
        11 => 'field_professional_title',
        12 => 'group_meta',
        13 => 'field_meta_description',
      ),
      'hidden' => array(
        5 => 'redirect',
      ),
    ),
    'fields' => array(
      'field_headline_ss' => 'ds_content',
      'group_details' => 'ds_content',
      '_add_existing_field' => 'ds_content',
      'field_image_single' => 'ds_content',
      'field_bp_body' => 'ds_content',
      'redirect' => 'hidden',
      'field_source_notes' => 'ds_content',
      'group_pull_quote' => 'ds_content',
      'field_quote_attribution' => 'ds_content',
      'field_pull_quote' => 'ds_content',
      'field_highlights' => 'ds_content',
      'field_professional_title' => 'ds_content',
      'group_meta' => 'ds_content',
      'field_meta_description' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_list_item_art_ss|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article_slideshow|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article_slideshow';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_publish_on',
        2 => 'field_publish_now',
        3 => 'field_page_title',
        4 => 'field_meta_description',
        5 => 'field_list_item_art_ss',
        6 => 'field_deck',
        7 => 'body',
        8 => 'field_category',
        9 => 'field_pull_quote',
        10 => 'field_quote_attribution',
        11 => 'field_internal_category',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_publish_on' => 'ds_content',
      'field_publish_now' => 'ds_content',
      'field_page_title' => 'ds_content',
      'field_meta_description' => 'ds_content',
      'field_list_item_art_ss' => 'ds_content',
      'field_deck' => 'ds_content',
      'body' => 'ds_content',
      'field_category' => 'ds_content',
      'field_pull_quote' => 'ds_content',
      'field_quote_attribution' => 'ds_content',
      'field_internal_category' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article_slideshow|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article_slideshow|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article_slideshow';
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
        8 => 'field_show_list_numbers',
        9 => 'field_list_item_art_ss',
        10 => 'field_featured_homepage',
        11 => 'group_meta_article_slideshow',
        12 => 'field_page_title',
        13 => 'field_meta_description',
        14 => 'path',
      ),
      'right' => array(
        15 => 'group_pub_options',
        16 => 'field_internal_category',
        17 => 'field_image',
        18 => 'field_publish_on',
        19 => 'field_article_thumbnail',
        20 => 'field_pull_quote',
        21 => 'field_publish_now',
        22 => 'field_highlights',
        23 => 'group_pull_quote_art_ss',
        24 => 'field_quote_attribution',
        25 => 'field_professional_title',
        26 => '_add_existing_field',
      ),
      'hidden' => array(
        27 => 'field_list_item',
        28 => 'xmlsitemap',
        29 => 'redirect',
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
      'field_show_list_numbers' => 'left',
      'field_list_item_art_ss' => 'left',
      'field_featured_homepage' => 'left',
      'group_meta_article_slideshow' => 'left',
      'field_page_title' => 'left',
      'field_meta_description' => 'left',
      'path' => 'left',
      'group_pub_options' => 'right',
      'field_internal_category' => 'right',
      'field_image' => 'right',
      'field_publish_on' => 'right',
      'field_article_thumbnail' => 'right',
      'field_pull_quote' => 'right',
      'field_publish_now' => 'right',
      'field_highlights' => 'right',
      'group_pull_quote_art_ss' => 'right',
      'field_quote_attribution' => 'right',
      'field_professional_title' => 'right',
      '_add_existing_field' => 'right',
      'field_list_item' => 'hidden',
      'xmlsitemap' => 'hidden',
      'redirect' => 'hidden',
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
  $export['node|article_slideshow|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article_slideshow|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article_slideshow';
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
  $export['node|article_slideshow|search_results'] = $ds_layout;

  return $export;
}
