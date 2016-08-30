/**
 * @file
 * Javascript for the interface at admin/content/media and also for interfaces
 * related to setting up media fields and for media type administration.
 *
 * Basically, if it's on the /admin path, it's probably here.
 */

(function ($) {

    /**
     * Functionality for the administrative file listings.
     */
    Drupal.settings.findCity = {}
    Drupal.settings.findCity.cache ={};

    Drupal.behaviors.findCity = {
        attach: function (context) {
            $(".find-city-input").focus();
            Drupal.settings.findCity.pos =-1;
            $(".find-city",context).submit(function(e){

                if(Drupal.settings.findCity.pos <1){
                    Drupal.settings.findCity.pos =0;
                }
                firstLink = $(".find-city li#"+Drupal.settings.findCity.pos+" a").first().attr('href');
                if(firstLink){
                    window.location = firstLink;
                }else{
                    alert('No city found. Type more of the name and it should appear below.');
                }
                e.stopImmediatePropagation();
                return false;
            });
            $(".find-city-input",context).keydown(function(e){
                //console.log(e.keyCode);
                if(e.keyCode == '13'){

                }
                if(e.keyCode == '8' || e.keyCode == '46') {
                    return;
                }
                if(e.keyCode == '40' || e.keyCode == '38'){
                    if(e.keyCode == '38' && Drupal.settings.findCity.pos >0){
                        Drupal.settings.findCity.pos--;
                    }
                    if(e.keyCode == '40'){
                        Drupal.settings.findCity.pos++;
                    }
                    if(Drupal.settings.findCity.pos < $(".find li").length){
                        $(".find-city li a").css('color','black');
                        $.each($(".find li a"),function(key,val){
                            if(key == Drupal.settings.findCity.pos){
                                $(".find-city li#"+key+" a").css('color','red');
                                //val.style('color','red');
                            }
                        })
                    }else{
                        Drupal.settings.findCity.pos = $(".find li").length;
                    }
                    return;
                }

                function setResults(success){
                    var items = [];
                    $.each( success, function( key, val ) {
                        if(val.type == 'city') {
                            items.push("<li id='" + key + "'><a href=\"/" + val.path + "\">"
                            + val.city + ", " + val.stateCode.toUpperCase() + "</a></li>");
                        }else if(val.type == 'metro_area'){
                            items.push( "<li id='" + key + "'><a href=\"/"+val.path+"\">"
                            +val.city+"</a></li>" );
                        }
                    });

                    $( ".find-city ul").html(items.join( "" ));
                }
                param = $(".find .find-city-input").prop('value');

                if(param.length>=3){
                    clearTimeout($(this).data('timer'));
                    $(this).data('timer', setTimeout(function() {
                        param = $(".find .find-city-input").prop('value');
                        if(param.length > 3){
                            url = '/find-city.json?search_api_views_fulltext='+param;
                            $.ajax({
                                dataType: "json",
                                url: url,

                                success: setResults
                            });
                        }else{
                            //alert('Please enter a city name.');
                        }
                    },50));
                }

           })
        }
    }
})(jQuery);