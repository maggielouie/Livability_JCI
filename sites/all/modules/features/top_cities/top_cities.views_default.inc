<?php
/**
 * @file
 * top_cities.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function top_cities_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'top_cities_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Top Cities Lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Top Cities List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'top-100-city clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'clearfix';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = 'Livability.com\'s ranking of the Best Places to Live includes cities and towns with populations between 20,000 to 350,000. Ties are broken by unrounded numbers. Please see the full <a href="[path]/methodology">methodology</a> for data sources and details.';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  /* Relationship: Content: List (field_top_100_item) */
  $handler->display->display_options['relationships']['field_top_100_item_value']['id'] = 'field_top_100_item_value';
  $handler->display->display_options['relationships']['field_top_100_item_value']['table'] = 'field_data_field_top_100_item';
  $handler->display->display_options['relationships']['field_top_100_item_value']['field'] = 'field_top_100_item_value';
  $handler->display->display_options['relationships']['field_top_100_item_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_top_100_item_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['id'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['field'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['required'] = TRUE;
  /* Field: Field collection item: Rank */
  $handler->display->display_options['fields']['field_rank']['id'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['table'] = 'field_data_field_rank';
  $handler->display->display_options['fields']['field_rank']['field'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_rank']['label'] = '';
  $handler->display->display_options['fields']['field_rank']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rank']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_rank']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_rank']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_rank']['field_api_classes'] = TRUE;
  /* Field: Field collection item: LivScore */
  $handler->display->display_options['fields']['field_livscore']['id'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['table'] = 'field_data_field_livscore';
  $handler->display->display_options['fields']['field_livscore']['field'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_livscore']['label'] = '';
  $handler->display->display_options['fields']['field_livscore']['element_type'] = '0';
  $handler->display->display_options['fields']['field_livscore']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_livscore']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_livscore']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_livscore']['field_api_classes'] = TRUE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image_single']['id'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['table'] = 'field_data_field_image_single';
  $handler->display->display_options['fields']['field_image_single']['field'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_image_single']['label'] = '';
  $handler->display->display_options['fields']['field_image_single']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image_single']['alter']['text'] = '<span class="city-image">[field_image_single]</span>';
  $handler->display->display_options['fields']['field_image_single']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_single']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_single']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_single']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_single']['settings'] = array(
    'image_style' => '325x216',
    'image_link' => '',
  );
  /* Field: State Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = 'State Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_state_code']['field_api_classes'] = TRUE;
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_top_100_city']['id'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['field'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_top_100_city']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_city']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_top_100_city']['alter']['text'] = '<h2>[field_top_100_city]<span> [title]</span></h2>';
  $handler->display->display_options['fields']['field_top_100_city']['element_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_city']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field collection item: Body */
  $handler->display->display_options['fields']['field_bp_body']['id'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['table'] = 'field_data_field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['field'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_bp_body']['label'] = '';
  $handler->display->display_options['fields']['field_bp_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bp_body']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="city-info">[field_bp_body]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'top_cities_list' => 'top_cities_list',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'top_cities_block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '11';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '<';
  $handler->display->display_options['pager']['options']['tags']['next'] = '>';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['block_description'] = 'Top Cities Main Block';

  /* Display: Ranking Criteria */
  $handler = $view->new_display('page', 'Ranking Criteria', 'ranking_criteria');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Ranking Criteria Page (field_top_100_ranking_page) */
  $handler->display->display_options['relationships']['field_top_100_ranking_page_value']['id'] = 'field_top_100_ranking_page_value';
  $handler->display->display_options['relationships']['field_top_100_ranking_page_value']['table'] = 'field_data_field_top_100_ranking_page';
  $handler->display->display_options['relationships']['field_top_100_ranking_page_value']['field'] = 'field_top_100_ranking_page_value';
  $handler->display->display_options['relationships']['field_top_100_ranking_page_value']['delta'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Ranking Criteria */
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['id'] = 'field_top_100_ranking_criteria';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['table'] = 'field_data_field_top_100_ranking_criteria';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['field'] = 'field_top_100_ranking_criteria';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['relationship'] = 'field_top_100_ranking_page_value';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['element_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['type'] = 'field_collection_view';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria']['field_api_classes'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/ranking-criteria';

  /* Display: Advisory Board */
  $handler = $view->new_display('page', 'Advisory Board', 'advisory_board');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Advisory Board Page (field_top_100_advisory_board_pag) */
  $handler->display->display_options['relationships']['field_top_100_advisory_board_pag_value']['id'] = 'field_top_100_advisory_board_pag_value';
  $handler->display->display_options['relationships']['field_top_100_advisory_board_pag_value']['table'] = 'field_data_field_top_100_advisory_board_pag';
  $handler->display->display_options['relationships']['field_top_100_advisory_board_pag_value']['field'] = 'field_top_100_advisory_board_pag_value';
  $handler->display->display_options['relationships']['field_top_100_advisory_board_pag_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_top_100_advisory_board_pag_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Advisory Board */
  $handler->display->display_options['fields']['field_top_100_advisory_board']['id'] = 'field_top_100_advisory_board';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['table'] = 'field_data_field_top_100_advisory_board';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['field'] = 'field_top_100_advisory_board';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['relationship'] = 'field_top_100_advisory_board_pag_value';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['element_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_board']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_board']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_top_100_advisory_board']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_board']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['field_api_classes'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/advisory-board';

  /* Display: Ranking Methodology */
  $handler = $view->new_display('page', 'Ranking Methodology', 'methodology');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Ranking Methodology Page (field_ranking_methodology_page) */
  $handler->display->display_options['relationships']['field_ranking_methodology_page_value']['id'] = 'field_ranking_methodology_page_value';
  $handler->display->display_options['relationships']['field_ranking_methodology_page_value']['table'] = 'field_data_field_ranking_methodology_page';
  $handler->display->display_options['relationships']['field_ranking_methodology_page_value']['field'] = 'field_ranking_methodology_page_value';
  $handler->display->display_options['relationships']['field_ranking_methodology_page_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_ranking_methodology_page_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2>Methodology</h2>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_ranking_methodology_page_value';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_description']['field_api_classes'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/methodology';

  /* Display: Ranking Data */
  $handler = $view->new_display('page', 'Ranking Data', 'ranking_data');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_rank' => 'field_rank',
    'field_top_100_city' => 'field_top_100_city',
    'title' => 'title',
    'nothing' => 'nothing',
    'field_livscore' => 'field_livscore',
    'field_economic_score' => 'field_economic_score',
    'field_healthcare_score' => 'field_healthcare_score',
    'field_housing_score' => 'field_housing_score',
    'field_civic_capital_score' => 'field_civic_capital_score',
    'field_education_score' => 'field_education_score',
    'field_amenities_score' => 'field_amenities_score',
    'field_demographics_score' => 'field_demographics_score',
    'field_infrastructure_score' => 'field_infrastructure_score',
  );
  $handler->display->display_options['style_options']['default'] = 'field_rank';
  $handler->display->display_options['style_options']['info'] = array(
    'field_rank' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_top_100_city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_livscore' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_economic_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_healthcare_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_housing_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_civic_capital_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_education_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_amenities_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_demographics_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_infrastructure_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: List (field_top_100_item) */
  $handler->display->display_options['relationships']['field_top_100_item_value']['id'] = 'field_top_100_item_value';
  $handler->display->display_options['relationships']['field_top_100_item_value']['table'] = 'field_data_field_top_100_item';
  $handler->display->display_options['relationships']['field_top_100_item_value']['field'] = 'field_top_100_item_value';
  $handler->display->display_options['relationships']['field_top_100_item_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_top_100_item_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['id'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['field'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Rank */
  $handler->display->display_options['fields']['field_rank']['id'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['table'] = 'field_data_field_rank';
  $handler->display->display_options['fields']['field_rank']['field'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_rank']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_rank']['alter']['text'] = '<span class="city-rank">#[field_rank]</span>';
  $handler->display->display_options['fields']['field_rank']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_class'] = 'rank';
  $handler->display->display_options['fields']['field_rank']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_wrapper_class'] = 'rank';
  $handler->display->display_options['fields']['field_rank']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_top_100_city']['id'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['field'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_top_100_city']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_top_100_city']['element_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_city']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'city';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'City <br/>State';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="city">[field_top_100_city]</span><br/><span class="state">[title]</span>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'city';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_class'] = 'city';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'css';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Field collection item: LivScore */
  $handler->display->display_options['fields']['field_livscore']['id'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['table'] = 'field_data_field_livscore';
  $handler->display->display_options['fields']['field_livscore']['field'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_livscore']['element_type'] = '0';
  $handler->display->display_options['fields']['field_livscore']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_livscore']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_livscore']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Econ */
  $handler->display->display_options['fields']['field_economic_score']['id'] = 'field_economic_score';
  $handler->display->display_options['fields']['field_economic_score']['table'] = 'field_data_field_economic_score';
  $handler->display->display_options['fields']['field_economic_score']['field'] = 'field_economic_score';
  $handler->display->display_options['fields']['field_economic_score']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_economic_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_economic_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_economic_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_economic_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_economic_score']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Health */
  $handler->display->display_options['fields']['field_healthcare_score']['id'] = 'field_healthcare_score';
  $handler->display->display_options['fields']['field_healthcare_score']['table'] = 'field_data_field_healthcare_score';
  $handler->display->display_options['fields']['field_healthcare_score']['field'] = 'field_healthcare_score';
  $handler->display->display_options['fields']['field_healthcare_score']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_healthcare_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_healthcare_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_healthcare_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_healthcare_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_healthcare_score']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Housing */
  $handler->display->display_options['fields']['field_housing_score']['id'] = 'field_housing_score';
  $handler->display->display_options['fields']['field_housing_score']['table'] = 'field_data_field_housing_score';
  $handler->display->display_options['fields']['field_housing_score']['field'] = 'field_housing_score';
  $handler->display->display_options['fields']['field_housing_score']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_housing_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_housing_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_housing_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_housing_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_housing_score']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Civic */
  $handler->display->display_options['fields']['field_civic_capital_score']['id'] = 'field_civic_capital_score';
  $handler->display->display_options['fields']['field_civic_capital_score']['table'] = 'field_data_field_civic_capital_score';
  $handler->display->display_options['fields']['field_civic_capital_score']['field'] = 'field_civic_capital_score';
  $handler->display->display_options['fields']['field_civic_capital_score']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_civic_capital_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_civic_capital_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_civic_capital_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_civic_capital_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_civic_capital_score']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Educat. */
  $handler->display->display_options['fields']['field_education_score']['id'] = 'field_education_score';
  $handler->display->display_options['fields']['field_education_score']['table'] = 'field_data_field_education_score';
  $handler->display->display_options['fields']['field_education_score']['field'] = 'field_education_score';
  $handler->display->display_options['fields']['field_education_score']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_education_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_education_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_education_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_education_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_education_score']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Amenities */
  $handler->display->display_options['fields']['field_amenities_score']['id'] = 'field_amenities_score';
  $handler->display->display_options['fields']['field_amenities_score']['table'] = 'field_data_field_amenities_score';
  $handler->display->display_options['fields']['field_amenities_score']['field'] = 'field_amenities_score';
  $handler->display->display_options['fields']['field_amenities_score']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_amenities_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_amenities_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_amenities_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_amenities_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_amenities_score']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Demo. */
  $handler->display->display_options['fields']['field_demographics_score']['id'] = 'field_demographics_score';
  $handler->display->display_options['fields']['field_demographics_score']['table'] = 'field_data_field_demographics_score';
  $handler->display->display_options['fields']['field_demographics_score']['field'] = 'field_demographics_score';
  $handler->display->display_options['fields']['field_demographics_score']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_demographics_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_demographics_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_demographics_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_demographics_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_demographics_score']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Infrast. */
  $handler->display->display_options['fields']['field_infrastructure_score']['id'] = 'field_infrastructure_score';
  $handler->display->display_options['fields']['field_infrastructure_score']['table'] = 'field_data_field_infrastructure_score';
  $handler->display->display_options['fields']['field_infrastructure_score']['field'] = 'field_infrastructure_score';
  $handler->display->display_options['fields']['field_infrastructure_score']['relationship'] = 'field_top_100_item_value';
  $handler->display->display_options['fields']['field_infrastructure_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_infrastructure_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_infrastructure_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_infrastructure_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_infrastructure_score']['field_api_classes'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'top_cities_list' => 'top_cities_list',
  );
  $handler->display->display_options['path'] = 'node/%/ranking-data';
  $export['top_cities_list'] = $view;

  return $export;
}
