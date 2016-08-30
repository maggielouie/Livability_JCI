
  <?php foreach ($items as $delta => $item): ?>
  <?php $imgpath = file_create_url($item['#item']['uri']);
  if (isset($item['#image_style'])) {
    $imgpath =  image_style_url($item['#image_style'], $item['#item']['uri']);
  } ?>
    <img src="<?php echo $imgpath; ?>" alt="<?php echo $item['#item']['alt']; ?>" class="one-fourth" />
  <?php endforeach; ?>
