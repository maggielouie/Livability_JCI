<div class="container"<?php print $attributes; ?>>
<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>
  <!-- ______________________ MAIN _______________________ -->
  <?php if (arg(0) != 'node' && null === arg(3)) : ?>
  <div class="clearfix content padded shadow-lrb page-header">
      <div id="content-header">
        <?php print $breadcrumb; ?>
        <?php if ($page['highlighted']): ?>
          <div id="highlighted"><?php print render($page['highlighted']) ?></div>
        <?php endif; ?>

        <?php if(array_key_exists('special_header',$page)){
          print $page['special_header'];
        }
        else {  ?>
			<span class="best-pin">
				<span class="seal-orange">
					<i class="icon-top10 white"></i>
				</span>
				<h1><?php print ucwords($title); ?></h1>
        <span class="county-area no-mobile">
          Our annual rankings of the best small to mid-sized cities in the U.S.
        </span>
			</span>
        <?php } ?>
        <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>

        <?php print render($page['help']); ?>

       </div> <!-- /#content-header -->
  </div>
  <?php endif; ?>
  <div class="slide">
    <section id="main" class="clearfix content main shadow-lr" role="main">

      <div class="l-300-full">
        <div class="shadow-inset-lr clearfix column-content">

          <?php if ($tabs): ?>
            <div class="tabs"><?php print render($tabs); ?></div>
          <?php endif; ?>
          <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>
          <?php print $messages; ?>
          <?php print render($page['help']); ?>

          <?php print render($page['content_top_ad']); ?>
          
          <?php print render($page['content']); ?>

          <?php include(drupal_get_path('theme', 'liv').'/partials/comments.php'); ?>
        </div>
          <?php if ($page['sidebar_first']): ?>
              <div class="r-300 column-content">
                  <?php print render($page['sidebar_first']); ?>
              </div>
          <?php endif; ?>
      </div>

    </section>

  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <footer class="clearfix shadow-top" id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>

</div> <!-- /page -->
