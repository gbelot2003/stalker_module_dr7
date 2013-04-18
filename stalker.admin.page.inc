<?php

	function admin_config_people_stalker(){
    	return drupal_get_form("stalker_settings_form");
	}

	function stalker_settings_form(){
		$form = array();

		$form['modes'] = array( // No sirve en si misma, hay que anidar elementos en ella
			'#type' => 'fieldset',
			'#title' => t('Modes of operation'),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
			'#tree' => TRUE,
		);

		$form['modes']['stalker_threshold'] = array(
			'#type' => 'textfield',
			'#title' => t('Stalker threshold'),
			'#description' => t('Users who view the profile <strong>fewers</strong> time then this number will not be listed'),
			'#default_value' => variable_get('stalker_threshold', 1),
			'#required' => TRUE,
		);

		$form['modes']['stalker_identity'] = array(
			'#type' => 'checkbox',
			'#title' => t('Secret admirer mode'),
			'#description' => t('Show the number of times users have visited, but hide their identity'),
			'#default_value' => variable_get('stalker_identity', false),
		);

		$form['modes']['stalker_narcissism'] = array(
			'#type' => 'checkbox',
			'#title' => t('Allow narcissism'),
			'#description' => t('Show how many times a user views their own profile'),
			'#default_value' => variable_get('stalker_narcissism', FALSE),
		);

		$form['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Save settings'),
		);

		return $form;
	}

	function stalker_settings_form_validate(&$form, &$form_state){

		if(!is_numeric($form_state['values']['modes']['stalker_threshold'])){
			form_set_error('stalker_threshold', t('You must enter a numer'));
		} elseif($form_state['values']['modes']['stalker_threshold'] < 1){
			form_set_error('stalker_threshold', t('You must enter a number biger than 0'));
		}
	}

	function stalker_settings_form_submit(&$form, &$form_state){
		variable_set('stalker_threshold', $form_state['values']['modes']['stalker_threshold']);
		variable_set('stalker_identity', $form_state['values']['modes']['stalker_identity']);
		variable_set('stalker_narcissism', $form_state['values']['modes']['stalker_narcissism']);
	}