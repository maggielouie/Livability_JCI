<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    print render($content);
  ?>
<div style="overflow:hidden;width:500px;height:500px;resize:none;max-width:100%;">
  <div id="gmap-display" style="height:100%; width:100%;max-width:100%;">
    <iframe style="height:100%;width:100%;border:0;" frameborder="0" src="https://www.google.com/maps/embed/v1/place?q=<?php print $title; ?>,+<?php print $field_state[0]['entity']->title; ?>,+United+States&key=AIzaSyAN0om9mFmy1QN6Wf54tXAowK4eT0ZUPrU"></iframe>
  </div>
</div>
</article>
