<?php

function liv_weather(){
    global $title;
    switch(arg(3)){
        case 'average-temperatures':
            $mainBody = citySectionInclude('weather/index');
            break;
        default:
            $mainBody = citySectionInclude('weather/index');
            break;
    }
    drupal_set_title($title);
    return $mainBody;
}