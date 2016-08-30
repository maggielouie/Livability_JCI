This module is dependent of ahah_helper module. However it is also necessary to
add the following patch to ahah_helper.module

http://drupal.org/files/ahah_helper-submit-1231140-12.patch

The patch allows to keep the $form_state to keep a non ahah submit handler.