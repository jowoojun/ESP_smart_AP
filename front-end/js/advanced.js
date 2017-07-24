$(function(){
  $("ul.sub").hide();
  $("ul.menu li").hover(function(){
      $("ul:not(:animated)",this).slideDown("fast");
    },
    function(){
      $("ul",this).slideUp();
    });
});

$(function(){
  $("ul.tab li ul li").click(function(){
    var active_tab=$(this).attr("data-tab");
    $("ul.tab li ul li").removeClass("current");
    $(".tabcontent").removeClass("current");
    $(this).addClass("current");
    $('#'+active_tab).addClass('current');
    $('#'+active_tab+'_desc').addClass('current');
  })
});
