<?php
/**
 * @file
 * moving.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function moving_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'how_to_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'How To Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'How to Guides';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'one-third';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'clearfix article-slider';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Content: Place (field_place) */
  $handler->display->display_options['relationships']['field_place_value']['id'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['table'] = 'field_data_field_place';
  $handler->display->display_options['relationships']['field_place_value']['field'] = 'field_place_value';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
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
  /* Filter criterion: Field collection item: Category (field_category_ref) */
  $handler->display->display_options['filters']['field_category_ref_tid']['id'] = 'field_category_ref_tid';
  $handler->display->display_options['filters']['field_category_ref_tid']['table'] = 'field_data_field_category_ref';
  $handler->display->display_options['filters']['field_category_ref_tid']['field'] = 'field_category_ref_tid';
  $handler->display->display_options['filters']['field_category_ref_tid']['relationship'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_ref_tid']['value'] = array(
    0 => '107',
  );
  $handler->display->display_options['filters']['field_category_ref_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_category_ref_tid']['vocabulary'] = 'category';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'related';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Category (field_category) */
  $handler->display->display_options['relationships']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['relationships']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_category_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $export['how_to_articles'] = $view;

  $view = new view();
  $view->name = 'moving';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Moving';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Moving';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'one-third';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'clearfix';
  $handler->display->display_options['style_options']['wrapper_class'] = 'padded';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'tile';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="show-more shadow-inset-lr"><a href="" class="show-more-link">Show more posts <i class="icon-arrow-down-double white"></i></a></div>';
  /* Relationship: Content: Place (field_place) */
  $handler->display->display_options['relationships']['field_place_value']['id'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['table'] = 'field_data_field_place';
  $handler->display->display_options['relationships']['field_place_value']['field'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['delta'] = '-1';
  /* Relationship: Content: Category (field_category) */
  $handler->display->display_options['relationships']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['relationships']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['delta'] = '-1';
  /* Relationship: Field collection item: Category (field_category_ref) */
  $handler->display->display_options['relationships']['field_category_ref_tid']['id'] = 'field_category_ref_tid';
  $handler->display->display_options['relationships']['field_category_ref_tid']['table'] = 'field_data_field_category_ref';
  $handler->display->display_options['relationships']['field_category_ref_tid']['field'] = 'field_category_ref_tid';
  $handler->display->display_options['relationships']['field_category_ref_tid']['relationship'] = 'field_category_value';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Field collection item: Featured in Category (field_featured_in_category) */
  $handler->display->display_options['sorts']['field_featured_in_category_value']['id'] = 'field_featured_in_category_value';
  $handler->display->display_options['sorts']['field_featured_in_category_value']['table'] = 'field_data_field_featured_in_category';
  $handler->display->display_options['sorts']['field_featured_in_category_value']['field'] = 'field_featured_in_category_value';
  $handler->display->display_options['sorts']['field_featured_in_category_value']['relationship'] = 'field_category_value';
  $handler->display->display_options['sorts']['field_featured_in_category_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_category_ref_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = '%1';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['name']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['name']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['name']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = TRUE;
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
  /* Filter criterion: Field: Place name (field_place_ref) */
  $handler->display->display_options['filters']['field_place_ref_target_id']['id'] = 'field_place_ref_target_id';
  $handler->display->display_options['filters']['field_place_ref_target_id']['table'] = 'field_data_field_place_ref';
  $handler->display->display_options['filters']['field_place_ref_target_id']['field'] = 'field_place_ref_target_id';
  $handler->display->display_options['filters']['field_place_ref_target_id']['relationship'] = 'field_place_value';
  $handler->display->display_options['filters']['field_place_ref_target_id']['operator'] = 'empty';
  /* Filter criterion: Field collection item: Category (field_category_ref) */
  $handler->display->display_options['filters']['field_category_ref_tid']['id'] = 'field_category_ref_tid';
  $handler->display->display_options['filters']['field_category_ref_tid']['table'] = 'field_data_field_category_ref';
  $handler->display->display_options['filters']['field_category_ref_tid']['field'] = 'field_category_ref_tid';
  $handler->display->display_options['filters']['field_category_ref_tid']['relationship'] = 'field_category_value';
  $handler->display->display_options['filters']['field_category_ref_tid']['value'] = array(
    305 => '305',
    107 => '107',
    105 => '105',
    106 => '106',
  );
  $handler->display->display_options['filters']['field_category_ref_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_category_ref_tid']['vocabulary'] = 'category';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'moving';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'marquee';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $export['moving'] = $view;

  $view = new view();
  $view->name = 'moving_menu_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Moving Menu List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Moving Menu List';
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'level-1';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'topics/[name]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'category' => 'category',
  );
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '105';
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = '!=';
  $handler->display->display_options['filters']['name']['value'] = 'Moving Countdown';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['moving_menu_list'] = $view;

  return $export;
}
