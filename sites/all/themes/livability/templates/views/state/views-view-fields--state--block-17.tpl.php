<?php
  $owned = $row->field_field_homes_owned[0]['raw']['value'];
  $rent = $row->field_field_homes_rent[0]['raw']['value'];
  $total = $owned+$rent;

  $percentOwned = $owned/$total;
  $percentRent = $rent/$total;
  $percent_friendlyOwned = round(number_format( $percentOwned * 100, 2 )) . '%';
  $percent_friendlyRent = round(number_format( $percentRent * 100, 2 )) . '%';
?>
<div class="data">
  <div class="icon white">
    <i class="flaticon-house112"></i>
  </div>
  <div class="output">
    <div class="clearfix"><strong><span class="pull-left">Homes Owned</span> <span class="pull-right"><?php print $percent_friendlyOwned; ?></span></strong></div>
    <div class="progress">
      <div class="progress-bar" role="progressbar" aria-valuenow="60" aria-valuemin="0" aria-valuemax="100" style="width: <?php print $percent_friendlyOwned; ?>;">
        <span class="sr-only"><?php print $percent_friendlyOwned; ?> Complete</span>
      </div>
    </div>
    <div class="clearfix"><strong><span class="pull-left">Homes Rented</span> <span class="pull-right"><?php print $percent_friendlyRent; ?></span></strong></div>
    <div class="progress">
      <div class="progress-bar" role="progressbar" aria-valuenow="60" aria-valuemin="0" aria-valuemax="100" style="width: <?php print $percent_friendlyRent; ?>;">
        <span class="sr-only"><?php print $percent_friendlyRent; ?> Complete</span>
      </div>
    </div>
  </div>
</div>
