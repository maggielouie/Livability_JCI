<?php
/**
 * @file
 * contexts.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function contexts_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-digital_magazine-field_mag_cover'
  $field_instances['node-digital_magazine-field_mag_cover'] = array(
    'bundle' => 'digital_magazine',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_mag_cover',
    'label' => 'Mag Cover',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'oembed' => 0,
          'private' => 'private',
          'public' => 'public',
        ),
        'allowed_types' => array(
          'application' => 0,
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Mag Cover');

  return $field_instances;
}
