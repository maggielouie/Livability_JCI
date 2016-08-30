<?php $bannerimage = null;
if (isset($node) && is_object($node) && in_array($node->type, array('city', 'area', 'state', 'county'))) {
    if (!empty($node->field_banner_image)) {
        $bannerimage = image_style_url('place_banner_-_1400x453', $node->field_banner_image['und'][0]['uri']);
    }
}
?>
<div class="container<?php if (!is_null($bannerimage)) {
    print ' place-banner';
} ?>"<?php print $attributes; ?>>
    <?php $contexts = array_keys(context_active_contexts()); ?>
    <?php include(drupal_get_path('theme', 'liv') . '/partials/header.php'); ?>
    <!-- ______________________ MAIN _______________________ -->
    <?php if (!in_array('top_cities', $contexts)) : ?>
        <?php if (arg(0) !== 'find-city') : ?>
            <div class="clearfix content shadow-lrb page-header<?php if (!is_null($bannerimage)) {
                print ' banner-image " style="background:url(\'' . $bannerimage . '\'); background-size:cover;';
            } else {
                print ' padded';
            } ?>">
                <?php if ($breadcrumb || $title || $messages || $tabs || $action_links): ?>
                    <div id="content-header"<?php if (!is_null($bannerimage)) print ' class="padded"'; ?>>

                        <?php print $breadcrumb; ?>

                        <?php if ($page['highlighted']): ?>
                            <div id="highlighted"><?php print render($page['highlighted']) ?></div>
                        <?php endif; ?>

                        <?php if (isset($page['special_header'])) {
                            print render($page['special_header']);
                        } else {
                            print '<h1 class="title">' . $title . '</h1>';
                        }
                        ?>
                        <?php include(drupal_get_path('theme', 'liv') . '/partials/social.php'); ?>

                        <?php print render($page['help']); ?>

                    </div> <!-- /#content-header -->
                <?php endif; ?>
            </div>
        <?php endif; ?>

    <?php endif; ?>
    <div class="slide">
        <section id="main" class="clearfix content main shadow-lr" role="main">
            <?php
            $sidebarboth = false;
            $sidebar1 = false;
            $sidebar2 = false;
            $sidebarnone = false; //neither
            if (count($page['sidebar_second']) > 0) $sidebar2 = TRUE;
            if (count($page['sidebar_first']) > 0) $sidebar1 = TRUE;
            if ($sidebar1 && $sidebar2) $sidebarboth = TRUE;
            if (!$sidebar1 && !$sidebar2) $sidebarnone = TRUE;
            if ($sidebar1) print '<div class="l-300-full">';
            if ($page['sidebar_second']) print render($page['sidebar_second']);
            if ($sidebar2) print '<div class="left-nav-full">'; ?>
            <?php if (arg(0) == 'find-city') : ?>
            <div class="shadow-inset-lr clearfix content main">
                <?php else : ?>
                <div class="shadow-inset-lr clearfix content main column-content">
                        <?php if (in_array('top_cities', $contexts)): ?>
                            <div class="padded" id="content-header">
                                <?php print $breadcrumb; ?>
                            </div>

                        <?php endif; ?>
                    <?php endif; ?>
                    <?php print render($title_suffix); ?>
                    <?php print $messages; ?>
                    <?php print render($page['content']) ?>
                </div>
                <?php if ($sidebar2) print '</div>'; ?>
                <?php
                if ($sidebar2) {
                    $class = 'with-left-nav';
                } else {
                    $class = '';
                }
                if ($sidebar1) {
                    print '<div class="r-300 ' . $class . ' clearfix column-content">
              ' . render($page['sidebar_first']) . '
          </div>';
                }
                if ($sidebar1) print '</div>'; //l-300-full
                ?>
        </section>
    </div>
    <!-- /slide -->

    <?php if ($page['footer']): ?>
        <footer id="footer">
            <?php print render($page['footer']); ?>
        </footer> <!-- /footer -->
    <?php endif; ?>

</div> <!--container-->
