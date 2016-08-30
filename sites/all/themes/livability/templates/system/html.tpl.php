<!DOCTYPE html>
<html>
<head>
  <link rel="profile" href="<?php print $grddl_profile; ?>" />
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
  <script src="https://s0.2mdn.net/ads/studio/Enabler.js"></script>
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

</head>
<body<?php print $body_attributes; ?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <div id="catfish"></div>
  <div id="ecpmband-c267eb294dc0aace17cf935aa07b1a21"></div>
</body>
</html>
