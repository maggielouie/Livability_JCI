<?php

class WriterImageMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('type', 'spotlight')
            ->orderBy('nid');
        $query->leftJoin('field_data_field_image','fi','fi.entity_id = n.nid');
        $query->leftJoin('file_managed','fm','fm.fid = fi.field_image_fid');
        $query->fields('n', array('nid',));
        $query->fields('fi', array('field_image_fid', 'field_image_alt', 'field_image_title',)); //image fid, alt and title
        $query->fields('fm', array('filename',)); // the, uh, filename of the image

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));
        $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

        $this->map = new MigrateSQLMap($this->machineName,
          array('field_image_fid' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Source File ID',
                'alias' => 'fi',
                ),
            ),
          MigrateDestinationUser::getKeySchema(),
          'default'
        );

        $this->addFieldMapping('value', 'filename');
        $this->addFieldMapping('source_dir')
          ->defaultValue('http://livability.com/sites/default/files/');
        $this->addFieldMapping('destination_file', 'filename');
        $this->addFieldMapping('file_replace')->defaultValue(MigrateFileBase::FILE_EXISTS_REUSE);
        $this->addFieldMapping('preserve_files')->defaultValue(TRUE);

    }

}
