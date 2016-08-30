<?php

class DigitalMagazineMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('n.type', 'digital_magazine')
            ->condition('n.status', '1')
            ->orderBy('nid');
        $query->leftJoin('field_data_field_digital_magazine_type', 'type', 'type.entity_id = n.nid');
        $query->leftJoin('field_data_field_description', 'fd', 'fd.entity_id = n.nid'); 
        $query->leftJoin('field_data_field_calamaeo_id', 'calameo', 'calameo.entity_id = n.nid');
        $query->leftJoin('field_data_field_city', 'city', 'city.entity_id = n.nid');
        $query->leftJoin('url_alias', 'ua', 'ua.source like concat(\'node/\', CAST(n.nid AS CHAR))');
        $query->leftJoin('node', 'nc', 'nc.nid = city.field_city_nid');
        $query->fields('n', array('nid', 'title', 'created', 'changed', 'promote', 'sticky', 'status'));
        $query->fields('fd', array('field_description_value', 'field_description_format'));
        $query->fields('calameo', array('field_calamaeo_id_value'));
        $query->fields('city', array('field_city_nid'));
        $query->fields('ua', array('alias'));
        $query->addfield('nc', 'title', 'city');
//        $query->range(0,20);

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));
        $this->destination = new MigrateDestinationNode('digital_magazine');

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
        $this->addFieldMapping('field_city', 'city');
        $this->addFieldMapping('field_description', 'field_description_value');
        $this->addFieldMapping('field_description:format')->defaultValue('filtered_html');
        $this->addFieldMapping('field_calamaeo_id', 'field_calamaeo_id_value');
        $this->addFieldMapping('field_image:title', 'field_image_title');
        $this->addFieldMapping('path', 'alias');

    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
      $row->field_description_value = str_replace('<p>&nbsp;</p>', '', $row->field_description_value);
      if (!is_null($row->city)) {
        $name = explode(',', $row->city);
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
          $row->city= $citynid;
        }
      }
    }
    
    function prepare($node, $row) {

    } 
}

