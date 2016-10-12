$(document).ready( function() {
	function makeid() {
		var text = "";
		var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

		for( var i=0; i < 5; i++ )
		text += possible.charAt(Math.floor(Math.random() * possible.length));

		return text;
	}
	function hashCode(str) {
		return str.split('').reduce((prevHash, currVal) =>
		((prevHash << 5) - prevHash) + currVal.charCodeAt(0), 0);
	}
	$('#searchSub').click(myProcedure);
	$('#movie').keydown(myProcedure);

	function myProcedure(e){
		io.socket.off("video");
		if((e.type == "keydown" && e.keyCode == "13") || (e.type == "click")) {

			var movie2 = $('#movie').val();

			$('#central').empty();

			$('#central').append(
				'<div class="container" style="width: 100%;margin: 0;padding: 0;text-align: center;">'+
				'<h1 class="title-header" style="margin-top:30px;">Movie</h1>'+
				'<div id="more">'+
				'<div class="list-inline">'+
				'</div>'+
				'</div>'
			);

			io.socket.post('/movie/searchMovie', {movie: movie2},function(resData, jwres){
			});
			var i = 0;
			$.getScript( "/js/popup.js", function( data, textStatus, jqxhr ) {
				$("#loadpopup").remove();
				$("head").append("<script id='loadpopup'>"+data+"</script>");
			});
			io.socket.on('video', function(data){
				var movie = jQuery.parseJSON(data);
				var movieId = "movie_"+makeid()+""+(i++);
				for (let i = 0; i < movie.length; i++) {
					var hash = hashCode(movie[i].magnet);
					$(".list-inline").append(
						'<img id="'+i+'" class="img-movie hvr-grow" src="'+((movie[i].poster && movie[i].poster != 'N/A') ? movie[i].poster : '/images/video.gif')+'" alt="'+movie[i].title+'"/>'
					)

					$("#"+i).click(function (){
						$('#more').append(
							'<div class="block-search block-'+i+' ui-draggable ui-draggable-handle" draggable="true">'+
							'<input id="close-search'+i+'" class="close-search button-play" type="submit" value="&#xf057;">'+
							'<img class="img-movie" src="'+((movie[i].poster && movie[i].poster != 'N/A') ? movie[i].poster : '/images/video.gif')+'" alt="'+movie[i].title+'"/>'+
							'<div class="block-info" id="'+(hashCode(movie[i].magnet))+'">'+
							'<h2 class="title-movie">'+movie[i].title+'</h2>'+
							'<p class="content-movie"> Note IMDB : '+(!movie[i].note ? 'N/A' : movie[i].note)+'</p>'+
							'<p class="content-movie">Year : '+movie[i].year+'</p>'+
							'<input type="hidden" name="magnet_link" value="'+movie[i].magnet+'">'+
							'<input type="hidden" name="title_movie" value="'+movie[i].title+'">'+
							'<input id="play-'+i+'" class="button-play" type="submit" name="play" class="send_movie" onclick="xD(\''+(hashCode(movie[i].magnet))+'\')" value="&#xf16a;">'+
							'</div></div>'
						)

						$(".block-"+i).draggable();

						$("#close-search"+i).click(function (){
							$(this).remove();
							$(".block-"+i).remove();
						})

						$("#play-"+i).click(function (){
							$(this).remove();
							$(".block-"+i).remove();
						})
					})
				}
			});
		}
	}
});
