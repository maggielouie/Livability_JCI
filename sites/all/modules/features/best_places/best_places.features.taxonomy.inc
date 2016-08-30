<?php
/**
 * @file
 * best_places.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function best_places_taxonomy_default_vocabularies() {
  return array(
    'best_places' => array(
      'name' => 'Best Places',
      'machine_name' => 'best_places',
      'description' => 'Categories for Best Places lists',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
