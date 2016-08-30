<?php

/**
 * @file
 * Main view template.
 *
 * @ingroup views_templates
 */
?>

  <?php if ($rows): ?>
    <span class="articles-content">
      <?php print $rows; ?>
    </span>
  <?php endif; ?>
<div class="show-more shadow-inset-lr" id="back-top"><a href="#header" class="">Back to Top <i class="icon-arrow-up-double white"></i></a></div>