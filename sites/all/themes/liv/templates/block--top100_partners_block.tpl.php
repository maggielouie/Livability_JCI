<div id="block-<?php print $block->module .'-'. $block->delta ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <?php print render($title_prefix); ?>
    <?php if ($block->subject): ?>
      <h3 class="block-title"<?php print $title_attributes; ?>><?php print $block->subject ?></h3>
    <?php endif;?>
    <?php print render($title_suffix); ?>


    <div class="block-content" <?php print $content_attributes; ?>>
      <?php print $content; ?>
    </div>

</div> <!-- /block-inner /block -->