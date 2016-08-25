let http = require('http')
let crypto = require('crypto')
let mysql = require('mysql')
let Message = require('../models/message')
let User = require('../models/users')
let Like = require('../models/like')
let Picture = require('../models/picture')

httpServer = http.createServer(function(req, res){
	console.log('Un utilisateur a affiche la page')
})

httpServer.listen(1337)

let io = require('socket.io').listen(httpServer)
let users = {}
var get_cookies = function(client) {
	var cookies = {}
	client.headers && client.headers.cookie.split(';').forEach(function(cookie) {
		var parts = cookie.match(/(.*?)=(.*)$/)
		cookies[ parts[1].trim() ] = (parts[2] || '').trim()
	})
	return cookies
}

io.sockets.on('connection', function(socket){
	let id = get_cookies(socket.request)['uid']
	let for_id = get_cookies(socket.request)['for_id']
	let me = false;
	let getLastComments = function(){
		Message.connect_messages(function(rows) {
			if (rows === "error") {
				socket.emit('error')
			} else {
				let messages = []
				rows.reverse()
				for(k in rows){
					let row = rows[k]
					Picture.find(row.user_id, function (picture) {
						if (picture) {
							let message = {
								message: row.message,
								created_at: row.created_at,
								user: {
									id: row.user_id,
									username: row.pseudo,
									avatar: picture.url_pic_1
								}
							}
							messages.push(message)
						} else {
							let message = {
								message: row.message,
								created_at: row.created_at,
								user: {
									id: row.user_id,
									username: row.pseudo,
									avatar: "https://gravatar.com/avatar/" + crypto.createHash('md5').update(row.email).digest('hex') + '?s=50'
								}
							}
							messages.push(message)
						}
						socket.emit('newmsg', messages)
					})
				}
			}
		})
	}
	let getLastCommentsId = function(for_user_id){
		User.find(id, function(user) {
			if (user) {
				Like.find_by_id(user.id, function (likes) {
					for (i in likes) {
						if (for_id == likes[i].like_you) {
							Message.get_message_id (user.id, for_id, function(rows) {
								for (i in rows) {
								}
								if (rows === "error") {
									socket.emit('error')
								} else {
									let messages = []
									rows.reverse()
									for(k in rows){
										let row = rows[k]
										let len = rows.length
										len -= 1
										Picture.find(row.user_id, function (picture) {
											if (picture) {
												let message = {
													message: row.message,
													created_at: row.created_at,
													user: {
														id: row.user_id,
														username: row.pseudo,
														avatar: picture.url_pic_1
													},
													like: for_id
												}
												messages.push(message)
											} else {
												let message = {
													message: row.message,
													created_at: row.created_at,
													user: {
														id: row.user_id,
														username: row.pseudo,
														avatar: "https://gravatar.com/avatar/" + crypto.createHash('md5').update(row.email).digest('hex') + '?s=50'
													}
												}
												messages.push(message)
											}
											if (rows[len] === row) {
												socket.emit('newmsg', messages)
											}
										})
									}
								}
							})
						}
					}
				})
			}
		})

	}

	for(let k in users){
		socket.emit('newusr', users[k])
	}

	/**
	* On a reçu un message
	**/
	socket.on('newmsg', function(message){
		if(message.message === '' || me.id === undefined) {
			socket.emit('error', 'Vous ne pouvez pas envoyer un message vide')
		} else if (me.id === undefined){
			socket.emit('error', 'Vous devez être identifié pour envoyer un message')
		} else {
			message.user = me
			message.for_id = me.for_id
			message.created_at = Date.now()
			Message.push(message.user.id, message.message, message.for_id, function(err) {
				if(err === "error"){
					socket.emit('error')
				} else {
					io.sockets.emit('newmsg', message)
				}
			})
		}
	})

	/**
	* Je me connecte
	**/
	socket.on('login', function(user){
		User.find(user.id, function (rows) {
			Like.find_by_id(user.id, function (like) {
				Picture.find(user.id, function (picture) {
					if (picture) {
						if (rows === "error") {
							socket.emit('error')
						} else if(rows && rows.token === user.token) {
							me = {
								username: rows.login,
								id: rows.id,
								for_id: for_id,
								avatar: picture.url_pic_1
							}
							socket.emit('logged')
							users[me.id] = me
							io.sockets.emit('newusr', me)
							getLastCommentsId()
						} else {
							io.sockets.emit('error', 'Aucun utilisateur ne correspond')
						}
					} else {
						if (rows === "error") {
							socket.emit('error')
						} else if(rows && rows.token === user.token) {
							me = {
								username: rows.login,
								id: rows.id,
								avatar: "https://gravatar.com/avatar/" + crypto.createHash('md5').update(row.email).digest('hex') + '?s=50'
							}
							socket.emit('logged')
							users[me.id] = me
							io.sockets.emit('newusr', me)
							getLastCommentsId()
						} else {
							io.sockets.emit('error', 'Aucun utilisateur ne correspond')
						}
					}
				})
			})
		})
	})

	/**
	* Je quitte le tchat
	**/
	socket.on('disconnect', function(){
		if(!me){
			return false
		} else {
			delete users[me.id]
			io.sockets.emit('disusr', me)
		}
	})


})
