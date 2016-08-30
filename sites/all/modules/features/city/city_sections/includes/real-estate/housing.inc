<?php
global $title;
$mainBody='';
$c = getCityContext();
$title = 'Housing and Housing Statistics in '.
    $c->title.', '.
    $c->state->field_state_code['und'][0]['value'];

// print citySectionInclude('stubs/ad728');
print '<div class="city-topic-summary padded">';
$census = $c->census['real-estate'];
print '<h1>'.$title.'</h1><p>Housing is often the largest expense we face each month. '.
    'The average monthly home ownership costs for owners with a mortgage in '.$c->title.' is $'. number_format($census['DP04_0100E']).
    ', which is ';
    if($c->nation['real-estate']['DP04_0107E'] > $census['DP04_0107E']) {
        print 'lower';
    }else {
        print 'higher';
    }
print ' than the nation as a whole. '.
    'The average monthly rent in '.$c->title.' is $'.number_format($census['DP04_0132E'],0).', which is ';
    if($c->nation['real-estate']['DP04_0132E'] >$census['DP04_0132E']){
        print 'lower';
    }else{
        print 'higher';
    }
    print ' than the U.S. '.
    'Approximately '.number_format($census['DP04_0045E'],0).' housing units are owner-occupied. '.
    'About '.
    number_format(($census['DP04_0109E'] + $census['DP04_0110E'] + $census['DP04_0111E'])/$census['DP04_0108E']*100,1).'% of owners and '.
    number_format(($census['DP04_0135E'] + $census['DP04_0136E'] + $census['DP04_0137E'] + $census['DP04_0138E'])/$census['DP04_0134E']*100,1).'% of renters pay less than 30% of their income '.
    'toward housing expenses, a measure of affordability. '.
    'Owners make up  '.number_format($census['DP04_0045E']/$census['DP04_0037E']*100,1).'% of housing units. '.
    number_format($census['DP04_0046E']/$census['DP04_0037E']*100,1).'% of the housing units are occupied by renters. '.
    number_format(($census['DP04_0050E']+$census['DP04_0051E']+$census['DP04_0052E'])/$census['DP04_0049E']*100,1).
    '% of homes in '.$c->title.' were built after 1990. '.
    number_format(($census['DP04_0041E']+$census['DP04_0042E']+$census['DP04_0043E'])/$census['DP04_0037E']*100,1).'% of all housing units in '.$c->title.' have three bedrooms or more.'.
    '</p>';

print '<ul class="clearfix infograph">
			<li class="one-third">
            <h4><span class="red">Own their own homes</h4>'.
    '<span class="large-value red">'.
    number_format($c->census['real-estate']['DP04_0045E'],0).'</span>'.
    '</li>
    <li class="one-third">
    <h4><span class="blue">Median home price</h4>'.
    '<span class="large-value blue">$'.number_format($c->census['real-estate']['DP04_0088E'],0).
    '</li>
<li class="one-third">
<h4><span class="orange">Median monthly mortgage</h4>'.
    '<span class="large-value orange">$'.
    number_format($c->census['real-estate']['DP04_0100E'],0).'</span>'.
    '</li></ul>';

print '</div>';
print citySectionInclude('stubs/promote-city');

print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Housing',$c,0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Housing in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>$content->terms));
}
print citySectionInclude('real-estate/block-listing');

print citySectionInclude('stubs/ad728bottom');
