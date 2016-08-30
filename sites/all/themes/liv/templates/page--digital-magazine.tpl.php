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

                  <?php if (isset($cityname)) { ?>
                    <span class="city-pin">
                      <a href="<?php print $cityurl; ?>">
                      <i class="icon-pin green no-mobile"></i>
                      <h2><?php print $cityname; ?>, <strong><?php print $state; ?></strong></h2>
                      </a>
                      <span class="county-area no-mobile"><?php if ($countyname) echo $countyname;?><?php if ($countyname && $metroname) echo ', ' ;?><?php if ($metroname) echo $metroname .' Metro Area'; ?></span>
                    </span>
                  <?php } ?>
                  <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
              </div> <!-- /#content-header -->
          <?php endif; ?>
        </div>
    <section id="main" class="clearfix content main shadow-lr" role="main">
      <div class="l-300-full">
          <?php if ($page['sidebar_second']): ?>
              <?php print render($page['sidebar_second']); ?>
          <?php endif; ?>
        <div class="left-nav-full">

        <div id="content-area">

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

        </div>
      </div>

    <?php if ($page['sidebar_first']): ?>
      <div class="r-300 clearfix column-content">
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
