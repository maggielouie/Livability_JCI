<?php
/**
 * Expose Web Area Contact Form as a Context condition.
 */
class context_condition_promoted_city extends context_condition {
  function condition_values() {
    return array(
      'TRUE' => t('City is Promoted'),
      'FALSE' => t('City is not Promoted'),
    );
  }

  function condition_form($context) {
    $form = parent::condition_form($context);

    $form['#type'] = 'radios';
    if(empty($form['#default_value'])){
      $form['#default_value'] = 'TRUE';
    }
    else{
      $form['#default_value'] = current($form['#default_value']);
    }
    return $form;
  }

  /**
   * Condition form submit handler.
   *
   * Storing values in an array since that's what Context prefers
   */
  function condition_form_submit($values) {
    return array_filter(array($values => $values));
  }

  function execute($node) {
    $ispromotedcity = FALSE;
    if(!empty($node) && isset($node->field_promoted_city) && arg(2) === null && arg(3) === null) {
      foreach ($this->get_contexts() as $context) {
        $values = $this->fetch_from_context($context, 'values');
        if ($node->field_promoted_city['und'][0]['value'] == 1) {
          $ispromotedcity = TRUE;
        }       
        if ((!empty($values['TRUE']) && $ispromotedcity) || (!empty($values['FALSE']) && !$ispromotedcity)) {
          $this->condition_met($context);
        }
      }
    }
  }
}
