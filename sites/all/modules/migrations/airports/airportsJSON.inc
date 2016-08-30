<?php

class MigrateSourceAirportsJSON extends MigrateSource{
    private $raw = array();
    public function __construct($url, $options = array()) {
        $contents = file_get_contents($url);
        $Data = str_getcsv($contents, "\n"); //parse the rows
        foreach($Data as $line){
            $columns = str_getcsv($line);
            //print $columns[3];
            if($columns[3] == 'United States'){
                $this->raw[] = $columns;
            }
        }
        reset($this->raw);
        parent::__construct($options);
        $this->cacheCounts = false;
        $this->trackChanges = true;
    }
    function __toString() {
        return t('OpenFlights json');
    }
    function fields() {
        $ret = array();
        $ret['id'] = 'id';
        $ret['name'] = 'Name';
        $ret['city'] = 'City';
        $ret['country'] = 'Country';
        $ret['faa'] = 'FAA Code';
        $ret['lat'] = 'Latitude';
        $ret['long'] = 'Longitude';
        $ret['geotype'] = 'Geotype static point';
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
        if($row == false){ return false; }
        $obj = new stdClass();
        $obj->id = $row[0];
        $obj->name = $row[1];
        $obj->city = $row[2];
        $obj->country = $row[3];
        $obj->faa = $row[4];
        $obj->lat = $row[6];
        $obj->long = $row[7];
        $obj->geotype = 'point';
        //$obj->geom = 'POINT ('.$obj->long.' '.$obj->lat.')';
        $obj->geom = 'POINT ('.$obj->long.' '.$obj->lat.')';
        //print 'lat:'.$obj->lat.'long:'.$obj->long."\n";
        //print 'geom'.$obj->geom."\n";
        return $obj;
    }

}

