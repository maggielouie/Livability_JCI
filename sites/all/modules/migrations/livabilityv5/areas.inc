<?php

class AreaMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('type', 'city')
            ->condition('status', '1')
            ->orderBy('nid');
        $query->leftJoin('field_data_field_city_layout','cl','cl.entity_id = n.nid');
        $query->leftJoin('field_data_field_summary','s','s.entity_id = n.nid');
        $query->leftJoin('field_data_field_ad_targeting_project_id','atp','atp.entity_id = n.nid');
        $query->fields('n', array('nid', 'title',));
        $query->fields('cl', array('field_city_layout_tid'));
        $query->fields('s', array('field_summary_value'));
        $query->fields('atp', array('field_ad_targeting_project_id_value'));
//        $query->range(0,40);

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));
        $this->destination = new MigrateDestinationNode('area');

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
        $this->addFieldMapping('body', 'field_summary_value');
        $this->addFieldMapping('body:format')->defaultValue('filtered_html');
        $this->addFieldMapping('citypromoted', 'field_data_field_city_layout');
        //$this->addFieldMapping('field_ad_targeting_project_id', 'field_ad_targeting_project_id_value');
    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }

      $name = explode(',', $row->title);
      $row->title = $name[0];
      if ($row->title == '') {
        return FALSE;
      }
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

      $row->statename = $states[$stateabbr];
      $statenid = db_query('SELECT nid from {node} where type = \'state\' and title = :s', array(':s' => $row->statename))->fetchColumn(0);
      $row->statenid = $statenid;
      $citytitle = $row->title;
      $cityquery = db_select('node', 'n')
        ->fields('n', array('nid'))
        ->condition('n.type', 'city')
        ->condition('n.title', db_like($citytitle).'%', 'LIKE')
        ->condition('fs.field_state_target_id', $statenid);
      $cityquery->leftJoin('field_data_field_state', 'fs', 'fs.entity_id = n.nid');
      $citynid = $cityquery->execute()->fetchAll();
      if(!empty($citynid)) {
        $cities = array();
        foreach($citynid as $i => $nid) {
          $cities[] = node_load($nid->nid);
        }
        foreach ($cities as $candidate) {
          if ($candidate->title === $row->title) {
            $city = $candidate;
          }
        }
        if (isset($city)) {
          $thislayout = $row->field_city_layout_tid;
          if ($thislayout == 84) { // 82 = basic, 83 = data, 84 = full
            $city->field_promoted_city[LANGUAGE_NONE][0]['value'] = 1;
            echo "\r\n$city->title updated to Promoted\r\n";
            node_save($city);
          }
          echo "$row->title not imported\r\n";
          return FALSE;
        }
      }
    }
    
    function prepare($node, $row) {
      if (isset($row->statenid) && !empty($row->statenid)) {
        $node->field_state['und'][0]['target_id'] = $row->statenid;
      }
      if (isset($row->citynid) && !empty($row->citynid)) {
        $node->field_city['und'][0]['target_id'] = $row->citynid;
      }
    }
}

