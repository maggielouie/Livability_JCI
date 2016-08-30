<header id="header" class="clearfix slide">
    <div class="content clearfix">
        <div class="logo-container">
            <a class="logo" href="/">Livability.com</a>
        </div>
        <?php if ($page['header']): ?>
            <?php print render($page['header']); ?>
        <?php endif; ?>
        <span class="right">
            <ul class="social desktop-only">
                <li><a href="http://www.facebook.com/Livability" class="icon-facebook-square white" target="_blank"></a></li>
                <li><a href="http://twitter.com/Livability" class="icon-twitter white" target="_blank"></a></li>
                <li><a href="http://plus.google.com/112521199452031771149" class="icon-googleplus white" target="_blank"></a></li>
                <li><a href="http://www.pinterest.com/livability/" class="icon-pinterest white" target="_blank"></a></li>
            </ul>
            <div class="search">
                <a href="#" class="icon-search white js-expand"></a>
                <span class="expand-target search-dropdown">
                <?php
                $view = views_get_view('global_search');
                $display_id = 'page';
                $view->set_display($display_id);
                $view->init_handlers(); //initialize display handlers
                $form_state = array(
                    'view' => $view,
                    'display' => $view->display_handler->display,
                    'exposed_form_plugin' => $view->display_handler->get_plugin('exposed_form'), //exposed form plugins are used in Views 3
                    'method' => 'get',
                    'rerender' => TRUE,
                    'no_redirect' => TRUE,
                );
                $form = drupal_build_form('views_exposed_form', $form_state); //create the filter form
                //you now have a form array which can be themed or further altered...
                $he = drupal_render($form);
                print $he;
                ?>
                </span>
            </div>
            <span class="mobile-menu-button mobile-only">
              <a href="" class="icon-menu white"></a>
            </span>
        </span>
    </div>
</header> <!-- /header -->