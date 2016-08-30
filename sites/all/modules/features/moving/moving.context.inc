<?php
/**
 * @file
 * moving.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function moving_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'moving_pages';
  $context->description = '';
  $context->tag = 'moving';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'moving' => 'moving',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-moving-block_1' => array(
          'module' => 'views',
          'delta' => 'moving-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'combo_ad_blocks-leaderboard_top' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_top',
          'region' => 'content',
          'weight' => '-9',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '15',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-how_to_articles-block' => array(
          'module' => 'views',
          'delta' => 'how_to_articles-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'best_places_block-best_places_block' => array(
          'module' => 'best_places_block',
          'delta' => 'best_places_block',
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
  t('moving');
  $export['moving_pages'] = $context;

  return $export;
}
