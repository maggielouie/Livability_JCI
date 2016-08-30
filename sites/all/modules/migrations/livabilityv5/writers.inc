<?php

class WriterMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('type', 'spotlight')
            ->orderBy('nid');
        $query->leftJoin('field_data_field_image','fi','fi.entity_id = n.nid');
        $query->leftJoin('field_data_field_description','fd','fd.entity_id = n.nid');
        $query->leftJoin('file_managed','fm','fm.fid = fi.field_image_fid');
        $query->fields('n', array('nid', 'title',)); // name
        $query->fields('fi', array('field_image_fid', 'field_image_alt', 'field_image_title',)); //image fid, alt and title
        $query->fields('fd', array('field_description_value')); // 'bio' and format
        $query->fields('fm', array('filename',)); // the, uh, filename of the image

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));
        $this->destination = new MigrateDestinationUser();

        $this->map = new MigrateSQLMap($this->machineName,
          array('nid' => array(
               'type' => 'int',
               'unsigned' => TRUE,
               'not null' => TRUE,
               'description' => 'Source node ID',
               'alias' => 'n',
               ),
          ),
          MigrateDestinationUser::getKeySchema(),
          'default'
        );

        $this->addFieldMapping('name', 'title')
          ->dedupe('users', 'name');
        $this->addFieldMapping('field_user_bio', 'field_description_value');
        $this->addFieldMapping('field_user_bio:format')->defaultValue('full_html'); //subfield notation
        $this->addFieldMapping('roles')
          ->defaultValue(DRUPAL_AUTHENTICATED_RID);
        $this->addFieldMapping('picture', 'field_image_fid')
          ->sourceMigration('WriterImages');
    }
    
    public function prepare($node, $row) {
      $name = explode(" ", $row->title);
      if(isset($name[1])) {
        $finit = substr($name[0], 0, 1);
        $lname = array_pop($name);
        $ename = $finit . $lname;// $name[1];
      }
      else {
        $ename = $name[0];
      }
      $node->mail = strtolower($ename . '@jnlcom.com');
      $node->pass = generateRandomString();
      $node->status = 1;

    }
}

function generateRandomString($length = 10) {
    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+!$@';
    $randomString = '';
    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, strlen($characters) - 1)];
    }
    return $randomString;
}