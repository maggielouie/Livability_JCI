<?php print render($title_prefix); ?>
<?php if ($title): ?>
<div class="block-title">
  <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
</div>
<?php endif;?>
<?php print render($title_suffix); ?>

<h4 class="text-center"><?php print number_format($view->totals->sum__field_data_field_population_node_entity_type); ?></h4>
