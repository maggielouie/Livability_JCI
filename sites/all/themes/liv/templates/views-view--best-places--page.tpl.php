<?php
// Lookup alias.
$source = db_query("SELECT source FROM
  {url_alias} WHERE alias = :alias", array(
  ':alias' => arg(0) . '/' . arg(1) . '/' .arg(2) . '/' . arg(3),
))->fetchColumn();

$node = NULL;

// Determine best places node.
if ($source) {
  $nid = str_replace('node/', '', $source);
  $node = node_load($nid);
  $city_id = $node->field_list_item['und'][10-$view->list_position]['value'];

  // Find the current city selected on the best places list.
  if ($city_id) {
    // Find the meta description for this city.
    $meta_description = db_query('SELECT field_meta_description_value
      FROM {field_data_field_meta_description}
      WHERE entity_id = :entity_id AND entity_type = :entity_type', array(
      ':entity_id' => $city_id,
      ':entity_type' => 'field_collection_item',
    ))->fetchColumn();

    if ($meta_description) {
      $metadesc = array(
        '#tag' => 'meta',
        '#attributes' => array(
          'name' => 'description',
          'content' => $meta_description,
        ),
      );
      drupal_add_html_head($metadesc, 'meta_description');
    }
  }
}
?>
<article>
<span class="padded clearfix">
  <?php print render($title_prefix); ?>
  <span class="right">
    <div class="top-100-sponsored-by"><span class="sponsored-by-txt">Sponsored by:</span>
      <?php print getDumbDFP(27);?>
    </div>
  </span>
  <span class="year"><?php print date('Y', strtotime($variables['view']->result[0]->field_field_year[0]['rendered'])); ?></span>
  <h1><?php print $variables['view']->result[0]->field_list_item_field_collection_item_title; ?></h1>
  <?php if (isset($variables['view']->result[0]->field_field_bp_category[0])) : ?>
    <h2><?php print render($variables['view']->result[0]->field_field_bp_category[0]['rendered']); ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <span class="synopsis clearfix"></span>
  <span class="top-10-nav clearfix">
    <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
    <span class="city-pin">
      <a href="/<?php print $view->current_city_path; ?>">
        <span class="top-10-no"><?php print $view->list_position; ?></span>
        <h1><?php print $view->current_city; ?>, <strong class="green"><?php print $view->current_state; ?></strong></h1>
      </a>
    </span>
  </span>
</span>
<span class="padded">

  <?php if ($attachment_before): ?>
    <?php print $attachment_before; ?>
  <?php endif; ?>

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
      <?php print $footer; ?>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</span><?php /* class view */ ?>
</article>
