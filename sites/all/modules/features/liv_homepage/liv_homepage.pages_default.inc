<?php
/**
 * @file
 * liv_homepage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function liv_homepage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_homepage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1f0b3778-66c1-4b0f-9b26-383514400f73';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1623465c-3448-4b45-a757-6bbbe3d8e5eb';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'homepage_marquee';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1623465c-3448-4b45-a757-6bbbe3d8e5eb';
    $display->content['new-1623465c-3448-4b45-a757-6bbbe3d8e5eb'] = $pane;
    $display->panels['center'][0] = 'new-1623465c-3448-4b45-a757-6bbbe3d8e5eb';
    $pane = new stdClass();
    $pane->pid = 'new-d9232e85-3808-43c1-9e0f-43b36d0978d0';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'liv_home_best_places_nav_block-liv_home_best_places_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd9232e85-3808-43c1-9e0f-43b36d0978d0';
    $display->content['new-d9232e85-3808-43c1-9e0f-43b36d0978d0'] = $pane;
    $display->panels['center'][1] = 'new-d9232e85-3808-43c1-9e0f-43b36d0978d0';
    $pane = new stdClass();
    $pane->pid = 'new-4bb6ea16-04ba-4282-8fec-887f11d20085';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'combo_ad_blocks-leaderboard_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4bb6ea16-04ba-4282-8fec-887f11d20085';
    $display->content['new-4bb6ea16-04ba-4282-8fec-887f11d20085'] = $pane;
    $display->panels['center'][2] = 'new-4bb6ea16-04ba-4282-8fec-887f11d20085';
    $pane = new stdClass();
    $pane->pid = 'new-37b8bcf1-d610-410c-a859-344dc08cdc47';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'recent_global_articles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '37b8bcf1-d610-410c-a859-344dc08cdc47';
    $display->content['new-37b8bcf1-d610-410c-a859-344dc08cdc47'] = $pane;
    $display->panels['center'][3] = 'new-37b8bcf1-d610-410c-a859-344dc08cdc47';
    $pane = new stdClass();
    $pane->pid = 'new-82941d3d-b1f7-44e6-a37b-4d6a54429c63';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'combo_ad_blocks-leaderboard_bottom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '82941d3d-b1f7-44e6-a37b-4d6a54429c63';
    $display->content['new-82941d3d-b1f7-44e6-a37b-4d6a54429c63'] = $pane;
    $display->panels['center'][4] = 'new-82941d3d-b1f7-44e6-a37b-4d6a54429c63';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  return $pages;

}
