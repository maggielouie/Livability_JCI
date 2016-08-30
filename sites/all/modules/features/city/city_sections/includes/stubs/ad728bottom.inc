<?php $topad = block_load('jci_dfp', 'jci-dfp-block-3');
$output = _block_get_renderable_array(_block_render_blocks(array($topad)));
print drupal_render($output);
