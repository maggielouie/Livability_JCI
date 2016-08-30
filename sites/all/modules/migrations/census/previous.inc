<?php
/**
 */

class MigratePreviousSync extends Migration{
  private $censusFields = array();
  public function __construct($arguments) {
    $this->systemOfRecord = Migration::DESTINATION;
    parent::__construct($arguments);
    $this->source = new MigrateSourceCensusAPI('https://api.census.gov/data/2009/acs5?get=NAME,B01003_001E&for=place:*&in=state:*&key=3d9521af9c510f2beea74ce6f3b599b38bc50de9');
    //$this->source = new MigrateSourceCensusAPI('https://api.census.gov/data/2014/acs5/profile?get=NAME,DP05_0001E&for=place:*&in=state:*&key=3d9521af9c510f2beea74ce6f3b599b38bc50de9');
    $this->destination = new MigrateDestinationNode('city');
    $this->map = new MigrateSQLMap($this->machineName,array(
        'stateplace' => array('type' => 'int','unsigned' => TRUE,'not null' => true)
    ), MigrateDestinationNode::getKeySchema());
    $this->addFieldMapping('nid', 'stateplace')->sourceMigration('CitySync');
    $this->addFieldMapping('field_population_previous_year','B01003_001E');//Civilian population 18 years and over
    //$this->addFieldMapping('field_population_previous_year', 'DP05_0001E');
  }
}
