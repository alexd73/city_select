<?php


/**
 * Implements hook_block_info().
 */
function city_select_block_info() {
    $blocks['domain_select'] = array(
      'info' => t('Region select'),
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
                if (user_access('access inactive domains')) {
                    $msg = TRUE;
                    $allow = TRUE;
                }
            }
            $path = domain_check_scheme($domain['scheme']) . '://' . $domain['subdomain'] . '/' . city_select_get_domain_path(current_path(), $domain['domain_id']);
            if ($allow) {
                $list[] = l($title, $path, array('absolute' => TRUE));
            }
        }
        $items = array('items' => $list);
        $output = theme('item_list', $items);
        $blocks = array(
          'subject' => t('Domain select'),
          'content' => array(
            '#markup' => $output,
          ),
        );
    }
    return $blocks;
}

