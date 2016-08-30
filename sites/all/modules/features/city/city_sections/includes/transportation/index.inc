<?php
global $title;
$c = getCityContext();
$title = 'Transporation';

print citySectionInclude('stubs/ad728');

print 'Transportation section';

print citySectionInclude('stubs/promote-city');

print citySectionInclude('real-estate/block-listing');