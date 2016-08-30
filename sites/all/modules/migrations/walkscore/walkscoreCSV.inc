<?php

class MigrateWalkscoreSync{
    public function __construct($arguments) {
        $this->systemOfRecord = Migration::DESTINATION;
        parent::__construct($arguments);
        $this->source = new MigrateWalkScoreCSV();
        $this->destination = new MigrateDestinationNode('city');
        $this->map = new MigrateSQLMap($this->machineName,
            array('place' => array('type' => 'int','unsigned' => TRUE,'not null' => true)),
            MigrateDestinationNode::getKeySchema());
        $this->addFieldMapping('nid', 'place')->sourceMigration('CitySync');
    }
}

class MigrateWalkScoreCSV{
    public function __construct(){
        $fh = fopen(drupal_get_path('module','walkscore').DIRECTORY_SEPARATOR.'walkscore.csv','r');
        while($row = fgetcsv($fh)){
            print_r($row);
        }
    }
}
