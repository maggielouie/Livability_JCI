<?php
/**
 * @file
 * livability_citys.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function livability_citys_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|city|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'city';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|city|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|city|search_results';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'city';
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
    'field_featured_image' => array(
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
  $export['node|city|search_results'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|city|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'city';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|city|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function livability_citys_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|city|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'city';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_3col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'field_state',
      ),
      'left' => array(
        2 => 'field_geo',
        3 => 'body',
      ),
      'middle' => array(
        4 => 'field_median_home_price',
        5 => 'field_employed',
        6 => 'field_unemployed',
        7 => 'field_employed_armed_forces',
      ),
      'right' => array(
        8 => 'field_county',
        9 => 'field_population',
        10 => 'field_median_household_income',
      ),
      'footer' => array(
        11 => 'field_drove_alone',
        12 => 'field_carpooled',
        13 => 'field_public',
        14 => 'field_walked',
        15 => 'field_commute_other',
        16 => 'field_worked_home',
        17 => 'field_avg_commute',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_state' => 'header',
      'field_geo' => 'left',
      'body' => 'left',
      'field_median_home_price' => 'middle',
      'field_employed' => 'middle',
      'field_unemployed' => 'middle',
      'field_employed_armed_forces' => 'middle',
      'field_county' => 'right',
      'field_population' => 'right',
      'field_median_household_income' => 'right',
      'field_drove_alone' => 'footer',
      'field_carpooled' => 'footer',
      'field_public' => 'footer',
      'field_walked' => 'footer',
      'field_commute_other' => 'footer',
      'field_worked_home' => 'footer',
      'field_avg_commute' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|city|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|city|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'city';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'search_results';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'title',
      ),
      'middle' => array(
        1 => 'field_featured_image',
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
      'field_featured_image' => 'middle',
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
  $export['node|city|search_results'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|city|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'city';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_3col_stacked_equal_width';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        1 => 'body',
      ),
      'middle' => array(
        2 => 'field_population',
        3 => 'field_median_home_price',
        4 => 'field_median_household_income',
      ),
      'right' => array(
        5 => 'field_employed',
        6 => 'field_unemployed',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'body' => 'left',
      'field_population' => 'middle',
      'field_median_home_price' => 'middle',
      'field_median_household_income' => 'middle',
      'field_employed' => 'right',
      'field_unemployed' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|city|teaser'] = $ds_layout;

  return $export;
}
