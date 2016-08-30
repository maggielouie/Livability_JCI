<?php
$ageunder5 = array($row->field_field_age_under_5[0]['raw']['value'], 'Under 5');
$age5_17 = array((($row->field_field_population[0]['raw']['value']-$row->field_field_age_18_over[0]['raw']['value'])-$row->field_field_age_under_5[0]['raw']['value']), '5-17');
$age10_24 = array($row->field_field_age_20_24[0]['raw']['value']+($row->field_field_age_18_over[0]['raw']['value']-($row->field_field_age_20_24[0]['raw']['value']+$row->field_field_age_25_34[0]['raw']['value']+$row->field_field_age_35_44[0]['raw']['value']+$row->field_field_age_45_54[0]['raw']['value']+$row->field_field_age_55_59[0]['raw']['value']+$row->field_field_age_60_64[0]['raw']['value']+$row->field_field_age_65_74[0]['raw']['value']+$row->field_field_age_75_84[0]['raw']['value']+$row->field_field_age_85_over[0]['raw']['value'])), '10-24');
$age25_34 = array($row->field_field_age_25_34[0]['raw']['value'], '25-34');
$age35_44 = array($row->field_field_age_35_44[0]['raw']['value'], '35-44');
$age45_54 = array($row->field_field_age_45_54[0]['raw']['value'], '45-54');
$age55_64 = array($row->field_field_age_55_59[0]['raw']['value']+$row->field_field_age_60_64[0]['raw']['value'], '55-64');
$age65up = array($row->field_field_age_65_over[0]['raw']['value'], 'Over 65');

$result = max($ageunder5, $age5_17, $age10_24, $age25_34, $age35_44, $age45_54, $age55_64, $age65up);

?>
<div class="data">
  <div class="icon white">
    <i class="flaticon-family21"></i>
  </div>
  <div class="output">
    <span class="change">Most residents are</span>
    <hr>
    <span class="pop"><span class="text"><?php print $result[1]; ?> Years old</span></span>
  </div>
</div>
