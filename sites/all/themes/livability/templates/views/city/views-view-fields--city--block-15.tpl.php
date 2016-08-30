<?php
  $last = $row->field_field_population_previous_year[0]['raw']['value'];
  $current = $row->field_field_population[0]['raw']['value'];
  $change = number_format((1 - $last / $current) * 100, 2);
  if(is_numeric($change)) {
    $change = str_replace('-', '', $change);
  }
  if ($current < $last ) {
    $statement = 'Down by <span class="text">' . $change . '%</span>';
  } elseif ($current > $last ) {
    $statement = 'Up by <span class="text">' . $change . '%</span>';
  } else {
    $statement =  'No change.';
  }
?>
<div class="data">
  <div class="icon white">
    <i class="flaticon-users6"></i>
  </div>
  <div class="output">
    <span class="pop"><?php print number_format($current); ?></span>
    <hr>
    <span class="change"><?php print $statement; ?></span>
  </div>
</div>
