# context_entity_terms
--------------------
Extend the Context Taxonomy Node Condition plugin (context_condition_node_taxonomy) to find terms referenced by entityreference.

What it does
------------

It's becoming more common (and it's totally valid) to add taxonomy fields to Drupal Content Types as entityreference field types, rather than using the traditonal term_reference field type.  A caveat to doing this, however, is the loss of common functionality for using terms, in this case, as a Context condition.

This module adds a Context condition that will find terms in nodes that are entityreferenced.

Installation
------------
Just put this module in your site's modules folder, then enable.

Requirements
------------
Requires EntityReference module (because without that you won't have any entityreference fields).
