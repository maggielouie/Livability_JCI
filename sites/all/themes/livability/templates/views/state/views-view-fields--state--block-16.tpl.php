<?php
$node = node_load($view->args[0]);
$state = theme_get_setting('national_home_price');
$city = $row->field_field_median_home_price[0]['raw']['value'];
if ($city < $state ) {
  $statement = '<span class="text">Lower</span> than the national average';
} elseif ($city > $state ) {
  $statement = '<span class="text">Higher</span> than the national average';
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
