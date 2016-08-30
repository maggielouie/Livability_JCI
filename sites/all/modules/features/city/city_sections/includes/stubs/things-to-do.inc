<?php

$heading = 'Articles for <b>'.$term.' in '.$c->title.', '.$c->state->field_state_code['und'][0]['value'].'</b>';
print citySectionInclude('stubs/content-cards',array('nodes'=>$nodes,'heading'=>$heading,'total'=>$total,'cnid'=>$c->nid,'terms'=>$term));
