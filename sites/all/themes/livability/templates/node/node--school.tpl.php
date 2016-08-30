<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    print render($content);
  ?>
  <div class="grateschools">
      <a class="grateschools-logo" href="http://www.greatschools.org/city/<?php print $field_city[0]['entity']->title; ?>/<?php print $field_state[0]['entity']->field_usps_code[LANGUAGE_NONE][0]['value']; ?>" target="_blank"></a>
  </div>
  <?php if(!empty($field_address)): ?>
  <div style="overflow:hidden;width:500px;height:500px;resize:none;max-width:100%;">
  <div id="gmap-display" style="height:100%; width:100%;max-width:100%;">
    <iframe style="height:100%;width:100%;border:0;" frameborder="0" src="https://www.google.com/maps/embed/v1/place?q=<?php print $field_address[0]['thoroughfare']; ?>,+<?php print $field_address[0]['locality']; ?>,+<?php print $field_state[0]['entity']->title; ?>,+<?php print $field_address[0]['postal_code']; ?>,+United+States&key=AIzaSyAN0om9mFmy1QN6Wf54tXAowK4eT0ZUPrU"></iframe>
  </div>
  <?php endif; ?>
</article>
