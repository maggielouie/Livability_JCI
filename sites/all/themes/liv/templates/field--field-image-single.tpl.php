
  <?php foreach ($items as $delta => $item): ?>
    <span class="center-bg shadow-inset-lr shadow-bottom" style="background-image: url('<?php echo file_create_url($item['#item']['uri']); ?>')">
      <?php echo $item['#item']['alt']; ?>
    </span>
    <?php if (!empty($item['#item']['field_byline'][LANGUAGE_NONE][0]) && !is_null($item['#item']['field_byline'][LANGUAGE_NONE][0]['value'])) {
      echo '<p class="credit">PHOTO CREDIT: '.$item['#item']['field_byline'][LANGUAGE_NONE][0]['value'].'</p>';
    } ?>
  <?php endforeach; ?>
