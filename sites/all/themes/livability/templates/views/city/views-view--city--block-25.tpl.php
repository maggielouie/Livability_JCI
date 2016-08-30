<?php
$node = node_load($view->args[0]);
$city = $node->title;
$state = $node->field_state['und'][0]['entity']->title;
$path = drupal_get_path_alias('node/'.$node->nid.'');

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
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div class="view-header">
    <div class="text-center"><small>In <?php print $city; ?>, <?php print $state; ?></small></div>
    <br /><?php print $header; ?>
    Access to quality hospitals, doctors and health-care providers is just part of what makes a healthy community. Here’s how to get and stay healthy in <?php print $city; ?>.
    <hr>
  </div>

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

  <div class="view-footer">
    <a href="/<?php print $path; ?>/health/healthy-lifestyle" >Healthy Lifestyles in <?php print $city; ?>, <?php print $state; ?></a>
    <br />
    <a href="/<?php print $path; ?>/health/doctors" >Doctors in <?php print $city; ?>, <?php print $state; ?></a>
    <br />
    <a href="/<?php print $path; ?>/health/hospitals" >Hospitals in <?php print $city; ?>, <?php print $state; ?></a>
    <br /><br />
    <a href="/<?php print $path; ?>/health" >More Health &rsaquo;</a>
  </div>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>
</div><?php /* class view */ ?>
