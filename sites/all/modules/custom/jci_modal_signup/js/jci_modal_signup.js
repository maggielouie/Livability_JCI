(function ($) {
  Drupal.behaviors.jci_modal_signup = {
    attach: function(context,settings) {
      // Dump out if this is a crawler, we do not want modal crawled.
      if (/bot|googlebot|crawler|spider|robot|crawling/i.test(navigator.userAgent)) {
        return;
      }

      var cookieName;
      var newsletter_iframe_url;
      if (window.location.pathname == '/blog') {
        cookieName = 'jciBlogSignupPresented';
        newsletter_iframe_url = 'http://eepurl.com/3kXgX';
      }
      else {
        cookieName = 'jciSignupPresented';
        newsletter_iframe_url = 'http://eepurl.com/R6-dD';
      }

      affirmative = $.cookie(cookieName);
      if(!affirmative) {
        $.cookie(cookieName, 'yes', { path: '/' });
        $('body').prepend('<div id="overlay-once"><span id="framewrap" class="' + cookieName + '"><a id="close">CLOSE</a><iframe src="' + newsletter_iframe_url + '"></iframe></span></div>');
        document.getElementById('overlay-once').addEventListener('click', function() {
          var elem = document.getElementById('overlay-once');
          elem.parentNode.removeChild(elem);
        }, false);
        document.getElementById('close').addEventListener('click', function() {
          var elem = document.getElementById('overlay-once');
          elem.parentNode.removeChild(elem);
        }, false);
        $(document).keyup(function(e) {
          if(e.which == 27)  {
          	var elem = document.getElementById('overlay-once');
            elem.parentNode.removeChild(elem);
          }
        });
      }
    } //eof attach
  };
})(jQuery);
