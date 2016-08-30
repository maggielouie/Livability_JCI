<?php
/**
 * @file
 * city2.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function city2_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'city';
  $context->description = '';
  $context->tag = 'Livability-2.0';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'city' => 'city',
      ),
      'options' => array(
        'node_form' => '1',
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
        'menu-menu-liv-main' => array(
          'module' => 'menu',
          'delta' => 'menu-liv-main',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'search',
          'weight' => '-10',
        ),
        'combo_ad_blocks-pushdown' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'pushdown',
          'region' => 'liv_ad_lb_top',
          'weight' => '-8',
        ),
        'combo_ad_blocks-leaderboard_middle' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_middle',
          'region' => 'liv_ad_lb_mid',
          'weight' => '-9',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'liv_ad_lb_bottom',
          'weight' => '-9',
        ),
        'views-city-block' => array(
          'module' => 'views',
          'delta' => 'city-block',
          'region' => 'liv_city_featured_img',
          'weight' => '-10',
        ),
        'views-city-block_1' => array(
          'module' => 'views',
          'delta' => 'city-block_1',
          'region' => 'liv_city_featured',
          'weight' => '-10',
        ),
        'views-city-block_3' => array(
          'module' => 'views',
          'delta' => 'city-block_3',
          'region' => 'liv_city_badge',
          'weight' => '-9',
        ),
        'views-city-block_2' => array(
          'module' => 'views',
          'delta' => 'city-block_2',
          'region' => 'liv_city_badge',
          'weight' => '-8',
        ),
        'views-city-block_28' => array(
          'module' => 'views',
          'delta' => 'city-block_28',
          'region' => 'liv_city_lists',
          'weight' => '-10',
        ),
        'views-city-block_37' => array(
          'module' => 'views',
          'delta' => 'city-block_37',
          'region' => 'liv_city_lists',
          'weight' => '-9',
        ),
        'views-city-block_36' => array(
          'module' => 'views',
          'delta' => 'city-block_36',
          'region' => 'liv_city_articles',
          'weight' => '-10',
        ),
        'views-city-block_4' => array(
          'module' => 'views',
          'delta' => 'city-block_4',
          'region' => 'liv_city_1',
          'weight' => '-10',
        ),
        'views-city-block_15' => array(
          'module' => 'views',
          'delta' => 'city-block_15',
          'region' => 'liv_city_1',
          'weight' => '-9',
        ),
        'views-city-block_5' => array(
          'module' => 'views',
          'delta' => 'city-block_5',
          'region' => 'liv_city_1',
          'weight' => '-8',
        ),
        'views-nearby_cities-block' => array(
          'module' => 'views',
          'delta' => 'nearby_cities-block',
          'region' => 'liv_city_1',
          'weight' => '-7',
        ),
        'views-city-block_27' => array(
          'module' => 'views',
          'delta' => 'city-block_27',
          'region' => 'liv_city_1',
          'weight' => '-6',
        ),
        'views-city-block_20' => array(
          'module' => 'views',
          'delta' => 'city-block_20',
          'region' => 'liv_city_2',
          'weight' => '-10',
        ),
        'views-city-block_6' => array(
          'module' => 'views',
          'delta' => 'city-block_6',
          'region' => 'liv_city_2',
          'weight' => '-9',
        ),
        'views-city-block_16' => array(
          'module' => 'views',
          'delta' => 'city-block_16',
          'region' => 'liv_city_2',
          'weight' => '-8',
        ),
        'views-city-block_17' => array(
          'module' => 'views',
          'delta' => 'city-block_17',
          'region' => 'liv_city_2',
          'weight' => '-7',
        ),
        'views-city-block_29' => array(
          'module' => 'views',
          'delta' => 'city-block_29',
          'region' => 'liv_city_2',
          'weight' => '-6',
        ),
        'views-city-block_22' => array(
          'module' => 'views',
          'delta' => 'city-block_22',
          'region' => 'liv_city_2',
          'weight' => '-5',
        ),
        'views-city-block_7' => array(
          'module' => 'views',
          'delta' => 'city-block_7',
          'region' => 'liv_city_3',
          'weight' => '-10',
        ),
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'liv_city_3',
          'weight' => '-9',
        ),
        'views-city-block_21' => array(
          'module' => 'views',
          'delta' => 'city-block_21',
          'region' => 'liv_city_3',
          'weight' => '-8',
        ),
        'views-city-block_30' => array(
          'module' => 'views',
          'delta' => 'city-block_30',
          'region' => 'liv_city_3',
          'weight' => '-7',
        ),
        'views-city-block_8' => array(
          'module' => 'views',
          'delta' => 'city-block_8',
          'region' => 'liv_city_3',
          'weight' => '-6',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'liv_city_4',
          'weight' => '-10',
        ),
        'views-city-block_26' => array(
          'module' => 'views',
          'delta' => 'city-block_26',
          'region' => 'liv_city_4',
          'weight' => '-9',
        ),
        'views-city-block_31' => array(
          'module' => 'views',
          'delta' => 'city-block_31',
          'region' => 'liv_city_4',
          'weight' => '-8',
        ),
        'views-city-block_13' => array(
          'module' => 'views',
          'delta' => 'city-block_13',
          'region' => 'liv_city_4',
          'weight' => '-7',
        ),
        'views-city-block_23' => array(
          'module' => 'views',
          'delta' => 'city-block_23',
          'region' => 'liv_city_4',
          'weight' => '-6',
        ),
        'views-city-block_18' => array(
          'module' => 'views',
          'delta' => 'city-block_18',
          'region' => 'liv_city_4',
          'weight' => '-5',
        ),
        'views-city-block_14' => array(
          'module' => 'views',
          'delta' => 'city-block_14',
          'region' => 'liv_city_4',
          'weight' => '-4',
        ),
        'views-city-block_32' => array(
          'module' => 'views',
          'delta' => 'city-block_32',
          'region' => 'liv_city_5',
          'weight' => '-10',
        ),
        'views-city-block_24' => array(
          'module' => 'views',
          'delta' => 'city-block_24',
          'region' => 'liv_city_5',
          'weight' => '-9',
        ),
        'views-city-block_9' => array(
          'module' => 'views',
          'delta' => 'city-block_9',
          'region' => 'liv_city_5',
          'weight' => '-8',
        ),
        'views-city-block_19' => array(
          'module' => 'views',
          'delta' => 'city-block_19',
          'region' => 'liv_city_6',
          'weight' => '-87',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'liv_city_6',
          'weight' => '-86',
        ),
        'views-city-block_10' => array(
          'module' => 'views',
          'delta' => 'city-block_10',
          'region' => 'liv_city_6',
          'weight' => '-85',
        ),
        'views-city-block_33' => array(
          'module' => 'views',
          'delta' => 'city-block_33',
          'region' => 'liv_city_6',
          'weight' => '-84',
        ),
        'views-city-block_11' => array(
          'module' => 'views',
          'delta' => 'city-block_11',
          'region' => 'liv_city_7',
          'weight' => '-10',
        ),
        'views-city-block_34' => array(
          'module' => 'views',
          'delta' => 'city-block_34',
          'region' => 'liv_city_7',
          'weight' => '-9',
        ),
        'views-city-block_25' => array(
          'module' => 'views',
          'delta' => 'city-block_25',
          'region' => 'liv_city_7',
          'weight' => '-8',
        ),
        'views-city-block_38' => array(
          'module' => 'views',
          'delta' => 'city-block_38',
          'region' => 'liv_city_8',
          'weight' => '-10',
        ),
        'views-city-block_35' => array(
          'module' => 'views',
          'delta' => 'city-block_35',
          'region' => 'liv_city_8',
          'weight' => '-9',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'liv_city_8',
          'weight' => '-8',
        ),
        'views-city-block_12' => array(
          'module' => 'views',
          'delta' => 'city-block_12',
          'region' => 'liv_city_8',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Livability-2.0');
  $export['city'] = $context;

  return $export;
}
