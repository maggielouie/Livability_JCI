<div class="container"<?php print $attributes; ?>>

<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>

  <div class="slide">
      <section id="main" class="clearfix content main shadow-lr" role="main">
          <div class="about-us">
              <?php print $messages; ?>
              <?php print render($page['content']) ?>
          </div>
      </section> 
  </div> 

  <?php if ($page['footer']): ?>
    <footer id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>

</div> 
