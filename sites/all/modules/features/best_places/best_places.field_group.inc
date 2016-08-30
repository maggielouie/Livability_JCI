<?php
/**
 * @file
 * best_places.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function best_places_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|field_collection_item|field_list_item|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_list_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_bp_body',
      1 => 'field_highlights',
      2 => 'field_source_notes',
      3 => 'field_image_single',
      4 => 'group_meta',
      5 => 'group_pull_quote',
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
  $export['group_details|field_collection_item|field_list_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|field_collection_item|field_list_item|form';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_list_item';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Meta Information',
    'weight' => '12',
    'children' => array(
      0 => 'field_meta_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_meta|field_collection_item|field_list_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|best_places|form';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'best_places';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Information',
    'weight' => '7',
    'children' => array(
      0 => 'field_meta_description',
      1 => 'field_page_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meta field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_meta|node|best_places|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publishing_options|node|best_places|form';
  $field_group->group_name = 'group_publishing_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'best_places';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publishing Options',
    'weight' => '10',
    'children' => array(
      0 => 'field_publish_now',
      1 => 'field_publish_on',
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
  $export['group_publishing_options|node|best_places|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pull_quote|field_collection_item|field_list_item|form';
  $field_group->group_name = 'group_pull_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_list_item';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Pull Quote',
    'weight' => '10',
    'children' => array(
      0 => 'field_professional_title',
      1 => 'field_pull_quote',
      2 => 'field_quote_attribution',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pull-quote field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pull_quote|field_collection_item|field_list_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pull_quote|node|best_places|form';
  $field_group->group_name = 'group_pull_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'best_places';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pull Quote',
    'weight' => '15',
    'children' => array(
      0 => 'field_pull_quote',
      1 => 'field_quote_attribution',
      2 => 'field_professional_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pull-quote field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pull_quote|node|best_places|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pull_quote|node|best_places|full';
  $field_group->group_name = 'group_pull_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'best_places';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pull Quote',
    'weight' => '5',
    'children' => array(
      0 => 'field_pull_quote',
      1 => 'field_quote_attribution',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pull-quote field-group-fieldset',
      ),
    ),
  );
  $export['group_pull_quote|node|best_places|full'] = $field_group;

  return $export;
}
