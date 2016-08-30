
  <?php foreach ($items as $delta => $item): ?>
    <div class="section <?php print $delta % 2 ? 'odd' : 'even'; ?>">

    <?php foreach($item['entity']['field_collection_item'] as $fcid => $entity){
      print render($item['entity']['field_collection_item'][$fcid]['field_image_single']);
      print render($item['entity']['field_collection_item'][$fcid]['field_top_100_board_name']);
      print render($item['entity']['field_collection_item'][$fcid]['field_top_100_board_bio']);
    } ?>
    <br style="clear:both;" />
    </div>
  <?php endforeach; ?>
