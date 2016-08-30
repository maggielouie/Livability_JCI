<?php
global $title;
$c = getCityContext();

$add_data = $c->census['city-add-data'];
$ed_attainment_total = $add_data['DP02_0058E'];
$ed_attaintment_9 = $add_data['DP02_0059E'];
$ed_attainment_somehigh = $add_data['DP02_0060E'];
$ed_attainment_high = $add_data['DP02_0061E'];
$ed_attainment_somecol = $add_data['DP02_0062E'];
$ed_attainment_associate = $add_data['DP02_0063E'];
$ed_attainment_bachelors = $add_data['DP02_0064E'];
$ed_attainment_postgrad = $add_data['DP02_0065E'];
$ed_percent_highschool = $add_data['DP02_0066PE'];
$ed_percent_bachelor = $add_data['DP02_0067PE'];

$ed_enrollment_prek = $add_data['DP02_0053E'];
$ed_enrollment_kind = $add_data['DP02_0054E'];
$ed_enrollment_elem = $add_data['DP02_0055E'];
$ed_enrollment_high = $add_data['DP02_0056E'];
$ed_enrollment_col = $add_data['DP02_0057E'];


$districts = array();
// load the district node, query for district enrollment
$districtEnrollment = 0;
foreach ($schoolDistricts as $district) {
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
	$schools = db_query($schoolq, array(':sdid' => $district->nid));
	foreach($schools as $school) {
		$districts[$district->nid]['enrollment'] += $school->enrollment;
		$districtEnrollment += $school->enrollment;
	}
}
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
if (isset($ed_enrollment_high)) {
	$totalenrollment += $ed_enrollment_high;
}
if (isset($ed_enrollment_col)) {
	$totalenrollment += $ed_enrollment_col;
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
$districts = array_slice($districts,0,4);

/* A CHECK FOR HOW MANY SCHOOLS HAVE ENROLLMENT DATA - not displayed anywhere, a data-quality check.
$schnoenroll = 0;
$schenroll = 0;
foreach ($schoolDistricts as $district) {
	$schoolq = 'SELECT n.nid, en.field_school_enrollment_value as enrollment from {node} n ';
	$schoolq .= 'LEFT JOIN {field_data_field_school_enrollment} en on en.entity_id = n.nid ';
	$schoolq .= 'LEFT JOIN {field_data_field_school_district} dis on dis.entity_id = n.nid ';
	$schoolq .= 'LEFT JOIN {field_data_field_school_type} typ on typ.entity_id = n.nid ';
	$schoolq .= 'WHERE n.type = \'schools\' ';
	$schoolq .= 'AND typ.field_school_type_value = \'public\' ';
	$schoolq .= 'AND dis.field_school_district_target_id = :sdid';
	$schools = db_query($schoolq, array(':sdid' => $district->nid));
	foreach($schools as $school) {
		if (is_null($school->enrollment)) {
			$schnoenroll++;
		}
		else {
			$schenroll++;
		}
	}
}
krumo('enrollment info exists for ' . $schenroll .' out of '.$schenroll+$schnoenroll.' schools');
*/

/* OUTPUT START */
$title = $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . ' Schools and School Ratings';
print citySectionInclude('stubs/ad728');
print '<div class="city-topic-summary schools schools-index padded">';
print '<h1>'.$title.'</h1>';
print '<p>' . $c->title . ' schools - which is  ';
$primarydistrict = FALSE;
$diter = 0;
foreach($districts as $dnid => $district) {
	$diter++;
	if ($district['servicepercent'] >= 95) {
		$primarydistrict = TRUE;
		print 'part of the ' . $district['name'] . (preg_match('/district/i', $district['name']) ? '' : 'district - ') . '. ';
	}
	elseif ($district['servicepercent'] >= 60 && $district['servicepercent'] < 95) {
		$primarydistrict = TRUE;
		print 'primarily part of the ' . $district['name'] . (preg_match('/district/i', $district['name']) ? '' : 'district - ') . '. ';
	}
	elseif ($primarydistrict == FALSE && $diter == 1) {
		print 'split between the ';
		$iter = 1;
		$distcount = count($districts);
		foreach($districts as $mdistnid => $mdistrict) {
			print $mdistrict['name'];
			if ($iter >= 1 && $iter < $distcount-1 && $distcount > 2) {
				print ', ';
			}
			if ($iter >=1 && $iter == $distcount-1 && $distcount >2) {
				print ' and ';
			}
			if ($iter == 1 && $distcount == 2) {
				print ' and ';
			}
			$iter++;
		}
		print (preg_match('/district/i', $mdistrict['name']) ? '. ' : 'school districts - '); //" school districts -  ";
	}
}
$iter = 0;
$piter = 0;
foreach($districts as $distnid => $district) {
	$iter++;
	if (isset($district['node']->field_greatschools_rating['und']) && $iter == 1 && $piter == 0) {
		print 'The ' . $district['name'] . ' ' . (preg_match('/district/i', $district['name']) ? '' : 'district') . ' has an average GreatSchools rating of ' . $district['node']->field_greatschools_rating['und'][0]['value'] . ' out of 10. ';
		$piter++;
	}
	if (isset($district['node']->field_greatschools_rating['und']) && $iter > 1 && $piter == 1 && $primarydistrict == FALSE) {
		$piter++;
		print 'The ' . $district['name'] . ' ' . (preg_match('/district/i', $district['name']) ? '' : 'district') . ' has an average rating of ' . $district['node']->field_greatschools_rating['und'][0]['value'] . ' out of 10. ';
	}
}
print '</p>';

$high_school = ($add_data['DP02_0061E'] + $add_data['DP02_0062E']) / $add_data['DP02_0058E'];
$college = $add_data['DP02_0064E'] / $add_data['DP02_0058E'];
$post_grad =  $add_data['DP02_0065E'] / $add_data['DP02_0058E'];
print 'While perhaps not raised and educated in ' . $c->title . ', more than ';

//print round(($c->field_education_high_school['und'][0]['value'] + $c->field_education_college['und'][0]['value'] + $c->field_education_post_grad['und'][0]['value'] ) / $ed_attainment_total * 100);
print round($high_school*100);
print ' percent hold high school diplomas, with ';
//print round(($c->field_education_college['und'][0]['value'] + $c->field_education_post_grad['und'][0]['value'] ) / $ed_attainment_total * 100);
print round($college*100);
print ' percent having graduated from college and ';
print round($post_grad*100);
print ' percent completing a post-graduate degree program.';
print '<p>';


$infograph = '';
$infograph .= '<ul class="clearfix infograph">
	<li class="half">
		<h4>Education Level of ' . $c->title . ', ' . $c->state->field_state_code[LANGUAGE_NONE][0]['value'] . ' Adults</h4>';
if(isset($ed_attainment_9) && !empty($ed_attainment_9)){
	$infograph .= '		<span class="out-of fill-bar-label">Less than 9th Grade</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_attainment_9 / $ed_attainment_total * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#7cc242;position:relative;top:-20px;width:' . round($ed_attainment_9 / $ed_attainment_total * 100, 1) . '%;"></span>';
}
if(isset($ed_attainment_somehigh) && !empty($ed_attainment_somehigh)){
	$infograph .= '		<span class="out-of fill-bar-label">Some High School</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_attainment_somehigh / $ed_attainment_total * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#7cc242;position:relative;top:-20px;width:' . round($ed_attainment_somehigh / $ed_attainment_total * 100, 1) . '%;"></span>';
}
if(isset($ed_attainment_high) && !empty($ed_attainment_high)){
	$infograph .= '		<span class="out-of fill-bar-label">High School</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_attainment_high / $ed_attainment_total * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#7cc242;position:relative;top:-20px;width:' . round($ed_attainment_high / $ed_attainment_total * 100, 1) . '%;"></span>';
}
if(isset($ed_attainment_somecol) && !empty($ed_attainment_somecol)){
	$infograph .= '		<span class="out-of fill-bar-label">Some College</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_attainment_somecol / $ed_attainment_total * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#7cc242;position:relative;top:-20px;width:' . round($ed_attainment_somecol / $ed_attainment_total * 100, 1) . '%;"></span>';
}
if(isset($ed_attainment_associate) && !empty($ed_attainment_associate)){
	$infograph .= '		<span class="out-of fill-bar-label">Associate Degree</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_attainment_associate / $ed_attainment_total * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#7cc242;position:relative;top:-20px;width:' . round($ed_attainment_associate / $ed_attainment_total * 100, 1) . '%;"></span>';
}
if(isset($ed_attainment_bachelors) && !empty($ed_attainment_bachelors)){
	$infograph .= '		<span class="out-of fill-bar-label">Bachelors</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_attainment_bachelors / $ed_attainment_total * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#7cc242;position:relative;top:-20px;width:' . round($ed_attainment_bachelors / $ed_attainment_total * 100, 1) . '%;"></span>';
}
if(isset($ed_attainment_postgrad) && !empty($ed_attainment_postgrad)){
	$infograph .= '		<span class="out-of fill-bar-label">Post-Graduate</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_attainment_postgrad / $ed_attainment_total * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#7cc242;position:relative;top:-20px;width:' . round($ed_attainment_postgrad / $ed_attainment_total * 100, 1) . '%;"></span>';
}
$infograph .= '	</li>
	<li class="half">
		<h4>Current School Enrollment in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</h4>';
if (isset($ed_enrollment_prek)) {
	$infograph .= '		<span class="out-of fill-bar-label">Pre-K</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_enrollment_prek / $totalenrollment * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#009bd5;position:relative;top:-20px;width:' . round($ed_enrollment_prek / $totalenrollment * 100, 1) . '%;"></span>';
}
if (isset($ed_enrollment_kind)) {
	$infograph .= '		<span class="out-of fill-bar-label">Kindergarten</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_enrollment_kind / $totalenrollment * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#009bd5;position:relative;top:-20px;width:' . round($ed_enrollment_kind / $totalenrollment * 100, 1) . '%;"></span>';
}
if (isset($ed_enrollment_elem)) {
	$infograph .= '		<span class="out-of fill-bar-label">Elementary</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_enrollment_elem / $totalenrollment * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#009bd5;position:relative;top:-20px;width:' . round($ed_enrollment_elem / $totalenrollment * 100, 1) . '%;"></span>';
}
if (isset($ed_enrollment_high)) {
	$infograph .= '		<span class="out-of fill-bar-label">High School</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_enrollment_high / $totalenrollment * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#009bd5;position:relative;top:-20px;width:' . round($ed_enrollment_high / $totalenrollment * 100, 1) . '%;"></span>';
}
if (isset($ed_enrollment_col)) {
	$infograph .= '		<span class="out-of fill-bar-label">College</span>
		<span class="fill-bar-label fill-bar-value right">'.round($ed_enrollment_col / $totalenrollment * 100, 1) . '%</span>
		<span class="fill-bar"></span>
		<span class="fill-bar" style="margin:0;background-color:#009bd5;position:relative;top:-20px;width:' . round($ed_enrollment_col / $totalenrollment * 100, 1) . '%;"></span>';
}

$infograph .= '	</li>
</ul>';
$infograph .= '<p class="description grey">Source:  U.S. Census Bureau, 2008-2013 American Community Survey</p>';

print $infograph;
print '</div>'; //end city topic summary
print citySectionInclude('stubs/promote-city');

print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Schools',$c,0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Schools in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Schools'));
}
print citySectionInclude('real-estate/block-listing');

print citySectionInclude('stubs/ad728bottom');
