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