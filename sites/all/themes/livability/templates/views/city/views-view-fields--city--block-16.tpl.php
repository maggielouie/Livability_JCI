<?php
$node = node_load($view->args[0]);
$state = $node->field_state['und'][0]['entity']->field_median_home_price['und'][0]['value'];
$city = $row->field_field_median_home_price[0]['raw']['value'];
if ($city < $state ) {
  $statement = '<span class="text">Lower</span> than the state average';
} elseif ($city > $state ) {
  $statement = '<span class="text">Higher</span> than the state average';
} else {
  $statement =  'No change.';
}
?>
<div class="data">
  <div class="icon white">
    <i class="flaticon-house198"></i>
  </div>
  <div class="output">
    <span class="pop">$<?php print number_format($city); ?></span>
    <hr>
    <span class="change"><?php print $statement; ?></span>
  </div>
</div>
