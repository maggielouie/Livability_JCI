<?php
/**
 * @file
 * article_slideshow.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function article_slideshow_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_slideshow';
  $context->description = '';
  $context->tag = 'Article-Slideshow';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article_slideshow' => 'article_slideshow',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'combo_ad_blocks-leaderboard_top' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_top',
          'region' => 'content_top_ad',
          'weight' => '-10',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '-8',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'popular_cities_block-popular_cities' => array(
          'module' => 'popular_cities_block',
          'delta' => 'popular_cities',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-7',
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
          'sidebar_first' => 'sidebar_first',
          'page_top' => 0,
          'header' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content_top_ad' => 0,
          'content' => 0,
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
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Article-Slideshow');
  $export['article_slideshow'] = $context;

  return $export;
}
