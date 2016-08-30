<div class="container"<?php print $attributes; ?>>
<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>
  <!-- ______________________ MAIN _______________________ -->

  <div class="slide">
    <div class="clearfix content padded shadow-lrb page-header">
      <?php print $breadcrumb; ?>
      <?php if (isset($cityname)) { ?>
        <span class="city-pin">
          <a href="<?php print $cityurl; ?>">
            <i class="icon-pin green no-mobile"></i>
            <h2><?php print $cityname; ?>, <strong class="green"><?php print $state; ?></strong></h2>
          </a>
          <span class="county-area no-mobile">
          <?php if ($countyname) {
            echo "<a href=" . $countyurl . ">" . $countyname . "</a>";
          }
            if ($countyname && $metroname) echo ', ' ;?><?php if ($metroname) echo $metroname .' Metro Area'; ?></span>

        </span>
      <?php }
     elseif (isset($globcat)) { ?>
        <span class="blog-pin">
          <a href="#">
           <i class="icon-<?php echo $globcaticon; ?> green no-mobile"></i>
            <h1><?php print $globcat; ?></h1>
          </a>
        </span>
      <?php } ?>
      <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
    </div>
    <section id="main" class="clearfix content main shadow-lr" role="main">
        <div class="l-300-full">
        <?php if ($page['sidebar_second']): ?>

          <?php print render($page['sidebar_second']); ?>
        <?php endif; ?> <!-- /sidebar-first -->
        
        <div class="left-nav-full">
          <div class="shadow-inset-lr clearfix column-content">
            <article>
              <?php print $messages; ?>

                <?php if ($page['highlighted']): ?>
                  <div id="highlighted"><?php print render($page['highlighted']) ?></div>
                <?php endif; ?>

                <?php if ($tabs): ?>
                  <div class="tabs"><?php print render($tabs); ?></div>
                <?php endif; ?>

                <?php if ($action_links): ?>
                  <ul class="action-links"><?php print render($action_links); ?></ul>
                <?php endif; ?>
                <?php print render($title_prefix); ?>

                <?php /* if ($title): ?>
                  <h1 class="title"><?php print $title; ?></h1>
                <?php endif; ?>

                <?php print render($title_suffix); */ ?>

                <?php print render($page['help']); ?>

              </span>

            <?php print render($page['content']) ?>
            <?php include(drupal_get_path('theme', 'liv').'/partials/comments.php'); ?>
            </article>
          </div>
        </div>
            <?php if ($page['sidebar_first']): ?>
                <div class="r-300 with-left-nav column-content">
                    <?php print render($page['sidebar_first']); ?>
                </div>
            <?php endif; ?> <!-- /sidebar-first -->
      </div>




    </section> <!-- /content-inner /content -->


  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <footer class="clearfix shadow-top" id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>
  </div> <!-- /main -->

</div> <!-- /page -->
