<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
  <?php /*$top_lb_ad = block_load('combo_ad_blocks', 'leaderboard_top');
  $top_lb_ad_output = _block_get_renderable_array(_block_render_blocks(array($top_lb_ad)));
  print drupal_render($top_lb_ad_output); */?>
  <article>
    <span class="padded clearfix">
      <?php if (isset($variables['view']->args[0])) {
        echo '<span class="year">'. $variables['view']->args[0] .'</span>';
      } ?>
      <h1>Top 100 Best Places to Live</h1>
      <div class="top-100-sponsored-by"><span class="sponsored-by-txt" style="display: none;">Sponsored by:</span>
        <?php $topad = block_load('jci_dfp', 'jci-dfp-block-28');
              $output = _block_get_renderable_array(_block_render_blocks(array($topad)));
              print drupal_render($output);
              ?>
      </div>
      <span class="top-10-nav clearfix">
        <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
      </span>
    </span>
    <span class="padded top-100">
      <?php if ($header): ?>
        <?php print $header; ?>
      <?php endif; ?>

      <?php if ($attachment_before): ?>
        <?php print $attachment_before; ?>
      <?php endif; ?>

      <span class="top-100-content rankings <?php print arg(3); ?>">
      <?php if ($title): ?>
        <?php print $title; ?>
        <?php endif; ?>
        <?php if ($rows): ?>
          <?php print $rows; ?>
        <?php elseif ($empty): ?>
          <?php print $empty; ?>
        <?php endif; ?>

        <?php if ($pager): ?>
          <?php print $pager; ?>
        <?php endif; ?>

        <?php if ($attachment_after): ?>
          <?php print $attachment_after; ?>
        <?php endif; ?>

        <?php if ($more): ?>
          <?php print $more; ?>
        <?php endif; ?>

        <?php if ($footer): ?>
          <?php print $footer; ?>
        <?php endif; ?>

        <?php $bottomad = block_load('combo_ad_blocks', 'leaderboard_bottom');
        $bottomad_output = _block_get_renderable_array(_block_render_blocks(array($bottomad)));
        print drupal_render($bottomad_output); ?>
        
      </span>
    </span>
  </article>