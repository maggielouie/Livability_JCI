<?php
/**
 * @file
 * article_slideshow.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function article_slideshow_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'article_slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Article Slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Field collection item: Entity with the List Item (field_list_item_art_ss) */
  $handler->display->display_options['relationships']['field_list_item_art_ss_node']['id'] = 'field_list_item_art_ss_node';
  $handler->display->display_options['relationships']['field_list_item_art_ss_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_list_item_art_ss_node']['field'] = 'field_list_item_art_ss_node';
  /* Field: Content: Headline */
  $handler->display->display_options['fields']['field_headline']['id'] = 'field_headline';
  $handler->display->display_options['fields']['field_headline']['table'] = 'field_data_field_headline';
  $handler->display->display_options['fields']['field_headline']['field'] = 'field_headline';
  $handler->display->display_options['fields']['field_headline']['label'] = '';
  $handler->display->display_options['fields']['field_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_headline']['element_type'] = '0';
  $handler->display->display_options['fields']['field_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_headline']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_headline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_headline']['field_api_classes'] = TRUE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image_single']['id'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['table'] = 'field_data_field_image_single';
  $handler->display->display_options['fields']['field_image_single']['field'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['label'] = '';
  $handler->display->display_options['fields']['field_image_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_single']['element_wrapper_class'] = 'featured-image';
  $handler->display->display_options['fields']['field_image_single']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_single']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_single']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_single']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Body */
  $handler->display->display_options['fields']['field_bp_body']['id'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['table'] = 'field_data_field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['field'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['label'] = '';
  $handler->display->display_options['fields']['field_bp_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bp_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['field_api_classes'] = TRUE;
  /* Field: Field: Quote */
  $handler->display->display_options['fields']['field_pull_quote']['id'] = 'field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['table'] = 'field_data_field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['field'] = 'field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['label'] = '';
  $handler->display->display_options['fields']['field_pull_quote']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pull_quote']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pull_quote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pull_quote']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_pull_quote']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pull_quote']['field_api_classes'] = TRUE;
  /* Field: Field: Person */
  $handler->display->display_options['fields']['field_quote_attribution']['id'] = 'field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['table'] = 'field_data_field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['field'] = 'field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['label'] = '';
  $handler->display->display_options['fields']['field_quote_attribution']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_quote_attribution']['element_type'] = '0';
  $handler->display->display_options['fields']['field_quote_attribution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_quote_attribution']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_quote_attribution']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_quote_attribution']['field_api_classes'] = TRUE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_professional_title']['id'] = 'field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['table'] = 'field_data_field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['field'] = 'field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['label'] = '';
  $handler->display->display_options['fields']['field_professional_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_professional_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_professional_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_professional_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_professional_title']['field_api_classes'] = TRUE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['item_id']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';

  /* Display: Slideshow: all fields */
  $handler = $view->new_display('block', 'Slideshow: all fields', 'block_6');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Headline */
  $handler->display->display_options['fields']['field_headline']['id'] = 'field_headline';
  $handler->display->display_options['fields']['field_headline']['table'] = 'field_data_field_headline';
  $handler->display->display_options['fields']['field_headline']['field'] = 'field_headline';
  $handler->display->display_options['fields']['field_headline']['label'] = '';
  $handler->display->display_options['fields']['field_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_headline']['element_type'] = '0';
  $handler->display->display_options['fields']['field_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_headline']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_headline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_headline']['field_api_classes'] = TRUE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image_single']['id'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['table'] = 'field_data_field_image_single';
  $handler->display->display_options['fields']['field_image_single']['field'] = 'field_image_single';
  $handler->display->display_options['fields']['field_image_single']['label'] = '';
  $handler->display->display_options['fields']['field_image_single']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_single']['element_wrapper_class'] = 'featured-image';
  $handler->display->display_options['fields']['field_image_single']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_single']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_single']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_single']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Body */
  $handler->display->display_options['fields']['field_bp_body']['id'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['table'] = 'field_data_field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['field'] = 'field_bp_body';
  $handler->display->display_options['fields']['field_bp_body']['label'] = '';
  $handler->display->display_options['fields']['field_bp_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bp_body']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bp_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bp_body']['field_api_classes'] = TRUE;
  /* Field: Field: Person */
  $handler->display->display_options['fields']['field_quote_attribution']['id'] = 'field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['table'] = 'field_data_field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['field'] = 'field_quote_attribution';
  $handler->display->display_options['fields']['field_quote_attribution']['label'] = '';
  $handler->display->display_options['fields']['field_quote_attribution']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_quote_attribution']['element_type'] = '0';
  $handler->display->display_options['fields']['field_quote_attribution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_quote_attribution']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_quote_attribution']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_quote_attribution']['field_api_classes'] = TRUE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['field_professional_title']['id'] = 'field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['table'] = 'field_data_field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['field'] = 'field_professional_title';
  $handler->display->display_options['fields']['field_professional_title']['label'] = '';
  $handler->display->display_options['fields']['field_professional_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_professional_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_professional_title']['alter']['text'] = ', [field_professional_title]';
  $handler->display->display_options['fields']['field_professional_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_professional_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_professional_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_professional_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_professional_title']['field_api_classes'] = TRUE;
  /* Field: Field: Quote */
  $handler->display->display_options['fields']['field_pull_quote']['id'] = 'field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['table'] = 'field_data_field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['field'] = 'field_pull_quote';
  $handler->display->display_options['fields']['field_pull_quote']['label'] = '';
  $handler->display->display_options['fields']['field_pull_quote']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pull_quote']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pull_quote']['alter']['text'] = '<span class="quote"><i class="quotes-green-large"></i><p>[field_pull_quote]</p><span class="author">[field_quote_attribution][field_professional_title]</span></span>';
  $handler->display->display_options['fields']['field_pull_quote']['element_type'] = '0';
  $handler->display->display_options['fields']['field_pull_quote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pull_quote']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_pull_quote']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pull_quote']['field_api_classes'] = TRUE;
  /* Field: Field: Highlights */
  $handler->display->display_options['fields']['field_highlights']['id'] = 'field_highlights';
  $handler->display->display_options['fields']['field_highlights']['table'] = 'field_data_field_highlights';
  $handler->display->display_options['fields']['field_highlights']['field'] = 'field_highlights';
  $handler->display->display_options['fields']['field_highlights']['label'] = '';
  $handler->display->display_options['fields']['field_highlights']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_highlights']['element_type'] = '0';
  $handler->display->display_options['fields']['field_highlights']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_highlights']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_highlights']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_highlights']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_highlights']['separator'] = '';
  $handler->display->display_options['fields']['field_highlights']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="featured-image clearfix"> 
[field_image_single]
</span>

<span class="l-275">
[field_highlights]

<span class="no-mobile">
[output_no_mobile]
</span>
<span class="mobile-only">
[output_mobile_only]
</span>

[field_pull_quote]
</span>

<span class="article-content r-275-full">
[field_bp_body]
</span>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $export['article_slideshow'] = $view;

  return $export;
}
