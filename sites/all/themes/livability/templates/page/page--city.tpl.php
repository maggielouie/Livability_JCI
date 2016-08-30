<?php $path = drupal_get_path_alias('node/'.$node->nid); ?>
<?php include path_to_theme().'/templates/system/page.header.inc'; ?>

<div id="page-<?php print $node->type; ?>" class="main-container <?php print $container_class; ?>">

  <?php if (!empty($page['liv_ad_lb_top'])): ?>
  <div class="ads">
    <?php print render($page['liv_ad_lb_top']); ?>
  </div>
  <?php endif; ?>
    
  <section id="page-<?php print $node->nid; ?>" class="<?php print $node->type; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="col-md-12 city-menu">
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <div class="col-md-5">
        <?php print render($title_prefix); ?>
        <?php if (!empty($title)): ?>
          <span class="livicon"></span>
          <h1 class="page-title white"><?php print $title; ?>, <a class="white" href="/<?php print $node->field_state['und'][0]['entity']->field_state_code['und'][0]['value']; ?>"><?php print $node->field_state['und'][0]['entity']->field_state_code['und'][0]['value']; ?></a></h1>
          <span class="county-name"><a href="/<?php print $countyPath; ?>" class="white" ><?php print $node->field_county['und'][0]['entity']->title; ?></a></span>
        <?php endif; ?>
        <?php print render($title_suffix); ?>

      </div>
      <div class="col-md-7 citynav">
        <?php if (!empty($page['liv_city_nav'])){ ?>
        <?php print render($page['liv_city_nav']); ?>
        <?php } else { ?>
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#citynavbar">
            <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <div class="navbar-collapse collapse" id="citynavbar">
            <ul class="menu nav">
            <?php if (!empty($page['liv_city_1']['views_city-block_4'])){ ?>
              <li class="last leaf"><a href="/<?php print $path; ?>/digital-magazine" title="">Magazine</a></li>
            <?php } ?>
              <li class="leaf"><a href="/<?php print $path; ?>/health" title="">Health</a></li>
              <li class="leaf"><a href="/<?php print $path; ?>/business" title="">Business</a></li>
              <li class="leaf"><a href="/<?php print $path; ?>/real-estate" title="">Real Estate</a></li>
              <li class="leaf"><a href="/<?php print $path; ?>/schools" title="">Schools</a></li>
              <?php if (!empty($page['liv_city_1']['views_city-block_5'])){ ?>
              <li class="leaf first"><a href="/<?php print $path; ?>/things-to-do" title="" >Things To Do</a></li>
              <?php } ?>
            </ul>
          </div>
        <?php } ?>
      </div>
    </div>
    <div id="page-<?php print $node->type; ?>-content" class="col-md-12">
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
