<?php
$last = theme_get_setting('national_income');
$current = $row->field_field_median_household_income[0]['raw']['value'];
if ($current < $last ) {
  $statement = '<span class="text">Lower</span> than the national average';
} elseif ($current > $last ) {
  $statement = '<span class="text">Higher</span> than the national average';
} else {
  $statement =  'No change.';
}
?>
<div class="data">
  <div class="icon white">
    <i class="flaticon-tool9"></i>
  </div>
  <div class="output">
    <span class="pop">$<?php print number_format($current); ?></span>
    <hr>
    <span class="change"><?php print $statement; ?></span>
  </div>
</div>
