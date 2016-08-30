<?php
global $title;
$c = getCityContext();
$countyHealthQuery = db_query('select * from data_health_countyhealth where FIPS = ? and DataYear = ?',
    array(getCountyFIP($c),2014));
$c->countyHealthData = array();
$countyHealthQuery = $countyHealthQuery->fetchAssoc();

print citySectionInclude('stubs/ad728');
$title = 'Healthy Lifestyle in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];

print '<div class="city-topic-summary padded">';
print '<h1>'.$title.'</h1>';

print '<p>Healthy living goes beyond whether residents have access to affordable, quality doctors and hospitals. A city’s health takes into consideration the choices residents are making to lower their personal health risk. Here are figures that indicate how ' . $c->title . ' residents stack up against other areas in ' . $c->state->title . ' in terms of leading a healthy lifestyle.</p>';

print '<ul class="clearfix infograph">';
    print '<h1 class="padded">Common Health Risks in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</h1>';
    print '<p class="padded">Percentage of adults in '.$c->county->name.' who reported themselves matching the criteria with any one or more of the following common health risks.</p>';
    print '<li class="one-fourth">';
        print '<span class="donut-graph">
                    <input value="'.(100-$countyHealthQuery['AdObesityPerc']).'%" class="donut-graph-large">
                </span>';
        print '<span class="heading center-txt">Healthy Weight</span>';
        print '<p class="center-txt">';
        print 'Percent of adults who report a BMI < 30 ';
        print '</p>';
    print '</li>';
    print '<li class="one-fourth">';
        print '<span class="donut-graph">
            <input value="'.(100-$countyHealthQuery['AdSmokersPerc']).'%" class="donut-graph-large">
        </span>';
        print '<span class="heading center-txt">Nonsmokers</span>';
        print '<p class="center-txt">';
            print 'Percent of adults who do not smoke';
        print '</p>';
    print '</li>';
print '<li class="one-fourth">';
        print '<span class="donut-graph">
                    <input value="'.(100-$countyHealthQuery['UninsurAdltsPerc']).'%" class="donut-graph-large">
                </span>';
    print '<span class="heading center-txt">Insured</span>';
    print '<p class="center-txt">';
            print 'Percent of adults with health insurance';
    print '</p>';
print '</li>';
print '<li class="one-fourth">';

    print '<span class="donut-graph">
        <input value="'.(100-$countyHealthQuery['PhyInactivePerc']).'%" class="donut-graph-large">
    </span>';
    print '<span class="heading center-txt">Active Lifestyles</span>';
    print '<p class="center-txt">';
        print 'Percent of adults who report leisure time physical activity';
    print '</p>';
print '</li>';
print '</ul>';



print '</div>';
print citySectionInclude('stubs/promote-city');
print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Health',$c,0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Health in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Health'));
}
print citySectionInclude('real-estate/block-listing');
print citySectionInclude('stubs/ad728bottom');