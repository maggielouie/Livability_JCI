<?php

function liv_health(){
    global $title;
    switch(arg(3)){
        case 'healthy-lifestyle':
            $mainBody = citySectionInclude('health/healthy-lifestyle');
            break;
        case 'doctors':
            $mainBody = citySectionInclude('health/doctors');
            break;
        case 'hospitals':
            $mainBody = citySectionInclude('health/hospitals');
            break;
        default:
            $mainBody = citySectionInclude('health/index');
            break;
    }
    drupal_set_title($title);
    return $mainBody;
}