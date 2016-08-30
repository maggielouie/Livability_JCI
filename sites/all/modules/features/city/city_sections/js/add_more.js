/**
 * @file
 * city_sections.add_more.js
 */

(function($) {
  Drupal.behaviors.liv_blog = {
    attach : function(context, settings) {
      $('.show-more-link').click( function(e) { 
        e.preventDefault();
        var path = window.location.pathname.split('/');
        var view = $('.show-more-link').parent().parent().children('.articles');
        var list = view.find('ul');
        var count = list.children().length;
        var arg = list.attr('id');
        var args = arg.split('-');
        var nid = args.shift();
        if (parseInt($(this).parent().attr('data')) <= count+3) {
        	$('.show-more').css('display', 'none');
        }
        $.get('/city_sections/views/ajax', { 'offset' : count, 'nid' : nid, 'terms' : args }, function(data) {
          list.append(data);
        }, 'json');
      });
    }
  };
}(jQuery));