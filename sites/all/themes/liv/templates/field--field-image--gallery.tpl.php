<?php
$imgtot = count($items);
if ($imgtot < 2 ) : ?>
<span class="featured-image shadow-bottom clearfix">
  <?php foreach ($items as $delta => $item): ?>
    <span class="center-bg shadow-inset-lr" style="background-image: url('<?php echo file_create_url($item['#item']['uri']); ?>')">
      <?php echo $item['#item']['alt']; ?>
    </span>
  <?php endforeach; ?>
</span>
<?php else : ?>
  <div class="fwImage">
    <div id="gallery" class="royalSlider rsDefault">

    <?php foreach ($items as $delta => $item): ?>
  
    <a class="rsImg" href="<?php echo image_style_url('gallery', $item['#item']['uri']); ?>">
    <?php 
      if (isset($item['#item']['field_file_image_title_text']['und'])) {
        echo '<h2>'.$item['#item']['field_file_image_title_text']['und'][0]['value'].'</h2>';
      }
      else { 
        if (isset($item['#item']['field_title']['und'])) {
          echo '<h2>'.$item['#item']['field_title']['und'][0]['value'].'</h2>';
        }
      }
      echo '<p class="no-mobile">';
      if (isset($item['#item']['field_description']['und'])) {
        echo strip_tags($item['#item']['field_description']['und'][0]['value']);
      }
      elseif (isset($item['#item']['field_file_image_alt_text']['und'])) {
        echo strip_tags($item['#item']['field_file_image_alt_text']['und'][0]['value']);
      }
      elseif (isset($item['#item']['alt'])) {
        echo strip_tags($item['#item']['alt']);
      }
      if (isset($item['#item']['field_byline']['und']) && !is_null($item['#item']['field_byline']['und'][0]['value'])) {
        echo '<p class="credit">PHOTO: '.strip_tags($item['#item']['field_byline']['und'][0]['value']).'</p>';
      }
      echo '</p>';
    ?>
    <img class="rsTmb" src="<?php echo image_style_url('media_thumbnail', $item['#item']['uri']); ?>" />
    </a>

  <?php endforeach; ?>
</div>
</div>
<?php endif; ?>