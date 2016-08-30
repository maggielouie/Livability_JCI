<?php
$node->type = 'city';
$c = city_node_load($node->nid);

$promoted = false;
if($c->field_promoted_city[LANGUAGE_NONE][0]['value'] == 1){
    $promoted = true;
    $q = 'SELECT n.nid FROM node n '.
         'LEFT JOIN field_data_field_place pc on pc.entity_id = n.nid '.
         'LEFT JOIN field_data_field_place_ref p on p.entity_id = pc.field_place_value '.
         'LEFT JOIN field_data_field_featured_on_place_homepage fph on fph.entity_id = pc.field_place_value '.
         'WHERE n.status = 1 '.
         'AND fph.field_featured_on_place_homepage_value = 1 '.
         'AND p.bundle = :bundletype '.
         'AND p.field_place_ref_target_id = :citynid';
    $featuredContentQuery = db_query($q,array(':bundletype' => 'field_place', ':citynid' => $c->nid));
    if($featuredContentQuery->rowCount() > 0){
        foreach($featuredContentQuery as $featuredContent){
            //print_r($featuredContent);
            $node = node_load($featuredContent->nid);
            $image = $node->field_image[LANGUAGE_NONE][0];
            //todo refactor to use the term name through the node
            $fi = entity_load('field_collection_item',$node->field_category[LANGUAGE_NONE][0]);
            $fi = array_shift($fi);
            $tid = $fi->field_category_ref[LANGUAGE_NONE][0]['tid'];
            $tax = taxonomy_term_load($tid);
            $image['title'] = $node->title;
            $image['topic'] = $tax->name;
            $image['link'] = '/'.drupal_get_path_alias('node/'.$node->nid);
            $images[] = $image;
        }
        if(count($images)>0){
            print new liv_slider($images,'hero');
        }
    }
}
?>

<div class="city-details padded clearfix">
    <span class="city-map-small">
        <img src="https://www.google.com/maps/api/staticmap?key=AIzaSyDG1yg6Il9JKBNlgFzrP0eLSWGjc7Ul0n8&center=<?php print $c->title.','.$c->state->field_state_code['und'][0]['value']; ?>&zoom=12&size=205x273&markers=color:0x009bd5%7c<?php print $c->title.','.$c->state->field_state_code['und'][0]['value']; ?>" >
    </span>
    <span class="city-summary">
        <h1>City of <?php print $c->title.', ';
             print $c->state->field_state_code['und'][0]['value']; ?></h1>
        <p class="truncate-mobile-350">
<?php
if($c->body != null) {

    print $c->body[LANGUAGE_NONE][0]['value'];

} else {

    print $c->title.' is located in '.$c->county->name.' in '.$c->state->title.'. ';
    //It is part of the <metro> area.
    function printEthnicPercentages($c){
        $c->census['city-data']['other-total'] = $c->census['city-data']['DP05_0077E'] + $c->census['city-data']['DP05_0078E'] + $c->census['city-data']['DP05_0079E'] + $c->census['city-data']['DP05_0080E'];
        $white    = isset($c->census['city-data']['DP05_0072E']) ? $c->census['city-data']['DP05_0072E'] : 0;
        $black    = isset($c->census['city-data']['DP05_0073E']) ? $c->census['city-data']['DP05_0073E'] : 0;
        $indian   = isset($c->census['city-data']['DP05_0074E']) ? $c->census['city-data']['DP05_0074E'] : 0;
        $hispanic = isset($c->census['city-data']['DP05_0066E']) ? $c->census['city-data']['DP05_0066E'] : 0;
        $asian    = isset($c->census['city-data']['DP05_0075E']) ? $c->census['city-data']['DP05_0075E'] : 0;
        $hawaiian = isset($c->census['city-data']['DP05_0076E']) ? $c->census['city-data']['DP05_0076E'] : 0;
        $other    = isset($c->census['city-data']['other-total']) ?$c->census['city-data']['other-total'] : 0;
        $other    = $other+$hawaiian+$indian;
        $total = $white+$black+$indian+$hispanic+$asian+$other;

        print 'The population is '.number_format($white/$total*100,0).'% White, ';
        print number_format($black/$total*100,0).'% Black, '.
            //number_format($indian/$total*100,1).'% American Indian, '.
            number_format($asian/$total*100,0).'% Asian and '.
            number_format(($indian+$hawaiian)/$total*100,0).'% Native American or Native Hawaiian. '.
            number_format($other/$total*100,0).'% identify as another race or ethnicity, or two or more races. '.
            number_format($hispanic/$total*100,0).'% of residents are of Hispanic or Latino origin. ';
    }

    $unemploymentRate = number_format($c->census['city-add-data']['DP03_0005E']/($c->census['city-add-data']['DP03_0004E']+$c->census['city-add-data']['DP03_0006E'])*100,2);

    //print 'The cost of living for its '.number_format($c->field_population[LANGUAGE_NONE][0]['value'],0).

    //    ' residents is <higher/lower> than the national average. '.
    print 'The median income is $'.number_format($c->census['city-data']['DP03_0062E'],0).
    ' and the median home value is ';
    if(isset($c->census['city-data']['DP04_0088E'])){
        print '$'.number_format($c->census['city-data']['DP04_0088E'],0).'. ';
    }else{
        print ' not available for this locality. ';
    }
    //'It’s population has been growing/shrinking> at a rate of growth> since 2000. '.
    //print //'The unemployment rate is '.$unemploymentRate.'% compared to the 6.1% unemployment rate for the United States (as of August 2014). '.
    //'Workers commute an average of '.$c->field_avg_commute[LANGUAGE_NONE][0]['value'].' minutes to work each day. ';
    //'Its crime rate is index> higher/lower> than the national average. ';
    print printEthnicPercentages($c);
    print 'For more on schools, real estate, business and health care in '.$c->title.', see each of the tabs ';
    print '<span class="no-mobile">to the left</span><span class="mobile-only">above</span>. ';

    $fh = fopen(drupal_get_path('module','walkscore').DIRECTORY_SEPARATOR.'walkscore.csv','r');

    $fipsPlaceCode = $c->state->field_fips_state_code[LANGUAGE_NONE][0]['value'];
    if(strlen($c->field_place_id[LANGUAGE_NONE][0]['value'])<5){
        $fipsPlaceCode .= '0'.$c->field_place_id[LANGUAGE_NONE][0]['value'];
    }else{
        $fipsPlaceCode .= $c->field_place_id[LANGUAGE_NONE][0]['value'];
    }
    $walkscoreData = false;
    while($row = fgetcsv($fh)){
        if($fipsPlaceCode == $row[0]){
            //print_r($row);
            $walkscoreData = $row;
        }
    }
    if($walkscoreData !== false){
        $pieces = explode(' ',$c->title);
        $cityURL = $c->state->field_state_code[LANGUAGE_NONE][0]['value'].'/'.implode('_',$pieces);
        print 'Walkability can be a key driver of the overall livability of a community. ';
        print $c->title.' has a <a href="http://www.walkscore.com/'.
            $cityURL.'" target="_new"> Walk Score®</a> of <a href="http://www.walkscore.com/'.$cityURL.'" target="_new">'.number_format($walkscoreData[4],0).'</a>.';
    }
}



?>
        </p>
    </span>
<br style="clear:both;">
<ul class="clearfix infograph" style="clear:both;">
    <li class="one-third">
        <h4>Population</h4>
            <span class="medium-value">
                <?php if (!empty($node->field_population)){
                    print number_format($node->field_population[LANGUAGE_NONE][0]['value']);
                } elseif (!empty($c->census['city-data']['DP05_0001E'])){
                    print number_format($c->census['city-data']['DP05_0001E'],0);
                } else {
                    print 'n/a';
                } ?>
            </span>
    </li>
    <li class="one-third">
        <h4>Median Household Income</h4>
            <span class="medium-value">
                <?php if (!empty($node->field_median_household_income)){
                    print '$'.number_format($node->field_median_household_income[LANGUAGE_NONE][0]['value']);
                } elseif (!empty($c->census['city-data']['DP03_0062E'])){
                    print '$'.number_format($c->census['city-data']['DP03_0062E'],0);
                } else {
                    print 'n/a';
                } ?>
            </span>
    </li>
    <li class="one-third last">
        <h4>Median Home Price</h4>
            <span class="medium-value">
                <?php if (!empty($node->field_median_home_price)){
                    print '$'.number_format($node->field_median_home_price[LANGUAGE_NONE][0]['value']);
                } elseif (!empty($c->census['city-data']['DP04_0088E'])){
                    print '$'.number_format($c->census['city-data']['DP04_0088E'],0);
                } else {
                    print 'n/a';
                } ?>
            </span>
    </li>
</ul>
</div>
<?php
    if ($promoted) { print citySectionInclude('stubs/ad728middle'); }
    else {
        print citySectionInclude('stubs/promote-city');
    }
    

    $placeLevelTaxonomy = taxonomy_get_children(1);
    $thingsToDoTaxonomy = $placeLevelTaxonomy;
    $content = array();
    $terms = array();
    foreach($thingsToDoTaxonomy as $tid => $tax){
        $terms[] = $tax->name;
    }
    $getcount = 99;
    //if($promoted) { $getcount = 9; }
    $stuff = getContentByTermAndPlace($terms,$c, 0, $getcount);
    foreach($stuff['nodes'] as $things){
        $content[] = $things;
    }
    if(!empty($content)) {
      print citySectionInclude('stubs/content-cards',array('nodes'=>$content,'heading'=>'Articles Related to '.$c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'],'total'=>$stuff['total'],'cnid'=>$c->nid,'terms'=>$terms));
    }
    
    if ($promoted) { print citySectionInclude('stubs/ad728bottom'); } else { print citySectionInclude('stubs/ad728middle'); }
    
    $galleryNidQuery = new EntityFieldQuery();

    $galleryNidQuery->entityCondition('entity_type','node')->entityCondition('bundle','gallery');
    $galleryNidQuery->fieldCondition('field_gallery_city','target_id',$c->nid);
    $galleryNidResults = $galleryNidQuery->execute();
    if(isset($galleryNidResults) && count($galleryNidResults) == 1){
        $nid = array_keys($galleryNidResults['node']);
        $galleryNode = node_load($nid[0]);
        $items = $galleryNode->field_image[LANGUAGE_NONE];
        ?>
        <div class="photo-strip-container">
            <span class="heading">Photos of <strong><?php print $c->title.', '.$c->state->field_state_code[LANGUAGE_NONE][0]['value'];?></strong></span>
            <ul class="photo-strip rsDefault">
                <?php foreach ($items as $delta => $item): ?>

                    <span>
                      <img class="rsTmb" src="<?php print image_style_url('media_thumbnail', $item['uri']); ?>" data-link="/<?php print drupal_get_path_alias('node/'.$c->nid).'/photos?slide='.$delta;?>" style="width:100px;height:100px;float:left;" />
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
print citySectionInclude('stubs/category-cards', array('url' => $node_url, 'city' => $c->title, 'state' => $c->state->title));
if (isset($promoted)) {
  print citySectionInclude('stubs/ad728bottom');
};
print citySectionInclude('real-estate/block-listing');

?>
