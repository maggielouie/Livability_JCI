<?php
/**
 * @file
 * top_cities.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function top_cities_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'top_cities';
  $context->description = 'Top Cities node';
  $context->tag = 'top_cities';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'top_cities_list' => 'top_cities_list',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'top_cities_list:advisory_board' => 'top_cities_list:advisory_board',
        'top_cities_list:methodology' => 'top_cities_list:methodology',
        'top_cities_list:ranking_criteria' => 'top_cities_list:ranking_criteria',
        'top_cities_list:ranking_data' => 'top_cities_list:ranking_data',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-63',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '-61',
        ),
        'combo_ad_blocks-filmstrip' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'filmstrip',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'popular_cities_block-popular_cities' => array(
          'module' => 'popular_cities_block',
          'delta' => 'popular_cities',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-from_the_blog-block' => array(
          'module' => 'views',
          'delta' => 'from_the_blog-block',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'top100_partners_block-top100_partners' => array(
          'module' => 'top100_partners_block',
          'delta' => 'top100_partners',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
    'clear_region' => array(
      'bartik' => array(
        'clear' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'liv' => array(
        'clear' => array(
          'content' => 'content',
          'sidebar_first' => 'sidebar_first',
          'page_top' => 0,
          'header' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content_top_ad' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'clear' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Top Cities node');
  t('top_cities');
  $export['top_cities'] = $context;

  return $export;
}
