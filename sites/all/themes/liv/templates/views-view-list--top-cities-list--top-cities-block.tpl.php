<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php print $list_type_prefix; ?>
    <?php foreach ($rows as $id => $row): ?>
      <li class="<?php print $classes_array[$id]; ?>"><?php print $row; ?></li>
			<?php if ($id == 4) : // Show ad after fifth row. ?>
			  <span class="no-mobile ad-middle">
          <?php $midad = block_load('jci_dfp', 'jci-dfp-block-2');
          $output = _block_get_renderable_array(_block_render_blocks(array($midad)));
          print drupal_render($output); ?>
        </span>
        <span class="mobile-only ad-middle">
          <?php $midadm = block_load('jci_dfp', 'jci-dfp-block-7');
          $outputm = _block_get_renderable_array(_block_render_blocks(array($midadm)));
          print drupal_render($outputm); ?>
        </span>
			<?php endif; ?>
    <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>