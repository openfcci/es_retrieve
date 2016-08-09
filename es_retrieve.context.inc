<?php

/**
 * @file
 * es_retrieve.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function es_retrieve_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  //$context->name = 'search_includes';
  $context->name = 'elastic_search';
  $context->description = 'Display elastic search on the search results page.';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'retrieve/*' => 'retrieve/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'retrieve-elastic_search_results_count' => array(
          'module' => 'es_retrieve',
          'delta' => 'elastic_search_results_count',
          'region' => 'content',
          'weight' => '-5',
        ),
        'retrieve-elastic_search_modify_results' => array(
          'module' => 'es_retrieve',
          'delta' => 'elastic_search_modify_results',
          'region' => 'content',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display elastic search on the search results page.');
  $export['elastic_search'] = $context;

  return $export;
}
