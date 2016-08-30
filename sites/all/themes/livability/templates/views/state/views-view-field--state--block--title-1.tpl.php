<?php
  $node = node_load($row->node_field_data_field_place_ref_nid);
  if ($node->type == "city") {
    $state = node_load($node->field_state['und'][0]['target_id']);
    $place = $node->title.', '. $state->field_state_code['und'][0]['value'];
    $link = drupal_get_path_alias('node/'.$node->nid);
    $compile = '<a href="'.$link.'">'.$place.'</a>';
  } else {
    $output = '';
  }
?>
<div class="cat"><?php print $compile; ?></div>