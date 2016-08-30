<?php

class BestPlacesImageMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('node', 'n')
            ->condition('type', 'photo')
            ->where('tax.taxonomy_vocabulary_1_tid IS NULL')
            ->orderBy('nid');
        $query->leftJoin('field_data_field_image','fi','fi.entity_id = n.nid');
        $query->leftJoin('file_managed','fm','fm.fid = fi.field_image_fid');
        $query->leftJoin('field_data_taxonomy_vocabulary_1','tax','tax.entity_id = n.nid');
        $query->leftJoin('field_data_field_byline', 'fb', 'fb.entity_id = n.nid');
        $query->leftJoin('field_data_field_description', 'fd', 'fd.entity_id = n.nid');
        $query->fields('n', array('nid',));
        $query->fields('fi', array('field_image_fid','field_image_alt', 'field_image_title')); //image fid, alt and title
        $query->fields('fm', array('filename',)); // the, uh, filename of the image
        $query->fields('tax', array('taxonomy_vocabulary_1_tid'));
        $query->fields('fb', array('field_byline_value'));
        $query->fields('fd', array('field_description_value'));
//        $query->isNotNull('fp.field_photos_nid');

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));
        $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

        $this->map = new MigrateSQLMap($this->machineName,
          array('nid' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'not null' => TRUE,
                'description' => 'Source File ID',
                'alias' => 'fi',
                ),
            ),
          MigrateDestinationFile::getKeySchema(),
          'default'
        );

        $this->addFieldMapping('value', 'filename');
        $this->addFieldMapping('source_dir')
          ->defaultValue('http://livability.com/sites/default/files/');
        $this->addFieldMapping('destination_file', 'filename');
        $this->addFieldMapping('file_replace')->defaultValue(MigrateFileBase::FILE_EXISTS_REUSE);
        $this->addFieldMapping('preserve_files')->defaultValue(TRUE);
$this->addFieldMapping('field_file_image_alt_text', 'field_image_alt');
$this->addFieldMapping('field_file_image_title_text', 'field_image_title');
$this->addFieldMapping('field_byline', 'field_byline_value');
$this->addFieldMapping('field_description', 'field_description_value');
    }

}
