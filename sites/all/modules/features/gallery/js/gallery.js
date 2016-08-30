function getUrlParameter(sParam)
{
    var sPageURL = window.location.search.substring(1);
    var sURLVariables = sPageURL.split('&');
    for (var i = 0; i < sURLVariables.length; i++)
    {
        var sParameterName = sURLVariables[i].split('=');
        if (sParameterName[0] == sParam)
        {
            return sParameterName[1];
        }
    }
}
(function ($) {
  Drupal.behaviors.gallery = {
    attach: function(context,settings) {
    if($('#gallery').length > 0){
        startSlide = parseInt(getUrlParameter('slide'));
        //startSlide=3;console.log(getUrlParameter('slide'))
      var slider = $('#gallery').royalSlider({
				// fullscreen: {
				// 	enabled: true,
				// 	nativeFS: true
				// },
				controlNavigation: 'thumbnails',
				autoScaleSlider: true,
				autoScaleSliderWidth: 923,
				autoScaleSliderHeight: 737,
				loop: false,
				loopRewind: false,
				imageScaleMode: 'fit',
				imageScalePadding : 0,
				navigateByClick: true,
				numImagesToPreload:10,
				arrowsNav:true,
				arrowsNavAutoHide: false,
				arrowsNavHideOnTouch: true,
				keyboardNavEnabled: true,
				fadeinLoadedSlide: true,
				globalCaption: true,
				globalCaptionInside: true,
				slidesSpacing: 0,
                startSlideId:startSlide,
				thumbs: {
				  appendSpan: true,
				  firstMargin: true,

				  spacing:2,
				},
				deeplinking: {
		            enabled: true,
		            prefix: 'image-'
		        }
			}).css({opacity: 1});
    } //eof if
  } //eof attach
  };

})(jQuery);

