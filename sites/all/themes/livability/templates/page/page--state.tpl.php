<?php $path = drupal_get_path_alias('node/'.$node->nid); ?>
<?php include path_to_theme().'/templates/system/page.header.inc'; ?>

<div id="page-<?php print $node->type; ?>" class="main-container <?php print $container_class; ?>">

  <?php if (!empty($page['liv_ad_lb_top'])): ?>
    <div class="ads">
      <?php print render($page['liv_ad_lb_top']); ?>
    </div>
  <?php endif; ?>

  <section id="page-<?php print $node->nid; ?>" class="<?php print $node->type; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="col-sm-12 state-menu">
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <div class="col-sm-8">
        <?php print render($title_prefix); ?>
        <?php if (!empty($title)): ?>
          <span class="livicon"></span>
          <h1 class="page-title white">Best Places to Live in <?php print $title; ?></h1>
          <span class="county-name white">Find your perfect city, here.</span>
        <?php endif; ?>
        <?php print render($title_suffix); ?>

      </div>
      <div class="col-sm-4 statenav">
        <?php if (!empty($page['liv_state_nav'])){ ?>
          <?php print render($page['liv_state_nav']); ?>
        <?php } else { ?>
        <?php } ?>
      </div>
    </div>
    <div id="page-<?php print $node->type; ?>-content" class="col-sm-12">
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </div>
  </section>

  <?php if (!empty($page['liv_ad_lb_bottom'])): ?>
    <div class="ads">
      <?php print render($page['liv_ad_lb_bottom']); ?>
    </div>
  <?php endif; ?>
</div>

<?php include path_to_theme().'/templates/system/page.footer.inc'; ?>
