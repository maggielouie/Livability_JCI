
  <?php foreach ($items as $delta => $item): ?>
    <img src="<?php echo file_create_url($item['#item']['uri']); ?>" alt="<?php echo $item['#item']['alt']; ?>" class="one-q" style="margin-right: 1em;" />
  <?php endforeach; ?>
