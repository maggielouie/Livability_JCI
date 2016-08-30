<?php
/**
 * @file
 * livability_article.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function livability_article_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'custom_byline' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'author' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'author',
    ),
  );
  $export['node|article|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|marquee';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'marquee';
  $ds_fieldsetting->settings = array(
    'read_more_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|article|marquee'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|search_results';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'search_results';
  $ds_fieldsetting->settings = array(
    'read_more_url' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'more',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'author' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'author',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' | ',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'ds_post_date_m_d_y_notime',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'date',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'search-snippet',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_short_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article|search_results'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function livability_article_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'custom_byline';
  $ds_field->label = 'Custom Byline';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'article|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
  if(isset($entity->field_author[\'und\'][0])) {$author = user_load($entity->field_author[\'und\'][0][\'target_id\']); $name = $author->name; echo "By " . l($author->name, \'user/\'.$author->uid) . " on "; }
  elseif (isset($entity->field_byline[\'und\'][0])) { $name = $entity->field_byline[\'und\'][0][\'value\']; echo "By $name on "; }
echo date(\'F j, Y\', $entity->created); ?> at <?php echo date(\'g:i a T\', $entity->created); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['custom_byline'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'read_more_link';
  $ds_field->label = 'Read More link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'article|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php print l("Read More &raquo;", "node/".$entity->nid); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['read_more_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'title';
  $ds_field->label = 'Title';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array();
  $export['title'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function livability_article_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_category|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_category';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_3col_equal_width';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_category_ref',
      ),
      'right' => array(
        1 => 'field_featured_in_category',
      ),
      'middle' => array(
        2 => 'field_primary_category',
      ),
      'hidden' => array(
        3 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_category_ref' => 'left',
      'field_featured_in_category' => 'right',
      'field_primary_category' => 'middle',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_category|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_place|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_place';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_3col_equal_width';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_place_ref',
      ),
      'middle' => array(
        1 => 'field_primary_host',
      ),
      'right' => array(
        2 => 'field_featured_on_place_homepage',
      ),
      'hidden' => array(
        3 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_place_ref' => 'left',
      'field_primary_host' => 'middle',
      'field_featured_on_place_homepage' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_place|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_sources|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_sources';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_source_name',
      ),
      'right' => array(
        1 => 'field_source_url',
      ),
      'hidden' => array(
        2 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_source_name' => 'left',
      'field_source_url' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_sources|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'two_column__6633';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_print_headline',
        2 => 'field_byline',
        3 => 'field_author',
        4 => 'field_deck',
        5 => 'field_short_description',
        6 => 'body',
        7 => 'field_place',
        8 => 'field_category',
        9 => 'field_featured_homepage',
        10 => 'group_meta',
        13 => 'path',
        27 => 'field_page_title',
        29 => 'field_meta_description',
      ),
      'right' => array(
        11 => 'field_publish_on',
        12 => 'field_publish_now',
        14 => 'group_publishing_options',
        15 => 'field_internal_category',
        16 => 'field_source_notes',
        17 => 'field_image',
        18 => 'field_article_thumbnail',
        19 => 'field_highlights',
        20 => 'group_pull_quote',
        21 => 'field_pull_quote',
        22 => '_add_existing_field',
        23 => 'field_quote_attribution',
        25 => 'field_professional_title',
      ),
      'hidden' => array(
        24 => 'field_tags',
        26 => 'redirect',
        28 => 'xmlsitemap',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_print_headline' => 'left',
      'field_byline' => 'left',
      'field_author' => 'left',
      'field_deck' => 'left',
      'field_short_description' => 'left',
      'body' => 'left',
      'field_place' => 'left',
      'field_category' => 'left',
      'field_featured_homepage' => 'left',
      'group_meta' => 'left',
      'field_publish_on' => 'right',
      'field_publish_now' => 'right',
      'path' => 'left',
      'group_publishing_options' => 'right',
      'field_internal_category' => 'right',
      'field_source_notes' => 'right',
      'field_image' => 'right',
      'field_article_thumbnail' => 'right',
      'field_highlights' => 'right',
      'group_pull_quote' => 'right',
      'field_pull_quote' => 'right',
      '_add_existing_field' => 'right',
      'field_quote_attribution' => 'right',
      'field_tags' => 'hidden',
      'field_professional_title' => 'right',
      'redirect' => 'hidden',
      'field_page_title' => 'left',
      'xmlsitemap' => 'hidden',
      'field_meta_description' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'field_deck',
        2 => 'custom_byline',
        3 => 'field_image',
      ),
      'left' => array(
        4 => 'field_highlights',
        5 => 'field_pull_quote',
        6 => 'field_quote_attribution',
        7 => 'field_professional_title',
      ),
      'right' => array(
        8 => 'body',
      ),
      'footer' => array(
        9 => 'author',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_deck' => 'header',
      'custom_byline' => 'header',
      'field_image' => 'header',
      'field_highlights' => 'left',
      'field_pull_quote' => 'left',
      'field_quote_attribution' => 'left',
      'field_professional_title' => 'left',
      'body' => 'right',
      'author' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|marquee';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'marquee';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_global_category',
        2 => 'field_deck',
        3 => 'read_more_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_global_category' => 'ds_content',
      'field_deck' => 'ds_content',
      'read_more_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|marquee'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'search_results';
  $ds_layout->settings = array(
    'regions' => array(
      'top' => array(
        0 => 'title',
      ),
      'middle' => array(
        1 => 'field_image',
        2 => 'read_more_url',
        3 => 'field_short_description',
      ),
      'bottom' => array(
        4 => 'author',
        5 => 'post_date',
      ),
    ),
    'fields' => array(
      'title' => 'top',
      'field_image' => 'middle',
      'read_more_url' => 'middle',
      'field_short_description' => 'middle',
      'author' => 'bottom',
      'post_date' => 'bottom',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'left_above' => 'div',
      'right_above' => 'div',
      'middle' => 'div',
      'left_below' => 'div',
      'right_below' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|search_results'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function livability_article_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'featured';
  $ds_view_mode->label = 'Featured';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['featured'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'marquee';
  $ds_view_mode->label = 'Marquee';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['marquee'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'related';
  $ds_view_mode->label = 'Related';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['related'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'tile';
  $ds_view_mode->label = 'Tile';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['tile'] = $ds_view_mode;

  return $export;
}
