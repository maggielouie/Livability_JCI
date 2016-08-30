<?php
print '<div class="articles padded grey-bg three-wide shadow-inset-lr" id="related_articles">';
print '<span class="heading">'.$heading.'</span>';
print '<span class="articles-content">';
print '<ul class="clearfix article-slider" id="'.$cnid;
if (isset($terms)) {
  if (is_array($terms)) {
    foreach($terms as $term) {
      print '-'.$term;
    }
  }
  else {
    print '-'.$terms;
  }
}
print '">';
foreach($nodes as $node){
    $view = node_view($node,'teaser');
    print '<li class="one-third">';
    print '<span class="image-icon">';
    print '<a href="/'.drupal_get_path_alias('node/'.$node->nid).'">';
    if(isset($node->field_image[LANGUAGE_NONE])){
        print '<img src="'.image_style_url('325x216', $node->field_image[LANGUAGE_NONE][0]['uri']).'">';
    } elseif (isset($node->field_article_thumbnail[LANGUAGE_NONE])) {
        print '<img src="'.image_style_url('325x216', $node->field_article_thumbnail[LANGUAGE_NONE][0]['uri']).'">';
    } else {
        print '<img src="/sites/all/themes/liv/images/325x216.jpg">';
    }
    print '</a>';
    $fi = entity_load('field_collection_item',$node->field_category[LANGUAGE_NONE][0]);
    $fi = array_shift($fi);
    $tid = $fi->field_category_ref[LANGUAGE_NONE][0]['tid'];
    $tax = taxonomy_term_load($tid);
    $pieces = explode(' ',strtolower($tax->name));
    $icon = implode('-',$pieces);
    /*
    print '<span class="circle-icon"><span class="sticker-orange-horizontal"><i class="icon-'.$icon.' white"></i>';
    print '</span></span>';
    print '</span>';
    */

    print '<span class="summary">';
    print '<h2><a href="/'.drupal_get_path_alias('node/'.$node->nid).'">'.$node->title.'</a></h2>';
    if (!empty($node->field_sponsor_name)) {
      print '<span style="color:#7cc242;text-transform:uppercase;font-size:0.724rem;font-weight: bold;position:absolute;margin-top:5px;">Sponsored by '.$node->field_sponsor_name['und'][0]['value'].'</span>';
    }
/*    print '<p class="no-mobile">'.strip_tags($view['body'][0]['#markup']).'</p>';
    print citySectionInclude('stubs/interact');
    print '</span>'; */
    print '</li>';
}
print '</ul>';
print '</span>';
print '</div>';
// if (count($nodes) < $total) {
//   print '<div class="show-more shadow-inset-lr" id="seemore" data="'.$total.'"><a href="" class="show-more-link">Show more articles <i class="icon-arrow-down-double white"></i></a></div>';
// }
print '<div class="show-more shadow-inset-lr" id="back-top"><a href="#header" class="">Back to Top <i class="icon-arrow-up-double white"></i></a></div>';

print citySectionInclude('stubs/ad728bottom');