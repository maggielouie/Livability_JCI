<div class="container"<?php print $attributes; ?>>

<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>
  <!-- ______________________ MAIN _______________________ -->
    <div class="clearfix content padded shadow-lrb page-header">
        <?php if ($breadcrumb || $title|| $messages || $tabs || $action_links): ?>
            <div id="content-header">

                <?php print $breadcrumb; ?>

                <?php if ($page['highlighted']): ?>
                    <div id="highlighted"><?php print render($page['highlighted']) ?></div>
                <?php endif; ?>

                <?php if(array_key_exists('special_header',$page)){
                    print $page['special_header'];
                }else{
                    print '<h1 class="title">'. $title .'</h1>';
                }
                ?>
                <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>

                <?php print render($page['help']); ?>

            </div> <!-- /#content-header -->
        <?php endif; ?>
    </div>

  <div class="slide">
      <section id="main" class="clearfix content main shadow-lr" role="main">
          <div class="full">
                  <div class="shadow-inset-lr clearfix column-content">
                      <?php print render($title_suffix); ?>
                      <?php print $messages; ?>
                      <?php print render($page['content']) ?>
                  </div>
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
