<?php

function livability_js_alter(&$javascript) {
  foreach ($javascript as $name => &$values) {
    $values['async'] = TRUE;
  }
}

function livability_preprocess_node(&$vars) {
  // Get context plugin to check that for blocks
  $reaction = context_get_plugin('reaction', 'block');
  // Get a list of all the regions for this theme
  foreach (system_region_list($GLOBALS['theme']) as $region_key => $region_name) {
    // Get the content for each region and add it to the $region variable
    if ($blocks = block_get_blocks_by_region($region_key)) {
      $vars['region'][$region_key] = $blocks;
      $vars['blockregion'][$region_key] = $blocks;
    }
    else {
      $vars['region'][$region_key] = array();
    }
    if ($context_blocks = $reaction->block_get_blocks_by_region($region_key)) {
      $vars['region'][$region_key] = array_merge($vars['region'][$region_key], $context_blocks);
    }
  }
  if ($vars['node']->type == 'city') {
    $countyNID = 'node/'.$vars['node']->field_county[LANGUAGE_NONE][0]['entity']->nid;
    $vars['countyPath'] = drupal_get_path_alias($countyNID);
    $stateNID = 'node/'.$vars['node']->field_state[LANGUAGE_NONE][0]['entity']->nid;
    $vars['statePath'] = drupal_get_path_alias($stateNID);
    $state = $vars['node']->field_state[LANGUAGE_NONE][0]['entity']->field_state_code[LANGUAGE_NONE][0]['value'];

    if ($vars['node']->body == NULL) {
      $output = '';
      $output .= $vars['node']->title.' is located in <a href="/'.$vars['countyPath'].'">'.$vars['node']->field_county[LANGUAGE_NONE][0]['entity']->title.'</a>, <a href="/'.$vars['statePath'].'">'.$vars['node']->field_state[LANGUAGE_NONE][0]['entity']->title.'</a>. ';
      $white = isset($vars['node']->field_ethnicity_white[LANGUAGE_NONE][0]['value']) ? $vars['node']->field_ethnicity_white[LANGUAGE_NONE][0]['value'] : 0;
      $black = isset($vars['node']->field_ethnicity_black[LANGUAGE_NONE][0]['value']) ? $vars['node']->field_ethnicity_black[LANGUAGE_NONE][0]['value'] : 0;
      $indian = isset($vars['node']->field_ethnicity_indian[LANGUAGE_NONE][0]['value']) ? $vars['node']->field_ethnicity_indian[LANGUAGE_NONE][0]['value'] : 0;
      $hispanic = isset($vars['node']->field_ethnicity_hispanic[LANGUAGE_NONE][0]['value']) ? $vars['node']->field_ethnicity_hispanic[LANGUAGE_NONE][0]['value'] : 0;
      $asian = isset($vars['node']->field_ethnicity_asian[LANGUAGE_NONE][0]['value']) ? $vars['node']->field_ethnicity_asian[LANGUAGE_NONE][0]['value'] : 0;
      $hawaiian = isset($vars['node']->field_ethnicity_hawiian[LANGUAGE_NONE][0]['value']) ? $vars['node']->field_ethnicity_hawiian[LANGUAGE_NONE][0]['value'] : 0;
      $other = isset($vars['node']->field_ethnicity_other[LANGUAGE_NONE][0]['value']) ? $vars['node']->field_ethnicity_other[LANGUAGE_NONE][0]['value'] : 0;
      $other = $other + $hawaiian + $indian;
      $total = $white + $black + $indian + $hispanic + $asian + $other;

      $output .= 'The population is ' . number_format($white / $total * 100, 0) . '% White, ';
      $output .= number_format($black / $total * 100, 0) . '% Black, ' .
          //number_format($indian/$total*100,1).'% American Indian, '.
          number_format($asian / $total * 100, 0) . '% Asian and ' .
          number_format(($indian + $hawaiian) / $total * 100, 0) . '% Native American or Native Hawaiian. ' .
          number_format($other / $total * 100, 0) . '% identify as another race or ethnicity, or two or more races. ' .
          number_format($hispanic / $total * 100, 0) . '% of residents are of Hispanic or Latino origin. ';

      $unemploymentRate = number_format($vars['node']->field_unemployed[LANGUAGE_NONE][0]['value']/($vars['node']->field_employed[LANGUAGE_NONE][0]['value']+$vars['node']->field_employed_armed_forces[LANGUAGE_NONE][0]['value'])*100,2);

      //print 'The cost of living for its '.number_format($vars['node']->field_population[LANGUAGE_NONE][0]['value'],0).

      //    ' residents is <higher/lower> than the national average. '.
      $output .= 'The median income is $'.number_format($vars['node']->	field_median_household_income[LANGUAGE_NONE][0]['value'],0).
            ' and the median home value is ';
      if(isset($vars['node']->field_median_home_price[LANGUAGE_NONE][0]['value'])){
        $output .= '$'.number_format($vars['node']->field_median_home_price[LANGUAGE_NONE][0]['value'],0).'. ';
      }else{
        $output .= ' not available for this locality. ';
      }
      //'It’s population has been growing/shrinking> at a rate of growth> since 2000. '.
      //print //'The unemployment rate is '.$unemploymentRate.'% compared to the 6.1% unemployment rate for the United States (as of August 2014). '.
      //'Workers commute an average of '.$vars['node']->field_avg_commute[LANGUAGE_NONE][0]['value'].' minutes to work each day. ';
      //'Its crime rate is index> higher/lower> than the national average. ';
      $output .= 'For more on schools, real estate, business and health care in '.$vars['node']->title.', see each of the tabs above. ';

      $fh = fopen(drupal_get_path('module','walkscore').DIRECTORY_SEPARATOR.'walkscore.csv','r');

      $fipsPlaceCode = $vars['node']->field_state[LANGUAGE_NONE][0]['entity']->field_fips_state_code[LANGUAGE_NONE][0]['value'];
      if(strlen($vars['node']->field_place_id[LANGUAGE_NONE][0]['value'])<5){
        $fipsPlaceCode .= '0'.$vars['node']->field_place_id[LANGUAGE_NONE][0]['value'];
      }else{
        $fipsPlaceCode .= $vars['node']->field_place_id[LANGUAGE_NONE][0]['value'];
      }
      $walkscoreData = false;
      while($row = fgetcsv($fh)){
        if($fipsPlaceCode == $row[0]){
          //print_r($row);
          $walkscoreData = $row;
        }
      }
      if($walkscoreData !== false){
        $pieces = explode(' ',$vars['node']->title);
        $cityURL = $vars['node']->field_state[LANGUAGE_NONE][0]['entity']->field_state_code[LANGUAGE_NONE][0]['value'].'/'.implode('_',$pieces);
        $output .= 'Walkability can be a key driver of the overall livability of a community. ';
        $output .= $vars['node']->title.' has a <a href="http://www.walkscore.com/'.
            $cityURL.'" target="_new"> Walk Score &reg;</a> of <a href="http://www.walkscore.com/'.$cityURL.'" target="_new">'.number_format($walkscoreData[4],0).'</a>.';
      }
      $vars['body'][LANGUAGE_NONE][0]['value'] = $output;
      $vars['body'][LANGUAGE_NONE][0]['format'] = 'filtered_html';
      $vars['body'][LANGUAGE_NONE][0]['safe_value'] = $output;
    }
  }
}

function livability_preprocess_block(&$vars, $hook) {
  if (isset($GLOBALS['currentCity'])) {
    $vars['block']->node_type = $GLOBALS['currentCity']->type;
  }
  $vars['ads'] = $GLOBALS['ads'];
}

function livability_preprocess_page(&$vars, $hook) {

  if (isset($vars['node']->type)) {
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
    if (isset($vars['node']->nid)) {
      $vars['theme_hook_suggestions'][] = "node__" . $vars['node']->nid;
    }
  }
  if (isset($vars['page']['#type'])) {
    if ($vars['page']['#type'] == "subpage") {
      $subtype = array_pop(explode('/', $_GET['q']));
      $vars['theme_hook_suggestions'][] = 'subpage__' . $subtype;
      //$vars['theme_hook_suggestions'][] = 'subpage__' . $subtype . '_parrent__'. $vars['node']->nid;
    }
  }
	
  //$vars['logo'] = str_replace('.png', '.svg', $vars['logo']);

  $imagesDir = drupal_get_path('theme', 'livability').'/images/hero/';
  $images = glob($imagesDir . '*.{jpg,jpeg,png,gif}', GLOB_BRACE);
  $randomImage = $images[array_rand($images)];
  $vars['hero_img'] = $randomImage;

  /*
  $project_code = theme_get_setting('project_code');
  $path = drupal_get_path_alias($_GET['q']);
  $target = '';
  if (drupal_is_front_page()) {
    $target .= "googletag.pubads().setTargeting('Project', ['".$project_code."']);" .PHP_EOL;
    $adstagoutput = PHP_EOL . $target;
  }
  if (isset($vars['node'])) {
    if ($vars['node']->type == 'state') {
      $state_id = $vars['node']->field_fips[LANGUAGE_NONE][0]['value'];
      $state = $vars['node']->field_usps_code[LANGUAGE_NONE][0]['value'];
      $target .= "googletag.pubads().setTargeting('Project', ['".$project_code."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('State_ID', ['".$state_id."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('State', ['".$state."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('Path', ['".$path."']);" .PHP_EOL;
      $adstagoutput = PHP_EOL . $target;
    } elseif ($vars['node']->type == 'county') {
      $state_id = $vars['node']->field_state[LANGUAGE_NONE][0]['entity']->field_fips[LANGUAGE_NONE][0]['value'];
      $state = $vars['node']->field_state[LANGUAGE_NONE][0]['entity']->field_usps_code[LANGUAGE_NONE][0]['value'];
      $county_id  = $vars['node']->field_fips[LANGUAGE_NONE][0]['value'];
      $target .= "googletag.pubads().setTargeting('Project', ['".$project_code."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('State_ID', ['".$state_id."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('State', ['".$state."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('County_ID', ['".$county_id."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('Path', ['".$path."']);" .PHP_EOL;
      $adstagoutput = PHP_EOL . $target;
    } elseif ($vars['node']->type == 'city') {
      $target .= "googletag.pubads().setTargeting('Project', ['".$project_code."']);" .PHP_EOL;
      $state_id = $vars['node']->field_state[LANGUAGE_NONE][0]['entity']->field_fips[LANGUAGE_NONE][0]['value'];
      $target .= "googletag.pubads().setTargeting('State_ID', ['".$state_id."']);" .PHP_EOL;
      $state = $vars['node']->field_state[LANGUAGE_NONE][0]['entity']->field_usps_code[LANGUAGE_NONE][0]['value'];
      $target .= "googletag.pubads().setTargeting('State', ['".$state."']);" .PHP_EOL;
      if (!empty($vars['node']->field_metro[LANGUAGE_NONE][0]['entity'])) {
        $metro = $vars['node']->field_metro[LANGUAGE_NONE][0]['entity']->field_fips[LANGUAGE_NONE][0]['value'];
        $target .= "gogoletag.pubads().setTargeting('Metro', ['".$metro."'])" .PHP_EOL;
      }
      $county_id  = $vars['node']->field_county[LANGUAGE_NONE][0]['entity']->field_fips[LANGUAGE_NONE][0]['value'];
      $target .= "googletag.pubads().setTargeting('County_ID', ['".$county_id."']);" .PHP_EOL;
      if (!empty($vars['node']->field_project_code[LANGUAGE_NONE][0]['value'])) {
        $print_code = $vars['node']->field_project_code[LANGUAGE_NONE][0]['value'];
        $target .= "gogoletag.pubads().setTargeting('Project_Code', ['".$print_code."'])" .PHP_EOL;
      }
      $city_id = $vars['node']->field_fips[LANGUAGE_NONE][0]['value'];
      $target .= "googletag.pubads().setTargeting('City_ID', ['".$city_id."']);" .PHP_EOL;
	  $liv_fips = $vars['node']->field_liv_fips[LANGUAGE_NONE][0]['value'];
	  $target .= "googletag.pubads().setTargeting('Liv_FIPS', ['".$liv_fips."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('Path', ['".$path."']);" .PHP_EOL;
      
      $adstagoutput = PHP_EOL . $target;;
    } else {
      $target .= "googletag.pubads().setTargeting('Project', ['".$project_code."']);" .PHP_EOL;
      $target .= "googletag.pubads().setTargeting('Path', ['".$path."']);" .PHP_EOL;
      $adstagoutput = PHP_EOL . $target;
    }
  }
  $dfp = <<<EOT
(function() {
  var useSSL = 'https:' == document.location.protocol;
  var src = (useSSL ? 'https:' : 'http:') +
	  '//www.googletagservices.com/tag/js/gpt.js';
  document.write('<scr' + 'ipt src="' + src + '"></scr' + 'ipt>');
})();
googletag.cmd.push(function() {
googletag.defineSlot('/17972781/liv_article_button_180x150', [180, 150], 'div-gpt-ad-1472665518839-1').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_byline_promo_300x100', [300, 100], 'div-gpt-ad-1472665518839-2').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_FilmStrip_300x600', [300, 600], 'div-gpt-ad-1472665518839-3').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_FilmStrip_mobile_300x250', [300, 250], 'div-gpt-ad-1472665518839-4').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_Floating_MR_300x250', [300, 250], 'div-gpt-ad-1472665518839-5').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_FUBA_Bottom_960x90', [[728, 90], [970, 90]], 'div-gpt-ad-1472665518839-6').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_FUBA_Bottom_960x90_Global', [[960, 90], [728, 90]], 'div-gpt-ad-1472665518839-7').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_FUBA_Expandable_960x360', [[728, 90], [960, 360]], 'div-gpt-ad-1472665518839-8').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_FUBA_Top_960x90', [[728, 90], [970, 90]], 'div-gpt-ad-1472665518839-9').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_FUBA_Top_960x90_Global', [[960, 90], [728, 90]], 'div-gpt-ad-1472665518839-10').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_HalfPage_300x600', [[160, 600], [300, 250], [300, 600]], 'div-gpt-ad-1472665518839-11').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_HFBA_234x60', [234, 60], 'div-gpt-ad-1472665518839-12').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_HR_300x125', [[300, 250], [300, 125]], 'div-gpt-ad-1472665518839-13').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_HR_300x125_Global', [[300, 250], [300, 125]], 'div-gpt-ad-1472665518839-14').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_HR_ProductAd_300x125', [[300, 250], [300, 125]], 'div-gpt-ad-1472665518839-15').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_lb_adsense_728x90', [728, 90], 'div-gpt-ad-1472665518839-16').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_lb_bottom_728x90', [728, 90], 'div-gpt-ad-1472665518839-17').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_lb_dm_728x90', [728, 90], 'div-gpt-ad-1472665518839-18').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_lb_middle_728x90', [728, 90], 'div-gpt-ad-1472665518839-19').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_lb_top_728x90', [728, 90], 'div-gpt-ad-1472665518839-20').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_logo_business_88x31', [88, 31], 'div-gpt-ad-1472665518839-21').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_logo_government_88x31', [88, 31], 'div-gpt-ad-1472665518839-22').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_logo_health_88x31', [88, 31], 'div-gpt-ad-1472665518839-23').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_logo_real_estate_88x31', [88, 31], 'div-gpt-ad-1472665518839-24').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_logo_schools_88x31', [88, 31], 'div-gpt-ad-1472665518839-25').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_logo_transportation_88x31', [88, 31], 'div-gpt-ad-1472665518839-26').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Activities_88x31', [88, 31], 'div-gpt-ad-1472665518839-27').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Activities_Facts_88x31', [88, 31], 'div-gpt-ad-1472665518839-28').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Attractions_88x31', [88, 31], 'div-gpt-ad-1472665518839-29').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Attractions_Facts_88x31', [88, 31], 'div-gpt-ad-1472665518839-30').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Business_88x31', [88, 31], 'div-gpt-ad-1472665518839-31').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Facts_88x31', [88, 31], 'div-gpt-ad-1472665518839-32').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Food_88x31', [88, 31], 'div-gpt-ad-1472665518839-33').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Health_88x31', [88, 31], 'div-gpt-ad-1472665518839-34').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Living_88x31', [88, 31], 'div-gpt-ad-1472665518839-35').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Schools_88x31', [88, 31], 'div-gpt-ad-1472665518839-36').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MicroBar_Shopping_88x31', [88, 31], 'div-gpt-ad-1472665518839-37').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mobile_lb_adsense_320x50', [320, 50], 'div-gpt-ad-1472665518839-38').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mobile_lb_bottom_320x50', [320, 50], 'div-gpt-ad-1472665518839-39').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mobile_lb_dm_320x50', [320, 50], 'div-gpt-ad-1472665518839-40').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mobile_lb_middle_320x50', [320, 50], 'div-gpt-ad-1472665518839-41').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mobile_lb_top_320x50', [320, 50], 'div-gpt-ad-1472665518839-42').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MR_300x250', [300, 250], 'div-gpt-ad-1472665518839-43').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MR_300x250_Global', [300, 250], 'div-gpt-ad-1472665518839-44').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mr_AdSense_300x250', [300, 250], 'div-gpt-ad-1472665518839-45').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mr_bottom_300x250', [300, 250], 'div-gpt-ad-1472665518839-46').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mr_dm_300x250', [300, 250], 'div-gpt-ad-1472665518839-47').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mr_middle_300x250', [300, 250], 'div-gpt-ad-1472665518839-48').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_MR_ProductAd_300x250', [300, 250], 'div-gpt-ad-1472665518839-49').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_mr_top_300x250', [300, 250], 'div-gpt-ad-1472665518839-50').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_PushDown_Collapsed_970x90', [[728, 90], [970, 90]], 'div-gpt-ad-1472665518839-51').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_PushDown_Collapsed_970x90_Bot', [[728, 90], [970, 90]], 'div-gpt-ad-1472665518839-52').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_PushDown_Collapsed_970x90_Mid', [[728, 90], [970, 90]], 'div-gpt-ad-1472665518839-53').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_PushDown_Expanded_970x415', [[970, 415], [728, 90], [970, 90]], 'div-gpt-ad-1472665518839-54').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_PushDown_Expanded_970x415_Bot', [[970, 415], [728, 90], [970, 90]], 'div-gpt-ad-1472665518839-55').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_PushDown_Expanded_970x415_Mid', [[970, 415], [728, 90], [970, 90]], 'div-gpt-ad-1472665518839-56').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_Rec_180x150', [180, 150], 'div-gpt-ad-1472665518839-57').addService(googletag.pubads());
    googletag.defineSlot('/17972781/Liv_Square_Button_125x125', [125, 125], 'div-gpt-ad-1472665518839-58').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_Top10_logo_88x31', [88, 31], 'div-gpt-ad-1472665518839-59').addService(googletag.pubads());
    googletag.defineSlot('/17972781/liv_Top10_MBLO_33x81', [88, 31], 'div-gpt-ad-1472665518839-60').addService(googletag.pubads());
    googletag.pubads().enableSingleRequest();
    googletag.enableServices();
});
EOT;
  $script = $dfp;
  $path = current_path();
  $path_alias = drupal_lookup_path('alias',$path);
  $file = file_build_uri('/js/dfp/'.hash('ripemd160', $path_alias).'_'.hash('md5', $path_alias).'_DFP.js');
  file_put_contents($file, $script);
  drupal_add_js($file);

  $dir = "sites/default/files/js/dfp/";
  foreach (glob($dir."*") as $file) {
  if (filemtime($file) < time() - 86400) {
	  unlink($file);
	  }
  }
  */

  if ($vars['is_front'] == 'true') {
    drupal_add_js(drupal_get_path('module', 'find_city') . '/find_city.js');
  }
  if (!empty($vars['node']->field_banner_image)) {
    $vars['banner_image'] = image_style_url('1400x453', $vars['node']->field_banner_image[LANGUAGE_NONE][0]['uri']);
  }
  if ($vars['node']->type == 'city') {
    $state = $vars['node']->field_state[LANGUAGE_NONE][0]['entity']->field_state_code[LANGUAGE_NONE][0]['safe_value'];
    $countyNID = 'node/'.$vars['node']->field_county[LANGUAGE_NONE][0]['entity']->nid;
    $vars['countyPath'] = drupal_get_path_alias($countyNID);
  }
}

function livability_form_views_exposed_form_alter(&$form, $form_state) {
  if ($form['#id'] == 'views-exposed-form-search-block-1') {
    $form['combine']['#size'] = 23;
    //$form['search_api_views_fulltext']['#default_value'] = 'Enter a City name here';
  }
  if ($form['#id'] == 'views-exposed-form-find-a-city-block-1') {
    $form['search_api_views_fulltext']['#size'] = 23;
  }
}
