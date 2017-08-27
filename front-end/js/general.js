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
  $("#move_to_drop").click(function(){
    $("#white_block option:selected").each(function(){
      $(this).remove().appendTo("#black_block");
    });
  });

  $("#move_to_allow").click(function(){
    $("#black_block option:selected").each(function(){
      $(this).remove().appendTo("#white_block");
    });
  });
});


$(function(){
  $("#time_add").click(function(){
    //날짜시간 만들기
    var day = [];
    var days = "";
    var day_checked = $("input:checkbox[name='day']");
    for(var i=0;i<day_checked.length;i++){
      if(day_checked[i].checked){
        day.push(day_checked[i].value);
      }
    }
    for(var i=0;i<day.length;i++){
      days += day[i]+",";
    }
    var ts = $("#time_start option:selected").text();
    var te = $("#time_end option:selected").text();
    day_time=days+ts+"-"+te;

    //추가하기
    if($('#time_blacklist').find("[value='"+day_time+"']").length == 0){
      $('#time_blacklist').append('<option value="'+day_time+'">'+day_time+"</option>");
    }else{
      alert("등록된 날짜,시간 입니다.");
    }
  });

  //삭제하기
  $("#time_del").click(function(){
    $('#time_blacklist option:selected').each( function() {
        $(this).remove();
    });
  });
});


$(document).ready(function(){
  $("#timelist_all").click(function(){
    $("#time_blacklist > option").attr("selected",true);
  });

  $("#timelist_not_all").click(function(){
    $("#time_blacklist > option").attr("selected",false);
  });
});
