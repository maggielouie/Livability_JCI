<?php
global $title;
$c = getCityContext();
$county = $c->county->title;

$title = 'Top Industries in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];
print '<div class="city-topic-summary padded">';
print '<h1>'.$title.'</h1>';
/*
print '<p>The top industry in '.$c->title.'&#39;s '.
	$county .
    'is the ';
$numberOne = key($industries);
print $naics[$numberOne];
$employed = str_replace(',','',$countyLabor['Employed']);
//[leading industry]
print ' industry with '.number_format($industries[$numberOne]/$employed*100,1).'% of all workers in '.
    $c->title.' employed in this sector.  Other leading employment sectors for '.$c->title.
	' include ';
next($industries);
$numberTwo = key($industries);
print trim($naics[$numberTwo]).', ';
next($industries);
$numberThree = key($industries);
print trim($naics[$numberThree]).', and ';
next($industries);
$numberFour = key($industries);
print trim($naics[$numberFour]).'. ';
//print '[#2], [#3], and [#4]. ';
//print 'Wages in '.$c->title.' are '; //TODO compare to nation avg [higher/lower] than the nation
//print 'with a median household income of [National Income]. ';
*/
print 'There are '.number_format($sums['fiveless']+$sums['tenless'],0).' business establishments in '.
    $c->title.'&#39;s '.
	$county .
	'with fewer than 10 employees, '.
    'which is a good indicator of the entrepreneurship in the community. Another '.
    number_format($sums['twentyless']+$sums['fiftyless'],0).' business have between 10 and 50 employees, '.
    number_format($sums['hundredless']+$sums['twofifty'],0).' have between 50 and 250, and '.
    number_format($sums['fivehundredless']+$sums['thousandless']+$sums['thousand'],0).' businesses have more than 250 employees.</p>';

print '</div>';
print citySectionInclude('stubs/promote-city');

print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Business',$c,0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Business in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Business'));
}

print citySectionInclude('real-estate/block-listing');

print citySectionInclude('stubs/ad728bottom');

