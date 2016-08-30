
  <?php if (isset($content['field_image'])) {
    print render($content['field_image']);
  } ?>
<span class="blog-details">
  <?php if (isset($content['field_blog_category'])) { ?>
    <span class="blog-category">
      <?php print render($content['field_blog_category']); ?>
    </span>
  <?php } ?>
  <?php print render($title_prefix); ?>
    <h1><?php print l($title, 'node/'.$nid, array('html' => TRUE)); ?><?php // print $title; ?></h1>
  <?php print render($title_suffix); ?>

  <span class="author">
    <?php if (isset($field_author[0])) {
      $name = $field_author[0]['entity']->name;
      echo "By " . l($name, 'user/'.$field_author[0]['target_id']) . " on ";
    }
    elseif (isset($field_byline['und'])) {
      $name = $field_byline['und'][0]['value']; echo "By $name on ";
    }
    $createdate = $node->created;
    echo date('F j, Y', $createdate); ?> at <?php echo date('g:i a T', $createdate); ?>
  </span>
  <?php if (isset($content['field_deck'])) { print render($content['field_deck']); }
  else { print render($content['body']); } ?>
</span>
