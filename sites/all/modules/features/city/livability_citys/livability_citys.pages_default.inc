<?php
/**
 * @file
 * livability_citys.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function livability_citys_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Health',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/*/health',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'area' => 'area',
              'city' => 'city',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = 'Health in %node:title, %node:field_state';
  $display->uuid = 'b39cd086-92f3-4f26-b31f-a7f7ad391223';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Access to quality hospitals, doctors and healthcare providers are just part of what make a healthy community. Here&rsquo;s how to get and stay healthy in&nbsp;%node:title.</p>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d32bba8-775e-4a86-835d-5fb45a86639f';
    $display->content['new-4d32bba8-775e-4a86-835d-5fb45a86639f'] = $pane;
    $display->panels['center'][0] = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Schools',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/*/schools',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'area' => 'area',
              'city' => 'city',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = 'Schools in %node:title, %node:field_state';
  $display->uuid = 'b39cd086-92f3-4f26-b31f-a7f7ad391223';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>The quality of a school district remains a top factor for parents considering where to live. Strong school systems attract new residents and help their cities prosper. See how %node:title schools rate.</p>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d32bba8-775e-4a86-835d-5fb45a86639f';
    $display->content['new-4d32bba8-775e-4a86-835d-5fb45a86639f'] = $pane;
    $display->panels['center'][0] = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Business',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/*/business',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'area' => 'area',
              'city' => 'city',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = 'Business in %node:title, %node:field_state';
  $display->uuid = 'b39cd086-92f3-4f26-b31f-a7f7ad391223';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Being a great place to live often means being a great place to work, too. Here&rsquo;s what the business and employment climate is like in %node:title.</p>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d32bba8-775e-4a86-835d-5fb45a86639f';
    $display->content['new-4d32bba8-775e-4a86-835d-5fb45a86639f'] = $pane;
    $display->panels['center'][0] = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Transportation',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/*/transportation',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'area' => 'area',
              'city' => 'city',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = 'Transportation in %node:title, %node:field_state';
  $display->uuid = 'b39cd086-92f3-4f26-b31f-a7f7ad391223';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Transportation in %node:title is an important part of livability. Getting around town should be a breeze whether you drive, bike, walk or commute by public transportation.</p>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d32bba8-775e-4a86-835d-5fb45a86639f';
    $display->content['new-4d32bba8-775e-4a86-835d-5fb45a86639f'] = $pane;
    $display->panels['center'][0] = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Government',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/*/government',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'area' => 'area',
              'city' => 'city',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = 'Government in %node:title, %node:field_state';
  $display->uuid = 'b39cd086-92f3-4f26-b31f-a7f7ad391223';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>%node:title is in the &lt;city_congressional_district&gt; of %node:field_state and is represented in the U.S. Congress by &lt;congressperson&gt;. Learn more about the state and local governments in %node:title.</p>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d32bba8-775e-4a86-835d-5fb45a86639f';
    $display->content['new-4d32bba8-775e-4a86-835d-5fb45a86639f'] = $pane;
    $display->panels['center'][0] = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Demographics',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/*/demographics',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'area' => 'area',
              'city' => 'city',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = 'Demographics in %node:title, %node:field_state';
  $display->uuid = 'b39cd086-92f3-4f26-b31f-a7f7ad391223';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>The demographics of %node:title, %node:field_state refers to the racial and ethnic make-up of the population as well as age, income and other characteristics. If you are thinking of moving to %node:title, these are the people in your neighborhood.</p>',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d32bba8-775e-4a86-835d-5fb45a86639f';
    $display->content['new-4d32bba8-775e-4a86-835d-5fb45a86639f'] = $pane;
    $display->panels['center'][0] = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
    $pane = new stdClass();
    $pane->pid = 'new-dc9cb6b5-474a-44e9-8d33-b67fe7da16ee';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'articles_by_category';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '15',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '%1',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => 'argument_entity_id:node_1.field-category',
        1 => '',
      ),
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
    $pane->uuid = 'dc9cb6b5-474a-44e9-8d33-b67fe7da16ee';
    $display->content['new-dc9cb6b5-474a-44e9-8d33-b67fe7da16ee'] = $pane;
    $display->panels['center'][1] = 'new-dc9cb6b5-474a-44e9-8d33-b67fe7da16ee';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d32bba8-775e-4a86-835d-5fb45a86639f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  return $export;
}
