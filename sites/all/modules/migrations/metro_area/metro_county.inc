<?php
class MetroCountyMigration extends Migration {
    public function __construct($arguments) {
      parent::__construct($arguments);
      $this->description = t('Add counties to imported Metro Area nodes from CSV data');
      $this->systemOfRecord = Migration::DESTINATION;
      //$this->dependencies = array('metroAreaCSV');

      $this->source = new metroCountySource(null);
      $this->destination = new MigrateDestinationNode('metro_area');
      $source_key = array('nid' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE,));
      $this->map = new MigrateSQLMap($this->machineName, $source_key, MigrateDestinationNode::getKeySchema());
      $this->addFieldMapping('nid', 'dest_nid');
      $this->addFieldMapping('field_county', 'county_nids')->separator(',');

    }
    public function prepareRow($row) {
      //drush_print_r($row);
    }
}
class metroCountySource extends MigrateSource {
    function __construct($arguments) {
        parent::__construct($arguments);
        $this->getNids();
        $path = drupal_get_path('module', 'metro_area') . "/metrocounty.csv";
        $this->data = $this->csvToArray($path);
    }
    public function fields() {
        return array('dest_nid' => t('The nid to be updated'), 'county_nids' => t('The counties to add'), 'rowId' => t('Unique county identifier'));
    }
    public function computeCount() {
        return count($this->nids);
    }
    public function performRewind() {
        reset($this->nids);
    }
    public function getNextRow() {
        $n = current($this->nids);
        if ($n == FALSE) {
            return FALSE;
        }
        next($this->nids);
        $n = node_load($n->nid);
        $row = new stdClass();
        $row->dest_nid = $n->nid;
        $metroFips = $n->field_place_id['und'][0]['value'];
        $county_array = array();
        foreach ($this->data as $data) {
            if ($data['metro_code'] == $metroFips) {
                //$row->rowId = $data['state_fips'] . $data['county_fips'];
                $county_array[] = $data;
            }
        }
        $row->county_nids = array();
        foreach ($county_array as $county) {
            $stateQuery = new EntityFieldQuery();
            $stateQuery->entityCondition('entity_type', 'node')->entityCondition('bundle', 'state')->fieldCondition('field_fips_state_code', 'value', $county['state_fips']);
            $state = $stateQuery->execute();
            if ($state['node']) {
                $state_result = (array_keys($state['node']));
                $state_nid = ($state_result[0]);
                $county_query = new EntityFieldQuery();
                $county_query->entityCondition('entity_type', 'node')->entityCondition('bundle', 'county')->fieldCondition('field_state', 'target_id', $state_nid)->fieldCondition('field_county_fips', 'value', $county['county_fips']);
                $county_nodes = $county_query->execute();
                if ($county_nodes['node']) {
                    $county_nids_array[] = key($county_nodes['node']);
                }
            }
        }
        if (!empty($county_nids_array)) {
            $row->county_nids = implode(',', $county_nids_array);
        }

        return $row;
    }
    protected function csvToArray($filename = '', $delimiter = ',') {
        if (!file_exists($filename) || !is_readable($filename)) return FALSE;
        $header = NULL;
        $data = array();
        if (($handle = fopen($filename, 'r')) !== FALSE) {
            while (($row = fgetcsv($handle, 1000, $delimiter)) !== FALSE) {
                if (!$header) $header = $row;
                else $data[] = array_combine($header, $row);
            }
            fclose($handle);
        }
        return $data;
    }
    public function __toString() {
        return t('Counties to Metro Areas');
    }
    protected function getNids() {
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')->entityCondition('bundle', 'metro_area');
        $metro_nodes = $query->execute();
        $this->nids = $metro_nodes['node'];
    }
}
