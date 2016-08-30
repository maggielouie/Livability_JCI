<div class="data">
  <div class="icon white">
    <i class="fa fa-graduation-cap fa-2x"></i>
  </div>
  <div class="output">
    <div class="clearfix"><strong><span class="pull-left">Bachelor’s Degree</span> <span class="pull-right"><?php print $row->field_field_education_percent_bachelor[0]['raw']['value']; ?>%</span></strong></div>
    <div class="progress">
      <div class="progress-bar" role="progressbar" aria-valuenow="60" aria-valuemin="0" aria-valuemax="100" style="width: <?php print $row->field_field_education_percent_bachelor[0]['raw']['value']; ?>%;">
        <span class="sr-only"><?php print $row->field_field_education_percent_bachelor[0]['raw']['value']; ?>% Complete</span>
      </div>
    </div>
    <div class="clearfix"><strong><span class="pull-left">Graduated High School</span> <span class="pull-right"><?php print $row->field_field_education_percent_high_sch[0]['raw']['value']; ?>%</span></strong></div>
    <div class="progress">
      <div class="progress-bar" role="progressbar" aria-valuenow="60" aria-valuemin="0" aria-valuemax="100" style="width: <?php print $row->field_field_education_percent_high_sch[0]['raw']['value']; ?>%;">
        <span class="sr-only"><?php print $row->field_field_education_percent_high_sch[0]['raw']['value']; ?>% Complete</span>
      </div>
    </div>
  </div>
</div>