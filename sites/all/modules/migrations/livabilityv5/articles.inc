<?php

class ArticleMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('type', 'article')
            ->condition('status', '1')
            ->isNotNull('tax.taxonomy_vocabulary_1_tid')
            ->isNull('tta.entity_id')
            ->isNull('cpa.entity_id')
            ->orderBy('nid');
        $query->leftJoin('field_data_field_byline','byl','byl.entity_id = n.nid');
        $query->leftJoin('field_data_field_article','fa','fa.entity_id = n.nid');
        $query->leftJoin('field_data_field_photos','fp','fp.entity_id = n.nid');
        $query->leftJoin('field_data_field_photo_display_title','fpdt','fpdt.entity_id=n.nid');
        $query->leftJoin('field_data_field_description','fd','fd.entity_id = fp.field_photos_nid');
        $query->leftJoin('field_data_field_metadescription','fmd','fmd.entity_id = n.nid');
        $query->leftJoin('field_data_field_sub_title','fst','fst.entity_id = n.nid');
        $query->leftJoin('field_data_field_teaser','ft','ft.entity_id = n.nid');
        $query->leftJoin('field_data_field_page_title', 'pt','pt.entity_id = n.nid');
        $query->leftJoin('field_data_taxonomy_vocabulary_1','tax','tax.entity_id = n.nid');
        $query->leftJoin('field_data_field_writer_reference','wr','wr.entity_id = n.nid');
        $query->leftJoin('url_alias', 'ua', 'ua.source like concat(\'node/\', CAST(n.nid AS CHAR))');
        $query->leftJoin('field_data_field_top_ten_article','tta','tta.field_top_ten_article_nid = n.nid');
        $query->leftJoin('field_data_field_city_profile_articles','cpa','cpa.field_city_profile_articles_nid = n.nid');
        $query->fields('n', array('nid', 'title', 'created', 'changed', 'promote', 'sticky', 'status'));
        $query->fields('byl', array('field_byline_value'));
        $query->fields('fa', array('field_article_value','field_article_format'));
        $query->fields('fd', array('field_description_value'));
        $query->fields('fp', array('field_photos_nid'));
        $query->fields('fmd', array('field_metadescription_value'));
        $query->fields('fst', array('field_sub_title_value','field_sub_title_format'));
        $query->fields('ft', array('field_teaser_value','field_teaser_format'));
        $query->fields('pt', array('field_page_title_value'));
        $query->fields('tax', array('taxonomy_vocabulary_1_tid'));
        $query->fields('wr', array('field_writer_reference_nid'));
        $query->fields('ua', array('alias'));
//        $query->range(0,20);

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));
        $this->destination = new MigrateDestinationNode('article');

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
        $this->addFieldMapping('uid', 'field_writer_reference_nid')
          ->sourceMigration('Writers')
          ->defaultValue(1);
        $this->addFieldMapping('body', 'field_article_value');
        $this->addFieldMapping('body:format')->defaultValue('filtered_html');
        $this->addFieldMapping('field_deck', 'field_sub_title_value');
        $this->addFieldMapping('field_deck:format')->defaultValue('filtered_html');
        $this->addFieldMapping('field_image', 'field_photos_nid')
          ->sourceMigration('ArticleImages');
        $this->addFieldMapping('field_image:file_class')
          ->defaultValue('MigrateFileFid');
        $this->addFieldMapping('field_image:title','field_photo_display_title_value')->defaultValue('n/a');
        $this->addFieldMapping('field_image:alt','field_photo_display_title_value')->defaultValue('n/a');
        $this->addFieldMapping('field_image:language')->defaultValue(LANGUAGE_NONE);

        $this->addFieldMapping('field_byline', 'field_byline_value');
        $this->addFieldMapping('field_author', 'field_writer_reference_nid')
          ->sourceMigration('Writers');
        $this->addFieldMapping('field_short_description', 'field_teaser_value');
        $this->addFieldMapping('field_page_title', 'field_page_title_value');
        $this->addFieldMapping('field_meta_description', 'field_metadescription_value');
        $this->addFieldMapping('path', 'alias');

    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
      if (strlen($row->field_description_value) > 512) {
        // echo "ALT TOO BIG: " . $row->nid ."\r\n"; // Alt: ". $row->field_description_value ."\r\n";
        $row->field_description_value = substr($row->field_description_value, 0, 512);
      }
      if (!is_null($row->field_writer_reference_nid)) {
        $row->field_byline_value = NULL;
      }
      $row->body = str_replace('<p>&nbsp;</p>', '', $row->body);
    }
}

