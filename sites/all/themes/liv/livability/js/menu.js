(function($) {
    $.slideNav = function(options) {
        var sn = {
            options: $.extend({
                'menuButton': '.mobile-menu',
                'menuButtonActive': '-active',
                'menuClose': '.slide-nav-close',
                'menuOpened': 'slide-nav-opened',
                'menuTransition': 'nav-transitioned',
                'menuWrapper': '.slide-nav-wrapper',
                'menuWrapperOther': '.slide-nav-bg',
                'removeBodyScrollOnOpen': true
            }, options),

            loadNav: function() {
                var transistionTypes = new Array();
                transistionTypes = ['-webkit-transform',
                    '-moz-transform',
                    '-ms-transform',
                    '-o-transform',
                    'transform'
                ];

                $(document.body).on('click', sn.options.menuWrapper + '.' + sn.options.menuTransition, function() {
                    sn.closeNav();
                });

                var menuWrapperOtherArray = sn.options.menuWrapperOther.split(",");

                $.each(menuWrapperOtherArray, function(index, value) {
                    $(document.body).on('click', $.trim(value) + '.' + sn.options.menuTransition, function() {
                        sn.closeNav();
                    });
                });


                if (!$('html').hasClass('no-csstransitions')) {
                    $(sn.options.menuWrapper).on('webkitTransitionEnd otransitionend oTransitionEnd msTransitionEnd transitionend', function(e) {
                        if (($(e.target).is(sn.options.menuWrapper) || $(e.target).is(sn.options.menuWrapperOther)) && $.inArray(e.originalEvent.propertyName, transistionTypes) != '-1') {
                            sn.toggleMenuTransition(($(e.target).hasClass(sn.options.menuTransition) ? 'close' : 'open'));
                        }
                    });
                }

                $(sn.options.menuButton).click(function(e) {
                    sn.openClick();

                    e.preventDefault();
                });


                $(sn.options.menuClose).click(function(e) {
                    e.preventDefault();

                    sn.closeNav();
                });
            },

            openClick: function() {
                if ($(sn.options.menuWrapper).hasClass(sn.options.menuOpened)) {
                    sn.closeNav();
                } else {
                    sn.openAndRemoveScroll();
                }
            },

            openAndRemoveScroll: function() {
                if (sn.options.removeBodyScrollOnOpen) {
                    $('html').addClass('slide-nav-lock');

                    setTimeout(sn.openNav, 1);
                } else {
                    sn.openNav();
                }
            },

            closeAndAddScroll: function() {
                if (sn.options.removeBodyScrollOnOpen) {
                    $('html').removeClass('slide-nav-lock');
                }
            },

            openNav: function() {
                $(sn.options.menuButton).addClass(sn.options.menuButtonActive);
                $(sn.options.menuWrapper).addClass(sn.options.menuOpened);
                $(sn.options.menuWrapperOther).addClass(sn.options.menuOpened)

                if ($('html').hasClass('no-csstransitions')) {
                    sn.toggleMenuTransition('open');
                }
            },

            closeNav: function() {
                $(sn.options.menuButton).removeClass(sn.options.menuButtonActive);
                $(sn.options.menuWrapper).removeClass(sn.options.menuOpened);
                $(sn.options.menuWrapperOther).removeClass(sn.options.menuOpened);
                $('.nav-container').removeClass("collapsed");
                $('.level-1').removeClass("active");

                if ($('html').hasClass('no-csstransitions')) {
                    sn.toggleMenuTransition('close');
                }
            },

            toggleMenuTransition: function(toggleType) {
                if (toggleType == 'close') {
                    setTimeout(sn.closeAndAddScroll, 1);
                }

                $(sn.options.menuWrapper).toggleClass(sn.options.menuTransition);
                $(sn.options.menuWrapperOther).toggleClass(sn.options.menuTransition);
            }
        };

        return {
            loadNav: sn.loadNav,
            openNav: sn.openAndRemoveScroll,
            toggleNav: sn.openClick,
            closeNav: sn.closeNav
        };
    };
})(jQuery);