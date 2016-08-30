<?php
$tablet_browser = 0;
$mobile_browser = 0;

if (preg_match('/(tablet|ipad|playbook)|(android(?!.*(mobi|opera mini)))/i', strtolower($_SERVER['HTTP_USER_AGENT']))) {
  $tablet_browser++;
}
if (preg_match('/(up.browser|up.link|mmp|symbian|smartphone|midp|wap|phone|android|iemobile)/i', strtolower($_SERVER['HTTP_USER_AGENT']))) {
  $mobile_browser++;
}
if ((strpos(strtolower($_SERVER['HTTP_ACCEPT']),'application/vnd.wap.xhtml+xml') > 0) or ((isset($_SERVER['HTTP_X_WAP_PROFILE']) or isset($_SERVER['HTTP_PROFILE'])))) {
  $mobile_browser++;
}
$mobile_ua = strtolower(substr($_SERVER['HTTP_USER_AGENT'], 0, 4));
$mobile_agents = array(
    'w3c ','acs-','alav','alca','amoi','audi','avan','benq','bird','blac',
    'blaz','brew','cell','cldc','cmd-','dang','doco','eric','hipt','inno',
    'ipaq','java','jigs','kddi','keji','leno','lg-c','lg-d','lg-g','lge-',
    'maui','maxo','midp','mits','mmef','mobi','mot-','moto','mwbp','nec-',
    'newt','noki','palm','pana','pant','phil','play','port','prox',
    'qwap','sage','sams','sany','sch-','sec-','send','seri','sgh-','shar',
    'sie-','siem','smal','smar','sony','sph-','symb','t-mo','teli','tim-',
    'tosh','tsm-','upg1','upsi','vk-v','voda','wap-','wapa','wapi','wapp',
    'wapr','webc','winw','winw','xda ','xda-');
if (in_array($mobile_ua,$mobile_agents)) {
  $mobile_browser++;
}
if (strpos(strtolower($_SERVER['HTTP_USER_AGENT']),'opera mini') > 0) {
  $mobile_browser++;
  //Check for tablets on opera mini alternative headers
  $stock_ua = strtolower(isset($_SERVER['HTTP_X_OPERAMINI_PHONE_UA'])?$_SERVER['HTTP_X_OPERAMINI_PHONE_UA']:(isset($_SERVER['HTTP_DEVICE_STOCK_UA'])?$_SERVER['HTTP_DEVICE_STOCK_UA']:''));
  if (preg_match('/(tablet|ipad|playbook)|(android(?!.*mobile))/i', $stock_ua)) {
    $tablet_browser++;
  }
}
if ($mobile_browser > 0) {
  $google = '<script>
    (adsbygoogle = window.adsbygoogle || []).push({
      google_ad_client: "ca-pub-0269980627110398",
      enable_page_level_ads: true
    });
</script>';

  $adsterra = '<script type=\'text/javascript\' src=\'http://pl6453875.puhtml.com/dc/35/27/dc352762da2ce2b75ef3149c350e8377.js\'></script>';

  $epom = '<script type="text/javascript">
  /*<![CDATA[*/
  if(!(window.EcpmbandConfig && window.EcpmbandConfig.ads)) window.EcpmbandConfig = {ads:[]};
  EcpmbandConfig.ads.push({
      ecpmband_key:"c267eb294dc0aace17cf935aa07b1a21",
      ecpmband_channel: "",
      ecpmband_code_format:"ads-async.js",
      ecpmband_click:"",
      ecpmband_custom_params:{},
      ecpmband_target_id:"ecpmband-c267eb294dc0aace17cf935aa07b1a21"
  });
  (function () {
      var sc = document.createElement("script");
      sc.type = "text/javascript";
      sc.async = true;
      sc.src = (location.protocol == "https:" ? "https:" : "http:") + "//www.adsonflags.com\/js\/show_ads_ecpmband.js?pubId=1835";
      var s = document.getElementsByTagName("script")[0];
      s.parentNode.insertBefore(sc, s);
  })();
  /*]]>*/
</script>
<div id="ecpmband-c267eb294dc0aace17cf935aa07b1a21"></div>';

  $mopub1 = '<script type="text/javascript">
  window.mopub = [{
    ad_unit: "4642a3f81c1644f687e012c20857c71c",
    ad_container_id: "catfish", // Specify the div or container to which you’d like to the mobile web tag
    ad_width: 320,
    ad_height: 50,
    keywords: "", // Optionally pass keywords as a comma separated list
  } ]; // To load additional ad units, add another object into the array.
  
  (function() {
    var mopubjs = document.createElement("script");
    mopubjs.async = true;
    mopubjs.type = "text/javascript";
    mopubjs.src = "//d1zg4cyg8u4pko.cloudfront.net/mweb/mobileweb.min.js";
    var node = document.getElementsByTagName("script")[0];
    node.parentNode.insertBefore(mopubjs, node);
  })();
</script>';

  $mopub2 = '<script type="text/javascript">
  window.mopub = [{
    ad_unit: "bdbcc9d526044a51a61fcfd616d59407",
    ad_container_id: "catfish", // Specify the div or container to which you’d like to the mobile web tag
    ad_width: 320,
    ad_height: 480,
    keywords: "", // Optionally pass keywords as a comma separated list
  } ]; // To load additional ad units, add another object into the array.
  
  (function() {
    var mopubjs = document.createElement("script");
    mopubjs.async = true;
    mopubjs.type = "text/javascript";
    mopubjs.src = "//d1zg4cyg8u4pko.cloudfront.net/mweb/mobileweb.min.js";
    var node = document.getElementsByTagName("script")[0];
    node.parentNode.insertBefore(mopubjs, node);
  })();
</script>';

  $option = array($google, $adsterra, $mopub1, $mopub2, $epom);
  $selection = array_rand($option, 1);
  print $option[$selection];

} /*else {
  $wwwpromoter = '<script>var _wwwp = {settings: {tag_id: 18193, popunder: {type: \'popunder\', times: 5, period: 24}}};</script><script src="//creative.wwwpromoter.com/static/v2/pop.min.js"></script>';
  $adsterra = '<script type=\'text/javascript\' src=\'http://pl6453873.puhtml.com/40/a4/0a/40a40a69764f30e49e169af30662c196.js\'></script>';
  $option = array($wwwpromoter, $adsterra);
  $selection = array_rand($option, 1);
  print $option[$selection];
} */
?>
