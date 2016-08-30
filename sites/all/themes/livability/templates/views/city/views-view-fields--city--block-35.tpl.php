<?php if (!empty($row->field_field_image)) { ?>
  <?php print $view->field['field_image']->original_value; ?>
  <br />
  <div class="city-quote">
    <h5 class="green-text text-center"><?php print $row->node_title; ?></h5>
    <?php print $row->field_body[0]['raw']['value']; ?>
  </div>
<?php } else { ?>
  <div class="icon-top liv-icon-green"></div>
  <div class="city-quote">
    <h5 class="green-text text-center"><?php print $row->node_title; ?></h5>
    <?php print $row->field_body[0]['raw']['value']; ?>
  </div>
<?php } ?>