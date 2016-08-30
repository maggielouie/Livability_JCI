<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
// dsm($view);
?>
<div class="ss-col ss-articles">
<?php 
$node = node_load($view->args[0][0]);
$n=0;
foreach ($node->field_ss_articles['und'] as $key => $value) {
	$n++;
	$n % 2 == 0 ? $class = 'even' : $class = 'odd';
	$out .= $class == 'odd' ? '<div class="row-article">' : '';
	$out .= "<div class=\"ss-article $class\">";
	$out .= views_embed_view('special_section', 'block_1', $value['target_id']);
	$out .= '</div>';
	$out .= $class == 'even' ? '</div>' : '';
}
print $out;
?>
</div>