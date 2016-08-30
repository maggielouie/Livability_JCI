<?php
/**
 * @file
 * top_100.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function top_100_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'top_100';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Top 100';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Top 100';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'top-100-city clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'clearfix';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  /* Relationship: Field collection item: Entity with the List (field_top_100_item) */
  $handler->display->display_options['relationships']['field_top_100_item_node']['id'] = 'field_top_100_item_node';
  $handler->display->display_options['relationships']['field_top_100_item_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_top_100_item_node']['field'] = 'field_top_100_item_node';
  $handler->display->display_options['relationships']['field_top_100_item_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['id'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['field'] = 'field_top_100_city_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  /* Field: Field collection item: Rank */
  $handler->display->display_options['fields']['field_rank']['id'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['table'] = 'field_data_field_rank';
  $handler->display->display_options['fields']['field_rank']['field'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['label'] = '';
  $handler->display->display_options['fields']['field_rank']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rank']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: LivScore */
  $handler->display->display_options['fields']['field_livscore']['id'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['table'] = 'field_data_field_livscore';
  $handler->display->display_options['fields']['field_livscore']['field'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['label'] = '';
  $handler->display->display_options['fields']['field_livscore']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_livscore']['alter']['text'] = '<span class="city-rank-container"><span class="city-rank">[field_rank]</span><span class="city-score">[field_livscore]</span></span>';
  $handler->display->display_options['fields']['field_livscore']['element_type'] = '0';
  $handler->display->display_options['fields']['field_livscore']['element_class'] = 'city-score';
  $handler->display->display_options['fields']['field_livscore']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[field_top_100_city]<span> [title]</span></h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_top_100_city']['id'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['field'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_city']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_top_100_city']['alter']['text'] = '<h2><a href="field_top_100_city-target_id">[field_top_100_city]</a><span> [title]</span></h2>';
  $handler->display->display_options['fields']['field_top_100_city']['element_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_city']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image_single']['id'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['table'] = 'field_data_field_image_single';
  $handler->display->display_options['fields']['field_image_single']['field'] = 'field_image_single';
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
  /* Field: Field collection item: Body */
  $handler->display->display_options['fields']['field_bp_body']['id'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['table'] = 'field_data_field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['field'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['label'] = '';
  $handler->display->display_options['fields']['field_bp_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bp_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_default_classes'] = FALSE;
  /* Field: Content: Median Home Price */
  $handler->display->display_options['fields']['field_median_home_price']['id'] = 'field_median_home_price';
  $handler->display->display_options['fields']['field_median_home_price']['table'] = 'field_data_field_median_home_price';
  $handler->display->display_options['fields']['field_median_home_price']['field'] = 'field_median_home_price';
  $handler->display->display_options['fields']['field_median_home_price']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['fields']['field_median_home_price']['label'] = '';
  $handler->display->display_options['fields']['field_median_home_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_median_home_price']['element_type'] = '0';
  $handler->display->display_options['fields']['field_median_home_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_median_home_price']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_median_home_price']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_median_home_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Median Household Income */
  $handler->display->display_options['fields']['field_median_household_income']['id'] = 'field_median_household_income';
  $handler->display->display_options['fields']['field_median_household_income']['table'] = 'field_data_field_median_household_income';
  $handler->display->display_options['fields']['field_median_household_income']['field'] = 'field_median_household_income';
  $handler->display->display_options['fields']['field_median_household_income']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['fields']['field_median_household_income']['label'] = '';
  $handler->display->display_options['fields']['field_median_household_income']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_median_household_income']['element_type'] = '0';
  $handler->display->display_options['fields']['field_median_household_income']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_median_household_income']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_median_household_income']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_median_household_income']['click_sort_column'] = 'amount';
  /* Field: Content: Population */
  $handler->display->display_options['fields']['field_population']['id'] = 'field_population';
  $handler->display->display_options['fields']['field_population']['table'] = 'field_data_field_population';
  $handler->display->display_options['fields']['field_population']['field'] = 'field_population';
  $handler->display->display_options['fields']['field_population']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['fields']['field_population']['label'] = '';
  $handler->display->display_options['fields']['field_population']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_population']['element_type'] = '0';
  $handler->display->display_options['fields']['field_population']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_population']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_population']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_population']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="city-info">[field_bp_body]<span class="city-stats"><dl><dt>Population:</dt><dd>[field_population]</dd><dt>Med. Household Income:</dt><dd>[field_median_household_income]</dd><dt>Med. Home Price:</dt><dd>$[field_median_home_price]</dd></dl><dl><dt>Job Growth:</dt><dd>value not set</dd></dl></span></span>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_top_100_item_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Contextual filter: Content: Year (field_year) */
  $handler->display->display_options['arguments']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['arguments']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['relationship'] = 'field_top_100_item_node';
  $handler->display->display_options['arguments']['field_year_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['field_year_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_year_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_year_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_year_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_year_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['validate_options']['code'] = '$len = strlen($argument);
if ($len == 4) {
$handler->argument = $argument.\'-01-01 000:00:00\';
}
return TRUE;';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_top_100_item_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'top_100' => 'top_100',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = 'Livability.com\'s ranking of the Best Places to Live includes cities and towns with populations between 20,000 to 350,000. Ties are broken by unrounded numbers. Please see the full <a href="/best-places/top-100-best-places-to-live/!1/methodology">methodology</a> for data sources and details.';
  $handler->display->display_options['footer']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the List (field_top_100_item) */
  $handler->display->display_options['relationships']['field_top_100_item_node']['id'] = 'field_top_100_item_node';
  $handler->display->display_options['relationships']['field_top_100_item_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_top_100_item_node']['field'] = 'field_top_100_item_node';
  $handler->display->display_options['relationships']['field_top_100_item_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['id'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['field'] = 'field_top_100_city_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Rank */
  $handler->display->display_options['fields']['field_rank']['id'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['table'] = 'field_data_field_rank';
  $handler->display->display_options['fields']['field_rank']['field'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['label'] = '';
  $handler->display->display_options['fields']['field_rank']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rank']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: LivScore */
  $handler->display->display_options['fields']['field_livscore']['id'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['table'] = 'field_data_field_livscore';
  $handler->display->display_options['fields']['field_livscore']['field'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['label'] = '';
  $handler->display->display_options['fields']['field_livscore']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_livscore']['alter']['text'] = '<span class="city-rank-container"><span class="city-rank">[field_rank]</span><span class="city-score">[field_livscore]</span></span>';
  $handler->display->display_options['fields']['field_livscore']['element_type'] = '0';
  $handler->display->display_options['fields']['field_livscore']['element_class'] = 'city-score';
  $handler->display->display_options['fields']['field_livscore']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[field_top_100_city]<span> [title]</span></h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_top_100_city']['id'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['field'] = 'field_top_100_city';
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
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image_single']['id'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['table'] = 'field_data_field_image_single';
  $handler->display->display_options['fields']['field_image_single']['field'] = 'field_image_single';
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
  /* Field: Field collection item: Body */
  $handler->display->display_options['fields']['field_bp_body']['id'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['table'] = 'field_data_field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['field'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['label'] = '';
  $handler->display->display_options['fields']['field_bp_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bp_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_default_classes'] = FALSE;
  /* Field: Content: Median Home Price */
  $handler->display->display_options['fields']['field_median_home_price']['id'] = 'field_median_home_price';
  $handler->display->display_options['fields']['field_median_home_price']['table'] = 'field_data_field_median_home_price';
  $handler->display->display_options['fields']['field_median_home_price']['field'] = 'field_median_home_price';
  $handler->display->display_options['fields']['field_median_home_price']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['fields']['field_median_home_price']['label'] = '';
  $handler->display->display_options['fields']['field_median_home_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_median_home_price']['element_type'] = '0';
  $handler->display->display_options['fields']['field_median_home_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_median_home_price']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_median_home_price']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_median_home_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Median Household Income */
  $handler->display->display_options['fields']['field_median_household_income']['id'] = 'field_median_household_income';
  $handler->display->display_options['fields']['field_median_household_income']['table'] = 'field_data_field_median_household_income';
  $handler->display->display_options['fields']['field_median_household_income']['field'] = 'field_median_household_income';
  $handler->display->display_options['fields']['field_median_household_income']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['fields']['field_median_household_income']['label'] = '';
  $handler->display->display_options['fields']['field_median_household_income']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_median_household_income']['element_type'] = '0';
  $handler->display->display_options['fields']['field_median_household_income']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_median_household_income']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_median_household_income']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_median_household_income']['click_sort_column'] = 'amount';
  /* Field: Content: Population */
  $handler->display->display_options['fields']['field_population']['id'] = 'field_population';
  $handler->display->display_options['fields']['field_population']['table'] = 'field_data_field_population';
  $handler->display->display_options['fields']['field_population']['field'] = 'field_population';
  $handler->display->display_options['fields']['field_population']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['fields']['field_population']['label'] = '';
  $handler->display->display_options['fields']['field_population']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_population']['element_type'] = '0';
  $handler->display->display_options['fields']['field_population']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_population']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_population']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_population']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_top_100_city_1']['id'] = 'field_top_100_city_1';
  $handler->display->display_options['fields']['field_top_100_city_1']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city_1']['field'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city_1']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_city_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_top_100_city_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="city-info">[field_bp_body]<span class="city-stats"><h4>Facts about [field_top_100_city_1]</h4><dl><dt>Population:</dt><dd>[field_population]</dd><dt>Med. Household Income:</dt><dd>[field_median_household_income]</dd><dt>Med. Home Price:</dt><dd>$[field_median_home_price]</dd></dl></span></span>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_top_100_item_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['path'] = 'best-places/top-100-best-places-to-live/%';

  /* Display: Ranking Data */
  $handler = $view->new_display('page', 'Ranking Data', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_rank' => 'field_rank',
    'field_top_100_city' => 'title',
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
    'nid' => 'nid',
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
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => 'views-align-left',
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
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = 'Livability.com\'s ranking of the Best Places to Live includes cities and towns with populations between 20,000 to 350,000. Ties are broken by unrounded numbers. Please see the full <a href="/best-places/top-100-best-places-to-live/!1/methodology">methodology</a> for data sources and details.';
  $handler->display->display_options['footer']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the List (field_top_100_item) */
  $handler->display->display_options['relationships']['field_top_100_item_node']['id'] = 'field_top_100_item_node';
  $handler->display->display_options['relationships']['field_top_100_item_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_top_100_item_node']['field'] = 'field_top_100_item_node';
  $handler->display->display_options['relationships']['field_top_100_item_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['id'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['field'] = 'field_top_100_city_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Rank */
  $handler->display->display_options['fields']['field_rank']['id'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['table'] = 'field_data_field_rank';
  $handler->display->display_options['fields']['field_rank']['field'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['label'] = 'Liv 100<br/>Rank';
  $handler->display->display_options['fields']['field_rank']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_rank']['alter']['text'] = '<span class="city-rank">#[field_rank]</span>';
  $handler->display->display_options['fields']['field_rank']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_class'] = 'rank';
  $handler->display->display_options['fields']['field_rank']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_wrapper_class'] = 'rank';
  $handler->display->display_options['fields']['field_rank']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_top_100_city']['id'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['field'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_top_100_city']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_top_100_city']['element_class'] = 'city';
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
  $handler->display->display_options['fields']['title']['label'] = 'City State';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_class'] = 'city';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'City<br />State';
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
  $handler->display->display_options['fields']['field_livscore']['label'] = 'Livability Score';
  $handler->display->display_options['fields']['field_livscore']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_livscore']['alter']['text'] = '<span class="city-score">[field_livscore]</span>';
  $handler->display->display_options['fields']['field_livscore']['element_type'] = '0';
  $handler->display->display_options['fields']['field_livscore']['element_class'] = 'score';
  $handler->display->display_options['fields']['field_livscore']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Econ */
  $handler->display->display_options['fields']['field_economic_score']['id'] = 'field_economic_score';
  $handler->display->display_options['fields']['field_economic_score']['table'] = 'field_data_field_economic_score';
  $handler->display->display_options['fields']['field_economic_score']['field'] = 'field_economic_score';
  $handler->display->display_options['fields']['field_economic_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_economic_score']['element_class'] = 'economic';
  $handler->display->display_options['fields']['field_economic_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_economic_score']['element_wrapper_class'] = 'economic';
  $handler->display->display_options['fields']['field_economic_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_economic_score']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Health */
  $handler->display->display_options['fields']['field_healthcare_score']['id'] = 'field_healthcare_score';
  $handler->display->display_options['fields']['field_healthcare_score']['table'] = 'field_data_field_healthcare_score';
  $handler->display->display_options['fields']['field_healthcare_score']['field'] = 'field_healthcare_score';
  $handler->display->display_options['fields']['field_healthcare_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_healthcare_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_healthcare_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_healthcare_score']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Housing */
  $handler->display->display_options['fields']['field_housing_score']['id'] = 'field_housing_score';
  $handler->display->display_options['fields']['field_housing_score']['table'] = 'field_data_field_housing_score';
  $handler->display->display_options['fields']['field_housing_score']['field'] = 'field_housing_score';
  $handler->display->display_options['fields']['field_housing_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_housing_score']['element_class'] = 'housing';
  $handler->display->display_options['fields']['field_housing_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_housing_score']['element_wrapper_class'] = 'housing';
  $handler->display->display_options['fields']['field_housing_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_housing_score']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Civic */
  $handler->display->display_options['fields']['field_civic_capital_score']['id'] = 'field_civic_capital_score';
  $handler->display->display_options['fields']['field_civic_capital_score']['table'] = 'field_data_field_civic_capital_score';
  $handler->display->display_options['fields']['field_civic_capital_score']['field'] = 'field_civic_capital_score';
  $handler->display->display_options['fields']['field_civic_capital_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_civic_capital_score']['element_class'] = 'civic_capital';
  $handler->display->display_options['fields']['field_civic_capital_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_civic_capital_score']['element_wrapper_class'] = 'civic_capital';
  $handler->display->display_options['fields']['field_civic_capital_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_civic_capital_score']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Educat. */
  $handler->display->display_options['fields']['field_education_score']['id'] = 'field_education_score';
  $handler->display->display_options['fields']['field_education_score']['table'] = 'field_data_field_education_score';
  $handler->display->display_options['fields']['field_education_score']['field'] = 'field_education_score';
  $handler->display->display_options['fields']['field_education_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_education_score']['element_class'] = 'education';
  $handler->display->display_options['fields']['field_education_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_education_score']['element_wrapper_class'] = 'education';
  $handler->display->display_options['fields']['field_education_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_education_score']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Amenities */
  $handler->display->display_options['fields']['field_amenities_score']['id'] = 'field_amenities_score';
  $handler->display->display_options['fields']['field_amenities_score']['table'] = 'field_data_field_amenities_score';
  $handler->display->display_options['fields']['field_amenities_score']['field'] = 'field_amenities_score';
  $handler->display->display_options['fields']['field_amenities_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_amenities_score']['element_class'] = 'amenities';
  $handler->display->display_options['fields']['field_amenities_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_amenities_score']['element_wrapper_class'] = 'amenities';
  $handler->display->display_options['fields']['field_amenities_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_amenities_score']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Demo. */
  $handler->display->display_options['fields']['field_demographics_score']['id'] = 'field_demographics_score';
  $handler->display->display_options['fields']['field_demographics_score']['table'] = 'field_data_field_demographics_score';
  $handler->display->display_options['fields']['field_demographics_score']['field'] = 'field_demographics_score';
  $handler->display->display_options['fields']['field_demographics_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_demographics_score']['element_class'] = 'demographics';
  $handler->display->display_options['fields']['field_demographics_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_demographics_score']['element_wrapper_class'] = 'demographics';
  $handler->display->display_options['fields']['field_demographics_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_demographics_score']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Infrast. */
  $handler->display->display_options['fields']['field_infrastructure_score']['id'] = 'field_infrastructure_score';
  $handler->display->display_options['fields']['field_infrastructure_score']['table'] = 'field_data_field_infrastructure_score';
  $handler->display->display_options['fields']['field_infrastructure_score']['field'] = 'field_infrastructure_score';
  $handler->display->display_options['fields']['field_infrastructure_score']['element_type'] = '0';
  $handler->display->display_options['fields']['field_infrastructure_score']['element_class'] = 'infrastructure';
  $handler->display->display_options['fields']['field_infrastructure_score']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_infrastructure_score']['element_wrapper_class'] = 'infrastructure';
  $handler->display->display_options['fields']['field_infrastructure_score']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_infrastructure_score']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_top_100_item_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['path'] = 'best-places/top-100-best-places-to-live/%/ranking-data';

  /* Display: Ranking Criteria */
  $handler = $view->new_display('page', 'Ranking Criteria', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
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
  /* Relationship: Field collection item: Entity with the Ranking Criteria Page (field_top_100_ranking_page) */
  $handler->display->display_options['relationships']['field_top_100_ranking_page_node']['id'] = 'field_top_100_ranking_page_node';
  $handler->display->display_options['relationships']['field_top_100_ranking_page_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_top_100_ranking_page_node']['field'] = 'field_top_100_ranking_page_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2>Ranking Criteria</h2>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Intro Paragraph */
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['id'] = 'field_top_100_advisory_intro';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['table'] = 'field_data_field_top_100_advisory_intro';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['field'] = 'field_top_100_advisory_intro';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['element_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Ranking Criteria */
  $handler->display->display_options['fields']['field_top_100_ranking_criteria_1']['id'] = 'field_top_100_ranking_criteria_1';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria_1']['table'] = 'field_data_field_top_100_ranking_criteria';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria_1']['field'] = 'field_top_100_ranking_criteria';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria_1']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_ranking_criteria_1']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_top_100_ranking_criteria_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_top_100_ranking_criteria_1']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_top_100_ranking_page_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Year (field_year) */
  $handler->display->display_options['arguments']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['arguments']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['relationship'] = 'field_top_100_ranking_page_node';
  $handler->display->display_options['arguments']['field_year_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_options']['code'] = '$query = "SELECT field_year_value FROM field_data_field_year fy WHERE fy.bundle = \'top_100\' ORDER BY fy.field_year_value DESC LIMIT 1";
$year = db_query($query)->fetchField();
return $year;';
  $handler->display->display_options['arguments']['field_year_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_year_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_year_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_year_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_year_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['validate_options']['code'] = '$len = strlen($argument);
if ($len == 4) {
$handler->argument = $argument.\'-01-01 000:00:00\';
}
return TRUE;';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_top_100_ranking_page_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'top_100' => 'top_100',
  );
  $handler->display->display_options['path'] = 'best-places/top-100-best-places-to-live/%/ranking-criteria';

  /* Display: Advisory Board */
  $handler = $view->new_display('page', 'Advisory Board', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the Advisory Board Page (field_top_100_advisory_board_pag) */
  $handler->display->display_options['relationships']['field_top_100_advisory_board_pag_node']['id'] = 'field_top_100_advisory_board_pag_node';
  $handler->display->display_options['relationships']['field_top_100_advisory_board_pag_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_top_100_advisory_board_pag_node']['field'] = 'field_top_100_advisory_board_pag_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2>Advisory Board</h2>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Intro Paragraph */
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['id'] = 'field_top_100_advisory_intro';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['table'] = 'field_data_field_top_100_advisory_intro';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['field'] = 'field_top_100_advisory_intro';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['element_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_intro']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Advisory Board */
  $handler->display->display_options['fields']['field_top_100_advisory_board']['id'] = 'field_top_100_advisory_board';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['table'] = 'field_data_field_top_100_advisory_board';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['field'] = 'field_top_100_advisory_board';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['element_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_board']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_advisory_board']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_top_100_advisory_board']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_top_100_advisory_board']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_top_100_advisory_board_pag_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Year (field_year) */
  $handler->display->display_options['arguments']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['arguments']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['relationship'] = 'field_top_100_advisory_board_pag_node';
  $handler->display->display_options['arguments']['field_year_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_options']['code'] = '$query = "SELECT field_year_value FROM field_data_field_year fy WHERE fy.bundle = \'top_100\' ORDER BY fy.field_year_value DESC LIMIT 1";
$year = db_query($query)->fetchField();
return $year;';
  $handler->display->display_options['arguments']['field_year_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_year_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_year_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_year_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_year_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['validate_options']['code'] = '$len = strlen($argument);
if ($len == 4) {
$handler->argument = $argument.\'-01-01 000:00:00\';
}
return TRUE;';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_top_100_advisory_board_pag_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'top_100' => 'top_100',
  );
  $handler->display->display_options['path'] = 'best-places/top-100-best-places-to-live/%/advisory-board';

  /* Display: Ranking Methodology */
  $handler = $view->new_display('page', 'Ranking Methodology', 'page_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
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
  /* Relationship: Field collection item: Entity with the Ranking Methodology Page (field_ranking_methodology_page) */
  $handler->display->display_options['relationships']['field_ranking_methodology_page_node']['id'] = 'field_ranking_methodology_page_node';
  $handler->display->display_options['relationships']['field_ranking_methodology_page_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_ranking_methodology_page_node']['field'] = 'field_ranking_methodology_page_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2>Ranking Methodology</h2>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_description']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_ranking_methodology_page_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Year (field_year) */
  $handler->display->display_options['arguments']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['arguments']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['arguments']['field_year_value']['relationship'] = 'field_ranking_methodology_page_node';
  $handler->display->display_options['arguments']['field_year_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['default_argument_options']['code'] = '$query = "SELECT field_year_value FROM field_data_field_year fy WHERE fy.bundle = \'top_100\' ORDER BY fy.field_year_value DESC LIMIT 1";
$year = db_query($query)->fetchField();
return $year;';
  $handler->display->display_options['arguments']['field_year_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_year_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_year_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_year_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_year_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_year_value']['validate_options']['code'] = '$len = strlen($argument);
if ($len == 4) {
$handler->argument = $argument.\'-01-01 000:00:00\';
}
return TRUE;';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_ranking_methodology_page_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'top_100' => 'top_100',
  );
  $handler->display->display_options['path'] = 'best-places/top-100-best-places-to-live/%/methodology';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
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
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = 'Livability.com\'s ranking of the Best Places to Live includes cities and towns with populations between 20,000 to 350,000. Ties are broken by unrounded numbers. Please see the full <a href="/best-places/top-100-best-places-to-live/!1/methodology">methodology</a> for data sources and details.';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field collection item: Entity with the List (field_top_100_item) */
  $handler->display->display_options['relationships']['field_top_100_item_node']['id'] = 'field_top_100_item_node';
  $handler->display->display_options['relationships']['field_top_100_item_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_top_100_item_node']['field'] = 'field_top_100_item_node';
  $handler->display->display_options['relationships']['field_top_100_item_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['id'] = 'field_top_100_city_target_id';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['relationships']['field_top_100_city_target_id']['field'] = 'field_top_100_city_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_state_target_id']['id'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_target_id']['field'] = 'field_state_target_id';
  $handler->display->display_options['relationships']['field_state_target_id']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Rank */
  $handler->display->display_options['fields']['field_rank']['id'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['table'] = 'field_data_field_rank';
  $handler->display->display_options['fields']['field_rank']['field'] = 'field_rank';
  $handler->display->display_options['fields']['field_rank']['label'] = '';
  $handler->display->display_options['fields']['field_rank']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rank']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_rank']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rank']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: LivScore */
  $handler->display->display_options['fields']['field_livscore']['id'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['table'] = 'field_data_field_livscore';
  $handler->display->display_options['fields']['field_livscore']['field'] = 'field_livscore';
  $handler->display->display_options['fields']['field_livscore']['label'] = '';
  $handler->display->display_options['fields']['field_livscore']['element_type'] = '0';
  $handler->display->display_options['fields']['field_livscore']['element_class'] = 'city-score';
  $handler->display->display_options['fields']['field_livscore']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_livscore']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[field_top_100_city]<span> [title]</span></h2>';
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
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image_single']['id'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['table'] = 'field_data_field_image_single';
  $handler->display->display_options['fields']['field_image_single']['field'] = 'field_image_single';
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
  /* Field: Content: Population */
  $handler->display->display_options['fields']['field_population']['id'] = 'field_population';
  $handler->display->display_options['fields']['field_population']['table'] = 'field_data_field_population';
  $handler->display->display_options['fields']['field_population']['field'] = 'field_population';
  $handler->display->display_options['fields']['field_population']['relationship'] = 'field_top_100_city_target_id';
  $handler->display->display_options['fields']['field_population']['label'] = '';
  $handler->display->display_options['fields']['field_population']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_population']['alter']['text'] = '<span class="city-pop">
Population: [field_population]
</span>';
  $handler->display->display_options['fields']['field_population']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_population']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_population']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_population']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_population']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Body */
  $handler->display->display_options['fields']['field_bp_body']['id'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['table'] = 'field_data_field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['field'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['label'] = '';
  $handler->display->display_options['fields']['field_bp_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bp_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_state_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_top_100_city_1']['id'] = 'field_top_100_city_1';
  $handler->display->display_options['fields']['field_top_100_city_1']['table'] = 'field_data_field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city_1']['field'] = 'field_top_100_city';
  $handler->display->display_options['fields']['field_top_100_city_1']['label'] = '';
  $handler->display->display_options['fields']['field_top_100_city_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_top_100_city_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_100_city_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_top_100_item_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="city-info">[field_bp_body]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $export['top_100'] = $view;

  $view = new view();
  $view->name = 'top_100_landing_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Top 100 landing page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Best Places To Live';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Year (field_year) */
  $handler->display->display_options['sorts']['field_year_value']['id'] = 'field_year_value';
  $handler->display->display_options['sorts']['field_year_value']['table'] = 'field_data_field_year';
  $handler->display->display_options['sorts']['field_year_value']['field'] = 'field_year_value';
  $handler->display->display_options['sorts']['field_year_value']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
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
    'top_100' => 'top_100',
    'top_cities_list' => 'top_cities_list',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'best-places';
  $export['top_100_landing_page'] = $view;

  return $export;
}
