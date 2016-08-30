<!DOCTYPE html>
<html<?php print $html_attributes . $rdf_namespaces; ?>>
<head id="www-livability-com" data-template-set="html5-reset">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script>
    !function(f,b,e,v,n,t,s){if(f.fbq)return;n=f.fbq=function(){n.callMethod?
        n.callMethod.apply(n,arguments):n.queue.push(arguments)};if(!f._fbq)f._fbq=n;
      n.push=n;n.loaded=!0;n.version='2.0';n.queue=[];t=b.createElement(e);t.async=!0;
      t.src=v;s=b.getElementsByTagName(e)[0];s.parentNode.insertBefore(t,s)}(window,
        document,'script','https://connect.facebook.net/en_US/fbevents.js');

    fbq('init', '1106745702700189');
    fbq('track', "PageView");
    fbq('track', 'ViewContent');
  </script>

  <!-- Google Page Level -->
  <script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
  <script>
    (adsbygoogle = window.adsbygoogle || []).push({
      google_ad_client: "ca-pub-0269980627110398",
      enable_page_level_ads: true
    });
  </script>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes; ?>>
<div class="nav-container slide mobile-only">
    <div class='go-back'>
        <a href='#'><i class="chev-left-white"></i>BACK</a>
    </div>
    <div class="logo-container">
        <span class="logo">Livability.com</span>
    </div>
    <nav class="no-desktop" role="navigation">
        <ul></ul>
    </nav>
</div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
<div id="catfish"></div>
<div id="ecpmband-c267eb294dc0aace17cf935aa07b1a21"></div>
</body>
</html>
