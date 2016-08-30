<?php
function ds_content_cards(){
    $plugin = array(
      'label' => t('Content Card'),
      'category' => t('Columns: 2'),
      'icon' => 'twocol_bricks.png',
      //'theme' => 'panels_search_results',
      'css' => 'content_cards.css',
    'regions' => array(
        'top' => t('Image'),
        'category' => t('Category'),
        'title' => t('Title'),
        'summary' => t('summary'),
        'left_below' => t('Left below'),
        'right_below' => t('Right below'),
        'bottom' => t('Bottom'),
    ),
    );
    return $plugin;
}
/**
 * @file
 * Implementation for the two column bricked layout
 */

// Plugin definition

