<?php
$m = $node;
?>
<div class="city-details padded clearfix">
	<span class="city-map-small">
		<img src="https://www.google.com/maps/api/staticmap?key=AIzaSyDG1yg6Il9JKBNlgFzrP0eLSWGjc7Ul0n8&center=<?php print $node->title; ?>&zoom=8&size=205x273&markers=color:0x009bd5%7c<?php print $node->title; ?>" >
	</span>
	<div class="city-summary">
		<h1><?php print $m->title; ?></h1>
        <?php print $m->madlib ?>

	</div>

<br style="clear:both;">
<ul class="clearfix infograph" style="clear:both;">
    <li class="one-third">
        <h4>Population</h4>
			<span class="medium-value">
                <?php if (isset($m->census['metro-data']['DP05_0001E'])) {
                    print number_format($m->census['metro-data']['DP05_0001E'], 0);
                }elseif(isset($m->field_population[LANGUAGE_NONE][0])){
                    //print number_format($m->field_population[LANGUAGE_NONE][0]['value'],0);
                }else{
                    print 'n/a';
                } ?>
			</span>
    </li>
    <li class="one-third">
        <h4>Median Household Income</h4>
			<span class="medium-value">
				<?php
                if (isset($m->census['metro-data']['DP03_0062E'])){
                    print '$'.number_format($m->census['metro-data']['DP03_0062E']);
                }elseif(isset($m->field_median_household_income[0])){
                    print '$'.number_format($m->field_median_household_income[0]['amount'],0);
                } else {
                    print 'n/a';
                } ?>
			</span>
    </li>
    <li class="one-third last">
        <h4>Median Home Price</h4>
			<span class="medium-value">
                <?php if(isset($m->census['metro-data']['DP04_0088E'])) {
                    print '$'.number_format($m->census['metro-data']['DP04_0088E']);
                }elseif(isset($m->field_median_home_price[LANGUAGE_NONE][0])){
                    print '$'.number_format($m->field_median_home_price[LANGUAGE_NONE][0]['value'],0);
                }else{
                    print 'n/a';
                } ?>
			</span>
    </li>
</ul>
</div>
<?php
    if ($promoted) { print citySectionInclude('stubs/ad728'); }
    else {

        print citySectionInclude('stubs/ad728middle');
    }
    $excluded = excludedTids();
    $placeLevelTaxonomy = taxonomy_get_children(1);
    $thingsToDoTaxonomy = array_diff_key($placeLevelTaxonomy,$excluded);
    $content = array();
    $terms = array();
    foreach($thingsToDoTaxonomy as $tid => $tax){
        $terms[] = $tax->name;
    }
    $getcount = 3;
    if($promoted) { $getcount = 9; }
    $stuff = getContentByTermAndPlace($terms,$m, 0, $getcount);
    foreach($stuff['nodes'] as $things){
        $content[] = $things;
    }
	if(!empty($content)) {
      print citySectionInclude('stubs/content-cards',array('nodes'=>$content,'heading'=>'Articles Related to '.$m->title.', '.$m->state->field_state_code[LANGUAGE_NONE][0]['value'],'total'=>$stuff['total'],'cnid'=>$m->nid,'terms'=>$terms));
    }
    if ($promoted) { print citySectionInclude('stubs/ad728middle'); }
    $galleryNidQuery = new EntityFieldQuery();

    $galleryNidQuery->entityCondition('entity_type','node')->entityCondition('bundle','gallery');
    $galleryNidQuery->fieldCondition('field_gallery_city','target_id',$m->nid);
    $galleryNidResults = $galleryNidQuery->execute();
    if(isset($galleryNidResults) && count($galleryNidResults) == 1){
        $nid = array_keys($galleryNidResults['node']);
        $galleryNode = node_load($nid[0]);
        $items = $galleryNode->field_image[LANGUAGE_NONE];
        ?>
        <div class="photo-strip-container">
            <span class="heading">Photos of <strong><?php print $m->title.', '.$m->state->field_state_code[LANGUAGE_NONE][0]['value'];?></strong></span>
            <ul class="photo-strip rsDefault">
                <?php foreach ($items as $delta => $item): ?>

                    <span>
                      <img class="rsTmb" src="<?php print image_style_url('media_thumbnail', $item['uri']); ?>" data-link="/<?php print drupal_get_path_alias('node/'.$m->nid).'/photos?slide='.$delta;?>" style="width:100px;height:100px;float:left;" />
                    </span>
                <?php endforeach; ?>
            </ul>
            <script>
                jQuery(document).ready(function($) {
                    var slider = $('.photo-strip').royalSlider({
                        controlNavigation: 'thumbnails',
                        thumbs: {
                            appendSpan: true,
                            firstMargin: false,
                            spacing:2
                        }
                    });
                    $('.photo-strip').css({
                        opacity: 1
                    })

                    $(".photo-strip").on("click", ".rsThumb", function(e) {
                        window.location.href = $(this).find('.rsTmb').data('link')
                    })
                });
            </script>
            <?php
        print '</div>';
    }
//County Content Cards
$nids = array();
foreach($node->cities as $city) {
    $nids[] = $city->nid;
}
$view_args = implode(',', $nids);
print views_embed_view('metro_content_cards', 'block', $view_args);
//print citySectionInclude('stubs/category-cards', array('url' => $node_url, 'city' => $c->title, 'state' => $c->state->title));
?>
<div class="find">
    <div class="states">
        <h1>Best Places to Live in <?php print $m->title;?></h1>
        <?php print views_embed_view('county_city_list', 'block', $view_args); ?>
    </div>
</div>
<?php
//print citySectionInclude('real-estate/block-listing');
?>
