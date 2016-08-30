<?php
/**
 * @file
 * article_slideshow.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function article_slideshow_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|field_collection_item|field_list_item_art_ss|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_list_item_art_ss';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_image_single',
      1 => 'field_bp_body',
      2 => 'field_source_notes',
      3 => 'field_highlights',
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
  $export['group_details|field_collection_item|field_list_item_art_ss|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_article_slideshow|node|article_slideshow|form';
  $field_group->group_name = 'group_meta_article_slideshow';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article_slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Information',
    'weight' => '11',
    'children' => array(
      0 => 'field_page_title',
      1 => 'field_meta_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Meta Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-meta-article-slideshow field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_meta_article_slideshow|node|article_slideshow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|field_collection_item|field_list_item_art_ss|form';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_list_item_art_ss';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Meta Information',
    'weight' => '7',
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
  $export['group_meta|field_collection_item|field_list_item_art_ss|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pub_options|node|article_slideshow|form';
  $field_group->group_name = 'group_pub_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article_slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publishing Options',
    'weight' => '13',
    'children' => array(
      0 => 'field_publish_on',
      1 => 'field_publish_now',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pub-options field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pub_options|node|article_slideshow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pull_quote_art_ss|node|article_slideshow|form';
  $field_group->group_name = 'group_pull_quote_art_ss';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article_slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pull Quote',
    'weight' => '18',
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
        'classes' => 'group-pull-quote-art-ss field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pull_quote_art_ss|node|article_slideshow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pull_quote|field_collection_item|field_list_item_art_ss|form';
  $field_group->group_name = 'group_pull_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_list_item_art_ss';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Pull Quote',
    'weight' => '5',
    'children' => array(
      0 => 'field_quote_attribution',
      1 => 'field_pull_quote',
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
  $export['group_pull_quote|field_collection_item|field_list_item_art_ss|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pull_quote|node|article_slideshow|full';
  $field_group->group_name = 'group_pull_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article_slideshow';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pull Quote',
    'weight' => '5',
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
      ),
    ),
  );
  $export['group_pull_quote|node|article_slideshow|full'] = $field_group;

  return $export;
}
