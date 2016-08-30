<?php
/**
 * @file
 * contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_city_block';
  $context->description = 'Popular cities block.';
  $context->tag = 'article';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'article_quiz' => 'article_quiz',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '~moving*' => '~moving*',
      ),
    ),
    'primary_city_set' => array(
      'values' => array(
        'FALSE' => 'FALSE',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'popular_cities_block-popular_cities' => array(
          'module' => 'popular_cities_block',
          'delta' => 'popular_cities',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Popular cities block.');
  t('article');
  $export['article_city_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_related_block';
  $context->description = 'Related articles block.';
  $context->tag = 'article';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'article_quiz' => 'article_quiz',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        '~moving*' => '~moving*',
      ),
    ),
    'primary_city_set' => array(
      'values' => array(
        'FALSE' => 'FALSE',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-related_articles-block' => array(
          'module' => 'views',
          'delta' => 'related_articles-block',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Related articles block.');
  t('article');
  $export['article_related_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'best_places';
  $context->description = '';
  $context->tag = 'best places';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'best-places' => 'best-places',
        'top-10' => 'top-10',
      ),
    ),
    'views' => array(
      'values' => array(
        'best_places_landing_page' => 'best_places_landing_page',
        'best_places_landing_page:page_1' => 'best_places_landing_page:page_1',
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
          'weight' => '-53',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '53',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('best places');
  $export['best_places'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'best_places_email_signup';
  $context->description = '';
  $context->tag = 'best places';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'jci_modal_signup-jci_modal_signup' => array(
          'module' => 'jci_modal_signup',
          'delta' => 'jci_modal_signup',
          'region' => 'footer',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('best places');
  $export['best_places_email_signup'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'best_places_list';
  $context->description = '';
  $context->tag = 'best places';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'best_places:page' => 'best_places:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'combo_ad_blocks-pushdown' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'pushdown',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '-8',
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
  t('best places');
  $export['best_places_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'best_places_node';
  $context->description = 'the intro page';
  $context->tag = 'best places';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'best_places' => 'best_places',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'combo_ad_blocks-pushdown' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'pushdown',
          'region' => 'content',
          'weight' => '-63',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-62',
        ),
        'liv_taboola_blocks-taboola_endslate' => array(
          'module' => 'liv_taboola_blocks',
          'delta' => 'taboola_endslate',
          'region' => 'content',
          'weight' => '-61',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '-60',
        ),
        'combo_ad_blocks-filmstrip' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'filmstrip',
          'region' => 'sidebar_first',
          'weight' => '-63',
        ),
        'popular_cities_block-popular_cities' => array(
          'module' => 'popular_cities_block',
          'delta' => 'popular_cities',
          'region' => 'sidebar_first',
          'weight' => '-62',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-61',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-60',
        ),
        'views-from_the_blog-block' => array(
          'module' => 'views',
          'delta' => 'from_the_blog-block',
          'region' => 'sidebar_first',
          'weight' => '-59',
        ),
        'best_places_block-best_places_block' => array(
          'module' => 'best_places_block',
          'delta' => 'best_places_block',
          'region' => 'sidebar_first',
          'weight' => '-58',
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
  t('best places');
  t('the intro page');
  $export['best_places_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'best_places_sidebar';
  $context->description = '';
  $context->tag = 'best places';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'best-places' => 'best-places',
        'top-10' => 'top-10',
      ),
    ),
    'views' => array(
      'values' => array(
        'best_places_landing_page' => 'best_places_landing_page',
        'best_places_landing_page:page_1' => 'best_places_landing_page:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
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
  t('best places');
  $export['best_places_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'best_places_top_10';
  $context->description = '';
  $context->tag = 'best places';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'top-10' => 'top-10',
      ),
    ),
    'views' => array(
      'values' => array(
        'best_places_landing_page:page_1' => 'best_places_landing_page:page_1',
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
          'weight' => '-53',
        ),
        'views-3cb0a9086718e6b2cb124994d5a308a1' => array(
          'module' => 'views',
          'delta' => '3cb0a9086718e6b2cb124994d5a308a1',
          'region' => 'content',
          'weight' => '-52',
        ),
        'top100_promo_block-top100_promo' => array(
          'module' => 'top100_promo_block',
          'delta' => 'top100_promo',
          'region' => 'content',
          'weight' => '51',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '53',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('best places');
  $export['best_places_top_10'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'best_places_top_100';
  $context->description = '';
  $context->tag = 'best places';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'best-places/top-100*' => 'best-places/top-100*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'top100_partners_block-top100_partners' => array(
          'module' => 'top100_partners_block',
          'delta' => 'top100_partners',
          'region' => 'sidebar_first',
          'weight' => '51',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('best places');
  $export['best_places_top_100'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_home';
  $context->description = '';
  $context->tag = 'blog';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blog' => 'blog',
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
          'weight' => '-3',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '3',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-popular_blog_posts-block' => array(
          'module' => 'views',
          'delta' => 'popular_blog_posts-block',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-blog_contributors-block' => array(
          'module' => 'views',
          'delta' => 'blog_contributors-block',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'best_places_block-best_places_block' => array(
          'module' => 'best_places_block',
          'delta' => 'best_places_block',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-4',
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
  t('blog');
  $export['blog_home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_posts';
  $context->description = '';
  $context->tag = 'blog';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog_post' => 'blog_post',
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
          'region' => 'content',
          'weight' => '-10',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '10',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-popular_blog_posts-block' => array(
          'module' => 'views',
          'delta' => 'popular_blog_posts-block',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'views-related_blog_posts-block' => array(
          'module' => 'views',
          'delta' => 'related_blog_posts-block',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'best_places_block-best_places_block' => array(
          'module' => 'best_places_block',
          'delta' => 'best_places_block',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blog');
  $export['blog_posts'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'city_articles';
  $context->description = '';
  $context->tag = 'city';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'article_quiz' => 'article_quiz',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'primary_city_set' => array(
      'values' => array(
        'TRUE' => 'TRUE',
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
          'weight' => '-10',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '10',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-61',
        ),
        'views-related_articles-block' => array(
          'module' => 'views',
          'delta' => 'related_articles-block',
          'region' => 'sidebar_first',
          'weight' => '-60',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-59',
        ),
        'city_sections-nearby_cities' => array(
          'module' => 'city_sections',
          'delta' => 'nearby_cities',
          'region' => 'sidebar_first',
          'weight' => '-58',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-57',
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
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('city');
  $export['city_articles'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'city_pages_not_promoted';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'city' => 'city',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'promoted_city' => array(
      'values' => array(
        'FALSE' => 'FALSE',
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
          'weight' => '-10',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '9',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'digital_magazine-digital_magazine' => array(
          'module' => 'digital_magazine',
          'delta' => 'digital_magazine',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'city_sections-city_accolades' => array(
          'module' => 'city_sections',
          'delta' => 'city_accolades',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'city_sections-city_quote' => array(
          'module' => 'city_sections',
          'delta' => 'city_quote',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'city_sections-nearby_cities' => array(
          'module' => 'city_sections',
          'delta' => 'nearby_cities',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-4',
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
  $context->condition_mode = 1;
  $export['city_pages_not_promoted'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'city_pages_promoted';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'city' => 'city',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'promoted_city' => array(
      'values' => array(
        'TRUE' => 'TRUE',
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
          'weight' => '-10',
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
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'digital_magazine-digital_magazine' => array(
          'module' => 'digital_magazine',
          'delta' => 'digital_magazine',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'city_sections-city_accolades' => array(
          'module' => 'city_sections',
          'delta' => 'city_accolades',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'city_sections-city_quote' => array(
          'module' => 'city_sections',
          'delta' => 'city_quote',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'city_sections-nearby_cities' => array(
          'module' => 'city_sections',
          'delta' => 'nearby_cities',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-4',
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
  $context->condition_mode = 1;
  $export['city_pages_promoted'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'city_sections';
  $context->description = '';
  $context->tag = 'city';
  $context->conditions = array(
    'city_section' => array(
      'values' => array(
        'business' => 'business',
        'demographics' => 'demographics',
        'government' => 'government',
        'health' => 'health',
        'real-estate' => 'real-estate',
        'schools' => 'schools',
        'things-to-do' => 'things-to-do',
        'transportation' => 'transportation',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'city_sections-city_accolades' => array(
          'module' => 'city_sections',
          'delta' => 'city_accolades',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'city_sections-nearby_cities' => array(
          'module' => 'city_sections',
          'delta' => 'nearby_cities',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'jci_dfp-jci-dfp-block-14' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-14',
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
          'sidebar_second' => 'sidebar_second',
          'page_top' => 0,
          'header' => 0,
          'highlighted' => 0,
          'help' => 0,
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
  t('city');
  $export['city_sections'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'digital_magazine';
  $context->description = '';
  $context->tag = 'digital magazine';
  $context->conditions = array(
    'city_section' => array(
      'values' => array(
        'digital-magazine' => 'digital-magazine',
      ),
    ),
    'node' => array(
      'values' => array(
        'digital_magazine' => 'digital_magazine',
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
          'region' => 'content',
          'weight' => '-54',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-53',
        ),
        'views-related_articles-block_1' => array(
          'module' => 'views',
          'delta' => 'related_articles-block_1',
          'region' => 'content',
          'weight' => '-52',
        ),
        'city_sections-trulia_widget' => array(
          'module' => 'city_sections',
          'delta' => 'trulia_widget',
          'region' => 'content',
          'weight' => '-51',
        ),
        'jci_dfp-jci-dfp-block-3' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-3',
          'region' => 'content',
          'weight' => '-49',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'city_sections-city_accolades' => array(
          'module' => 'city_sections',
          'delta' => 'city_accolades',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'city_sections-city_quote' => array(
          'module' => 'city_sections',
          'delta' => 'city_quote',
          'region' => 'sidebar_first',
          'weight' => '-6',
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
  t('digital magazine');
  $export['digital_magazine'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_articles';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'article_quiz' => 'article_quiz',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'primary_city_set' => array(
      'values' => array(
        'FALSE' => 'FALSE',
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
          'weight' => '-10',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '10',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'popular_articles_block-popular_articles' => array(
          'module' => 'popular_articles_block',
          'delta' => 'popular_articles',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'best_places_block-best_places_block' => array(
          'module' => 'best_places_block',
          'delta' => 'best_places_block',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-4',
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
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['global_articles'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_footer';
  $context->description = '';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'footer_about_block-footer_about_text' => array(
          'module' => 'footer_about_block',
          'delta' => 'footer_about_text',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'footer_menu_block-footer_menu' => array(
          'module' => 'footer_menu_block',
          'delta' => 'footer_menu',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'footer_social_block-footer_social' => array(
          'module' => 'footer_social_block',
          'delta' => 'footer_social',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'partner_icon_block-partner_icons' => array(
          'module' => 'partner_icon_block',
          'delta' => 'partner_icons',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('global');
  $export['global_footer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_header';
  $context->description = '';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('global');
  $export['global_header'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = '';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
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
  t('home');
  $export['home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'state_pages';
  $context->description = '';
  $context->tag = 'state';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'state' => 'state',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '8',
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
          'weight' => '-9',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-7',
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
          'weight' => '-5',
        ),
        'views-from_the_blog-block' => array(
          'module' => 'views',
          'delta' => 'from_the_blog-block',
          'region' => 'sidebar_first',
          'weight' => '-6',
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
  t('state');
  $export['state_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'top_100';
  $context->description = '';
  $context->tag = 'best places';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'top_100' => 'top_100',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'top_100' => 'top_100',
        'top_100:page' => 'top_100:page',
        'top_100:page_1' => 'top_100:page_1',
        'top_100:page_2' => 'top_100:page_2',
        'top_100:page_3' => 'top_100:page_3',
        'top_100:page_4' => 'top_100:page_4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'combo_ad_blocks-filmstrip' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'filmstrip',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'popular_cities_block-popular_cities' => array(
          'module' => 'popular_cities_block',
          'delta' => 'popular_cities',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'jci_dfp-jci-dfp-block-12' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-12',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'views-from_the_blog-block' => array(
          'module' => 'views',
          'delta' => 'from_the_blog-block',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'jci_dfp-jci-dfp-block-13' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-13',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'top100_partners_block-top100_partners' => array(
          'module' => 'top100_partners_block',
          'delta' => 'top100_partners',
          'region' => 'sidebar_first',
          'weight' => '-3',
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
  t('best places');
  $export['top_100'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'topics_pages';
  $context->description = '';
  $context->tag = 'topics';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'topics' => 'topics',
      ),
    ),
    'views' => array(
      'values' => array(
        'topics' => 'topics',
        'topics:page' => 'topics:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-topics-block' => array(
          'module' => 'views',
          'delta' => 'topics-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'combo_ad_blocks-leaderboard_top' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_top',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-766eed186365628888ba17665e903c5f' => array(
          'module' => 'views',
          'delta' => '766eed186365628888ba17665e903c5f',
          'region' => 'content',
          'weight' => '2',
        ),
        'combo_ad_blocks-leaderboard_bottom' => array(
          'module' => 'combo_ad_blocks',
          'delta' => 'leaderboard_bottom',
          'region' => 'content',
          'weight' => '8',
        ),
        'jci_dfp-jci-dfp-block-11' => array(
          'module' => 'jci_dfp',
          'delta' => 'jci-dfp-block-11',
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
  t('topics');
  $export['topics_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_page';
  $context->description = '';
  $context->tag = 'user';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-user_authored_content-block' => array(
          'module' => 'views',
          'delta' => 'user_authored_content-block',
          'region' => 'content',
          'weight' => '3',
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
          'page_top' => 0,
          'header' => 0,
          'highlighted' => 0,
          'help' => 0,
          'sidebar_first' => 0,
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
  t('user');
  $export['user_page'] = $context;

  return $export;
}
