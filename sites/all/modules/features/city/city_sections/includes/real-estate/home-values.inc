<?php
global $title;
$c = getCityContext();
$title ='Home Values in '.$c->title.', '.
    $c->state->field_state_code['und'][0]['value'];
//var_dump($c->county);
// print citySectionInclude('stubs/ad728');
$census = $c->census['real-estate'];
$percentage_output = ($census['DP04_0085E'] + $census['DP04_0086E']+$census['DP04_0087E'])/$census
['DP04_0079E']*100 <= 5 ? 'Very few ' : 'About ' . number_format(($census['DP04_0085E'] + $census['DP04_0086E']+$census['DP04_0087E'])/$census['DP04_0079E']*100,1) . '% of ';
print '<div class="city-topic-summary padded"><h1>'.$title.'</h1><p>'
    .'The median home value as of 2012 is $'.
    number_format($c->census['real-estate']['DP04_0088E'],0).'. '.
    //' compared to [median home value metro] '.
    //'for the metro area (if applicable, use county if not) and [median home value state] for the state. '.
    $percentage_output.'homes cost more than $500,000 while '.number_format(($census['DP04_0080E']+$census['DP04_0081E']+$census['DP04_0082E'] + $census['DP04_0083E'])/$census['DP04_0079E']*100).'% cost less than '.
    '$200,000. In '.$c->title.', owners occupy about '.number_format($census['DP04_0045E']/$census['DP04_0037E']*100,0).'% of homes. '.
    'Renters make up '.
    number_format($census['DP04_0046E']/$census['DP04_0037E']*100,1).'% of households.';
    //'A typical home here has [bedrooms] bedrooms and typical home-owners in '.$c->title.' have lived '.
    //'in their home for [ave. years.]</p></div>';
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