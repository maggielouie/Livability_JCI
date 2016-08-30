<div class="articles grey-bg padded">
      <?php print $content; ?>
</div>
<?php $path = explode('/', $_SERVER['REQUEST_URI']); ?>
<div class="show-more shadow-inset-lr"><a href="/<?php echo $path[1].'/'.$path[2].'/things-to-do'?> " class="show-more-link">Show more posts <i class="icon-arrow-down-double white"></i></a></div>