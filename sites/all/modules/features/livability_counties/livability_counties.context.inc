<?php
/**
 * @file
 * livability_counties.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function livability_counties_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'county_context';
  $context->description = '';
  $context->tag = 'county';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'county' => 'county',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'combo_ad_blocks-leaderboard_top' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_top',
          'region' => 'content',
          'weight' => '-9',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-8',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '-7',
        ),
        'combo_ad_blocks-filmstrip' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'filmstrip',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'popular_articles_block-popular_articles' => array(
          'module' => 'popular_articles_block',
          'delta' => 'popular_articles',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'views-from_the_blog-block' => array(
          'module' => 'views',
          'delta' => 'from_the_blog-block',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
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
  t('county');
  $export['county_context'] = $context;

  return $export;
}
