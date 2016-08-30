<?php

class Top100Migration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);

         $columns = array(
           0 => array('rank', 'Rank'),
           1 => array('place_id', 'Place_ID'),
           2 => array('city_name', 'GEO.display-label'),
           3 => array('state', 'State'),
           4 => array('pop2010', 'Pop 2010'),
           5 => array('livscore', 'LivScore'),
           6 => array('economics', 'Economics'),
           7 => array('healthcare', 'Healthcare'),
           8 => array('housing', 'Housing'),
           9 => array('social_civic_capital', 'Social and Civic Capital'),
           10 => array('education', 'Education'),
           11 => array('amenities', 'Amenities'),
           12 => array('demographics', 'Demographics'),
           13 => array('infrastructure', 'Infrastructure'),
        );

        $this->source = new MigrateSourceCSV(drupal_get_path('module', 'livabilityv5').'/t100/top100-2013.csv', $columns, array('header_rows' => 1,));
        $this->destination = new MigrateDestinationFieldCollection(
           'field_top_100_item',
           array('host_entity_type' => 'node')
        );
        $this->map = new MigrateSQLMap($this->machineName,
          array('rank' => array( 'type' => 'int',
                                'unsigned' => TRUE,
                                'not null' => TRUE,
                                'description' => 'Source node ID',),),
          MigrateDestinationFieldCollection::getKeySchema()
        );
        
        $this->addFieldMapping('host_entity_id')->defaultValue(43593);

        $this->addFieldMapping('field_rank', 'rank');
        $this->addFieldMapping('field_top_100_city', 'place_id');
        $this->addFieldMapping('field_livscore', 'livscore');
        $this->addFieldMapping('field_economic_score', 'economics');
        $this->addFieldMapping('field_healthcare_score', 'healthcare');
        $this->addFieldMapping('field_housing_score', 'housing');
        $this->addFieldMapping('field_civic_capital_score', 'social_civic_capital');
        $this->addFieldMapping('field_education_score', 'education');
        $this->addFieldMapping('field_amenities_score', 'amenities');
        $this->addFieldMapping('field_demographics_score', 'demographics');
        $this->addFieldMapping('field_infrastructure_score', 'infrastructure');

    }

    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }

      $cityquery = 'SELECT n.nid from node n inner join field_data_field_state fs on fs.entity_id = n.nid inner join node s on s.nid = fs.field_state_target_id where n.type = :type and n.title like :city and s.title = :state';
      $cityname = str_replace(' ', '%', $row->city_name);
      $city = db_query($cityquery, array(':type' => 'City', ':city' => $cityname, ':state' => $row->state))->fetchAll();
      if (!isset($city[0]->nid)) { echo $row->city_name .", ".$row->state ." didn't match a City\n";}
      $row->place_id = $city[0]->nid;

    }
    
    function prepare($node, $row) {
//print_r($node);
// print_r($row);

    }
}

