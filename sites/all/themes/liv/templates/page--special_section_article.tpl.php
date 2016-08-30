<?php 
  $parent_nid = _special_section_parent_node($node->nid);
  $current_delta = _special_section_current_delta($node->nid, $parent_nid);
  $previous_nid = $current_delta > 0 ? _special_section_nid_delta($parent_nid, $current_delta - 1) : FALSE;
  $next_nid = _special_section_nid_delta($parent_nid, $current_delta + 1);
  $parent_node = node_load($parent_nid);
  // dsm($parent_node);
  // $styles = image_styles();
  // dsm($styles);
  $fid = $parent_node->field_sponsor_logo['und'][0]['fid'];
  $file = file_load($fid);
  $image = image_load($file->uri);
  $promoter_logo = array(
    'file' => array(
      '#theme' => 'image_style',
      '#style_name' => 'sponsor_logo',
      '#path' => $image->source,
      '#width' => $image->info['width'],
      '#height' => $image->info['height'],
    ),
  );
  $rendered_logo = l(drupal_render($promoter_logo), $parent_node->field_sponsor_link['und'][0]['value'], 
    array('html' => TRUE, 'attributes' => array('target' => '_blank')));
  ?>
<div class="container"<?php print $attributes; ?>>
<?php include(drupal_get_path('theme', 'liv').'/partials/header.php'); ?>

  <div class="slide">
    <div class="clearfix content padded page-header">
      <?php print $breadcrumb; ?>
      <div class="view-special-section">
        <div class="ss-col ss-header">
          <?php print $rendered_logo; ?>
          <div class="ss-social-media">
            <a href="https://www.facebook.com/SouthernIdaho/" target="_blank"><i class="icon-facebook-square"></i></a>
            <a href="https://twitter.com/visitsouthidaho" target="_blank"><i class="icon-twitter-square"></i></a>
          </div>
        </div>
      </div>
    </div>

      <section id="main" class="clearfix content main" role="main">
        <div class="l-300-full">
          <div class="clearfix">
          <?php print $messages; ?>
          <?php $params = array($node->nid);
          print views_embed_view('special_section', 'block_2', $params); ?>

          <?php if (module_exists('special_section')) : ?>
            <div class="ss-pager">
              <?php
              $output_previous = '<li><span class="previous">' . l(html_entity_decode('&laquo;&nbsp;') . 'Previous Article', 'node/' . $previous_nid) . '</span></li>';
              $output_parent = '<li><span class="back">' . l('Back to Home', 'node/' . $parent_nid) . '</span></li>';
              $output_next = '<li><span class="next">' . l('Next Article' . html_entity_decode('&nbsp;&raquo;'), 'node/' . $next_nid) . '</span></li>';
              ?>
              <ul>
                <?php 
                $previous_nid ? print $output_previous : print '<li>&laquo;&nbsp;Previous Article</li>';
                $parent_nid ? print $output_parent : print '<li>Back to Home</li>';
                $next_nid ? print $output_next : print '<li>Next Article&nbsp;&raquo;</li>';
                ?>
              </ul>

            </div>
          <?php endif; ?>

          </div>
        </div>
          
        <div class="r-300 clearfix column-content">
          <div class="ss-column-wrapper">
            <h2 class="ss-related-stories">RELATED STORIES</h2>
            <?php print views_embed_view('special_section', 'block_3', $params); ?>
          </div>
        </div>
          
      </section> <!-- /content-inner /content -->

      <section class="ss-logos clearfix">
        
        <table class="ss-logos-b">
          <tr style="height:100px">
            <td  style="vertical-align:middle"><?php print $rendered_logo; ?></td>
            <td  style="vertical-align:middle"><a href="http://www.jnlcom.com/" target="_blank"><img src="/<?php print drupal_get_path('theme', 'liv') . '/livability/images/jnl_logo_200x43_2014_center_trans.png'; ?>" /></a></td>
          </tr>
        </table>
      </section>


  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <footer id="footer">
      <?php print render($page['footer']); ?>
    </footer> <!-- /footer -->
  <?php endif; ?>

</div> <!-- /page -->
</div>