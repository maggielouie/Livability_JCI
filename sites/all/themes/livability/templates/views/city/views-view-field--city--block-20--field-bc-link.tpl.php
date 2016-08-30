<?php
$node = node_load($view->args[0]);
$city = $node->title;
$state = $node->field_state['und'][0]['entity']->title;
$path = drupal_get_path_alias('node/'.$node->nid.'');

?>
<div class="businessclimate">
  Interested in learning more about the business climate in the <?php print $city; ?>, <?php print $state; ?> area? Visit <a href="<?php print $row->field_field_bc_link[0]['raw']['value']; ?>" target="_blank">BusinessClimate.com</a>
  <br /><br />
  <a href="<?php print $row->field_field_bc_link[0]['raw']['value']; ?>" target="_blank"><img src="/sites/all/themes/livability/images/logo/business-climate.png" alt="Business Climate" /></a>
</div>