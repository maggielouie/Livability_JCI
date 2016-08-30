<?php
global $title;
$c = getCityContext();
print citySectionInclude('stubs/ad728');
$title = 'Cost of Living in '.$c->title.', '.$c->state->title;
print '[City], as part of [County] county, has a cost of living '.
    'index score of [#], which is about [00.00]% higher/lower than the national average. '.
    'Of the various categories calculated by the Council for Community and Economic Research, '.
    '[City] residents can expect to see [Category 1] '.
    'having the highest cost basis while [Category 2] '.
    'will tend to be the lowest. Within the surrounding counties, '.
    '[County] county appears to be the most affordable.';

print citySectionInclude('stubs/promote-city');

print citySectionInclude('real-estate/block-listing');