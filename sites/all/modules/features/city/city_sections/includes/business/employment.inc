<?php
global $title;
$c = getCityContext();
$title = 'Employment in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'];
$data = $c->census['city-add-data'];
if (!empty($c->field_employed[LANGUAGE_NONE][0]['value'])) {
  $employed = $c->field_employed[LANGUAGE_NONE][0]['value'];
} else {
  $employed = $data['DP03_0004E'];
}
if (!empty($c->field_unemployed[LANGUAGE_NONE][0]['value'])) {
  $unemployed = $c->field_unemployed[LANGUAGE_NONE][0]['value'];
} else {
  $unemployed = $data['DP03_0005E'];
}
if (!empty($c->field_employed_armed_forces[LANGUAGE_NONE][0]['value'])) {
  $armedforces = $c->field_employed_armed_forces[LANGUAGE_NONE][0]['value'];
} else {
  $armedforces = $data['DP03_0006E'];
}

print '<div class="city-topic-summary padded">';
print citySectionInclude('stubs/ad728');
print '<h1>'.$title.'</h1>';
print 'While employment opportunities often play a big part in why people move, a city’s unemployment rate also is a major indicator of an economy’s overall health. Regardless of whether personal employment is a factor, lower unemployment rates often mean a region is better able to attract and retain skilled workers, new industries and retailers. See below for a statistical snapshot of employment in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] .'.';

//print 'Unemployment in '.$c->county->name.' where '.$c->title.' is located has been ';
//rising/falling faster/slower than nearby [county], [county] and the state of [state].
//print 'During this period, the national unemployment rate is [national rate]. ';
//print 'Overall, [adult workforce]% of [City Name] adult residents are in the labor force. ';

//print $c->field_unemployed[LANGUAGE_NONE][0]['value'].':'.$c->field_employed[LANGUAGE_NONE][0]['value'];
print '<br>';
print '<ul class="infograph clearfix">';
print '<li class="two-third">';
print '<span class="large-value blue">';
print number_format($unemployed / $employed * 100, 2);
print '%</span>';
print '<span class="description">Unemployment in '.$c->title.'</span>';

print '<h1>Employment Data</h1>';
print '<span class="large-value blue">';
print number_format($employed,0);
print '</span>';
print '<span class="description">Total Employed</span>';
print '<br>';
print '<br>';
print '<span class="large-value blue">';
print number_format($unemployed,0);
print '</span>';
print '<span class="description">Total Unemployed</span>';
print '<br>';
print '<br>';
print '<span class="large-value blue">';
print number_format($armedforces,0);
print '</span>';
print '<span class="description">Total Armed Forces</span>';

print '</li>';
print '<li class="one-third">';
$nearby = views_get_view_result('nearby_cities');
$nearby = array_slice($nearby,0,4);
foreach($nearby as $city){
    $cityNode = getCityContext($city->nid);
    $alias =drupal_get_path_alias('node/'.$city->nid);
    print '<span><a href="/'.$alias.'/business/employment">'.$cityNode->title;
    if($cityNode->field_state[LANGUAGE_NONE][0]['target_id'] == $c->field_state[LANGUAGE_NONE][0]['target_id']){
        print ', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</span>';
    }else{
        $st = node_load($cityNode->field_state[LANGUAGE_NONE][0]['target_id']);
        print ', '.$st->field_state_code[LANGUAGE_NONE][0]['value'].'</span>';
    }
    print '</a>';
    $p = number_format($cityNode->census['city-add-data']['DP03_0005E']/$cityNode->census['city-add-data']['DP03_0004E']*100,2);
    print '<span class="small-value">'.$p.'%</span>';
    print '<span class="fill-bar"></span>';
    print '<span class="fill-bar" style="background-color:#7cc242;position:relative;top:-20px;width:' . $p . '%;"></span>';
}
print '</li>';
print '</ul>';
print '<span class="description">Source: Source: U.S. Census Bureau 2014 American Community Survey 5-year estimates</span>';
print '</div>';
print '<br>';
print citySectionInclude('stubs/promote-city');

print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Business',$c,0);
$heading = 'Articles related to <b>Business in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Business'));

print citySectionInclude('real-estate/block-listing');

print citySectionInclude('stubs/ad728bottom');
