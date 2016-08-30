
<span class="image-icon">
  <?php 
  if ($content['field_top_100_item']['#object']->field_featured_image) {
    $image_uri = $content['field_top_100_item']['#object']->field_featured_image[LANGUAGE_NONE][0]['uri'];
    $image = image_load($image_uri);
      $img_output = array(
        'file' => array(
          '#theme' => 'image_style',
          '#style_name' => '325x216',
          '#path' => $image->source,
          '#width' => $image->info['width'],
          '#height' => $image->info['height'],
        ),
      );
    print drupal_render($img_output);
  } elseif ($content['field_top_100_item'][0]['entity']['field_collection_item']) {
    foreach ($content['field_top_100_item'][0]['entity']['field_collection_item'] as $key => $value) {
      $file = file_load($value['field_image_single']['#items'][0]['fid']);
      $image = image_load($file->uri);
      $img_output = array(
        'file' => array(
          '#theme' => 'image_style',
          '#style_name' => '325x216',
          '#path' => $image->source,
          '#width' => $image->info['width'],
          '#height' => $image->info['height'],
        ),
      );
      print drupal_render($img_output);
    }
    
  } else {
    print '<a href="'.$node_url.'"><img src="/'.drupal_get_path('theme', 'liv').'/images/325x216.jpg" alt="placeholder" /></a>';
  }
  ?>

  <?php /* ?>
  <span class="circle-icon">
    <span class="sticker-orange-horizontal">
      <i class="icon-top10 white"></i>
    </span>
  </span>
  <?php */ ?>
</span>
<span class="summary">
  <h2><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <span class="interact"></span>
</span>