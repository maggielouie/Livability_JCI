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

                <?php if(isset($page['special_header'])){
                    print render($page['special_header']);
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
          <div class="<?php print $classes;?>">
              <div class="l-300-full">
                  <div class="shadow-inset-lr clearfix content main column-content">
                      <?php print render($title_suffix); ?>
                      <?php print $messages; ?>
                      <?php print render($page['content']) ?>
                  </div>
              </div>
              <?php
              if(isset($page['sidebar_second'])){
                    $class = 'with-left-nav';
              }else{
                      $class = '';
                  }
              if (isset($page['sidebar_first'])):
              ?>
                <div class="r-300 <?php print $class; ?> clearfix column-content">
                      <?php print render($page['sidebar_first']); ?>
                </div>
              <?php endif; ?>
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
