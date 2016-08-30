<?php
$data = node_load($row->nid);
$text = '<span class="center-bg circle"';
if (isset($data->field_image[LANGUAGE_NONE][0])) {
    $text .= 'style="background-image: url(\''.file_create_url($data->field_image[LANGUAGE_NONE][0]['uri']).'\')"';
}
$text .= '>';
$text .= '<span class="fill-overlay circle"><span class="seal-orange no-mobile"><i class="icon-top10 white"></i></span></span></span>';
$text .= '<span class="left"><h2>'.$data->title.'<i class="icon-arrow-right-circle no-mobile"></i></h2></span>';
print l($text, 'node/'.$row->nid, array('html' => TRUE)); ?>
