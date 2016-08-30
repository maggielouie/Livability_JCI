<?php
/**
 * @file
 * city2.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function city2_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-liv-main_arts--entertainment:topics/arts-and-entertainment.
  $menu_links['menu-liv-main_arts--entertainment:topics/arts-and-entertainment'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics/arts-and-entertainment',
    'router_path' => 'topics',
    'link_title' => 'Arts & Entertainment',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_arts--entertainment:topics/arts-and-entertainment',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_topics:topics',
  );
  // Exported menu link: menu-liv-main_best-places-to-live:best-places.
  $menu_links['menu-liv-main_best-places-to-live:best-places'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'best-places',
    'router_path' => 'best-places',
    'link_title' => 'Best Places to Live',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_best-places-to-live:best-places',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-liv-main_blog:blog.
  $menu_links['menu-liv-main_blog:blog'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-liv-main_business--economy:topics/business-and-economy.
  $menu_links['menu-liv-main_business--economy:topics/business-and-economy'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics/business-and-economy',
    'router_path' => 'topics',
    'link_title' => 'Business & Economy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_business--economy:topics/business-and-economy',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_topics:topics',
  );
  // Exported menu link: menu-liv-main_community:topics/community.
  $menu_links['menu-liv-main_community:topics/community'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics/community',
    'router_path' => 'topics',
    'link_title' => 'Community',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_community:topics/community',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_topics:topics',
  );
  // Exported menu link: menu-liv-main_education--schools:topics/education-and-schools.
  $menu_links['menu-liv-main_education--schools:topics/education-and-schools'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics/education-and-schools',
    'router_path' => 'topics',
    'link_title' => 'Education & Schools',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_education--schools:topics/education-and-schools',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_topics:topics',
  );
  // Exported menu link: menu-liv-main_find-a-city:find-city.
  $menu_links['menu-liv-main_find-a-city:find-city'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'find-city',
    'router_path' => 'find-city',
    'link_title' => 'Find a City',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_find-a-city:find-city',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-liv-main_food--drink:topics/food-and-drink.
  $menu_links['menu-liv-main_food--drink:topics/food-and-drink'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics/food-and-drink',
    'router_path' => 'topics',
    'link_title' => 'Food & Drink',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_food--drink:topics/food-and-drink',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_topics:topics',
  );
  // Exported menu link: menu-liv-main_health--wellness:topics/health-and-wellness.
  $menu_links['menu-liv-main_health--wellness:topics/health-and-wellness'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics/health-and-wellness',
    'router_path' => 'topics',
    'link_title' => 'Health & Wellness',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_health--wellness:topics/health-and-wellness',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_topics:topics',
  );
  // Exported menu link: menu-liv-main_housing--real-estate:topics/housing-and-real-estate.
  $menu_links['menu-liv-main_housing--real-estate:topics/housing-and-real-estate'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics/housing-and-real-estate',
    'router_path' => 'topics',
    'link_title' => 'Housing & Real Estate',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_housing--real-estate:topics/housing-and-real-estate',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_topics:topics',
  );
  // Exported menu link: menu-liv-main_how-to-guides:moving/how-to-guides.
  $menu_links['menu-liv-main_how-to-guides:moving/how-to-guides'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'moving/how-to-guides',
    'router_path' => 'moving',
    'link_title' => 'How To Guides',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_how-to-guides:moving/how-to-guides',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_moving:moving',
  );
  // Exported menu link: menu-liv-main_moving-checklist:moving/moving-checklists.
  $menu_links['menu-liv-main_moving-checklist:moving/moving-checklists'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'moving/moving-checklists',
    'router_path' => 'moving',
    'link_title' => 'Moving Checklist',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_moving-checklist:moving/moving-checklists',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_moving:moving',
  );
  // Exported menu link: menu-liv-main_moving-tips:moving/moving-tips.
  $menu_links['menu-liv-main_moving-tips:moving/moving-tips'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'moving/moving-tips',
    'router_path' => 'moving',
    'link_title' => 'Moving Tips',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_moving-tips:moving/moving-tips',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_moving:moving',
  );
  // Exported menu link: menu-liv-main_moving:moving.
  $menu_links['menu-liv-main_moving:moving'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'moving',
    'router_path' => 'moving',
    'link_title' => 'Moving',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_moving:moving',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-liv-main_top-10:top-10.
  $menu_links['menu-liv-main_top-10:top-10'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'top-10',
    'router_path' => 'top-10',
    'link_title' => 'Top 10',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_top-10:top-10',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-liv-main_topics:topics.
  $menu_links['menu-liv-main_topics:topics'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics',
    'router_path' => 'topics',
    'link_title' => 'Topics',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_topics:topics',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-liv-main_transportation:topics/transportation.
  $menu_links['menu-liv-main_transportation:topics/transportation'] = array(
    'menu_name' => 'menu-liv-main',
    'link_path' => 'topics/transportation',
    'router_path' => 'topics',
    'link_title' => 'Transportation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-liv-main_transportation:topics/transportation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-liv-main_topics:topics',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Arts & Entertainment');
  t('Best Places to Live');
  t('Blog');
  t('Business & Economy');
  t('Community');
  t('Education & Schools');
  t('Find a City');
  t('Food & Drink');
  t('Health & Wellness');
  t('Housing & Real Estate');
  t('How To Guides');
  t('Moving');
  t('Moving Checklist');
  t('Moving Tips');
  t('Top 10');
  t('Topics');
  t('Transportation');

  return $menu_links;
}
