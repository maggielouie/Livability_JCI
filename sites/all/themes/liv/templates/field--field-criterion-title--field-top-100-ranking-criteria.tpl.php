
  <?php foreach ($items as $delta => $item): ?>
    <h2 id="<?php print strtolower(drupal_clean_css_identifier($element['#object']->field_criterion_title['und'][0]['value'])); ?>" class="js-more-title"><i class="icon-arrow-down control"></i><?php print render($item); ?></h2>
  <?php endforeach; ?>
