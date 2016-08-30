<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
  <div class="container">
    <div class="col-md-2">
      <div class="navbar-header">
        <?php if (!empty($site_name)): ?>
        <a class="name navbar-brand hidden" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
        <?php endif; ?>
        
        <?php if ($logo): ?>
        <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
        <?php endif; ?>
        
      </div>
    </div>
    
    <div class="col-md-6">
      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse">
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
    
    <div class="col-md-3">
      <?php if (!empty($page['social'])): ?>
        <div class="social col-md-10">
          <?php print render($page['social']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['search'])): ?>
        <div class="search col-md-2">
          <?php print render($page['search']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</header>

<div class="main-container container">
  
<div class="container"<?php print $attributes; ?>>

  <div class="slide">
      <section id="main" class="clearfix content main shadow-lr" role="main">
              <div class="clearfix column-content">
                  <?php print render($title_suffix); ?>
                      <?php print $messages; ?>
                      <div class="content">
<p><a href="/" target="_blank"><img alt="Livability Logo" src="<?php print path_to_theme() ?>/images/livability_logo_large.jpg"></a></p>
<p><strong>404.</strong>&nbsp;<span>That’s an error.</span></p>
<p>The requested URL&nbsp;<code><?php print $_SERVER['REQUEST_URI']; ?></code>&nbsp;was not found on this server.&nbsp;<span>That’s all we know.</span></p>
						</div>
              </div>

      </section> <!-- /content-inner /content -->
  </div> <!-- /main -->

</div> <!-- /page -->
