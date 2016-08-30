/**
 * @file
 * liv_blog.views.js
 */

(function($) {
  Drupal.behaviors.liv_blog = {
    attach : function(context, settings) {
      $('.show-more-link').click( function(e) {
        e.preventDefault();
        var path = window.location.pathname.split('/');
        var cat = null;
        if(path[2]) { cat = path[2]; }
        var view = $('.show-more-link').parent().parent().parent();
        var list = view.find('.views-row');
        var count = list.size();
        count--;
        $.get('/liv_blog/views/ajax', { 'offset' : count, 'cat' : cat }, function(data) {
          list.parent().append(data);
        }, 'json');
      });
    }
  };
}(jQuery));
