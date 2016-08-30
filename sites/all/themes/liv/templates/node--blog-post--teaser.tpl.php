
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
        <?php $createdate = $node->created;
        echo date('F j, Y', $createdate); ?> at <?php echo date('g:i a T', $createdate); ?>
        </span>
      </span>
      
  <?php endif; ?>
