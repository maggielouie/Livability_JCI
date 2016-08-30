<div class="container"<?php print $attributes; ?>>

  <div class="slide">
      <section id="main" class="clearfix content main shadow-lr" role="main">
              <div class="clearfix column-content">
                  <?php print render($title_suffix); ?>
                      <?php print $messages; ?>
                      <div class="content">
<p><a href="/" target="_blank"><img alt="Livability Logo" src="/sites/all/themes/liv/images/logos/livability_logo_large.jpg"></a></p>
<p><strong>404.</strong>&nbsp;<span>That’s an error.</span></p>
<p>The requested URL&nbsp;<code><?php print $_SERVER['REQUEST_URI']; ?></code>&nbsp;was not found on this server.&nbsp;<span>That’s all we know.</span></p>
						</div>
              </div>

      </section> <!-- /content-inner /content -->
  </div> <!-- /main -->

</div> <!-- /page -->
