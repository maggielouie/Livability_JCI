<?php

class MigrateHospitalSync extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->source = new MigrateSourceMedicareJSON('sites/all/modules/migrations/medicare/medicare.json');
        
        $this->destination = new MigrateDestinationNode('hospitals');
        //county field is not unique globally
        $this->map = new MigrateSQLMap($this->machineName,
                array('id' => array('type' => 'int','unsigned' => TRUE,'not null' => true)), MigrateDestinationNode::getKeySchema());
        $this->addFieldMapping('title', 'name');
        $this->addFieldMapping('field_hospital_type','type');
        $this->addFieldMapping('field_geo','geom');
        $this->addFieldMapping('field_geo:input_format')->defaultValue('lat/lon');
        $this->addFieldMapping('field_geo:geo_type')->defaultValue('point');
        $this->addFieldMapping('field_geo:lat','lat');
        $this->addFieldMapping('field_geo:lon','long');
        $this->addFieldMapping('field_ownership','ownership');
        $this->addFieldMapping('field_provider_id','provider');
    }
}