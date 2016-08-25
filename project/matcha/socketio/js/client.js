let startTchat;

(function($){

	let socket = io.connect('http://localhost:1337')
	let msgtpl = $('#msgtpl').html()
	let lastmsg= false;

	$('#msgtpl').remove()

	startTchat = function(user_id, token){
		socket.emit('login', {
			id: user_id,
			token: token
		})
	}

	socket.on('logged', function(){
		$('#login').fadeOut()
		$('#message').focus()
	})

	/**
	* Envois de message
	**/
	$('#form').submit(function(event){
		event.preventDefault()
		socket.emit('newmsg', {message: $('#message').val() })
		$('#message').val('')
		$('#message').focus()
	})

	socket.on('newmsg', function(messages){
		if(!Array.isArray(messages)){
			messages = [messages]
		}
		for(k in messages){
			let message = messages[k]
			message.h = new Date(message.created_at).getHours()
			message.m = new Date(message.created_at).getMinutes()
			message.for_id = message.like
			if(lastmsg != message.user.id){
				$('#messages').append('<div class="sep"></div>')
				lastmsg = message.user.id
			}
			$('#messages').append('<div class="message">' + Mustache.render(msgtpl, message) + '</div>')
		}
		$('#messages').animate({scrollTop : $('#messages').prop('scrollHeight') }, 50)
	})


	/**
	* Gestion des connectés
	**/
	socket.on('newusr', function(user){
		$('#users').append('<img class="chat-img" src="' + user.avatar + '" id="' + user.id + '">')
	})

	socket.on('disusr', function(user){
		$('#' + user.id).remove()
	})

	socket.on('error', function(err){
		console.log(err)
	})

})(jQuery)
