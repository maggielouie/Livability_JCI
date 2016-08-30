<?php

class ArticleCatMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('type', 'article')
            ->condition('status', '1')
            ->isNotNull('tax.taxonomy_vocabulary_1_tid')
//            ->condition('nid', array(52442,68620,72023), 'IN')
            ->isNull('tta.entity_id')
            ->isNull('cpa.entity_id')
            ->orderBy('nid');
        $query->leftJoin('field_data_taxonomy_vocabulary_1','tax','tax.entity_id = n.nid');
        $query->leftJoin('field_data_field_top_ten_article','tta','tta.field_top_ten_article_nid = n.nid');
        $query->leftJoin('field_data_field_city_profile_articles','cpa','cpa.field_city_profile_articles_nid = n.nid');
        $query->fields('n', array('nid'));
        $query->fields('tax', array('taxonomy_vocabulary_1_tid', 'entity_id')); 
//        $query->range(0,20);

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));

        $this->map = new MigrateSQLMap($this->machineName,
          array('nid' => array( 'type' => 'int',
                                'unsigned' => TRUE,
                                'not null' => TRUE,
                                'description' => 'Source node ID',
                                'alias' => 'n', ),),
          MigrateDestinationFieldCollection::getKeySchema()
        );
        $this->destination = new MigrateDestinationFieldCollection(
           'field_category',
           array('host_entity_type' => 'node')
        );
        $this->addFieldMapping('host_entity_id', 'nid')
          ->sourceMigration('Articles');
        $this->addFieldMapping('field_category_ref', 'taxonomy_vocabulary_1_tid')
          ->sourceMigration('LivTerms');
        $this->addFieldMapping('field_category_ref:source_type')
          ->defaultValue('tid');
        $this->addFieldMapping('field_primary_category', 'entity_id');
    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
      if (is_null($row->taxonomy_vocabulary_1_tid)) {
        return FALSE;
      }
      
      if ($row->taxonomy_vocabulary_1_tid == 171) {
        $row->taxonomy_vocabulary_1_tid = 3;
      }
      if ($row->taxonomy_vocabulary_1_tid == 172) {
        $row->taxonomy_vocabulary_1_tid = 10;
      }
      if ($row->taxonomy_vocabulary_1_tid == 173) {
        $row->taxonomy_vocabulary_1_tid = 64;
      }
      $row->entity_id = 1;
//      echo $row->nid .": " . $row->taxonomy_vocabulary_1_tid ."\n";

    }
    
    function prepare($node, $row) {


    }

}
