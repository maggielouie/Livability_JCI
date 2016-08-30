jQuery(document).ready(function($) {
	$(document).ready(function(){

		var width = $(window).width();
		$.ajax({
			url: '/',
			type: 'post',
			data: { 'width' : width, 'recordSize' : 'true' },
			success: function(response) {
				$("body").html(response);
			}
		});

		$('#search-main').on("click", ".js-expand", function (e) {
			e.preventDefault();
			$(this).removeClass("js-expand").addClass("js-expanded");
			$(this).next(".expand-target").addClass("active");
		});
		$('#search-main').on("click", ".js-expanded", function (e) {
			e.preventDefault();
			$(this).addClass("js-expand").removeClass("js-expanded");
			$(this).next(".expand-target").removeClass("active");
		});

		// hide #back-top first
		$("#back-top").hide();
		
		// fade in #back-top
		$(function () {
			$(window).scroll(function () {
				if ($(this).scrollTop() > 100) {
					$('#back-top').fadeIn();
				} else {
					$('#back-top').fadeOut();
				}
			});
	
			// scroll body to 0px on click
			$('#back-top a').click(function () {
				$('body,html').animate({
					scrollTop: 0
				}, 800);
				return false;
			});
		});
	});

});