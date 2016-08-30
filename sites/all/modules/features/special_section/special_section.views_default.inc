<?php
/**
 * @file
 * special_section.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function special_section_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'special_section';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Special Section';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Special Section';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Sponsor Link */
  $handler->display->display_options['fields']['field_sponsor_link']['id'] = 'field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['table'] = 'field_data_field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['field'] = 'field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_sponsor_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_sponsor_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_link']['field_api_classes'] = TRUE;
  /* Field: Content: Sponsor Facebook Link */
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['id'] = 'field_sponsor_facebook_link';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['table'] = 'field_data_field_sponsor_facebook_link';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['field'] = 'field_sponsor_facebook_link';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['alter']['text'] = '<i class="icon-facebook-square"></i>';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['alter']['path'] = '[field_sponsor_facebook_link]';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_facebook_link']['field_api_classes'] = TRUE;
  /* Field: Content: Sponsor Twitter Link */
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['id'] = 'field_sponsor_twitter_link';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['table'] = 'field_data_field_sponsor_twitter_link';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['field'] = 'field_sponsor_twitter_link';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['alter']['text'] = '<i class="icon-twitter-square"></i>';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['alter']['path'] = '[field_sponsor_twitter_link]';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_twitter_link']['field_api_classes'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['text'] = '<div class="ss-col ss-header">
<a href="[field_sponsor_link]" target="_blank">[field_sponsor_logo]</a>
<div class="ss-social-media">
[field_sponsor_facebook_link]
[field_sponsor_twitter_link]
</div>
</div>';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'sponsor_logo',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_sponsor_logo']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_ss_description']['id'] = 'field_ss_description';
  $handler->display->display_options['fields']['field_ss_description']['table'] = 'field_data_field_ss_description';
  $handler->display->display_options['fields']['field_ss_description']['field'] = 'field_ss_description';
  $handler->display->display_options['fields']['field_ss_description']['label'] = '';
  $handler->display->display_options['fields']['field_ss_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ss_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ss_description']['element_default_classes'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_photo']['alter']['text'] = '<div class="ss-photo-c">
<div class="ss-col ss-photo-container">
<div class="ss-shade">
<div class="ss-photo-c-d"><h1>[title]</h1>
<div class="ss-photo-c-d-c"><p>[field_ss_description]</p></div>
</div>
</div>
<div class="ss-photo">[field_photo]</div>
</div>
</div>';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => 'special_edition_hero',
    'image_link' => '',
  );
  /* Field: Content: Header */
  $handler->display->display_options['fields']['field_ss_header']['id'] = 'field_ss_header';
  $handler->display->display_options['fields']['field_ss_header']['table'] = 'field_data_field_ss_header';
  $handler->display->display_options['fields']['field_ss_header']['field'] = 'field_ss_header';
  $handler->display->display_options['fields']['field_ss_header']['label'] = '';
  $handler->display->display_options['fields']['field_ss_header']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ss_header']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_ss_header']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ss_header']['element_default_classes'] = FALSE;
  /* Field: Content: Deck */
  $handler->display->display_options['fields']['field_ss_deck']['id'] = 'field_ss_deck';
  $handler->display->display_options['fields']['field_ss_deck']['table'] = 'field_data_field_ss_deck';
  $handler->display->display_options['fields']['field_ss_deck']['field'] = 'field_ss_deck';
  $handler->display->display_options['fields']['field_ss_deck']['label'] = '';
  $handler->display->display_options['fields']['field_ss_deck']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ss_deck']['alter']['text'] = '<div class="ss-col"><h2>[field_ss_header]</h2><p>[field_ss_deck]</p></div>';
  $handler->display->display_options['fields']['field_ss_deck']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ss_deck']['element_default_classes'] = FALSE;
  /* Field: Content: Articles */
  $handler->display->display_options['fields']['field_ss_articles']['id'] = 'field_ss_articles';
  $handler->display->display_options['fields']['field_ss_articles']['table'] = 'field_data_field_ss_articles';
  $handler->display->display_options['fields']['field_ss_articles']['field'] = 'field_ss_articles';
  $handler->display->display_options['fields']['field_ss_articles']['label'] = '';
  $handler->display->display_options['fields']['field_ss_articles']['element_type'] = '0';
  $handler->display->display_options['fields']['field_ss_articles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ss_articles']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_ss_articles']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ss_articles']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_ss_articles']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_ss_articles']['field_api_classes'] = TRUE;
  /* Field: Content: Data Graphic */
  $handler->display->display_options['fields']['field_ss_data_graphic']['id'] = 'field_ss_data_graphic';
  $handler->display->display_options['fields']['field_ss_data_graphic']['table'] = 'field_data_field_ss_data_graphic';
  $handler->display->display_options['fields']['field_ss_data_graphic']['field'] = 'field_ss_data_graphic';
  $handler->display->display_options['fields']['field_ss_data_graphic']['label'] = '';
  $handler->display->display_options['fields']['field_ss_data_graphic']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ss_data_graphic']['alter']['text'] = '<div class="ss-col">[field_ss_data_graphic]</div>';
  $handler->display->display_options['fields']['field_ss_data_graphic']['element_type'] = '0';
  $handler->display->display_options['fields']['field_ss_data_graphic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ss_data_graphic']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_ss_data_graphic']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ss_data_graphic']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ss_data_graphic']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_ss_data_graphic']['field_api_classes'] = TRUE;
  /* Field: Content: Sponsor Logo */
  $handler->display->display_options['fields']['field_sponsor_logo_1']['id'] = 'field_sponsor_logo_1';
  $handler->display->display_options['fields']['field_sponsor_logo_1']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo_1']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo_1']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo_1']['settings'] = array(
    'image_style' => 'sponsor_logo',
    'image_link' => '',
  );
  /* Field: Content: Header */
  $handler->display->display_options['fields']['field_ss_dm_header']['id'] = 'field_ss_dm_header';
  $handler->display->display_options['fields']['field_ss_dm_header']['table'] = 'field_data_field_ss_dm_header';
  $handler->display->display_options['fields']['field_ss_dm_header']['field'] = 'field_ss_dm_header';
  $handler->display->display_options['fields']['field_ss_dm_header']['label'] = '';
  $handler->display->display_options['fields']['field_ss_dm_header']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ss_dm_header']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ss_dm_header']['element_default_classes'] = FALSE;
  /* Field: Content: Embed Link */
  $handler->display->display_options['fields']['field_ss_dm_embed_link']['id'] = 'field_ss_dm_embed_link';
  $handler->display->display_options['fields']['field_ss_dm_embed_link']['table'] = 'field_data_field_ss_dm_embed_link';
  $handler->display->display_options['fields']['field_ss_dm_embed_link']['field'] = 'field_ss_dm_embed_link';
  $handler->display->display_options['fields']['field_ss_dm_embed_link']['label'] = '';
  $handler->display->display_options['fields']['field_ss_dm_embed_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ss_dm_embed_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ss_dm_embed_link']['element_default_classes'] = FALSE;
  /* Field: Content: Deck */
  $handler->display->display_options['fields']['field_ss_dm_deck']['id'] = 'field_ss_dm_deck';
  $handler->display->display_options['fields']['field_ss_dm_deck']['table'] = 'field_data_field_ss_dm_deck';
  $handler->display->display_options['fields']['field_ss_dm_deck']['field'] = 'field_ss_dm_deck';
  $handler->display->display_options['fields']['field_ss_dm_deck']['label'] = '';
  $handler->display->display_options['fields']['field_ss_dm_deck']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ss_dm_deck']['alter']['text'] = '<div class="ss-col"><h2>[field_ss_dm_header]</h2><p><span class="ss-sponsor-logo"><a href="[field_sponsor_link]" target="_blank">[field_sponsor_logo_1]</a></span>[field_ss_dm_deck]</p><div class="ss-embed-link">[field_ss_dm_embed_link]</div>
</div>';
  $handler->display->display_options['fields']['field_ss_dm_deck']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ss_dm_deck']['element_default_classes'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special_section' => 'special_section',
  );

  /* Display: Special Section Landing */
  $handler = $view->new_display('block', 'Special Section Landing', 'block');

  /* Display: Special Section Articles */
  $handler = $view->new_display('block', 'Special Section Articles', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Special Section Articles';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_photo']['field_api_classes'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'READ MORE';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="ss-article-content"><h3>[title]</h3><p class="ss-article-body">[body]</p><p class="ss-article-more">[view_node]</p></div>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special_section_article' => 'special_section_article',
  );

  /* Display: Article Detail page */
  $handler = $view->new_display('block', 'Article Detail page', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Photo Caption */
  $handler->display->display_options['fields']['field_photo_caption']['id'] = 'field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['table'] = 'field_data_field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['field'] = 'field_photo_caption';
  $handler->display->display_options['fields']['field_photo_caption']['label'] = '';
  $handler->display->display_options['fields']['field_photo_caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_photo_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_caption']['element_default_classes'] = FALSE;
  /* Field: Content: Photo Credit */
  $handler->display->display_options['fields']['field_photo_credit']['id'] = 'field_photo_credit';
  $handler->display->display_options['fields']['field_photo_credit']['table'] = 'field_data_field_photo_credit';
  $handler->display->display_options['fields']['field_photo_credit']['field'] = 'field_photo_credit';
  $handler->display->display_options['fields']['field_photo_credit']['label'] = '';
  $handler->display->display_options['fields']['field_photo_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_photo_credit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_credit']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="ss-article-photo">[field_photo]
<div class="ss-article-photo-credit">[field_photo_credit]</div>
<p class="ss-article-photo-caption">[field_photo_caption]</p>
</div>
<div class="ss-article-detail-content">
<h1>[title]</h1>
[body]
</div>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special_section_article' => 'special_section_article',
  );

  /* Display: Related Stories */
  $handler = $view->new_display('block', 'Related Stories', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Stories';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h3>[title]</h3>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<p>[body]</p>';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '180';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read More';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special_section_article' => 'special_section_article',
  );
  $export['special_section'] = $view;

  return $export;
}
