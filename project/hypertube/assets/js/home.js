$(document).ready( function() {
	$('#button-home').click(goHome);

	function goHome(e){
		io.socket.off("home");
		var home = jQuery.get('/', function(data) {
			//process text file line by line
			var parse = data.split("<start>");
			parse = parse[1].split("<end>");
			var result = parse[0];
			$('#central').html(result);
		});

		io.socket.on('home', function(data){
			$('#central').append(home);
		})
	}
})
