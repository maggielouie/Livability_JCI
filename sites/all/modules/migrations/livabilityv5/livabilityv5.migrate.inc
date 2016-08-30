<?php 

function livabilityv5_migrate_api() {
    $api = array(
        'api' => 2,
        'groups' => array(
            'Content' => array('title' => t('V5 Content Migrations'))
        ),
        'migrations' => array(
            'Areas' => array(
                'class_name' => 'AreaMigration',
                'group_name' => 'Content'
            ),
            'LivTerms' => array(
                'class_name' => 'LivTermMigration',
                'group_name' => 'Content'
            ),
            'Writers' => array(
                'class_name' => 'WriterMigration',
                'group_name' => 'Content'
            ),
            'WriterImages' => array(
                'class_name' => 'WriterImageMigration',
                'group_name' => 'Content'
            ),
            'Articles' => array(
                'class_name' => 'ArticleMigration',
                'group_name' => 'Content'
            ),
            'ArticleImages' => array(
                'class_name' => 'ArticleImageMigration',
                'group_name' => 'Content'
            ),
            'ArticleCategories' => array(
                'class_name' => 'ArticleCatMigration',
                'group_name' => 'Content'
            ),
            'ArticleCities' => array(
                'class_name' => 'ArticleCitiesMigration',
                'group_name' => 'Content'
            ),
            'BestPlacesTerms' => array(
                'class_name' => 'BestPlacesTermMigration',
                'group_name' => 'Content'
            ),
            'BestPlacesImages' => array(
                'class_name' => 'BestPlacesImageMigration',
                'group_name' => 'Content'
            ),
            'BestPlaces' => array(
                'class_name' => 'BestPlacesMigration',
                'group_name' => 'Content'
            ),
            'BestPlacesItems' => array(
                'class_name' => 'BestPlacesItemMigration',
                'group_name' => 'Content'
            ),
            'Top100' => array(
                'class_name' => 'Top100Migration',
                'group_name' => 'Content'
            ),
            'DigitalMagazine' => array(
                'class_name' => 'DigitalMagazineMigration',
                'group_name' => 'Content'
            ),
        )
    );
    return $api;
}


