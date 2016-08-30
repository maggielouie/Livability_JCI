<div class="container"<?php print $attributes; ?>>
<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>
  <!-- ______________________ MAIN _______________________ -->

  <div class="slide">
      <div class="clearfix content padded shadow-lrb page-header">
          <?php if ($breadcrumb || $title|| $messages || $tabs || $action_links): ?>
              <div id="content-header">

                  <?php print $breadcrumb; ?>

                  <?php if ($page['highlighted']): ?>
                      <div id="highlighted"><?php print render($page['highlighted']) ?></div>
                  <?php endif; ?>

              </div> <!-- /#content-header -->
          <?php endif; ?>
        </div>
    <section id="main" class="clearfix content main shadow-lr" role="main">

            <div class="shadow-inset-lr clearfix column-content">
                 <?php print $messages; ?>
                  <?php print render($page['help']); ?>

                  <?php if ($tabs): ?>
                      <div class="tabs"><?php print render($tabs); ?></div>
                  <?php endif; ?>

                  <?php if ($action_links): ?>
                      <ul class="action-links"><?php print render($action_links); ?></ul>
                  <?php endif; ?>

                <?php print render($page['content']) ?>

        </div>

    </section> <!-- /content-inner /content -->



  </div> <!-- /main -->

  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <footer id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>

</div> <!-- /page -->
