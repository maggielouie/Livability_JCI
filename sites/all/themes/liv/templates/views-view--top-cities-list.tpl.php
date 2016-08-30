<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */

?>

<span class="top-100">
<?php
$nid = $view->args[0];
$node = node_load($nid);
$urlBase = url(arg(0) . '/' . arg(1));

$top100nav = '<ul class="top-100-tabs">';
$top100nav .= '<li';
$top100nav .= !arg(2) ? ' class="active">' : '>';
$top100nav .= '<a href="'.$urlBase.'">Rankings</a></li>';
if ($node->field_ranking_methodology_page) {
    $top100nav .= '<li';
    $top100nav .= (arg(2) == 'ranking-data') ? ' class="active">' : '>';
    $top100nav .= '<a href="'.$urlBase.'/ranking-data">Ranking Data</a></li></ul>';
}
$top100nav .= '<ul class="top-100-links">';
if ($node->field_top_100_ranking_page) {
    $top100nav .= '<li';
    $top100nav .= (arg(2) == 'ranking-criteria') ? ' class="active"><span>Ranking Criteria</span>' : '><a href="'.$urlBase.'/ranking-criteria">Ranking Criteria</a>';
    $top100nav .= '</li>';
}
if ($node->field_ranking_methodology_page) {
    $top100nav .= '<li';
    $top100nav .= (arg(2) == 'methodology') ? ' class="active"><span>Methodology</span>' : '><a href="'.$urlBase.'/methodology">Methodology</a>';
    $top100nav .= '</li>';
}
if ($node->field_top_100_advisory_board_pag) {
    $top100nav .= '<li';
    $top100nav .= (arg(2) == 'advisory-board') ? ' class="active"><span>Advisory Board</span>' : '><a href="'.$urlBase.'/advisory-board">Advisory Board</a>';
    $top100nav .= '</li>';
}
$top100nav .= '</ul>';
print $top100nav;
?>
<div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <?php print $title; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($header): ?>
        <div class="view-header">
            <?php print $header; ?>
        </div>
    <?php endif; ?>

    <?php if ($exposed): ?>
        <div class="view-filters">
            <?php print $exposed; ?>
        </div>
    <?php endif; ?>

    <?php if ($attachment_before): ?>
        <div class="attachment attachment-before">
            <?php print $attachment_before; ?>
        </div>
    <?php endif; ?>

    <?php if ($rows): ?>
        <div class="view-content">
            <?php print $rows; ?>
        </div>
    <?php elseif ($empty): ?>
        <div class="view-empty">
            <?php print $empty; ?>
        </div>
    <?php endif; ?>

    <?php if ($pager): ?>
        <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($attachment_after): ?>
        <div class="attachment attachment-after">
            <?php print $attachment_after; ?>
        </div>
    <?php endif; ?>

    <?php if ($more): ?>
        <?php print $more; ?>
    <?php endif; ?>

    <?php if ($footer): ?>
        <div class="view-footer">
            <?php $node->field_top_cities_footer ? $footer = $node->field_top_cities_footer[LANGUAGE_NONE][0]['value']: $footer; ?>
            <?php print $footer; ?>
        </div>
    <?php endif; ?>

    <?php if ($feed_icon): ?>
        <div class="feed-icon">
            <?php print $feed_icon; ?>
        </div>
    <?php endif; ?>

</div><?php /* class view */ ?>
</span>