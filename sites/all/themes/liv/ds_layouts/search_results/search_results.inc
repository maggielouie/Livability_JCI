<?php
function ds_search_results(){
    $plugin = array(
      'label' => t('Search Results Layout'),
      'category' => t('Columns: 2'),
      'icon' => 'twocol_bricks.png',
      //'theme' => 'panels_search_results',
      'css' => 'search_results.css',
      'regions' => array(
        'top' => t('Top'),
        'left_above' => t('Left above'),
        'right_above' => t('Right above'),
        'middle' => t('Middle'),
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

