<?php
//$categoryField = field_get_items('node',$node,'field_blog_category');
//$category = $categoryField[0]['taxonomy_term']->name;
?>
<div class="container"<?php print $attributes; ?>>
<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>
  <!-- ______________________ MAIN _______________________ -->

  <div class="slide">


      <div class="clearfix content padded shadow-lrb page-header">
          <?php print $breadcrumb; ?>
          <?php if(array_key_exists('special_header',$page)){
              print render($page['special_header']);
          }else{
              print '<h1 class="title">'. $title .'</h1>';
          }
          ?>
<?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
      </div>

    <section id="main" class="clearfix content main shadow-lr" role="main">
        <div class="l-300-full">
            <?php if ($page['sidebar_second']): ?>
                <?php print render($page['sidebar_second']); ?>
            <?php endif; ?>

        
        <div class="left-nav-full">
          <div class="shadow-inset-lr clearfix column-content">
            <span class="no-mobile">
              <?php $topad = block_load('jci_dfp', 'jci-dfp-block-1');
              $output = _block_get_renderable_array(_block_render_blocks(array($topad)));
              print drupal_render($output); ?>
            </span>
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



            <?php print render($page['content']) ?>
            <?php include(drupal_get_path('theme', 'liv').'/partials/comments.php'); ?>
            </article>
          </div>
        </div>
            <?php if ($page['sidebar_first']): ?>
                <div class="r-300 with-left-nav column-content">
                    <?php print render($page['sidebar_first']); ?>
                </div>
            <?php endif; ?>
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
