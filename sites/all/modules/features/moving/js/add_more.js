/**
 * @file
 * Behaviors for Moving page.
 */

(function($) {
  Drupal.behaviors.moving_add_more = {
    attach : function(context, settings) {
      $('.show-more-link').click( function(e) {
        e.preventDefault();
        var path = window.location.pathname.split('/');
        var cat = null;
        if(path[2]) { cat = path[2]; }
        var view = $('.show-more-link').parent().parent().parent();
        var list = view.find('ul');
        var count = list.children().length;
        $.get('/moving/views/ajax', { 'offset' : count, 'cat' : cat }, function(data) {
          list.append(data);
        }, 'json');
      });
    }
  };
}(jQuery));
