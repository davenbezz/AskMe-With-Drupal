<?php

/**
 * @file
 * Form utility functions for the 'Answers' module.
 */

/**
 * Returns the form definition for answers administer page.
 */
function answers_settings() {
  $form = array();

  $form['additional_settings'] = array(
    '#type' => 'vertical_tabs',
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'answers') . '/js/answers_admin.js'),
    ),
  );

  $form['display'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Display'),
    '#weight' => -100,
    '#group' => 'additional_settings',
  );

  $form['display']['answers_redirect_from_answer_to_question_nodes_p'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Redirect paths from answers to questions'),
    '#default_value' => variable_get('answers_redirect_from_answer_to_question_nodes_p', TRUE),
    '#description'   => t('This will redirect from showing answer nodes in page view to instead showing the question node in page view, scrolling down to the answer. (Recommended)'),
  );

  $form['display']['answers_hide_question_reference_field'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Hide %field field', array('%field' => 'answer to question')),
    '#default_value' => variable_get('answers_hide_question_reference_field', TRUE),
    '#description'   => t('This will hide the %field field when users create an answer to a question.', array('%field' => 'answer to question')),
  );

  $form['notification'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Notification'),
    '#weight' => -50,
    '#group' => 'additional_settings',
  );

  $form['notification']['answers_new_answer_notice_allow_p'] = array(
    '#type' => 'checkbox',
    '#title' => t('Give users the option to be notified'),
    '#default_value' => variable_get('answers_new_answer_notice_allow_p', TRUE),
    '#description' => t('If disabled, users will not be offered the option to receive notifications. Also, any new answers to questions will not trigger notifications, even if their authors had previously requested notification.'),
  );

  $form['notification']['answers_new_answer_notice_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject line'),
    '#default_value' => variable_get('answers_new_answer_notice_subject', ANSWERS_DEFAULT_NEW_ANSWER_NOTICE_SUBJECT),
    '#description' => t('Dynamic variables available: !question_user_name, !answer_user_name, !question_title, !question_url, !site and !site_url'),
    '#required' => TRUE,
  );

  $form['notification']['answers_new_answer_notice_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('answers_new_answer_notice_body', ANSWERS_DEFAULT_NEW_ANSWER_NOTICE_BODY),
    '#description' => t('Dynamic variables available: !question_user_name, !answer_user_name, !question_title, !question_url, !site and !site_url'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Returns the form definition for answers administer page.
 */
function answers_branding_form() {
  $form = array();

  $form['question'] = array(
    '#type' => 'fieldset',
    '#title' => t('Questions'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['question']['answers_question_create_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Create'),
    '#description' => t('Word for <em>Save</em>'),
    '#default_value' => variable_get('answers_question_create_button_text', t('Ask Your Question')),
  );

  $form['question']['answers_question_edit_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Update'),
    '#description' => t('Word for <em>Save</em>'),
    '#default_value' => variable_get('answers_question_edit_button_text', t('Update Your Question')),
  );

  $form['question']['answers_trans_ucquestions'] = array(
    '#type' => 'textfield',
    '#title' => t('Questions'),
    '#description' => t('Word to use in the interface for the upper case plural word !Questions', answers_translation()),
    '#default_value' => variable_get('answers_trans_ucquestions', 'Questions'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['question']['answers_trans_lcquestions'] = array(
    '#type' => 'textfield',
    '#title' => t('questions'),
    '#description' => t('Word to use in the interface for the lower case plural word !questions', answers_translation()),
    '#default_value' => variable_get('answers_trans_lcquestions', 'questions'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['question']['answers_trans_ucquestion'] = array(
    '#type' => 'textfield',
    '#title' => t('Question'),
    '#description' => t('Word to use in the interface for the upper case singular word !Question', answers_translation()),
    '#default_value' => variable_get('answers_trans_ucquestion', 'Question'),
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['question']['answers_trans_lcquestion'] = array(
    '#type' => 'textfield',
    '#title' => t('question'),
    '#description' => t('Word to use in the interface for the lower case singular word !question', answers_translation()),
    '#default_value' => variable_get('answers_trans_lcquestion', 'question'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['answer'] = array(
    '#type' => 'fieldset',
    '#title' => t('Answers'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['answer']['answers_answer_create_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Create'),
    '#description' => t('Word for <em>Save</em>'),
    '#default_value' => variable_get('answers_answer_create_button_text', t('Post Your !Answer'), answers_translation()),
  );

  $form['answer']['answers_answer_edit_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Update'),
    '#description' => t('Word for <em>Save</em>'),
    '#default_value' => variable_get('answers_answer_edit_button_text', t('Update Your !Answer', answers_translation())),
  );

  $form['answer']['answers_trans_ucanswers'] = array(
    '#type' => 'textfield',
    '#title' => t('Answers'),
    '#description' => t('Word to use in the interface for the upper case plural word !Answers', answers_translation()),
    '#default_value' => variable_get('answers_trans_ucanswers', t('Answers')),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['answer']['answers_trans_lcanswers'] = array(
    '#type' => 'textfield',
    '#title' => t('answers'),
    '#description' => t('Word to use in the interface for the lower case plural word !answers', answers_translation()),
    '#default_value' => variable_get('answers_trans_lcanswers', 'answers'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['answer']['answers_trans_ucanswer'] = array(
    '#type' => 'textfield',
    '#title' => t('Answer'),
    '#description' => t('Word to use in the interface for the upper case singular word !Answer', answers_translation()),
    '#default_value' => variable_get('answers_trans_ucanswer', 'Answer'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form['answer']['answers_trans_lcanswer'] = array(
    '#type' => 'textfield',
    '#title' => t('answer'),
    '#description' => t('Word to use in the interface for the lower case singular word !answer', answers_translation()),
    '#default_value' => variable_get('answers_trans_lcanswer', 'answer'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'answers_branding_form_submit';

  return $form;
}

/**
 * Answers Brnading form submit function.
 *
 * @param array $form
 *   Form array.
 * @param mixed $form_state
 *   Form State.
 */
function answers_branding_form_submit(array $form, $form_state) {
  drupal_flush_all_caches();
}
