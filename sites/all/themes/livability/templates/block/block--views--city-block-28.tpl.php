<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="block-title">
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    </div>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <?php print $content ?>

</section>