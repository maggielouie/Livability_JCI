<?php
  $node = node_load($view->args[0]);
  $city = strtolower($node->title);
  $city = preg_replace("/[^a-z0-9_\s-]/", "", $city);
  $city = preg_replace("/[\s-]+/", " ", $city);
  $city = preg_replace("/[\s_]/", "-", $city);
  $state = strtolower($node->field_state['und'][0]['entity']->field_state_code['und'][0]['value']);
  $cat = $output;
  $cat = strtolower($cat);
  $cat = preg_replace("/[^a-z0-9_\s-]/", "", $cat);
  $cat = preg_replace("/[\s-]+/", " ", $cat);
  $cat = trim($cat);
  $cat = preg_replace("/[\s_]/", "-", $cat);

  $path = $state.'/'.$city.'/things-to-do/'.$cat;
?>
<div class="cat"><a href="/<?php print $path; ?>"><?php print $output; ?></a></div>