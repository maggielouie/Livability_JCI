<?php print $wrapper_prefix; ?>
<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
  <?php
  $group_nr = 1;
  $last_row = count($rows) -1;
  $wrapper  = 5;
  ?>
  <?php foreach ($rows as $id => $row): ?>
    <?php if ($id % $wrapper == 0) {print '<div id="group-'.$group_nr.'">'; $i = 0; $group_nr++; } ?>
    <div class="<?php print $options['row_class']; ?>">
      <?php print $row; ?>
    </div>
    <?php $i++; if ($i == $wrapper || $id == $last_row) print '</div>'; ?>
  <?php endforeach; ?>
<?php print $wrapper_suffix; ?>