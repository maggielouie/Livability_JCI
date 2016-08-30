<?php
global $title;
$c = getCityContext();
$schoolCounts['elem'] = count($schoolCounts['elem']);
$schoolCounts['middle'] = count($schoolCounts['middle']);
$schoolCounts['high'] = count($schoolCounts['high']);


$total_enrollment = NULL;
foreach ($schools as $school) {
    $total_enrollment += $school->field_field_school_enrollment[0]['raw']['value'];
}

// not sure if this is still needed --jdd
// get schools in [xx] mi if needed (per type) (existing is already 20mi radius)
        $types = array('elementary', 'middle', 'high');
        $getmore = array();
        foreach ($types as $type) {
            if (!isset($schoolCounts[$type])) {
                $getmore[] = $type;
            }
        }
        if (!empty($getmore)) {
            $ordinates = round($c->field_geo['und'][0]['lat'], 5) . '_' . round($c->field_geo['und'][0]['lon'], 5) . '_40';
            $more = views_get_view_result('nearby_schools', 'block', $ordinates, 'all');
            $moreschoolCounts = array();
            $moreschoolsPrivateCount = 0;
            $moreprivateenrollment = 0;
            foreach ($more as $key => $school) {
                if (in_array($key, array_keys($schools))) {
                    unset($more[$key]);
                    unset($school);
                }
                if (isset($school->field_field_school_type)) {
                    $type = $school->field_field_school_type[0]['raw']['value'];
                }
                if ($type == 'private') {
                    $more[$key]->node = node_load($school->nid);
                    // setup groups/tallies of schools by type
                    // determine elementary/middle/high based on school_level
                    if (isset($school->field_field_greatschools_rating[0])) {
                        $more[$key]->rating = $school->field_field_greatschools_rating[0]['raw']['value'];
                    } else {
                        $more[$key]->rating = 'n/a';
                    }
                    if (isset($school->field_field_school_subtype[0])) {
                        $subtype = $school->field_field_school_subtype[0]['raw']['value'];
                    } else {
                        $subtype = null;
                    }
                    $more[$key]->level = schoolLevel($subtype, $school->field_field_school_level[0]['raw']['value'], $school->node_title);
                    if (isset($more[$key]->level)) {
                        if (isset($moreschoolCounts{$more[$key]->level})) {
                            $moreschoolCounts{$more[$key]->level}++;
                        } else {
                            $moreschoolCounts{$more[$key]->level} = 1;
                        }
                    }
                    if ($more[$key]->rating == 'n/a') {
                        $moreschoolsPrivateCount++;
                    }
                    if (!is_null($more[$key]->field_field_school_enrollment) && !empty($more[$key]->field_field_school_enrollment)) {
                        $moreprivateenrollment += $more[$key]->field_field_school_enrollment[0]['raw']['value'];
                    }
                } else {
                    unset($more[$key]);
                }
            }
        }
        $base = arg();
        array_pop($base);

        /* OUTPUT START */
        $title = 'Private Schools in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'];
        print '<div class="city-topic-summary schools private-schools padded">';
        print citySectionInclude('stubs/ad728');
        print '<h1>' . $title . '</h1>';
        print '<p>For parents who wish to explore options outside of the <a href="/' . implode('/', $base) . '/public-schools">public schools</a> in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . ', ';
        $tharb = FALSE;
        if (isset($schoolCounts['elem']) && $schoolCounts['elem'] > 0) {
            $tharb = TRUE;
            if ($schoolCounts['elem'] == 1) {
                echo ' there is ';
            } else {
                echo ' there are ';
            }
            print $schoolCounts['elem'] . ' private elementary school';
            print $schoolCounts['elem'] > 1 ? 's' : '';
        }
        if (isset($schoolCounts['middle']) && $schoolCounts['middle'] > 0) {
            if (!$tharb) {
                if ($schoolCounts['middle'] == 1) {
                    echo ' there is ';
                } else {
                    echo ' there are ';
                }
            }
            if ($tharb) print ', ';
            $tharb = TRUE;
            print $schoolCounts['middle'] . ' private middle school';
            print $schoolCounts['middle'] > 1 ? 's' : '';
        }
        if (isset($schoolCounts['high']) && $schoolCounts['high'] > 0) {
            if (!$tharb) {
                if ($schoolCounts['high'] == 1) {
                    echo ' there is ';
                } else {
                    echo ' there are ';
                }
            }
            if ($tharb) print ' and ';
            $tharb = TRUE;
            print $schoolCounts['high'] . ' private high school';
            print $schoolCounts['high'] > 1 ? 's' : '';
        }
        if ((!isset($schoolCounts['elem']) && isset($moreschoolCounts['elementary'])) || (!isset($schoolCounts['middle']) && isset($moreschoolCounts['middle'])) || (!isset($schoolCounts['high']) && isset($moreschoolCounts['high']))) {
            if ($tharb) {
                print ', as well as ';
            }
            if (isset($moreschoolCounts['elem']) && $moreschoolCounts['elementary'] > 0) {
                print $moreschoolCounts['elem'] . ' private elementary school';
                print $moreschoolCounts['elem'] > 1 ? 's' : '';
            }
            if (isset($moreschoolCounts['middle']) && $moreschoolCounts['middle'] > 0) {
                if (isset($moreschoolCounts['elem']) && $moreschoolCounts['elem'] > 0) {
                    if (isset($moreschoolCounts['high']) && $moreschoolCounts['high'] > 0) {
                        print ', ';
                    } else {
                        print ' and ';
                    }
                }
                print $moreschoolCounts['middle'] . ' private middle school';
                print $moreschoolCounts['middle'] > 1 ? 's' : '';
            }
            if (isset($moreschoolCounts['high']) && $moreschoolCounts['high'] > 0) {
                if ((isset($moreschoolCounts['elem']) && $moreschoolCounts['elementary'] > 0) && (isset($moreschoolCounts['middle']) && $moreschoolCounts['middle'] > 0)) {
                    print ', ';
                } elseif ((isset($moreschoolCounts['elementary']) && $moreschoolCounts['elementary'] > 0) || (isset($moreschoolCounts['middle']) && $moreschoolCounts['middle'] > 0)) {
                    print ' and ';
                }
                print $moreschoolCounts['high'] . ' private high school';
                print $moreschoolCounts['high'] > 1 ? 's' : '';
            }
            print ' within 40 miles of ' . $c->title . '. ';
        } else {
            print ' within 20 miles of ' . $c->title . '. ';
        }

        print ' Approximately ' . number_format(round($total_enrollment, -1)) . ' students attend private school in ' . $c->title . '.</p>';

        print '<ul class="clearfix infograph">';
        print '<li class="one-third"><h4><span class="red">Elementary</span> Schools</h4>
				<span class="large-value red">';
        if (isset($schoolCounts['elem'])) {
            print $schoolCounts['elem'];
        } else {
            print '0';
            $schoolCounts['elem'] = 0;
        }
        print '</span>
				<span class="description">school';
        print $schoolCounts['elem'] == 1 ? ' serves' : 's serve';
        print '<br/>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</span>
		</li>';
        print '<li class="one-third"><h4><span class="blue">Middle</span> Schools</h4>
				<span class="large-value blue">';
        if (isset($schoolCounts['middle'])) {
            print $schoolCounts['middle'];
        } else {
            print '0';
            $schoolCounts['middle'] = 0;
        }
        print'</span>
				<span class="description">school';
        print $schoolCounts['middle'] == 1 ? ' serves' : 's serve';
        print '<br/>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</span>
		</li>';
        print '<li class="one-third"><h4><span class="orange">High</span> Schools</h4>
				<span class="large-value orange">';
        if (isset($schoolCounts['high'])) {
            print $schoolCounts['high'];
        } else {
            print '0';
            $schoolCounts['high'] = 0;
        }
        print'</span>
				<span class="description">school';
        print $schoolCounts['high'] == 1 ? ' serves' : 's serve';
        print '<br/>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</span>
		</li>';
        print '</ul>';

        print '<ul class="clearfix infograph">';
        print '<li class="one-third"><h4>Students Enrolled</h4>
				<span class="large-value green">';
        print number_format(round($total_enrollment, -1), 0, ".", ",");
        print "</span>";
        print '<span class="description">Students in private schools in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</span>';

        print '</li>';
        print '<li class="two-third">';
        print '<div><h4>Largest schools in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</h4>';
        print '<ol class="largest-schools">';
        print '<li>The largest private high school is ' . $largestSchools['high']['name'] . ' <span class="enrollment">' . $largestSchools['high']['enrollment'] . ' students</span></li>';
        print '<li>The largest private middle school is ' . $largestSchools['middle']['name'] . ' <span class="enrollment">' . $largestSchools['middle']['enrollment'] . ' students</span></li>';
        print '<li>The largest private elementary school is ' . $largestSchools['elem']['name'] . ' <span class="enrollment">' . $largestSchools['elem']['enrollment'] . ' students</span></li>';
        print '</ol>';
        print '</div>';
        print '</li>';
        print '</ul>';

        print '<span class="description-small grey">Source: <a href="http://www.greatschools.org/" target="_blank">GreatSchools</a></span>';
        print '</div>';


        print '<div class="locations-nearby padded grey-bg shadow-inset-lr clearfix">';
        print '<span class="heading">Private Schools near ' . $c->title . '</span>';
        print '<span class="locations-nearby-container clearfix schools-containter"><span class="location-listings">';
        print '<ul>'; // class="infograph">';
        foreach ($schools as $school) {
            if (!isset($firstSchool)) {
                $firstSchool = 'bacon';
                print '<li class="listing active level-' . $school->level . '">';
            } else {
                print '<li class="listing level-' . $school->level . '">';
            }
            //if($school->rating == 'n/a'){continue;}
            //var_dump($school);
            print '<i class="icon-pin green"></i>
		<h5>' . $school->node_title . '</h5>
		<span class="summary">
				<span>' . $school->field_field_school_type[0]['raw']['value'] . '</span>
				<span>' . $school->field_field_school_level[0]['raw']['value'] . '</span>';
            if (isset($school->field_field_school_enrollment[0])) {
                print '<span>' . $school->field_field_school_enrollment[0]['raw']['value'] . ' students</span>';
            }
            print '
		</span>
		<span class="address">
				<span class="street">' . $school->field_field_school_address[0]['raw']['value'] . '</span>
				<span class="city">' . $school->field_field_school_citystatezip[0]['raw']['value'] . '</span>
		</span>';
            if (isset($school->field_field_school_phone[0])) {
                print '<span class="icon-phone"><a href="tel:' . $school->field_field_school_phone[0]['raw']['value'] . '">' . $school->field_field_school_phone[0]['raw']['value'] . '</a></span>';
            }
            if ($school->rating < 4) {
                $color = 'red';
            } elseif ($school->rating < 8) {
                $color = 'yellow';
            } else {
                $color = 'green';
            }
            if ($school->rating == 'n/a') {
                $school->rating = 'na';
            }
            print '
		<span class="location-details">
				<span class="large-value ' . $color . ' school-rating public rating-' . $school->rating . '">
				<a href="http://www.greatschools.org/school/rating.page?id=' .
                substr($school->field_field_greatschools_id[0]['raw']['value'], 2) .
                '&state=' . $c->state->field_state_code[LANGUAGE_NONE][0]['value'] . '">&nbsp;</a></span>';
            print '<span style="padding-top: 20px;float: left;">';
            print '<a href="http://www.greatschools.org/' . strtolower($c->state->title) . '/' . strtolower($c->title) . '/';
            $gsid = substr($school->field_field_greatschools_id[0]['raw']['value'], 2);
            if ($gsid[0] == '0') {
                $gsid = substr($gsid, 1);
            }
            print $gsid . '-' .
                str_replace(' ', '-', $school->node_title) . '/" target="_blank">';
            print 'GreatSchools Rating</a></span>';
            print '<a href="http://www.greatschools.org" target="_blank" alt="GreatSchools"><img src="/' . drupal_get_path('module', 'city_sections') . '/includes/schools/GS_logo.png" style="width:100px;float: right;padding: 20px;"></a>';
            print '<span class="clearfix">&nbsp;</span>';
            //print '<h1>'.$school->rating.'</h1>';
            print '<h1>' . $school->node_title . '</h1>';
            if (isset($school->_field_data['nid']['entity']->field_school_district[LANGUAGE_NONE][0]['target_id'])) {
                $d = node_load($school->_field_data['nid']['entity']->field_school_district[LANGUAGE_NONE][0]['target_id']);
                print '<h5>' . $d->title . '</h5>';
            }
            print '<ul class="infograph">';
            if (isset($school->field_field_school_bachelors[0])) {
                print '<li>' . $school->field_field_school_bachelors[0]['raw']['value'] . '</li>';
            }
            if (isset($school->field_field_school_license[0])) {
                print '<li>' . $school->field_field_school_license[0]['raw']['value'] . '%valid license</li>';
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

        $content = getContentByTermAndPlace('Schools', $c, 0);
        if (!empty($content['nodes'])) {
            $heading = 'Articles related to <b>Schools in ' . $c->title . ', ' . $c->state->field_state_code[LANGUAGE_NONE][0]['value'] . '</b>';
            print citySectionInclude('stubs/content-cards', array('nodes' => $content['nodes'], 'heading' => $heading, 'total' => $content['total'], 'cnid' => $c->nid, 'terms' => 'Schools'));
        }
        print citySectionInclude('real-estate/block-listing');

        print citySectionInclude('stubs/ad728bottom');
