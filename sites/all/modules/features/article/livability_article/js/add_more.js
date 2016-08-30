/**
 * @file
 */

(function($) {
  Drupal.behaviors.liv_article = {
    attach : function(context, settings) {
      $('.show-more-link').click( function(e) {
        e.preventDefault();
        var path = window.location.pathname.split('/');
        var cat = null;
        if(path[2]) { cat = path[2]; }
        var view = $('.show-more-link').parent().parent().parent();
        var list = view.find('ul');
        var count = list.children().length;
        $.get('/liv_topics/views/ajax', { 'offset' : count, 'cat' : cat }, function(data) {
          list.append(data);
        }, 'json');
      });
    }
  };
}(jQuery));