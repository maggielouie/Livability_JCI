<?php
/**
 * @file
 * top_100.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function top_100_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|field_collection_item|field_top_100_item|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_top_100_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '11',
    'children' => array(
      0 => 'field_image',
      1 => 'field_bp_body',
      2 => 'field_image_single',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_details|field_collection_item|field_top_100_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publishing_options|node|top_100|form';
  $field_group->group_name = 'group_publishing_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'top_100';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publishing Options',
    'weight' => '4',
    'children' => array(
      0 => 'field_publish_now',
      1 => 'field_publish_on',
      2 => 'field_featured_homepage',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publishing-options field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_publishing_options|node|top_100|form'] = $field_group;

  return $export;
}
