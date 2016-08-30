<?php
/**
 * @file
 * livability_citys.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function livability_citys_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_commute|node|city|form';
  $field_group->group_name = 'group_commute';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commute',
    'weight' => '14',
    'children' => array(
      0 => 'field_avg_commute',
      1 => 'field_carpooled',
      2 => 'field_commute_other',
      3 => 'field_drove_alone',
      4 => 'field_public',
      5 => 'field_walked',
      6 => 'field_worked_home',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-commute field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_commute|node|city|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_demographics|node|city|form';
  $field_group->group_name = 'group_demographics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Demographics',
    'weight' => '13',
    'children' => array(
      0 => 'field_different_state',
      1 => 'field_foreign_born',
      2 => 'field_population',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-demographics field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_demographics|node|city|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_economic|node|city|form';
  $field_group->group_name = 'group_economic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Economic',
    'weight' => '15',
    'children' => array(
      0 => 'field_median_home_price',
      1 => 'field_median_household_income',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_economic|node|city|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_education|node|city|form';
  $field_group->group_name = 'group_education';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Education',
    'weight' => '19',
    'children' => array(
      0 => 'field_education_college',
      1 => 'field_education_high_school',
      2 => 'field_education_post_grad',
      3 => 'field_education_attainment_total',
      4 => 'field_education_degree_associate',
      5 => 'field_education_degree_bachelors',
      6 => 'field_education_enrollment_colle',
      7 => 'field_education_enrollment_eleme',
      8 => 'field_education_enrollment_high',
      9 => 'field_education_enrollment_kinde',
      10 => 'field_education_enrollment_prek',
      11 => 'field_education_less_than_9th',
      12 => 'field_education_some_high_school',
      13 => 'field_education_percent_bachelor',
      14 => 'field_education_percent_high_sch',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-education field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_education|node|city|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_employment|node|city|form';
  $field_group->group_name = 'group_employment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Employment',
    'weight' => '17',
    'children' => array(
      0 => 'field_employed',
      1 => 'field_employed_armed_forces',
      2 => 'field_unemployed',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_employment|node|city|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ethnicity|node|city|form';
  $field_group->group_name = 'group_ethnicity';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ethnicity',
    'weight' => '18',
    'children' => array(
      0 => 'field_ethnicity_asian',
      1 => 'field_ethnicity_black',
      2 => 'field_ethnicity_hawaiian',
      3 => 'field_ethnicity_indian',
      4 => 'field_ethnicity_other',
      5 => 'field_ethnicity_white',
      6 => 'field_ethnicity_hispanic',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ethnicity|node|city|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_language|node|city|form';
  $field_group->group_name = 'group_language';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'city';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Language',
    'weight' => '16',
    'children' => array(
      0 => 'field_english_only',
      1 => 'field_language_other',
      2 => 'field_poor_english',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_language|node|city|form'] = $field_group;

  return $export;
}
