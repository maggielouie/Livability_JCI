<?php
/**
 * @file
 * liv_schools.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function liv_schools_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nearby_school_districts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nearby School Districts';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
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
  /* Contextual filter: Content: County (field_county) */
  $handler->display->display_options['arguments']['field_county_target_id']['id'] = 'field_county_target_id';
  $handler->display->display_options['arguments']['field_county_target_id']['table'] = 'field_data_field_county';
  $handler->display->display_options['arguments']['field_county_target_id']['field'] = 'field_county_target_id';
  $handler->display->display_options['arguments']['field_county_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_county_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_county_target_id']['default_argument_options']['code'] = 'global $c;
return($c->county->nid);';
  $handler->display->display_options['arguments']['field_county_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_county_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_county_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school_districts' => 'school_districts',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['nearby_school_districts'] = $view;

  $view = new view();
  $view->name = 'nearby_schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Nearby Schools';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '400';
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
  /* Field: Content: GreatSchools Rating */
  $handler->display->display_options['fields']['field_greatschools_rating']['id'] = 'field_greatschools_rating';
  $handler->display->display_options['fields']['field_greatschools_rating']['table'] = 'field_data_field_greatschools_rating';
  $handler->display->display_options['fields']['field_greatschools_rating']['field'] = 'field_greatschools_rating';
  $handler->display->display_options['fields']['field_greatschools_rating']['label'] = '';
  $handler->display->display_options['fields']['field_greatschools_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_greatschools_rating']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_greatschools_rating']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: School Level */
  $handler->display->display_options['fields']['field_school_level']['id'] = 'field_school_level';
  $handler->display->display_options['fields']['field_school_level']['table'] = 'field_data_field_school_level';
  $handler->display->display_options['fields']['field_school_level']['field'] = 'field_school_level';
  $handler->display->display_options['fields']['field_school_level']['label'] = '';
  $handler->display->display_options['fields']['field_school_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_level']['element_default_classes'] = FALSE;
  /* Field: Content: School Level Code */
  $handler->display->display_options['fields']['field_school_level_code']['id'] = 'field_school_level_code';
  $handler->display->display_options['fields']['field_school_level_code']['table'] = 'field_data_field_school_level_code';
  $handler->display->display_options['fields']['field_school_level_code']['field'] = 'field_school_level_code';
  $handler->display->display_options['fields']['field_school_level_code']['label'] = '';
  $handler->display->display_options['fields']['field_school_level_code']['element_type'] = '0';
  $handler->display->display_options['fields']['field_school_level_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_level_code']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_school_level_code']['element_default_classes'] = FALSE;
  /* Field: Content: School District */
  $handler->display->display_options['fields']['field_school_district']['id'] = 'field_school_district';
  $handler->display->display_options['fields']['field_school_district']['table'] = 'field_data_field_school_district';
  $handler->display->display_options['fields']['field_school_district']['field'] = 'field_school_district';
  $handler->display->display_options['fields']['field_school_district']['label'] = '';
  $handler->display->display_options['fields']['field_school_district']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_district']['element_type'] = '0';
  $handler->display->display_options['fields']['field_school_district']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_district']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_school_district']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_school_district']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_school_district']['field_api_classes'] = TRUE;
  /* Field: Content: School Type */
  $handler->display->display_options['fields']['field_school_type']['id'] = 'field_school_type';
  $handler->display->display_options['fields']['field_school_type']['table'] = 'field_data_field_school_type';
  $handler->display->display_options['fields']['field_school_type']['field'] = 'field_school_type';
  $handler->display->display_options['fields']['field_school_type']['label'] = '';
  $handler->display->display_options['fields']['field_school_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_school_type']['type'] = 'text_plain';
  /* Field: Content: School Subtype */
  $handler->display->display_options['fields']['field_school_subtype']['id'] = 'field_school_subtype';
  $handler->display->display_options['fields']['field_school_subtype']['table'] = 'field_data_field_school_subtype';
  $handler->display->display_options['fields']['field_school_subtype']['field'] = 'field_school_subtype';
  $handler->display->display_options['fields']['field_school_subtype']['label'] = '';
  $handler->display->display_options['fields']['field_school_subtype']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school_subtype']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_subtype']['element_default_classes'] = FALSE;
  /* Field: Content: School Enrollment */
  $handler->display->display_options['fields']['field_school_enrollment']['id'] = 'field_school_enrollment';
  $handler->display->display_options['fields']['field_school_enrollment']['table'] = 'field_data_field_school_enrollment';
  $handler->display->display_options['fields']['field_school_enrollment']['field'] = 'field_school_enrollment';
  $handler->display->display_options['fields']['field_school_enrollment']['label'] = '';
  $handler->display->display_options['fields']['field_school_enrollment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_enrollment']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_school_enrollment']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Content: School Address */
  $handler->display->display_options['fields']['field_school_address']['id'] = 'field_school_address';
  $handler->display->display_options['fields']['field_school_address']['table'] = 'field_data_field_school_address';
  $handler->display->display_options['fields']['field_school_address']['field'] = 'field_school_address';
  $handler->display->display_options['fields']['field_school_address']['label'] = '';
  $handler->display->display_options['fields']['field_school_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_address']['element_default_classes'] = FALSE;
  /* Field: Content: School citystatezip */
  $handler->display->display_options['fields']['field_school_citystatezip']['id'] = 'field_school_citystatezip';
  $handler->display->display_options['fields']['field_school_citystatezip']['table'] = 'field_data_field_school_citystatezip';
  $handler->display->display_options['fields']['field_school_citystatezip']['field'] = 'field_school_citystatezip';
  $handler->display->display_options['fields']['field_school_citystatezip']['label'] = '';
  $handler->display->display_options['fields']['field_school_citystatezip']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_citystatezip']['element_default_classes'] = FALSE;
  /* Field: Content: School Phone */
  $handler->display->display_options['fields']['field_school_phone']['id'] = 'field_school_phone';
  $handler->display->display_options['fields']['field_school_phone']['table'] = 'field_data_field_school_phone';
  $handler->display->display_options['fields']['field_school_phone']['field'] = 'field_school_phone';
  $handler->display->display_options['fields']['field_school_phone']['label'] = '';
  $handler->display->display_options['fields']['field_school_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_phone']['element_default_classes'] = FALSE;
  /* Field: Content: School Teacher Bachelors */
  $handler->display->display_options['fields']['field_school_teacher_bachelors']['id'] = 'field_school_teacher_bachelors';
  $handler->display->display_options['fields']['field_school_teacher_bachelors']['table'] = 'field_data_field_school_teacher_bachelors';
  $handler->display->display_options['fields']['field_school_teacher_bachelors']['field'] = 'field_school_teacher_bachelors';
  $handler->display->display_options['fields']['field_school_teacher_bachelors']['label'] = '';
  $handler->display->display_options['fields']['field_school_teacher_bachelors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_teacher_bachelors']['element_default_classes'] = FALSE;
  /* Field: Content: School Teacher Licensed */
  $handler->display->display_options['fields']['field_school_teacher_licensed']['id'] = 'field_school_teacher_licensed';
  $handler->display->display_options['fields']['field_school_teacher_licensed']['table'] = 'field_data_field_school_teacher_licensed';
  $handler->display->display_options['fields']['field_school_teacher_licensed']['field'] = 'field_school_teacher_licensed';
  $handler->display->display_options['fields']['field_school_teacher_licensed']['label'] = '';
  $handler->display->display_options['fields']['field_school_teacher_licensed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school_teacher_licensed']['element_default_classes'] = FALSE;
  /* Field: Content: Greatschools ID */
  $handler->display->display_options['fields']['field_greatschools_id']['id'] = 'field_greatschools_id';
  $handler->display->display_options['fields']['field_greatschools_id']['table'] = 'field_data_field_greatschools_id';
  $handler->display->display_options['fields']['field_greatschools_id']['field'] = 'field_greatschools_id';
  $handler->display->display_options['fields']['field_greatschools_id']['label'] = '';
  $handler->display->display_options['fields']['field_greatschools_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_greatschools_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_greatschools_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Contextual filter: Content: County (field_county) */
  $handler->display->display_options['arguments']['field_county_target_id']['id'] = 'field_county_target_id';
  $handler->display->display_options['arguments']['field_county_target_id']['table'] = 'field_data_field_county';
  $handler->display->display_options['arguments']['field_county_target_id']['field'] = 'field_county_target_id';
  $handler->display->display_options['arguments']['field_county_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_county_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_county_target_id']['default_argument_options']['code'] = 'global $currentCity;
return($currentCity->county->nid);';
  $handler->display->display_options['arguments']['field_county_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_county_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_county_target_id']['summary_options']['items_per_page'] = '25';
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
    'schools' => 'schools',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['nearby_schools'] = $view;

  return $export;
}
