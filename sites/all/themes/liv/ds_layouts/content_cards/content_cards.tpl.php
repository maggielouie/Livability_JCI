
<?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
<?php endif;

$pieces = explode(' ',trim($category));
print '<span class="image-icon">';
if(!empty($top)){
    print $top;
}else{
    print '<img src="/sites/all/themes/liv/images/325x216.jpg">';
}


print '<span class="circle-icon">';
print '<span class="sticker-orange-horizontal"> ';
print '<i class="icon-'.strtolower(implode('-',$pieces)).' white"></i>';
print '</span></span>';
print '</span>';
?>

<span class="summary">
<?php
if(!empty($title)):
 print $title;
endif;
if(!empty($summary)):
    print '<p class="no-mobile">';
        print strip_tags($summary);
    print '</p>';
endif;?>
</span>

<?php if(!empty($left_below)):?>
    <?php print $left_below; ?>
<?php endif;?>

<?php if(!empty($right_below)):?>
    <?php print $right_below; ?>
<?php endif;?>

<?php if(!empty($bottom)):?>
    <?php print $bottom; ?>
<?php endif;?>

<?php if (!empty($drupal_render_children)): ?>
    <?php print $drupal_render_children ?>
<?php endif; ?>
