<?php

function airports_migrate_api() {
    $api = array(
        'api' => 2,
        'groups' => array(
            'airports' => array('title' => t('Airports'))
        ),
        'migrations' => array(
            'airports' => array(
                'class_name' => 'MigrateAirports',
                'group_name' => 'airports'
            )
        )
    );
    return $api;
}