<?php
$plugin = array(
  // The name of the table as found in the schema in hook_install. This
  // must be an exportable type with the 'export' section defined.
  'schema' => 'team',

  // The access permission to use. If not provided it will default to
  // 'administer site configuration'
  'access' => 'administer site configuration',

  //Menu settings
  'menu' => array(
    'menu prefix' => 'admin/config/people',
    'menu item' => 'team',
    // Title of the top level menu. Note this should not be translated,
    // as the menu system will translate it.
    'menu title' => 'Teams',
    // Description of the top level menu, which is usually needed for
    // menu items in an administration list. Will be translated
    // by the menu system.
    'menu description' => 'Administer favorite teams for users.',
  ),

  // These are required to provide proper strings for referring to the
  // actual type of exportable. "proper" means it will appear at the
  // beginning of a sentence.
  'title singular' => t('team'),
  'title singular proper' => t('Team'),
  'title plural' => t('teams'),
  'title plural proper' => t('Teams'),

  // This will provide you with a form for editing the properties on your
  // exportable, with validate and submit handler.
  //
  // The item being edited will be in $form_state['item'].
  //
  // The submit handler is only responsible for moving data from
  // $form_state['values'] to $form_state['item'].
  //
  // All callbacks will accept &$form and &$form_state as arguments.
  'form' => array(
    'settings' => 'favorite_team_ctools_export_ui_form',
    'validate' => 'favorite_team_ctools_export_ui_form_validate',
    'submit' => 'favorite_team_ctools_export_ui_form_submit',
  ),
);

/**
 * Implements hook_form_alter().
 */
function favorite_team_ctools_export_ui_form(&$form, &$form_state) {
  /*
  dsm($form);
  dsm($form_state);
   */
  $team = $form_state['item'];
  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Short description of the team'),
    '#default_value' => isset($team->description) ? $team->description : $team->description,
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Implements hook_form_validate
 */
function favorite_team_ctools_export_ui_form_validate(&$form , &$form_state){
  //Validate code
}

/**
 * Implements hook_form_submit
 */
function favorite_team_ctools_export_ui_form_submit(&$form , &$form_state){
  //Submit Code
}


