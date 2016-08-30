<?php
/**
 * @file
 * special_section.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function special_section_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_area|node|special_section|form';
  $field_group->group_name = 'group_content_area';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'special_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Area',
    'weight' => '4',
    'children' => array(
      0 => 'group_content_intro',
      1 => 'group_data_graphic',
      2 => 'group_digital_magazine',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Content Area',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-content-area field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_content_area|node|special_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_intro|node|special_section|form';
  $field_group->group_name = 'group_content_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'special_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_area';
  $field_group->data = array(
    'label' => 'Content Intro',
    'weight' => '12',
    'children' => array(
      0 => 'field_ss_header',
      1 => 'field_ss_deck',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content-intro field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_content_intro|node|special_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_graphic|node|special_section|form';
  $field_group->group_name = 'group_data_graphic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'special_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_area';
  $field_group->data = array(
    'label' => 'Data Graphic',
    'weight' => '13',
    'children' => array(
      0 => 'field_ss_data_graphic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Data Graphic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-data-graphic field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data_graphic|node|special_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_digital_magazine|node|special_section|form';
  $field_group->group_name = 'group_digital_magazine';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'special_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_area';
  $field_group->data = array(
    'label' => 'Digital Magazine',
    'weight' => '14',
    'children' => array(
      0 => 'field_ss_dm_header',
      1 => 'field_ss_dm_deck',
      2 => 'field_ss_dm_embed_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Digital Magazine',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-digital-magazine field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_digital_magazine|node|special_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header|node|special_section|form';
  $field_group->group_name = 'group_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'special_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '2',
    'children' => array(
      0 => 'field_sponsor_logo',
      1 => 'field_sponsor_link',
      2 => 'field_sponsor_facebook_link',
      3 => 'field_sponsor_twitter_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Header',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-header field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_header|node|special_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_intro|node|special_section|form';
  $field_group->group_name = 'group_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'special_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Intro',
    'weight' => '3',
    'children' => array(
      0 => 'field_photo',
      1 => 'field_ss_description',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Intro',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-intro field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_intro|node|special_section|form'] = $field_group;

  return $export;
}
