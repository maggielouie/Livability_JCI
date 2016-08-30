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

                    <?php print '<h1 class="title"><?php print $title; ?></h1>'; ?>
                  <?php // include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>

                  <?php print render($page['help']); ?>

              </div> <!-- /#content-header -->
          <?php endif; ?>
        </div>
    <section id="main" class="clearfix content main shadow-lr" role="main">
 <!-- /sidebar-second -->

        <div class="l-300-full">

        <div class="">
            <div style="" class="shadow-inset-lr clearfix column-content padded">
                <?php print render($title_suffix); ?>
                <?php print $messages; ?>
                <?php print render($page['content']) ?>
            </div>
        </div>
        </div>


        <?php if ($page['sidebar_first']): ?>
            <div class="r-300 with-left-nav column-content">
                <?php print render($page['sidebar_first']); ?>
            </div>
        <?php endif; ?> <!-- /sidebar-first -->

    </section> <!-- /content-inner /content -->



  </div> <!-- /main -->

  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <footer id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>

</div> <!-- /page -->
