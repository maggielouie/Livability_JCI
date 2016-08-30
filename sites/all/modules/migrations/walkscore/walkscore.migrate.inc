<?php

function walkscore_migrate_api() {
    $api = array(
        'api' => 2,
        'groups' => array(
            'WalkScore' => array('title' => t('Walk Score'))
        ),
        'migrations' => array(
            'WalkScoreCity' => array(
                'class_name' => 'MigrateWalkscoreSync',
                'group_name' => 'WalkScore'
            )
        )
    );
    return $api;
}
