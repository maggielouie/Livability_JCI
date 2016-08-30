<?php

function census_migrate_api() {
    $api = array(
        'api' => 2,
        'groups' => array(
            'Locations' => array('title' => t('Census Migrations'))
        ),
        'migrations' => array(
            'StateSync' => array(
                'class_name' => 'MigrateStateSync',
                'group_name' => 'Locations'
            ),
            'CountySync' => array(
                'class_name' => 'MigrateCountySync',
                'group_name' => 'Locations'
            ),
            'CitySync' => array(
                'class_name' => 'MigrateCitySync',
                'group_name' => 'Locations'
            ),
            'CityDemoSync' => array(
                'class_name' => 'MigrateCityDemoSync',
                'group_name' => 'Locations'
            ),
            'PreviousSync' => array(
                'class_name' => 'MigratePreviousSync',
                'group_name' => 'Locations'
            )
        )
    );
    return $api;
}