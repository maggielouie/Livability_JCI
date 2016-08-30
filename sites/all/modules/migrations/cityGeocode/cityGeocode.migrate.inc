<?php

function cityGeocode_migrate_api(){
    $api = array(
        'api' => 2,
        'groups' => array(
            'Locations' => array('title' => t('Census Migrations'))
        ),
        'migrations' => array(
            'cityGeocode' => array(
                'class_name' => 'MigrateCityGeocode',
                'group_name' => 'Locations'
            ),
            'cityCounty' => array(
                'class_name' => 'MigrateCityCounty',
                'group_name' => 'Locations'
            )
        )
    );
    return $api;
}