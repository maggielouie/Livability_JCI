<?php

/**
 * Implements hook_migrate_api().
 */
function metro_area_migrate_api() {
	$api = array(
		'api' => 2,
		'groups' => array(
			'metroAreas' => array(
				'title' => t('Metro Area migrations'),
				),
			),
		'migrations' => array(
			'metroAreaCSV' => array(
				'class_name' => 'MetroAreaMigration',
				'group_name' => 'metroAreas',
			),
			'metroCountyCSV' => array(
				'class_name' => 'MetroCountyMigration',
				'group_name' => 'metroAreas',
			),
		),
	);
	return $api;
}
