<?php

class MigrateCityGeocode extends Migration {
    public function __construct($args){
        parent::__construct($args);
        $this->source = new MigrateCitySource(null);
        $this->destination = new MigrateDestinationNode('city');
        $this->map = new MigrateSQLMap($this->machineName,array('nid' => array('type' => 'int','unsigned' => TRUE,'not null' => true)), MigrateDestinationNode::getKeySchema());

        $this->addFieldMapping('nid','nid');
        $this->addFieldMapping('title','title');
        $this->addFieldMapping('field_geo','geom');
        $this->addFieldMapping('field_geo:input_format')->defaultValue('lat/lon');
        $this->addFieldMapping('field_geo:geo_type')->defaultValue('point');
        $this->addFieldMapping('field_geo:lat','lat');
        $this->addFieldMapping('field_geo:lon','long');
    }
}

class MigrateCityCounty extends Migration {
    public function __construct($args){
        parent::__construct($args);
        $this->source = new CityCountySource(null);
        $this->destination = new MigrateDestinationNode('city');
        $this->map = new MigrateSQLMap($this->machineName,array('nid' => array('type' => 'int','unsigned' => TRUE,'not null' => true)), MigrateDestinationNode::getKeySchema());
        $this->addFieldMapping('nid','nid');
        $this->addFieldMapping('field_county','countyID');
    }
}