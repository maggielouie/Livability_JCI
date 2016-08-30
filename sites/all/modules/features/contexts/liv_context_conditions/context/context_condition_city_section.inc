<?php
/**
 * Expose Web Area Contact Form as a Context condition.
 */
class context_condition_city_section extends context_condition {
  function condition_values() {
    return array(
      'things-to-do' => t('Things to Do'),
      'photos' => t('Photos'),
      'schools' => t('Schools'),
      'real-estate' => t('Real Estate'),
      'business' => t('Business'),
      'health' => t('Health'),
      'transportation' => t('Transportation'),
      'government' => t('Government'),
      'demographics' => t('Demographics'),
      'digital-magazine' => t('Digital Magazine'),
      'all' => t('All sections'),
    );
  }

  function condition_form($context) {
    $form = parent::condition_form($context);
    $defaults = $this->fetch_from_context($context, 'values');
    if(empty($form['#default_value'])){
      $form['#default_value'] = array('all');
    }
    else{
      $form['#default_value'] = $defaults;
    }
    return $form;
  }

  function execute($node) {
    $c = getCityContext();

    foreach ($this->get_contexts() as $context) {
      $values = $this->fetch_from_context($context, 'values');

      if($c !== false && null != arg(2)){
        if (isset($values['all'])) { $this->condition_met($context); }
        if (in_array(arg(2), $values)) {
          $this->condition_met($context);
        }
      }
    }
  }
}
