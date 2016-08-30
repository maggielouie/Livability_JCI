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
 *
 * = LIVABILITY USAGE =
 * This template is for using the nid field to retrieve and display the census data city population
 * via city_node_load.
 */
?>
<?php
$nid = $field->original_value;
$city = city_node_load($nid);
$pop = $city->census['city-data']['DP05_0001E'];
?>
<span class="city-pop">
    Population: <?php print number_format($pop);?>
</span>
