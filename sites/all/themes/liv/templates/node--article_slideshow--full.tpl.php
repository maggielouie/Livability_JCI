<article>
  <span class="padded clearfix">

    <?php
      // We hide the comments to render below.
      hide($content['comments']);
      hide($content['links']);
    ?>

   
    <?php print render($title_prefix); ?>

    <?php if ($title): ?>
      <h1 class="title"><?php print $title; ?></h1>
    <?php endif; ?>

    <?php print render($title_suffix); ?>
    <?php if (isset($content['field_bp_category'])) {
      print render($content['field_bp_category']);
    } ?>
    <span class="synopsis clearfix">
      <?php if (isset($content['field_deck'])) : ?>
        <p><?php print $content['field_deck'][0]['#markup']; ?></p>
      <?php endif; ?>
    </span>

    <span class="top-10-nav clearfix">
      <?php include(drupal_get_path('theme', 'liv').'/partials/social.php'); ?>
      <?php print article_slideshow_number($node); ?>
      <span class="right">
        <?php print article_slideshow_pager($node); ?>
      </span>
    </span>
  </span>



  <span class="padded">
   <?php print article_slideshow_content($content, $node); ?>

    <span class="top-10-nav clearfix">
      <span class="right">
        <?php print article_slideshow_pager($node); ?>
      </span>
    </span>

    <?php if (!empty($content['links'])): ?>
      <div class="links">
        <?php print render($content['links']); ?>
      </div> <!-- /links -->
    <?php endif; ?>
  </span>
</article>