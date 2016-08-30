<?php
$path = check_plain($_SERVER['REQUEST_URI']);
// print $path ."<br/>";
if (!isset($custompath)) {
// Some magic to deliver the preserve comments from content created pre-migration
  if (isset($node) && $node->created < 1409292005) {
    $query = db_query('SELECT source from redirect where redirect = CONCAT(\'node/\', ' . $node->nid .') order by rid DESC')->fetchAll();
    if(!empty($query)) {
    $nodie = strpos($query[0]->source, 'node');
      if (FALSE !== $nodie) {
        $aliasquery = db_query('SELECT alias from url_alias where source = \'' . $query[0]->source .'\' order by pid DESC')->fetchAll();
        $path = $aliasquery[0]->alias;
      }
      else {
        $path = $query[0]->source;
      }
    }
  } else {
    if(arg(0) == 'top-10' && null !== arg(1)) {
      $curview = views_get_page_view();
      if (isset($curview->result[0]->field_list_item_field_collection_item_nid)) {
        $basenode = node_load($curview->result[0]->field_list_item_field_collection_item_nid);
        if($basenode->created < 1409292005) {
          $query = db_query('SELECT source from redirect where redirect = CONCAT(\'node/\', ' . $basenode->nid .') order by rid DESC')->fetchAll();
          if(!empty($query)) {
            $nodie = strpos($query[0]->source, 'node');
            if (FALSE !== $nodie) {
              $aliasquery = db_query('SELECT alias from url_alias where source = \'' . $query[0]->source .'\' order by pid DESC')->fetchAll();
              $path = $aliasquery[0]->alias;
            }
            else {
              $path = $query[0]->source;
            }
          }
        }
        $path .= arg(5);
        if(isset($page)) {
          $pagecontent = $page['content']['system_main']['main']['#markup'];
          preg_match("/<strong class=\"green\">(.*)<\/strong>/", $pagecontent, $matches);
          if (isset($matches[1])) {
            $path .= strtolower($matches[1]);
          }
        }
        else {
          $state = node_load($curview->result[0]->_field_data['item_id']['entity']->field_city['und'][0]['entity']->field_state['und'][0]['target_id']);
          $path .= strtolower($state->field_state_code['und'][0]['value']);
        }
      }
    }
  }

  // $path = $_SERVER['SERVER_NAME'] . $path;
  $path = 'livability.com' . $path;
  $custompath = $path;
}
?>

<div class="addthis_custom_sharing" data-url="http://<?php print $custompath; ?>" ></div><br style="clear:both;"/>
