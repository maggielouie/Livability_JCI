<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!empty($variables['region']['liv_city_featured_img'])) { ?>
  <div class="row clearfix">
    <div class="col-md-3 madlib clearfix">
      <?php print render($region['share']); ?>
      <h2>What you need to know about <?php print $node->title.', '.$node->field_state[LANGUAGE_NONE][0]['entity']->field_state_code[LANGUAGE_NONE][0]['value']; ?></h2>
      <div class="body">
        <?php if(!empty($content['body'])) {
          print render($content['body']);
        } else {
          print $body[LANGUAGE_NONE][0]['value'];
        } ?>
      </div>
      <div class="list-badge feature clearfix">
        <?php print render($region['liv_city_badge']); ?>
      </div>
    </div>
    <div class="col-md-6 fi-block"><?php print render($region['liv_city_featured_img']); ?></div>
    <div class="col-md-3"><?php print render($region['liv_city_featured']); ?></div>
  </div>
  <?php } else { ?>
  <div class="row clearfix">
    <div class="col-md-6 madlib clearfix">
      <?php print render($region['share']); ?>
      <h2>What you need to know about <?php print $node->title.', '.$node->field_state[LANGUAGE_NONE][0]['entity']->field_state_code[LANGUAGE_NONE][0]['value']; ?></h2>
      <div class="body">
        <?php if(!empty($content['body'])) {
          print render($content['body']);
        } else {
          print $body[LANGUAGE_NONE][0]['value'];
        } ?>
      </div>
      <div class="list-badge clearfix">
        <?php print render($region['liv_city_badge']); ?>
      </div>

    </div>
    <div class="col-md-6 map clearfix">
      <div id="gmap-display">
        <iframe style="height:225px;width:100%;border:0;" frameborder="0" src="https://www.google.com/maps/embed/v1/place?q=<?php print $node->title; ?>,+<?php print $node->field_state[LANGUAGE_NONE][0]['entity']->title; ?>,+United+States&key=AIzaSyAN0om9mFmy1QN6Wf54tXAowK4eT0ZUPrU"></iframe>
      </div>
    </div>
  </div>
  <?php }; ?>
  <div class="row clearfix">
    <div class="col-md-3">
    <?php if (!empty($region['liv_city_1'])): ?>
      <div class="liv-city-col-1">
        <?php print render($region['liv_city_1']); ?>
      </div>
    <?php endif; ?>
    </div>
    <div class="col-md-3">
    <?php if (!empty($region['liv_city_2'])): ?>
      <div class="liv-city-col-2">
        <?php print render($region['liv_city_2']); ?>
      </div>
    <?php endif; ?>
    </div>
    <div class="col-md-3">
    <?php if (!empty($region['liv_city_3'])): ?>
      <div class="liv-city-col-3">
        <?php print render($region['liv_city_3']); ?>
      </div>
    <?php endif; ?>
    </div>
    <div class="col-md-3">
    <?php if (!empty($region['liv_city_4'])): ?>
      <div class="liv-city-col-4">
        <?php print render($region['liv_city_4']); ?>
      </div>
    <?php endif; ?>
    </div>
  </div>
  <div class="row clearfix">
  <?php if (!empty($region['liv_ad_lb_mid'])): ?>
    <div class="ads">
      <?php print render($region['liv_ad_lb_mid']); ?>
    </div>
  <?php endif; ?>
  </div>
  <div class="row clearfix">
    <div class="col-md-3">
    <?php if (!empty($region['liv_city_5'])): ?>
      <div class="liv-city-col-5">
        <?php print render($region['liv_city_5']); ?>
      </div>
    <?php endif; ?>
    </div>
    <div class="col-md-3">
    <?php if (!empty($region['liv_city_6'])): ?>
      <div class="liv-city-col-6">
        <?php print render($region['liv_city_6']); ?>
      </div>
    <?php endif; ?>
    </div>
    <div class="col-md-3">
    <?php if (!empty($region['liv_city_7'])): ?>
      <div class="liv-city-col-7">
        <?php print render($region['liv_city_7']); ?>
      </div>
    <?php endif; ?>
    </div>
    <div class="col-md-3">
    <?php if (!empty($region['liv_city_8'])): ?>
      <div class="liv-city-col-8">
        <?php print render($region['liv_city_8']); ?>
      </div>
    <?php endif; ?>
    </div>
  </div>
  <?php if (!empty($region['liv_city_lists'])): ?>
    <div class="col-md-12 clearfix">
      <div class="more-header">
        <h3><?php print $node->title; ?>, <?php print $node->field_state['und'][0]['entity']->field_state_code['und'][0]['value']; ?>'s Livability Rankings</h3>
      </div>
      <?php print render($region['liv_city_lists']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($region['liv_city_articles'])): ?>
    <div class="col-md-12 clearfix">
      <div class="more-header">
        <h3>More About <?php print $node->title; ?>, <?php print $node->field_state['und'][0]['entity']->field_state_code['und'][0]['value']; ?></h3>
      </div>
      <?php print render($region['liv_city_articles']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($region['liv_city_trulia'])): ?>
    <div class="col-md-12 clearfix">
      <?php print render($region['liv_city_trulia']); ?>
    </div>
  <?php endif; ?>
</article>