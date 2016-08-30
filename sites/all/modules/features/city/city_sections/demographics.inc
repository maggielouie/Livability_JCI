<?php

function liv_demographics(){
    global $title;
    switch(arg(3)){
        case 'population':
            $mainBody = citySectionInclude('demographics/population');
            break;
        case 'cost-of-living':
            $mainBody = citySectionInclude('demographics/cost-of-living');
            break;
        case 'income-levels':
            $mainBody = citySectionInclude('demographics/income-levels');
            break;
        default:
            $mainBody = citySectionInclude('demographics/index');
            break;
    }
    drupal_set_title($title);
    return $mainBody;
}