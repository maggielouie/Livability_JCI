<?php
global $title;
$c = getCityContext();

$title = 'Population of '.$c->title.', '.$c->state->title;
print citySectionInclude('stubs/ad728');

$mainBody .= $c->title.', '.$c->state->field_state_code['und'][0]['value'].' has a '.
    'population of '.number_format($c->field_population['und'][0]['value']).' according to 2012 U.S. Census data. ';
$cityPop = $c->field_population['und'][0]['value'];
$countyPop = $c->county->field_population['und'][0]['value'];
$cityPercentofCounty = $cityPop / $countyPop;

//todo find close cities within x miles to ascertain:
//todo smallest in set
//todo if current city is larger or smaller by population(larger/smaller by greater than half of set)
//todo pick by population to get first/last cities of the sorted set

//this sets the the views contextual filter for nearby cities view
global $currentCity;
$currentCity = $c;
$nearby = views_get_view('nearby_cities',true);
$nearby->execute('block');

$pos = 0;
foreach($nearby->result as $nid){
    $pos++;
    $nearbyCities[$nid->nid] = city_node_load($nid->nid);
    $population[$nid->nid] = $nearbyCities[$nid->nid]->field_population['und'][0]['value'];
}
$c->nearby = new stdClass();
$c->nearby->cities = $nearbyCities;
$c->nearby->populationLargeToSmall = $population;
arsort($c->nearby->populationLargeToSmall,SORT_NUMERIC);
$c->nearby->largestNearby = null;
$c->nearby->secondLargestNearby = null;
$c->nearby->smallestNearby = null;
$half = count($population)/2;
$pos = 0;
$c->cityIsLarge = false;
foreach($c->nearby->populationLargeToSmall as $nid=>$pop){
    $pos++;
    //$mainBody .= $c->nearby->cities[$nid]->title.' pop:'.$c->nearby->populationLargeToSmall[$nid].'<br>';

    if($nid == $c->nid){
        $position = $pos;
        if($pos < $half){
            $c->cityIsLarge = true;
        }else{ $c->cityIsLarge = false; }
    }else{
        if(!isset($c->nearby->largestNearby)){
            $c->nearby->largestNearby = $nid;
        }
        elseif(!isset($c->nearby->secondLargestNearby)){
            $c->nearby->secondlargestNearby = $nid;
        }

    }
    $c->nearby->smallestNearby = $nid;
}
//var_dump($population);
//todo larger cities nearby and/or smaller cities nearby


$mainBody .= 'Making up roughly '.number_format($cityPercentofCounty * 100,2).
    '% of the '.$c->county->name.' population, '.
    $c->title.' is one of the ';
if($c->cityIsLarge){ $mainBody .= 'larger';}else{ $mainBody .= 'smaller'; }
$mainBody .= ' cities in the region. '.
    'Of the surrounding cities '.$nearbyCities[$c->nearby->largestNearby]->title.
    ' is the largest with a population of '
    .number_format($nearbyCities[$c->nearby->largestNearby]->field_population['und'][0]['value'],0).', '.
    'while '.$nearbyCities[$c->nearby->smallestNearby]->title.
    ' is the smallest with only '.number_format($nearbyCities[$c->nearby->smallestNearby]->field_population['und'][0]['value'],0).
    ' residents. '.
    'A more detailed view of '.$c->title.'’s demographics shows the '.
    'age, race, gender and educational attainment of the city’s residents.';
print $mainBody;
print citySectionInclude('stubs/promote-city');

print citySectionInclude('real-estate/block-listing');