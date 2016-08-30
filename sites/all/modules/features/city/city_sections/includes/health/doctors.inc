<?php
global $title;
$c = getCityContext();
$title = 'Doctors in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];
print citySectionInclude('stubs/ad728');
$physicians = db_query('select * from data_health_physicians where City = ? and StateAbbrev = ?', array(
    strtoupper($c->title),$c->state->field_state_code['und'][0]['value']));
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

print '<div class="city-topic-summary padded">';
if ($physicians->rowCount() < 1) {
  $view = views_get_view('nearby_cities');
  $view->execute('block');
  $nearby = array();
  foreach($view->result as $row){
    $nearbyc = city_node_load($row->nid);
    $nearby[] = l($nearbyc->title .' ('.$nearbyc->state->field_state_code['und'][0]['value'] . ')', strtolower($nearbyc->state->field_state_code['und'][0]['value']) . '/' . strtolower($nearbyc->title) . '/health/doctors', array('html' => TRUE));
  }

  print '<h2>According to the Medicare.gov database, there are no physician offices in ' . $c->title . '.</h2><p>For nearby doctors see ' . implode(', ', $nearby) . '</p>';
}
else {
    $c->physiciansByColumn = array();
    $physiciansSort = array();
    $pdata = $physicians->fetchAllAssoc('ID');
    foreach($pdata as $id => $doctor) {
        foreach($doctor as $col => $colval) {
            if(array_key_exists($col,$physiciansSort)) {
                if(array_key_exists($colval,$physiciansSort[$col])){
                    $physiciansSort[$col][$colval] = ($physiciansSort[$col][$colval]+1);
                }
                else {
                    $physiciansSort[$col][$colval] = 1;
                }
            }
            else {
                $physiciansSort[$col] = array();
                $physiciansSort[$col][$colval] = 1;
            }
        }
    }
    arsort($physiciansSort['PrimSpecialty'],SORT_NATURAL);
    $sortedBySpecialty = $physiciansSort['PrimSpecialty'];
    $docCount = 0;
    $nurseCount = 0;
    foreach ($sortedBySpecialty as $specialty => $count) {
      if (preg_match('/NURSE/', $specialty)) {
        $nurseCount += $count;
        unset($sortedBySpecialty[$specialty]);
      }
      else {
        $docCount += $count;
      }
    }
    $sortedBySpecialty = array_slice($sortedBySpecialty, 0, 6);
    $specialtyBody = '<ul class="clearfix infograph">';
    $maxSpeccol = round(count($sortedBySpecialty)/2);
    $specialtyI = 1;
    $specialtyBody .= '<h4 class="heading padded">Top Medical Specialties</h4><span></span>';
    foreach($sortedBySpecialty as $specialty => $count) {
        if ($specialtyI == 1 || $specialtyI == $maxSpeccol+1) {
          $specialtyBody .= '<li class="half">';
          if ($specialtyI == 1) {
          }
        }
        $specialtyBody .= '<span class="large-value green">' . $count . '</span> ';
        $specialtyBody .= formatSpecialty($specialty);
        $specialtyBody .= '<br/><br/>';
        $specialtyRank[] = $specialty;
        if ($specialtyI == $maxSpeccol || $specialtyI == count($sortedBySpecialty)) {
          $specialtyBody .= '</li>';
        }
        $specialtyI++;
    }
    $specialtyBody .= '</ul>';
    print '<h1>' . $title . '</h1>';
    $mainBody = 'There are ' . number_format($docCount) . ' doctors and ' . number_format($nurseCount) .' nurses in ' . $c->title .'. ';
    $mainBody .= 'The top specialties are ';
    $specCount = count($sortedBySpecialty) > 3 ? 3 : count($sortedBySpecialty);
    foreach ($sortedBySpecialty as $specialty => $count) {
      if ($specCount > 0) {
        $mainBody .= ucwords(strtolower($specialty)) . ' with ' . number_format($count) . ' doctors';
        if ($specCount > 2) {
          $mainBody .= ', ';
        }
        if ($specCount == 2) {
          $mainBody .= ' and ';
        }
      }
      $specCount--;
      if ($specCount == 0) break;
    }
    $mainBody .= '. ';
    $ratio = number_format($c->field_population['und'][0]['value'] / count($pdata),0);
    $_PrimCarePhyRatio = explode(':', $countyHealthQuery['PrimCarePhyRatio']);
    $_PrimCarePhyRatio[0] = number_format($_PrimCarePhyRatio[0]);
    $_str_PrimCarePhyRatio = implode(':', $_PrimCarePhyRatio);
    $mainBody .= "According to County Health Rankings &amp; Roadmaps, " . $c->county->name . ' has a ratio of ';
    $mainBody .= $_str_PrimCarePhyRatio . ' residents per doctor, ranking ' . ($countyHealthQuery['ClinCareRank'] > 1 ? livHelper::ordinalSuffix($countyHealthQuery['ClinCareRank']) : '') . ' in ' . $c->state->title . '. ';
    $mainBody .= '
<ul class="clearfix infograph">
  <li class="half">
    <span class="circle-stroke red-stroke"><i class="icon-doctor"></i></span>

      <span class="red large-value">' . number_format($docCount) . '</span><span class="description"> doctors in<br/>' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '
    </span>
  </li>
  <li class="half">
    <span class="circle-stroke blue-stroke"><i class="icon-doctor"></i></span>

      <span class="blue large-value">' . $ratio . ':1</span><span class="description">population per<br/>medical doctor ratio
    </span>
  </li>
</ul>';
    $mainBody .= '<span class="description-small grey">Source: <a href="http://www.countyhealthrankings.org/" title="_blank">County Health Rankings &amp; Roadmaps</a></span>';
    $mainBody .= $specialtyBody;
    $mainBody .= '<span class="description-small grey">Source: <a href="http://www.countyhealthrankings.org/" title="_blank">County Health Rankings &amp; Roadmaps</a></span>';
    print $mainBody;
}
print '</div>';
function formatSpecialty($s){
    $s = ucwords(strtolower($s));
    // Special handling of Gynecology which ucwords does not capitalize.
    if (strstr($s, '/gynecology')) {
      $s = str_replace('/gynecology', '/Gynecology', $s);
    }
    return trim($s);
}

print citySectionInclude('stubs/ad728middle');

$content = getContentByTermAndPlace('Health',$c,0);
if (!empty($content['nodes'])) {
  $heading = 'Articles related to <b>Health in '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</b>';
  print citySectionInclude('stubs/content-cards',array('nodes'=>$content['nodes'],'heading'=>$heading,'total'=>$content['total'],'cnid'=>$c->nid,'terms'=>'Health'));
}
print citySectionInclude('real-estate/block-listing');
print citySectionInclude('stubs/ad728bottom');