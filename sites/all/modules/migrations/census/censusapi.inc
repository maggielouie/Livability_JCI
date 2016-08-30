<?php
class MigrateSourceCensusAPI extends MigrateSource{
  private $raw = array();
  function __construct($url, $options = array()) {
    //print $url;
    $raw = json_decode(file_get_contents($url));
    $this->keys = array_shift($raw);
    foreach($raw as $obj){
      $state = array_search('state',$this->keys);
      if($state !== false){
        $st = $obj[$state];
        if($st == '72'){
          continue;
        }
      }
      $popKey = array_search('DP05_0001E',$this->keys);
      if($popKey !== false){
        $pop = $obj[$popKey];
        //print 'population: '.$pop.' popkey: '.$popKey."\n";
        if($pop < 499){
          //print 'less than 1k population'.$obj->place."\n";
          continue;
        }
      } /*
      $popKey2 = array_search('B01003_001E',$this->keys);
      if($popKey2 !== false){
        $pop = $obj[$popKey2];
        //print 'population: '.$pop.' popkey: '.$popKey."\n";
        if($pop < 0){
          //print 'less than 1k population'.$obj->place."\n";
          continue;
        }
      } */
      $this->raw[] = $obj;
    }
    reset($this->raw);
    parent::__construct($options);
    $this->cacheCounts = false;
    $this->trackChanges = true;
  }
  function __toString() {
    return t('Census API');
  }
  function fields() {
    $ret = array();
    foreach($this->keys as $key){
      $ret[$key] = t($key);
    }
    return $ret;
  }
  function computeCount(){
    return count($this->raw);
  }
  function performRewind(){
    return reset($this->raw);
  }
  function getNextRow(){
    $row = current($this->raw);
    next($this->raw);
    if($row === false){ return false; }

    $obj = new stdClass();
    foreach($row as $field => $value){
      $field = $this->keys[$field];
      $obj->$field = $value;
    }
    if(isset($obj->NAME)){
      $obj->censusname = $obj->NAME;
      $obj->NAME = locality::trimStateCensusClean($obj->NAME);
    }
    if(isset($obj->NAME) && isset($obj->state)){
      $obj->stateCode = locality::stateCodeFromName($obj->NAME);
    }
/*
    if(isset($obj->NAME)){
      $obj->mapname = locality::mapFromName($obj->censusname);
      $address = $obj->mapname;
      $prepAddr = str_replace(' ','+',$address);
      $geocode=file_get_contents('https://maps.google.com/maps/api/geocode/json?address='.$prepAddr.'&sensor=false&key=AIzaSyD7g1O0vVJOx5uuhrqzTWyk3nVWyPsXNZM');
      $output= json_decode($geocode);
      $obj->lat = $output->results[0]->geometry->location->lat;
      $obj->long = $output->results[0]->geometry->location->lng;
      $obj->geom = 'POINT ('.$obj->long.' '.$obj->lat.')';
    }
*/
    if(isset($obj->place)){
      $obj->placeCode = $obj->place;
      if(strlen($obj->state) < 2){
        $obj->state = '0'.$obj->state;
      }
      $obj->livfips = $obj->state.'-'.$obj->place;
      if (strpos($obj->state, '0') !== false) {
        $obj->state = ltrim($obj->state, '0');
      }
      if (str_replace('0', '', $obj->place)) {
        $obj->place2 = substr($obj->place, 1);
        $obj->place3 = ltrim($obj->place, '0');
      }
      $obj->stateplace = $obj->state.$obj->place3;
    }
    if(isset($obj->county)) {
      $obj->livfips = $obj->state.'-'.$obj->county;
    }
    if(isset($obj->DP03_0086E)){
        $obj->DP03_0086E = $this->cleanCensusMoney($obj->DP03_0086E);
    }
    if(isset($obj->DP04_0088E)){
        $obj->DP04_0088E = $this->cleanCensusMoney($obj->DP04_0088E);
    }
    return $obj;
  }
  function cleanCensusMoney($value){
    if($value == '-'){
      $value = null;
    }
    if(strstr($value, '-') !== false){
      $value = str_replace('-','',$value);
    }
    if(strstr($value, ',') !== false){
      $value = str_replace(',','',$value);
    }
    if(strstr($value, '+') !== false){
      $value = str_replace('+','',$value);
    }
    return $value;
  }
}
