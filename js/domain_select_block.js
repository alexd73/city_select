(function ($) { $(document).ready(function(){

    $('.regions__item').click(function () {
        $.cookie(
            'manual_region',
            true,
            {
                domain: '.semeynaya.ru',
                expires: 1
            }
        )
    });

}); })(jQuery);

