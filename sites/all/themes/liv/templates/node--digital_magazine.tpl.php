<?php /*<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix padded"<?php print $attributes; ?>>

  <?php print $user_picture ?>

  <?php if ($page == 0): ?>
    <h2><?php print $title ?></h2>
  <?php else : ?>
    <h2 class="green"><?php if(isset($variables['cityname']) && isset($variables['state'])) { print $variables['cityname'] .', '.$variables['state'];?> Community Magazine<?php }
    else print $title; ?></h2>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <div class='dm-content'>
      <?php if (isset($content['field_image']) && !is_null($content['field_image'][0]['#item'])) {
        echo '<span class="sponsor">Presented by<br/>';
        print render($content['field_image']);
        echo '</span>';
      } ?>
      <?php print render($content['field_description']); ?>
    </div>
  <?php // endif; ?>

    <div class="magazine">
      <?php // This field is being deprecated.
            // print render($content['field_calamaeo_id']);
      ?>
      <?php if (!empty($content['field_mag_pdf_link'])): ?>
        <div class="magazine-pdf-link-1">
          <a href="<?php print $content['field_mag_pdf_link']['#path']; ?>" class="mag-download-link" target="_blank">Read Magazine</a>
        </div>
      <?php endif; ?>
      <?php if (!empty($content['field_mag_cover'])): ?>
        <div class="magazine-preview-image">
          <a href="<?php print $content['field_mag_pdf_link']['#path']; ?>" class="mag-download-link" target="_blank">
          <?php print render($content['field_mag_cover']); ?>
          </a>
        </div>
      <?php endif; ?>
      <?php if (!empty($content['field_mag_pdf_link'])): ?>
        <div class="magazine-pdf-link">
          <span class="magazine-pdf-link-icon"></span>
          <?php print render($content['field_mag_pdf_link']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>

  <div class="meta clearfix">
    <?php print render($content['links']); ?>
    <?php /* print render($content['field_tags']);  ?>
  </div>

</article>
*/ ?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix padded"<?php print $attributes; ?>>

  <?php print $user_picture ?>

  <?php if ($page == 0): ?>
    <h2><?php print $title ?></h2>
  <?php else : ?>
    <h2 class="green"><?php if(isset($variables['cityname']) && isset($variables['state'])) { print $variables['cityname'] .', '.$variables['state'];?> Community Magazine<?php }
    else print $title; ?></h2>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <div class='dm-content'>
      <?php if (isset($content['field_image']) && !is_null($content['field_image'][0]['#item'])) {
        echo '<span class="sponsor">Presented by<br/>';
        print render($content['field_image']);
        echo '</span>';
      } ?>
      <?php print render($content['field_description']); ?>
    </div>
  <?php // endif; ?>

    <div class="magazine">
      <?php print render($content['field_calamaeo_id']); ?>
    </div>
  </div>

  <div class="meta clearfix">
    <?php print render($content['links']); ?>
    <?php /* print render($content['field_tags']); */ ?>
  </div>

</article>
