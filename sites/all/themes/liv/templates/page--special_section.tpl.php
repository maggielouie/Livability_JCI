<div class="container"<?php print $attributes; ?>>
<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>

  <div class="slide">
    <div class="clearfix content padded shadow-lrb page-header">
      <?php print $breadcrumb; ?>
    </div>
      <section id="main" class="clearfix content main shadow-lr" role="main">
        <?php print $messages; ?>
        <?php $params = array($node->nid);
        print views_embed_view('special_section', 'block', $params); ?>
      </section> <!-- /content-inner /content -->


  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <footer id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>

</div> <!-- /page -->
</div>