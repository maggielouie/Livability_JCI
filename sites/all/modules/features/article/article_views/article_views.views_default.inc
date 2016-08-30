<?php
/**
 * @file
 * article_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function article_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'articles_by_category';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Articles by Category';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Articles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_area_ref_target_id']['id'] = 'field_area_ref_target_id';
  $handler->display->display_options['relationships']['field_area_ref_target_id']['table'] = 'field_data_field_area_ref';
  $handler->display->display_options['relationships']['field_area_ref_target_id']['field'] = 'field_area_ref_target_id';
  $handler->display->display_options['relationships']['field_area_ref_target_id']['label'] = 'Content entity referenced from field_area_ref';
  $handler->display->display_options['relationships']['field_area_ref_target_id']['required'] = TRUE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_category_tid']['id'] = 'field_category_tid';
  $handler->display->display_options['relationships']['field_category_tid']['table'] = 'field_data_field_category';
  $handler->display->display_options['relationships']['field_category_tid']['field'] = 'field_category_tid';
  $handler->display->display_options['relationships']['field_category_tid']['label'] = 'term from field_category';
  $handler->display->display_options['relationships']['field_category_tid']['required'] = TRUE;
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
  /* Contextual filter: Content: Alias Helper (field_alias_helper) */
  $handler->display->display_options['arguments']['field_alias_helper_value']['id'] = 'field_alias_helper_value';
  $handler->display->display_options['arguments']['field_alias_helper_value']['table'] = 'field_data_field_alias_helper';
  $handler->display->display_options['arguments']['field_alias_helper_value']['field'] = 'field_alias_helper_value';
  $handler->display->display_options['arguments']['field_alias_helper_value']['relationship'] = 'field_area_ref_target_id';
  $handler->display->display_options['arguments']['field_alias_helper_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_alias_helper_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_alias_helper_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_alias_helper_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_alias_helper_value']['limit'] = '0';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_category_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'content-archive';
  $export['articles_by_category'] = $view;

  $view = new view();
  $view->name = 'categories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Categories';
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
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Relationship: Content: Category (field_category) */
  $handler->display->display_options['relationships']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['relationships']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_category_value']['delta'] = '-1';
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
  /* Contextual filter: Taxonomy Entity Index: Has taxonomy term ID on Field collection item (with depth and indexed in taxonomy_entity_index) */
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['id'] = 'taxonomy_entity_index_tid_depth';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['field'] = 'taxonomy_entity_index_tid_depth';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['relationship'] = 'field_category_value';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['depth'] = '0';
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
  $export['categories'] = $view;

  $view = new view();
  $view->name = 'featured_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Featured Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Featured Articles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'featured';
  $handler->display->display_options['row_options']['links'] = FALSE;
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
  /* Filter criterion: Content: Featured on Homepage (field_featured_homepage) */
  $handler->display->display_options['filters']['field_featured_homepage_value']['id'] = 'field_featured_homepage_value';
  $handler->display->display_options['filters']['field_featured_homepage_value']['table'] = 'field_data_field_featured_homepage';
  $handler->display->display_options['filters']['field_featured_homepage_value']['field'] = 'field_featured_homepage_value';
  $handler->display->display_options['filters']['field_featured_homepage_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['featured_articles'] = $view;

  $view = new view();
  $view->name = 'global_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Global Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Global Articles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Category (field_category) */
  $handler->display->display_options['relationships']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['relationships']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['delta'] = '-1';
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
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/global-articles';
  $export['global_articles'] = $view;

  $view = new view();
  $view->name = 'homepage_marquee';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage Marquee';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Homepage Marquee';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'marquee';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Content: Category (field_category) */
  $handler->display->display_options['relationships']['field_category_value']['id'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['table'] = 'field_data_field_category';
  $handler->display->display_options['relationships']['field_category_value']['field'] = 'field_category_value';
  $handler->display->display_options['relationships']['field_category_value']['delta'] = '0';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'home_slider',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Category */
  $handler->display->display_options['fields']['field_category_ref']['id'] = 'field_category_ref';
  $handler->display->display_options['fields']['field_category_ref']['table'] = 'field_data_field_category_ref';
  $handler->display->display_options['fields']['field_category_ref']['field'] = 'field_category_ref';
  $handler->display->display_options['fields']['field_category_ref']['relationship'] = 'field_category_value';
  $handler->display->display_options['fields']['field_category_ref']['label'] = '';
  $handler->display->display_options['fields']['field_category_ref']['element_type'] = '0';
  $handler->display->display_options['fields']['field_category_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_category_ref']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_category_ref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_category_ref']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_category_ref']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Deck */
  $handler->display->display_options['fields']['field_deck']['id'] = 'field_deck';
  $handler->display->display_options['fields']['field_deck']['table'] = 'field_data_field_deck';
  $handler->display->display_options['fields']['field_deck']['field'] = 'field_deck';
  $handler->display->display_options['fields']['field_deck']['label'] = '';
  $handler->display->display_options['fields']['field_deck']['element_type'] = '0';
  $handler->display->display_options['fields']['field_deck']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deck']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_deck']['element_default_classes'] = FALSE;
  /* Field: Content: Short Description */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = '';
  $handler->display->display_options['fields']['field_short_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_short_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_short_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_short_description']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Publish on (field_publish_on) */
  $handler->display->display_options['sorts']['field_publish_on_value']['id'] = 'field_publish_on_value';
  $handler->display->display_options['sorts']['field_publish_on_value']['table'] = 'field_data_field_publish_on';
  $handler->display->display_options['sorts']['field_publish_on_value']['field'] = 'field_publish_on_value';
  $handler->display->display_options['sorts']['field_publish_on_value']['order'] = 'DESC';
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
    'article_quiz' => 'article_quiz',
    'article_slideshow' => 'article_slideshow',
    'article' => 'article',
    'top_100' => 'top_100',
    'top_cities_list' => 'top_cities_list',
  );
  /* Filter criterion: Content: Featured on Homepage (field_featured_homepage) */
  $handler->display->display_options['filters']['field_featured_homepage_value']['id'] = 'field_featured_homepage_value';
  $handler->display->display_options['filters']['field_featured_homepage_value']['table'] = 'field_data_field_featured_homepage';
  $handler->display->display_options['filters']['field_featured_homepage_value']['field'] = 'field_featured_homepage_value';
  $handler->display->display_options['filters']['field_featured_homepage_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['homepage_marquee'] = $view;

  $view = new view();
  $view->name = 'related_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Articles';
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
  $handler->display->display_options['relationships']['field_category_value']['delta'] = '-1';
  /* Relationship: Content: Place (field_place) */
  $handler->display->display_options['relationships']['field_place_value']['id'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['table'] = 'field_data_field_place';
  $handler->display->display_options['relationships']['field_place_value']['field'] = 'field_place_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Category (field_category_ref) */
  $handler->display->display_options['arguments']['field_category_ref_tid']['id'] = 'field_category_ref_tid';
  $handler->display->display_options['arguments']['field_category_ref_tid']['table'] = 'field_data_field_category_ref';
  $handler->display->display_options['arguments']['field_category_ref_tid']['field'] = 'field_category_ref_tid';
  $handler->display->display_options['arguments']['field_category_ref_tid']['relationship'] = 'field_category_value';
  $handler->display->display_options['arguments']['field_category_ref_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_category_ref_tid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_category_ref_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_category_ref_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_category_ref_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_category_ref_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_category_ref_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_category_ref_tid']['validate_options']['code'] = '$node = node_load($argument);
if (isset($node->field_category[\'und\']) && !is_null($node->field_category[\'und\'][0][\'value\'])) {
    $catentity = entity_load(\'field_collection_item\',array($node->field_category[\'und\'][0][\'value\']));
    if(isset($catentity[$node->field_category[\'und\'][0][\'value\']]->field_category_ref[\'und\'])) {
      $handler->argument = $catentity[$node->field_category[\'und\'][0][\'value\']]->field_category_ref[\'und\'][0][\'tid\'];
      return TRUE;
    }
}
return FALSE;';
  /* Contextual filter: Field: Place name (field_place_ref) */
  $handler->display->display_options['arguments']['field_place_ref_target_id']['id'] = 'field_place_ref_target_id';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['table'] = 'field_data_field_place_ref';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['field'] = 'field_place_ref_target_id';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['relationship'] = 'field_place_value';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_place_ref_target_id']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['validate_options']['code'] = '$node = node_load($argument);
if (isset($node->field_place[\'und\']) && !is_null($node->field_place[\'und\'][0][\'value\'])) {
    $placeentity = entity_load(\'field_collection_item\',array($node->field_place[\'und\'][0][\'value\']));
    if (isset($placeentity[$node->field_place[\'und\'][0][\'value\']]->field_place_ref[\'und\'])) {
      $handler->argument = $placeentity[$node->field_place[\'und\'][0][\'value\']]->field_place_ref[\'und\'][0][\'target_id\'];
      return TRUE;
    }
}
return FALSE;';
  $handler->display->display_options['arguments']['field_place_ref_target_id']['validate']['fail'] = 'ignore';

  /* Display: DM Block */
  $handler = $view->new_display('block', 'DM Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'one-third';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'clearfix article-slider';
  $handler->display->display_options['style_options']['wrapper_class'] = 'three-wide';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'tile';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Place (field_place) */
  $handler->display->display_options['relationships']['field_place_value']['id'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['table'] = 'field_data_field_place';
  $handler->display->display_options['relationships']['field_place_value']['field'] = 'field_place_value';
  $handler->display->display_options['relationships']['field_place_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_place_ref_target_id']['id'] = 'field_place_ref_target_id';
  $handler->display->display_options['relationships']['field_place_ref_target_id']['table'] = 'field_data_field_place_ref';
  $handler->display->display_options['relationships']['field_place_ref_target_id']['field'] = 'field_place_ref_target_id';
  $handler->display->display_options['relationships']['field_place_ref_target_id']['relationship'] = 'field_place_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_place_ref_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = '$node = node_load($argument);
if (isset($node->field_city[\'und\'][0]) && !is_null($node->field_city[\'und\'][0][\'target_id\'])) {
    $handler->argument = $node->field_city[\'und\'][0][\'target_id\'];
    $argument = $handler->argument;
    return $argument;
}
elseif (isset($node->field_gallery_city[\'und\'][0]) && !is_null($node->field_gallery_city[\'und\'][0][\'target_id\'])) {
    $handler->argument = $node->field_gallery_city[\'und\'][0][\'target_id\'];
    $argument = $handler->argument;
    return $argument;
}
return FALSE;';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['label'] = 'field_state';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h3>Articles related to <strong>[title], [field_state_code]</strong></h3>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = '$node = node_load($argument);
if (isset($node->field_city[\'und\']) && !is_null($node->field_city[\'und\'][0][\'target_id\'])) {
    $handler->argument = $node->field_city[\'und\'][0][\'target_id\'];
    $argument = $handler->argument;
    return $argument;
}
elseif (isset($node->field_gallery_city[\'und\']) && !is_null($node->field_gallery_city[\'und\'][0][\'target_id\'])) {
    $handler->argument = $node->field_gallery_city[\'und\'][0][\'target_id\'];
    $argument = $handler->argument;
    return $argument;
}
return FALSE;';
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
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
    'block' => 0,
  );
  $export['related_articles'] = $view;

  $view = new view();
  $view->name = 'topics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Topics';
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
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = '%1';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['name']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['name']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['name']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['name']['validate_options']['vocabularies'] = array(
    'category' => 'category',
  );
  $handler->display->display_options['arguments']['name']['validate_options']['type'] = 'name';
  $handler->display->display_options['arguments']['name']['validate_options']['transform'] = TRUE;
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
    'article_quiz' => 'article_quiz',
    'article_slideshow' => 'article_slideshow',
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
    11 => '11',
    12 => '12',
    13 => '13',
    14 => '14',
    15 => '15',
    16 => '16',
    17 => '17',
    18 => '18',
  );
  $handler->display->display_options['filters']['field_category_ref_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_category_ref_tid']['vocabulary'] = 'category';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Best Places Topics';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'topics';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_category_ref_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['name']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['name']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['name']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $export['topics'] = $view;

  return $export;
}
