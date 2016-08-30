<?php
/**
 * @file
 * media_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function media_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__image';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'preview' => array(
        'custom_settings' => TRUE,
      ),
      'media_link' => array(
        'custom_settings' => TRUE,
      ),
      'media_original' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'filename' => array(
          'weight' => '-10',
        ),
        'preview' => array(
          'weight' => '-5',
        ),
      ),
      'display' => array(
        'file' => array(
          'media_small' => array(
            'weight' => 0,
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__video';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'preview' => array(
        'custom_settings' => TRUE,
      ),
      'article_video' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'file' => array(
          'media_small' => array(
            'weight' => 0,
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'article_video' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__video'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_alt';
  $strongarm->value = '[file:field_file_image_alt_text]';
  $export['file_entity_alt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_default_allowed_extensions';
  $strongarm->value = 'jpg jpeg gif png txt mp3 mov mp4 m4a m4v mpeg avi ogg oga ogv weba webp webm ';
  $export['file_entity_default_allowed_extensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_file_upload_wizard_skip_fields';
  $strongarm->value = 0;
  $export['file_entity_file_upload_wizard_skip_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_file_upload_wizard_skip_file_type';
  $strongarm->value = 1;
  $export['file_entity_file_upload_wizard_skip_file_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_file_upload_wizard_skip_scheme';
  $strongarm->value = 1;
  $export['file_entity_file_upload_wizard_skip_scheme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_max_filesize';
  $strongarm->value = '';
  $export['file_entity_max_filesize'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_title';
  $strongarm->value = '[file:field_file_image_title_text]';
  $export['file_entity_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_wysiwyg_wysiwyg_allowed_types';
  $strongarm->value = array();
  $export['media_wysiwyg_wysiwyg_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_api_key';
  $strongarm->value = 'bec990c94a614397bd9961269c7697f2';
  $export['oembedembedly_api_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_default';
  $strongarm->value = '1';
  $export['oembedembedly_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_providers';
  $strongarm->value = array(
    'youtube' => 1,
    'twitchtv' => 1,
    'ustream' => 1,
    'qik' => 1,
    'revision3' => 1,
    'dailymotion' => 1,
    'collegehumor' => 1,
    'telly' => 1,
    'break' => 1,
    'myspacevideos' => 1,
    'metacafe' => 1,
    'bliptv' => 1,
    'googlevideo' => 1,
    'yahoovideo' => 1,
    'viddler' => 1,
    'liveleak' => 1,
    'animoto' => 1,
    'dotsub' => 1,
    'overstream' => 1,
    'livestream' => 1,
    'worldstarhiphop' => 1,
    'bambuser' => 1,
    'schooltube' => 1,
    'bigthink' => 1,
    'jibjab' => 1,
    'xtranormal' => 1,
    'socialcam' => 1,
    'youku' => 1,
    'snotr' => 1,
    'clipfish' => 1,
    'myvideo' => 1,
    'vzaar' => 1,
    'coub' => 1,
    'streamio' => 1,
    'vine' => 1,
    'viddy' => 1,
    'tudou' => 1,
    'mixbit' => 1,
    'sproutvideo' => 1,
    'minotovideo' => 1,
    'brainshark' => 1,
    '23video' => 1,
    'goanimate' => 1,
    'brainsonic' => 1,
    'lustich' => 1,
    'reelhouse' => 1,
    'webtv' => 1,
    'mynet' => 1,
    'izlesene' => 1,
    'alkislarlayasiyorum' => 1,
    '59saniye' => 1,
    'zie' => 1,
    'ustudio' => 1,
    'bale' => 1,
    'allego' => 1,
    'clipter' => 1,
    'hirevue' => 1,
    'sendvid' => 1,
    'snappytv' => 1,
    'clipmine' => 1,
    'whitehouse' => 1,
    'hulu' => 1,
    'crackle' => 1,
    'funnyordie' => 1,
    'vimeo' => 1,
    'ted' => 1,
    'nfb' => 1,
    'thedailyshow' => 1,
    'yahoomovies' => 1,
    'colbertnation' => 1,
    'comedycentral' => 1,
    'theonion' => 1,
    'wordpresstv' => 1,
    'traileraddict' => 1,
    'trailerspy' => 1,
    'foratv' => 1,
    'spike' => 1,
    'gametrailers' => 1,
    'koldcasttv' => 1,
    'mixergy' => 1,
    'pbsvideo' => 1,
    'zapiks' => 1,
    'trutv' => 1,
    'nzonscreen' => 1,
    'wistia' => 1,
    'confreaks' => 1,
    'allthingsd' => 1,
    'nymag' => 1,
    'aniboom' => 1,
    'grindtv' => 1,
    'ifoodtv' => 1,
    'logotv' => 1,
    'lonelyplanet' => 1,
    'streetfire' => 1,
    'sciencestage' => 1,
    'brightcove' => 1,
    'wirewax' => 1,
    'canalplus' => 1,
    'vevo' => 1,
    'pixorial' => 1,
    'spreecast' => 1,
    'showme' => 1,
    'looplogic' => 1,
    'onaol' => 1,
    'videodetective' => 1,
    'khanacademy' => 1,
    'vidyard' => 1,
    'veoh' => 1,
    'univision' => 1,
    'vidcaster' => 1,
    'muzutv' => 1,
    'vube' => 1,
    'boxofficebuz' => 1,
    'godtube' => 1,
    'mediamatters' => 1,
    'clikthrough' => 1,
    'clipsyndicate' => 1,
    'srf' => 1,
    'mpora' => 1,
    'jstream' => 1,
    'vice' => 1,
    'videodonor' => 1,
    'lovelive' => 1,
    'hurriyettv' => 1,
    'uludagsozlukvideo' => 1,
    'ign' => 1,
    'askmen' => 1,
    'esri' => 1,
    'officemix' => 1,
    'zapkolik' => 1,
    'iplayerhd' => 1,
    'espn' => 1,
    'abcnews' => 1,
    'washingtonpost' => 1,
    'boston' => 1,
    'facebook' => 1,
    'cnbc' => 1,
    'cbsnews' => 1,
    'googleplus' => 1,
    'cnn' => 1,
    'cnnedition' => 1,
    'cnnmoney' => 1,
    'msnbc' => 1,
    'nbcnews' => 1,
    'foxsports' => 1,
    'globalpost' => 1,
    'guardian' => 1,
    'bravotv' => 1,
    'discovery' => 1,
    'forbes' => 1,
    'distrify' => 1,
    'foxnews' => 1,
    'foxbusiness' => 1,
    'reuters' => 1,
    'huffpost' => 1,
    'nytimes' => 1,
    'vorarlberg' => 1,
    'spiegel' => 1,
    'zeitonline' => 1,
    'rtsch' => 1,
    'github' => 1,
    'crunchbase' => 1,
    'slideshare' => 1,
    'scribd' => 1,
    'screenr' => 1,
    'polldaddy' => 1,
    'howcast' => 1,
    'screencast' => 1,
    'issuu' => 1,
    'kickstarter' => 1,
    'scrapblog' => 1,
    'foursquare' => 1,
    'linkedin' => 1,
    'sliderocket' => 1,
    'googlemaps' => 1,
    'myopera' => 1,
    'tumblr' => 1,
    'polleverywhere' => 1,
    'quantcast' => 1,
    'compete' => 1,
    'statusnet' => 1,
    'identica' => 1,
    'vznetworks' => 1,
    'mylocme' => 1,
    'pastebin' => 1,
    'pastie' => 1,
    'redux' => 1,
    'cloudapp' => 1,
    'speakerdeck' => 1,
    'kiva' => 1,
    'timetoast' => 1,
    'storify' => 1,
    'meetup' => 1,
    'dailymile' => 1,
    'kinomap' => 1,
    'metacdn' => 1,
    'prezi' => 1,
    'uservoice' => 1,
    'formspring' => 1,
    'twitlonger' => 1,
    'qwiki' => 1,
    'crocodoc' => 1,
    'wikipedia' => 1,
    'wikimedia' => 1,
    'urtak' => 1,
    'ganxy' => 1,
    'panorama' => 1,
    'behance' => 1,
    'jdsupra' => 1,
    'minilogs' => 1,
    'sketchfab' => 1,
    'jsfiddle' => 1,
    'ponga' => 1,
    'listly' => 1,
    'crowdmap' => 1,
    'ifttt' => 1,
    'weavly' => 1,
    'tagmotion' => 1,
    'cloudup' => 1,
    'hackpad' => 1,
    'talely' => 1,
    'polar' => 1,
    'bubbli' => 1,
    'imajize' => 1,
    'giflike' => 1,
    'rapidengage' => 1,
    'infomous' => 1,
    'stepic' => 1,
    'tapestry' => 1,
    'chirbit' => 1,
    'polstir' => 1,
    'medium' => 1,
    'gettyimages' => 1,
    'isnare' => 1,
    'branchtrack' => 1,
    'jsbin' => 1,
    'wedgies' => 1,
    'chartblocks' => 1,
    'raddit' => 1,
    'vidbi' => 1,
    'kastio' => 1,
    'megavisor' => 1,
    'bunkr' => 1,
    'portfolium' => 1,
    'cartodb' => 1,
    'flowvella' => 1,
    'peoplbrain' => 1,
    'codepicnic' => 1,
    'yfrog' => 1,
    'flickr' => 1,
    'twitpic' => 1,
    'imgur' => 1,
    'twitgoo' => 1,
    'photobucket' => 1,
    'mobypicture' => 1,
    'xkcd' => 1,
    'asofterworld' => 1,
    'dinosaurcomics' => 1,
    '23hq' => 1,
    'dribbble' => 1,
    'smugmug' => 1,
    'picasa' => 1,
    'imgly' => 1,
    'tinypic' => 1,
    'meadd' => 1,
    'deviantart' => 1,
    'fotopedia' => 1,
    'photozou' => 1,
    'instagram' => 1,
    'skitch' => 1,
    'questionablecontent' => 1,
    'twitrpix' => 1,
    'someecards' => 1,
    'pikchur' => 1,
    'achewood' => 1,
    'whosay' => 1,
    'owly' => 1,
    'mlkshk' => 1,
    'lockerz' => 1,
    'droplr' => 1,
    'eyeem' => 1,
    'giphy' => 1,
    'frontback' => 1,
    'fotokritik' => 1,
    'vidme' => 1,
    'uludagsozlukgaleri' => 1,
    'gfycat' => 1,
    'tochka' => 1,
    'amazon' => 1,
    'shopstyle' => 1,
    'apple' => 1,
    'shoplocket' => 1,
    'etsy' => 1,
    'fiverr' => 1,
    'soundcloud' => 1,
    'spotify' => 1,
    'lastfm' => 1,
    'mixcloud' => 1,
    'radionomy' => 1,
    'hark' => 1,
    'rdio' => 1,
    'zeroinch' => 1,
    'bandcamp' => 1,
    'freemusicarchive' => 1,
    'npr' => 1,
    'huffduffer' => 1,
    'audioboom' => 1,
    'xiami' => 1,
    'saynow' => 1,
    'grooveshark' => 1,
    'radioreddit' => 1,
    'gogoyoko' => 1,
    'hypem' => 1,
    'bopfm' => 1,
    'clyp' => 1,
    'dnbradio' => 1,
    'sfxio' => 1,
  );
  $export['oembedembedly_providers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_schemes';
  $strongarm->value = '';
  $export['oembedembedly_schemes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_cache_flush';
  $strongarm->value = 1;
  $export['oembed_cache_flush'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembed_cache_lifetime';
  $strongarm->value = '3600';
  $export['oembed_cache_lifetime'] = $strongarm;

  return $export;
}
