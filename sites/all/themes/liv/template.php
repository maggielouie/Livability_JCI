<?php

/**
 * Here we override the default HTML output of drupal.
 * refer to http://drupal.org/node/550722
 */

// Auto-rebuild the theme registry during theme development.
if (theme_get_setting('clear_registry')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}

// Add Zen Tabs styles
if (theme_get_setting('liv_tabs')) {
  drupal_add_css( drupal_get_path('theme', 'basic') .'/css/tabs.css');
}

function liv_js_alter(&$javascript) {
  foreach ($javascript as $name => &$values) {
    $values['async'] = TRUE;
  }
}

function liv_preprocess_html(&$vars) {

  global $user;

  // Add role name classes (to allow css based show for admin/hidden from user)
  foreach ($user->roles as $role){
    $vars['classes_array'][] = 'role-' . liv_id_safe($role);
  }

  drupal_add_js('http://s7.addthis.com/js/300/addthis_widget.js#pubid=ra-4ed544966ca8922e', 'external');

  // HTML Attributes
  // Use a proper attributes array for the html attributes.
  global $language;
  $vars['html_attributes'] = array();
  $vars['html_attributes']['lang'][] = $language->language;
  $vars['html_attributes']['dir'][] = $language->dir;

  // Convert RDF Namespaces into structured data using drupal_attributes.
  $vars['rdf_namespaces'] = array();
  if (function_exists('rdf_get_namespaces')) {
    foreach (rdf_get_namespaces() as $prefix => $uri) {
      $prefixes[] = $prefix . ': ' . $uri;
    }
    $vars['rdf_namespaces']['prefix'] = implode(' ', $prefixes);
  }

  // Flatten the HTML attributes and RDF namespaces arrays.
  $vars['html_attributes'] = drupal_attributes($vars['html_attributes']);
  $vars['rdf_namespaces'] = drupal_attributes($vars['rdf_namespaces']);

  if (!$vars['is_front']) {
    // Add unique classes for each page and website section
    $path = drupal_get_path_alias($_GET['q']);
    list($section, ) = explode('/', $path, 2);
    $vars['classes_array'][] = 'with-subnav';
    $vars['classes_array'][] = liv_id_safe('page-'. $path);
    $vars['classes_array'][] = liv_id_safe('section-'. $section);

    if (arg(0) == 'node') {
      if (arg(1) == 'add') {
        if ($section == 'node') {
          // Remove 'section-node'
          array_pop( $vars['classes_array'] );
        }
        // Add 'section-node-add'
        $vars['classes_array'][] = 'section-node-add';
      }
      elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
        if ($section == 'node') {
          // Remove 'section-node'
          array_pop( $vars['classes_array']);
        }
        // Add 'section-node-edit' or 'section-node-delete'
        $vars['classes_array'][] = 'section-node-'. arg(2);
      }
    }
  }
  //for normal un-themed edit pages
  if ((arg(0) == 'node') && (arg(2) == 'edit')) {
    $vars['template_files'][] =  'page';
  }

  // Add IE classes.
  if (theme_get_setting('liv_ie_enabled')) {
    $liv_ie_enabled_versions = theme_get_setting('liv_ie_enabled_versions');
    if (in_array('ie8', $liv_ie_enabled_versions, TRUE)) {
      drupal_add_css(path_to_theme() . '/css/ie8.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 8', '!IE' => FALSE), 'preprocess' => FALSE));
      drupal_add_js(path_to_theme() . '/js/selectivizr-min.js');
    }
    if (in_array('ie9', $liv_ie_enabled_versions, TRUE)) {
      drupal_add_css(path_to_theme() . '/css/ie9.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 9', '!IE' => FALSE), 'preprocess' => FALSE));
    }
    if (in_array('ie10', $liv_ie_enabled_versions, TRUE)) {
      drupal_add_css(path_to_theme() . '/css/ie10.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 10', '!IE' => FALSE), 'preprocess' => FALSE));
    }
  }

  // favicon stuff
/*
  $favicons = '<link rel="apple-touch-icon" sizes="57x57" href="/icons/apple-touch-icon-57x57.png">'."\r";
  $favicons .= '<link rel="apple-touch-icon" sizes="114x114" href="/icons/apple-touch-icon-114x114.png">'."\r";
  $favicons .= '<link rel="apple-touch-icon" sizes="72x72" href="/icons/apple-touch-icon-72x72.png">'."\r";
  $favicons .= '<link rel="apple-touch-icon" sizes="144x144" href="/icons/apple-touch-icon-144x144.png">'."\r";
  $favicons .= '<link rel="apple-touch-icon" sizes="60x60" href="/icons/apple-touch-icon-60x60.png">'."\r";
  $favicons .= '<link rel="apple-touch-icon" sizes="120x120" href="/icons/apple-touch-icon-120x120.png">'."\r";
  $favicons .= '<link rel="apple-touch-icon" sizes="76x76" href="/icons/apple-touch-icon-76x76.png">'."\r";
  $favicons .= '<link rel="apple-touch-icon" sizes="152x152" href="/icons/apple-touch-icon-152x152.png">'."\r";
  $favicons .= '<link rel="icon" type="image/png" href="/icons/favicon-196x196.png" sizes="196x196">'."\r";
  $favicons .= '<link rel="icon" type="image/png" href="/icons/favicon-160x160.png" sizes="160x160">'."\r";
  $favicons .= '<link rel="icon" type="image/png" href="/icons/favicon-96x96.png" sizes="96x96">'."\r";
  $favicons .= '<link rel="icon" type="image/png" href="/icons/favicon-16x16.png" sizes="16x16">'."\r";
  $favicons .= '<link rel="icon" type="image/png" href="/icons/favicon-32x32.png" sizes="32x32">'."\r";
  $favicons .= '<meta name="msapplication-TileColor" content="#7ec346">'."\r";
  $favicons .= '<meta name="msapplication-TileImage" content="/icons/mstile-144x144.png">'."\r";
  $element = array(
    '#type' => 'markup',
    '#markup' => $favicons,
    );
  drupal_add_html_head($element, 'favicons');
*/
}

function liv_preprocess_page(&$vars, $hook) {

  if (isset($vars['node_title'])) {
    $vars['title'] = $vars['node_title'];
  }
  // Adding classes whether #navigation is here or not
  if (!empty($vars['main_menu']) or !empty($vars['sub_menu'])) {
    $vars['classes_array'][] = 'with-navigation';
  }
  if (!empty($vars['secondary_menu'])) {
    $vars['classes_array'][] = 'with-subnav';
  }

  // Add first/last classes to node listings about to be rendered.
  if (isset($vars['page']['content']['system_main']['nodes'])) {
    // All nids about to be loaded (without the #sorted attribute).
    $nids = element_children($vars['page']['content']['system_main']['nodes']);
    // Only add first/last classes if there is more than 1 node being rendered.
    if (count($nids) > 1) {
      $first_nid = reset($nids);
      $last_nid = end($nids);
      $first_node = $vars['page']['content']['system_main']['nodes'][$first_nid]['#node'];
      $first_node->classes_array = array('first');
      $last_node = $vars['page']['content']['system_main']['nodes'][$last_nid]['#node'];
      $last_node->classes_array = array('last');
    }
  }

  // Allow page override template suggestions based on node content type.
  if (isset($vars['node']->type)) {
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
    if (isset($vars['node']->nid)) {
      $vars['theme_hook_suggestions'][] = "page__node__" . $vars['node']->nid;
    }
  }
  if ($vars['theme_hook_suggestions'][0] == 'page__blog') {
    //$vars['page']['special_header'] = '<span class="blog-pin no-pin">'. l('<h1>Livability Blog</h1>', 'blog', array('html' => TRUE)).'</span>';
  }

  if (isset($vars['node'])) {
    if (preg_match('/404/', $vars['node']->title)) {
      $vars['theme_hook_suggestions'][] = 'page__404';
    }
  }
  /*
  // Adding some stuff for FB
  $fbadmins = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'fb:admins',
      'content' => "1375002090,58900562,1049698481,179200762,1322930595",
      ),
    );
  drupal_add_html_head($fbadmins, 'fb_admins');
  $fbadmins = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'fb:app_id',
      'content' => "266785933857",
      ),
    );
  drupal_add_html_head($fbadmins, 'fb_appid');
  */

  // Setting up $deck_copy variable for use on category topic pages, which are driven by
  // a taxonomy argument.
  $view = views_get_page_view();
  if ($view->name == 'topics' && $view->current_display == 'page' || $view->name == 'moving' && $view->current_display == 'page') {
    //we set the copy for the view landing page when no argument is present
    if ($view->name == 'topics') {
          $vars['deck_copy'] = "Our writers continually uncover interesting stories about what makes a city thrive, how people live and the latest place-making trends in the best places to live. These topics range from arts and entertainment to business, transportation and real estate. Take a look at the stories below or browse through our categories in the drop-down bar.";
    } else if ($view->name == 'moving') {
      $vars['deck_copy'] = "Whether you're moving, getting ready to move or just day dreaming about what it would be like to move to a new place you'll want to check out our moving section for tips, how to guides and checklists. You'll also find articles on the latest real estate trends, hot housing markets and best places to live.
";
    }
    $view_argument = $view->argument['name']->value[0];
    //if we have an argument, we go grab the taxonomy description
    if ($view_argument != NULL) {
      $terms = taxonomy_get_term_by_name($view_argument, 'category');
      $term = array_shift($terms);
      //this will return two terms, we want to grab the description off of the Global term
      if ($term->tid < 10) {
        $term = array_shift($terms);
      }
      $vars['deck_copy'] = $term->description;
    }

  }
}

function liv_preprocess_node(&$vars) {
  // Add a striping class.
  $vars['classes_array'][] = 'node-' . $vars['zebra'];

  // Add $unpublished variable.
  $vars['unpublished'] = (!$vars['status']) ? TRUE : FALSE;

  // Merge first/last class (from liv_preprocess_page) into classes array of current node object.
  $node = $vars['node'];
  if (!empty($node->classes_array)) {
    $vars['classes_array'] = array_merge($vars['classes_array'], $node->classes_array);
  }

  if (isset($vars['view_mode'])) {
    $vars['theme_hook_suggestions'][] = 'node__'.$vars['type'].'__'.$vars['view_mode'];
  }

// dpm($vars['theme_hook_suggestions']);
}

function liv_preprocess_block(&$vars, $hook) {
  // Add a striping class.
  $vars['classes_array'][] = 'block-' . $vars['block_zebra'];
  // Add widget class per Wouter's styling
  if ($vars['elements']['#block']->module == 'top100_partners_block') {
    $vars['classes_array'][] = 'widget';
    $vars['classes_array'][] = 'standard';
    $vars['classes_array'][] = 'stay-full';
    $vars['classes_array'][] = 'livability-partners';
  }
  if ($vars['elements']['#block']->module == 'popular_articles_block') {
    $vars['classes_array'][] = 'widget';
    $vars['classes_array'][] = 'standard';
    $vars['classes_array'][] = 'stay-full';
    $vars['classes_array'][] = 'related-articles';
  }
  if ($vars['elements']['#block']->module == 'popular_cities_block') {
    $vars['classes_array'][] = 'widget';
    $vars['classes_array'][] = 'stay-full';
    $vars['classes_array'][] = 'popular-cities';
  }

  // Add first/last block classes
  $first_last = "";
  // If block id (count) is 1, it's first in region.
  if ($vars['block_id'] == '1') {
    $first_last = "first";
    $vars['classes_array'][] = $first_last;
  }
  // Count amount of blocks about to be rendered in that region.
  $block_count = 0;
  if (isset($vars['elements']['#block']->region)) {
    $block_count = count(block_list($vars['elements']['#block']->region));
  }
  if ($vars['block_id'] == $block_count) {
    $first_last = "last";
    $vars['classes_array'][] = $first_last;
  }
  $menu_object = menu_get_object();
  if (isset($menu_object->type) && $vars['block']->module == 'system' && $vars['block']->delta == 'main') {
    // Create the $content variable that templates expect.
    $vars['theme_hook_suggestions'][] = 'block__content__main__'.$menu_object->type;
  }
  if (isset($menu_object->type) && $menu_object->type == 'article' && $vars['block']->delta == 'article_category_jumpmenu-block' && $vars['block']->region == 'sidebar_first') {
    $vars['theme_hook_suggestions'][] = 'block__sidebar_first__'.$menu_object->type;
  }
  if (arg(0) == 'best-places') {
    if (arg(1)) {
      switch (arg(1)) {
        case 'top-10':
        $vars['theme_hook_suggestions'][] = 'block__content__'.$vars['elements']['#block']->region.'__best_places';
        break;
        case 'top-100':
        $vars['theme_hook_suggestions'][] = 'block__content__'.$vars['elements']['#block']->region.'__top_100';
        break;
      }
    }
  }
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return
 *   A string containing the breadcrumb output.
 */
function liv_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  // Determine if we are to display the breadcrumb.
  $show_breadcrumb = theme_get_setting('liv_breadcrumb');
  if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {
    if(arg(0) == 'node' && is_numeric(arg(1))) {
      $node = node_load(arg(1));
      if (is_object($node)) {
        $heading = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
        if ($node->type == 'article') {
          $item = menu_get_item();
          if (!empty($item['tab_parent'])) {
            // If we are on a non-default tab, use the tab's title.
            $title = check_plain($item['title']);
          }
          else {
            $title = drupal_get_title();
          }

          // Provide a navigational heading to give context for breadcrumb links to
          // screen-reader users. Make the heading invisible with .element-invisible.
        }
        if ($node->type == 'special_section' || $node->type == 'special_section_article') {
          $state_node = node_load($node->field_state['und'][0]['target_id']);
          if (is_object($state_node)) {
            $breadcrumb[1] = l($state_node->title, 'node/' . $state_node->nid);
          }
        }
        if ($node->type == 'special_section_article') {
          $state_node = node_load($node->field_state['und'][0]['target_id']);
          if (is_object($state_node)) {
            if (module_exists('special_section')) {
              $parent_nid = _special_section_parent_node($node->nid);
              if ($parent_nid) {
                $parent_node = node_load($parent_nid);
                $breadcrumb[2] = l($parent_node->title, 'node/' . $parent_node->nid);
              }
            }
          }
        }
        if ($node->type == 'best_places' || $node->type == 'top_100') {
          $skiptitle = TRUE;
          $output = '<ul class="breadcrumbs padded clearfix no-mobile">';
        }
        else {
          $output = '<ul class="breadcrumbs clearfix no-mobile">';
        }
        foreach ($breadcrumb as $crumb) {
          $output .= '<li>'.$crumb.'</li>';
        }
        if (!isset($skiptitle)) {
          if ($node->type == 'gallery') {
            $output .= '<li><span>Gallery</span></li>';
          }
          elseif ($node->type == 'digital_magazine') {
            $output .= '<li><span>Digital Magazine</span></li>';
          }
          elseif ($node->type == 'metro_area') {
            $output .= '<li><span>' .$node->field_metro_shortname[LANGUAGE_NONE][0]['value'] .'</span></li>';
          }
          else {
            $output .= '<li><span>'.$node->title.'</span></li>';
          }
        }
        $output .= '</ul>';
        return $heading . $output;
      }
    }
    else {

      // Return the breadcrumb with separators.
      if (!empty($breadcrumb)) {
        $breadcrumb_separator = theme_get_setting('liv_breadcrumb_separator');
        $trailing_separator = $title = '';
        if (theme_get_setting('liv_breadcrumb_title')) {
          $item = menu_get_item();
          if (!empty($item['tab_parent'])) {
            // If we are on a non-default tab, use the tab's title.
            $title = check_plain($item['title']);
          }
          else {
            $title = drupal_get_title();
          }
        } else {
          $item = menu_get_item();
          if ($item['path'] == 'metro') {
            $metro_title = 'Metro';
          }
        }

        // Provide a navigational heading to give context for breadcrumb links to
        // screen-reader users. Make the heading invisible with .element-invisible.
        $heading = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
        if (isset($item['page_arguments'][0]->type) && $item['page_arguments'][0]->type == 'best_places' || (arg(1) == 'top-10'  && null !== arg(2)) || arg(1) == 'top-100') {
          $skiptitle = TRUE;
          $output = '<ul class="breadcrumbs padded clearfix no-mobile">';
        }
        else {
          $output = '<ul class="breadcrumbs clearfix no-mobile">';
        }
        foreach ($breadcrumb as $crumb) {
          $output .= '<li>'.$crumb.'</li>';
        }
        if (!isset($skiptitle)) {
          if (isset($metro_title)) {
            $output .='<li><span>' . $metro_title . '</span></li>';
          } else {
          $output .= '<li><span>'.ucwords(drupal_get_title()).'</span></li>';
        }
      }
        $output .= '</ul>';
        return $heading . $output;
    //  return $heading . implode($breadcrumb_separator, $breadcrumb) . $trailing_separator . $title;
      }
    // Otherwise, return an empty string.
      return '';
    }
  }
}

/**
 * Converts a string to a suitable html ID attribute.
 *
 * http://www.w3.org/TR/html4/struct/global.html#h-7.5.2 specifies what makes a
 * valid ID attribute in HTML. This function:
 *
 * - Ensure an ID starts with an alpha character by optionally adding an 'n'.
 * - Replaces any character except A-Z, numbers, and underscores with dashes.
 * - Converts entire string to lowercase.
 *
 * @param $string
 *  The string
 * @return
 *  The converted string
 */
function liv_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9_-]+/', '-', $string));
  // If the first character is not a-z, add 'n' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
  $string = 'id'. $string;
}
return $string;
}

/**
 * Generate the HTML output for a menu link and submenu.
 *
 * @param $variables
 *  An associative array containing:
 *   - element: Structured array data for a menu link.
 *
 * @return
 *  A themed HTML string.
 *
 * @ingroup themeable
 *
 */
function liv_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  if ($element['#below']) {
    foreach ($element['#below'] as $i => $details) {
      if (is_numeric($i)) {
        $element['#below'][$i]['#attributes']['class'][] = 'level-1';
      }
    }
    $sub_menu = drupal_render($element['#below']);
  }
  if($sub_menu != null && $element['#original_link']['menu_name'] == 'main-menu'){
    $element['#title'] .= '<i class="icon-arrow-down white no-mobile"></i>'.
    '<i class="icon-arrow-right white mobile-only"></i>';
    $element['#localized_options']['html'] = true;
    $sub_menu = preg_replace('/\smenu-mlid-[\d]*/', '', $sub_menu);
    $sub_menu = preg_replace('/^<ul class="menu"><li class="first last leaf level-[\d]* menu-views">/', '', $sub_menu);
    $sub_menu = preg_replace('/<\/li>$/', '', $sub_menu);
    $sub_menu = preg_replace('/<\/ul>$/', '', $sub_menu);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  if ($element['#original_link']['menu_name'] !== 'main-menu') {
    // Adding a class depending on the TITLE of the link (not constant)
    $element['#attributes']['class'][] = liv_id_safe($element['#title']);
    // Adding a class depending on the ID of the link (constant)
    if (isset($element['#original_link']['mlid']) && !empty($element['#original_link']['mlid'])) {
      $element['#attributes']['class'][] = 'mid-' . $element['#original_link']['mlid'];
    }
  }
  else { unset($element['#attributes']['class']); }
  $return = '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
  return $return;
}

/**
 * Override or insert variables into theme_menu_local_task().
 */
function liv_preprocess_menu_local_task(&$variables) {
  $link =& $variables['element']['#link'];

  // If the link does not contain HTML already, check_plain() it now.
  // After we set 'html'=TRUE the link will not be sanitized by l().
  if (empty($link['localized_options']['html'])) {
    $link['title'] = check_plain($link['title']);
  }
  $link['localized_options']['html'] = TRUE;
  $link['title'] = '<span class="tab">' . $link['title'] . '</span>';
}

/**
 * Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 */
function liv_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs primary clearfix">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}

/**
 * Region
 */
function liv_preprocess_region(&$variables) {
  $variables['theme_hook_suggestions'][] = 'region__'.$variables['region'];
  $menu_object = menu_get_object();
  if (isset($menu_object->type) ) {
    // Create the $content variable that templates expect.
    $variables['theme_hook_suggestions'][] = 'region__'.$variables['region'].'__'.$menu_object->type;
    $variables['attributes_array']['class'] = array();
  }
  if (arg(0) == 'best-places' && arg(1) == 'top-100') {
    $variables['theme_hook_suggestions'][] = 'region__'.$variables['region'].'__top_100';
  }
}

function liv_pager($variables) {
  /* see includes/pager.inc, line 320 for original */
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  $pager_middle = ceil($quantity / 2);
  $pager_current = $pager_page_array[$element] + 1;
  $pager_first = $pager_current - $pager_middle + 1;
  $pager_last = $pager_current + $quantity - $pager_middle;
  $pager_max = $pager_total[$element];

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.
  if (isset($tags[0]) && !empty($tags[0])) {
    $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  }
  else {
    $li_first = FALSE;
  }
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  if (isset($tags[0]) && !empty($tags[0])) {
    $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));
  }
  else {
    $li_last = FALSE;
  }
  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
        );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
        );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
          );
      }
      // Now generate the actual pager piece.
      $node = menu_get_object();
      $top100 = FALSE;
      if (isset($node->type) && $node->type == 'top_100' || $node->type == 'top_cities_list') {
        $top100 = TRUE;
      }
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($top100) {
          $text = (($i*10) - 9) .'-'.($i*10);
        }
        else {
          $text = $i;
        }
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $text, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
            );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current', 'active'),
            'data' => "<a>$text</a>", //theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),// $i,
            );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $text, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
            );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
          );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
        );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
        );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager', 'pagination')),
      ));
  }
}

function liv_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'views_exposed_form') {
    $form['submit']['#attributes']['class'][] = 'button-green';
    $form['submit']['#attributes']['style'] = "display:inline;float:left;margin-top:5px;";
    $form['search_api_views_fulltext']['#attributes']['style'] = "display:inline;float:left;";
        //drupal_set_message(print_r($form['search_api_views_fulltext'],true));
  }
  if (preg_match('/webform_client_form_/', $form_id) == 1) {
    $form['actions']['submit']['#attributes']['class'][] = 'button-blue';
  }
}

function liv_preprocess_search_result(&$variables) {
  global $language;

  $result = $variables['result'];

  $path = '<span class="path">'.l($result['link'], $result['link']).'</span><br/>';
  switch ($result['type']) {
    case 'Article':
    if (isset($result['node']->field_place['und'][0])) {
      foreach($result['node']->field_place['und'] as $p => $place) {
        $place_entity = entity_load('field_collection_item',array($place['value']));
        if (isset($place_entity[$result['node']->field_place['und'][$p]['value']]->field_primary_host['und'][0]['value']) && $place_entity[$result['node']->field_place['und'][$p]['value']]->field_primary_host['und'][0]['value'] == 1) {
          $primaryplaceid = $place_entity[$result['node']->field_place['und'][$p]['value']]->field_place_ref['und'][0]['target_id'];
          $primeplace = node_load($primaryplaceid);
          $citystate = node_load($primeplace->field_state['und'][0]['target_id']);
          $state = $citystate->field_state_code['und'][0]['value'];
          $variables['location'] = $primeplace->title .', '.$state;
        }
      }
    }
    $img = '';
    if (isset($result['node']->field_image['und'])) {
      $img = '<img src="'.image_style_url('thumbnail', $result['node']->field_image['und'][0]['uri']) .'" />';
    }
    if (isset($result['node']->field_short_description['und'][0])) {
      $result['snippet'] = $img.$path.$result['node']->field_short_description['und'][0]['value'];
    }
    else {
      $result['snippet'] = $img.$path.substr(strip_tags($result['node']->body['und'][0]['value']), 0, 200);
    }
    break;
    case 'Blog Post':
    $img = '';
    if (isset($result['node']->field_image['und'])) {
      $img = '<img src="'.image_style_url('thumbnail', $result['node']->field_image['und'][0]['uri']) .'" />';
    }
    $result['snippet'] = $img.$path.substr(strip_tags($result['node']->body['und'][0]['value']), 0, 200);
    break;
    case 'Best Places':
    $img = '';
    if (isset($result['node']->field_image['und'])) {
      $img = '<img src="'.image_style_url('thumbnail', $result['node']->field_image['und'][0]['uri']) .'" />';
    }
    if (isset($result['node']->field_short_description['und'])) {
      $result['snippet'] = $img.$path.$result['node']->field_short_description['und'][0]['value'];
    }
    else {
      $result['snippet'] = $img.$path.substr(strip_tags($result['node']->body['und'][0]['value']), 0, 200);
    }
    break;
    case 'Gallery':
    $img = '';
    if (isset($result['node']->field_image['und'])) {
      $img = '<img src="'.image_style_url('thumbnail', $result['node']->field_image['und'][0]['uri']) .'" />';
    }
    $result['snippet'] = $img;
    break;
    case 'Top 100':
    if (isset($result['node']->field_deck['und'])) {
      $result['snippet'] = $path.$result['node']->field_deck['und'][0]['value'];
    }
    else {
      $result['snippet'] = $path.substr(strip_tags($result['node']->body['und'][0]['value']), 0, 200);
    }
    break;
    case 'City':
    $result['snippet'] = $path.getCityMeta($result['node']->nid);
    break;
    case 'Area':
    case 'County':
    case 'State':
    $result['snippet'] = $path.$result['snippet'];
    break;

  }

  $info = array();
  if (!empty($result['module'])) {
    $info['module'] = check_plain($result['module']);
  }
  if (!empty($result['user']) && ($result['node']->uid == 0 || $result['node']->uid == 1)) {
   if (isset($result['node']->field_byline['und'])) {
     $info['user'] = $result['node']->field_byline['und'][0]['value'];
   }
 }
 else {
  $info['user'] = $result['user'];
}
if (!empty($result['date'])) {
  $info['date'] = format_date($result['date'], 'custom', 'M d, Y');
}
if (isset($result['extra']) && is_array($result['extra'])) {
  $info = array_merge($info, $result['extra']);
}
  // Check for existence. User search does not include snippets.
$variables['snippet'] = isset($result['snippet']) ? $result['snippet'] : '';
  // Provide separated and grouped meta information..
$variables['info_split'] = $info;
$variables['info'] = implode(' &bull; ', $info);
}


function liv_media_wysiwyg_token_to_markup_alter(&$element, $tag_info, $settings){
  foreach($settings['fields'] as $field_name => $field) {
    if (empty($field[LANGUAGE_NONE][0]['value'])) {
      $element['content'][$field_name]['#label_display'] = 'hidden';
    }
  }
}

function liv_field_attach_view_alter(&$output, $context) {
  foreach ($output as $field_name => $field) {
    if (!empty($field['#label_display'])) {
      if(isset($field[0]['#markup']) && empty($field[0]['#markup']) && ($field[0]['#markup'] !== 0)) {
        $output[$field_name]['#label_display'] = 'hidden';
      }
    }
  }
}


function liv_preprocess_webform_confirmation(&$vars) {
  $confirmation = check_markup($vars['node']->webform['confirmation'], $vars['node']->webform['confirmation_format'], '', TRUE);

  // Replace tokens.
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $submission = webform_get_submission($vars['node']->nid, $vars['sid']);
  $confirmation = webform_replace_tokens($confirmation, $vars['node'], $submission, NULL, TRUE);
  if (isset($submission->data[1])) {
    $confirmation .= '<p>You should receive an email confirming your subscription shortly.</p>';
  }

  // Strip out empty tags added by WYSIWYG editors if needed.
  $vars['confirmation_message'] = strlen(trim(strip_tags($confirmation))) ? $confirmation : '';

  // Progress bar.
  $vars['progressbar'] = '';
  $page_labels = webform_page_labels($vars['node']);
  $page_count = count($page_labels);
  if ($vars['node']->webform['progressbar_include_confirmation'] && $page_count > 2) {
    $vars['progressbar'] = theme('webform_progressbar', array(
      'node' => $vars['node'],
      'page_num' => $page_count,
      'page_count' => $page_count,
      'page_labels' => $page_labels,
      ));
  }
}

function liv_tablesort_indicator($variables) {
    $theme_path = path_to_theme();
    if ($variables ['style'] == "asc") {
        $sort_arrow = theme('image', array(
            'path' => $theme_path . '/livability/images/icons/sort-asc.png',
            //'width' => 13, 'height' => 13,
            'alt' => t('sort ascending'),
            'title' => t('sort ascending'),
            'attributes' => array('class' => 'sort-image')));
    }
    else {
        $sort_arrow = theme('image', array(
            'path' => $theme_path . '/livability/images/icons/sort-desc.png',
            //'width' => 13, 'height' => 13,
            'alt' => t('sort descending'),
            'title' => t('sort descending'),
            'attributes' => array('class' => 'sort-image')));
    }
    $sort_markup = '<div class=table-arrow>' . $sort_arrow . '</div>';
    return $sort_markup;
}

function liv_field__expert__author($variables) {
  $name = $variables['items'][0]['#markup'];
  if ($variables['element']['#object']->uid != 0) {
    $name = l($variables['items'][0]['#markup'], 'user/' . $variables['element']['#object']->uid);
  }
  return '<span class="author-name">' . $name . '</span>';

}

function liv_render_field($fieldname,$node, $bundle) {
  $r = field_view_field($bundle, $node, $fieldname);
  return render($r); 
}


