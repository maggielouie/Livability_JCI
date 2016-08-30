
<span class="image-icon">
  <?php if (isset($content['field_image'])) {
    print render($content['field_image']);
  }
  else {
    print '<a href="'.$node_url.'"><img src="/'.drupal_get_path('theme', 'liv').'/images/325x216.jpg" alt="placeholder "/></a>';
  } ?>
<?php /* $term_name = 'none'; if(isset($content['field_blog_category'][0])) { $term_name = $content['field_blog_category'][0]['#title'];}
  echo '<span class="circle-icon">';
    echo '<span class="sticker-orange-horizontal">';
      print '<i class="icon-' . livability_article_get_icon($term_name) . ' white"></i>';
    echo '</span>';
  echo '</span>'; */ ?>
</span>
  <span class="summary">
    <h2><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <span class="date no-mobile">
      <?php $createdate = $node->created +18000;
        date_default_timezone_set("EST");
        echo date('F j, Y', $createdate);
        date_default_timezone_set("GMT"); ?>
    </span>
      <?php if (isset($content['field_deck'])) { $desc = $content['field_deck'][0]['#markup']; }
      else { $desc = $content['body']['#items'][0]['safe_summary']; }
      $desc = substr(str_replace('<p>', '' , str_replace('</p>', ' ', $desc)), 0, 165);
      print '<p class="no-mobile">'.$desc;
      if (substr($desc, -1) != '.') { print '&hellip;'; }
      print '</p>'; ?>
      <span class="interact">
        <?php /* <a href="#"><i class="icon-share grey"></i>Share</a> */ ?>
        <?php /* <a href="#"><i class="icon-comments grey"></i># comments</a> */ ?>
      </span>
  </span>
