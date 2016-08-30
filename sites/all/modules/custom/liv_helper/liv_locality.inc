<?php

class locality {
    static $states = array('AL' => 'Alabama',
        'AK' => 'Alaska',
        'AZ' => 'Arizona',
        'AR' => 'Arkansas',
        'CA' => 'California',
        'CO' => 'Colorado',
        'CT' => 'Connecticut',
        'DE' => 'Delaware',
        'FL' => 'Florida',
        'GA' => 'Georgia',
        'HI' => 'Hawaii',
        'ID' => 'Idaho',
        'IL' => 'Illinois',
        'IN' => 'Indiana',
        'IA' => 'Iowa',
        'KS' => 'Kansas',
        'KY' => 'Kentucky',
        'LA' => 'Louisiana',
        'ME' => 'Maine',
        'MD' => 'Maryland',
        'MA' => 'Massachusetts',
        'MI' => 'Michigan',
        'MN' => 'Minnesota',
        'MS' => 'Mississippi',
        'MO' => 'Missouri',
        'MT' => 'Montana',
        'NE' => 'Nebraska',
        'NV' => 'Nevada',
        'NH' => 'New Hampshire',
        'NJ' => 'New Jersey',
        'NM' => 'New Mexico',
        'NY' => 'New York',
        'NC' => 'North Carolina',
        'ND' => 'North Dakota',
        'OH' => 'Ohio',
        'OK' => 'Oklahoma',
        'OR' => 'Oregon',
        'PA' => 'Pennsylvania',
        'RI' => 'Rhode Island',
        'SC' => 'South Carolina',
        'SD' => 'South Dakota',
        'TN' => 'Tennessee',
        'TX' => 'Texas',
        'UT' => 'Utah',
        'VT' => 'Vermont',
        'VA' => 'Virginia',
        'WA' => 'Washington',
        'WV' => 'West Virginia',
        'WI' => 'Wisconsin',
        'WY' => 'Wyoming',);
    static function stateCodeFromName($name){
        return array_search($name,locality::$states);
    }
    static function trimStateCensusClean($value){
        $cityState = explode(',', $value);
        if(count($cityState) > 1){
            $state = $cityState[1];
            $city = $cityState[0];
            return self::cleanCity($city);
        }else{
            return($value);
        }
    }
  static function mapFromName($value){
    $cityState = explode(',', $value);
    if(count($cityState) > 1){
      $state = $cityState[1];
      $city = $cityState[0];
      $splitCity = explode(" ",$city);
      if(count($splitCity) > 1){
        $thelast = array_pop($splitCity);
        //print $thelast.'the last'."\n";
        $newcity = implode(" ", $splitCity);
      }
      $mapname = $newcity.$state;
      return $mapname;
    }else{
      return($value);
    }
  }
    static function findState($string){
        $parts = explode(",",$string);
        if(count($parts) == 2){
            return $parts[1];
        }
        if(count($parts) > 0){
            foreach($parts as $part){
                if(strlen($part) == 2){
                    return $part;
                }
            }
        }
        $parts = explode(" ",$string);
        if(count($parts) > 0){
            return array_pop($parts);
        }
    }
    function cleanCity($city){
        $splitCity = explode(" ",$city);
        if(count($splitCity) > 1){
            $thelast = array_pop($splitCity);
            //print $thelast.'the last'."\n";
            return implode(" ", $splitCity);
        }
        return implode(" ",$splitCity);
    }
}