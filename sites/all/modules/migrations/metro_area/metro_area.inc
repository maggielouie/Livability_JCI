<?php
class MetroAreaMigration extends Migration {
    public function __construct($arguments) {
        parent::__construct($arguments);
        $sourcefile = drupal_get_path('module', 'metro_area') . '/msa_metro.csv';
        $this->source = new MigrateSourceCSV($sourcefile, $this->csvColumns(), array(), $this->extraFields());
        $this->destination = new MigrateDestinationNode('metro_area');
        $source_key = array('GEO_id2' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE,));
        $this->map = new MigrateSQLMap($this->machineName, $source_key, MigrateDestinationNode::getkeySchema(), 'default');
        $this->addFieldMapping('title', 'GEO_displayLabel');
        $this->addFieldMapping('field_metro_nickname', 'Nickname');
        $this->addFieldMapping('field_metro_shortname', 'Shortname');
        $this->addFieldMapping('field_place_id', 'GEO_id2');
        $this->addFieldMapping('field_state', 'states')->separator(',');
    }
    public function prepareRow($row) {
        $longname = $row->GEO_displayLabel;
        $us_state_abbrevs = array('AL', 'AK', 'AS', 'AZ', 'AR', 'CA', 'CO', 'CT', 'DE', 'DC', 'FM', 'FL', 'GA', 'GU', 'HI', 'ID', 'IL', 'IN', 'IA', 'KS', 'KY', 'LA', 'ME', 'MH', 'MD', 'MA', 'MI', 'MN', 'MS', 'MO', 'MT', 'NE', 'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND', 'MP', 'OH', 'OK', 'OR', 'PW', 'PA', 'PR', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT', 'VI', 'VA', 'WA', 'WV', 'WI', 'WY', 'AE', 'AA', 'AP');
        $nids = array();
        foreach ($us_state_abbrevs as $st) {
            if (strpos($longname, $st) == TRUE) {
                $nid = db_query('SELECT entity_id from {field_data_field_state_code} where field_state_code_value = :state', array(':state' => $st))->fetchField();
                $nids[] = $nid;
            }
        }
        $row->states = implode(',', $nids);
    }
    public function csvColumns() {
        $columns[0] = array('GEO_id', 'Long Geo ID');
        $columns[1] = array('GEO_id2', 'Short Geo ID');
        $columns[2] = array('Population', 'Area Population');
        $columns[3] = array('GEO_displayLabel', 'Long Name');
        $columns[4] = array('Nickname', 'Nickname');
        $columns[5] = array('Shortname', 'Shorter Nickname');
        return $columns;
    }
    public function extraFields() {
        return array('states' => 'States processed out of Long Name in prepareRow',);
    }
}
