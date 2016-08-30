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
        <?php if (isset($content['field_deck'])) { print render($content['field_deck']); } ?>
        <span class="author">
        <?php if (isset($field_author[0])) {
          $name = $field_author[0]['entity']->name;
          echo "By " . l($name, 'user/'.$field_author[0]['target_id']) . " on ";
        }
        elseif (isset($field_byline['und'])) {
          $name = $field_byline['und'][0]['value']; echo "By $name on ";
        }
        $createdate = $node->created;
        echo date('F j, Y', $createdate); ?> at <?php echo date('g:i a T', $createdate); ?>
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
    <span class="l-275">
      <?php if (isset($content['field_highlights'])) {
        print render($content['field_highlights']);
      } ?>
      <span>
        <?php $topad = block_load('jci_dfp', 'jci-dfp-block-24');
	    $output = _block_get_renderable_array(_block_render_blocks(array($topad)));
        print drupal_render($output); ?>
      </span>
      <?php if (isset($content['field_pull_quote'])) {
        print '<span class="quote"><i class="quotes-green-large"></i>';
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
    <span class="article-content r-275-full">
      <?php print render($content['body']); ?>
    </span>
    <?php if (isset($field_author[0])) : ?>
      <span class="article-author clearfix">
        <span class="article-author-container">
        <?php $auth = user_view($field_author[0]['entity'], 'article_bottom'); print render($auth); ?>
        </span>
      <span class="ad300-right no-mobile">
        <?php $topad = block_load('jci_dfp', 'jci-dfp-block-23');
    	$output = _block_get_renderable_array(_block_render_blocks(array($topad)));
	    print drupal_render($output); ?>
      </span>
    </span>
    <?php endif; ?>
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

