<?php


/**
 * Implements hook_block_info().
 */
function city_select_block_info() {
    $blocks['domain_select'] = array(
      'info' => t('Domain select (City select)'),
      'cache' => DRUPAL_CACHE_GLOBAL,
    );
    return $blocks;
}


/**
 * A nifty little domain-switcher block, useful during debugging.
 *
 */
/**
 * Implements hook_block_view().
 */
function city_select_block_view($delta = '') {
    global $_domain; // Текущий домен
    drupal_add_library('system', 'jquery.cookie');


    $blocks = array();
    if ($delta = 'domain_select') {
        $output = '';
        $list = array();
        $domains = domain_domains();
        $msg = FALSE;
        foreach ($domains as $domain) {
            if ($domain['valid']) {
                $title = $domain['sitename'];
                $allow = TRUE;
            }
            else {
                $title = $domain['sitename'] . ' *';
                $allow = FALSE;
//                if (user_access('access inactive domains')) {
//                    $msg = TRUE;
//                    $allow = TRUE;
//                }
            }
            if ($allow) {
                $path = domain_check_scheme($domain['scheme']) . '://' . $domain['subdomain'] . '/' . city_select_get_domain_path(current_path(), $domain['domain_id']);
                $list[] = l($title, $path, array(
                  'absolute' => TRUE,
                  'attributes' => array(
                    'class' => 'regions__item' .  ($domain['domain_id'] == $_domain['domain_id'] ? ' active' : '')
                  )
                ));
            }
        }
        $items = array(
          'items' => $list,
          'attributes' => array('class' => 'regions clearfix')
        );
        $output = theme('item_list', $items);
        $blocks = array(
          'subject' => t('City select'),
          'content' => array(
            '#markup' => $output,
            '#attached' => array(
              'library' => array(array('system', 'jquery.cookie')),
              'js' => array(YOUR_MODULE_PATH . '/js/domain_select_block.js'),
              'css' => array(YOUR_MODULE_PATH . '/css/domain_select_block.css')
            )
          ),
        );
    }
    return $blocks;
}

