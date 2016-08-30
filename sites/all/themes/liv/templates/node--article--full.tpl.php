  <span class="padded clearfix">
  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || $title): ?>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php if($page && $title): ?>
        <h1><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($unpublished): ?>
        <p class="unpublished"><?php print t('Unpublished'); ?></p>
      <?php endif; ?>

      <span class="synopsis clearfix">
        <?php if (isset($content['field_deck'])) { print '<p>'. render($content['field_deck']).'</p>'; } ?>
        <span class="author">
        <?php if (isset($field_author['und'])) {
          $author = user_load($field_author['und'][0]['target_id']);
          $name = $author->name;
          echo "By " . l($author->name, 'user/'.$author->uid) . " on ";
        }
        elseif (isset($field_byline['und'])) {
          $name = $field_byline['und'][0]['value']; echo "By $name on ";
        }
        $createdate = $node->created +18000;
        date_default_timezone_set("EST");
        echo date('F j, Y', $createdate); ?> at <?php echo date('g:i a T', $createdate);
        date_default_timezone_set("GMT"); ?>
        </span>
      </span>
      
  <?php endif; ?>
  </span>
  <?php if (isset($content['field_image'])) {
    print '<span class="full">';
    print render($content['field_image']);
    print '</span>';
  } ?>
  <span class="padded">
    <?php 
      $content_wraps = FALSE;
      
      $wrap_class = $content_wraps ? 'content-wrap' : '';
    ?>
    <span class="l-275">
      <?php if (isset($content['field_highlights'])) {
        print render($content['field_highlights']);
      } ?>
      <span>
        <?php $topad = block_load('jci_dfp', 'jci-dfp-block-23');
    	$output = _block_get_renderable_array(_block_render_blocks(array($topad)));
	    print drupal_render($output); ?>
      </span>
      
      <?php if (isset($content['field_pull_quote'])) {
        print '<span class="quote">';
        print '<p>' . $content['field_pull_quote']['#items'][0]['value'] .'</p>';
        if (isset($content['field_quote_attribution'])) {
          print '<span class="author">';
          print $content['field_quote_attribution']['#items'][0]['value'];
          if (isset($content['field_professional_title'])) {
            print ', ' . $content['field_professional_title']['#items'][0]['value'];
          }
          print '</span>';
        }
        print '</span>';
      } ?>
      
    </span>
    <span class="article-content r-275-full <?php print $wrap_class; ?>">
	<div style="margin-top: -19px; position: absolute; z-index: 1;">
	  <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
	</div>
      <div class="mainContent" style="padding-top: 25px;">
        <?php print render($content['body']); ?>
        <?php if (!empty($field_sponsor_name)) {
          $image = array('style_name' => 'article_sponsor',
                          'path' => $field_sponsor_logo['und'][0]['uri'],
                          'width' => $field_sponsor_logo['und'][0]['width'],
                          'height' => $field_sponsor_logo['und'][0]['height'],
                          'alt' => $field_sponsor_logo['und'][0]['alt'],
                          'title' => $field_sponsor_logo['und'][0]['title'],
                        );
          $sponsorImage = theme('image_style', $image);
          $link = $field_sponsor_link['und'][0]['value'];
          print '<div class="articleSponsor">';
          print '<hr>';
          print '<div class="sponsorImage">';
          print '<a href="'.$link.'" target="_blank">';
          print $sponsorImage;
          print '</a>';
          print '</div>';
          print '<div class="sponsorName">';
          print '<a href="'.$link.'" target="_blank">';
          print '<h5>Sponsored by '.$field_sponsor_name['und'][0]['value'].'</h5>';
          print '</a>';
          print '<div class="sponsorSlogan">';
          print $field_sponsor_slogan['und'][0]['value'];
          print '</div>';
          print '</div>';
          print '<hr>';
          print '</div>';
        } ?>
      </div>
    </span>
    <span class="article-author clearfix">
      <?php if (isset($author)) : ?>
        <span class="article-author-container">
        <?php $auth = user_view($author, 'article_bottom'); print render($auth); ?>
        </span>
      <?php endif; ?>
      <span class="ad300-right right no-mobile">
        <?php $topad = block_load('jci_dfp', 'jci-dfp-block-22');
    	$output = _block_get_renderable_array(_block_render_blocks(array($topad)));
	    print drupal_render($output); ?>
      </span>
    </span>
  </span>


  <?php if (!empty($content['links']['terms'])): ?>
    <div class="terms">
      <?php print render($content['links']['terms']); ?>
    </div> <!-- /terms -->
  <?php endif;?>

  <?php if (!empty($content['links'])): ?>
    <div class="links">
      <?php print render($content['links']); ?>
    </div> <!-- /links -->
  <?php endif; ?>

