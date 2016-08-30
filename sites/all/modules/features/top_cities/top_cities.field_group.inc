<?php
/**
 * @file
 * top_cities.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function top_cities_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publishing_options|node|top_cities_list|form';
  $field_group->group_name = 'group_publishing_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'top_cities_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publishing Options',
    'weight' => '7',
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
  $export['group_publishing_options|node|top_cities_list|form'] = $field_group;

  return $export;
}
