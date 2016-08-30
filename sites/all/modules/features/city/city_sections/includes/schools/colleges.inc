<?php
global $title;
$c = getCityContext();
$title = 'Colleges in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'].
    ' - Private School Ratings';
print '<div class="city-topic-summary padded">';
print citySectionInclude('stubs/ad728');
print '<h1>'.$title.'</h1>';
$queryString = 'select * from data_schools_college_enrollment enrollment join data_schools_accreditation schools'.
    '  on enrollment.InstID=schools.InstID where schools.CampStateAbbrev=?'.
    ' and CampCity like ? order by Enroll_Fall2012 DESC';
$collegeQuery = db_query($queryString,array($c->state->field_state_code[LANGUAGE_NONE][0]['value'],
    '%'.$c->title.'%'));
print_r($collegeQuery->fetchAssoc());
print '<br>count:'.$collegeQuery->rowCount().'<br>';

if($collegeQuery->rowCount() == 0){
    print '<h2>No local colleges found. Check nearby cities to see if there are some in the area.</h2>';
}else{
print 'Colleges and universities play an integral role '.
    'in the economy, culture and livability of any community in which they are present. '.
    '<# of colleges in city> accredited colleges call <city> home with a total of '.
    '<# colleges in range> colleges within 50 miles. '.
    'These post-graduate institutions provide ample opportunities to earn degrees across an '.
    'array of subject areas. The largest area college is '.
    '<largest college>, which, as of <year>, had an enrollment of <# students at largest college> '.
    'students with <% full time> percent being full time.';
}
print '</div>';
print citySectionInclude('stubs/promote-city');

$content = getContentByTermAndPlace('Schools',$c,0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Schools in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>$content->terms));
}
print citySectionInclude('real-estate/block-listing');