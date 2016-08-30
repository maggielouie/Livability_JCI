
<span class="image-icon">
  <?php if (isset($content['field_article_thumbnail'])) {
    print render($content['field_article_thumbnail']);
  } else if (isset($content['field_image'])) {
    print render($content['field_image']);
  } else {
    // dsm(render($content['body']));
    $doc = new DOMDocument();
    @$doc->loadHTML(render($content['body']));
    $tags = $doc->getElementsByTagName('img');
    $img = array();
    foreach ($tags as $tag) {
      $img[] = $tag->getAttribute('src');
    }
    if (isset($img[0])) {
      $pieces = explode('/', $img[0]);
      // Display the first embedded image in the body content
      print l('<img src="' . image_style_url('325x216', end($pieces)) .'" alt="placeholder" />', 'node/'.$node->nid, array('html' => TRUE));
    } else {
      print '<a href="'.$node_url.'"><img src="/'.drupal_get_path('theme', 'liv').'/images/325x216.jpg" alt="placeholder" /></a>';
    }
  } ?>
<?php /*if (isset($content['field_category'][0]['entity'])) : ?>
  <?php foreach($content['field_category'][0]['entity']['field_collection_item'] as $fcid => $catcollection) {
    echo '<span class="circle-icon">';
      echo '<span class="sticker-orange-horizontal">';
        if (isset($catcollection['field_category_ref'][0]['#title'])) {
          print '<i class="icon-' . livability_article_get_icon($catcollection['field_category_ref'][0]['#title']) . ' white"></i>';
        }
        elseif (isset($catcollection['field_category_ref'][0]['#markup'])) {
          print '<i class="icon-' . livability_article_get_icon($catcollection['field_category_ref'][0]['#markup']) . ' white"></i>';
        }
      echo '</span>';
    echo '</span>';
  } ?>
<?php endif; */?>
</span>
  <span class="summary">
    <?php if (!empty($field_sponsor_name)) { ?>
    <span style="color:#7cc242;text-transform:uppercase;font-size:0.724rem;font-weight: bold;position:absolute;margin-top:-25px;">Sponsored by <?php print $field_sponsor_name['und'][0]['value']; ?></span>
    <?php } ?>
    <h2><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php /* <span class="date no-mobile">
      <?php $createdate = $node->created +18000;
        date_default_timezone_set("EST");
        echo date('F j, Y', $createdate);
        date_default_timezone_set("GMT"); ?>
    </span>
      <?php if (isset($content['field_short_description'])) {
        $desc = $content['field_short_description']['#items'][0]['value'];
      }
      else {
        $desc = $content['body']['#items'][0]['value'];
      }
      $desc = substr(str_replace('<p>', '' , str_replace('</p>', ' ', $desc)), 0, 165);
      print '<p class="no-mobile">'.$desc;
      if (substr($desc, -1) != '.') { print '&hellip;'; }
      print '</p>'; ?>
    */ ?>
      <span class="interact">
        <?php /* <a href="#"><i class="icon-share grey"></i>Share</a> */ ?>
        <?php /* <a href="#"><i class="icon-comments grey"></i># comments</a> */ ?>
      </span>
  </span>
