<?php

function liv_schools(){
    global $title;
    global $c;
    $c = getCityContext();
    //$ordinates = round($c->field_geo['und'][0]['lat'], 5).','.round($c->field_geo['und'][0]['lon'], 5) .'_20';
    $county = $c->county->nid;
    switch(arg(3)){
        case 'public-schools':
            $title = 'Public Schools in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];
            $schools= views_get_view_result('nearby_schools', 'block', $county);
            $public_schools = get_public_schools($schools);
            $schoolCounts = get_school_counts($public_schools);
            $largestSchools = get_largest_school($schoolCounts);
            $schoolDistricts = views_get_view_result('nearby_school_districts');
            $data = array('title' => $title,'c' => $c,'schools' => $public_schools,'schoolCounts' => $schoolCounts, 'nearbySchoolDistricts' => $schoolDistricts, 'largestSchools' => $largestSchools);
            $mainBody = citySectionInclude('schools/public-schools',$data);
            break;
        case 'private-schools':
            $schools= views_get_view_result('nearby_schools', 'block', $county);
            $schoolDistricts = views_get_view_result('nearby_school_districts');
            $privateSchools = getPrivateSchools($schools);
            $schoolCounts = get_school_counts($privateSchools);
            $largestSchools = get_largest_private_schools($privateSchools);
            $data = array('title' => $title,'c' => $c,'schools' => $privateSchools,'schoolCounts' => $schoolCounts, 'nearbySchoolDistricts' => $schoolDistricts, 'largestSchools' => $largestSchools);
            $mainBody = citySectionInclude('schools/private-schools',$data);
            break;
        case 'colleges':
//            $collegeQuery = db_query('select * from data_schools_college_enrollment');
            $mainBody = citySectionInclude('schools/colleges');
            break;
        default:
            $schoolDistricts = views_get_view_result('nearby_school_districts');
            $data = array('schoolDistricts' => $schoolDistricts);
            $mainBody = citySectionInclude('schools/index',$data);
    }
    drupal_set_title($title);
    return ($mainBody);
}

function schoolLevel($subtype,$level,$title=null){
    if($subtype != null){
        if($subtype == 'elementary' || $subtype == 'middle' || $subtype == 'high'){
            return $subtype;
        }else{
            //guess we can see if the string contains ele/middle/high
            if(stripos($subtype,'elementary')){
                return 'elementary';
            }elseif(stripos($subtype,'middle')){
                return 'middle';
            }elseif(stripos($subtype,'high')){
                return 'high';
            }
//            return $subtype;
        }
    }

    if($level != null){
        //split level on dash
        if(stripos($level,'K') == 1 || stripos($level,'K') === 0){
            $school_levels[] =  'elementary';
        }
        $levelParts = explode('-',$level);
        //old comment: PK-3, 5-9 is a great weird example...split on comma first? if split has only one part then it's normal
        if(is_numeric($level) || count($levelParts) >= 2){
            if(is_numeric($level)){
                $levelParts = array();
                $levelParts[0] = $level;
            }
            if($levelParts[0] == 'PK' || $levelParts[0] == 'K'){
                $school_levels[] =  'elementary';
            }elseif(is_numeric($levelParts[0])){
                if($levelParts[0] < 6){
                    $school_levels[] =  'elementary';
                }elseif($levelParts[0] < 8){
                    $school_levels[] =  'middle';
                }elseif($levelParts[0] <= 12){
                    $school_levels[] =  'high';
                }else{
                    //print 'unknown level:'.$levelParts[0];
                }
            }else{
                //print 'unknown level:'.$levelParts[0];
                $pieces = explode(',',$level);
                //print count($pieces);
                if(count($pieces) == 2){
                    foreach($pieces as $piece){
                        $pi = trim($piece);
                        //print '<br>pi:'.$pi.':level'.$level.'<br>';
                        //print_r($piece);
                    }
                }else{
                    $pieces = explode('-',$level);
                    //print_r($pieces);
                }
            }
        }else{

            if($level == 'n/a'){
                return('n/a');
            }else{
                //print $level;
                //print 'unknown level:'.$level;
            }
        }
    }
}

function get_school_counts($schools) {
    $highschools = array();
    $middleschools = array();
    $elemschools = array();
    foreach ($schools as $school) {
        $subtype = implode(',', $school->level_code);
        if (strpos($subtype,'high') !== FALSE) {
            $highschools[] = array('name' => $school->node_title, 'enrollment' => $school->field_field_school_enrollment[0]['raw']['value']);
        }
        if (strpos($subtype, 'middle') !== FALSE) {
            $middleschools[] = array('name' => $school->node_title, 'enrollment' => $school->field_field_school_enrollment[0]['raw']['value']);
        }
        if (strpos($subtype, 'elem') !== FALSE) {
            $elemschools[] = array('name' => $school->node_title, 'enrollment' => $school->field_field_school_enrollment[0]['raw']['value']);
        }
    }
    $schoolCounts['high'] = $highschools;
    $schoolCounts['middle'] = $middleschools;
    $schoolCounts['elem'] = $elemschools;
    return $schoolCounts;
}
function get_largest_school($schools) {
  $highschools = $schools['high'];
  $middleschools = $schools['middle'];
  $elemschools = $schools['elem'];

  usort($highschools, 'schoolSort');
  usort($middleschools, 'schoolSort');
  usort($elemschools, 'schoolSort');
  $largest_schools = array('high' => array_shift($highschools), 'middle' => array_shift($middleschools), 'elem' => array_shift($elemschools));
  return $largest_schools;
}

function schoolSort($a, $b) {
    return $a['enrollment'] < $b['enrollment'];
};

function getPrivateSchools($schools) {
    $private_Schools = array();
    foreach ($schools as $school) {
        if ($school->field_field_school_type[0]['raw']['value'] == 'private') {
            $school->level_code = getSchoolLevel($school->field_field_school_level[0]['raw']['value']);
            $private_schools[] = $school;
        }
    }
    return $private_schools;
}


function get_largest_private_schools($schools) {
  $highschools = array();
  $middleschools = array();
  $elemschools = array();
  foreach ($schools as $school) {
    $level = $school->field_field_school_level[0]['raw']['value'];
    $level_code = getSchoolLevel($level);
    $school->level_code = $level_code;
    if (in_array('elementary',$level_code)) {
      $elemschools[] = array('name' => $school->node_title, 'enrollment' => $school->field_field_school_enrollment[0]['raw']['value']);
;
    }
    if (in_array('middle', $level_code)) {
      $middleschools[] = array('name' => $school->node_title, 'enrollment' => $school->field_field_school_enrollment[0]['raw']['value']);
    }
    if (in_array('high', $level_code)) {
      $highschools[] = array('name' => $school->node_title, 'enrollment' => $school->field_field_school_enrollment[0]['raw']['value']);
    }
  }
  usort($highschools, 'schoolSort');
  usort($middleschools, 'schoolSort');
  usort($elemschools, 'schoolSort');

  $largest_schools = array('high' => array_shift($highschools), 'middle' => array_shift($middleschools), 'elem' => array_shift($elemschools));
  return $largest_schools;
}

function getSchoolLevel($level) {
  if ($level != NULL) {
    $level_parts = explode('-', $level);
    if ($level_parts[0] == 'PK' || $level_parts[0] == 'K' || $level_parts[0] == '1') {
      $school_level[] = 'elementary';
      if ($level_parts[1] == '12') {
        $school_level[] = 'middle';
        $school_level[] = 'high';
    } elseif ((int)$level_parts[1] < 12) {
      $school_level[] = 'middle';
    }

    } elseif ((int)$level_parts[1] < 5 && !$school_level[0]) {
      $school_level[] = 'elementary';

    } elseif ((int)$level_parts[1] > 4 && (int)$level_parts[1] < 10 ) {
      $school_level[] = 'middle';
    } elseif ((int)$level_parts[1] == 12) {
        $school_level[] = 'high';
    }

  }
  return $school_level;
}

function get_public_schools($schools) {
    $public_schools = array();
    foreach ($schools as $school) {
        if ($school->field_field_school_type[0]['raw']['value'] == 'public') {
            $school->level_code = getSchoolLevel($school->field_field_school_level[0]['raw']['value']);
            $public_schools[] = $school;
        }
    }
    return $public_schools;
}
