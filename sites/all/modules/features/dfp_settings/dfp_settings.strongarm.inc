<?php
/**
 * @file
 * dfp_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dfp_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-ACTIVATE';
  $strongarm->value = 1;
  $export['jci-dfp-ACTIVATE'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-CATEGORY-KEY';
  $strongarm->value = 'Category';
  $export['jci-dfp-CATEGORY-KEY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-CATEGORY-TARGET';
  $strongarm->value = 1;
  $export['jci-dfp-CATEGORY-TARGET'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-CITY-KEY';
  $strongarm->value = 'City';
  $export['jci-dfp-CITY-KEY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-CITY-TARGET';
  $strongarm->value = 1;
  $export['jci-dfp-CITY-TARGET'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-CUSTOM-TARGET';
  $strongarm->value = 0;
  $export['jci-dfp-CUSTOM-TARGET'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-DOMAIN-KEY';
  $strongarm->value = '';
  $export['jci-dfp-DOMAIN-KEY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-DOMAIN-TARGET';
  $strongarm->value = 0;
  $export['jci-dfp-DOMAIN-TARGET'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-GLOBAL-KEY';
  $strongarm->value = '';
  $export['jci-dfp-GLOBAL-KEY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-GLOBAL-TARGET';
  $strongarm->value = 0;
  $export['jci-dfp-GLOBAL-TARGET'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-ID';
  $strongarm->value = 'ca-pub-0269980627110398';
  $export['jci-dfp-ID'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-NID-KEY';
  $strongarm->value = 'Nid';
  $export['jci-dfp-NID-KEY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-NID-TARGET';
  $strongarm->value = 1;
  $export['jci-dfp-NID-TARGET'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-PATH-KEY';
  $strongarm->value = 'Path';
  $export['jci-dfp-PATH-KEY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-PATH-TARGET';
  $strongarm->value = 1;
  $export['jci-dfp-PATH-TARGET'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-QUANTITY';
  $strongarm->value = 31;
  $export['jci-dfp-QUANTITY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-1';
  $strongarm->value = 'LIV_LB_Top_728x90';
  $export['jci-dfp-SLOT-1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-10';
  $strongarm->value = 'LIV_Mobile_LB_DM_320x50';
  $export['jci-dfp-SLOT-10'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-11';
  $strongarm->value = 'LIV_MR_Top_300x250';
  $export['jci-dfp-SLOT-11'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-12';
  $strongarm->value = 'LIV_MR_Middle_300x250';
  $export['jci-dfp-SLOT-12'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-13';
  $strongarm->value = 'LIV_MR_Bottom_300x250';
  $export['jci-dfp-SLOT-13'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-14';
  $strongarm->value = 'LIV_MR_AdSense_300x250';
  $export['jci-dfp-SLOT-14'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-15';
  $strongarm->value = 'LIV_MR_DM_300x250';
  $export['jci-dfp-SLOT-15'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-16';
  $strongarm->value = 'LIV_Logo_Business_88x31';
  $export['jci-dfp-SLOT-16'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-17';
  $strongarm->value = 'LIV_Logo_Health_88x31';
  $export['jci-dfp-SLOT-17'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-18';
  $strongarm->value = 'LIV_Logo_Schools_88x31';
  $export['jci-dfp-SLOT-18'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-19';
  $strongarm->value = 'liv_logo_real_estate_88x31';
  $export['jci-dfp-SLOT-19'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-2';
  $strongarm->value = 'liv_lb_middle_728x90';
  $export['jci-dfp-SLOT-2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-20';
  $strongarm->value = 'LIV_Logo_Transportation_88x31';
  $export['jci-dfp-SLOT-20'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-21';
  $strongarm->value = 'LIV_Logo_Government_88x31';
  $export['jci-dfp-SLOT-21'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-22';
  $strongarm->value = 'LIV_Byline_promo_300x100';
  $export['jci-dfp-SLOT-22'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-23';
  $strongarm->value = 'LIV_Article_Button_180x150';
  $export['jci-dfp-SLOT-23'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-24';
  $strongarm->value = 'LIV_Article_Button_180x150';
  $export['jci-dfp-SLOT-24'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-25';
  $strongarm->value = 'LIV_MR_Top_300x250';
  $export['jci-dfp-SLOT-25'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-26';
  $strongarm->value = 'liv_FilmStrip_mobile_300x250';
  $export['jci-dfp-SLOT-26'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-27';
  $strongarm->value = 'liv_Top10_logo_88x31';
  $export['jci-dfp-SLOT-27'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-28';
  $strongarm->value = 'Top100_SponsorBranding_88x31';
  $export['jci-dfp-SLOT-28'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-29';
  $strongarm->value = 'liv_PushDown_Collapsed_970x90';
  $export['jci-dfp-SLOT-29'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-3';
  $strongarm->value = 'liv_lb_bottom_728x90';
  $export['jci-dfp-SLOT-3'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-30';
  $strongarm->value = 'liv_Floating_MR_300x250';
  $export['jci-dfp-SLOT-30'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-31';
  $strongarm->value = 'Liv_HalfPage_300x600';
  $export['jci-dfp-SLOT-31'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-4';
  $strongarm->value = 'LIV_LB_AdSense_728x90';
  $export['jci-dfp-SLOT-4'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-5';
  $strongarm->value = 'LIV_LB_DM_728x90';
  $export['jci-dfp-SLOT-5'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-6';
  $strongarm->value = 'LIV_Mobile_LB_Top_320x50';
  $export['jci-dfp-SLOT-6'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-7';
  $strongarm->value = 'LIV_Mobile_LB_Middle_320x50';
  $export['jci-dfp-SLOT-7'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-8';
  $strongarm->value = 'LIV_Mobile_LB_Bottom_320x50';
  $export['jci-dfp-SLOT-8'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-SLOT-9';
  $strongarm->value = 'LIV_Mobile_LB_AdSense_320x50';
  $export['jci-dfp-SLOT-9'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-STATE-KEY';
  $strongarm->value = 'State';
  $export['jci-dfp-STATE-KEY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-STATE-TARGET';
  $strongarm->value = 1;
  $export['jci-dfp-STATE-TARGET'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-T-QUANTITY';
  $strongarm->value = 1;
  $export['jci-dfp-T-QUANTITY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-TYPE-KEY';
  $strongarm->value = 'Type';
  $export['jci-dfp-TYPE-KEY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jci-dfp-TYPE-TARGET';
  $strongarm->value = 1;
  $export['jci-dfp-TYPE-TARGET'] = $strongarm;

  return $export;
}
