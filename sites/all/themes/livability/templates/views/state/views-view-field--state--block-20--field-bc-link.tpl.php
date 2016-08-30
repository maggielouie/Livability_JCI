<?php
$node = node_load($view->args[0]);
?>
<div class="businessclimate">
  Interested in learning more about the business climate in the <?php print $node->title; ?> area? Visit <a href="<?php print $row->field_field_bc_link[0]['raw']['value']; ?>" target="_blank">BusinessClimate.com</a>
  <br /><br />
  <a href="<?php print $row->field_field_bc_link[0]['raw']['value']; ?>" target="_blank"><img src="/sites/all/themes/livability/images/logo/business-climate.png" alt="Business Climate" /></a>
</div>