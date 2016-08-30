<?php

class BestPlacesMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('type', 'top_ten')
            ->condition('status', '1')
            ->where('tta.delta = 0')
            ->orderBy('nid')
            ->orderBy('ua.pid');
        $query->leftJoin('field_data_field_pull_up_text', 'put', 'put.entity_id = n.nid');
        $query->leftJoin('field_data_field_page_title', 'pt', 'pt.entity_id = n.nid');
        $query->leftJoin('field_data_field_top10_metadescription', 'md', 'md.entity_id = n.nid');
        $query->leftJoin('field_data_field_top_ten_article', 'tta', 'tta.entity_id = n.nid');
        $query->leftJoin('field_data_field_article', 'fa', 'fa.entity_id = tta.field_top_ten_article_nid');
        $query->leftJoin('field_data_field_teaser', 'ft', 'ft.entity_id = tta.field_top_ten_article_nid');
        $query->leftJoin('field_data_field_photos', 'fp', 'fp.entity_id = tta.field_top_ten_article_nid');
        $query->leftJoin('field_data_field_description', 'fd', 'fd.entity_id = fp.field_photos_nid');
        $query->leftJoin('url_alias', 'ua', 'ua.source like concat(\'node/\', CAST(n.nid AS CHAR))');
        $query->fields('n', array('nid', 'vid', 'title', 'created', 'changed', 'promote', 'sticky', 'status', 'uuid'));
        $query->fields('put', array('field_pull_up_text_value'));
        $query->fields('pt', array('field_page_title_value'));
        $query->fields('md', array('field_top10_metadescription_value'));
        $query->fields('ft', array('field_teaser_value'));
        $query->fields('fa', array('field_article_value'));
        $query->fields('fp', array('field_photos_nid'));
        $query->fields('fd', array('field_description_value'));
        $query->fields('ua', array('alias'));
        $query->distinct();

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));
        $this->destination = new MigrateDestinationNode('best_places');

        $this->map = new MigrateSQLMap($this->machineName,
          array('nid' => array( 'type' => 'int',
                                'unsigned' => TRUE,
                                'not null' => TRUE,
                                'description' => 'Source node ID',
                                'alias' => 'n', ),),
          MigrateDestinationNode::getKeySchema(),
          'default'
        );

        $this->addFieldMapping('title', 'title');
        $this->addFieldMapping('created', 'created');
        $this->addFieldMapping('changed', 'changed');
        $this->addFieldMapping('promote', 'promote');
        $this->addFieldMapping('sticky', 'sticky');
        $this->addFieldMapping('status', 'status');
        $this->addFieldMapping('field_year', 'uuid');
        $this->addFieldMapping('field_short_description', 'field_teaser_value');
        $this->addFieldMapping('field_ranking_criteria', 'field_pull_up_text_value');
        $this->addFieldMapping('field_bp_category', 'vid')
          ->sourceMigration('BestPlacesTerms');
        $this->addFieldMapping('field_bp_category:source_type')
          ->defaultValue('tid');
        $this->addFieldMapping('field_teaser_value');
        $this->addFieldMapping('body', 'field_article_value');
        $this->addFieldMapping('body:format')->defaultValue('filtered_html');
        $this->addFieldMapping('field_image', 'field_photos_nid')
          ->sourceMigration('BestPlacesImages');
        $this->addFieldMapping('field_image:file_class')
          ->defaultValue('MigrateFileFid');
        $this->addFieldMapping('field_image:alt', 'field_description_value'); // 512 char limit.
        $this->addFieldMapping('field_image:title', 'field_description_value');
        $this->addFieldMapping('field_page_title', 'field_page_title_value');
        $this->addFieldMapping('field_meta_description', 'field_top10_metadescription_value');
        $this->addFieldMapping('path', 'alias');
    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
      $row->vid = $row->nid;
      $year = date('Y',$row->created);
      // really we want the current year, this is to address the Timezone difference.
      $year--;
      //$row->uuid = $year.'-12-31 18:00:00';
      $row->uuid = $year.'-01-01 00:00:00';
    }
    
    function prepare($node, $row) {
      if ($row->field_pull_up_text_value) {
        // the existing "Ranking Criteria" is one field, with terrible formatting (indenting, etc.).
        $criteria = str_replace('<ul>', '', $row->field_pull_up_text_value);
        $criteria = str_replace('</ul>', '', $criteria);
        $criteria = str_replace('<li>', '', $criteria);
        $criteria = str_replace("\t", '', $criteria);
        $criteria = str_replace("\r", '', $criteria);
        $criteria = str_replace("\n", '', $criteria);
        $criteria = str_replace("\s\s", '', $criteria);
        $criteria = str_replace("\s\s", '', $criteria);
        $criteria = trim($criteria);
        $criteria = explode('</li>', $criteria);
        foreach ($criteria as $i => $criterion) {
          if ($criterion != '') {
            $node->field_ranking_criteria['und'][$i]['value'] = $criterion;
          }
        }
      }
    } 
}

