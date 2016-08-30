<?php
/**
 * @file
 * rules_publishing.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rules_publishing_default_rules_configuration() {
  $items = array();
  $items['rules_publish'] = entity_import('rules_config', '{ "rules_publish" : {
      "LABEL" : "Publish",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "views_bulk_operations", "rules" ],
      "ACTION SET" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : { "view" : "articles_to_be_published|block_1" },
            "PROVIDE" : { "entity_list" : { "unpublished_nodes" : "Unpublished Nodes" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "unpublished-nodes" ] },
            "ITEM" : { "node" : "Node" },
            "DO" : [
              { "node_publish" : { "node" : [ "node" ] } },
              { "data_set" : { "data" : [ "node:created" ], "value" : "now" } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_publish_now'] = entity_import('rules_config', '{ "rules_publish_now" : {
      "LABEL" : "Publish now",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_publish_now" } },
        { "NOT data_is_empty" : { "data" : [ "node:field-publish-now" ] } }
      ],
      "DO" : [
        { "node_publish" : { "node" : [ "node" ] } },
        { "data_set" : { "data" : [ "node:field-publish-now" ], "value" : 0 } }
      ]
    }
  }');
  $items['rules_publish_now_set'] = entity_import('rules_config', '{ "rules_publish_now_set" : {
      "LABEL" : "Publish Now Set",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_publish_now" } },
        { "data_is" : { "data" : [ "node:field-publish-now" ], "value" : 1 } }
      ],
      "DO" : [ { "component_rules_publish_now" : { "node" : [ "node" ] } } ]
    }
  }');
  $items['rules_publish_unpublished_content'] = entity_import('rules_config', '{ "rules_publish_unpublished_content" : {
      "LABEL" : "Publish unpublished content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules_switch_user", "rules" ],
      "ON" : { "cron" : [] },
      "DO" : [
        { "rules_switch_user_action_switch_to" : { "account" : "1" } },
        { "component_rules_publish" : [] },
        { "rules_switch_user_action_switch_back" : [] }
      ]
    }
  }');
  $items['rules_unpublish_scheduled_content'] = entity_import('rules_config', '{ "rules_unpublish_scheduled_content" : {
      "LABEL" : "Unpublish Scheduled Content",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "4" : "4" } }
              }
            },
            { "AND" : [
                { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_publish_on" } },
                { "NOT data_is_empty" : { "data" : [ "node:field-publish-on" ] } },
                { "data_is" : {
                    "data" : [ "node:field-publish-on" ],
                    "op" : "\\u003E",
                    "value" : "+30 seconds"
                  }
                }
              ]
            }
          ]
        }
      ],
      "DO" : [ { "node_unpublish" : { "node" : [ "node" ] } } ]
    }
  }');
  $items['rules_unpublish_scheduled_content_rule'] = entity_import('rules_config', '{ "rules_unpublish_scheduled_content_rule" : {
      "LABEL" : "Unpublish Scheduled Content",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave" : [] },
      "DO" : [
        { "component_rules_unpublish_scheduled_content" : { "node" : [ "node" ] } }
      ]
    }
  }');
  return $items;
}
