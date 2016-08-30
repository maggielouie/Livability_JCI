<?php include path_to_theme().'/templates/system/page.header.inc'; ?>

<div id="page-<?php print $node->type; ?>" class="main-container <?php print $container_class; ?>">
  <?php if (!empty($page['liv_ad_lb_top'])): ?>
  <div class="container ads">
    <?php print render($page['liv_ad_lb_top']); ?>
  </div>
  <?php endif; ?>
    
  <section id="page-<?php print $node->nid; ?>" class="container <?php print $node->type; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="row page-header" <?php if (!empty($node->field_banner_image)): ?>style="background:url('<?php print render($banner_image);  ?>');background-size: cover; height: 453px;"<?php endif; ?>>
      <div class="<?php if (!empty($node->field_banner_image)) { print 'header-shadow'; } else { print 'header-none'; }; ?>">
        <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
        <?php print render($title_prefix); ?>
        <?php if (!empty($title)): ?>
          <h1 class="page-title"><i class="fa fa-graduation-cap green"></i> <?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if (!empty($page['share'])): ?>
          <div><?php print render($page['share']); ?></div>
        <?php endif; ?>
      </div>
    </div>
    <div class="row">
      <div id="page-<?php print $node->type; ?>-content" class="col-md-9">
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
      <aside class="col-md-3">
        <?php if (!empty($page['liv_ad_mr_top'])): ?>
        <div class="ads">
          <?php print render($page['liv_ad_mr_top']); ?>
        </div>
        <?php endif; ?>
        <?php if (!empty($page['sidebar_1'])): ?>
          <?php print render($page['sidebar_1']); ?>
        <?php endif; ?>
        <?php if (!empty($page['liv_ad_mr_mid'])): ?>
        <div class="ads">
          <?php print render($page['liv_ad_mr_mid']); ?>
        </div>
        <?php endif; ?>
        <?php if (!empty($page['sidebar_2'])): ?>
          <?php print render($page['sidebar_2']); ?>
        <?php endif; ?>
        <?php if (!empty($page['liv_ad_mr_bottom'])): ?>
        <div class="ads">
          <?php print render($page['liv_ad_mr_bottom']); ?>
        </div>
        <?php endif; ?>
      </aside>
    </div>
  </section> 

</div>

<?php include path_to_theme().'/templates/system/page.footer.inc'; ?>
