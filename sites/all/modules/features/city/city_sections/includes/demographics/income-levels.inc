<?php
global $title;
$c = getCityContext();
print citySectionInclude('stubs/ad728');
$title = 'Income levels in'.$c->title.' , '.$c->state->title;
print 'Income levels';

print citySectionInclude('stubs/promote-city');

print citySectionInclude('real-estate/block-listing');