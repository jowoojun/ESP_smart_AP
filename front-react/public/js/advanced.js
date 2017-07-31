$(function(){
  $("ul.sub").hide();
  $("ul.menu li").hover(function(){
      $("ul:not(:animated)",this).slideDown();
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

$(document).ready(function(){
  $("input[name='con_type']:radio").change(function(){
    //get radio value
    var con_type=this.value;
    if(con_type=="ip_dynamic"){
      $("#ip_dynamic_cont").show();
      $("#ip_static_cont").hide();
    }else if(con_type=="ip_static"){
      $("#ip_static_cont").show();
      $("#ip_dynamic_cont").hide();
    }
  });

  $("input[name='dns_server']:radio").change(function(){
      var dns_server=this.value;
      if(dns_server=="dns_dynamic"){
        //readonly
        $(".dns_default").attr("readonly",true);
        $(".dns_secondary").attr("readonly",true);
      }else if(dns_server=="dns_static"){
        $(".dns_default").attr("readonly",false);
        $(".dns_secondary").attr("readonly",false);
      }
  });

  $("input[name='dhcp']:radio").change(function(){
      var dhcp=this.value;
      if(dhcp=="stop"){
        //readonly
        $(".dhcp_range").attr("readonly",true);
      }else if(dns_server=="dns_static"){
        $(".dhcp_range").attr("readonly",false);
      }
  });

  $("#chk_all").click(function(){
      $("input[name=mal_site_category]").prop("checked",true);
  });

  $("#chk_not_all").click(function(){
    $("input[name=mal_site_category]").prop("checked",false);
  });

  $("#chk_all_day").click(function(){
      $("input[name=day]").prop("checked",true);
  });

  $("#chk_not_all_day").click(function(){
    $("input[name=day]").prop("checked",false);
  });

});
