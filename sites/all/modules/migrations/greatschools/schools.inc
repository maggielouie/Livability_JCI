<?php

class MigrateSourceGreatSchoolsSchoolsXML extends MigrateSource{
    public function __construct($options = array()) {
        $states = locality::$states;
        $this->states = $states;
        foreach($states as $st => $name){
            $feed = simplexml_load_file(drupal_get_path('module','greatschools').'/feed/local-greatschools-feed-'.$st.'.xml');
            foreach($feed->school as $district){
                //print_r($district);die();
                $ret = new stdClass();
                $ret->id = (string)$district->{'universal-id'};
                $ret->name = (string)$district->name;
                $ret->city = (string)$district->city;
                $ret->lat = (string)$district->lat;
                $ret->lon = (string)$district->lon;
                $ret->geom = 'POINT('.$ret->lon.' '.$ret->lat.')';
                $ret->body = (string)$district->description;
                $ret->county = $this->lookupCounty((string)$district->fipscounty,$st);
                $ret->districtid = (string)$district->{'universal-district-id'};
                $ret->enrollment = (string) $district->{'census-info'}->enrollment->value;
                $ret->level = (string) $district->level;
                $ret->levelcode = (string) $district->level->code;
                $ret->type = (string) $district->type;
                $ret->subtype = (string) $district->subtype;
                $ret->address = (string) $district->street;
                $ret->citystatezip = (string)$district->city.', '.(string)$district->state.' '.(string)$district->zip;
                $ret->phone = (string) $district->phone;
                if($district->{'teacher-data'}){
                    foreach($district->{'teacher-data'} as $data){
                        //print_r($data);
                        //$ret->bachelors = (string) $district->
                    }
                }
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
            /*
            foreach($this->districts as $rid => $district){

                $this->districts->cityid = $this->lookupCity($this->districts[$rid]->city,$st);
            }
            /*$cityfeed = simplexml_load_file(drupal_get_path('module','greatschools').'/city-feed/local-greatschools-city-feed-'.$st.'.xml');
            foreach($cityfeed->city as $city){  }
            */
        }
    }
    function  lookupCity($name,$state=null){
        $cityLookupQuery = new EntityFieldQuery();
        $cityLookupQuery->entityCondition('entity_type','node')->entityCondition('bundle','city');
        //$cityLookupQuery->fieldCondition('title','value',$this->districts[$rid]->city);
        $cityLookupQuery->propertyCondition('title',$name);
        if($state != null){
            $statenid = $this->lookupState($state);
            $cityLookupQuery->fieldCondition('field_state','target_id',$statenid);
        }
        $cityLookup = $cityLookupQuery->execute();
        $nids = array_keys($cityLookup['node']);

        //$cityLookupQuery->
        print 'node:'.$nids[0]."\n";
        return $nids[0];
    }
    function lookupState($state){
        if(array_key_exists(strtoupper($state),locality::$states)){
            $stateLookupQuery = new EntityFieldQuery();
            $stateLookupQuery->entityCondition('entity_type','node')->entityCondition('bundle','state');
            $stateLookupQuery->fieldCondition('field_state_code','value',$state);
            $stateLookup = $stateLookupQuery->execute();
            if(count($stateLookup) == 1){
                $keys = array_keys($stateLookup['node']);
                //var_dump($keys);
                $stateNID = $keys[0];
            }
            return $stateNID;
        }
    }
    function lookupCounty($fipCode,$state){
        $countyNID = NULL;
        $stateNID = $this->lookupState($state);
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
        $ret['districtid'] = 'District ID Reference';
        $ret['type'] = 'School Type';
        $ret['subtype'] = 'School subtype';
        $ret['address'] = 'School Address';
        $ret['citystatezip'] = 'School city/state/zip line';
        $ret['phone'] = 'phone';
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
    function __toString(){ return 'Schools';}
}

class MigrateSchools extends Migration{
    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->source = new MigrateSourceGreatSchoolsSchoolsXML();
        $this->destination = new MigrateDestinationNode('schools');
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
        $this->addFieldMapping('field_school_district','districtid')->sourceMigration('gsDistricts');
        $this->addFieldMapping('field_greatschools_rating', 'rating');
        $this->addFieldMapping('field_school_enrollment','enrollment');
        $this->addFieldMapping('field_school_level','level');
        $this->addFieldMapping('field_school_level_code','levelcode');
        $this->addFieldMapping('field_school_type','type');
        $this->addFieldMapping('field_school_subtype','subtype');
        $this->addFieldMapping('field_school_address','address');
        $this->addFieldMapping('field_school_citystatezip','citystatezip');
        $this->addFieldMapping('field_school_phone','phone');
        $this->addFieldMapping('field_school_teacher_bachelors','bachelors');
        $this->addFieldMapping('field_school_teacher_licensed','licensed');
        //$this->addFieldMapping('field_place_ref','cityid');
    }
}
//drush php-eval 'foreach(locality::$states as $code => $name) { db_query("delete from url_alias where alias like ?",array($code."/%")); } '
