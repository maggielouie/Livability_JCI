<?php
/**
 * @file
 * state_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function state_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'state';
  $context->description = '';
  $context->tag = 'Livability-2.0';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'state' => 'state',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'theme' => array(
      'values' => array(
        'livability' => 'livability',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-17' => array(
          'module' => 'block',
          'delta' => '17',
          'region' => 'share',
          'weight' => '-10',
        ),
        'block-20' => array(
          'module' => 'block',
          'delta' => '20',
          'region' => 'liv_ad_lb_top',
          'weight' => '-10',
        ),
        'views-state-block' => array(
          'module' => 'views',
          'delta' => 'state-block',
          'region' => 'liv_state_featured_img',
          'weight' => '-10',
        ),
        'views-state-block_1' => array(
          'module' => 'views',
          'delta' => 'state-block_1',
          'region' => 'liv_state_featured',
          'weight' => '-10',
        ),
        'views-state-block_28' => array(
          'module' => 'views',
          'delta' => 'state-block_28',
          'region' => 'liv_state_lists_100',
          'weight' => '-10',
        ),
        'views-state-block_37' => array(
          'module' => 'views',
          'delta' => 'state-block_37',
          'region' => 'liv_state_lists_10',
          'weight' => '-10',
        ),
        'views-state-block_36' => array(
          'module' => 'views',
          'delta' => 'state-block_36',
          'region' => 'liv_state_articles',
          'weight' => '-10',
        ),
        'views-state-block_39' => array(
          'module' => 'views',
          'delta' => 'state-block_39',
          'region' => 'liv_state_articles',
          'weight' => '-9',
        ),
        'views-state-block_4' => array(
          'module' => 'views',
          'delta' => 'state-block_4',
          'region' => 'liv_state_1',
          'weight' => '-10',
        ),
        'views-state-block_15' => array(
          'module' => 'views',
          'delta' => 'state-block_15',
          'region' => 'liv_state_1',
          'weight' => '-9',
        ),
        'views-state-block_5' => array(
          'module' => 'views',
          'delta' => 'state-block_5',
          'region' => 'liv_state_1',
          'weight' => '-8',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'liv_state_1',
          'weight' => '-7',
        ),
        'views-state-block_6' => array(
          'module' => 'views',
          'delta' => 'state-block_6',
          'region' => 'liv_state_1',
          'weight' => '-6',
        ),
        'views-state-block_20' => array(
          'module' => 'views',
          'delta' => 'state-block_20',
          'region' => 'liv_state_2',
          'weight' => '-10',
        ),
        'views-state-block_7' => array(
          'module' => 'views',
          'delta' => 'state-block_7',
          'region' => 'liv_state_2',
          'weight' => '-9',
        ),
        'views-state-block_17' => array(
          'module' => 'views',
          'delta' => 'state-block_17',
          'region' => 'liv_state_2',
          'weight' => '-8',
        ),
        'views-state-block_16' => array(
          'module' => 'views',
          'delta' => 'state-block_16',
          'region' => 'liv_state_2',
          'weight' => '-7',
        ),
        'views-state-block_8' => array(
          'module' => 'views',
          'delta' => 'state-block_8',
          'region' => 'liv_state_2',
          'weight' => '-6',
        ),
        'views-state-block_27' => array(
          'module' => 'views',
          'delta' => 'state-block_27',
          'region' => 'liv_state_2',
          'weight' => '-5',
        ),
        'views-state-block_9' => array(
          'module' => 'views',
          'delta' => 'state-block_9',
          'region' => 'liv_state_3',
          'weight' => '-10',
        ),
        'views-state-block_40' => array(
          'module' => 'views',
          'delta' => 'state-block_40',
          'region' => 'liv_state_3',
          'weight' => '-9',
        ),
        'views-state-block_21' => array(
          'module' => 'views',
          'delta' => 'state-block_21',
          'region' => 'liv_state_3',
          'weight' => '-8',
        ),
        'views-state-block_29' => array(
          'module' => 'views',
          'delta' => 'state-block_29',
          'region' => 'liv_state_3',
          'weight' => '-7',
        ),
        'views-state-block_10' => array(
          'module' => 'views',
          'delta' => 'state-block_10',
          'region' => 'liv_state_3',
          'weight' => '-6',
        ),
        'views-state-block_30' => array(
          'module' => 'views',
          'delta' => 'state-block_30',
          'region' => 'liv_state_3',
          'weight' => '-5',
        ),
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'liv_state_4',
          'weight' => '-10',
        ),
        'views-state-block_13' => array(
          'module' => 'views',
          'delta' => 'state-block_13',
          'region' => 'liv_state_4',
          'weight' => '-9',
        ),
        'views-state-block_18' => array(
          'module' => 'views',
          'delta' => 'state-block_18',
          'region' => 'liv_state_4',
          'weight' => '-8',
        ),
        'views-state-block_38' => array(
          'module' => 'views',
          'delta' => 'state-block_38',
          'region' => 'liv_state_4',
          'weight' => '-7',
        ),
        'views-state-block_14' => array(
          'module' => 'views',
          'delta' => 'state-block_14',
          'region' => 'liv_state_4',
          'weight' => '-6',
        ),
        'views-state-block_19' => array(
          'module' => 'views',
          'delta' => 'state-block_19',
          'region' => 'liv_state_4',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Livability-2.0');
  $export['state'] = $context;

  return $export;
}
