<?php
global $title;
$c = getCityContext();
// print citySectionInclude('stubs/ad728');
$title = 'Real Estate in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];
print citySectionInclude('stubs/ad728');
/* MADLIB */
print '<div class="city-topic-summary padded">';
$nationalMedian = $c->nation['real-estate']['DP04_0088E'];

print '<h1>'.$title.'</h1><p>Once you’ve found your best place to live, how do you find a home there? '.
    'Below are selected listings of homes for sale in '.$c->title.' from our partner, Trulia. '.
    'To give you a sense of the overall real estate market in the area, the median home price in '.$c->title.' is $'.
    number_format($c->census['real-estate']['DP04_0088E'],0).', which is ';
    if($nationalMedian > $c->census['real-estate']['DP04_0088E']){
        print 'lower';
    }else{
        print 'higher';
    }
print ' than the national median. '.
    'There are '.number_format($c->census['real-estate']['DP04_0006E'],0).' housing units in '.$c->title.'. '.
    'Approximately '.number_format($c->census['real-estate']['DP04_0045E'],0).
    ' are owner-occupied and '.number_format($c->census['real-estate']['DP04_0046E'],0).
	' are occupied by renters. Find your perfect home by searching the listings below for housing values and details about homes in '.$c->title.'.</p>';
print '<ul class="clearfix infograph">
			<li class="one-third">
            <h4>Own their own homes</h4>'.
    '<span class="large-value red">'.
    number_format($c->census['real-estate']['DP04_0045E'],0).'</span>'.
    '</li>
    <li class="one-third">
    <h4>Median home price</h4>'.
    '<span class="large-value blue">$'.number_format($c->census['real-estate']['DP04_0088E'],0).
    '</li>
<li class="one-third">
<h4>Median monthly mortgage</h4>'.
    '<span class="large-value orange">$'.
    number_format($c->census['real-estate']['DP04_0100E'],0).'</span>'.
    '</li>
    </ul>';

print '<span class="description-small grey">';
print 'Source: U.S. Census Bureau, 2008-2012 American Community Survey</span>';

print '</div>';
/* TRULIA WIDGET */
print citySectionInclude('real-estate/block-listing-a');

/* Grabbing some data from Trulia
$url = 'http://api.trulia.com/webservices.php?library=TruliaStats&function=getCityStats&city='.urlencode($c->title).'&state='.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'&statType=listings&startDate=2014-08-01&endDate=2014-10-03&apikey=236frv8jbe99qt35ymp5fzpk';
$result = simplexml_load_file($url);
krumo($result);
*/

print citySectionInclude('stubs/promote-city');

print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Real Estate',$c,0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Real Estate in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>$content->terms));
}
print citySectionInclude('stubs/ad728bottom');
