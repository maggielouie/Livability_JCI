<?php
/**
 * @file
 * city_context_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function city_context_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nearby_cities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nearby Cities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nearby Cities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Geo */
  $handler->display->display_options['fields']['field_geo']['id'] = 'field_geo';
  $handler->display->display_options['fields']['field_geo']['table'] = 'field_data_field_geo';
  $handler->display->display_options['fields']['field_geo']['field'] = 'field_geo';
  $handler->display->display_options['fields']['field_geo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_geo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_geo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_geo']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geo']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_geo']['field_api_classes'] = TRUE;
  /* Field: Content: Provider ID */
  $handler->display->display_options['fields']['field_provider_id']['id'] = 'field_provider_id';
  $handler->display->display_options['fields']['field_provider_id']['table'] = 'field_data_field_provider_id';
  $handler->display->display_options['fields']['field_provider_id']['field'] = 'field_provider_id';
  $handler->display->display_options['fields']['field_provider_id']['element_type'] = '0';
  $handler->display->display_options['fields']['field_provider_id']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_provider_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_provider_id']['field_api_classes'] = TRUE;
  /* Field: Content: Population */
  $handler->display->display_options['fields']['field_population']['id'] = 'field_population';
  $handler->display->display_options['fields']['field_population']['table'] = 'field_data_field_population';
  $handler->display->display_options['fields']['field_population']['field'] = 'field_population';
  $handler->display->display_options['fields']['field_population']['label'] = '';
  $handler->display->display_options['fields']['field_population']['element_type'] = '0';
  $handler->display->display_options['fields']['field_population']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_population']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_population']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_population']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: State Code */
  $handler->display->display_options['fields']['field_state_code']['id'] = 'field_state_code';
  $handler->display->display_options['fields']['field_state_code']['table'] = 'field_data_field_state_code';
  $handler->display->display_options['fields']['field_state_code']['field'] = 'field_state_code';
  $handler->display->display_options['fields']['field_state_code']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['fields']['field_state_code']['label'] = '';
  $handler->display->display_options['fields']['field_state_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_state_code']['element_type'] = '0';
  $handler->display->display_options['fields']['field_state_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_code']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_state_code']['element_default_classes'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Geo (field_geo) - proximity */
  $handler->display->display_options['sorts']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['table'] = 'field_data_field_geo';
  $handler->display->display_options['sorts']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['source'] = 'contextual_geofield_filter';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '',
    'lon' => '',
  );
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_geo';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_geo';
  /* Contextual filter: Content: Geo (field_geo) - proximity */
  $handler->display->display_options['arguments']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['arguments']['field_geofield_distance']['table'] = 'field_data_field_geo';
  $handler->display->display_options['arguments']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['arguments']['field_geofield_distance']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_geofield_distance']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_geofield_distance']['default_argument_options']['code'] = 'global $currentCity;
//drupal_set_message($cityContextActive.\'test\');
return($currentCity->field_geo[\'und\'][0][\'lat\'].\' \'.$currentCity->field_geo[\'und\'][0][\'lon\']);
';
  $handler->display->display_options['arguments']['field_geofield_distance']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_geofield_distance']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_geofield_distance']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_geofield_distance']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_geofield_distance']['proximity'] = array(
    'operation' => 'lt',
    'default_radius' => '30',
    'radius_unit' => '3959',
  );
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
    'city' => 'city',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'nearbycities';
  $export['nearby_cities'] = $view;

  $view = new view();
  $view->name = 'nearby_hospitals';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nearby Hospitals';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nearby Hospitals';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Hospital Type */
  $handler->display->display_options['fields']['field_hospital_type']['id'] = 'field_hospital_type';
  $handler->display->display_options['fields']['field_hospital_type']['table'] = 'field_data_field_hospital_type';
  $handler->display->display_options['fields']['field_hospital_type']['field'] = 'field_hospital_type';
  /* Field: Content: Ownership */
  $handler->display->display_options['fields']['field_ownership']['id'] = 'field_ownership';
  $handler->display->display_options['fields']['field_ownership']['table'] = 'field_data_field_ownership';
  $handler->display->display_options['fields']['field_ownership']['field'] = 'field_ownership';
  $handler->display->display_options['fields']['field_ownership']['element_type'] = '0';
  $handler->display->display_options['fields']['field_ownership']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_ownership']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ownership']['field_api_classes'] = TRUE;
  /* Field: Content: Provider ID */
  $handler->display->display_options['fields']['field_provider_id']['id'] = 'field_provider_id';
  $handler->display->display_options['fields']['field_provider_id']['table'] = 'field_data_field_provider_id';
  $handler->display->display_options['fields']['field_provider_id']['field'] = 'field_provider_id';
  $handler->display->display_options['fields']['field_provider_id']['label'] = '';
  $handler->display->display_options['fields']['field_provider_id']['element_type'] = '0';
  $handler->display->display_options['fields']['field_provider_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_provider_id']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_provider_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_provider_id']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Geo (field_geo) - proximity */
  $handler->display->display_options['sorts']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['table'] = 'field_data_field_geo';
  $handler->display->display_options['sorts']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['sorts']['field_geofield_distance']['source'] = 'contextual_geofield_filter';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_manual'] = array(
    'lat' => '',
    'lon' => '',
  );
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_entity_url_field'] = 'field_geo';
  $handler->display->display_options['sorts']['field_geofield_distance']['geofield_proximity_current_user_field'] = 'field_geo';
  /* Contextual filter: Content: Geo (field_geo) - proximity */
  $handler->display->display_options['arguments']['field_geofield_distance']['id'] = 'field_geofield_distance';
  $handler->display->display_options['arguments']['field_geofield_distance']['table'] = 'field_data_field_geo';
  $handler->display->display_options['arguments']['field_geofield_distance']['field'] = 'field_geofield_distance';
  $handler->display->display_options['arguments']['field_geofield_distance']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_geofield_distance']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_geofield_distance']['default_argument_options']['code'] = 'global $currentCity;
return($currentCity->field_geo[\'und\'][0][\'lat\'].\',\'.$currentCity->field_geo[\'und\'][0][\'lon\'].\'_60\');';
  $handler->display->display_options['arguments']['field_geofield_distance']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_geofield_distance']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_geofield_distance']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_geofield_distance']['proximity'] = array(
    'operation' => 'lt',
    'default_radius' => '60',
    'radius_unit' => '3959',
  );
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
    'hospitals' => 'hospitals',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['nearby_hospitals'] = $view;

  return $export;
}
