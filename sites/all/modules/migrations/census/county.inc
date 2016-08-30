<?php

class MigrateCountySync extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->source = new MigrateSourceCensusAPI(
                'https://api.census.gov/data/2014/acs5/profile?get=NAME,DP05_0001E,DP04_0088E,DP03_0062E&for=county:*&in=state:*&key=3d9521af9c510f2beea74ce6f3b599b38bc50de9');
        //$this->dependencies = array('StateSync');
        $this->destination = new MigrateDestinationNode('county');
        //county field is not unique globally
        $this->map = new MigrateSQLMap($this->machineName,array(
            'county' => array('type' => 'int','unsigned' => TRUE,'not null' => true),
            'state' => array('type' => 'int','unsigned' => TRUE, 'not null' => true)
        ), MigrateDestinationNode::getKeySchema());
        $this->addFieldMapping('title', 'NAME');
        $this->addFieldMapping('field_population','DP05_0001E');
        $this->addFieldMapping('field_fips', 'county');
        $this->addFieldMapping('field_liv_fips', 'livfips');
        $this->addFieldMapping('field_state', 'state')->sourceMigration('StateSync');
        $this->addFieldMapping('field_median_home_price','DP04_0088E');
        $this->addFieldMapping('field_median_household_income','DP03_0062E');
        /* GEO
        $this->addFieldMapping('field_geo','geom');
        $this->addFieldMapping('field_geo:input_format')->defaultValue('lat/lon');
        $this->addFieldMapping('field_geo:geo_type')->defaultValue('point');
        $this->addFieldMapping('field_geo:lat','lat');
        $this->addFieldMapping('field_geo:lon','long');
        */
        $this->addFieldMapping('pathauto','1');
    }
}