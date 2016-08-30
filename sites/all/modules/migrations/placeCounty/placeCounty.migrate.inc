<?php

function placeCounty_migrate_api(){
    $api = array(
        'api' => 2,
        'groups' => array(
            'Locations' => array('title' => t('Census Migrations'))
        ),
        'migrations' => array(
            'placeCounty' => array(
                'class_name' => 'MigratePlaceCounty',
                'group_name' => 'Locations'
            )
        )
    );
    return $api;
}