/**
 * @file
 */

(function($) {
  Drupal.behaviors.liv_best_places = {
    attach : function(context, settings) {
      $('.show-more-link').click( function(e) {
        e.preventDefault();
        var path = window.location.pathname.split('/');
        var arg = null;
        if(path[2]) { arg = path[2]; }
        var view = $('.show-more-link').parent().parent().parent();
        var list = view.find('ul');
        var count = list.children().length;
        $.get('/best_places/views/ajax', { 'offset' : count, 'arg' : arg }, function(data) {
          list.append(data);
        }, 'json');
      });
    }
  };
}(jQuery));