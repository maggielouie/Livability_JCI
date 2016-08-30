<article>
  <span class="padded clearfix">

    <?php
      // We hide the comments to render below.
      hide($content['comments']);
      hide($content['links']);
    ?>

    <span class="year">
      <?php if (isset($content['field_year'])) {
        print render($content['field_year']);
      } ?>
    </span>
    <?php print render($title_prefix); ?>
	  <span class="right">
        <div class="top-100-sponsored-by"><span class="sponsored-by-txt">Sponsored by:</span>
          <?php print getDumbDFP(27);?>
        </div>
    </span>
    <?php if ($title): ?>
      <h1 class="title"><?php print $title; ?></h1>
    <?php endif; ?>

    <?php print render($title_suffix); ?>
    <?php if (isset($content['field_bp_category'])) {
      print render($content['field_bp_category']);
    } ?>
    <span class="synopsis clearfix">
      <?php if (isset($content['field_deck'])) : ?>
        <p><?php print $content['field_deck'][0]['#markup']; ?></p>
      <?php endif; ?>
    </span>

    <span class="top-10-nav clearfix">
      <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
      <span class="right">
        <?php print best_places_item_first(arg(1)); ?>
      </span>
    </span>
  </span>
  <span class="padded">

    <?php if (!empty($content['field_image'])) {
      print render($content['field_image']);
    } ?>

    <span class="l-275">
      <?php if (isset($content['field_ranking_criteria'])) : ?>
        <span class="highlights">
          <h4><?php print $content['field_ranking_criteria']['#title']; ?></h4>
          <ul class="bullet">
          <?php foreach($content['field_ranking_criteria']['#items'] as $i => $item) {
            echo '<li>'.$item['value'].'</li>';
          } ?>
          </ul>
          <?php // print render($content['field_ranking_criteria']); ?>
        </span>
      <?php endif; ?>
      
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
	  <span class="no-mobile center-txt">
    	<?php print getDumbDFP(23); ?>
	  </span>
	</span>
    <span class="article-content r-275-full">
      <?php if (isset($content['body'])) {
        print render($content['body']);
      } ?>
    </span>
    <span class="top-10-nav clearfix">
      <span class="right">
        <?php print best_places_item_first(arg(1)); ?>
      </span>
    </span>

    <?php if (!empty($content['links'])): ?>
      <div class="links">
        <?php print render($content['links']); ?>
      </div> <!-- /links -->
    <?php endif; ?>
  </span>
</article>