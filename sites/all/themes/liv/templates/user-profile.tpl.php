<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
// dsm($user_profile);
?>
<?php if ($user_profile['field_author_photo']['#view_mode'] == 'mini') : ?>

  <?php if (isset($user_profile['field_author_photo'])) :
    echo '<span class="headshot circle circle-65" style="background-image: url(\''.image_style_url('media_thumbnail', $user_profile['field_author_photo']['#object']->field_author_photo['und'][0]['uri']).'\')"></span>'; ?>
  <?php endif; ?>
      <h2><?php print l($variables['elements']['#account']->name, 'user/'.$variables['elements']['#account']->uid, array('attributes' => array('class' => array('name')))); ?></h2>
<?php else : ?>
  <span class="padded author">
  <?php if (isset($user_profile['field_user_bio']) && isset($user_profile['field_user_bio']['#object']->field_author_photo['und'])) :
    echo '<span class="headshot circle" style="background-image: url(\''.image_style_url('large', $user_profile['field_user_bio']['#object']->field_author_photo['und'][0]['uri']).'\')"></span>'; ?>
  <?php endif; ?>  
  <?php $account = menu_get_object('user'); $name = $account->name;
    echo '<h1>'.$name.'</h1>'; ?>                  
    <span class="bio">
      <?php print render($user_profile['field_user_bio']); ?>
      <?php if (isset($user_profile['field_user_facebook']) || isset($user_profile['field_user_twitter']) || isset($user_profile['field_user_google_plus']) || isset($user_profile['field_user_linked_in'])) : ?>
      <span class="social"><ul>
        <?php if (isset($user_profile['field_user_facebook'])) { ?>
          <li><a href="<?php print render($user_profile['field_user_facebook']); ?>" target="_blank"><img src="/<?php echo drupal_get_path('theme', 'liv'). '/images/icons/icon-facebook.png';?>" width=30 height=30 /></a></li>
        <?php } ?>
        <?php if (isset($user_profile['field_user_twitter'])) { ?>
          <li><a href="<?php print render($user_profile['field_user_twitter']); ?>" target="_blank"><img src="/<?php echo drupal_get_path('theme', 'liv'). '/images/icons/icon-twitter.png';?>" width=30 height=30 /></a></li>
        <?php } ?>
        <?php if (isset($user_profile['field_user_google_plus'])) { ?>
          <li><a href="<?php print render($user_profile['field_user_google_plus']); ?>" target="_blank"><img src="/<?php echo drupal_get_path('theme', 'liv'). '/images/icons/icon-google.png';?>" width=30 height=30 /></a></li>
        <?php } ?>
        <?php if (isset($user_profile['field_user_linked_in'])) { ?>
          <li><a href="<?php print render($user_profile['field_user_linked_in']); ?>" target="_blank"><img src="/<?php echo drupal_get_path('theme', 'liv'). '/images/icons/icon-linkedin.png';?>" width=30 height=30 /></a></li>
        <?php } ?>
      </ul></span>
      <?php endif; ?>
    </span>
    <br style="clear:both;" />
  </span>
<?php endif; ?>