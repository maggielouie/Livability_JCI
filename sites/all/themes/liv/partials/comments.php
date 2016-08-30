<?php
$path = check_plain($_SERVER['REQUEST_URI']);
// print $path ."<br/>";
// Some magic to deliver the preserve comments from content created pre-migration
if (isset($node) && $node->created < 1409292005) {
  $query = db_query('SELECT source from redirect where redirect = CONCAT(\'node/\', ' . $node->nid .') order by rid DESC')->fetchAll();
  if(!empty($query)) {
  $nodie = strpos($query[0]->source, 'node');
    if (FALSE !== $nodie) {
      $aliasquery = db_query('SELECT alias from url_alias where source = \'' . $query[0]->source .'\' order by pid DESC')->fetchAll();
      $path = '/'. $aliasquery[0]->alias;
    }
    else {
      $path = '/'.$query[0]->source;
    }
  }
}
else {
  if(arg(0) == 'best-places' && arg(1) == 'top-10' && null !== arg(2) && null !== arg(3)) {
    $curview = views_get_page_view();
    $basenode = node_load($curview->result[0]->field_list_item_field_collection_item_nid);
    if(is_object($basenode) && $basenode->created < 1409292005) {
      $query = db_query('SELECT source from redirect where redirect = CONCAT(\'node/\', ' . $basenode->nid .') order by rid DESC')->fetchAll();
      if(!empty($query)) {
        $nodie = strpos($query[0]->source, 'node');
        if (FALSE !== $nodie) {
          $aliasquery = db_query('SELECT alias from url_alias where source = \'' . $query[0]->source .'\' order by pid DESC')->fetchAll();
          $path = '/'. $aliasquery[0]->alias;
        }
        else {
          $path = '/'.$query[0]->source;
        }
      }
    }
    else {
/*      $path .= '/'.arg(5);
      $pagecontent = $page['content']['system_main']['main']['#markup'];
      preg_match("/<strong class=\"green\">(.*)<\/strong>/", $pagecontent, $matches);
      if (isset($matches[1])) {
        $path .= '/'.strtolower($matches[1]);
      } */
    }
  }
}
// $path = $_SERVER['SERVER_NAME'] . $path;
$path = 'livability.com' . $path;
//print $path .'<br/>';
$custompath = $path;

?>
<span class="padded comments">
	<span class="summary">
		<span class="title">
			<i class="comments-green"></i>
			<span class="count"><fb:comments-count href=http://<?php print $path; ?>></fb:comments-count></span> Reader Comments
		</span>
		<span class="description">
			Use a Facebook account to comment. Subject to Facebook's <a href="https://www.facebook.com/policies/" target="_blank">Terms of Service</a> and <a href="https://www.facebook.com/about/privacy/" target="_blank">Privacy Policy</a>. Your Facebook name, photo other personal information you make public on Facebook will appear with your comment.
		</span>
		<div id="fb-root"></div><script src="http://connect.facebook.net/en_US/all.js#appId=266785933857&amp;xfbml=1"></script><fb:comments href="http://<?php print $path;?>" data-notify="true" num_posts="3" width="100%"></fb:comments>
	</span>
</span>
