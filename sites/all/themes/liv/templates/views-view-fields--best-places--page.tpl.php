
<span class="featured-image clearfix"> 
  <?php if (isset($fields['field_image_single'])) {
    print $fields['field_image_single']->content;
  } ?>
  <?php if (isset($view->pager)) : ?>
    <?php print $view->pager; ?>
  <?php endif; ?>
</span>
<span class="l-275">
  <?php if (isset($fields['field_highlights'])) {
    print $fields['field_highlights']->content;
  } ?>
  <span class="no-mobile">
    <?php $topad = block_load('jci_dfp', 'jci-dfp-block-23');
	$output = _block_get_renderable_array(_block_render_blocks(array($topad)));
	print drupal_render($output); ?>
  </span>
</span>
<span class="article-content r-275-full">
  <?php if (isset($fields['field_bp_body'])) {
    print $fields['field_bp_body']->content;
  } ?>
</span>
<span class="card-large">
<span class="card-arrow"></span>
<?php /* [CITY CARD] */ ?>
</span>