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

    <span class="article-content">
      <?php print render($content['body']); ?>
    </span>
    <span class="no-mobile">
      <?php $topad = block_load('jci_dfp', 'jci-dfp-block-24');
      $output = _block_get_renderable_array(_block_render_blocks(array($topad)));
      print drupal_render($output); ?>
    </span>
    <span class="mobile-only">
      <?php $topad = block_load('jci_dfp', 'jci-dfp-block-12');
      $output = _block_get_renderable_array(_block_render_blocks(array($topad)));
      print drupal_render($output); ?>
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

