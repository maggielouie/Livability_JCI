<?php $titlelink = '';
if (isset($content['field_category'])) {
	$titlelink .= '<i class="no-mobile">'.render($content['field_category'][0]).'</i>';
} 
$titlelink .= $title;
$buttonlink = 'Read more<i class="raquo-white no-mobile"></i>'; 
?>
<span class="hero-image center-bg shadow-inset-lr" style="background-image: url('<?php echo file_create_url($content['field_image'][0]['#item']['uri']); ?>')">
	<?php if (isset($content['field_image'][0]['#item']['field_file_image_alt_text']['und'])) { print $content['field_image'][0]['#item']['field_file_image_alt_text']['und'][0]['value']; } ?>
</span>
<div class="summary">
	<h2><?php print l($titlelink, 'node/'.$node->nid, array('html' => TRUE)); ?></h2>
<p>
<?php if (isset($content['field_deck']) && !isset($content['field_short_description'])) {
	print render($content['field_deck']);
}
elseif (isset($content['field_short_description'])) {
	print render($content['field_short_description']).'.';
}
// print l($buttonlink, 'node/'.$node->nid, array('html' => TRUE, 'attributes' => array('class' => array('button-orange')))); ?>
</p>
</div>
