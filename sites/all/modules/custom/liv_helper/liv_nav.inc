<?php

class liv_nav{
    function __construct($menu){
        $this->menu = $menu;
    }
    //array of at least link and title properties, icon optional
    function renderNavMenu($menu){
        $leftNav = '<div class="left-nav"><span class="drag-container"><ul class="all-categories">';
        foreach($menu as $name=>$attr){
            $leftNav .= '<li><a href="'.$attr['link'].'">';
            if(array_key_exists('icon',$attr)){
                $leftNav .= '<i class="icon-'.$attr['icon'].'"></i>';
            }
            $leftNav .= '<span>'.$attr['title'].'</span></a>';
            $leftNav .= '</li>';
        }
        $leftNav .= '</ul></span></div>';
        return $leftNav;
    }
    function renderNav(){
        $c = getCityContext();
        $leftNav = '<div class="left-nav"><span class="drag-container"><ul class="all-categories">';

        $this->bread = array();
        $this->bread[0] = l('Home','<front>');
        if(!$c){
            if(arg(0) == 'node'){
                $n = node_load(arg(1));
            }else{
                $n = new stdClass();$n->type = false;//dirty dirty trick
            }

      // Moving category page or article pages that belong to moving.
      if (strpos(request_uri(), '/moving') !== false & ($n->type == '' || $n->type == 'article')) {
        // This is global content.
        $globalContentMenu = array('home' =>
          array(
            'title' => 'Moving',
            'link' => '/moving',
            'icon' => 'flag'
          )
        );
        $v = views_get_view_result('moving_menu_list');
        foreach ($v as $k => $li) {
          $machineName = str_replace(' ', '-', strtolower($li->taxonomy_term_data_name));
          if ($n->type == 'article'){
            $ceid = $n->field_category[LANGUAGE_NONE][0]['value'];
            $catItem = entity_load('field_collection_item',array($ceid));
            $cid = $catItem[$ceid]->field_category_ref[LANGUAGE_NONE][0]['tid'];
            $tax = taxonomy_term_load($cid);
            $taxMachineName = str_replace(' ','-',strtolower($tax->name));
          }
          if (strpos(request_uri(), '/moving/' . $machineName) !== false || $n->type == 'article') {
            $this->bread[1] = l('Moving', 'moving');
          }
          if ($n->type == 'article' && $machineName == $taxMachineName){
            $this->bread[2] = l($tax->name, 'moving/' . $machineName);
          }
          if ($machineName == 'moving-tips') {
            $title = 'Moving Tips';
          }
          elseif ($machineName == 'how-to-guides') {
            $title = 'How To Guides';
          }
          elseif ($machineName == 'moving-checklists') {
            $title = 'Moving Checklists';
          }
          else {
            $title = $li->taxonomy_term_data_name;
          }
          $globalContentMenu[$k]['title'] = $title;
          $globalContentMenu[$k]['link'] = '/moving/' . $machineName;
          $globalContentMenu[$k]['icon'] = livability_article_get_icon($title);
        }
        drupal_set_breadcrumb($this->bread);

        // Append Best Places link.
        $globalContentMenu[] = array(
          'title' => 'Best Places To Live',
          'link' => '/best-places',
          'icon' => 'top10',
        );

        return self::renderNavMenu($globalContentMenu);
      }
      elseif ($n->type == 'article' || strpos(request_uri(), '/topics') !== false) {
        // This is global content.
                $globalContentMenu = array('home' =>
                    array(
                        'title'=>'Topics',
                        'link'=>'/topics',
                        'icon' => 'flag'
                    )
                );
                if($n->type == 'article'){
                    $ceid = $n->field_category[LANGUAGE_NONE][0]['value'];
                    $catItem = entity_load('field_collection_item',array($ceid));
                    $cid = $catItem[$ceid]->field_category_ref[LANGUAGE_NONE][0]['tid'];
                    $tax = taxonomy_term_load($cid);
                    $taxMachineName = str_replace(' ','-',strtolower($tax->name));
                }
                $v = views_get_view_result('topics_menu_list');
                foreach($v as $k => $li){
                    $machineName = str_replace(' ','-',strtolower($li->taxonomy_term_data_name));
                    if(strpos(request_uri(),'/topics/'.$machineName)!==false || $n->type == 'article'){
                        $this->bread[1] = l('Topics','topics');
                    }
                    if($n->type == 'article' && $machineName == $taxMachineName){
                        $this->bread[2] = l($tax->name,'topics/'.$machineName);
                    }
                    if($machineName == 'arts-and-entertainment'){
                        $title = 'Entertainment';
                    }elseif($machineName == 'business-and-economy'){
                        $title = 'Economy';
                    }elseif($machineName == 'education-and-schools')
                    {
                        $title = 'Schools';
                    }elseif($machineName == 'health-and-wellness'){
                        $title = 'Health';
                    }elseif($machineName == 'housing-and-real-estate'){
                        $title = 'Real Estate';
                    }else{
                        $title = $li->taxonomy_term_data_name;
                    }
                    $globalContentMenu[$k]['title'] = $title;
                    $globalContentMenu[$k]['link'] = '/topics/'.$machineName;
                    $globalContentMenu[$k]['icon'] = $machineName;
                }
                //print_r($this->bread);
                drupal_set_breadcrumb($this->bread);
                return self::renderNavMenu($globalContentMenu);
            }
            elseif($n->type == 'blog_post' || strpos(request_uri(),'blog') !== false){
                $blogMenu = array('a_index' => array(
                    'link' =>'/blog',
                    'title' =>'Blog Home',
                    'icon' => 'flag'
                ));
                $this->bread[1] = l('Blog','blog');
                if($n->type == 'blog_post'){
                    $cat = array_shift($n->field_blog_category[LANGUAGE_NONE][0]);
                    $category = taxonomy_term_load($cat);
                    //$parts = explode(' ',$category->name);

                    drupal_set_title($n->title);
                }
                $v = views_get_view_result('blog_menu_list');
                foreach($v as $k => $li){
                    $machineName = str_replace(' ','-',strtolower($li->taxonomy_term_data_name));
                    $blogMenu[$k]['title'] = $li->taxonomy_term_data_name;
                    $blogMenu[$k]['link'] = '/blog/'.$machineName;
                    $blogMenu[$k]['icon'] = $machineName;
                    if($machineName == 'city-amenities'){
                        $blogMenu[$k]['title'] = 'City Amenities';
                        $blogMenu[$k]['icon'] = 'entertainment';
                    }
                    if($n->type !== false && $li->taxonomy_term_data_name == $category->name){
                        $this->bread[2] = l($category->name,'blog/'.$machineName);
                    }
                }
                drupal_set_breadcrumb($this->bread);
                return self::renderNavMenu($blogMenu);
            }
        }
        // State pages.
        elseif (menu_get_object('node')->type == 'state'){
          $node = menu_get_object('node');
          // Home links.
          $globalContentMenu = array(array(
            'title' => 'Home',
            'link' => url('node/' . $node->nid),
            'icon' => 'flag',
          ));

          return self::renderNavMenu($globalContentMenu);
        }
        else{
            //we have a city context
            if(arg(0) == 'node'){
                $n = node_load(arg(1));
                if($n->type == 'article'){
                    $this->bread[2] = l($c->title,drupal_get_path_alias('node/'.$c->nid));
                }
            }
            else{
                $n = new stdClass();
                $n->type=false;
            }
            $galleryQuery = new EntityFieldQuery();
            $galleryQuery->entityCondition('entity_type','node')->entityCondition('bundle','gallery');
            $galleryQuery->fieldCondition('field_gallery_city','target_id',$c->nid);
            $galleryResults = $galleryQuery->execute();
            if(count($galleryResults) == 0){
                unset($this->menu['photos']);
            }
            $magQuery = new EntityFieldQuery();
            $magQuery->entityCondition('entity_type','node')->entityCondition('bundle','digital_magazine');
            $magQuery->fieldCondition('field_city','target_id',$c->nid);
            $magResults = $magQuery->execute();
            if(count($magResults) == 0){
                unset($this->menu['digital-magazine']);
            }
            $tids = excludedTids();

            $placeLevelTaxonomy = taxonomy_get_children(1);
            $found = array();
            foreach($placeLevelTaxonomy as $placeTerm){
                if(array_key_exists($placeTerm->tid,$tids)){ continue;}
                //todo join node so we can filter out unpublished here instead of things_to_do controller
                $q = 'select fc.*,n.status from field_data_field_category_ref c '.
                    'join field_data_field_category fc on c.entity_id=fc.field_category_value '.
                    'join field_data_field_place p on fc.entity_id=p.entity_id '.
                    'join field_data_field_place_ref pf on p.field_place_value=pf.entity_id '.
                    'join node n on n.nid=fc.entity_id '.
                    'where c.field_category_ref_tid=? and pf.field_place_ref_target_id=? and n.status=1 limit 1';
                $placeTermCheckQuery = db_query($q,array($placeTerm->tid,$c->nid));
                //print $placeTermCheckQuery->getQueryString();
                if($placeTermCheckQuery->rowCount()>0){
                    $ttdUrl = drupal_get_path_alias('node/'.$c->nid).'/things-to-do';
                    if(request_uri() == '/'.$ttdUrl){
                        drupal_set_title('Things To Do in '.$c->title);
                    }
                    elseif(strpos(request_uri(),'/'.$ttdUrl) !== false){
                        $this->bread[3] = l('Things To Do',$ttdUrl);
                    }
                    elseif(strpos(request_uri(),'/schools') !== false) {
                      $this->bread[3] = l('Public Schools', drupal_get_path_alias('node/'.$c->nid).'/schools');
                    }
                    elseif(strpos(request_uri(),'/real-estate') !== false) {
                      $this->bread[3] = l('Real Estate', drupal_get_path_alias('node/'.$c->nid).'/real-estate');
                    }
                    elseif(strpos(request_uri(),'/business') !== false) {
                      $this->bread[3] = l('Business', drupal_get_path_alias('node/'.$c->nid).'/business');
                    }
                    elseif(strpos(request_uri(),'/health') !== false) {
                      $this->bread[3] = l('Health', drupal_get_path_alias('node/'.$c->nid).'/health');
                    }
                    if(!isset($citySectionMenu['things-to-do']['submenu'])){ $citySectionMenu['things-to-do']['submenu'] = array();}
                    $found[] = $placeTerm->name;
                    $pieces = explode(' ',strtolower($placeTerm->name));
                    $url = implode('-',$pieces);
                    $parts = explode('/',request_uri());
                    if(request_uri() == $ttdUrl.'/'.$url){
                        $this->bread[4] = l($placeTerm->name,$ttdUrl.'/'.$url);
                    }
                    $this->menu['things-to-do']['submenu'][urlencode($url)] = array('title' => $placeTerm->name);
                }
            }
            if(count($found) == 0){
                unset($this->menu['things-to-do']);
            }
            $leftNav .= self::generateCityMenu();
        }
        $leftNav .= '</ul></span></div>';
        ksort($this->bread);
                        //print_r($this->bread);
        drupal_set_breadcrumb($this->bread);
        return $leftNav;
    }
    function generateCityMenu(){
        $c = getCityContext();
        $leftNav = '';
        if ($c->type != 'state') {
          $statePath = drupal_get_path_alias('node/'.$c->state->nid);
          $this->bread[1] = l($c->state->title,$statePath);
        }
        $cityPath = drupal_get_path_alias('node/'.$c->nid);
        if(arg(2) != null){
            $this->bread[2] = l($c->title,$cityPath);
        }

        foreach($this->menu as $name => $attr){
            $leftNav .= '<li';
            if($name == arg(2)){
                $leftNav .= ' class="active"';
                $bread[3] = l($attr['title'],$cityPath.'/'.$name);
            }
            $leftNav .= '><a href="/'.drupal_get_path_alias('node/'.$c->nid);

            if($name != 'home'){ $leftNav .= '/'.$name.'';}
            $leftNav .= '">';
            if(array_key_exists('icon',$attr)){
                $leftNav .= '<i class="icon-'.$attr['icon'].'"></i>';
            }
            $leftNav .= '<span>'.$attr['title'].'</span></a>';

            if(array_key_exists('submenu',$attr)){
                $leftNav .= '<ul class="level-1">';
                foreach($attr['submenu'] as $subName => $subAttr){
                    $leftNav .= '<li';
                    if(arg(3) == $subName){
                        $leftNav .= ' class="active"';
                    }
                    $leftNav .= '><a href="/'.drupal_get_path_alias('node/'.$c->nid).'/'.$name.'/'.$subName.'">'.$subAttr['title'].'</a></li>';
                }
                $leftNav .= '</ul>';
            }
            $leftNav .= '</li>';
        }
        return $leftNav;

    }
}
