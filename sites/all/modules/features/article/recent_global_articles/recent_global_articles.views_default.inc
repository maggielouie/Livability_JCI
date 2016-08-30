<?php
/**
 * @file
 * recent_global_articles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function recent_global_articles_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'recent_global_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent Global Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '99';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'one-third';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'tile';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Content: Place (field_place) */
  $handler->display->display_options['relationships']['field_place_value']['id'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['table'] = 'field_data_field_place';
  $handler->display->display_options['relationships']['field_place_value']['field'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
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
    'article' => 'article',
    'best_places' => 'best_places',
    'top_100' => 'top_100',
    'top_cities_list' => 'top_cities_list',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Place name (field_place_ref) */
  $handler->display->display_options['filters']['field_place_ref_target_id']['id'] = 'field_place_ref_target_id';
  $handler->display->display_options['filters']['field_place_ref_target_id']['table'] = 'field_data_field_place_ref';
  $handler->display->display_options['filters']['field_place_ref_target_id']['field'] = 'field_place_ref_target_id';
  $handler->display->display_options['filters']['field_place_ref_target_id']['relationship'] = 'field_place_value';
  $handler->display->display_options['filters']['field_place_ref_target_id']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_place_ref_target_id']['group'] = 1;
  /* Filter criterion: Content: Featured on Homepage (field_featured_homepage) */
  $handler->display->display_options['filters']['field_featured_homepage_value']['id'] = 'field_featured_homepage_value';
  $handler->display->display_options['filters']['field_featured_homepage_value']['table'] = 'field_data_field_featured_homepage';
  $handler->display->display_options['filters']['field_featured_homepage_value']['field'] = 'field_featured_homepage_value';
  $handler->display->display_options['filters']['field_featured_homepage_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_featured_homepage_value']['group'] = 2;
  $handler->display->display_options['filters']['field_featured_homepage_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['recent_global_articles'] = $view;

  return $export;
}
