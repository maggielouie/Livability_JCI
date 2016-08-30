<div><div>
    <?php
      // We hide the comments to render below.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>

    <?php
      print views_embed_view('top_cities_list', 'top_cities_block', $node->nid);
    ?>
    </div>
  </div> <!-- /content -->