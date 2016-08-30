<?php

class MigrateCitySource extends MigrateSource{
    function __construct($args){
        parent::__construct($args);
        $q = new EntityFieldQuery();
        $q->entityCondition('entity_type','node')->entityCondition('bundle','city');
        //->fieldCondition('field_state','target_id','40'); //for testing quickly against just RI data
        $entity_nodes = $q->execute();
        $this->nodes = $entity_nodes['node'];

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
        $options = array('target' => 'postgis');
        $pq = db_query("select * from place where placefp=? and statefp=?",array($pid,$state),$options);
        $geoPlace = $pq->fetchObject();
        $obj->title = $n->title;
        $obj->title = $geoPlace->name;
        $obj->long = $geoPlace->intptlon;
        $obj->lat = $geoPlace->intptlat;
        $obj->geom = 'POINT ('.$obj->long.' '.$obj->lat.')';
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