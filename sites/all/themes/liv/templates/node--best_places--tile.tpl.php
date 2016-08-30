
<span class="image-icon">
  <?php  if (isset($content['field_image'])) {
    // print render($content['field_image']);
    $fid = $content['field_image']['#items'][0]['fid'];
    $file = file_load($fid);
    $image = image_load($file->uri);
    $img_content = array(
      'file' => array(
        '#theme' => 'image_style',
        '#style_name' => '325x216',
        '#path' => $image->source,
        '#width' => $image->info['width'],
        '#height' => $image->info['height'],
      ),
    );
    print l(drupal_render($img_content), 'node/' . $node->nid, array('html' => TRUE));
  } else {
    // dsm(render($content['body']));
    $doc = new DOMDocument();
    @$doc->loadHTML(render($content['body']));
    $tags = $doc->getElementsByTagName('img');
    $img = array();
    foreach ($tags as $tag) {
      $img[] = $tag->getAttribute('src');
    }
    if (isset($img[0])) {
      $pieces = explode('/', $img[0]);
      // Display the first embedded image in the body content
      print l('<img src="' . image_style_url('325x216', end($pieces)) .'" alt="placeholder" />', 'node/'.$node->nid, array('html' => TRUE));
    } else {
      print '<a href="'.$node_url.'"><img src="/'.drupal_get_path('theme', 'liv').'/images/325x216.jpg" alt="placeholder" /></a>';
    }
  } ?>
<?php /*

    print '<span class="circle-icon">';
      print '<span class="sticker-orange-horizontal">';
        print '<i class="icon-top10 white"></i>';
      print '</span>';
    print '</span>';
  
    */
 ?>

</span>
<span class="summary">
  <h2><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <span class="interact"></span>
</span>
