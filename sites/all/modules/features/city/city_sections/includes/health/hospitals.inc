<?php
global $title;
$c = getCityContext();
print citySectionInclude('stubs/ad728');//x90" alt="Advertisement Place Holder"></a></span>
print '<div class="city-topic-summary padded">';
$title = 'Hospitals in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'];
print '<h1>' . $title . '</h1>';

$nearby = views_get_view('nearby_hospitals',TRUE);
$nearby->execute('block');
$c->hospitals = new stdClass();
$c->physicians = new stdClass();
$c->hospitals->nearby = $nearby->result;

$c->hospitals->types = array();
$c->hospitals->closestByType = array();
$c->hospitals->byType = array();
$c->hospitals->byOwnership = array();
$c->hospitals->waitTotal = 0;
$c->hospitals->waitCount = 0;

foreach($c->hospitals->nearby as $hospital) {
  $type = $hospital->field_field_hospital_type[0]['raw']['value'];
  $hospital->providerID = $hospital->_field_data['nid']['entity']->field_provider_id['und'][0]['value'];
  $hospital->ownership = $hospital->_field_data['nid']['entity']->field_ownership['und'][0]['value'];
  $dataHealthHospitals = db_query('select * from data_health_hospitals where ProviderNumber = ?', array($hospital->providerID));
  $dataHealthHospitalsAvgWait = db_query('select AVG(AvgTimeEmpDept) as avgTime,AVG(StateAvgTimeEmgDept) as stateTime,AVG(NatlAvgTimeEmgDept) as NationalTime,EmgService from data_health_hospitals where ProviderNumber = ? and EmgService=\'Yes\'', array($hospital->providerID));
  $avgWait = $dataHealthHospitalsAvgWait->fetchAssoc();
  if ($avgWait['avgTime'] != 0 && $avgWait['avgTime'] != NULL) {
    $c->hospitals->waitTotal = $c->hospitals->waitTotal + $avgWait['avgTime'];
    $c->hospitals->waitCount++;
  }
  foreach($dataHealthHospitals as $data) {
    $hospital->data = $data;
  }
  if (array_key_exists($type,$c->hospitals->types)) {
    $c->hospitals->types[$type] = $c->hospitals->types[$type]+1;
  }
  else {
    $c->hospitals->types[$type] = 1;
    $c->hospitals->closestByType[$type] = $hospital;
  }
  $c->hospitals->byOwnership[$hospital->ownership][] = $hospital;
  $c->hospitals->byType[$type][] = $hospital;
}

$nationalRecommendQuery = db_query('select avg(PatRec_PercAnswer) as RecRate, avg(PatRate_PercAnswer) as RateRate from data_health_hospitals');
$nationalRecommendResult = $nationalRecommendQuery->fetchAssoc();
$stateQuery = db_query('select avg(PatRec_PercAnswer) as RecRate, avg(PatRate_PercAnswer) as RateRate from data_health_hospitals where StateAbbrev = ?',array($c->state->field_state_code[LANGUAGE_NONE][0]['value']));
$stateQueryResult = $stateQuery->fetchAssoc();
$c->hospitals->avgWait = round($c->hospitals->waitTotal / $c->hospitals->waitCount,1);

print '<p>Residents of '.$c->title.' have ';

if (array_key_exists('Acute Care Hospitals',$c->hospitals->types)) {
  $acute = $c->hospitals->byType['Acute Care Hospitals'];
  print 'access to ' . count($acute) . ' acute care hospital';
  if (count($acute) > 1) print 's';
  print ' within 60 miles with an average emergency room wait time of ' . $c->hospitals->avgWait . ' minutes. ';
}
else {
  print ' no acute care facilities within 60 miles. ';
}

if (!array_key_exists('ACUTE CARE - VETERANS ADMINISTRATION',$c->hospitals->byType) && !array_key_exists('Childrens',$c->hospitals->byType)) {
  print 'There are no veteran\'s or children\'s hospitals nearby. ';
}
else {
  if (array_key_exists('ACUTE CARE - VETERANS ADMINISTRATION',$c->hospitals->byType)) {
    print 'There ';
    if (count($c->hospitals->byType['ACUTE CARE - VETERANS ADMINISTRATION']) > 1 ) {
      print 'are ' . count($c->hospitals->byType['ACUTE CARE - VETERANS ADMINISTRATION']) . ' veteran’s hospitals';
    }
    else {
      print 'is one Veteran’s hospital';
    }
    print ' within 60 miles. ';
  }
  else {
    print 'There are no veteran’s hospitals nearby.';
  }
  if (array_key_exists('Childrens',$c->hospitals->byType)) {
    print 'There ';
    if (count($c->hospitals->byType['Childrens']) > 1 ) {
      print 'are ' . count($c->hospitals->byType['Childrens']) . 'Children’s hospitals ';
    }
    else {
      print 'is one Children’s hospital ';
    }
    print 'within 60 miles. ';
  }
  else {
    print 'There are no children\'s hospitals nearby. ';
  }
}
print $c->title . ' ranks ';

$countyFIP = $c->county->field_county_fips['und'][0]['value'];
while(strlen($countyFIP) < 3){
    $countyFIP = '0' . $countyFIP;
}
$stateFIP = $c->state->field_fips_state_code['und'][0]['value'];
while(strlen($stateFIP) < 2){
    $stateFIP = '0' . $stateFIP;
}
$countyHealthFIP = $stateFIP.$countyFIP;
$countyHealthQuery = db_query('select * from data_health_countyhealth where FIPS = ? order by DataYear desc ', array($countyHealthFIP));
$c->countyHealthData = array();
$countyHealthQuery = $countyHealthQuery->fetchAssoc();

print livHelper::ordinalSuffix($countyHealthQuery['OutcomeRank']) . ' in health outcomes within the state of ' . $c->state->title . '.</p>';
print '<ul class="clearfix infograph">
  <li class="one-third">
    <h4><span class="red">Acute Care </span>Hospitals</h4>
    <span class="large-value red">' . count($c->hospitals->byType['Acute Care Hospitals']) . '</span>
    <span class="description">Within 60 miles of <br>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'].'</span>
  </li>
  <li class="one-third">
    <h4><span class="blue">Veteran\'s </span>Hospitals</h4>';
if (array_key_exists('ACUTE CARE - VETERANS ADMINISTRATION', $c->hospitals->byType)) {
  print '<span class="large-value blue">' . count($c->hospitals->byType['ACUTE CARE - VETERANS ADMINISTRATION']) . '</span>';
}
else{
  print '<span class="large-value blue">0</span>';
}
print '<span class="description">Within 60 miles of <br>' . $c->title . ', ' .
    $c->state->field_state_code['und'][0]['value'] . '</span>
  </li>
  <li class="one-third">
    <h4><span class="orange">Children\'s </span>Hospitals</h4>';
if (array_key_exists('Childrens', $c->hospitals->byType)){
    print '
    <span class="large-value orange">' . count($c->hospitals->byType['Childrens']) . '</span>';
}
else {
    print '<span class="large-value orange">0</span>';
}
print '<span class="description">Within 60 miles of <br>' . $c->title . ', ' .
    $c->state->field_state_code['und'][0]['value'].'</span>
  </li>
</ul>';

$total = count($c->hospitals->nearby);
$forProfit = 0;
$nonProfit = 0;
$federal = 0;
$local = 0;
if (array_key_exists('Proprietary',$c->hospitals->byOwnership)) {
  $forProfit = count($c->hospitals->byOwnership['Proprietary']);
}
if (array_key_exists('Voluntary non-profit - Private',$c->hospitals->byOwnership)) {
  $nonProfit += count($c->hospitals->byOwnership['Voluntary non-profit - Private']);
}
if (array_key_exists('Voluntary non-profit - Other',$c->hospitals->byOwnership)) {
  $nonProfit += count($c->hospitals->byOwnership['Voluntary non-profit - Other']);
}
if (array_key_exists('Voluntary non-profit - Church',$c->hospitals->byOwnership)) {
  $nonProfit += count($c->hospitals->byOwnership['Voluntary non-profit - Church']);
}
if (array_key_exists('Government - Federal',$c->hospitals->byOwnership)) {
  $federal = count($c->hospitals->byOwnership['Government - Federal']);
}
if (array_key_exists('Government - Hospital District or Authority',$c->hospitals->byOwnership)) {
  $local = count($c->hospitals->byOwnership['Government - Hospital District or Authority']);
}
if (array_key_exists('Government - Local',$c->hospitals->byOwnership)) {
  $local += count($c->hospitals->byOwnership['Government - Local']);
}

print '<ul class="clearfix infograph">
  <li class="one-third">
    <h4>Average ER Wait Time</h4>';
print '
    <span class="large-value green">'.$c->hospitals->avgWait.'</span> minutes
    <span class="description">Average Wait time at<br> emergency rooms in<br>' . $c->title . ', ' . $c->state->field_state_code[LANGUAGE_NONE][0]['value'] . '</span>
  </li>
  <li class="two-third last">
    <h4>Hospital Ownership</h4>
    <ul>
      <li class="one-fourth">
        <span class="donut-chart" id="for-profit">
          <input value="' . number_format((($forProfit/$total)*100),0) . '%" class="donut-graph">
          <label for="for-profit">For-Profit</label>
        </span>
      </li>
      <li class="one-fourth">
        <span class="donut-chart" id="non-profit">
          <input value="' . number_format((($nonProfit/$total)*100),0) . '%" class="donut-graph">
          <label for="non-profit">NonProfit</label>
        </span>
      </li>
      <li class="one-fourth">
        <span class="donut-chart" id="local-state">
          <input value="' . number_format((($local/$total)*100),0) . '%" class="donut-graph">
          <label for="local-state">Local/State Gov\'t</label>
        </span>
      </li>
      <li class="one-fourth">
        <span class="donut-chart" id="federal">
          <input value="' . number_format((($federal/$total)*100),0) . '%" class="donut-graph">
          <label for="federal">Federal Gov\'t</label>
        </span>
      </li>
    </ul>
  </li>
</ul>
</div>';
print '<span class="padded description data-source">Source: Centers for Medicare & Medicaid Services</span>';

print citySectionInclude('stubs/promote-city');

print citySectionInclude('stubs/ad728middle');

print
'<div class="locations-nearby padded grey-bg shadow-inset-lr clearfix">' .
  '<span class="heading">Hospitals in <strong>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '</strong></span>' .
  '<span class="locations-nearby-container clearfix">' .
    '<span class="location-listings">' .
      '<ul>';
      $active = FALSE;
      foreach($c->hospitals->nearby as $hospital) {
        $hospitalData = $hospital->data;
        print '<li class="';
        if(!$active) { print 'active '; $active = TRUE;}
        print 'listing"><i class="icon-pin green"></i>' .
          '<h5>' . $hospitalData->HospName . '</h5>' .
          '<span class="summary">' .
            '<span>' . $hospitalData->HospType . '</span>';
            if (is_numeric($hospitalData->AvgTimeEmpDept)) {
              print '<span>' . $hospitalData->AvgTimeEmpDept . ' avg wait time</span>';
            }
          print '</span>' . //end summary
          '<span class="address">
            <span class="street">' . $hospitalData->Address1 . '</span>
            <span class="city">' . $hospitalData->City.', ' . $hospitalData->StateAbbrev .
              ' ' . $hospitalData->ZipCode . '</span>
          </span>' .
          '<span class="location-details">';
             print '<span class="infograph">' .
               '<ul>';
                 print '<li>'.
                   '<h4>Patient Rating</h4>'.
                   '<p>Patients who gave the hospital a rating of 9 or 10 on a scale of 10</p>';
                   if (is_numeric($hospitalData->PatRate_PercAnswer)) {
                      $higherThanNationPatientRating = FALSE;
                      if ($hospitalData->PatRate_PercAnswer > $nationalRecommendResult['RateRate']) {
                        $higherThanNationPatientRating = TRUE;
                      }
                      $higherThanStatePatientRating = FALSE;
                      if ($hospitalData->PatRate_PercAnswer > $stateQueryResult['RateRate']) {
                        $higherThanStatePatientRating = TRUE;
                      }
                      print '<span class="donut-graph-container">
                        <input value="' . $hospitalData->PatRate_PercAnswer . '%" class="donut-graph">
                      </span>
                      <ul class="compare">
                        <li>';
                          print '<i class="';
                          if ($higherThanStatePatientRating) {
                            print 'icon-arrow-up green"></i> <span class="black">';
                            print number_format($hospitalData->PatRate_PercAnswer-$stateQueryResult['RateRate'], 0);
                            print '%</span> higher than';
                          }
                          else {
                            print 'icon-arrow-down red"></i> <span class="black">';
                            print number_format($stateQueryResult['RateRate']-$hospitalData->PatRate_PercAnswer, 0);
                            print '%</span> lower than';
                          }
                          print ' <span class="no-mobile">'.
                            $c->state->title.'</span><span class="mobile-only">'.
                            $c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</span> average
                        </li>
                        <li>
                          <i class="';
                          if ($higherThanNationPatientRating) {
                            print 'icon-arrow-up green';
                            $percDiff = number_format($hospitalData->PatRate_PercAnswer-$nationalRecommendResult['RateRate'], 0);
                          }
                          else {
                            print 'icon-arrow-down red';
                            $percDiff = number_format($nationalRecommendResult['RateRate']-$hospitalData->PatRate_PercAnswer, 0);
                          }
                          print '"></i> <span class="black">';
                          print $percDiff;
                          print '%</span> ';
                          if ($higherThanNationPatientRating) { print 'higher';}
                          else { print 'lower';}
                          print ' than national average
                        </li>
                      </ul>';
                   }
                   else {
                     print '<span class="donut-graph-container">
                       <input value="n/a" class="donut-graph">
                     </span>
                     <ul class="compare">
                       <li>Data not available for this hospital.</li></ul>';
                   }
                 print '</li>';
                 print '<li>' .
                   '<h4>Patient Recommendation</h4>' .
                   '<p>Patients who reported they would definitely recommend this hospital</p>';
                   if (is_numeric($hospitalData->PatRec_PercAnswer)) {
                     $higherThanNation = FALSE;
                     if ($hospitalData->PatRec_PercAnswer > $nationalRecommendResult['RecRate']) {
                       $higherThanNation = TRUE;
                     }
                     print '<span class="donut-graph-container" id="federal">
                       <input value="'.$hospitalData->PatRec_PercAnswer.'%" class="donut-graph">
                     </span>
                     <ul class="compare">
                       <li>';
                         $higherThanStatePatientRecommend = FALSE;
                         if ($hospitalData->PatRec_PercAnswer > $stateQueryResult['RecRate']) {
                           $higherThanStatePatientRecommend = TRUE;
                           print '<i class="icon-arrow-up green"></i>';
                           print '<span class="black">' .
                             number_format($hospitalData->PatRec_PercAnswer - $stateQueryResult['RecRate'],0).'% </span>'.
                           'higher than ';
                         }
                         else {
                           print '<i class="icon-arrow-down red"></i>';
                           print '<span class="black">' .
                             number_format($stateQueryResult['RecRate']-$hospitalData->PatRec_PercAnswer,0).'% </span>'.
                           'lower than ';
                         }
                         print '<span class="no-mobile">' .
                           $c->state->title . '
                         </span>
                         <span class="mobile-only">' .
                           $c->state->field_state_code[LANGUAGE_NONE][0]['value'] . '
                         </span> average
                       </li>
                       <li>
                         <i class="';
                           if ($higherThanNation) {
                             print 'icon-arrow-up green';
                             $percDiff = number_format($hospitalData->PatRec_PercAnswer-$nationalRecommendResult['RecRate'],0);
                           }
                           else {
                             print 'icon-arrow-down red';
                             $percDiff = number_format($nationalRecommendResult['RecRate']-$hospitalData->PatRec_PercAnswer,0);
                           }
                         print '"></i> <span class="black">';
                         print $percDiff.'%</span> ';
                         if ($higherThanNation) { print 'higher';}
                         else { print 'lower';}
                         print ' than national average';
                     print '</li></ul>';
                    //end compare^^
                   print '</li>';
                } else {
                    print '<span class="donut-graph-container" id="federal">
                            <input value="n/a" class="donut-graph">
                            </span>
                            <ul class="compare">
                                <li>Data not available for this hospital.</li></ul>';
                }
                    print '<li><h4>Emergency Room</h4>';
                    print '<p>Average time spent in the ER before seeing a health-care professional</p>';
                if(is_numeric($hospitalData->AvgTimeEmpDept)){
                    print '<span class="large-value white red-fill">'.$hospitalData->AvgTimeEmpDept.'<span>minutes</span></span>';
                    print '<ul class="compare">';
                        print '<li>';
                        if($hospitalData->StateAvgTimeEmgDept < $hospitalData->AvgTimeEmpDept){
                            print '<i class="icon-arrow-up red"></i>';
                            print '<span class="black">'.
                                number_format((1-($hospitalData->StateAvgTimeEmgDept/$hospitalData->AvgTimeEmpDept))*100,0).
                                '% </span> higher than ';
                        }else{
                            print '<i class="icon-arrow-down green"></i>';
                            print '<span class="black">'.
                                number_format((1-($hospitalData->AvgTimeEmpDept/$hospitalData->StateAvgTimeEmgDept))*100,0).
                                '% </span> lower than ';
                        }
                        print '<span class="no-mobile">'.$c->state->title.'</span>';
                        print '<span class="mobile-only">'.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</span>';
                        print ' average';
                        print '</li>';
                        print '<li>';
                        if($hospitalData->NatlAvgTimeEmgDept < $hospitalData->AvgTimeEmpDept){
                            print '<i class="icon-arrow-up red"></i>';
                            print '<span class="black">';
                            print number_format((1-($hospitalData->NatlAvgTimeEmgDept/$hospitalData->AvgTimeEmpDept))*100,0).
                            '% </span> higher than ';
                        }else{
                            print '<i class="icon-arrow-down green"></i>';
                            print '<span class="black">'.
                                number_format((1-($hospitalData->AvgTimeEmpDept/$hospitalData->NatlAvgTimeEmgDept))*100,0).
                                '% </span> lower than ';
                        }
                        print 'national average</li>';
                    print '</ul>';//end compare
                    print '</li>';//end ER li
                }else{
                    print '<span class="large-value white red-fill">n/a</span>';
                    print '<ul class="compare">';
                    print '<li>Data not available for this hospital.</li></ul>';

                }
                //end location listing
                        print '</ul>';
                        print '</span>';

                    print '</span>';//end location details
            }
print '</ul>';

print '<span class="pages clearfix"><ul>';
print '<li class="previous"><a href="#">Previous</a></li>';
print '<li class="next"><a href="#">Next</a></li>';
print '</ul></span>';
        print '</span>'.
    '</span>'.
'</div>';
print citySectionInclude('stubs/ad728');

$content = getContentByTermAndPlace('Health',$c,0);
if (!empty($content['nodes'])) {
  $heading = 'Articles related to <b>Health in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
  print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Health'));
}
print citySectionInclude('real-estate/block-listing');
print citySectionInclude('stubs/ad728bottom');
