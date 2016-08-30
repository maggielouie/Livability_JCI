<?php
$c = city_node_load($node->nid);
?>
<?php 
// Top Leaderboard Ad block.
$ad = block_load('combo_ad_blocks', 'leaderboard_top');
$output = _block_get_renderable_array(_block_render_blocks(array($ad)));
print drupal_render($output);
?>
<div class="city-details padded clearfix">
    <span class="city-summary">
        <h1>State of <?php print $c->title.'</h1>';?>
        <p class="truncate-mobile-350">
      <?php print render($content['body']);

            $populusQuery = new EntityFieldQuery();            
            $populusQuery->entityCondition('entity_type','node')->entityCondition('bundle','city');
            $populusQuery->fieldCondition('field_state','target_id',$c->nid);
            $populusQuery->fieldOrderBy('field_population','value','DESC')->pager(4);
            $populusCitiesNids = $populusQuery->execute();
            $populusCity = array();
            foreach($populusCitiesNids['node'] as $nid=>$data){

                $populusCity[] = node_load($nid);
            }

            $expensiveQuery = new EntityFieldQuery();
            $expensiveQuery->entityCondition('entity_type','node')->entityCondition('bundle','city');
            $expensiveQuery->fieldCondition('field_state','target_id',$c->nid);
            $expensiveQuery->fieldOrderBy('field_median_home_price','value','DESC');
            $expensiveQuery->pager(5);
            $expensiveNids = $expensiveQuery->execute();
            $expensiveCitys = array();
            foreach($expensiveNids['node'] as $nid => $data){
                $expensiveCitys[] = node_load($nid);
            }

            $cheapQuery = new EntityFieldQuery();
            $cheapQuery->entityCondition('entity_type','node')->entityCondition('bundle','city');
            $cheapQuery->fieldCondition('field_state','target_id',$c->nid);
            $cheapQuery->fieldOrderBy('field_median_home_price','value','ASC');
            $cheapQuery->pager(5);
            $cheapNids = $cheapQuery->execute();
            $cheapCitys = array();
            foreach($cheapNids['node'] as $nid => $data){
                $cheapCitys[] = node_load($nid);
            }

            $statePopQuery = new EntityFieldQuery();
            $statePopQuery->entityCondition('entity_type','node')->entityCondition('bundle','state');
            $statePopQuery->fieldOrderBy('field_population','value','DESC');
            $statePop = $statePopQuery->execute();
            $statePopRank=1;
            foreach($statePop['node'] as $nid => $data){
                $state = node_load($nid);

                if($c->nid == $state->nid){
                    break;
                }
                $statePopRank++;
            }

            $nationalMedianIncome = 51371;
            $nationalMedianHomePrice = 180200;
            $incomeHigher = false;
            $income =$c->field_median_household_income[LANGUAGE_NONE][0]['amount'];
            if($income > $nationalMedianIncome){
                $incomeHigher = true;
                $incomePercDiff = number_format(($nationalMedianIncome/$income)*100,0);
            }else{
                $incomePercDiff = number_format(100-(($income/$nationalMedianIncome)*100),0);
            }
            // if someone adds text to the node body field then the default madlib will go away.
            if (empty($content['body'])) {
                print $c->title.' is the '.livHelper::ordinalSuffix($statePopRank).' populous state in the U.S. '.
                //'It is bordered by <list of neighboring states>. '.
                'The largest cities in '.$c->title.' are '.
                '<a href="/'.drupal_get_path_alias('node/'.$populusCity[0]->nid).'">'.$populusCity[0]->title.'</a>, '.
                '<a href="/'.drupal_get_path_alias('node/'.$populusCity[1]->nid).'">'.$populusCity[1]->title.'</a> and '.
                '<a href="/'.drupal_get_path_alias('node/'.$populusCity[2]->nid).'">'.$populusCity[2]->title.'</a>. '.
                'The median income for '.$c->title.' is $'.number_format($c->field_median_household_income[LANGUAGE_NONE][0]['amount'],0).
                ', which is '.$incomePercDiff.'% ';
                if($incomeHigher){
                    print 'higher';
                }else{
                    print 'lower';
                }
                //    higher/lower
                print ' than the national median income. '. //51371
                'The median home price in '.$c->title.' is $'.number_format($c->field_median_home_price[LANGUAGE_NONE][0]['value'],0).'. '.
                'The highest-priced homes are typically '.
                'found in '.
                '<a href="/'.drupal_get_path_alias('node/'.$expensiveCitys[0]->nid).'">'.$expensiveCitys[0]->title.'</a>, '.
                '<a href="/'.drupal_get_path_alias('node/'.$expensiveCitys[1]->nid).'">'.$expensiveCitys[1]->title.'</a> and '.
                '<a href="/'.drupal_get_path_alias('node/'.$expensiveCitys[2]->nid).'">'.$expensiveCitys[2]->title.'</a>. '.
                'The lowest-priced homes are in '.
                '<a href="/'.drupal_get_path_alias('node/'.$cheapCitys[0]->nid).'">'.$cheapCitys[0]->title.'</a>, '.
                '<a href="/'.drupal_get_path_alias('node/'.$cheapCitys[1]->nid).'">'.$cheapCitys[1]->title.'</a> and '.
                '<a href="/'.drupal_get_path_alias('node/'.$cheapCitys[2]->nid).'">'.$cheapCitys[2]->title.'</a>. ';
    //<city>, <city>, and <city.>'.
                // [jim, you can take this out if we don’t have it]
    
                //print $nationalMedianIncome.':'.$c->field_median_household_income[LANGUAGE_NONE][0]['amount'];
                //print $c->title.'’s cost of living is higher/lower than the national average by x%. '.
                //'If '.$c->title.' is on your relocation short-list, we recommend checking out these popular cities: '.
                //'<list of featured cities + cities with accolades like top 10s and top 100. as a fall back I guess we’d have to go random.>';
            }
            ?>
        </p>
    </span>
    <br style="clear:both;">
    <ul class="clearfix infograph" style="clear:both;">
        <li class="one-third">
            <h4>Population</h4>
            <span class="medium-value">
                <?php if(!empty($node->field_population)) {
                  print number_format($node->field_population[LANGUAGE_NONE][0]['value']);
                }else{
                    print 'n/a';
                } ?>
            </span>
        </li>
        <li class="one-third">
            <h4>Median Household Income</h4>
            <span class="medium-value">
                <?php if(!empty($node->field_median_household_income)){
                    print '$'.number_format($node->field_median_household_income[LANGUAGE_NONE][0]['value']);
                }else{
                    print 'n/a';
                } ?>
            </span>
        </li>
        <li class="one-third last">
            <h4>Median Home Price</h4>
            <span class="medium-value">
                <?php if(!empty($node->field_median_home_price)){
                    print '$'.number_format($node->field_median_home_price[LANGUAGE_NONE][0]['value']);
                }else{
                    print 'n/a';
                } ?>
            </span>
        </li>
    </ul>
</div>
<?php
// City Featured Image Slider.
print $featured_city_images;

// Middle Leaderboard Ad block.
$middlead = block_load('combo_ad_blocks', 'leaderboard_middle');
$middlead_output = _block_get_renderable_array(_block_render_blocks(array($middlead)));
print drupal_render($middlead_output);

// Article River.
print views_embed_view('state_content_cards','block');
?>
<div class="find">
<div class="states shadow-inset-tb ">
    <h1>Best Places to Live in <?php print $node->title;?></h1>
    <ul style="width: 100%;">
        <?php
        $citiesQuery = new EntityFieldQuery();
        $citiesQuery->entityCondition('entity_type','node')->entityCondition('bundle','city'); //->entityOrderBy('title');
        $citiesQueryResults = $citiesQuery->fieldCondition('field_state','target_id',$c->nid)->execute();
        //var_dump($citiesQueryResults);
        foreach($citiesQueryResults['node'] as $nid =>$data){
            //print $nid.'cb';
            $cn = node_load($nid);
            print '<li style="width:33%;"><a href="/'.drupal_get_path_alias('node/'.$cn->nid).'">'.$cn->title.'</a></li>';
        }
?>
    </ul>
</div>
</div>
<?php
print '</div>';