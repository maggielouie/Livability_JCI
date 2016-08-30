<?php
/**
 * @file
 * top_100.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function top_100_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_top_100_item|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_top_100_item';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_rank',
        1 => 'field_top_100_city',
        2 => 'field_livscore',
        3 => 'field_economic_score',
        4 => 'field_healthcare_score',
        5 => 'field_housing_score',
        6 => 'field_civic_capital_score',
        7 => 'field_education_score',
        8 => 'field_amenities_score',
        9 => 'field_demographics_score',
        10 => 'field_infrastructure_score',
        11 => 'group_details',
        12 => 'field_image_single',
        13 => 'field_image',
        14 => 'field_bp_body',
        15 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_rank' => 'ds_content',
      'field_top_100_city' => 'ds_content',
      'field_livscore' => 'ds_content',
      'field_economic_score' => 'ds_content',
      'field_healthcare_score' => 'ds_content',
      'field_housing_score' => 'ds_content',
      'field_civic_capital_score' => 'ds_content',
      'field_education_score' => 'ds_content',
      'field_amenities_score' => 'ds_content',
      'field_demographics_score' => 'ds_content',
      'field_infrastructure_score' => 'ds_content',
      'group_details' => 'ds_content',
      'field_image_single' => 'ds_content',
      'field_image' => 'ds_content',
      'field_bp_body' => 'ds_content',
      '_add_existing_field' => 'ds_content',
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
  $export['field_collection_item|field_top_100_item|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|top_100|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'top_100';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'two_column__6633__stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_year',
        1 => 'title',
        2 => 'field_deck',
        18 => 'field_short_description',
      ),
      'right' => array(
        3 => 'field_publish_on',
        4 => 'field_publish_now',
        5 => 'group_publishing_options',
        6 => 'field_featured_homepage',
      ),
      'full_width' => array(
        7 => 'body',
        8 => 'field_top_100_item',
        9 => 'field_top_100_ranking_page',
        10 => 'field_ranking_methodology_page',
        11 => 'field_top_100_advisory_board_pag',
        12 => 'field_page_title',
        13 => 'field_meta_description',
        14 => 'path',
        19 => '_add_existing_field',
      ),
      'hidden' => array(
        15 => 'field_image',
        16 => 'xmlsitemap',
        17 => 'redirect',
      ),
    ),
    'fields' => array(
      'field_year' => 'left',
      'title' => 'left',
      'field_deck' => 'left',
      'field_publish_on' => 'right',
      'field_publish_now' => 'right',
      'group_publishing_options' => 'right',
      'field_featured_homepage' => 'right',
      'body' => 'full_width',
      'field_top_100_item' => 'full_width',
      'field_top_100_ranking_page' => 'full_width',
      'field_ranking_methodology_page' => 'full_width',
      'field_top_100_advisory_board_pag' => 'full_width',
      'field_page_title' => 'full_width',
      'field_meta_description' => 'full_width',
      'path' => 'full_width',
      'field_image' => 'hidden',
      'xmlsitemap' => 'hidden',
      'redirect' => 'hidden',
      'field_short_description' => 'left',
      '_add_existing_field' => 'full_width',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'full_width' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|top_100|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|top_100|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'top_100';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_deck',
        1 => 'body',
        2 => 'comments',
      ),
    ),
    'fields' => array(
      'field_deck' => 'ds_content',
      'body' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|top_100|full'] = $ds_layout;

  return $export;
}
