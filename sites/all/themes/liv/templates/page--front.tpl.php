<div class="container"<?php print $attributes; ?>>
<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>
  <div class="slide">
      <section id="main" class="clearfix content main shadow-lr" role="main">
      	<div class="home">
          <div class="l-300-full">
            <div class="shadow-inset-lr clearfix column-content">

				<?php print $messages; ?>
                <?php print render($page['content']) ?>

              </div>
          </div>
          <?php if ($page['sidebar_first']): ?>
              <div class="r-300 clearfix column-content">
                  <?php print render($page['sidebar_first']); ?>
              </div>
          <?php endif; ?>

      </section> <!-- /content-inner /content -->


  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <footer id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>

</div> <!-- /page -->
</div>