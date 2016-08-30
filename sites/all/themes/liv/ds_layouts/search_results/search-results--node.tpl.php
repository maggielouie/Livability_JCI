
<?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<?php if(!empty($top)):?>
<div class="search-snippet-title-wrapper">
	<div class="search-snippet-title"><?php print $top; ?></div>
</div>
<?php endif;?>

<?php if(!empty($left_above)):?>
    <?php print $left_above; ?>
<?php endif;?>

<?php if(!empty($right_above)):?>
    <?php print $right; ?>
<?php endif;?>

<?php if(!empty($middle)):?>
    <div class="search-snippet-info"><?php print $middle; ?></div>
<?php endif;?>

<?php if(!empty($left_below)):?>
    <?php print $left_below; ?>
<?php endif;?>

<?php if(!empty($right_below)):?>
    <?php print $right_below; ?>
<?php endif;?>

<?php if(!empty($bottom)):?>
    <div class="search-submitted"><?php print $bottom; ?></div>
<?php endif;?>

<?php if (!empty($drupal_render_children)): ?>
    <?php print $drupal_render_children ?>
<?php endif; ?>
