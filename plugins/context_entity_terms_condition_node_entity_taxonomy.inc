<?php
/**
 * @file
 * Extends context_condition_node_taxonomy class
 *
 * Allows checking taxonomy terms on nodes including those by entityreference.
 *
 */

 /**
 * Expose entity referenced node taxonomy terms as a context condition.
 */
class context_entity_terms_condition_node_entity_taxonomy extends context_condition_node_taxonomy {

  function execute($node, $op) {
    // build a list of each entityreference taxonomy field belonging to the bundle for the current node.
    $fields = field_info_fields();
    $instance_fields = field_info_instances('node', $node->type);
    $check_fields = array();
    foreach ($instance_fields as $key => $field_info) {
      if ($fields[$key]['type'] == 'entityreference') {
        $check_fields[] = $key;
      }
    }

    if ($this->condition_used() && !empty($check_fields)) {
      foreach ($check_fields as $field) {
        if ($terms = field_get_items('node', $node, $field)) {
          foreach ($terms as $term) {
            foreach ($this->get_contexts($term['target_id']) as $context) {
              // Check the node form option.
              if ($op === 'form') {
                $options = $this->fetch_from_context($context, 'options');
                if (!empty($options['node_form'])) {
                  $this->condition_met($context, $term['target_id']);
                }
              }
              else {
                $this->condition_met($context, $term['target_id']);
              }
            }
          }
        }
      }
    }
  }
}
