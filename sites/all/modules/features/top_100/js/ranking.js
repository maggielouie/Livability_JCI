(function ($) {
  Drupal.behaviors.top_100 = {
    attach: function(context,settings) {
        $('.js-more').click( function() { 
          var section = $(this).attr('id');
          var height = $('.' + section + '-contents').css('height');
          if (height <= '152px') {
               $('.' + section + '-contents').css('height', 'auto');
               $('.' + section + '-contents .js-more-title .control').addClass('icon-arrow-up');
               $('.' + section + '-contents .js-more-title .control').removeClass('icon-arrow-down');
               $(this).text('Less');
            }
          else {
            $('.' + section + '-contents').css('height', '152px');
            $('.' + section + '-contents .js-more-title .control').addClass('icon-arrow-down');
            $('.' + section + '-contents .js-more-title .control').removeClass('icon-arrow-up');
            $(this).text('Read more');
          }
        });
        $('.js-more-title').click( function() { 
          var section = $(this).attr('id');
          var height = $('.' + section + '-contents').css('height');
          if (height <= '152px') {
               $('.' + section + '-contents').css('height', 'auto');
               $('.' + section + '-contents .js-more-title .control').addClass('icon-arrow-up');
               $('.' + section + '-contents .js-more-title .control').removeClass('icon-arrow-down');
               $('.' + section + '-contents .js-more').text('Less');
            }
          else {
            $('.' + section + '-contents').css('height', '152px');
            $('.' + section + '-contents .js-more-title .control').addClass('icon-arrow-down');
            $('.' + section + '-contents .js-more-title .control').removeClass('icon-arrow-up');
            $('.' + section + '-contents .js-more').text('Read more');
          }
        });
    } //eof attach
  };
})(jQuery);
