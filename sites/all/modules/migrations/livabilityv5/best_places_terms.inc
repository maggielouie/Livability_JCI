<?php

class BestPlacesTermMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('type', 'top_ten')
            ->condition('status', '1')
            ->orderBy('nid'); 
        $query->fields('n', array('nid', 'title'));
        
        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));

        $this->destination = new MigrateDestinationTerm('best_places');

        $this->map = new MigrateSQLMap($this->machineName,
          array('nid' => array( 'type' => 'int',
                                'unsigned' => TRUE,
                                'not null' => TRUE,
                                'alias' => 'ttd', ),),
          MigrateDestinationTerm::getKeySchema()
        );

        $this->addFieldMapping('name', 'title');

    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
    }
 
}

