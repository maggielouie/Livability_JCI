<?php
print '<div class="city-real-estate padded">
	<h2>Real Estate Listings
		<span class="powered-by">
			Powered by: <img src="/sites/all/themes/liv/livability/images/logos/trulia.png" alt="Trulia">
		</span>
	</h2>
';
if(!isset($c)){ global $c;$c=getCityContext();}
//var_dump($c->state->field_state_code);
print '<link rel="stylesheet" href="http://css.trulia-cdn.com/css/G30_32/css/pg_truliatool-generate.css">
    <div class="trulia_tool home-gallery">
    <iframe src="'.
    'http://synd.trulia.com/tools/home-gallery/embedded'.
    '?params[location]='.
    urlencode($c->title).
    ','.
    $c->state->field_state_code[LANGUAGE_NONE][0]['value'].
    '&params[speed]=0&params[title]=Livability&params[color]=red'.
    //'&params%5BlocationId%5D=&params%5Bmin_price%5D=&params%5Bmax_price%5D=&params%5Bnum_beds%5D=&params%5Bnum_baths%5D='.
    //'&params%5Bemail%5D=&params%5Buser_url%5D=
    '&params[width]=100%&params[height]=250'.
    '&params[guid]=53f670e296d48'.
    '&params[slides_per_page]=5'.
    '&city='.urlencode($c->title).'&state_code='.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].
    '&params[tpl]=livability'.
    '" style="height: 250px; overflow: hidden;">'.
    '<p>Your browser does not support iframes</p>
    </iframe>
    <div class="trulia_tool_footer"><div class="footer-link typeTruncate">
        <a href="http://www.trulia.com/for_sale/' . check_plain($c->title) . ',' . check_plain($c->state->field_state_code[LANGUAGE_NONE][0]['value']) . '/" title="See homes in ' . check_plain($c->title) . ', ' . check_plain($c->state->field_state_code[LANGUAGE_NONE][0]['value']) . '" target="_blank" rel="nofollow">
        See homes in
        </a><br />
        <span>'.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'].'</span>
    </div><a class="trulia-logo" href="http://www.trulia.com/" title="Trulia" target="_blank"></a>
</div></div>';


print '</div>';