<?php

// Form override fo theme settings
function livability_form_system_theme_settings_alter(&$form, $form_state) {

  $form['options_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theme Specific Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  $form['options_settings']['project_code'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Project Code'),
    '#description'   => t('Numbers Only!!'),
    '#default_value' => theme_get_setting('project_code'),
    '#size'          => 3,
    '#maxlength'     => 5,
  );
  $form['options_settings']['national_income'] = array(
      '#type'          => 'textfield',
      '#title'         => t('National Income'),
      '#description'   => t('Numbers Only!!'),
      '#default_value' => theme_get_setting('national_income'),
      '#size'          => 10,
      '#maxlength'     => 15,
  );
  $form['options_settings']['national_home_price'] = array(
    '#type'          => 'textfield',
    '#title'         => t('National Home Price '),
    '#description'   => t('Numbers Only!!'),
    '#default_value' => theme_get_setting('national_home_price'),
    '#size'          => 10,
    '#maxlength'     => 15,
  );
}
