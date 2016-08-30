<?php
/**
 * @file
 * helper_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function helper_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'place_reference';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Place reference';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_state']['element_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title], [field_state] ([type])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'node';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
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
    'area' => 'area',
    'city' => 'city',
    'county' => 'county',
    'state' => 'state',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_state' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Place Reference */
  $handler = $view->new_display('entityreference', 'Place Reference', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_state' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_state']['element_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_state']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title], [field_state]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'county' => 'county',
  );

  /* Display: City Reference */
  $handler = $view->new_display('entityreference', 'City Reference', 'entityreference_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_state' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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

  /* Display: Gallery Entity Reference */
  $handler = $view->new_display('entityreference', 'Gallery Entity Reference', 'entityreference_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_state' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_gallery_city_node']['id'] = 'reverse_field_gallery_city_node';
  $handler->display->display_options['relationships']['reverse_field_gallery_city_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_gallery_city_node']['field'] = 'reverse_field_gallery_city_node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'area' => 'area',
    'city' => 'city',
    'county' => 'county',
    'state' => 'state',
  );
  /* Filter criterion: Content: Place (field_gallery_city) */
  $handler->display->display_options['filters']['field_gallery_city_target_id']['id'] = 'field_gallery_city_target_id';
  $handler->display->display_options['filters']['field_gallery_city_target_id']['table'] = 'field_data_field_gallery_city';
  $handler->display->display_options['filters']['field_gallery_city_target_id']['field'] = 'field_gallery_city_target_id';
  $handler->display->display_options['filters']['field_gallery_city_target_id']['relationship'] = 'reverse_field_gallery_city_node';
  $handler->display->display_options['filters']['field_gallery_city_target_id']['operator'] = 'empty';

  /* Display: Popular State Reference */
  $handler = $view->new_display('entityreference', 'Popular State Reference', 'entityreference_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_state' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_popular_place_node']['id'] = 'reverse_field_popular_place_node';
  $handler->display->display_options['relationships']['reverse_field_popular_place_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_popular_place_node']['field'] = 'reverse_field_popular_place_node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'state' => 'state',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_popular_state_target_id']['id'] = 'field_popular_state_target_id';
  $handler->display->display_options['filters']['field_popular_state_target_id']['table'] = 'field_data_field_popular_state';
  $handler->display->display_options['filters']['field_popular_state_target_id']['field'] = 'field_popular_state_target_id';
  $handler->display->display_options['filters']['field_popular_state_target_id']['relationship'] = 'reverse_field_popular_place_node';
  $handler->display->display_options['filters']['field_popular_state_target_id']['operator'] = 'empty';
  $export['place_reference'] = $view;

  return $export;
}
