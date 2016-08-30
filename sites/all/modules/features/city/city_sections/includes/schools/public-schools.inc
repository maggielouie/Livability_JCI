<?php

$add_data = $c->census['city-add-data'];

$ed_enrollment_prek = $add_data['DP02_0053E'];
$ed_enrollment_kind = $add_data['DP02_0054E'];
$ed_enrollment_elem = $add_data['DP02_0055E'];
$ed_enrollment_high = $add_data['DP02_0056E'];
$ed_enrollment_col = $add_data['DP02_0057E'];


$schoolCounts['elem'] = count($schoolCounts['elem']);
$schoolCounts['middle'] = count($schoolCounts['middle']);
$schoolCounts['high'] = count($schoolCounts['high']);

$districts = array();
$totalenrollment = 0;
if (isset($ed_enrollment_prek)) {
	$totalenrollment += $ed_enrollment_prek;
}
if (isset($ed_enrollment_kind)) {
	$totalenrollment += $ed_enrollment_kind;
}
if (isset($ed_enrollment_elem)) {
	$totalenrollment += $ed_enrollment_elem;
}
if (isset($ed_attainment_high)) {
	$totalenrollment +=$ed_enrollment_high;
}
if (isset($ed_enrollment_col)) {
	$totalenrollment += $ed_enrollment_col;
}

// load the district node, query for district enrollment, tabulate total enrollment
if (count($nearbySchoolDistricts) > 0) {
	$districtEnrollment = 0;
	foreach ($nearbySchoolDistricts as $district) {
		$districts[$district->nid] = array();
		$districts[$district->nid]['node'] = node_load($district->nid);
		$districts[$district->nid]['name'] = $district->node_title;
		$districts[$district->nid]['enrollment'] = 0;
		$schoolq = 'SELECT SUM(en.field_school_enrollment_value) as enrollment from {node} n ';
		$schoolq .= 'LEFT JOIN {field_data_field_school_enrollment} en on en.entity_id = n.nid ';
		$schoolq .= 'LEFT JOIN {field_data_field_school_district} dis on dis.entity_id = n.nid ';
		$schoolq .= 'LEFT JOIN {field_data_field_school_type} typ on typ.entity_id = n.nid ';
		$schoolq .= 'WHERE n.type = \'schools\' ';
		$schoolq .= 'AND typ.field_school_type_value = \'public\' ';
		$schoolq .= 'AND dis.field_school_district_target_id = :sdid';
		$schoolQueryResult = db_query($schoolq, array(':sdid' => $district->nid));
		foreach($schoolQueryResult as $school) {
			$districts[$district->nid]['enrollment'] += $school->enrollment;
			$districtEnrollment += $school->enrollment;
		}
	}
}
// tabulate percentage enrollment per district
foreach ($districts as $dnid => $district) {
	$districts[$dnid]['servicepercent'] = round($district['enrollment']/$districtEnrollment*100);
}
// sort districts array so the largest/highest percentage is first
function cmp($a, $b) {
	if ($a['enrollment'] == $b['enrollment']) {
		return 0;
	}
	return ($a['enrollment'] > $b['enrollment']) ? -1 : 1;
}
uasort($districts, 'cmp');

// $districts = array_slice($districts,0,4);

/* OUTPUT START */
print '<div class="city-topic-summary schools public-schools padded">';
print citySectionInclude('stubs/ad728');
print '<h1>'.$title.'</h1>';
print '<p>There ' . format_plural($schoolCounts['elem'], 'is ', 'are ') . $schoolCounts['elem'] . ' public elementary ' . format_plural($schoolCounts['elem'], 'school', 'schools') . ' in ' . $c->title .  ', ';
$primarydistrict = FALSE;
$diter = 0;
foreach($districts as $dnid => $district) {
	$diter++;
	if ($district['servicepercent'] >= 95) {
		$primarydistrict = TRUE;
		print 'part of the ' . $district['name'] . ' district. ';
	}
	elseif ($district['servicepercent'] >= 60 && $district['servicepercent'] < 95) {
		$primarydistrict = TRUE;
		print 'primarily served by ' . $district['name'] . ' district. ';
	}
	elseif ($primarydistrict == FALSE && $diter == 1) {
		print 'split between the ';
		$iter = 1;
		$distcount = count($districts);
		foreach($districts as $mdistnid => $mdistrict) {
			print $mdistrict['name'];

      if ($iter == 3 && (($distcount - $iter) > 0)) {
        print ', and ' . ($distcount - $iter) . ' more additional ';
        break;
      }
			if ($iter >= 1 && $iter < $distcount-1 && $distcount > 2) {
				print ', ';
			}
			if ($iter >=1 && $iter == $distcount-1 && $distcount >2) {
				print ', and ';
			}
			if ($iter == 1 && $distcount == 2) {
				print ' and ';
			}

			$iter++;
		}
		print " school districts. ";
	}
}
print 'Additionally, there ' . format_plural($schoolCounts['high'], 'is ', 'are ');
print $schoolCounts['high'] . ' high ' . format_plural($schoolCounts['high'], 'school', 'schools') . ' and ';
print $schoolCounts['middle'] . ' middle ' . format_plural($schoolCounts['middle'], 'school', 'schools') . ' in ';

print $c->title . ', ';
print 'with more than ' . number_format(round($totalenrollment, -1), 0, ".", ",") . ' students enrolled in public schools in ' . $c->title . '.</p>';

print '<ul class="clearfix infograph">';
print '<li class="one-third"><h4><span class="red">Elementary</span> Schools</h4>
				<span class="large-value red">';
if (isset($schoolCounts['elem'])) { print $schoolCounts['elem']; }
else { print '0'; }
print'</span>
				<span class="description">school';
print $schoolCounts['elem'] == 1 ? ' serves': 's serve';
print '<br/>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</span>
		</li>';
print '<li class="one-third"><h4><span class="blue">Middle</span> Schools</h4>
				<span class="large-value blue">';
if (isset($schoolCounts['middle'])) { print $schoolCounts['middle']; }
else { print '0'; }
print'</span>
				<span class="description">school';
print $schoolCounts['middle'] == 1 ? ' serves': 's serve';
print '<br/>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</span>
		</li>';
print '<li class="one-third"><h4><span class="orange">High</span> Schools</h4>
				<span class="large-value orange">';
if (isset($schoolCounts['high'])) { print $schoolCounts['high']; }
else { print '0'; }
print'</span>
				<span class="description">school';
print $schoolCounts['high'] == 1 ? ' serves': 's serve';
print '<br/>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</span>
		</li>';
print '</ul>';
print '<ul class="clearfix infograph">';
print '<li class="one-third"><h4>Students Enrolled</h4>
				<span class="large-value green">';
print number_format(round($totalenrollment, -1), 0, ".", ",");
print "</span>";
print '<span class="description">Students in public schools in '  . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</span>';

print '</li>';
print '<li class="two-third">';
print '<div><h4>Largest schools in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</h4>';
print '<ol class="largest-schools">';
print '<li>The largest public high school is ' . $largestSchools['high']['name'] . ' <span class="enrollment">' . $largestSchools['high']['enrollment'] . ' students</span></li>';
print '<li>The largest public middle school is ' . $largestSchools['middle']['name'] . ' <span class="enrollment">' . $largestSchools['middle']['enrollment'] . ' students</span></li>';
print '<li>The largest public elementary school is ' . $largestSchools['elem']['name'] . ' <span class="enrollment">' . $largestSchools['elem']['enrollment'] . ' students</span></li>';
print '</ol>';
print '</div>';
print '</li>';
print '</ul>';
print '<span class="description-small grey">Source: <a href="http://www.greatschools.org/" target="_blank">GreatSchools</a></span>';
print '</div>';


print '<div class="locations-nearby padded grey-bg shadow-inset-lr clearfix">';
print '<span class="heading">Public Schools near '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</span>';
print '<span class="locations-nearby-container clearfix schools-containter"><span class="location-listings">';
print '<ul>'; // class="infograph">';
foreach($schools as $school){
        $school->rating = $school->field_field_greatschools_rating[0]['raw']['value'];
		if(!isset($firstSchool)){
				$firstSchool = 'bacon';
				print '<li class="listing active level-'.$school->level.'">';
		}else{
				print '<li class="listing level-'.$school->level.'">';
		}
		//if($school->rating == 'n/a'){continue;}
		//var_dump($school);
		print '<i class="icon-pin green"></i>
		<h5>'.$school->node_title.'</h5>
		<span class="summary">
				<span>'.$school->field_field_school_type[0]['raw']['value'].'</span>
				<span>'.$school->field_field_school_level[0]['raw']['value'].'</span>';
		if(isset($school->field_field_school_enrollment[0])){
				print '<span>'.$school->field_field_school_enrollment[0]['raw']['value'].' students</span>';
		}
		print '
		</span>
		<span class="address">
				<span class="street">'.$school->field_field_school_address[0]['raw']['value'].'</span>
				<span class="city">'.$school->field_field_school_citystatezip[0]['raw']['value'].'</span>
		</span>';
		if(isset($school->field_field_school_phone[0])){
				print '<span class="icon-phone"><a href="tel:'.$school->field_field_school_phone[0]['raw']['value'].'">'.$school->field_field_school_phone[0]['raw']['value'].'</a></span>';
		}
		if($school->rating < 4){
				$color = 'red';
		}elseif($school->rating < 8){
				$color = 'yellow';
		}else{
				$color = 'green';
		}

        if($school->rating == 'n/a'){ $school->rating = 'na';}
		print '
		<span class="location-details">
				<span class="large-value '.$color.' school-rating public rating-'.$school->rating.'">
				<a href="http://www.greatschools.org/school/rating.page?id='.
				substr($school->field_field_greatschools_id[0]['raw']['value'],2).
				'&state='.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'">&nbsp;</a></span>';
				print '<span style="padding-top: 20px;float: left;">';
                print '<a href="http://www.greatschools.org/'.strtolower($c->state->title).'/'.strtolower($c->title).'/';
                $gsid = substr($school->field_field_greatschools_id[0]['raw']['value'],2);
                if($gsid[0] == '0'){
                    $gsid = substr($gsid,1);
                }
                print $gsid.'-'.
                    str_replace(' ','-',$school->node_title).'/" target="_blank">';
                print 'GreatSchools Rating</a></span>';
                print '<a href="http://www.greatschools.org" target="_blank" alt="GreatSchools"><img src="/'.drupal_get_path('module','city_sections').'/includes/schools/GS_logo.png" style="width:100px;float: right;padding: 20px;"></a>';
                print '<span class="clearfix">&nbsp;</span>';
    //print '<h1>'.$school->rating.'</h1>';
                print '<h1>'.$school->node_title.'</h1>';
                if(isset($school->_field_data['nid']['entity']->field_school_district[LANGUAGE_NONE][0]['target_id'])){
                    $d = node_load($school->_field_data['nid']['entity']->field_school_district[LANGUAGE_NONE][0]['target_id']);
                    print '<h5>'.$d->title.'</h5>';
                }
				print '<ul class="infograph">';
				if(isset($school->field_field_school_bachelors[0])){
						print '<li>'.$school->field_field_school_bachelors[0]['raw']['value'].'</li>';
				}
				if(isset($school->field_field_school_license[0])){
						print '<li>'.$school->field_field_school_license[0]['raw']['value'].'%valid license</li>';
				}
				//<li>teacher exp years</li>
				//<li>avg years teach in districts</li>

				print '</ul>';
				/*
				if(isset($school->level)){
						print '<span class="small-value blue">'.$school->level.'</span>';
				}else{
						print '<span class="small-value blue">School Level unknown?</span>';
				}
				*/
		print '</span>';
		print '</li>';
}
print '</ul>';
$pages = count($schools) / 5;
$pages++;
print '<span class="pages clearfix"><ul>';
    print '<li class="previous"><a href="#">Previous</a></li>';
    print '<li class="next"><a href="#">Next</a></li>';
print '</ul></span>';

print '</span></span></div>';

print citySectionInclude('stubs/promote-city');

print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Schools',$c,0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Schools in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Schools'));
}
print citySectionInclude('real-estate/block-listing');

print citySectionInclude('stubs/ad728bottom');
