<?php
global $title;
$title = 'Business and Economy in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];
print '<div class="city-topic-summary padded">';
print citySectionInclude('stubs/ad728');
print '<h1>'.$title.'</h1>';
$unemployed = str_replace(',','',$countyLabor['Unemployed']);
$employed = str_replace(',','',$countyLabor['Employed']);
$unemployment = number_format($employed/$unemployed,0);
$numberOne = key($industries);
$county = $c->county->title;



print '<p>Being a great place to live also means being a great place to work. A thriving economy helps the tax base '.
    '(so there’s more money for city improvements) and helps a city attract and retain talent. ';
    /*'The economy in '.$c->title.'&#39;s '.
	$county .
	'is led by the ';
print $naics[$numberOne];
//var_dump($numberOne);
    //[leading industry]
print ' industry, which accounts for '.number_format($industries[$numberOne]/$employed*100,1).'% of the jobs in the area. ';
print 'Other top employment sectors include ';
next($industries);
$numberTwo = key($industries);
print trim($naics[$numberTwo]).', ';
next($industries);
$numberThree = key($industries);
print trim($naics[$numberThree]) . ' and ';
next($industries);
$numberFour = key($industries);
print trim($naics[$numberFour]).'. ';

// print 'The unemployment in '.$c->county->name.', where '.$c->title.' is located is '.
//    $unemployment.'%.';
//, which is higher/lower than the national rate and is in the [quartile] for the state.';*/
print '</p></div>';

print citySectionInclude('stubs/promote-city');

print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Business',$c,0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Business in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Business'));
}
print citySectionInclude('real-estate/block-listing');

print citySectionInclude('stubs/ad728bottom');