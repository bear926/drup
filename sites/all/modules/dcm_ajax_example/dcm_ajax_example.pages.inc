<?php

/**
 * @file
 * Page callbacks for DrupalCampMinsk Ajax Examples module.
 */

/**
 * AJAX callback for LOAD FORM link.
 */
function dcm_ajax_example_page_ajax_callback($node, $js) {

  switch($js) {

    // If no js support just redirect to terms of use.
    case 'nojs':
      drupal_goto('node/' . $node->nid);
      break;

    // If js support enabled load view and show it in popup.
    default:

      // Add library for popup.
      drupal_add_library('system', 'ui.dialog');

      // Load full node view.
      $view = node_view($node);

      // Load access/deny terms of use form.
      $form = drupal_get_form('dcm_ajax_example_accept_terms_form');

      // Collect AJAX commands.
      $commands   = array();
      $commands[] = ajax_command_remove('#example-form-popup');
      $commands[] = ajax_command_append('body', '<div id="example-form-popup"></div>');
      $commands[] = ajax_command_html('#example-form-popup', render($view));
      $commands[] = ajax_command_append('#example-form-popup', render($form));
      $commands[] = ajax_command_invoke('#example-form-popup', 'dialog');

      return array('#type' => 'ajax', '#commands' => $commands);
  }
}
