<?php $imgtot = count($items);
if ($imgtot < 2 ) : ?>
<span class="featured-image clearfix">
  <?php foreach ($items as $delta => $item): ?>
    <span class="center-bg shadow-inset-lr shadow-bottom" style="background-image: url('<?php echo file_create_url($item['#item']['uri']); ?>')">
      <?php echo $item['#item']['alt']; ?>
    </span>
    <?php if (!empty($item['#item']['field_byline'][LANGUAGE_NONE][0])) {
      echo '<p class="credit">PHOTO CREDIT: '.$item['#item']['field_byline'][LANGUAGE_NONE][0]['value'].'</p>';
    } ?>
  <?php endforeach; ?>
</span>
<?php else : ?>
<div class="hero-slider rsHor rsWithBullets">
  <?php foreach ($items as $delta => $item): ?>
    <span class="hero-image center-bg shadow-inset-lr" style="background-image: url('<?php echo file_create_url($item['#item']['uri']); ?>')">
      <?php echo $item['#item']['alt']; ?>
    </span>
  <?php endforeach; ?>
</div>
<?php endif; ?>