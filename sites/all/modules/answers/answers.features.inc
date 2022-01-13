<?php

/**
 * @file
 * answers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function answers_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function answers_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function answers_node_info() {
  $items = array(
    'answer' => array(
      'name' => t('!Answer', answers_translation()),
      'base' => 'node_content',
      'description' => t('An !answer provided to !question asked by a member of the community', answers_translation()),
      'has_title' => '1',
      'title_label' => t('!Answer', answers_translation()),
      'help' => '',
    ),
    'question' => array(
      'name' => t('!Question', answers_translation()),
      'base' => 'node_content',
      'description' => t('A !question which can be answered by other users', answers_translation()),
      'has_title' => '1',
      'title_label' => t('!Question', answers_translation()),
      'help' => '',
    ),
  );
  return $items;
}
