<?php

function liv_things_to_do(){
    global $title;
    $c = getCityContext();
    if(arg(3) == null){
        //get all sections
        $title = 'Things to Do in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];
        $pageContent = '<div class="city-topic-summary padded">';
        $pageContent .= '<h1>'.$title.'</h1>';
        // $pageContent .= '<p>Like any community, there are plenty of great things to do in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'].'. Sometimes these events, attractions and restaurants are well known, while other times it takes a well-trained eye or local guide to introduce you to them. If you are looking for more variety, the more populous cities in '.$c->state->title.' are certain to accommodate your desires of activities.</p>';
        $pageContent .= '<p>'.$c->title.', '.$c->state->field_state_code['und'][0]['value'].' has many entertaining things to do, from attending special events, getting involved in the arts and learning about local history to dining at independent restaurants and staying active at area parks. Read on to explore the options.</p>';
        $pageContent .= citySectionInclude('stubs/ad728');
        $pageContent .= '</div>';
        $excluded = excludedTids();
        $placeLevelTaxonomy = taxonomy_get_children(1);
        $thingsToDoTaxonomy = array_diff_key($placeLevelTaxonomy,$excluded);
        $content = array();
        $terms = array();
        foreach($thingsToDoTaxonomy as $tid => $tax){
            $terms[] = $tax->name;
        }
        $stuff = getContentByTermAndPlace($terms,$c, 0);
        foreach($stuff['nodes'] as $things){
            $content[] = $things;
        }
        $termName = $stuff['term'];

/* UPDATED THE QUERY TO FACILITATE AJAX. MOVED SORT THERE
        foreach($content as $key => $node){
            $date[$key] = $node->changed;

        }
        array_multisort($date,SORT_DESC,$content);
*/
        $pageContent .= citySectionInclude('stubs/content-cards',array('nodes'=>$content,'heading'=>'','total'=>$stuff['total'],'cnid'=>$c->nid,'terms'=>$terms));

        return $pageContent;
    }
    if (!isset($termName)) {
      $pieces = explode('-',arg(3));
      $termName = implode(' ', $pieces);
    }
    $termName = preg_replace('/And/','and',ucwords($termName));
    $term = taxonomy_get_term_by_name($termName,'category');
    $term = array_pop($term);
    $content = getContentByTermAndPlace($termName,$c,0);
    $title = $termName .' in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'];

    $pageContent = '<div class="city-topic-summary padded">';
    $pageContent .= '<h1>'.$title.'</h1>';
    $pageContent .= '<p>';
    //todo join node sort by date or publish_date
    if($termName == 'Arts and Entertainment') {
        $pageContent .= 'The arts may be sacrificed by many public schools in the country, but that doesn’t mean that ' . $c->title . ' residents feel the loss. Through the opportunities available in the city, as well as those within their region of '.$c->state->title.', residents and visitors are certain to be fulfilled with the arts and and entertainment of the community.';
    } elseif($termName == 'Attractions') {
        //$pageContent .= 'Amongst the other various things to do, '.$c->title.' features several key attractions for both residents and visitors to keep themselves entertained. These, combined with the local and regional events, restaurants and shopping make '.$c->title.' and the surrounding region an inviting place to live.';
        $pageContent .= 'Many of the events and destinations that draw visitors to ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . ' and the surrounding region are also part of everyday life for locals, including popular restaurants, arts and cultural institutions and festivals. Below, read more about the area’s top attractions.';
    } elseif($termName == 'Events') {
        //todo nearby populus cities
        $pageContent .= 'Whether it be festivals, parades or other community gatherings, events in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . ' appear to happen pretty regularly, making them some of the more lively things to do in '.$c->title.'. If you are willing to make a drive, there are countless great events in the State of '.$c->state->title.'.';//, particularly in the more populated areas like [City 1] and [City 2].';
    } elseif($termName == 'Food and Drink') {
        //$pageContent .= 'Local and regional cuisine usually defines an area and '.$c->title.' is no different. Residents and visitors can enjoy a variety of restaurants in '.$c->title.' and the surrounding region, some featuring local flavors and farm-to-table recipes as well as wines and beers from around the State of '.$c->state->title.'.';
        $pageContent .= 'Among the quickest - and most enjoyable - ways to experience a town’s “local flavor” is to literally taste it by sampling local and regional cuisine at area restaurants. Read on for a variety of restaurants and signature dishes worth trying in ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . '.';
    } elseif($termName == 'Shopping') {
        //$pageContent .= 'Even with the amount of people shopping online these days, nothing really replaces the enjoyment of browsing local stores and and products. '.$c->title.' offers a variety of shopping venues for residents and visitors, with many more available within a short drive.';
        $pageContent .= 'With a mix of independent shops to national retailers ' . $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . ' has a variety of shopping options, whether you’re seeking boutique fashions, local products or life’s essentials. Read more below to learn more about where to shop.';
    } elseif($termName == 'Sports and Recreation') {
        //$pageContent .= 'Kids and adults alike have an array of sports and recreation opportunities near '.$c->title.', '.$c->state->field_state_code['und'][0]['value'].' including school and youth sports, public parks and places to both walk and bike. Branching out a bit further in '.$c->state->title.' allows residents to experience professional and semi-pro sports teams.';
        $pageContent .= $c->title . ', ' . $c->state->field_state_code['und'][0]['value'] . ' has many opportunities for people who enjoy sports and recreation, including school and youth sports, public parks and places for biking and walking. Read more for details about residents’ favorite places for fitness and fun.';
    }
    $pageContent .= '</p>';
    if(count($content['featured']) > 0){
        $images = array();
        foreach($content['featured'] as $nid){
            $node = $content['nodes'][$nid];
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
        $pageContent .= new liv_slider($images,'hero');
    }
    $pageContent .= citySectionInclude('stubs/ad728');
    $pageContent .= '</div>';
    $pageContent .= citySectionInclude('stubs/things-to-do',array('nodes'=>$content['nodes'],'featured'=>$content['featured'],'term' =>$content['term'],'c'=>$c,'total'=>$content['total']));
    drupal_set_title($title);
    return $pageContent;
}