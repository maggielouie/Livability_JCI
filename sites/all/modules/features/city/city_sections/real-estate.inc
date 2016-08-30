<?php
function liv_real_estate(){
    global $title;
    switch(arg(3)){
        case 'housing':
            $mainBody = citySectionInclude('real-estate/housing');
            break;
        case 'home-values':
            $mainBody = citySectionInclude('real-estate/home-values');
            break;
        default:
            $mainBody = citySectionInclude('real-estate/index');
            break;
    }

    drupal_set_title($title);
    return ($mainBody);
}