
  <?php foreach ($items as $delta => $item): ?>
    <div class="section <?php print $delta % 2 ? 'odd' : 'even'; ?>">
    <?php foreach($item['entity']['field_collection_item'] as $fcid => $entity){

      $content = '';
      $content .= render($item['entity']['field_collection_item'][$fcid]['field_image_single']);
      $content .= render($item['entity']['field_collection_item'][$fcid]['field_criterion_title']);
      $desc = render($item['entity']['field_collection_item'][$fcid]['field_top_100_description']);
      $more = '';
      $descwc = strlen($desc);
      if ($descwc > 600) {

      echo '<div class="'. strtolower(drupal_clean_css_identifier($item['entity']['field_collection_item'][$fcid]['field_criterion_title']['#object']->field_criterion_title['und'][0]['value'])) . '-contents" style="overflow:hidden; height: 180px; position:relative;">';

      $content .= render($item['entity']['field_collection_item'][$fcid]['field_top_100_description']).'<br style="clear:both;" />';
      print $content . '</div>';

    } ?>
    </div>
  <?php
    $more = '<a id="'. strtolower(drupal_clean_css_identifier($item['entity']['field_collection_item'][$fcid]['field_criterion_title']['#object']->field_criterion_title['und'][0]['value'])) .'" class="js-more" style="float: right; margin-right:10px">Read more</a>';
    echo $more;
    }
    ?>
  <?php endforeach; ?>
