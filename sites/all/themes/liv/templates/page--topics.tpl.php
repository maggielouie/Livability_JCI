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
                }
                else {
                	if ($title == 'Topics') { ?>
						<span class="topic-pin no-pin">
							<h1><?php print ucwords($title); ?></h1>
						</span>
                	<?php }
                	else { ?>
						<span class="topic-pin">
							<span class="sticker-orange-horizontal">
							<i class="icon-<?php print arg(1) ? livability_article_get_icon($title) : 'flag';?> white"></i>
							</span>
							<h1><?php print ucwords($title); ?></h1>
              <span class="county-area no-mobile">
                  <?php print $deck_copy ?>
              </span>
						</span>
                    <?php }
                }
                ?>
                <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>

                <?php print render($page['help']); ?>

            </div> <!-- /#content-header -->
        <?php endif; ?>
    </div>

    <div class="slide">
      <section id="main" class="clearfix content main shadow-lr" role="main">
          <?php if ($page['sidebar_second']): ?>
              <div class="l-300-full">
                  <?php print render($page['sidebar_second']); ?>
                  <div class="left-nav-full">
                      <div class="shadow-inset-lr clearfix column-content">
                          <?php print render($title_suffix); ?>
                          <?php print $messages; ?>
                          <?php print render($page['content']) ?>
                      </div>
                  </div>
            </div>
          <?php else: ?>
              <div class="l-300-full">
                  <div class="shadow-inset-lr clearfix column-content">
                      <?php print render($title_suffix); ?>
                      <?php print $messages; ?>
                      <?php print render($page['content']) ?>
                 </div>
              </div>
          <?php endif; ?>
          <?php if ($page['sidebar_first']): ?>
              <div class="r-300 with-left-nav column-content">
                  <?php print render($page['sidebar_first']); ?>
              </div>
          <?php endif; ?>
      </section> <!-- /content-inner /content -->
    </div>

  <!-- /main -->

  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <footer id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>

</div> <!-- /page -->
