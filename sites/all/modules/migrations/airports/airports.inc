<?php

class MigrateAirports extends Migration{

    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->source = new MigrateSourceAirportsJSON('sites/all/modules/migrations/airports/airports.dat');

        $this->destination = new MigrateDestinationNode('airports');
        //county field is not unique globally
        $this->map = new MigrateSQLMap($this->machineName,
            array('id' => array('type' => 'int','unsigned' => TRUE,'not null' => true)), MigrateDestinationNode::getKeySchema());
        $this->addFieldMapping('title', 'name');

        //$this->addFieldMapping('field_state', 'state')->sourceMigration('StateSync');

        $this->addFieldMapping('field_geo','geom');
        $this->addFieldMapping('field_geo:input_format')->defaultValue('lat/lon');
        $this->addFieldMapping('field_geo:geo_type')->defaultValue('point');
        $this->addFieldMapping('field_geo:lat','lat');
        $this->addFieldMapping('field_geo:lon','long');

        /*$this->addFieldMapping('field_geo:left','long');
        $this->addFieldMapping('field_geo:right','long');

        $this->addFieldMapping('field_geo:top','lat');
        $this->addFieldMapping('field_geo:bottom','lat');
        $this->addFieldMapping('field_geo:geom','geom');
        */
        $this->addFieldMapping('field_faa_code','faa');
    }
}