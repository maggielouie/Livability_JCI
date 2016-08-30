<?php
/**
 * @file
 * city2.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function city2_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|city|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '14',
    'children' => array(
      0 => 'group_commute',
      1 => 'group_demographics',
      2 => 'group_economic',
      3 => 'group_education',
      4 => 'group_employment',
      5 => 'group_ethnicity',
      6 => 'group_language',
      7 => 'group_main',
      8 => 'group_images',
      9 => 'group_video',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_content|node|city|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|city|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '47',
    'children' => array(
      0 => 'body',
      1 => 'field_county',
      2 => 'field_geo',
      3 => 'field_place_id',
      4 => 'field_state',
      5 => 'field_census_name',
      6 => 'field_promoted_city',
      7 => 'field_ad_targeting_project_id',
      8 => 'field_city_quote_author',
      9 => 'field_city_quotes',
      10 => 'field_weatherbase_id',
      11 => 'field_liv_fips',
      12 => 'field_metro',
      13 => 'field_bc_link',
      14 => 'field_fips',
      15 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_main|node|city|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|node|city|form';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '56',
    'children' => array(
      0 => 'field_youtube',
      1 => 'field_vimeo',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_video|node|city|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Main');
  t('Video');

  return $field_groups;
}
