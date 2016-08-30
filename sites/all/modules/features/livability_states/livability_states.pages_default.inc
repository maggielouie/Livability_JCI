<?php
/**
 * @file
 * livability_states.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function livability_states_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'States',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'state' => 'state',
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
  $display->title = '';
  $display->uuid = 'd1a70ead-3c36-4c01-a5a5-d03c38cb480e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4f2567f7-a89a-47d7-a393-300f489b38c7';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_population';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
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
    $pane->uuid = '4f2567f7-a89a-47d7-a393-300f489b38c7';
    $display->content['new-4f2567f7-a89a-47d7-a393-300f489b38c7'] = $pane;
    $display->panels['center'][0] = 'new-4f2567f7-a89a-47d7-a393-300f489b38c7';
    $pane = new stdClass();
    $pane->pid = 'new-2c8be095-81dc-4769-b557-3c789a94ab41';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-counties-block';
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
    $pane->uuid = '2c8be095-81dc-4769-b557-3c789a94ab41';
    $display->content['new-2c8be095-81dc-4769-b557-3c789a94ab41'] = $pane;
    $display->panels['center'][1] = 'new-2c8be095-81dc-4769-b557-3c789a94ab41';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
