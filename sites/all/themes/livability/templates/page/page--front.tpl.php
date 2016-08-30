<?php $path = drupal_get_path_alias('node/'.$node->nid); ?>
<?php include path_to_theme().'/templates/system/page.header.inc'; ?>

<div id="page-front" class="main-container <?php print $container_class; ?>">
  <?php if (!empty($page['liv_ad_lb_top'])): ?>
    <div class="ads">
      <?php print render($page['liv_ad_lb_top']); ?>
    </div>
  <?php endif; ?>

  <section id="page-0" class="front <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div id="page-front-content row">
      <div class="col-sm-12"><?php print $messages; ?></div>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php if (!empty($page['liv_home_hero'] || $page['liv_home_search_city'] || $page['liv_home_search_state'])): ?>
        <div class="col-sm-12 clearfix" style="background: url('<?php print $hero_img ?>') no-repeat center center;-webkit-background-size: cover;-moz-background-size: cover;-o-background-size: cover;background-size: cover;padding: 15px 0px;margin-bottom: 15px;">
          <div class="col-sm-12"><?php print render($page['liv_home_hero']); ?></div>
          <div class="col-sm-6 col-sm-offset-3 place-search">
            <div class="col-sm-6"><?php print render($page['liv_home_search_city']); ?></div>
            <div class="col-sm-6"><?php print render($page['liv_home_search_state']); ?></div>
          </div>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['liv_home_featured'])): ?>
          <div class="trending col-sm-12 clearfix"><?php print render($page['liv_home_featured']); ?></div>
      <?php endif; ?>
      <?php if (!empty($page['liv_home_content'])): ?>
      <div class="col-sm-9">
        <?php print render($page['liv_home_content']); ?>
      </div>
      <?php endif; ?>
      <?php if (!empty($page['liv_home_sidebar'])): ?>
      <div class="col-sm-3">
        <?php print render($page['liv_home_sidebar']); ?>
      </div>
      <?php endif; ?>
      <?php if (!empty($page['liv_home_more'])): ?>
      <div class="col-sm-12">
        <?php print render($page['liv_home_more']); ?>
      </div>
      <?php endif; ?>
    </div>
  </section>

  <?php if (!empty($page['liv_ad_lb_bottom'])): ?>
    <div class="ads">
      <?php print render($page['liv_ad_lb_bottom']); ?>
    </div>
  <?php endif; ?>
</div>
<?php include path_to_theme().'/templates/system/page.footer.inc'; ?>
