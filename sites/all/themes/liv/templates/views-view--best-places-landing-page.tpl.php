<?php

/**
 * @file
 * Main view template.
 *
 * @ingroup views_templates
 */
?>
<div class="best-of">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <div class="view-header">
    <?php
      $recent_title = arg(0) == 'top-10' ? 'Recent Top 10' : 'Recent Top 100';
      if (!empty($view->args[0])) {
        $term = taxonomy_get_term_by_name(str_replace('-', ' ', arg(1)));
        if (!empty($term)) {
          $term = current($term);
          $recent_title = '<h2>Recent ' . check_plain($term->name) . ' Lists</h2>';
        }
      }
    ?>
    <h2><?php print $recent_title; ?></h2>
  </div>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>

      <?php print $rows; ?>

  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if (count($view->result) == 6): ?>
    <div class="view-footer">
      <?php print $footer; ?>
      <div class="show-more shadow-inset-lr"><a href="" class="show-more-link">Show more posts <i class="icon-arrow-down-double white"></i></a></div>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
