<?php

/**
 * @file
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>

<?php if (isset($user_profile['field_author_photo'])) :
  echo '<span class="headshot circle circle-65" style="background-image: url(\''.image_style_url('media_thumbnail', $user_profile['field_author_photo']['#object']->field_author_photo['und'][0]['uri']).'\')"></span>'; ?>
<?php endif; ?>
    <h2><?php print l($variables['elements']['#account']->name, 'user/'.$variables['elements']['#account']->uid, array('attributes' => array('class' => array('name')))); ?></h2>
