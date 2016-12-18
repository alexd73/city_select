<?php
require_once 'city_select.vars.inc';

function city_select_domain_list() {
  drupal_set_message('Настройки не реализованы и производятся с файле city_select.vars.inc, переменная $region_domain', 'information');
  return '';

//  if (!function_exists('domain_domains')){
//    drupal_set_message(t('Cannot get domain list. Please check module <b>Domain Access</b>!'), 'error');
//    return '';
//  }
//
//  $header = array(t('Name'), t('Path'), t('Actions'));
//  $domains = domain_domains();
//  // TODO Перебрать все домены и вывести список с настройками
//  $rows = array();
//  if ($domains) {
//    foreach ($domains as $domain) {
//      $actions = array(
//        l(t('edit'), 'admin/structure/city_select/' . $domain['domain_id'] . '/edit'),
//      );
//      $rows[] = array(
//        $domain['sitename'] . ' (' . $domain['subdomain'] . ')',
//        $domain['path'],
//        implode(' | ', $actions),
//      );
//    }
//  }
//  return theme('table', array(
//    'header' => $header,
//    'rows' => $rows
//  ));
}

function city_select_domain_form($form, &$form_state, $domain = null) {
  global $ALL_RUSSIAN_REGIONS;
  $form = array();
  if ($domain) {
    $form['id'] = array(
      '#type'  => 'item',
      '#title' => $domain,
    );
  }
  $form['region'] = array(
    '#type' => 'select',
    '#title' => t('Select a region'),
    '#options' => $ALL_RUSSIAN_REGIONS,
    '#description' => 'Выберите регион, в котором будет открываться этот домен'
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return system_settings_form($form);
}