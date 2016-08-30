<?php

class placeData{
    private $data;
    private $dataname;
    function __construct($name,$data,$keys){
        $this->dataname = $name;
        foreach ($data as $k => $val) {
            $this->{$keys[$k]} = $val;
        }
        $cacheFilePath = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'place'.
            DIRECTORY_SEPARATOR.$this->state.DIRECTORY_SEPARATOR.$this->place.'.json';
        if(file_exists($cacheFilePath)){
            $frozen = json_decode(file_get_contents($cacheFilePath),true);
            if(array_key_exists($this->dataname,$frozen)){
                if($frozen[$this->dataname] !== $this->data[$this->dataname]){
                    $frozen[$this->dataname] = $this->data[$this->dataname];
                    $this->data = $frozen;
                    $fp = file_put_contents($cacheFilePath,json_encode($this->data));
                }
            }else{
                $frozen[$this->dataname] = $this->data[$this->dataname];
                $this->data = $frozen;
                $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            }
        }else{
            $placedir = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'place';
            print($placedir);
            if(!is_dir($placedir)){
                mkdir($placedir);
            }
            $statedir = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'place'.
                DIRECTORY_SEPARATOR.$this->state;
            if(!is_dir($statedir)){
                mkdir($statedir);
            }
            $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            if($fp !==false){
                print 'wrote cache for state:'.$this->state.' place:'.$this->place;
            }
        }

    }
    function __set($key,$val){
        //print 'k:'.$key.':val:'.$val."\r\n";
        if ($key == 'DP04_0088E') {
            // Sanitize to prevent non-numerical values.
            $val = filter_var($val,FILTER_SANITIZE_NUMBER_INT);
        }
        $this->data[$this->dataname][$key] = $val;
    }
    function __get($key){
        return $this->data[$this->dataname][$key];
    }
}

class metroData{
    private $data;
    private $dataname;
    function __construct($name,$data,$keys){
        $this->dataname = $name;
        foreach ($data as $k => $val) {
            $this->{$keys[$k]} = $val;

        }
        $cacheFilePath = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'metro'.
            DIRECTORY_SEPARATOR.$this->metro.'.json';
        if(file_exists($cacheFilePath)){
            $frozen = json_decode(file_get_contents($cacheFilePath),true);
            if(array_key_exists($this->dataname,$frozen)){
                if($frozen[$this->dataname] !== $this->data[$this->dataname]){
                    $frozen[$this->dataname] = $this->data[$this->dataname];
                    $this->data = $frozen;
                    $fp = file_put_contents($cacheFilePath,json_encode($this->data));
                }
            }else{
                $frozen[$this->dataname] = $this->data[$this->dataname];
                $this->data = $frozen;
                $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            }
        }else{
            $placedir = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'metro';
            print($placedir);
            if(!is_dir($placedir)){
                mkdir($placedir);
            }
            $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            if($fp !==false){
                print 'wrote cache for metro: '.$this->place;
            }
        }

    }
    function __set($key,$val){
        //print 'k:'.$key.':val:'.$val."\r\n";
        $this->data[$this->dataname][$key] = $val;
    }
    function __get($key){
        return $this->data[$this->dataname][$key];
    }
}

class countyData{
    private $data;
    private $dataname;
    function __construct($name,$data,$keys){
        $this->dataname = $name;
        foreach ($data as $k => $val) {
            $this->{$keys[$k]} = $val;
        }
        $cacheFilePath = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'county'.
            DIRECTORY_SEPARATOR.$this->state.DIRECTORY_SEPARATOR.$this->county.'.json';
        if(file_exists($cacheFilePath)){
            $frozen = json_decode(file_get_contents($cacheFilePath),true);
            if(array_key_exists($this->dataname,$frozen)){
                if($frozen[$this->dataname] !== $this->data[$this->dataname]){
                    $frozen[$this->dataname] = $this->data[$this->dataname];
                    $this->data = $frozen;
                    $fp = file_put_contents($cacheFilePath,json_encode($this->data));
                }
            }else{
                $frozen[$this->dataname] = $this->data[$this->dataname];
                $this->data = $frozen;
                $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            }
        }else{
            $countydir = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'county';
            print($countydir);
            if(!is_dir($countydir)){
                mkdir($countydir);
            }
            $statedir = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'county'.
                DIRECTORY_SEPARATOR.$this->state;
            if(!is_dir($statedir)){
                mkdir($statedir);
            }
            $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            if($fp !==false){
                print 'wrote cache for state:'.$this->state.' place:'.$this->county;
            }
        }

    }
    function __set($key,$val){
        //print 'k:'.$key.':val:'.$val."\r\n";
        $this->data[$this->dataname][$key] = $val;
    }
    function __get($key){
        return $this->data[$this->dataname][$key];
    }
}
class stateData{
    private $data;
    private $dataname;
    function __construct($name,$data,$keys){
        $this->dataname = $name;
        foreach ($data as $k => $val) {
            $this->{$keys[$k]} = $val;
        }
        $cacheFilePath = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'state'.
            DIRECTORY_SEPARATOR.$this->state.'.json';
        if(file_exists($cacheFilePath)){
            $frozen = json_decode(file_get_contents($cacheFilePath),true);
            if(array_key_exists($this->dataname,$frozen)){
                if($frozen[$this->dataname] !== $this->data[$this->dataname]){
                    $frozen[$this->dataname] = $this->data[$this->dataname];
                    $this->data = $frozen;
                    $fp = file_put_contents($cacheFilePath,json_encode($this->data));
                }
            }else{
                $frozen[$this->dataname] = $this->data[$this->dataname];
                $this->data = $frozen;
                $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            }
        }else{
            $placedir = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'state';
            if(!is_dir($placedir)){
                mkdir($placedir);
            }
            $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            if($fp !==false){
                print 'wrote cache for state:'.$this->state.' place:'.$this->place;
            }
        }

    }
    function __set($key,$val){
        //print 'k:'.$key.':val:'.$val."\r\n";
        $this->data[$this->dataname][$key] = $val;
    }
    function __get($key){
        return $this->data[$this->dataname][$key];
    }
}



class usData{
    private $data;
    private $dataname;
    function __construct($name,$data,$keys){
        $this->dataname = $name;
        foreach ($data as $k => $val) {
            $this->{$keys[$k]} = $val;
        }
        $cacheFilePath = drupal_get_path('module','census_cache').DIRECTORY_SEPARATOR.'cache'.DIRECTORY_SEPARATOR.'national.json';
        if(file_exists($cacheFilePath)){
            $frozen = json_decode(file_get_contents($cacheFilePath),true);
            if(array_key_exists($this->dataname,$frozen)){
                if($frozen[$this->dataname] !== $this->data[$this->dataname]){
                    $frozen[$this->dataname] = $this->data[$this->dataname];
                    $this->data = $frozen;
                    $fp = file_put_contents($cacheFilePath,json_encode($this->data));
                }
            }else{
                $frozen[$this->dataname] = $this->data[$this->dataname];
                $this->data = $frozen;
                $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            }
        }else{
            $fp = file_put_contents($cacheFilePath,json_encode($this->data));
            if($fp !==false){
                print 'wrote cache for us:'.$this->state.' place:'.$this->place."\n";
            }
        }

    }
    function __set($key,$val){
        //print 'k:'.$key.':val:'.$val."\r\n";
        $this->data[$this->dataname][$key] = $val;
    }
    function __get($key){
        return $this->data[$this->dataname][$key];
    }
}

class censusAPI{
    var $url = 'http://api.census.gov/data/2014/acs5/';
    var $key = '3d9521af9c510f2beea74ce6f3b599b38bc50de9';
    var $raw = array();

    public function __construct($name,$vars,$type = 'profile',$geography = 'place'){
        $this->name = $name;
        $this->geography = $geography;
        $this->fetch($type,$vars);
        return($this->raw);
    }
    private function fetch($type,$vars)
    {
        if($type != '') {
            $url = $this->url . $type . '/';
        }else{
            $url = $this->url;
        }
        $req = implode(',',array_keys($vars));
        $url = $url.'?get='.$req.'&for='.$this->geography.':*';
        if($this->geography != 'us' || $this->geography != "metropolitan+statistical+area/micropolitan+statistical+area"){
            $url = $url.'&in=state:*';
        }
        $url = $url.'&key='.$this->key;

        $raw = json_decode(file_get_contents($url));
        $this->keys = array_shift($raw);
        $place_key = array_pop($this->keys);
        if ($place_key == 'metropolitan statistical area/micropolitan statistical area') {
          $this->keys[] = 'metro';
        } else {
          $this->keys[] = $place_key;
        }
        foreach ($raw as $i => $obj) {
            if($this->geography == 'place') {
                new placeData($this->name, $obj, $this->keys);
            }
            if($this->geography == 'state'){
                new stateData($this->name,$obj,$this->keys);
            }
            if($this->geography == 'us'){
                new usData($this->name,$obj,$this->keys);
            }
            if($this->geography == 'county') {
                new countyData($this->name,$obj,$this->keys);
            }
            if($this->geography == 'metropolitan+statistical+area/micropolitan+statistical+area') {
              new metroData($this->name,$obj,$this->keys);
            }
        }
    }
}
