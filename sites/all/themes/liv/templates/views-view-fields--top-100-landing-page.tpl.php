<?php

$data = node_load($row->nid);
// dpm($data);
$text = '<span class="center-bg circle"';
if ($data->field_featured_image) {
	$text .= 'style="background-image: url(\''.file_create_url($data->field_featured_image[LANGUAGE_NONE][0]['uri']).'\')"';
} elseif (isset($data->field_top_100_item[LANGUAGE_NONE][0]['value'])) {
    $id = $data->field_top_100_item[LANGUAGE_NONE][0]['value'];
    $numberOne = field_collection_item_load($id);
    $text .= 'style="background-image: url(\''.file_create_url($numberOne->field_image_single[LANGUAGE_NONE][0]['uri']).'\')"';
}
$text .= '>';
$text .= '<span class="fill-overlay circle"><span class="seal-orange no-mobile"><i class="icon-top10 white"></i></span></span>'.
    '</span>';
$text .= '<span class="left"><h2>';

//$term = taxonomy_term_load($data->field_bp_category[LANGUAGE_NONE][0]['tid']);

$text .= $data->title . ' ' . date('Y', strtotime($data->field_year[LANGUAGE_NONE][0]['value']));

$text .= '<i class="icon-arrow-right-circle no-mobile"></i></span></h2>';
print l($text, 'node/'.$data->nid, array('html' => TRUE));
$text = '';