
<?php if (isset($variables['element']['#view_mode']) && ($variables['element']['#view_mode'] == 'tile')) : ?>
  <?php foreach ($items as $delta => $item): ?>
    <?php if ($delta == 0) : ?>
    <?php print l('<img src="' . image_style_url('325x216', $item['#item']['uri']) .'" alt="'. $item['#item']['alt'] .'" />', 'node/'.$variables['element']['#object']->nid, array('html' => TRUE)); ?>
    <?php endif; ?>
  <?php endforeach; ?>
<?php else: ?>
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
    <div class="royalSlider hero-slider rsHor rsWithBullets">
      <?php foreach ($items as $delta => $item): ?>
        <div>
          <span class="hero-image center-bg shadow-inset-lr" style="background-image: url('<?php echo file_create_url($item['#item']['uri']); ?>')">
            <?php echo $item['#item']['alt']; ?>
          </span><?php /* this is where the summary would go in other instances */ ?>
          <?php if (isset($item['#item']['field_byline']['und']) || isset($item['#item']['field_file_image_title_text']['und']) || isset($item['#item']['field_description']['und'])) {
            echo '<span class="summary">';
            if (isset($item['#item']['field_file_image_title_text']['und'])) {
              echo '<h3>'.$item['#item']['field_file_image_title_text']['und'][0]['value'].'</h3>';
            }
            if (isset($item['#item']['field_description']['und'])) {
              echo '<p>'.$item['#item']['field_description']['und'][0]['value'].'</p>';
            }
            elseif (isset($item['#item']['field_file_image_alt_text']['und'])) {
              echo '<p>'.$item['#item']['field_file_image_alt_text']['und'][0]['value'].'</p>';
            }
            elseif (isset($item['#item']['alt'])) {
              echo '<p>'.$item['#item']['alt'].'</p>';
            }
            if (isset($item['#item']['field_byline']['und'])) {
              echo '<p class="credit">PHOTO CREDIT: '.$item['#item']['field_byline']['und'][0]['value'].'</p>';
            }
            echo '</span>';
          } ?>
        </div>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
<?php endif; ?>