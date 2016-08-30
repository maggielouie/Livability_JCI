<?php
global $title;
$c = getCityContext();
print citySectionInclude('stubs/ad728');
$title = $c->title.', '.$c->state->field_state_code['und'][0]['value'].' Demographics';
$mainBody = 'Of the '.$c->field_population['und'][0]['value'].' residents living within '.$c->title.','. $c->state->field_state_code['und'][0]['value'].', '.
    '[00.00]% are under the age of 18 and [00.00%] are over the age '.
    'of 65 making the city one of the younger/older populations in the State of '.$c->state->title.'. '.
    'The adult population of [City]. With [00.00]% of the population of '.$c->title.' being of ethnic or non-white descent,';
//todo determine criteria for diversity
$diverse = true;
if($diverse){ $mainBody .= 'it is a well diversified community.';}else{ $mainBody .= 'it is not very diversified community. ';}
print $mainBody;
print citySectionInclude('promote-city');

print citySectionInclude('real-estate/block-listing');