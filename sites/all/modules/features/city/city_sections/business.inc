<?php
function liv_business(){
    global $title;
    $c = getCityContext();
    $countyFIP = $c->county->field_fips[LANGUAGE_NONE][0]['value'];
    if(strlen($countyFIP) < 3){ $countyFIP = '0'.$countyFIP;}
    $stateFIP = $c->state->field_fips[LANGUAGE_NONE][0]['value'];
    if(strlen($stateFIP) < 2){ $stateFIP = '0'.$stateFIP;}
    $q = 'select * from data_business_buspatterns_county where FIPs_State=? and FIPS_County=?';
    $county = db_query($q,array($stateFIP,$countyFIP));
    $data = $county->fetchAllAssoc('ID');
    $naics = getNAICSLookup();
    $q = 'select * from data_business_laborforce_county where FIPS_State=? and FIPS_County=? order by ID DESC limit 1';
    $labor = db_query($q,array($stateFIP,$countyFIP));
    $countyLabor = $labor->fetchAssoc();
    $uniqueIndustries = array();
    $totalEmployed = 0;
    foreach($data as $r){
        if(is_numeric($r->NAICS) && is_numeric($r->EmploysNoise) && $r->EmploysNoise > 0
            && array_key_exists($r->NAICS,$naics)){
            if(!array_key_exists($r->NAICS,$uniqueIndustries)){ $uniqueIndustries[$r->NAICS] = 0;}
            $uniqueIndustries[$r->NAICS] = $uniqueIndustries[$r->NAICS] + $r->EmploysNoise;
            $totalEmployed += $r->EmploysNoise;
        }
    }
    arsort($uniqueIndustries,SORT_NUMERIC);
    switch(arg(3)){
        case 'major-industries':
            $q = 'select sum(NumEst1_4) fiveless, sum(NumEst5_9) tenless, sum(NumEst10_19) twentyless, '.
                'sum(NumEst20_49) fiftyless, sum(NumEst50_99) hundredless,sum(NumEst100_249) twofifty, '.
                'sum(NumEst250_499) fivehundredless, sum(NumEst500_999) thousandless,sum(NumEst1000)thousand '.
                'from data_business_buspatterns_county where FIPs_State=? and FIPS_County=?';
            $sumQ = db_query($q,array($stateFIP,$countyFIP));
            $sumData = $sumQ->fetchAssoc();
            //var_dump($sumData);
            $mainBody = citySectionInclude('business/major-industries',array('c' => $c,
                'industries' => $uniqueIndustries,'naics' =>$naics,'countyLabor' => $countyLabor,'laborData'=>$data,
                'sums' => $sumData));
            break;
        case 'employment':
            $mainBody = citySectionInclude('business/employment');
            break;
        default:
            $mainBody = citySectionInclude('business/index',array('c' => $c,
                'industries' => $uniqueIndustries,'naics' =>$naics,'countyLabor' => $countyLabor));
            break;
    }
    drupal_set_title($title);
    return $mainBody;
}
function getNAICSLookup(){
    $ret = array();
    $handle = fopen(drupal_get_path('module','city_sections').
        DIRECTORY_SEPARATOR.'includes'.DIRECTORY_SEPARATOR.
        'business'.DIRECTORY_SEPARATOR.'NAICS-6-digit_2012_Codes.csv','r');
    while($r = fgetcsv($handle)){
        $name = preg_replace('/\(.*|\)/','',trim($r[1]));
        $ret[$r{0}] = $name;
    }
    return $ret;
}