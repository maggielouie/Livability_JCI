<?php

class LivTermMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('taxonomy_term_data', 'ttd')
            ->condition('vid', '1')
            ->where('tid in (1,2,3,4,5,10,11,64,156,224,225,226,227,228,229,230,231,232)')
            ->orderBy('tid');
        $query->fields('ttd', array('tid', 'name', 'description', 'weight', 'uuid'));

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));

        $this->destination = new MigrateDestinationTerm('category');

        $this->map = new MigrateSQLMap($this->machineName,
          array('tid' => array( 'type' => 'int',
                                'unsigned' => TRUE,
                                'not null' => TRUE,
                                'alias' => 'ttd', ),),
          MigrateDestinationTerm::getKeySchema()
        );

        $this->addFieldMapping('name', 'name');
        $this->addFieldMapping('description', 'description');
        $this->addFieldMapping('parent_name', 'uuid');
        $this->addFieldMapping('weight', 'weight');

    }
    
    function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
      
      switch ($row->tid) {
        case 1:
          unset($row->uuid);
          $row->name = 'Place level';
          $row->description = '';
          $row->weight = 0;
          break;
        case 2:
          $row->uuid = 'Place level';
          break;
        case 3:
          $row->uuid = 'Place level';
          $row->name = 'Sports and Recreation';
          break;
        case 4:
          $row->uuid = 'Place level';
          break;
        case 5:
          $row->uuid = 'Place level';
          $row->name = 'Food and Drink';
          break;
        case 10:
          $row->uuid = 'Place level';
          break;
        case 11:
          $row->uuid = 'Place level';
          break;
        case 64:
          $row->uuid = 'Place level';
          $row->name = 'Real Estate';
          break;
        case 156:
          $row->uuid = 'Place level';
          break;
        case 224:
          unset($row->uuid);
          break;
        case 225:
          $row->uuid = 'Global';
          break;
        case 226:
          $row->uuid = 'Global';
          break;
        case 227:
          $row->uuid = 'Global';
          break;
        case 228:
          $row->uuid = 'Global';
          break;
        case 229:
          $row->uuid = 'Global';
          break;
        case 230:
          $row->uuid = 'Global';
          break;
        case 231:
          $row->uuid = 'Global';
          break;
        case 232:
          $row->uuid = 'Global';
          break;
      }

    }
 
}

