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
?>
<?php if (isset($user_profile['field_user_bio']) && isset($user_profile['field_user_bio']['#object']->field_author_photo['und'])) :
  echo '<span class="headshot circle" style="background-image: url(\''.image_style_url('large', $user_profile['field_user_bio']['#object']->field_author_photo['und'][0]['uri']).'\')"></span>'; ?>
<?php endif; ?>  
<?php if (isset($user_profile['field_user_bio'])) : ?>
  <span class="bio clearfix">
    <?php print l($user_profile['field_user_bio']['#object']->name, 'user/'.$user_profile['field_user_bio']['#object']->uid, array('attributes' => array('class' => array('name')))); ?>
    <?php if (isset($user_profile['field_professional_title'])) { print '<span class="title">'; print render($user_profile['field_professional_title']); print '</span>';} ?>
    <?php print render($user_profile['field_user_bio']); ?>
    <?php $seemo = html_entity_decode('More&hellip;'); ?>
    <?php print l($seemo, 'user/'.$user_profile['field_user_bio']['#object']->uid, array('attributes' => array('class' => array('name')))); ?>
  </span>
<?php endif; ?>
