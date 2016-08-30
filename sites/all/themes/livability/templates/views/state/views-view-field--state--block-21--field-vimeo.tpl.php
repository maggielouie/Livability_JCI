<?php
if (!empty($row->field_field_vimeo)) {
  $vlink = $row->field_field_vimeo[0]['raw']['value'];
  $vid = substr($vlink, strrpos($vlink, "/") + 1);
}
?>
<?php if (!empty($row->field_field_vimeo)) { ?>
<div class="embed-responsive embed-responsive-16by9">
  <iframe class="embed-responsive-item" src="https://player.vimeo.com/video/<?php print $vid; ?>" width="500" height="281" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>
</div>
<?php } ?>