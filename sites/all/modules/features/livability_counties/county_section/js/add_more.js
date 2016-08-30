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
        var view = $('.show-more-link').parent().parent().parent();
        var list = view.find('ul');
        var count = list.size();
        count--;
        var bodyclasses = $('body').attr('class');
        var match = bodyclasses.match(/page-node-(\d+)/);
        var nid = match[1]
        $.get('/county_section/views/ajax', { 'offset' : count, 'nid' : nid }, function(data) {
          list.append(data);
        }, 'json');
      });
    }
  };
}(jQuery));