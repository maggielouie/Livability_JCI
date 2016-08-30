<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
  <div class="<?php print $container_class; ?>">
    <div class="col-md-2">
      <div class="navbar-header">
        <?php if (!empty($site_name)): ?>
          <a class="name navbar-brand hidden" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
        <?php endif; ?>
        <?php if ($logo): ?>
          <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>?ref=logo" title="<?php print t('Home'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        <?php endif; ?>
      </div>
    </div>

    <div class="col-md-8">
      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-main">
          <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
      <?php endif; ?>
      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <div class="navbar-collapse collapse" id="navbar-main">
          <nav role="navigation">
            <?php if (!empty($primary_nav)): ?>
              <?php print render($primary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($secondary_nav)): ?>
              <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])): ?>
              <?php print render($page['navigation']); ?>
            <?php endif; ?>
          </nav>
        </div>
      <?php endif; ?>
    </div>

    <div class="col-md-2 search">
      <?php if (!empty($page['search'])): ?>
        <div class="search">
          <?php print render($page['search']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>


</header>