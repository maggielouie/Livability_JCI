<?php if (!empty($page['footer'] || $page['footer_about'] || $page['footer_menu'] || $page['footer_links'])): ?>
  <footer class="footer <?php print $container_class; ?>">
    <div class="col-sm-7">
      <?php print render($page['footer_about']); ?>
    </div>
    <div class="col-sm-5">
      <?php print render($page['footer_menu']); ?>
    </div>
    <div class="col-sm-12">
      <?php print render($page['footer_links']); ?>
      <?php print render($page['footer']); ?>
    </div>
  </footer>
<?php endif; ?>
<?php if( extension_loaded('newrelic') ) { echo newrelic_get_browser_timing_footer(); } ?>