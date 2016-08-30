<?php

function greatschools_migrate_api(){
    $api = array(
        'api' => 2,
        'groups' => array(
            'greatschools' => array('title' => t('Great Schools/ Migrations'))
        ),
        'migrations' => array(
            'gsSchools' => array(
                'class_name' => 'MigrateSchools',
                'group_name' => 'greatschools'
            ),
            'gsDistricts' => array(
                'class_name' => 'MigrateDistricts',
                'group_name' => 'greatschools'
            )
        )
    );
    return $api;
}