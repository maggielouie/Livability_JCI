<?php
/**
 * @file
 * liv_nav.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function liv_nav_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_:<view>
  $menu_links['main-menu_:<view>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<view>',
    'router_path' => '<view>',
    'link_title' => '',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_views' => array(
        'mlid' => 1799,
        'type' => 'view',
        'original_path' => '',
        'view' => array(
          'name' => 'blog_menu_list',
          'display' => 'block',
          'arguments' => '',
          'settings' => array(
            'wrapper_classes' => 'menu-views',
            'breadcrumb' => 1,
            'breadcrumb_title' => '',
            'breadcrumb_path' => '<front>',
            'title' => 0,
            'title_wrapper' => '',
            'title_classes' => '',
            'title_override' => '',
          ),
        ),
      ),
      'identifier' => 'main-menu_:<view>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_blog:blog',
  );
  // Exported menu link: main-menu_best-places-to-live:best-places
  $menu_links['main-menu_best-places-to-live:best-places'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'best-places',
    'router_path' => 'best-places',
    'link_title' => 'Best Places To Live',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_best-places-to-live:best-places',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_blog:blog
  $menu_links['main-menu_blog:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_find-a-city:find-city
  $menu_links['main-menu_find-a-city:find-city'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'find-city',
    'router_path' => 'find-city',
    'link_title' => 'Find a City',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_find-a-city:find-city',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_top-10:top-10
  $menu_links['main-menu_top-10:top-10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'top-10',
    'router_path' => 'top-10',
    'link_title' => 'Top 10',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_top-10:top-10',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_topics:topics
  $menu_links['main-menu_topics:topics'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'topics',
    'router_path' => 'topics',
    'link_title' => 'Topics',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_topics:topics',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Best Places To Live');
  t('Blog');
  t('Find a City');
  t('Top 10');
  t('Topics');


  return $menu_links;
}
