<?php
/**
 * @file
 * city_state_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function city_state_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'find_a_city';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_city_state_search_solr';
  $view->human_name = 'Find a City';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find a City';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_city_state_search_solr';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: State: State Code (indexed) */
  $handler->display->display_options['fields']['field_state_field_state_code']['id'] = 'field_state_field_state_code';
  $handler->display->display_options['fields']['field_state_field_state_code']['table'] = 'search_api_index_city_state_search_solr';
  $handler->display->display_options['fields']['field_state_field_state_code']['field'] = 'field_state_field_state_code';
  /* Field: State: Title (indexed) */
  $handler->display->display_options['fields']['field_state_title']['id'] = 'field_state_title';
  $handler->display->display_options['fields']['field_state_title']['table'] = 'search_api_index_city_state_search_solr';
  $handler->display->display_options['fields']['field_state_title']['field'] = 'field_state_title';
  $handler->display->display_options['fields']['field_state_title']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_city_state_search_solr';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_city_state_search_solr';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['min_length'] = '1';
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_state:field_state_code' => 'field_state:field_state_code',
    'field_state:title' => 'field_state:title',
    'title' => 'title',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'find-a-city';
  $export['find_a_city'] = $view;

  return $export;
}
