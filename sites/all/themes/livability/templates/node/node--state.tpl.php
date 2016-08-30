<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!empty($region['liv_state_featured_img'])) { ?>
    <div class="row clearfix">
      <div class="col-sm-3 madlib clearfix">
        <?php print render($region['share']); ?>
        <h2>What you need to know about <?php print $node->title; ?></h2>
        <div class="body">
          <?php if(!empty($content['body'])) {
            print render($content['body']);
          } else {
            print $body[LANGUAGE_NONE][0]['value'];
          } ?>
        </div>
      </div>
      <div class="col-sm-6 fi-block"><?php print render($region['liv_state_featured_img']); ?></div>
      <div class="col-sm-3"><?php print render($region['liv_state_featured']); ?></div>
    </div>
  <?php } else { ?>
    <div class="row clearfix">
      <div class="col-sm-6 madlib clearfix">
        <?php print render($region['share']); ?>
        <h2>What you need to know about <?php print $node->title; ?></h2>
        <div class="body">
          <?php if(!empty($content['body'])) {
            print render($content['body']);
          } else {
            print $body[LANGUAGE_NONE][0]['value'];
          } ?>
        </div>

      </div>
      <div class="col-sm-6 map clearfix">
        <div id="gmap-display">
          <iframe style="height:225px;width:100%;border:0;" frameborder="0" src="https://www.google.com/maps/embed/v1/place?q=<?php print $node->title; ?>,+United+States&key=AIzaSyAN0om9mFmy1QN6Wf54tXAowK4eT0ZUPrU"></iframe>
        </div>
      </div>
    </div>
  <?php }; ?>
  <div class="row clearfix">
    <div class="col-sm-3">
      <?php if (!empty($region['liv_state_1'])): ?>
        <div class="liv-state-col-1">
          <?php print render($region['liv_state_1']); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-sm-3">
      <?php if (!empty($region['liv_state_2'])): ?>
        <div class="liv-state-col-2">
          <?php print render($region['liv_state_2']); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-sm-3">
      <?php if (!empty($region['liv_state_3'])): ?>
        <div class="liv-state-col-3">
          <?php print render($region['liv_state_3']); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-sm-3">
      <?php if (!empty($region['liv_state_4'])): ?>
        <div class="liv-state-col-4">
          <?php print render($region['liv_state_4']); ?>
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
    <div class="col-sm-3">
      <?php if (!empty($region['liv_state_5'])): ?>
        <div class="liv-state-col-5">
          <?php print render($region['liv_state_5']); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-sm-3">
      <?php if (!empty($region['liv_state_6'])): ?>
        <div class="liv-state-col-6">
          <?php print render($region['liv_state_6']); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-sm-3">
      <?php if (!empty($region['liv_state_7'])): ?>
        <div class="liv-state-col-7">
          <?php print render($region['liv_state_7']); ?>
        </div>
      <?php endif; ?>
    </div>
    <div class="col-sm-3">
      <?php if (!empty($region['liv_state_8'])): ?>
        <div class="liv-state-col-8">
          <?php print render($region['liv_state_8']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
  <?php if (!empty($region['liv_ad_lb_middle'])): ?>
    <div class="col-sm-12 clearfix">
      <div class="ads">
        <?php print render($region['liv_ad_lb_middle']); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (!empty($region['liv_state_lists_100'])): ?>
    <div class="col-sm-12 clearfix">
      <div class="more-header">
        <h3><?php print $node->title; ?> Top 100 City Rankings</h3>
      </div>
      <?php print render($region['liv_state_lists_100']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($region['liv_state_lists_10'])): ?>
    <div class="col-sm-12 clearfix">
      <div class="more-header">
        <h3><?php print $node->title; ?> Top 10 City Rankings</h3>
      </div>
      <?php print render($region['liv_state_lists_10']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($region['liv_state_articles'])): ?>
    <div class="col-sm-12 clearfix">
      <div class="more-header">
        <h3>More About <?php print $node->title; ?> Cities</h3>
      </div>
      <?php print render($region['liv_state_articles']); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($region['liv_state_trulia'])): ?>
    <div class="col-sm-12 clearfix">
      <?php print render($region['liv_state_trulia']); ?>
    </div>
  <?php endif; ?>
</article>