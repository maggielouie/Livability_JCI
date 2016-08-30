<?php

class MigrateSourceGreatSchoolsDistrictsXML extends MigrateSource{
    public function __construct($options = array()) {
        $states = locality::$states;
        $this->states = $states;
        foreach($states as $st => $name){
            $feed = simplexml_load_file(drupal_get_path('module','greatschools').'/feed/local-greatschools-feed-'.$st.'.xml');

            foreach($feed->district as $district){
                $ret = new stdClass();
                $ret->id = (string)$district->{'universal-id'};
                $ret->name = (string)$district->name;
                $ret->lat = (string)$district->lat;
                $ret->lon = (string)$district->lon;
                $ret->geom = 'POINT('.$ret->lon.' '.$ret->lat.')';
                $ret->body = (string)$district->description;
                $ret->enrollment = (string) $district->{'census-info'}->enrollment->value;
                $ret->county = $this->lookupCounty((string)$district->fipscounty,$st);
                $this->districts[$ret->id] = $ret;
                //todo make this value be the stdclass obj, move getNextRow code up here
            }
            unset($feed);
            $testfeed = simplexml_load_file(drupal_get_path('module','greatschools').'/test-rating/local-gs-test-rating-feed-'.$st.'.xml');
            foreach($testfeed->{'test-rating-value'} as $test){
                $rid = (string)$test->{'universal-id'};
                if(array_key_exists($rid,$this->districts)){
                    $this->districts[$rid]->rating = (string)$test->rating;
                }
            }
            unset($testfeed);
        }
    }
    function lookupCounty($fipCode,$state){
        $stateLookupQuery = new EntityFieldQuery();
        $stateLookupQuery->entityCondition('entity_type','node')->entityCondition('bundle','state');
        $stateLookupQuery->fieldCondition('field_state_code','value',$state);
        $stateLookup = $stateLookupQuery->execute();
        if(count($stateLookup) == 1){
            $keys = array_keys($stateLookup['node']);
            //var_dump($keys);
            $stateNID = $keys[0];
        }
        $countyLookupQuery = new EntityFieldQuery();
        $countyLookupQuery->entityCondition('entity_type','node')->entityCondition('bundle','county');
        $countyLookupQuery->fieldCondition('field_state','target_id',$stateNID);
        $countyLookupQuery->fieldCondition('field_county_fips','value',substr($fipCode,2));
        $countyLookup = $countyLookupQuery->execute();
        if(count($countyLookup)>0){
            $keys = array_keys($countyLookup['node']);
            $countyNID = $keys[0];
        }
//        print $countyNID."\n";
        return $countyNID;
    }
    function fields() {
        $ret = array();
        $ret['id'] = 'id';
        $ret['name'] = 'Name';
        $ret['lat'] = 'Latitude';
        $ret['lon'] = 'Longitude';
        $ret['geom'] = 'Geometry';
        $ret['county'] = 'County';
//        $ret['city'] = 'City';
        return $ret;
    }
    function computeCount(){
        return count($this->districts);
    }
    function performRewind(){
        reset($this->districts);
    }
    function getNextRow(){
        //var_dump($this->districts);
        $row = next($this->districts);
        if($row == false){
            return false;
        }
        //var_dump($row);
        return $row;
    }
   function __toString(){ return 'Districts';}
}

class MigrateDistricts extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->source = new MigrateSourceGreatSchoolsDistrictsXML();
        $this->destination = new MigrateDestinationNode('school_districts');
        $this->map = new MigrateSQLMap($this->machineName,
            array('id' => array('type' => 'int','unsigned' => TRUE,'not null' => true)), MigrateDestinationNode::getKeySchema());
        $this->addFieldMapping('title', 'name');
        $this->addFieldMapping('body','body');
        $this->addFieldMapping('field_county','county');
        //$this->addFieldMapping('field_state', 'state')->sourceMigration('StateSync');
        $this->addFieldMapping('field_greatschools_id','id');
        $this->addFieldMapping('field_geo','geom');
        $this->addFieldMapping('field_geo:input_format')->defaultValue('lat/lon');
        $this->addFieldMapping('field_geo:geo_type')->defaultValue('point');
        $this->addFieldMapping('field_geo:lat','lat');
        $this->addFieldMapping('field_geo:lon','lon');
        $this->addFieldMapping('field_greatschools_rating', 'rating');
        $this->addFieldMapping('field_school_enrollment','enrollment');
    }
}
//drush php-eval 'foreach(locality::$states as $code => $name) { db_query("delete from url_alias where alias like ?",array($code."/%")); } '