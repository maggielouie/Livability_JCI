<div><div>
    <?php
      // We hide the comments to render below.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
      $top_lb_ad = block_load('combo_ad_blocks', 'pushdown');
      $top_lb_ad_output = _block_get_renderable_array(_block_render_blocks(array($top_lb_ad)));
      print drupal_render($top_lb_ad_output);
    ?>
    <?php
      print views_embed_view('top_cities_list', 'top_cities_block', $node->nid);
    ?>
    </div>
  </div> <!-- /content -->