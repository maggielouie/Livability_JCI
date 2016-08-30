<?php

class CityCountySource extends MigrateSource{
    function __construct($args){
        parent::__construct($args);
        $q = new EntityFieldQuery();
        $q->entityCondition('entity_type','node')->entityCondition('bundle','city');
        //->fieldCondition('field_state','target_id','40'); //for testing quickly against just RI data
        $entity_nodes = $q->execute();
        $this->nodes = $entity_nodes['node'];
        $h = fopen(drupal_get_path('module','cityGeocode').'/geocorr12.csv','r');
        $i = 0;
        while($r = fgetcsv($h)){
            $i++;
            if($i == 1){ $this->keys = $r; continue;}
            if($i == 2) continue;
            $this->data[$r[0]][$r[1]] = $r[2];
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
        if(isset($n->field_state['und'])){
            $stateN = node_load($n->field_state['und'][0]['target_id']);
            $state = $stateN->field_fips_state_code['und'][0]['value'];
        }else{
            print 'no state on nid: '.$n->nid.' '.$n->title."\n";
        }
        $pid = $n->field_place_id['und'][0]['value'];
        if(strlen($pid) < 5){ while(strlen($pid)<5){ $pid = '0'.$pid;}}
        if(strlen($state) < 2){ $state = '0'.$state;}
        if(array_key_exists($pid,$this->data[$state])){
            $county = $this->data[$state][$pid];
            $countyQ = substr($county,2);
            $q = new EntityFieldQuery();
            $q->entityCondition('entity_type','node')->entityCondition('bundle','county')
                ->fieldCondition('field_county_fips','value',$countyQ)
                ->fieldCondition('field_state','target_id',$n->field_state['und'][0]['target_id']);
            $countyNode = $q->execute();
            if(count($countyNode) == 1){
                $obj->countyID = array_shift(array_keys($countyNode['node']));
            }else { print 'not found '.$n->title.' in county '.$this->data[$state][$pid]."\n"; }
        }
        return $obj;
    }
    function __toString(){
        return t('City Source');
    }
    function performRewind(){
        reset($this->nodes);
    }
    function computeCount(){
        return count($this->nodes);
    }
}