<?php if (isset($content['field_image'])) {
  $img = file_create_url($content['field_image'][0]['#item']['uri']);
} 
else {
 $img = '/'.drupal_get_path('theme', 'liv').'/images/325x216.jpg';
} ?>
<a href="<?php print $node_url; ?>">
  <span class="thumb-95" style="background-image: url('<?php print $img; ?>'); background-size: cover; background-position: 50%;"></span>
  <h2><?php print $title; ?></h2>
</a>