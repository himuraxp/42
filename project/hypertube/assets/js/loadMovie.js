$(document).ready( function() {
$("#send_movie").click(function(){

  var movie2 = $('#magnet_link').val();
  alert(movie2);
  io.socket.post('/movie/download', {magnet_link: movie2},function(resData, jwres){
  });
  // var content = document.getElementById('magnet_link').value;
  // var xhttp = new XMLHttpRequest();
  // xhttp.onreadystatechange = function() {
  // 	if (xhttp.readyState == 4 && xhttp.status == 200) {
  // 		console.log("ok");
  // 	}
  // };
  //
  //
  // xhttp.open("POST", "/movie/download", true);
  // xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  // xhttp.send("magnet_link="+content+"");
  io.socket.on('stream', function(data){
    $("#player").html('<video width="320" height="240" controls>'+
    '<source src="" type="video/mp4">'+
' Your browser does not support the video tag.'+
  '</video><br>'+data+'');
    });
    io.socket.on('loading', function(data){
      $("#player").html('Loading...<br/><div style="width:200px;"><div style="background-color:green;width:'+data+';"></div></div>');
      });
})
});
