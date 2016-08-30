<?php $titlelink = '';
if (isset($content['field_category'])) {
	$titlelink .= '<i class="no-mobile">'.render($content['field_category'][0]).'</i>';
} 
$titlelink .= $title;
$buttonlink = 'Read more<i class="raquo-white no-mobile"></i>'; 
$image_uri = '';
$image_alt = '';
if ($content['field_image']) {
	$image_uri = $content['field_image'][0]['#item']['uri'];
	if (isset($content['field_image'][0]['#item']['field_file_image_alt_text']['und'])) { 
		$image_alt = $content['field_image'][0]['#item']['field_file_image_alt_text']['und'][0]['value']; 
	}
} elseif ($content['field_article_thumbnail']) {
	$image_uri = $content['field_article_thumbnail'][0]['#item']['uri'];
	if (isset($content['field_article_thumbnail'][0]['#item']['field_file_image_alt_text']['und'])) { 
		$image_alt = $content['field_article_thumbnail'][0]['#item']['field_file_image_alt_text']['und'][0]['value']; 
	}
}
?>
<span class="hero-image center-bg shadow-inset-lr" style="background-image: url('<?php echo file_create_url($image_uri); ?>')">
	<?php print $image_alt;  ?>
</span>
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