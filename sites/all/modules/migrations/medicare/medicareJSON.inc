<?php

class MigrateSourceMedicareJSON extends MigrateSource{
    private $raw = array();
    public function __construct($url, $options = array()) {
        $contents = file_get_contents($url);
        $this->src = json_decode($contents);
        $this->raw = $this->src->data;
        reset($this->raw);
        parent::__construct($options);
        $this->cacheCounts = false;
        $this->trackChanges = true;
    }
    function __toString() {
        return t('Medicare json');
    }
    function fields() {
        $ret = array();
        $ret['id'] = t('id');
        $ret['name'] = t('name');
        $ret['type'] = t('type');
        $ret['lat'] = t('lat');
        $ret['long'] = t('long');
        $ret['geom'] = t('geom');
        $ret['ownership'] = t('Ownership');
        $ret['provider'] = t('provider');
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

        //var_dump($row);die();
        if($row == false){ return false; }
        $obj = new stdClass();
        $obj->id = $row[0];
        $obj->provider = $row[8];
        $obj->name = $row[9];
        $obj->type = $row[16];
        $obj->ownership = $row[17];
        $obj->long = $row[19][1];
        $obj->lat = $row[19][2];
        $obj->geom = 'POINT ('.$obj->lat.' '.$obj->long.')';
        return $obj;
    }
    
}

