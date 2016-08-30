<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php print $ds_content; ?>
  <span class="top-100-key">
  <!-- this is in ds-1col__node-top-100-full, but perhaps should be the header of the next view -->
    <span class="city-score">600</span> = The city’s overall score, based on the weighted sum of the eight component scores.
  </span>


<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children; ?>
<?php endif; ?>

  <?php $item = menu_get_object();
  if ($item) {
    print views_embed_view('top_100', 'block_1');
  }
  ?>