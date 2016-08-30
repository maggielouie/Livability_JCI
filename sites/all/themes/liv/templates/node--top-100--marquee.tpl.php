<?php $titlelink = '';

$titlelink .= '<i class="no-mobile">Top 100</i>';

$titlelink .= $title;
$buttonlink = 'Read more<i class="raquo-white no-mobile"></i>'; 

$image_uri = '';
if ($content['field_top_100_item']['#object']->field_featured_image) {
	$image_uri = $content['field_top_100_item']['#object']->field_featured_image[LANGUAGE_NONE][0]['uri'];
} elseif ($content['field_top_100_item'][0]['entity']['field_collection_item']) {
  foreach ($content['field_top_100_item'][0]['entity']['field_collection_item'] as $key => $value) {
    $image_uri = $value['field_image_single']['#items'][0]['uri'];
  }
  
}

?>
<span class="hero-image center-bg shadow-inset-lr" style="background-image: url('<?php echo file_create_url($image_uri); ?>')"></span>
<div class="summary">
	<h2><?php print l($titlelink, 'node/'.$node->nid, array('html' => TRUE)); ?></h2>
<p>
<?php if (isset($content['field_deck']) && !isset($content['field_short_description'])) {
	print render($content['field_deck']).'.';
}
if (isset($content['field_short_description'])) {
	print '<span class="no-mobile">'. render($content['field_short_description']) .'</span>';
}
// print l($buttonlink, 'node/'.$node->nid, array('html' => TRUE, 'attributes' => array('class' => array('button-orange')))); ?>
</p>
</div>