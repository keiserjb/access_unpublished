<?php
/**
 * @file
 * Admin page callbacks for Access unpublished.
 */

/**
 * Form constructor for system setting.
 */
function access_unpublished_url_param_form($form) {
  $form['access_unpublished_url_key'] = array(
    '#type' => 'textfield',
    '#title' => t('URL hash parameter'),
    '#default_value' => config_get('access_unpublished.settings', 'access_unpublished_url_key'),
    '#description' => t('Set the URL parameter for hashed key, 
      for example: http://example.com/node/1?<strong>hash</strong>=abc..., 
      example.com/node/1?<strong>key</strong>=abc...'),
    '#maxlength' => 20,
    '#size' => 10,
  );
  $form['access_unpublished_display_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display hashed link to unpublished node in:'),
  );
  $form['access_unpublished_display_link']['access_unpublished_display_link_in_message'] = array(
    '#type' => 'checkbox',
    '#title' => t('Drupal message'),
    '#default_value' => config_get('access_unpublished.settings', 'access_unpublished_display_link_in_message'),
  );
  $form['access_unpublished_display_link']['access_unpublished_display_link_in_node_content'] = array(
    '#type' => 'checkbox',
    '#title' => t('Node content'),
    '#description' => t('Use template access-unpublished-link.tpl.php 
      and access_unpublished.css for custom design.'),
    '#default_value' => config_get('access_unpublished.settings', 'access_unpublished_display_link_in_node_content'),
  );
  // Add a submit button
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Form validation handler for access_unpublished_url_param_form().
 *
 * Pass only ASCII characters.
 * At least one display option must be checked.
 */
function access_unpublished_url_param_form_validate($form, &$form_state) {
  $access_unpublished_url_key = $form_state['values']['access_unpublished_url_key'];
  if (preg_match('/^[a-zA-Z0-9]+$/', $access_unpublished_url_key) != 1) {
    form_set_error('access_unpublished_url_key', t('Only ASCII characters can be used as URL key'));
  }

  if (!$form_state['values']['access_unpublished_display_link_in_message']
    && !$form_state['values']['access_unpublished_display_link_in_node_content']) {
    form_set_error('access_unpublished_display_link', t('At least one display option must be checked.'));
  }
}

/**
 * Submit handler for module_settings_form().
 */
function access_unpublished_url_param_form_submit($form, &$form_state) {
  $config = config('access_unpublished.settings');
  $config->set('access_unpublished_url_key', $form_state['values']['access_unpublished_url_key']);
  $config->set('access_unpublished_display_link_in_message', $form_state['values']['access_unpublished_display_link_in_message']);
  $config->set('access_unpublished_display_link_in_node_content', $form_state['values']['access_unpublished_display_link_in_node_content']);
  $config->save();
  backdrop_set_message(t('The configuration options have been saved.'));
}
