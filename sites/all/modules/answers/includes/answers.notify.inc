<?php

/**
 * @file
 * Notification functionality for 'Answers' to inform users of answers.
 */

module_load_include('inc', 'answers', 'includes/answers.field_utils');

/**
 * Pseudo implementation of hook_node_insert().
 *
 * @see answers_node_insert()
 */
function _answers_notify_node_insert($node) {
  if ($node->type == 'answer' && variable_get('answers_new_answer_notice_allow_p', TRUE)) {
    $question = answers_field_get_node_reference($node, 'field_answer_question');
    if ($question->nid) {
      answers_notify_new_answer($question);
    }
  }
}

/**
 * If configured to, notify question author of an answer.
 *
 * @param object $question
 *   Numeric node NID of question.
 */
function answers_notify_new_answer($question) {
  $notify_p = answers_field_get_value($question, 'field_notify_p');

  if ($notify_p) {
    answers_notify('answers', $question, 'new_answer');
  }
}

/**
 * Send a notification.
 *
 * @param string $module
 *   Question node object.
 * @param object $question
 *   Question node object.
 * @param object $notification
 *   The type of notification.
 * @param array $starting_params
 *   Default settings to pass to drupal_mail().
 */
function answers_notify($module, $question, $notification, array $starting_params) {
  global $user;
  global $base_url;

  $question_author = user_load($question->uid);

  $params = array(
    '!question_user_name'  => $question_author->name,
    '!question_title'      => $question->title,
    '!question_url'        => url('node/' . $question->nid, array('absolute' => TRUE, 'target' => '_blank')),
    '!question_expiration' => date(DATE_RFC822, answers_field_get_value($question, 'field_question_expiration')),
    '!site'                => variable_get('site_name', 'drupal'),
    '!site_url'            => $base_url,
  );

  $params = array_merge($params, $starting_params);

  drupal_mail($module, $notification, $question_author->mail, user_preferred_language($question_author), $params);
}

/**
 * Implements hook_mail().
 */
function answers_mail($key, &$message, $params) {

  switch ($key) {
    case 'new_answer':
      $subject_template = variable_get('answers_new_answer_notice_subject', ANSWERS_DEFAULT_NEW_ANSWER_NOTICE_SUBJECT);
      $body_template = variable_get('answers_new_answer_notice_body', ANSWERS_DEFAULT_NEW_ANSWER_NOTICE_BODY);
      break;
  }

  answers_mail_helper($key, $message, $params, $subject_template, $body_template);
}

/**
 * Implements helper for answers_mail().
 */
function answers_mail_helper($key, &$message, $params, $subject_template, $body_template) {
  $langcode = $message['language']->language;
  $message['headers']['Content-Type'] = 'text/html; charset=UTF-8; format=flowed';
  if (!module_exists('mimemail')) {
    $message['headers']['Mime-Version'] = '1.0';
  }

  $message['subject'] = t(check_plain($subject_template), $params, array('langcode' => $langcode));
  $message['body'][] = t(filter_xss($body_template), $params, array('langcode' => $langcode));
}
