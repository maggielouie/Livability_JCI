<?php
global $title;
$c = getCityContext();
print citySectionInclude('stubs/ad728');
$mainBody = '<div class="city-topic-summary padded">';
$nearby = views_get_view('nearby_hospitals',true);
$nearby->execute('block');
//var_dump($nearby->result);
$c->hospitals = new stdClass();
$c->physicians = new stdClass();
$c->hospitals->nearby = $nearby->result;
$c->hospitals->withinSixtyMiles = count($nearby->result);

$physicianQuery = db_query('SELECT COUNT(*) AS total FROM data_health_physicians WHERE City = ? AND StateAbbrev = ?', array(
    strtoupper($c->title),$c->state->field_state_code['und'][0]['value']));

$physicianQueryAssoc = $physicianQuery->fetchAssoc();

$c->physicians->nearbyPrimaryCareTotal = $physicianQueryAssoc['total'];

$title = 'Health and Health Care in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];
$mainBody .= '<h1>'.$title.'</h1>';

$countyHealthFIP = getCountyFIP($c);
$countyHealthQuery = db_query('select * from data_health_countyhealth where FIPS = ? and DataYear=2014',array($countyHealthFIP));
$c->countyHealthData = array();
$countyHealthQuery = $countyHealthQuery->fetchAssoc();
$numberOfCounties = new EntityFieldQuery();
$numberOfCounties->entityCondition('entity_type','node')->entityCondition('bundle','county')
    ->fieldCondition('field_state','target_id',$c->state->nid);
$results = $numberOfCounties->execute();
$numberOfCounties = count($results['node']);

if(isset($c->physicians->nearbyPrimaryCareTotal) and $c->physicians->nearbyPrimaryCareTotal > 0)
$drRatio= number_format($c->field_population['und'][0]['value'] /$c->physicians->nearbyPrimaryCareTotal,0);
else
     $drRatio = 0;
$nationalHealthCostsQuery = db_query('select avg(HlthCareCosts) costs from data_health_countyhealth where DataYear=2014');
$nationalHealthCosts = $nationalHealthCostsQuery->fetchAssoc();

$nationalTotalPrimaryCareQuery = db_query('select count(*) as total from data_health_physicians '.
    'where '. //PrimSpecialty = ? or PrimSpecialty = ?',
    'PrimSpecialty = ? or PrimSpecialty = ? or PrimSpecialty = ?'.
    ' or PrimSpecialty = ? or PrimSpecialty = ? or PrimSpecialty = ?',
            array('INTERNAL MEDICINE',
                'FAMILY PRACTICE',
                'OBSTETRICS/GYNECOLOGY',
                'PEDIATRIC MEDICINE',
                'GENERAL PRACTICE',
                'GERIATRIC MEDICINE'));
$nationalTotalPrimaryCare = $nationalTotalPrimaryCareQuery->fetchAssoc();
$nationalTotalPrimaryCare = $nationalTotalPrimaryCare['total'];

$nationalTotalPopulationQuery = db_query('select sum(field_population_value) total from field_data_field_population where bundle =?',array('state'));
$nationalTotalPopulation = $nationalTotalPopulationQuery->fetchAssoc();
$nationalTotalPopulation = $nationalTotalPopulation['total'];
$ratio = number_format($nationalTotalPopulation / $nationalTotalPrimaryCare,0);
$mainBody .= '<p>Health care comes down to access, affordability and outcomes. '.
    $c->title.' residents have access to '.$c->hospitals->withinSixtyMiles.' acute care hospital' . ($c->hospitals->withinSixtyMiles > 1 ? 's' : '') . ' within 60 miles. ';
$mainBody .= $c->title.' residents are ';
$mainBody .= 'in '.$c->county->name.'. ';
$mainBody .= $c->county->name.' ranks '.
    livHelper::ordinalSuffix($countyHealthQuery['OutcomeRank']).' for health outcomes, '.
    livHelper::ordinalSuffix($countyHealthQuery['FactorRank']).' for health factors and '.
    livHelper::ordinalSuffix($countyHealthQuery['BehaviorsRank']).' for healthy behaviors in '.$c->state->title.'. '.
    'Residents spend ';
if($nationalHealthCosts['costs']< $countyHealthQuery['HlthCareCosts']){
    $mainBody .= number_format((1-($nationalHealthCosts['costs']/$countyHealthQuery['HlthCareCosts']))*100,1);
    $mainBody .= '% more than ';
}else{
    $mainBody .= number_format((1-($countyHealthQuery['HlthCareCosts']/$nationalHealthCosts['costs']))*100,1);
    $mainBody .= '% less than ';
}
    //[coli-percent] more/less than the
    $mainBody .= 'the national average on health care-related goods and services.</p>';

$outComesPercent = number_format((($numberOfCounties-$countyHealthQuery['OutcomeRank'])/$numberOfCounties)*100,0);
$factorsPercent = number_format((($numberOfCounties-$countyHealthQuery['FactorRank'])/$numberOfCounties)*100,0);
$behaviorsPercent = number_format((($numberOfCounties-$countyHealthQuery['BehaviorsRank'])/$numberOfCounties)*100,0);
$mainBody .= '<ul class="clearfix infograph">
			<li class="one-third">
            <h4><span class="red">Health Outcomes</span> Rank</h4>'.
    '<span class="large-value red">'.
    livHelper::ordinalSuffix($countyHealthQuery['OutcomeRank']).'</span>'.
    '<span class="description"> in '.$c->state->title.'<br>'.
    'out of '.$numberOfCounties.' counties</span>'.
    '
    </li>
    <li class="one-third">
    <h4><span class="blue">Health Factors</span> Rank</h4>'.
    '<span class="large-value blue">'.
    livHelper::ordinalSuffix($countyHealthQuery['FactorRank']).'</span>'.
    '<span class="description"> in '.$c->state->title.'<br>'.
    'out of '.$numberOfCounties.' counties</span>'.
    '
     </li>
<li class="one-third">
<h4><span class="orange">Healthy Behaviors</span> Rank</h4>'.
    '<span class="large-value orange">'.
    livHelper::ordinalSuffix($countyHealthQuery['BehaviorsRank']).'</span>'.
    '<span class="description"> in '.$c->state->title.'<br>'.
    'out of '.$numberOfCounties.' counties</span>'.
    '
</li></ul>
<span class="description-small grey"><strong>Health Outcomes</strong> refer to how long people live and how they feel while they\'re alive. <strong>Health Factors</strong> include clinical care, social, economic and the physical environment. <strong>Healthy Behaviors</strong> include diet, exercise and other measures of healthy living. For more information, see the <a href="http://www.countyhealthrankings.org/" title="_blank">County Health Rankings &amp; Roadmaps</a>.</span>
<ul class="clearfix infograph">
    <li class="half">
        <h4>Hospitals in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'].'</h4>
            <span class="circle-stroke blue-stroke"><i class="icon-hospital"></i></span>
            <span class="description">
                <span class="blue">'. format_plural(count($c->hospitals->nearby), '1 hospital', '@count hospitals') .'</span>
                within 60 miles<br/><br/>
                of '.$c->title.', '.$c->state->field_state_code['und'][0]['value'].'
            </span>
        </li>
        <li class="half">
            <h4>Doctors in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'].'</h4>
            <span class="circle-stroke red-stroke"><i class="icon-doctor"></i></span>
            <span class="description">
                <span class="red">' . format_plural(number_format($physicianQueryAssoc['total']), '1 doctor', '@count doctors') . '</span>
                within city limits<br/><br/>
                of '.$c->title.', '.$c->state->field_state_code['und'][0]['value'].'
            </span>
        </li>
    </ul>
<span class="description-small grey">Source: <a href="http://www.countyhealthrankings.org/" target="_blank">County Health Rankings &amp; Roadmaps</a>.</span>';
$mainBody .= '</div>';//end city topic summary
print $mainBody;
print citySectionInclude('stubs/promote-city');
print citySectionInclude('stubs/ad728middle');

/*
print '
<div class="city-detailed-stats padded grey-bg shadow-inset-lr">
    <span class="heading">More Health Stats for <strong>'.$c->title.', '.
        $c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</strong>
    </span>
    <ul class="clearfix detailed-stats">
        <li class="one-third infograph">
            <h4>Good Health Rate<span>in '.$c->county->title.' County</span></h4>
            <span class="main-stat">
                <input class="donut-graph-large" id="health-rate" value="';
                    print $countyHealthQuery['PFHlthPerc'];
                    print '%">
            </span>
            <span class="compare-regions">
                <ul>';

                    //<li class="one-third">
                    //        <input id="metro-rate" class="donut-graph-small" value="23%">
                    //        <label for="metro-rate">metro</label>
                    //</li>
$stateAvgQuery = db_query('select avg(PFHlthPerc) physicalhealthavg,avg(PMenHlthDaysPerc) mentalhealthavg from data_health_countyhealth where StateName=? and DataYear=2014 order by DataYear',array($c->state->title));
$stateAvgData = $stateAvgQuery->fetchAssoc();
                    print '<li class="one-third">
                            <input id="state-rate" class="donut-graph-small" value="'.number_format($stateAvgData['physicalhealthavg'],0).'%">
                            <label for="state-rate">state</label>
                    </li>';
$nationalAvgQuery = db_query('select avg(PFHlthPerc) physicalhealthavg,avg(PMenHlthDaysPerc) mentalhealthavg from data_health_countyhealth');
$nationalAvgData = $nationalAvgQuery->fetchAssoc();
print '
                    <li class="one-third">
                            <input id="nation-rate" class="donut-graph-small" value="'.number_format($nationalAvgData['physicalhealthavg'],0).'%">
                            <label for="nation-rate">nation</label>
                    </li>
                </ul>
            </span>
            <p>Percent of adults within '.$c->county->title.' County that reported to be in fair or poor health. (age-adjusted)</p>
        </li>
        <li class="one-third infograph">
            <h4>Good Physical Health<span>in '.$c->county->title.' County</span></h4>
            <span class="main-stat">
                <span class="large-value">27.5</span>
                <span class="description"><strong>Days</strong><br>per month</span>
                <span class="compare-national">
                    <i class="icon-arrow-down red"></i> <span class="black">32%</span> lower than national average
                </span>
            </span>

            <span class="compare-regions">
                <ul>';
/*                    <li class="one-third">
                            <input id="metro-rate" class="donut-graph-small blue" value="23.8">
                            <label for="metro-rate">metro</label>
                    </li>
*/ /*
                print '<li class="one-third">
                            <input id="state-rate" class="donut-graph-small red" value="'.number_format($nationalAvgData['mentalhealthavg'],0).'%">
                            <label for="state-rate">state</label>
                    </li>
                    <li class="one-third">
                            <input id="nation-rate" class="donut-graph-small orange" value="3.1">
                            <label for="nation-rate">nation</label>
                    </li>
                </ul>
            </span>
            <p>Percent of adults within '.$c->county->title.
                ' County that reported to be in fair or poor health. (age-adjusted)
            </p>
        </li>
        <li class="one-third infograph">
            <h4>Good Mental Health<span>in '.$c->county->title.' County</span></h4>
            <span class="main-stat">
                <span class="large-value">27.5</span>
                <span class="description"><strong>Days</strong><br>per month</span>
                <span class="compare-national">
                    <i class="icon-arrow-up green"></i> <span class="black">7%</span> higher than national average
                </span>
            </span>

            <span class="compare-regions">
                <ul>
                    <li class="one-third">
                            <input id="metro-rate" class="donut-graph-small blue" value="2.3">
                            <label for="metro-rate">metro</label>
                    </li>
                    <li class="one-third">
                            <input id="state-rate" class="donut-graph-small red" value="18.9">
                            <label for="state-rate">state</label>
                    </li>
                    <li class="one-third">
                            <input id="nation-rate" class="donut-graph-small orange" value="36.4">
                            <label for="nation-rate">nation</label>
                    </li>
                </ul>
            </span>
            <p>Percent of adults within Manatee County that reported to be in fair or poor health. (age-adjusted)</p>

        </li>
    </ul>
</div>';
*/

$content = getContentByTermAndPlace('Health',$c, 0);
if (!empty($content['nodes'])) {
	$heading = 'Articles related to <b>Health in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
	print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Health'));
}
print citySectionInclude('real-estate/block-listing');

print citySectionInclude('stubs/ad728bottom');