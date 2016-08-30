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
<?php
    $nid = $view->args[0];
    $node = node_load($nid);
    $title = $node->title;
    $date = new DateTime($node->field_year[LANGUAGE_NONE][0]['value']);
    $year = $date->format('Y');
    $deck = $node->field_deck[LANGUAGE_NONE][0]['value'];
    $body = $node->body[LANGUAGE_NONE][0]['value'];
    $wrapper = entity_metadata_wrapper('node', $node);
    $ranking_page = FALSE;
    $methodology = FALSE;
    $advisory_board = FALSE;

if ($wrapper->field_top_100_ranking_page->value() !== NULL && $wrapper->field_top_100_ranking_page->field_top_100_ranking_criteria->value()) {
    $ranking_page = TRUE;
}
if ($wrapper->field_ranking_methodology_page->value() !== NULL) {
    $methodology = TRUE;
}
if ($wrapper->field_top_100_advisory_board_pag->value() !== NULL && $wrapper->field_top_100_advisory_board_pag->field_top_100_advisory_board->value()) {
    $advisory_board = TRUE;
}
?>

<article>
    <div class="padded top-100 top-cities">
    <span class="year"><?php print $year; ?></span>
    <h1><?php print $title; ?></h1>
    <div class="top-100-sponsored-by"><span class="sponsored-by-txt">Sponsored by:</span>
      <?php $topad = block_load('jci_dfp', 'jci-dfp-block-28');
      $output = _block_get_renderable_array(_block_render_blocks(array($topad)));
      print drupal_render($output);?>
    </div>
        <span><?php print $deck; ?></span>
        <span class="top-10-nav clearfix">
            <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
        </span>
        <div class="content">

            <?php print $body; ?>

<?php
    $nid = $view->args[0];
    $node = node_load($nid);
    $urlBase = url(arg(0) . '/' . arg(1));

    $top100nav = '<ul class="top-100-tabs">';
    $top100nav .= '<li';
    $top100nav .= !arg(2) ? ' class="active">' : '>';
    $top100nav .= '<a href="'.$urlBase.'">Rankings</a></li>';
    if ($methodology) {
        $top100nav .= '<li';
        $top100nav .= (arg(2) == 'ranking-data') ? ' class="active">' : '>';
        $top100nav .= '<a href="'.$urlBase.'/ranking-data">Ranking Data</a></li></ul>';
    }
    $top100nav .= '<ul class="top-100-links">';
    if ($ranking_page) {
        $top100nav .= '<li';
        $top100nav .= (arg(2) == 'ranking-criteria') ? ' class="active"><span>Ranking Criteria</span>' : '><a href="'.$urlBase.'/ranking-criteria">Ranking Criteria</a>';
        $top100nav .= '</li>';
    }
    if ($methodology) {
        $top100nav .= '<li';
        $top100nav .= (arg(2) == 'methodology') ? ' class="active"><span>Methodology</span>' : '><a href="'.$urlBase.'/methodology">Methodology</a>';
        $top100nav .= '</li>';
    }
    if ($advisory_board) {
        $top100nav .= '<li';
        $top100nav .= (arg(2) == 'advisory-board') ? ' class="active"><span>Advisory Board</span>' : '><a href="'.$urlBase.'/advisory-board">Advisory Board</a>';
        $top100nav .= '</li>';
    }
    $top100nav .= '</ul>';
    print $top100nav;
?>


      <?php if ($header): ?>
          <?php print $header; ?>
      <?php endif; ?>

        <?php if ($attachment_before): ?>
            <?php print $attachment_before; ?>
        <?php endif; ?>

        <div class="top-100-content rankings <?php print arg(3); ?>">
      <?php if ($rows): ?>
          <?php print $rows; ?>
      <?php elseif ($empty): ?>
          <?php print $empty; ?>
      <?php endif; ?>

      <?php if ($pager): ?>
          <?php print $pager; ?>
      <?php endif; ?>

      <?php if ($attachment_after): ?>
          <?php print $attachment_after; ?>
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
      </div>
    </article>
</div>

