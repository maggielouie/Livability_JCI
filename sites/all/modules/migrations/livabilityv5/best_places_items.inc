<?php

class BestPlacesItemMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('n.type', 'article')
            ->condition('n.status', '1')
            ->where('tta.delta > 0')
            ->orderBy('tta.delta');
        $query->leftJoin('field_data_field_city', 'fc', 'fc.entity_id = n.nid');
        $query->leftJoin('field_data_field_photos', 'fp', 'fp.entity_id = n.nid');
        $query->leftJoin('field_data_field_description','fd','fd.entity_id = fp.field_photos_nid');
        $query->leftJoin('field_data_field_article', 'fa', 'fa.entity_id = n.nid');
        $query->leftJoin('field_data_field_info_box_body', 'ibb', 'ibb.entity_id = n.nid');
        $query->leftJoin('field_data_field_page_title' ,'pt', 'pt.entity_id = n.nid');
        $query->leftJoin('field_data_field_metadescription', 'md', 'md.entity_id = n.nid');
        $query->leftJoin('node', 'nc', 'nc.nid = fc.field_city_nid');
        $query->innerJoin('field_data_field_top_ten_article', 'tta', 'tta.field_top_ten_article_nid = n.nid');
        $query->fields('n', array('nid', 'title'));
        $query->fields('fc', array('field_city_nid'));
        $query->fields('fp', array('field_photos_nid'));
        $query->fields('fd', array('field_description_value'));
        $query->fields('fa', array('field_article_value'));
        $query->fields('ibb', array('field_info_box_body_value'));
        $query->fields('pt', array('field_page_title_value'));
        $query->fields('md', array('field_metadescription_value'));
        $query->fields('tta', array('entity_id'));
        $query->addField('nc', 'title', 'city_title');
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
           'field_list_item',
           array('host_entity_type' => 'node')
        );

        $this->addFieldMapping('host_entity_id', 'entity_id')
          ->sourceMigration('BestPlaces');
        $this->addFieldMapping('field_city', 'city_title');
        $this->addFieldMapping('field_image_single', 'field_photos_nid')
          ->sourceMigration('BestPlacesImages');
        $this->addFieldMapping('field_image_single:file_class')
          ->defaultValue('MigrateFileFid');
        $this->addFieldMapping('field_image_single:alt', 'field_description_value'); // 512 char limit.
        $this->addFieldMapping('field_image_single:title', 'field_description_value');
        $this->addFieldMapping('field_headline', 'title');
        $this->addFieldMapping('field_bp_body', 'field_article_value');
        $this->addFieldMapping('field_bp_body:format')->defaultValue('filtered_html');
        $this->addFieldMapping('field_highlights', 'field_data_field_info_box_body');
        $this->addFieldMapping('field_page_title', 'field_page_title_value');
        $this->addFieldMapping('field_meta_description', 'field_metadescription_value');

    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
      if (is_null($row->city_title)) {
        return FALSE;
      }
      else {
        $name = explode(',', $row->city_title);
        $cityname = $name[0];
        $stateabbr = trim(array_pop($name));
        $states = array('AL' => 'Alabama',
                 'AK' => 'Alaska',
                 'AZ' => 'Arizona',
                 'AR' => 'Arkansas',
                 'CA' => 'California',
                 'CO' => 'Colorado',
                 'CT' => 'Connecticut',
                 'DE' => 'Delaware',
                 'FL' => 'Florida',
                 'GA' => 'Georgia',
                 'HI' => 'Hawaii',
                 'ID' => 'Idaho',
                 'IL' => 'Illinois',
                 'IN' => 'Indiana',
                 'IA' => 'Iowa',
                 'KS' => 'Kansas',
                 'KY' => 'Kentucky',
                 'LA' => 'Louisiana',
                 'ME' => 'Maine',
                 'MD' => 'Maryland',
                 'MA' => 'Massachusetts',
                 'MI' => 'Michigan',
                 'MN' => 'Minnesota',
                 'MS' => 'Mississippi',
                 'MO' => 'Missouri',
                 'MT' => 'Montana',
                 'NE' => 'Nebraska',
                 'NV' => 'Nevada',
                 'NH' => 'New Hampshire',
                 'NJ' => 'New Jersey',
                 'NM' => 'New Mexico',
                 'NY' => 'New York',
                 'NC' => 'North Carolina',
                 'ND' => 'North Dakota',
                 'OH' => 'Ohio',
                 'OK' => 'Oklahoma',
                 'OR' => 'Oregon',
                 'PA' => 'Pennsylvania',
                 'RI' => 'Rhode Island',
                 'SC' => 'South Carolina',
                 'SD' => 'South Dakota',
                 'TN' => 'Tennessee',
                 'TX' => 'Texas',
                 'UT' => 'Utah',
                 'VT' => 'Vermont',
                 'VA' => 'Virginia',
                 'WA' => 'Washington',
                 'WV' => 'West Virginia',
                 'WI' => 'Wisconsin',
                 'WY' => 'Wyoming',);

        $statename = $states[$stateabbr];
        $statenid = db_query('SELECT nid from {node} where type = \'state\' and title = :s', array(':s' => $statename))->fetchColumn(0);
        $cityquery = db_select('node', 'n')
          ->fields('n', array('nid'))
          ->condition('n.type', array('city', 'area'),'IN')
          ->condition('n.title', db_like($cityname).'%', 'LIKE')
          ->condition('fs.field_state_target_id', $statenid);
        $cityquery->leftJoin('field_data_field_state', 'fs', 'fs.entity_id = n.nid');
        $citynid = $cityquery->execute()->fetchAll();

        if(!empty($citynid)) {
          $cities = array();
          foreach($citynid as $i => $nid) {
            $cities[] = node_load($nid->nid);
          }
          foreach ($cities as $candidate) {
            if ($candidate->title === $cityname) {
              $citynid = $candidate->nid;
            }
          }
          if (!isset($citynid)) {
            $citynid = $citynid[0]->nid;
          }
          $row->city_title = $citynid;
        }
        else {
          return FALSE;
        }
      }

      if (strlen($row->field_description_value) > 512) {
        $row->field_description_value = substr($row->field_description_value, 0, 512);
      }
    }
}

