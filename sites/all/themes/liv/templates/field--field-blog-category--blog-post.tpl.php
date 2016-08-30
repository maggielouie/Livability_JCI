<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>

  <?php foreach ($items as $delta => $item): ?>
    <span class="circle-icon">
      <span class="sticker-orange-horizontal">
        <i class="icon-<?php print livability_article_get_icon($item['#title']); ?> white"></i>
      </span>
    </span>
    <?php print render($item); ?>
  <?php endforeach; ?>
