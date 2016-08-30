<?php
/**
 * @file
 * user_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function user_fields_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Author' => 'Author',
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access navbar'.
  $permissions['access navbar'] = array(
    'name' => 'access navbar',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'navbar',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer ctools access ruleset'.
  $permissions['administer ctools access ruleset'] = array(
    'name' => 'administer ctools access ruleset',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools_access_ruleset',
  );

  // Exported permission: 'administer data tables'.
  $permissions['administer data tables'] = array(
    'name' => 'administer data tables',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'data_ui',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu views'.
  $permissions['administer menu views'] = array(
    'name' => 'administer menu views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_views',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer oembed'.
  $permissions['administer oembed'] = array(
    'name' => 'administer oembed',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oembed',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panel-nodes'.
  $permissions['administer panel-nodes'] = array(
    'name' => 'administer panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer schema'.
  $permissions['administer schema'] = array(
    'name' => 'administer schema',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'schema',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer taxonomy display'.
  $permissions['administer taxonomy display'] = array(
    'name' => 'administer taxonomy display',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_display',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'advanced migration information'.
  $permissions['advanced migration information'] = array(
    'name' => 'advanced migration information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create airports content'.
  $permissions['create airports content'] = array(
    'name' => 'create airports content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create area content'.
  $permissions['create area content'] = array(
    'name' => 'create area content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create best_places content'.
  $permissions['create best_places content'] = array(
    'name' => 'create best_places content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create blog_post content'.
  $permissions['create blog_post content'] = array(
    'name' => 'create blog_post content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create city content'.
  $permissions['create city content'] = array(
    'name' => 'create city content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create county content'.
  $permissions['create county content'] = array(
    'name' => 'create county content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_author'.
  $permissions['create field_author'] = array(
    'name' => 'create field_author',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_criterion_title'.
  $permissions['create field_criterion_title'] = array(
    'name' => 'create field_criterion_title',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_featured_homepage'.
  $permissions['create field_featured_homepage'] = array(
    'name' => 'create field_featured_homepage',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_featured_on_place_homepage'.
  $permissions['create field_featured_on_place_homepage'] = array(
    'name' => 'create field_featured_on_place_homepage',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_image_single'.
  $permissions['create field_image_single'] = array(
    'name' => 'create field_image_single',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_place'.
  $permissions['create field_place'] = array(
    'name' => 'create field_place',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_primary_category'.
  $permissions['create field_primary_category'] = array(
    'name' => 'create field_primary_category',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_primary_host'.
  $permissions['create field_primary_host'] = array(
    'name' => 'create field_primary_host',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_print_headline'.
  $permissions['create field_print_headline'] = array(
    'name' => 'create field_print_headline',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_publish_now'.
  $permissions['create field_publish_now'] = array(
    'name' => 'create field_publish_now',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_publish_on'.
  $permissions['create field_publish_on'] = array(
    'name' => 'create field_publish_on',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ranking_criteria'.
  $permissions['create field_ranking_criteria'] = array(
    'name' => 'create field_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ranking_methodology_page'.
  $permissions['create field_ranking_methodology_page'] = array(
    'name' => 'create field_ranking_methodology_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_source_notes'.
  $permissions['create field_source_notes'] = array(
    'name' => 'create field_source_notes',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_summary'.
  $permissions['create field_summary'] = array(
    'name' => 'create field_summary',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_top_100_advisory_board'.
  $permissions['create field_top_100_advisory_board'] = array(
    'name' => 'create field_top_100_advisory_board',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_top_100_advisory_board_pag'.
  $permissions['create field_top_100_advisory_board_pag'] = array(
    'name' => 'create field_top_100_advisory_board_pag',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_top_100_advisory_intro'.
  $permissions['create field_top_100_advisory_intro'] = array(
    'name' => 'create field_top_100_advisory_intro',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_top_100_board_bio'.
  $permissions['create field_top_100_board_bio'] = array(
    'name' => 'create field_top_100_board_bio',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_top_100_board_name'.
  $permissions['create field_top_100_board_name'] = array(
    'name' => 'create field_top_100_board_name',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_top_100_ranking_criteria'.
  $permissions['create field_top_100_ranking_criteria'] = array(
    'name' => 'create field_top_100_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_top_100_ranking_page'.
  $permissions['create field_top_100_ranking_page'] = array(
    'name' => 'create field_top_100_ranking_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create hospitals content'.
  $permissions['create hospitals content'] = array(
    'name' => 'create hospitals content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create panel content'.
  $permissions['create panel content'] = array(
    'name' => 'create panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create panel-nodes'.
  $permissions['create panel-nodes'] = array(
    'name' => 'create panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'create state content'.
  $permissions['create state content'] = array(
    'name' => 'create state content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create top_100 content'.
  $permissions['create top_100 content'] = array(
    'name' => 'create top_100 content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'currency.currency.administer'.
  $permissions['currency.currency.administer'] = array(
    'name' => 'currency.currency.administer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'currency',
  );

  // Exported permission: 'currency.currency_exchanger.administer'.
  $permissions['currency.currency_exchanger.administer'] = array(
    'name' => 'currency.currency_exchanger.administer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'currency',
  );

  // Exported permission: 'currency.currency_locale_pattern.administer'.
  $permissions['currency.currency_locale_pattern.administer'] = array(
    'name' => 'currency.currency_locale_pattern.administer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'currency',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete any airports content'.
  $permissions['delete any airports content'] = array(
    'name' => 'delete any airports content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any area content'.
  $permissions['delete any area content'] = array(
    'name' => 'delete any area content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any best_places content'.
  $permissions['delete any best_places content'] = array(
    'name' => 'delete any best_places content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any blog_post content'.
  $permissions['delete any blog_post content'] = array(
    'name' => 'delete any blog_post content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any city content'.
  $permissions['delete any city content'] = array(
    'name' => 'delete any city content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any county content'.
  $permissions['delete any county content'] = array(
    'name' => 'delete any county content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any hospitals content'.
  $permissions['delete any hospitals content'] = array(
    'name' => 'delete any hospitals content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any panel content'.
  $permissions['delete any panel content'] = array(
    'name' => 'delete any panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any panel-nodes'.
  $permissions['delete any panel-nodes'] = array(
    'name' => 'delete any panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'delete any state content'.
  $permissions['delete any state content'] = array(
    'name' => 'delete any state content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any top_100 content'.
  $permissions['delete any top_100 content'] = array(
    'name' => 'delete any top_100 content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own airports content'.
  $permissions['delete own airports content'] = array(
    'name' => 'delete own airports content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own area content'.
  $permissions['delete own area content'] = array(
    'name' => 'delete own area content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own best_places content'.
  $permissions['delete own best_places content'] = array(
    'name' => 'delete own best_places content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own blog_post content'.
  $permissions['delete own blog_post content'] = array(
    'name' => 'delete own blog_post content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own city content'.
  $permissions['delete own city content'] = array(
    'name' => 'delete own city content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own county content'.
  $permissions['delete own county content'] = array(
    'name' => 'delete own county content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own hospitals content'.
  $permissions['delete own hospitals content'] = array(
    'name' => 'delete own hospitals content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own panel content'.
  $permissions['delete own panel content'] = array(
    'name' => 'delete own panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own panel-nodes'.
  $permissions['delete own panel-nodes'] = array(
    'name' => 'delete own panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'delete own state content'.
  $permissions['delete own state content'] = array(
    'name' => 'delete own state content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own top_100 content'.
  $permissions['delete own top_100 content'] = array(
    'name' => 'delete own top_100 content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in best_places'.
  $permissions['delete terms in best_places'] = array(
    'name' => 'delete terms in best_places',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in blog_category'.
  $permissions['delete terms in blog_category'] = array(
    'name' => 'delete terms in blog_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in category'.
  $permissions['delete terms in category'] = array(
    'name' => 'delete terms in category',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in internal_category'.
  $permissions['delete terms in internal_category'] = array(
    'name' => 'delete terms in internal_category',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any airports content'.
  $permissions['edit any airports content'] = array(
    'name' => 'edit any airports content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any area content'.
  $permissions['edit any area content'] = array(
    'name' => 'edit any area content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any best_places content'.
  $permissions['edit any best_places content'] = array(
    'name' => 'edit any best_places content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any blog_post content'.
  $permissions['edit any blog_post content'] = array(
    'name' => 'edit any blog_post content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any city content'.
  $permissions['edit any city content'] = array(
    'name' => 'edit any city content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any county content'.
  $permissions['edit any county content'] = array(
    'name' => 'edit any county content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any hospitals content'.
  $permissions['edit any hospitals content'] = array(
    'name' => 'edit any hospitals content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any panel content'.
  $permissions['edit any panel content'] = array(
    'name' => 'edit any panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any panel-nodes'.
  $permissions['edit any panel-nodes'] = array(
    'name' => 'edit any panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'edit any state content'.
  $permissions['edit any state content'] = array(
    'name' => 'edit any state content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any top_100 content'.
  $permissions['edit any top_100 content'] = array(
    'name' => 'edit any top_100 content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit field_author'.
  $permissions['edit field_author'] = array(
    'name' => 'edit field_author',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_criterion_title'.
  $permissions['edit field_criterion_title'] = array(
    'name' => 'edit field_criterion_title',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_featured_homepage'.
  $permissions['edit field_featured_homepage'] = array(
    'name' => 'edit field_featured_homepage',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_featured_on_place_homepage'.
  $permissions['edit field_featured_on_place_homepage'] = array(
    'name' => 'edit field_featured_on_place_homepage',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_image_single'.
  $permissions['edit field_image_single'] = array(
    'name' => 'edit field_image_single',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_place'.
  $permissions['edit field_place'] = array(
    'name' => 'edit field_place',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_primary_category'.
  $permissions['edit field_primary_category'] = array(
    'name' => 'edit field_primary_category',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_primary_host'.
  $permissions['edit field_primary_host'] = array(
    'name' => 'edit field_primary_host',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_print_headline'.
  $permissions['edit field_print_headline'] = array(
    'name' => 'edit field_print_headline',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_publish_now'.
  $permissions['edit field_publish_now'] = array(
    'name' => 'edit field_publish_now',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_publish_on'.
  $permissions['edit field_publish_on'] = array(
    'name' => 'edit field_publish_on',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ranking_criteria'.
  $permissions['edit field_ranking_criteria'] = array(
    'name' => 'edit field_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ranking_methodology_page'.
  $permissions['edit field_ranking_methodology_page'] = array(
    'name' => 'edit field_ranking_methodology_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_source_notes'.
  $permissions['edit field_source_notes'] = array(
    'name' => 'edit field_source_notes',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_summary'.
  $permissions['edit field_summary'] = array(
    'name' => 'edit field_summary',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_top_100_advisory_board'.
  $permissions['edit field_top_100_advisory_board'] = array(
    'name' => 'edit field_top_100_advisory_board',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_top_100_advisory_board_pag'.
  $permissions['edit field_top_100_advisory_board_pag'] = array(
    'name' => 'edit field_top_100_advisory_board_pag',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_top_100_advisory_intro'.
  $permissions['edit field_top_100_advisory_intro'] = array(
    'name' => 'edit field_top_100_advisory_intro',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_top_100_board_bio'.
  $permissions['edit field_top_100_board_bio'] = array(
    'name' => 'edit field_top_100_board_bio',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_top_100_board_name'.
  $permissions['edit field_top_100_board_name'] = array(
    'name' => 'edit field_top_100_board_name',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_top_100_ranking_criteria'.
  $permissions['edit field_top_100_ranking_criteria'] = array(
    'name' => 'edit field_top_100_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_top_100_ranking_page'.
  $permissions['edit field_top_100_ranking_page'] = array(
    'name' => 'edit field_top_100_ranking_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own airports content'.
  $permissions['edit own airports content'] = array(
    'name' => 'edit own airports content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own area content'.
  $permissions['edit own area content'] = array(
    'name' => 'edit own area content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own best_places content'.
  $permissions['edit own best_places content'] = array(
    'name' => 'edit own best_places content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own blog_post content'.
  $permissions['edit own blog_post content'] = array(
    'name' => 'edit own blog_post content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own city content'.
  $permissions['edit own city content'] = array(
    'name' => 'edit own city content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own county content'.
  $permissions['edit own county content'] = array(
    'name' => 'edit own county content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own field_author'.
  $permissions['edit own field_author'] = array(
    'name' => 'edit own field_author',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_criterion_title'.
  $permissions['edit own field_criterion_title'] = array(
    'name' => 'edit own field_criterion_title',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_featured_homepage'.
  $permissions['edit own field_featured_homepage'] = array(
    'name' => 'edit own field_featured_homepage',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_featured_on_place_homepage'.
  $permissions['edit own field_featured_on_place_homepage'] = array(
    'name' => 'edit own field_featured_on_place_homepage',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_image_single'.
  $permissions['edit own field_image_single'] = array(
    'name' => 'edit own field_image_single',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_place'.
  $permissions['edit own field_place'] = array(
    'name' => 'edit own field_place',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_primary_category'.
  $permissions['edit own field_primary_category'] = array(
    'name' => 'edit own field_primary_category',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_primary_host'.
  $permissions['edit own field_primary_host'] = array(
    'name' => 'edit own field_primary_host',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_print_headline'.
  $permissions['edit own field_print_headline'] = array(
    'name' => 'edit own field_print_headline',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_publish_now'.
  $permissions['edit own field_publish_now'] = array(
    'name' => 'edit own field_publish_now',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_publish_on'.
  $permissions['edit own field_publish_on'] = array(
    'name' => 'edit own field_publish_on',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ranking_criteria'.
  $permissions['edit own field_ranking_criteria'] = array(
    'name' => 'edit own field_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ranking_methodology_page'.
  $permissions['edit own field_ranking_methodology_page'] = array(
    'name' => 'edit own field_ranking_methodology_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_source_notes'.
  $permissions['edit own field_source_notes'] = array(
    'name' => 'edit own field_source_notes',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_summary'.
  $permissions['edit own field_summary'] = array(
    'name' => 'edit own field_summary',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_top_100_advisory_board'.
  $permissions['edit own field_top_100_advisory_board'] = array(
    'name' => 'edit own field_top_100_advisory_board',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_top_100_advisory_board_pag'.
  $permissions['edit own field_top_100_advisory_board_pag'] = array(
    'name' => 'edit own field_top_100_advisory_board_pag',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_top_100_advisory_intro'.
  $permissions['edit own field_top_100_advisory_intro'] = array(
    'name' => 'edit own field_top_100_advisory_intro',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_top_100_board_bio'.
  $permissions['edit own field_top_100_board_bio'] = array(
    'name' => 'edit own field_top_100_board_bio',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_top_100_board_name'.
  $permissions['edit own field_top_100_board_name'] = array(
    'name' => 'edit own field_top_100_board_name',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_top_100_ranking_criteria'.
  $permissions['edit own field_top_100_ranking_criteria'] = array(
    'name' => 'edit own field_top_100_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_top_100_ranking_page'.
  $permissions['edit own field_top_100_ranking_page'] = array(
    'name' => 'edit own field_top_100_ranking_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own hospitals content'.
  $permissions['edit own hospitals content'] = array(
    'name' => 'edit own hospitals content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own panel content'.
  $permissions['edit own panel content'] = array(
    'name' => 'edit own panel content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own panel-nodes'.
  $permissions['edit own panel-nodes'] = array(
    'name' => 'edit own panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'edit own state content'.
  $permissions['edit own state content'] = array(
    'name' => 'edit own state content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own top_100 content'.
  $permissions['edit own top_100 content'] = array(
    'name' => 'edit own top_100 content',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit terms in best_places'.
  $permissions['edit terms in best_places'] = array(
    'name' => 'edit terms in best_places',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in blog_category'.
  $permissions['edit terms in blog_category'] = array(
    'name' => 'edit terms in blog_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in category'.
  $permissions['edit terms in category'] = array(
    'name' => 'edit terms in category',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in internal_category'.
  $permissions['edit terms in internal_category'] = array(
    'name' => 'edit terms in internal_category',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'migration information'.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view field_author'.
  $permissions['view field_author'] = array(
    'name' => 'view field_author',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_criterion_title'.
  $permissions['view field_criterion_title'] = array(
    'name' => 'view field_criterion_title',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_featured_homepage'.
  $permissions['view field_featured_homepage'] = array(
    'name' => 'view field_featured_homepage',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_featured_on_place_homepage'.
  $permissions['view field_featured_on_place_homepage'] = array(
    'name' => 'view field_featured_on_place_homepage',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_image_single'.
  $permissions['view field_image_single'] = array(
    'name' => 'view field_image_single',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_place'.
  $permissions['view field_place'] = array(
    'name' => 'view field_place',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_primary_category'.
  $permissions['view field_primary_category'] = array(
    'name' => 'view field_primary_category',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_primary_host'.
  $permissions['view field_primary_host'] = array(
    'name' => 'view field_primary_host',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_print_headline'.
  $permissions['view field_print_headline'] = array(
    'name' => 'view field_print_headline',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_publish_now'.
  $permissions['view field_publish_now'] = array(
    'name' => 'view field_publish_now',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_publish_on'.
  $permissions['view field_publish_on'] = array(
    'name' => 'view field_publish_on',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ranking_criteria'.
  $permissions['view field_ranking_criteria'] = array(
    'name' => 'view field_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ranking_methodology_page'.
  $permissions['view field_ranking_methodology_page'] = array(
    'name' => 'view field_ranking_methodology_page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_source_notes'.
  $permissions['view field_source_notes'] = array(
    'name' => 'view field_source_notes',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_summary'.
  $permissions['view field_summary'] = array(
    'name' => 'view field_summary',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_top_100_advisory_board'.
  $permissions['view field_top_100_advisory_board'] = array(
    'name' => 'view field_top_100_advisory_board',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_top_100_advisory_board_pag'.
  $permissions['view field_top_100_advisory_board_pag'] = array(
    'name' => 'view field_top_100_advisory_board_pag',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_top_100_advisory_intro'.
  $permissions['view field_top_100_advisory_intro'] = array(
    'name' => 'view field_top_100_advisory_intro',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_top_100_board_bio'.
  $permissions['view field_top_100_board_bio'] = array(
    'name' => 'view field_top_100_board_bio',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_top_100_board_name'.
  $permissions['view field_top_100_board_name'] = array(
    'name' => 'view field_top_100_board_name',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_top_100_ranking_criteria'.
  $permissions['view field_top_100_ranking_criteria'] = array(
    'name' => 'view field_top_100_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_top_100_ranking_page'.
  $permissions['view field_top_100_ranking_page'] = array(
    'name' => 'view field_top_100_ranking_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own field_author'.
  $permissions['view own field_author'] = array(
    'name' => 'view own field_author',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_criterion_title'.
  $permissions['view own field_criterion_title'] = array(
    'name' => 'view own field_criterion_title',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_featured_homepage'.
  $permissions['view own field_featured_homepage'] = array(
    'name' => 'view own field_featured_homepage',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_featured_on_place_homepage'.
  $permissions['view own field_featured_on_place_homepage'] = array(
    'name' => 'view own field_featured_on_place_homepage',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_image_single'.
  $permissions['view own field_image_single'] = array(
    'name' => 'view own field_image_single',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_place'.
  $permissions['view own field_place'] = array(
    'name' => 'view own field_place',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_primary_category'.
  $permissions['view own field_primary_category'] = array(
    'name' => 'view own field_primary_category',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_primary_host'.
  $permissions['view own field_primary_host'] = array(
    'name' => 'view own field_primary_host',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_print_headline'.
  $permissions['view own field_print_headline'] = array(
    'name' => 'view own field_print_headline',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_publish_now'.
  $permissions['view own field_publish_now'] = array(
    'name' => 'view own field_publish_now',
    'roles' => array(
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_publish_on'.
  $permissions['view own field_publish_on'] = array(
    'name' => 'view own field_publish_on',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ranking_criteria'.
  $permissions['view own field_ranking_criteria'] = array(
    'name' => 'view own field_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ranking_methodology_page'.
  $permissions['view own field_ranking_methodology_page'] = array(
    'name' => 'view own field_ranking_methodology_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_source_notes'.
  $permissions['view own field_source_notes'] = array(
    'name' => 'view own field_source_notes',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_summary'.
  $permissions['view own field_summary'] = array(
    'name' => 'view own field_summary',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_top_100_advisory_board'.
  $permissions['view own field_top_100_advisory_board'] = array(
    'name' => 'view own field_top_100_advisory_board',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_top_100_advisory_board_pag'.
  $permissions['view own field_top_100_advisory_board_pag'] = array(
    'name' => 'view own field_top_100_advisory_board_pag',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_top_100_advisory_intro'.
  $permissions['view own field_top_100_advisory_intro'] = array(
    'name' => 'view own field_top_100_advisory_intro',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_top_100_board_bio'.
  $permissions['view own field_top_100_board_bio'] = array(
    'name' => 'view own field_top_100_board_bio',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_top_100_board_name'.
  $permissions['view own field_top_100_board_name'] = array(
    'name' => 'view own field_top_100_board_name',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_top_100_ranking_criteria'.
  $permissions['view own field_top_100_ranking_criteria'] = array(
    'name' => 'view own field_top_100_ranking_criteria',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_top_100_ranking_page'.
  $permissions['view own field_top_100_ranking_page'] = array(
    'name' => 'view own field_top_100_ranking_page',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Author' => 'Author',
      'Editor' => 'Editor',
      'Proof Reader' => 'Proof Reader',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
