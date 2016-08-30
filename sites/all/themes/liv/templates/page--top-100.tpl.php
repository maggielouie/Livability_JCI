<div class="container"<?php print $attributes; ?>>
<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>
  <!-- ______________________ MAIN _______________________ -->

  <div class="slide">

    <section id="main" class="clearfix content main shadow-lr" role="main">
 
      <div class="l-300-full">
         <div class="shadow-inset-lr clearfix column-content">

          <?php if ($breadcrumb) print $breadcrumb; ?>

          <?php if ($page['highlighted']): ?>
            <div id="highlighted"><?php print render($page['highlighted']) ?></div>
          <?php endif; ?>

          <?php if ($tabs): ?>
            <div class="tabs"><?php print render($tabs); ?></div>
          <?php endif; ?>

          <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>

          <?php print $messages; ?>
          <?php print render($page['help']); ?>

          <article>
            <span class="padded clearfix">
              <?php if (isset($node->field_year['und'])) {
                echo '<span class="year">'. date('Y', strtotime($node->field_year['und'][0]['value'])) .'</span>';
              } ?>
              <?php print render($title_prefix); ?>
                <h1>Top 100 Best Places to Live</h1>
                <div class="top-100-sponsored-by"><span class="sponsored-by-txt">Sponsored by:</span>
                  <?php $topad = block_load('jci_dfp', 'jci-dfp-block-28');
                        $output = _block_get_renderable_array(_block_render_blocks(array($topad)));
                        print drupal_render($output);
                        ?>
                </div>

              <?php print render($title_suffix); ?>
              <span class="top-10-nav clearfix">
                <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
              </span>
            </span>

            <span class="padded top-100">
              <?php print render($page['content']) ?>
              <?php $bottomad = block_load('combo_ad_blocks', 'leaderboard_bottom');
              $bottomad_output = _block_get_renderable_array(_block_render_blocks(array($bottomad)));
              print drupal_render($bottomad_output); ?>
              <?php include(drupal_get_path('theme', 'liv').'/partials/comments.php'); ?>
            </span>
          </article>
        </div>
      </div>
      
      <?php if ($page['sidebar_first']): ?>
        <div class="r-300 column-content">
          <?php print render($page['sidebar_first']); ?>
        </div>
      <?php endif; ?> <!-- /sidebar-second -->

    </section> <!-- /content-inner /content -->

    <!-- ______________________ FOOTER _______________________ -->

    <?php if ($page['footer']): ?>
      <footer class="clearfix shadow-top" id="footer">
        <?php print render($page['footer']); ?>
      </footer> <!-- /footer -->
    <?php endif; ?>
  </div>
</div> <!-- /page -->
