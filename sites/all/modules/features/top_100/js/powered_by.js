(function ($) {
  Drupal.behaviors.top_100_powered_by = {
    attach: function(context,settings) {
        $('.top-100-sponsored-by').each(function(){
            if($(this).find('iframe').length > 0){
                $(this).show();
            }
        });
    } //eof attach
  };
})(jQuery);
