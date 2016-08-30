
<?php $imgtot = count($items);
if ($imgtot < 2 || $element['#view_mode'] == 'blog_home' ) : ?>
  <?php if ($element['#view_mode'] !== 'tile') { ?>
    <span class="featured-image shadow-bottom clearfix">
  <?php } ?>
  <?php foreach ($items as $delta => $item) {
    if ($delta == 0) {
      if ($element['#view_mode'] !== 'tile') {
        $imgoutput = '<span class="center-bg shadow-inset-lr" style="background-image: url(\'' . file_create_url($item['#item']['uri']) . '\')">' . $item['#item']['alt'] . '</span>';
      }
      else {
        $imgoutput = '<img src="' . image_style_url('325x216', $item['#item']['uri']) .'" alt="'. $item['#item']['alt'] .'" />';
      }
      if ($element['#view_mode'] == 'blog_home') {
        print l($imgoutput, 'node/'.$element['#object']->nid, array('html' => TRUE));
      }
      else {
        print $imgoutput;
      }
    }
  } ?>
<?php if ($element['#view_mode'] !== 'tile') { ?>
</span>
<?php } ?>
<?php else : ?>
<div class="hero-slider rsHor rsWithBullets">
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
        echo '<p class="credit">PHOTO: '.$item['#item']['field_byline']['und'][0]['value'].'</p>';
      }
      echo '</span>';
    } ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif; ?>