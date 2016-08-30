<?php
/**
 * @file
 * best_places.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function best_places_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'best_places';
  $view->description = '';
  $view->tag = 'best places';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Best Places';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Top 10';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'best_places_landing_page:block';
  $handler->display->display_options['empty']['view']['inherit_arguments'] = TRUE;
  /* Relationship: Field collection item: Entity with the List item (field_list_item) */
  $handler->display->display_options['relationships']['field_list_item_node']['id'] = 'field_list_item_node';
  $handler->display->display_options['relationships']['field_list_item_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_list_item_node']['field'] = 'field_list_item_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_city_target_id']['id'] = 'field_city_target_id';
  $handler->display->display_options['relationships']['field_city_target_id']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_target_id']['field'] = 'field_city_target_id';
  /* Relationship: state from city */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['relationship'] = 'field_city_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['ui_name'] = 'state from city';
  $handler->display->display_options['relationships']['field_state_target_id']['label'] = 'state from city';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image_single']['id'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['table'] = 'field_data_field_image_single';
  $handler->display->display_options['fields']['field_image_single']['field'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['label'] = '';
  $handler->display->display_options['fields']['field_image_single']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_single']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_single']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_single']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_single']['settings'] = array(
    'image_style' => 'article_top',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_single']['field_api_classes'] = TRUE;
  /* Field: Field: Highlights */
  $handler->display->display_options['fields']['field_highlights']['id'] = 'field_highlights';
  $handler->display->display_options['fields']['field_highlights']['table'] = 'field_data_field_highlights';
  $handler->display->display_options['fields']['field_highlights']['field'] = 'field_highlights';
  $handler->display->display_options['fields']['field_highlights']['label'] = '';
  $handler->display->display_options['fields']['field_highlights']['element_type'] = '0';
  $handler->display->display_options['fields']['field_highlights']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_highlights']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_highlights']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_highlights']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_highlights']['field_api_classes'] = TRUE;
  /* Field: Field: Person */
  $handler->display->display_options['fields']['field_quote_attribution']['id'] = 'field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['table'] = 'field_data_field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['field'] = 'field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['label'] = '';
  $handler->display->display_options['fields']['field_quote_attribution']['element_type'] = '0';
  $handler->display->display_options['fields']['field_quote_attribution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_quote_attribution']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_quote_attribution']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_quote_attribution']['field_api_classes'] = TRUE;
  /* Field: Field: Quote */
  $handler->display->display_options['fields']['field_pull_quote']['id'] = 'field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['table'] = 'field_data_field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['field'] = 'field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['label'] = '';
  $handler->display->display_options['fields']['field_pull_quote']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pull_quote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pull_quote']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_pull_quote']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pull_quote']['field_api_classes'] = TRUE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_professional_title']['id'] = 'field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['table'] = 'field_data_field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['field'] = 'field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['label'] = '';
  $handler->display->display_options['fields']['field_professional_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_professional_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_professional_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_professional_title']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Body */
  $handler->display->display_options['fields']['field_bp_body']['id'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['table'] = 'field_data_field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['field'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['label'] = '';
  $handler->display->display_options['fields']['field_bp_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['field_api_classes'] = TRUE;
  /* Field: Content: List item */
  $handler->display->display_options['fields']['field_list_item']['id'] = 'field_list_item';
  $handler->display->display_options['fields']['field_list_item']['table'] = 'field_data_field_list_item';
  $handler->display->display_options['fields']['field_list_item']['field'] = 'field_list_item';
  $handler->display->display_options['fields']['field_list_item']['relationship'] = 'field_list_item_node';
  $handler->display->display_options['fields']['field_list_item']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_list_item']['type'] = 'field_collection_view';
  $handler->display->display_options['fields']['field_list_item']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_list_item']['delta_offset'] = '0';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_bp_category']['id'] = 'field_bp_category';
  $handler->display->display_options['fields']['field_bp_category']['table'] = 'field_data_field_bp_category';
  $handler->display->display_options['fields']['field_bp_category']['field'] = 'field_bp_category';
  $handler->display->display_options['fields']['field_bp_category']['relationship'] = 'field_list_item_node';
  $handler->display->display_options['fields']['field_bp_category']['label'] = '';
  $handler->display->display_options['fields']['field_bp_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bp_category']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_bp_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bp_category']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bp_category']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_list_item_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['relationship'] = 'field_list_item_node';
  $handler->display->display_options['fields']['field_year']['label'] = '';
  $handler->display->display_options['fields']['field_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_year']['element_type'] = '0';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_year']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_year']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_year']['field_api_classes'] = TRUE;
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title_1']['id'] = 'title_1';
  $handler->display->display_options['arguments']['title_1']['table'] = 'node';
  $handler->display->display_options['arguments']['title_1']['field'] = 'title';
  $handler->display->display_options['arguments']['title_1']['relationship'] = 'field_list_item_node';
  $handler->display->display_options['arguments']['title_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title_1']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['title_1']['validate_options']['code'] = 'if (NULL != arg(3)) {
$title = db_query(\'SELECT n.title FROM node n LEFT JOIN url_alias a ON a.source = CONCAT(\\\'node/\\\',n.nid) LEFT JOIN field_data_field_year y ON y.entity_id = n.nid WHERE a.alias LIKE :arg AND y.field_year_value = :year\', array(\':arg\' => \'%\'.$argument.\'%\', \':year\' => arg(3).\'-01-01 000:00:00\'))->fetchAll();
if (!empty($title[0])) { $handler->argument = $title[0]->title; return TRUE; }
else { $title = db_query(\'SELECT n.title FROM node n LEFT JOIN field_data_field_year y ON y.entity_id = n.nid WHERE n.title LIKE :arg AND y.field_year_value = :year\', array(":arg" => \'%\'.$argument.\'%\', \':year\' => arg(3).\'-01-01 000:00:00\'))->fetchAll();
 if (!empty($title[0])) { $handler->argument = $title[0]->title; return TRUE; }
 else {return FALSE;}
}
}';
  $handler->display->display_options['arguments']['title_1']['limit'] = '0';
  /* Contextual filter: Content: Year (field_year) */
  $handler->display->display_options['arguments']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['arguments']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['relationship'] = 'field_list_item_node';
  $handler->display->display_options['arguments']['field_year_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['field_year_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_year_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_year_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_year_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_year_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_year_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['validate_options']['code'] = '$handler->argument = $argument.\'-01-01 000:00:00\';
return TRUE;';
  $handler->display->display_options['arguments']['field_year_value']['validate']['fail'] = 'summary';
  $handler->display->display_options['arguments']['field_year_value']['year_range'] = '-10:+3';
  $handler->display->display_options['arguments']['field_year_value']['use_fromto'] = 'no';
  /* Contextual filter: Content: State Code (field_state_code) */
  $handler->display->display_options['arguments']['field_state_code_value']['id'] = 'field_state_code_value';
  $handler->display->display_options['arguments']['field_state_code_value']['table'] = 'field_data_field_state_code';
  $handler->display->display_options['arguments']['field_state_code_value']['field'] = 'field_state_code_value';
  $handler->display->display_options['arguments']['field_state_code_value']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['arguments']['field_state_code_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_state_code_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_state_code_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_state_code_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_state_code_value']['limit'] = '0';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_city_target_id';
  $handler->display->display_options['arguments']['title']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['title']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['title']['title'] = '%5, %4';
  $handler->display->display_options['arguments']['title']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['title']['breadcrumb'] = '!3';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['arguments']['title']['case'] = 'ucwords';
  $handler->display->display_options['arguments']['title']['transform_dash'] = TRUE;

  /* Display: Best Places Items Page */
  $handler = $view->new_display('page', 'Best Places Items Page', 'page');
  $handler->display->display_options['path'] = 'top-10/%/%/%/%/%';
  $export['best_places'] = $view;

  $view = new view();
  $view->name = 'best_places_landing_page';
  $view->description = 'Provides a block for Best Places conditional validation errors';
  $view->tag = 'best places';
  $view->base_table = 'node';
  $view->human_name = 'Best Places Landing Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Best Places To Live';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'marquee';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_bp_category']['id'] = 'field_bp_category';
  $handler->display->display_options['fields']['field_bp_category']['table'] = 'field_data_field_bp_category';
  $handler->display->display_options['fields']['field_bp_category']['field'] = 'field_bp_category';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  /* Sort criterion: Content: Publish on (field_publish_on) */
  $handler->display->display_options['sorts']['field_publish_on_value']['id'] = 'field_publish_on_value';
  $handler->display->display_options['sorts']['field_publish_on_value']['table'] = 'field_data_field_publish_on';
  $handler->display->display_options['sorts']['field_publish_on_value']['field'] = 'field_publish_on_value';
  $handler->display->display_options['sorts']['field_publish_on_value']['order'] = 'DESC';
  /* Contextual filter: Content: Category (field_bp_category) */
  $handler->display->display_options['arguments']['field_bp_category_tid']['id'] = 'field_bp_category_tid';
  $handler->display->display_options['arguments']['field_bp_category_tid']['table'] = 'field_data_field_bp_category';
  $handler->display->display_options['arguments']['field_bp_category_tid']['field'] = 'field_bp_category_tid';
  $handler->display->display_options['arguments']['field_bp_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_bp_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_bp_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_bp_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_bp_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_bp_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_bp_category_tid']['validate_options']['vocabularies'] = array(
    'best_places' => 'best_places',
  );
  $handler->display->display_options['arguments']['field_bp_category_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_bp_category_tid']['validate_options']['transform'] = TRUE;
  /* Contextual filter: Content: Year (field_year) */
  $handler->display->display_options['arguments']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['arguments']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_year_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_year_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_year_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_year_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_year_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['validate_options']['code'] = '$handler->argument = $argument.\'-01-01 000:00:00\';
return TRUE;';
  $handler->display->display_options['arguments']['field_year_value']['validate']['fail'] = 'summary';
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
    'best_places' => 'best_places',
  );
  /* Filter criterion: Content: Image (field_image:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_image';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['operator'] = 'not empty';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Best Places Landing Page';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Other Lists */
  $handler = $view->new_display('block', 'Other Lists', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'related';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;

  /* Display: Top 10 Page */
  $handler = $view->new_display('page', 'Top 10 Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Top 10 Lists';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2>Recent Top 10</h2>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'top-10';

  /* Display: Recent Block */
  $handler = $view->new_display('block', 'Recent Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_bp_category']['id'] = 'field_bp_category';
  $handler->display->display_options['fields']['field_bp_category']['table'] = 'field_data_field_bp_category';
  $handler->display->display_options['fields']['field_bp_category']['field'] = 'field_bp_category';
  $handler->display->display_options['fields']['field_bp_category']['label'] = '';
  $handler->display->display_options['fields']['field_bp_category']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bp_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bp_category']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bp_category']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bp_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;

  /* Display: Marquee */
  $handler = $view->new_display('block', 'Marquee', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Category (field_bp_category) */
  $handler->display->display_options['arguments']['field_bp_category_tid']['id'] = 'field_bp_category_tid';
  $handler->display->display_options['arguments']['field_bp_category_tid']['table'] = 'field_data_field_bp_category';
  $handler->display->display_options['arguments']['field_bp_category_tid']['field'] = 'field_bp_category_tid';
  $handler->display->display_options['arguments']['field_bp_category_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_bp_category_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_bp_category_tid']['default_argument_options']['code'] = 'if (arg(1)) {
  return arg(1);
}
return \'all\';';
  $handler->display->display_options['arguments']['field_bp_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_bp_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_bp_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_bp_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_bp_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_bp_category_tid']['validate_options']['vocabularies'] = array(
    'best_places' => 'best_places',
  );
  $handler->display->display_options['arguments']['field_bp_category_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_bp_category_tid']['validate_options']['transform'] = TRUE;
  /* Contextual filter: Content: Year (field_year) */
  $handler->display->display_options['arguments']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['arguments']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_year_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_year_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_year_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_year_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_year_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['validate_options']['code'] = '$handler->argument = $argument.\'-01-01 000:00:00\';
return TRUE;';
  $handler->display->display_options['arguments']['field_year_value']['validate']['fail'] = 'summary';
  $export['best_places_landing_page'] = $view;

  return $export;
}
