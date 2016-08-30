<?php

function medicare_migrate_api() {
    $api = array(
        'api' => 2,
        'groups' => array(
            'Hospitals' => array('title' => t('Hospitals'))
        ),
        'migrations' => array(
            'HospitalSync' => array(
                'class_name' => 'MigrateHospitalSync',
                'group_name' => 'Hospitals'
            )
        )
    );
    return $api;
}