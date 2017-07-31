$(function(){
    $('ul.tab li').click(function(){
      var active_tab=$(this).attr('data-tab');
      $('ul.tab li').removeClass('current');
      $('.tabcontent').removeClass('current');
      $(this).addClass('current');
      $('#'+active_tab).addClass('current');
      $('#'+active_tab+'_desc').addClass('current');
    })
});
