<?php
  $ytlink = $output;
  $ytid = substr($ytlink, strpos($ytlink, "=") + 1);
?>
<div class="embed-responsive embed-responsive-16by9">
  <iframe width="560" height="315" src="https://www.youtube.com/embed/<?php print $ytid; ?>" frameborder="0" allowfullscreen></iframe>
</div>