<?php
/**
 * Expose Web Area Contact Form as a Context condition.
 */
class context_condition_primary_city extends context_condition {
  function condition_values() {
    return array(
      'TRUE' => t('Node has a Primary City'),
      'FALSE' => t('Node does not have a Primary City'),
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
    $hasprimarycity = FALSE;
    if(!empty($node)) {
      foreach ($this->get_contexts() as $context) {
        $values= $this->fetch_from_context($context, 'values');
        if (isset($node->field_place['und'])) {
          foreach ($node->field_place['und'] as $place) {
            $city = entity_load_single('field_collection_item',$place['value']);
            if($city->field_primary_host['und'][0]['value'] == 1) {
              $hasprimarycity = TRUE;
            }
          }
        }
        if ((!empty($values['TRUE']) && $hasprimarycity) || (!empty($values['FALSE']) && !$hasprimarycity)) {
          $this->condition_met($context);
        }
      }
    }
  }
}
