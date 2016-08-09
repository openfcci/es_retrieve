<?php

/**
 * @file
 * es_retrieve.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function es_retrieve_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_node_info().
 */
function es_retrieve_node_info() {
  $items = array(
    'elastic_search_include' => array(
      'name' => t('Elastic Search Include'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a new elastic search include.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This title is displayed on the elastic search include block on the search results page.'),
    ),
  );
  return $items;
}
