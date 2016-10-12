$('button[name=reduct]').click(reductPopup);
$('button[name=close]').click(closePopup);
$('.popup').mousedown(addMovePopup);
$('.popup').mouseup(rmMovePopup);
$('body').mousemove(MovePopup);

  function MovePopup(){
    if ($("#clickstatus").val() == "1") {
      var idPop = $("#idpopup").val();
      var mY = $("#mouseY").val();
      var mX = $("#mouseX").val();
      if (!document.getElementById(idPop).style.top)
        document.getElementById(idPop).style.top = "20px";
      if(!document.getElementById(idPop).style.left)
        document.getElementById(idPop).style.left = "50px";
      var objTop = parseInt(document.getElementById(idPop).style.top) - mY + event.pageY;
      var objLeft = parseInt(document.getElementById(idPop).style.left) - mX + event.pageX;
      $("#mouseY").val(event.pageY);
      $("#mouseX").val(event.pageX);
      document.getElementById(idPop).style.top = objTop+"px";
      document.getElementById(idPop).style.left = objLeft+"px";
      $("#mouseY").html(event.pageY);
      $("#mouseX").html(event.pageX);
    }
  }
  function rmMovePopup(){
    $("#clickstatus").val("0");
    console.log("mouseOff");
  }
  function addMovePopup(){
    $("#clickstatus").val("1");
    $("#idpopup").val($(this).attr('id'));
    $("#mouseY").val(event.pageY);
    $("#mouseX").val(event.pageX);
    document.getElementById("Zindex").value = (parseInt($("#Zindex").val()) + 1);
    document.getElementById($(this).attr('id')).style.zIndex = ""+$("#Zindex").val();
    console.log("mouseOn");
  }
  function closePopup(){
    $("#little_"+$(this).parent().attr('id')).remove();
    $("#"+$(this).parent().attr('id')).remove();
  }
  function reductPopup(){
    $("#"+$(this).parent().attr('id')).fadeOut();
  }
  function openPopup(id){
    if (document.getElementById(id).style.display == "none")
      document.getElementById(id).style.display = "block";
    else
      document.getElementById(id).style.display = "none";
    //document.getElementById($( this ).attr('id')).style.display = "block";
  }
