<?php
/**
 * @file
 * livability_states.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function livability_states_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nearby_airports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nearby Airports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nearby Airports';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Geo (field_geo) - proximity */
  $handler->display->display_options['sorts']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['table'] = 'field_data_field_geo';
  $handler->display->display_options['sorts']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['expose']['label'] = 'Geo (field_geo) - proximity';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '35.902787',
    'lon' => '-86.808780',
  );
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_geo';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_geo';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'airports' => 'airports',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['nearby_airports'] = $view;

  $view = new view();
  $view->name = 'state_content_cards';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'State Content Cards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'State Content Cards';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'one-third';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'clearfix article-slider';
  $handler->display->display_options['style_options']['wrapper_class'] = 'articles padded grey-bg shadow-inset-lr';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'content_card';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="show-more shadow-inset-lr"><a href="" class="show-more-link">Show more posts <i class="icon-arrow-down-double white"></i></a></div>';
  /* Relationship: Content: Place (field_place) */
  $handler->display->display_options['relationships']['field_place_value']['id'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['table'] = 'field_data_field_place';
  $handler->display->display_options['relationships']['field_place_value']['field'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_place_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_place_ref_target_id']['id'] = 'field_place_ref_target_id';
  $handler->display->display_options['relationships']['field_place_ref_target_id']['table'] = 'field_data_field_place_ref';
  $handler->display->display_options['relationships']['field_place_ref_target_id']['field'] = 'field_place_ref_target_id';
  $handler->display->display_options['relationships']['field_place_ref_target_id']['relationship'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_ref_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['relationship'] = 'field_place_ref_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: FIPS state code */
  $handler->display->display_options['fields']['field_fips_state_code']['id'] = 'field_fips_state_code';
  $handler->display->display_options['fields']['field_fips_state_code']['table'] = 'field_data_field_fips_state_code';
  $handler->display->display_options['fields']['field_fips_state_code']['field'] = 'field_fips_state_code';
  $handler->display->display_options['fields']['field_fips_state_code']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['fields']['field_fips_state_code']['element_type'] = '0';
  $handler->display->display_options['fields']['field_fips_state_code']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_fips_state_code']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fips_state_code']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_fips_state_code']['field_api_classes'] = TRUE;
  /* Field: Content: Place */
  $handler->display->display_options['fields']['field_place']['id'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['table'] = 'field_data_field_place';
  $handler->display->display_options['fields']['field_place']['field'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['label'] = '';
  $handler->display->display_options['fields']['field_place']['element_type'] = '0';
  $handler->display->display_options['fields']['field_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_place']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_place']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_place']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_place']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_place']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Publish on (field_publish_on) */
  $handler->display->display_options['sorts']['field_publish_on_value']['id'] = 'field_publish_on_value';
  $handler->display->display_options['sorts']['field_publish_on_value']['table'] = 'field_data_field_publish_on';
  $handler->display->display_options['sorts']['field_publish_on_value']['field'] = 'field_publish_on_value';
  $handler->display->display_options['sorts']['field_publish_on_value']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['state_content_cards'] = $view;

  $view = new view();
  $view->name = 'states';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'States';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'States';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|title';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'State';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'state' => 'state',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'states';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'States';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['states'] = $view;

  return $export;
}
