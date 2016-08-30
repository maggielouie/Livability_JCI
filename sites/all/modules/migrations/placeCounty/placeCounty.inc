<?php
class MigratePlaceCounty extends Migration {
  public function __construct($args){
    $this->systemOfRecord = Migration::DESTINATION;
    parent::__construct($args);
    $this->source = new placeCountySource(null);
    $this->destination = new MigrateDestinationNode('city');
    $this->map = new MigrateSQLMap($this->machineName,array('nid' => array('type' => 'int','unsigned' => TRUE,'not null' => true)), MigrateDestinationNode::getKeySchema());
    $this->addFieldMapping('nid','nid');
    $this->addFieldMapping('field_county','countyID');
  }
}
class placeCountySource extends MigrateSource{
  function __construct($args){
    parent::__construct($args);
    $q = new EntityFieldQuery();
    $q->entityCondition('entity_type','node')->entityCondition('bundle','city');
    //->fieldCondition('field_state','target_id','43'); //for testing quickly against just RI data
    $entity_nodes = $q->execute();
    $this->nodes = $entity_nodes['node'];
    $h = fopen(drupal_get_path('module','placeCounty').'/place_county.csv','r');
    $i = 0;
    while($r = fgetcsv($h)){
      $i++;
      if($i == 1){ $this->keys = $r; continue;}
      if($i == 2) continue;
      if(isset($this->data[$r[0]][$r[1]])){
        if($r[7] > $this->data[$r[0]][$r[1]][7]){
          $this->data[$r[0]][$r[1]] = $r;
        }
      }else{
        $this->data[$r[0]][$r[1]] = $r;
      }
    }
  }
  function fields(){
    return($this->nodes[0]->fields);
  }
  function getNextRow(){
    $n = current($this->nodes);
    if($n == false){ return false; }
    next($this->nodes);
    $n = node_load($n->nid);

    $obj = new stdClass();
    $obj->nid = $n->nid;
    $stateN = node_load($n->field_state['und'][0]['target_id']);
    $state = $stateN->field_fips['und'][0]['value'];
    $pid = $n->field_fips['und'][0]['value'];
    if(array_key_exists($pid,$this->data[$state])){
      $row = $this->data[$state][$pid];
      $countyQ = $row[2];
      //print $countyQ." the q\n";
      /*
      if($countyQ[0] == '0'){
          $countyQ = substr($countyQ,1);
      } */
      $q = new EntityFieldQuery();
      $q->entityCondition('entity_type','node')->entityCondition('bundle','county')
          ->fieldCondition('field_fips','value',$countyQ)
          ->fieldCondition('field_state','target_id',$n->field_state['und'][0]['target_id']);
      $countyNode = $q->execute();
      if(count($countyNode['node']) == 1){
        $obj->countyID = array_shift(array_keys($countyNode['node']));
      } else {
        var_dump($row);print $countyQ.'== '.$pid;print ' not found '.$n->title.' in county '.$this->data[$state][$pid][1]."\n";
      }
    } else {
      print 'source mapping failed for state: '.$state.' with pid of:'.$pid."\n";
    }
    return $obj;
  }
  function __toString(){
      return t('Place to county Source');
  }
  function performRewind(){
      reset($this->nodes);
  }
  function computeCount(){
      return count($this->nodes);
  }
}