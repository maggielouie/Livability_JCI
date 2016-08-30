<?php

class ArticleImageMigration extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $query = Database::getConnection('default', 'migration')
            ->select('field_data_field_photos', 'fp')
            ->condition('fp.bundle', 'article');
        //the money shot right der
        //select * from field_data_field_photos fp join node np on fp.field_photos_nid=np.nid join field_data_field_image fi on fi.entity_id=np.nid where fp.bundle = 'article' limit 10;
        $query->leftJoin('node','np','fp.field_photos_nid=np.nid');
        $query->leftJoin('field_data_field_image','fi','fi.entity_id = np.nid');
        $query->leftJoin('field_data_field_photo_display_title','fpdt','fpdt.entity_id=np.nid');

        $query->leftJoin('file_managed','fm','fm.fid = fi.field_image_fid');
        $query->leftJoin('field_data_field_byline', 'fb', 'fb.entity_id = np.nid');
        $query->leftJoin('field_data_field_description', 'fd', 'fd.entity_id = np.nid');
        $query->fields('np', array('nid'));
        $query->fields('fm', array('filename',)); // the, uh, filename of the image
        $query->isNotNull('fp.field_photos_nid');

        $this->source = new MigrateSourceSQL($query,array(),null,array('map_joinable' => FALSE));
        $this->destination = new MigrateDestinationFile('image', 'MigrateFileUri');

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
        $this->addFieldMapping('field_file_image_title_text','field_photo_display_title_value');
        $this->addFieldMapping('field_file_image_alt_text','field_photo_display_title_value');
        $this->addFieldMapping('field_byline','field_byline_value');
        $this->addFieldMapping('field_description','field_description_value');
        //$this->addFieldMapping('field_place_ref');
    }
}
