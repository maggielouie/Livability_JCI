/* To avoid CSS expressions while still supporting IE 7 and IE 6, use this script */
/* The script tag referring to this file must be placed before the ending body tag. */

/* Use conditional comments in order to target IE 7 and older:
	<!--[if lt IE 8]><!-->
	<script src="ie7/ie7.js"></script>
	<!--<![endif]-->
*/

(function() {
	function addIcon(el, entity) {
		var html = el.innerHTML;
		el.innerHTML = '<span style="font-family: \'livability\'">' + entity + '</span>' + html;
	}
	var icons = {
		'icon-moving': '&#xe605;',
		'icon-calculator': '&#xe603;',
		'icon-alarm': '&#xe604;',
		'icon-pia-partial': '&#xe606;',
		'icon-pie-empty': '&#xe607;',
		'icon-pie-full': '&#xe608;',
		'icon-googleplus': '&#xe629;',
		'icon-pinterest': '&#xe62a;',
		'icon-arrow-left-double': '&#xf100;',
		'icon-arrow-right-double': '&#xf101;',
		'icon-arrow-up-double': '&#xf102;',
		'icon-arrow-down-double': '&#xf103;',
		'icon-arrow-left': '&#xf104;',
		'icon-arrow-right': '&#xf105;',
		'icon-arrow-up': '&#xf106;',
		'icon-arrow-down': '&#xf107;',
		'icon-google-plus-square': '&#xf0d4;',
		'icon-pinterest-round': '&#xf0d2;',
		'icon-twitter-square': '&#xf081;',
		'icon-facebook-square': '&#xf082;',
		'icon-question': '&#xf128;',
		'icon-arrow-left-circle': '&#xe622;',
		'icon-arrow-right-circle': '&#xe623;',
		'icon-arrow-down-circle': '&#xe624;',
		'icon-arrow-up-circle': '&#xe625;',
		'icon-check': '&#xe626;',
		'icon-refresh': '&#xe627;',
		'icon-comments': '&#xe628;',
		'icon-search': '&#xe62b;',
		'icon-menu': '&#xe62c;',
		'icon-share': '&#xe62d;',
		'icon-quote-open': '&#xe609;',
		'icon-quote-close': '&#xe62e;',
		'icon-pin': '&#xe62f;',
		'icon-facebook': '&#xf09a;',
		'icon-twitter': '&#xf099;',
		'icon-housing': '&#xe631;',
		'icon-urban-planning': '&#xe632;',
		'icon-photos': '&#xe633;',
		'icon-education': '&#xe634;',
		'icon-government': '&#xe635;',
		'icon-entertainment': '&#xe637;',
		'icon-location': '&#xe638;',
		'icon-guides': '&#xe639;',
		'icon-digital-magazine': '&#xe63b;',
		'icon-binoculars': '&#xe63c;',
		'icon-demographics': '&#xe63d;',
		'icon-trophy': '&#xe63e;',
		'icon-food-drink': '&#xe63f;',
		'icon-transportation': '&#xe643;',
		'icon-community': '&#xe646;',
		'icon-flag': '&#xe647;',
		'icon-top10': '&#xe648;',
		'icon-bookmarks': '&#xe649;',
		'icon-weather': '&#xe64a;',
		'icon-health': '&#xe64b;',
		'icon-tags': '&#xe636;',
		'icon-calendar': '&#xe63a;',
		'icon-blog': '&#xe640;',
		'icon-sustainability': '&#xe641;',
		'icon-business': '&#xe642;',
		'icon-truck': '&#xe644;',
		'icon-checklist': '&#xe645;',
		'icon-zoom': '&#xe601;',
		'icon-phone': '&#xe602;',
		'icon-directions': '&#xe600;',
		'0': 0
		},
		els = document.getElementsByTagName('*'),
		i, c, el;
	for (i = 0; ; i += 1) {
		el = els[i];
		if(!el) {
			break;
		}
		c = el.className;
		c = c.match(/icon-[^\s'"]+/);
		if (c && icons[c[0]]) {
			addIcon(el, icons[c[0]]);
		}
	}
}());
