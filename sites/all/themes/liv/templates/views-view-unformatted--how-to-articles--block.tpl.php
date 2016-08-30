<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<h3>How To Articles</h3>
<ul>
<?php foreach ($rows as $id => $row): ?>
  <li>
    <?php print $row; ?>
  </li>
<?php endforeach; ?>
</ul>