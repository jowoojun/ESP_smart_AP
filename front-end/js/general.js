function toggle_menu(id){
  var myId=document.getElementById(id);
  if(id=="internet_info"){
    if(myId.style.display=="none"){
      myId.style.display="block";
      var otherId=document.getElementById('admin_setting');
      otherId.style.display="none";
    }
  }else{
    if(myId.style.display=="none"){
      myId.style.display="block";
      otherId=document.getElementById('internet_info');
      otherId.style.display="none";
    }
  }
}
