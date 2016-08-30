jQuery(document).ready(function($) {
    
    // Save Article HTML for use after destroying slideshow
    articleContent = $('.articles-content').html();
    // Attach class to tables referencing the # of columns there are.
    $('.article-content table').each(function() {
        var colCount = 0;
        $(this).find('tr:nth-child(1) td').each(function() {
            if ($(this).attr('colspan')) {
                colCount += + $(this).attr('colspan');
            } else {
                colCount++;
            }
        });
        $(this).addClass('cols_' + colCount);
    });

    $(window).resize(function() {
        measureBrowser();

        var mapWidth = $('#map').width();

        if (mapWidth != undefined) {
            simplemaps_usmap_mapdata.main_settings.width=mapWidth;
            simplemaps_usmap();
        }

    });

    // Run JS for all devices and screensizes
    allJs();



window.onload = function() {
    // Measure browser on page load
    measureBrowser();
}
// Match heights
function matchHeight() {
    resetHeight();
    var row = new Array();
    $('.column-content').each(function(){
        row.push($(this).outerHeight());
    })
    var targetHeight = Math.max.apply(Math, row);
    $('.column-content').css('min-height',targetHeight)
}

function resetHeight() {
    $('.column-content').css('min-height',0)
}

function measureBrowser() {
    //Calculate body width - with and without scrollbars

    //Viewport width with scrollbar
    $('body').css('overflow', 'scroll');
    var widthWithScrollBars = $(window).width();

    // Viewport without scrollbars
    $('body').css('overflow', 'hidden');
    var widthNoScrollBars = $(window).width();

    // Scroll bar size for this particular client browser
    var scrollbarWidth = widthWithScrollBars - widthNoScrollBars;


    // Reset overflow
    $('body').css('overflow', '');

    windowWidth = widthNoScrollBars;
    windowHeight = $(window).height();

    // Desktop Only
    if (windowWidth > 1100) {
        matchHeight();
    }

    // Desktop and Tablet
    if (windowWidth > 767) {
        mobileDestroyJs();
        desktopTabletJs();
    }

    // Tablet Only
    if (windowWidth > 767 && windowWidth < 1100) {
        $('.right-column').addClass('shadow-inset-lr');
        resetHeight();
    }

    // Mobile Only
    if (windowWidth < 768) {
        mobileJs();
        resetHeight();
    }


}

function allJs() {
    var heroSlider = $(".hero-slider").royalSlider({
        arrowsNav: true,
        arrowsNavAutoHide: false,
        loop: false,
        numImagesToPreload: 5,
        slidesSpacing: 0
    });

    var heroSlider = $(".page-hero-slider").royalSlider({
        arrowsNav: true,
        arrowsNavAutoHide: false,
        loop: false,
        numImagesToPreload: 5,
        slidesSpacing: 0
    });

    var quoteSlider = $(".quotes-slider").royalSlider({
        arrowsNav: false

    })



    $('body').on("click", ".js-expand", function (e) {
        e.preventDefault();
        $(this).removeClass("js-expand").addClass("js-expanded")
        $(this).next(".expand-target").addClass("active");
    })
    $('body').on("click", ".js-expanded", function (e) {
        e.preventDefault();
        $(this).addClass("js-expand").removeClass("js-expanded")
        $(this).next(".expand-target").removeClass("active");
    })


    $('.locations-nearby').on("click", " li.listing", function (e) {
        defineListing = $(this);
        if ($(defineListing).hasClass("active") && $('body').hasClass('mobile'))  {
            $(defineListing).removeClass('active');
        }
        else {
            q = '';
            $('li.listing').removeClass('active');
            $(defineListing).addClass('active');
            mapData = $(defineListing).contents('.address').each(function(){
                $(this).contents('span').each(function(){
                    q = q+$.trim($( this ).text());
                });
            });
            if(q != '' && !$(defineListing).find('iframe').length){
                $(defineListing).find('.location-details')
                .prepend('<iframe src="https://www.google.com/maps/embed/v1/search?key=AIzaSyASxlXVkOAMgyF_iVQw0Xd286DlgLBD3lE&q='+q+'&zoom=11" style="border:0" frameborder="0" height="400" width="100%"></iframe>');
            }
        }
    })
    q='';
    near = $('.location-listings > ul .active');
    mapData = near.contents('.address').each(function(){
            q = q+$.trim($( this ).text());
    });
    $(near).find('.location-details')
        .prepend('<iframe src="https://www.google.com/maps/embed/v1/search?key=AIzaSyASxlXVkOAMgyF_iVQw0Xd286DlgLBD3lE&q='+q+'&zoom=11" style="border:0" frameborder="0" height="400" width="100%"></iframe>');
    count = 1;
    hospitals = $('.locations-nearby .listing').each(function(){
        if(count > 5){
            $(this).hide();
        }
        count++;
    });
    //todo pagination needs to be based on the set's length
    Drupal.settings.location = new Object();
    if($('.location-listings > ul')){
        Drupal.settings.location.page = 0;
    }

    $('.location-listings .pages li.previous').hide();
    if (hospitals.length < 5) {
        $('.location-listings .pages li.next').hide();
    }
    $('.pages li').click(function(e){
        element = $(e.target).closest('li');
        if(element.hasClass('next')) {
            Drupal.settings.location.page = Drupal.settings.location.page + 1;
        }else{
            Drupal.settings.location.page = Drupal.settings.location.page - 1;
        }

        $('.pages li').removeClass('active');

        perpage=5;
        starting = perpage * Drupal.settings.location.page;
        end = starting+perpage;

        if(Drupal.settings.location.page == 0){
            $('.location-listings .pages li.previous').hide();
        }else{
            $('.location-listings .pages li.previous').show();
        }
        if(end >= $('.location-listings > ul > li').length){
            $('.location-listings .pages li.next').hide();
        }else{
            $('.location-listings .pages li.next').show();
        }

        $('.location-listings > ul > li').each(function(i){
            if(i >= starting && i < end){
                $(this).show();
            }else{
                $(this).hide();
            }
            if(i == starting){
                $(this).addClass('active');
                q = '';
                $(this).contents('.address').each(function(){
                    q = q+' '+$.trim($( this ).text());
                });
                if(q != '' && !$(this).find('iframe').length){
                    $(this).find('.location-details').prepend('<iframe src="https://www.google.com/maps/embed/v1/search?key=AIzaSyASxlXVkOAMgyF_iVQw0Xd286DlgLBD3lE&q='+q+'&zoom=11" style="border:0" frameborder="0" height="200" width="100%"></iframe>');
                }
            }else{
                $(this).removeClass('active');
            }
        });

        return false;
    });
    $('.city-list').on("click", "li .city-info", function (e) {
        defineListing = $(this).parent();
        if ($(defineListing).hasClass("active-city") && $('body').hasClass('mobile'))  {
            $(defineListing).removeClass('active-city');
        }
        else {
            $('li').removeClass('active-city');
            $(defineListing).addClass('active-city');
        }
    })
}

function desktopTabletJs() {
    // Variables for Left Nav
    var leftNavOffset = $('.left-nav').offset();

    // Variables for City Listing
    var cityListHeightThreshold = $('.city-list').offset();
    var cityListHeight = $('.city-list').height();
    var cityActiveHeight = $('.active-city .city-details').height();
    var cityActiveOffset = $('.active-city .city-details').offset();
    var cityListOnPage = $('.city-list').length;

    $(window).scroll(function() {
        scrollTopVal = $(window).scrollTop();

        // Left Nav Sticky
        if (leftNavOffset != undefined && scrollTopVal > leftNavOffset.top) {
            $('.left-nav').css({
                position: 'fixed'
            })
        }
        else{
            $('.left-nav').css({
                position: 'relative'
            })
        }
        // End Left Nav Sticky

        // City List Sticky
        if (cityListOnPage){
            var cityActiveHeight = $('.active-city .city-details').height();
            cityActiveHeight = $('.active-city .city-details').height();
            if (scrollTopVal > cityListHeightThreshold.top) {
                if (scrollTopVal < (cityListHeight - cityActiveHeight + cityListHeightThreshold.top)) {
                    $('.city-list .city-details').css({
                        top: scrollTopVal - cityListHeightThreshold.top,
                        bottom: 'initial'
                    })
                }
                else {
                    $('.city-list .city-details').css({
                       top: 'initial',
                       bottom: 0
                    })
                }
            }
            else {
                $('.city-list .city-details').css({
                    top: 0
                })
            }
        }
        //End City List Sticky

    });
}


function mobileJs() {
    // Copy contents of main header nav into mobile slide nav - doing this to avoid content duplicates
    $('body').addClass('mobile');

    navContent = $('header nav ul').html();
    moreStoriesContent = $('.more-stories').html();
    $('li.more-stories').remove();

    if ($("nav.no-desktop ul").is(':empty')) {
        $("nav.no-desktop ul").append(navContent);
        $(".container").addClass("closed")
    }

    // Handle menu
    $('body').on("click", ".closed .mobile-menu-button", function (e) {
        e.preventDefault();
        e.stopPropagation();
        expandNav();
    })

    $('body').on("click", ".open .slide, .open .mobile-menu-button", function (e) {
        e.preventDefault();
        e.stopPropagation();
        closeNav();
    })

    // Handle menu submenus
    $("nav.no-desktop ul li").click(function(e) {

        if ($(this).children('ul').length) {
            e.preventDefault();
            $(this).find('.level-1').addClass("active");
            $('.nav-container').addClass("collapsed");
        }
    })
    $("nav.no-desktop ul li > ul > li").click(function(e) {
//        console.log(e.toElement);
        e.preventDefault();
        window.location = e.toElement;
    });

    $(".nav-container .go-back").click(function(e) {
        e.preventDefault();
        $('.nav-container').removeClass("collapsed");
        setTimeout(function(){
            $('.level-1').removeClass("active");
        },600); // wait 600ms before removing class - to give time for animation to finish.

    })

    // Handle search dropdown
     $('header').on("click", ".js-expand", function (e) {
        $('header').addClass('search');
     });
     $('header').on("click", ".js-expanded", function (e) {
        $('header').removeClass('search');
     });


    // Handle leftNav menu
    leftNavWidth = $('.left-nav ul.all-categories li a i').size() * 48;
    leftNavBoundary = leftNavWidth-windowWidth;
    $('.drag-container').css({
        left: -leftNavBoundary,
        width: leftNavWidth
    })
    if (leftNavWidth < windowWidth) {
        $('.drag-container ul.all-categories').css({
            width: windowWidth
        })
    }

    $('.drag-container ul.all-categories').css({
       left: leftNavBoundary
    })
    $('.drag-container ul.all-categories').udraggable('destroy')
    $('.drag-container ul.all-categories').udraggable({
        containment: [0,0,leftNavBoundary,0],
        axis: "x"
    });

    // Put articles into slideshow
    $(".article-slider img").addClass("rsImg")
    $(".article-slider li").addClass("rsContent")

    var articleSlider = $(".article-slider").royalSlider({
        imageScaleMode: 'fit-if-smaller',
        imageScalePadding: 0,
        autoScaleSlider: false,
        addActiveClass: true,
        slidesSpacing: 5,
        arrowsNav: true,
        arrowsNavAutoHide: false,
        navigateByClick:false,
        loop: true,
        visibleNearby: {
            enabled: true,
            centerArea: 0.875,
            center: true,
            navigateByCenterClick: false
        }
    })

    // Truncate content

    // Flush previously truncated elements - prevents duplicate content on resize
    $('.truncated').remove();
    $('.hidden').show().removeClass('hidden').find('.showless').remove();

    $(".truncate-mobile-50").truncate({
        maxLength : 50,
        more: "more" ,
        less: "less",
        lessSeparator: ""
    });

    $(".truncate-mobile-150").truncate({
        maxLength : 150,
        more: "more" ,
        less: "less",
        lessSeparator: ""
    });

    $(".truncate-mobile-250").truncate({
        maxLength : 250,
        more: "more" ,
        less: "less",
        lessSeparator: ""
    });

    $(".truncate-mobile-350").truncate({
        maxLength : 350,
        more: "more" ,
        less: "less",
        lessSeparator: ""
    });


}

function mobileDestroyJs() {
    $('body').removeClass('mobile');
    $('.drag-container, .drag-container ul').css({
        width: '100%',
        left:0
    });



    $('.drag-container ul.all-categories').udraggable('destroy')

    // Destroy Slider
    $(".article-slider").royalSlider('destroy', true);

    // Check if Article Slider is empty - which it will be after a destroy - and reload content if it is
    if ($(".article-slider").length == 0) {
       $('.articles').append(articleContent)
    }
}

function expandNav() {
    $('.container, .nav-container').addClass('open').removeClass('closed');
    $('html').addClass('fixed');
}

function closeNav() {
    $('.nav-container').removeClass("collapsed"); // Always collapse secondary menu items
    $('.container,  .nav-container').removeClass('open').addClass('closed');
    $('html').removeClass('fixed');
}

$(document).ready(function(){

	// hide #back-top first
	$("#back-top").hide();
	
	// fade in #back-top
	$(function () {
		$(window).scroll(function () {
			if ($(this).scrollTop() > 100) {
				$('#back-top').fadeIn();
			} else {
				$('#back-top').fadeOut();
			}
		});

		// scroll body to 0px on click
		$('#back-top a').click(function () {
			$('body,html').animate({
				scrollTop: 0
			}, 800);
			return false;
		});
	});

});

});
