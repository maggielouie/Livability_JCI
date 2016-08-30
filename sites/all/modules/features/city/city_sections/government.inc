<?php

function liv_government(){

    $c = getCityContext();
    drupal_set_title($c->title.', '.$c->state->field_state_code['und'][0]['value'].
        ' Government');
    return 'Government';
}