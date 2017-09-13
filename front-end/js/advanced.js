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
    $('ul.tab li').click(function(){
      var active_tab=$(this).attr('data-tab');
      $('ul.tab li').removeClass('current');
      $('.tabcontent').removeClass('current');
      $(this).addClass('current');
      $('#'+active_tab).addClass('current');
      $('#'+active_tab+'_desc').addClass('current');
    })
});

$(function(){
  $("#add_word").click(function(){
    if($('#word_list').find("[value='"+$('#searchbox').val().replace('"','\'')+"']").length == 0){
      $('#word_list').append('<option value="'+$('#searchbox').val().replace('"','\'')+'">'+$('#searchbox').val()+"</option>");
    }else{
      alert("등록된 단어입니다.");
    }
  });

  $("#del_word").click(function(){
    $('#word_list option:selected').each( function() {
        $(this).remove();
    });
  });
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
      $("input[name='mal_site_category']").attr("checked",true);
  });

  $("#chk_not_all").click(function(){
    $("input[name='mal_site_category']").attr("checked",false);
  });

  $("#chk_all_day").click(function(){
      $("input[name='day']").attr("checked",true);
  });

  $("#chk_not_all_day").click(function(){
    $("input[name='day']").attr("checked",false);
  });

  $(function(){
    $("#mac_add").click(function(){
      //mac주소 만들기
      function full_mac(){
        var full_mac="";
        for(i=1;i<6;i++){
          full_mac+=$("#black_mac"+i).val()+"-";
        }
        full_mac+=$("#black_mac6").val();
        return full_mac;
      }
      var full_mac=full_mac();

      //추가하기
      if($('#mac_blacklist').find("[value='"+full_mac+"']'").length == 0){
        $('#mac_blacklist').append('<option value="'+full_mac+'">'+full_mac+"</option>");
      }else{
        alert("등록된 MAC주소 입니다.");
      }
    });

    //삭제하기
    $("#mac_del").click(function(){
      $('#mac_blacklist option:selected').each( function() {
          $(this).remove();
      });
    });
  });

  $(document).ready(function(){

  	$("#blacklist_all").click(function(){
  	      $("#mac_blacklist > option").attr("selected",true);
  	  });

  	  $("#blacklist_not_all").click(function(){
  	    $("#mac_blacklist > option").attr("selected",false);
  	  });
  });

  $("#word_all").click(function(){
      $("#word_list > option").attr("selected",true);
  });

  $("#word_not_all").click(function(){
    $("#word_list > option").attr("selected",false);
  });

  $("#blacklist_all").click(function(){
      $("#mac_blacklist > option").attr("selected",true);
  });

  $("#blacklist_not_all").click(function(){
    $("#mac_blacklist > option").attr("selected",false);
  });

  var availableTags=[
    '강다솔',
    '조우준',
    '김재한',
    '장호동',
    '이창건',
    '안랩',
    '한이음',
    '박수현멘토님',
    '강민아',
    '조석현',
    '김수빈'
  ];

  $("#searchbox").autocomplete(availableTags,{
    matchContains: true,
    selectFirst: false
  });



});
