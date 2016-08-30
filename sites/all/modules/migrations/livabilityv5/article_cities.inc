<?php

class ArticleCitiesMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('n.type', 'article')
            ->condition('n.status', '1')
            ->isNotNull('tax.taxonomy_vocabulary_1_tid')
            ->isNull('tta.entity_id')
            ->isNull('cpa.entity_id')
            ->orderBy('n.nid');
        $query->leftJoin('field_data_field_city','fc','fc.entity_id = n.nid');
        $query->leftJoin('field_data_taxonomy_vocabulary_1','tax','tax.entity_id = n.nid');
        $query->leftJoin('field_data_field_top_ten_article','tta','tta.field_top_ten_article_nid = n.nid');
        $query->leftJoin('field_data_field_city_profile_articles','cpa','cpa.field_city_profile_articles_nid = n.nid');
        $query->leftJoin('node', 'nc', 'nc.nid = fc.field_city_nid');

        $query->fields('n', array('nid'));
        $query->fields('nc', array('title'));
        $query->fields('fc', array('field_city_nid', 'entity_id'));
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
           'field_place',
           array('host_entity_type' => 'node')
        );
        $this->addFieldMapping('host_entity_id', 'nid')
          ->sourceMigration('Articles');
        $this->addFieldMapping('field_place_ref', 'title');
        $this->addFieldMapping('field_primary_host', 'entity_id');

    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
	
      if (is_null($row->title)) {
        return FALSE;
      }
      else {
        $name = explode(',', $row->title);
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
          $row->title = $citynid;
        }
        else {
          return FALSE;
        }
      }
      
      if (!is_null($row->entity_id)) {
        $row->entity_id = 1;
      }
//      print_r($row);
    }
    
    function prepare($node, $row) {
/*
echo 'NODE:';
print_r($node);
echo 'ROW:';
print_r($row);
*/
    }
}

