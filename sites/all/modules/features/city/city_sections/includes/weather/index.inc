<?php
global $title;
$c = getCityContext();
$title = 'Weather in '.$c->title.', '.$c->state->title;

print citySectionInclude('stubs/ad728');

print 'Weather Content';
print citySectionInclude('stubs/promote-city');

print citySectionInclude('real-estate/block-listing');