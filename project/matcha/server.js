
let express		= require('express')
let bodyParser	= require('body-parser')
let session		= require('express-session')
let cookieParser= require('cookie-parser')
let moment		= require('./config/moment')
var fileUpload	= require('express-fileupload')
let NodeGeocoder= require('node-geocoder')
var fs 			= require('fs')
// var Promise		= require('promise')
let app			= express()

// Template
app.set('view engine', 'ejs')

// Middleware
app.use('/assets', express.static('public'))
app.use('/client', express.static('client'))
app.use('/socketio', express.static('socketio'))
app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json())
app.use(fileUpload());
app.set('trust proxy', 1)
app.use(session({
	secret				: 'matcha@42',
	resave				: false,
	saveUninitialized	: true,
	cookie				: { secure : false }
}))
app.use(require('./middlewares/flash'))
var get_cookies = function(request) {
	var cookies = {};
	request.headers && request.headers.cookie.split(';').forEach(function(cookie) {
		var parts = cookie.match(/(.*?)=(.*)$/)
		cookies[ parts[1].trim() ] = (parts[2] || '').trim();
	});
	return cookies;
};

// Route
app.get('/', (req, res) => {
	if (req.headers.cookie) {
		if (get_cookies(req)['uid']) {
			res.redirect('/home')
		} else {
			res.render('layout/index')
		}
	} else {
		res.render('layout/index')
	}
})
app.post('/', (req, res) => {
	if (req.body.email === undefined || req.body.email === '' || req.body.password === undefined || req.body.password === '') {
		req.flash("error", "Les champs ne peuvent être vide :(")
		res.redirect('/')
	} else {
		let Signin = require('./models/signin')
		Signin.find_account(req.body, function (user, err) {
			let sha256 = require('sha256')
			let new_hash = sha256(req.body.password)
			if (user && new_hash === user.password) {
				req.flash('success', "Connexion réussi !")
				res.cookie('uid', user.id)
				res.redirect('/home')
			} else {
				req.flash('error', "Email ou mot de passe invalide !")
				res.redirect('/')
			}
		})
	}
})
app.get('/notif', (req, res) => {
	let User = require('./models/users')
	let Notification = require('./models/notification')
	id = get_cookies(req)['uid']
	Notification.find_by_id(id, (notifs) => {
		User.all((users) => {
			User.find(id, function (user) {
				if (id) {
					res.render('layout/notif', {users:users, user: user, notifs: notifs})
				} else {
					res.render('layout/notif', {users:users, user: user, notifs: notifs})
				}
			})
		})
	})
})
app.post('/notif/:id', (req, res) => {
	let User = require('./models/users')
	let Notification = require('./models/notification')
	id = get_cookies(req)['uid']
	Notification.false_notif(req.body.notif, (err) => {
		Notification.find_by_id(id, (notifs) => {
			User.all((users) => {
				User.find(id, function (user) {
					if (id) {
						res.redirect(req.headers.referer)
					} else {
						res.redirect(req.headers.referer)
					}
				})
			})
		})
	})
})
app.get('/geo', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	id = get_cookies(req)['uid']
	token = get_cookies(req)['connect.sid']
	path = "./public/upload/" + id
	User.find(id, function (user) {
		User.init_token(id, token, function (err) {
			if (err) throw err
			if (id) {
				fs.access(path, fs.F_OK, function(err) {
					if (!err) {
						res.render('pages/geo', {
							error: undefined,
							location: {
								latitude: undefined,
								longitude: undefined,
								address: undefined
							}
						})
					} else {
						Picture.init(id)
						fs.mkdirSync('./public/upload/' + id)
						res.render('pages/geo', {
							error: undefined,
							location: {
								latitude: undefined,
								longitude: undefined,
								address: undefined
							}
						})
					}
				})
			} else {
				res.render('layout/index')
			}
		})
	})

})
app.post('/geo', require('./routes/index_post.js'))

app.get('/home', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	id = get_cookies(req)['uid']
	token = get_cookies(req)['connect.sid']
	path = "./public/upload/" + id
	User.find(id, function (user) {
		User.init_token(id, token, function (err) {
			if (err) throw err
			if (id) {
				fs.access(path, fs.F_OK, function(err) {
					if (!err) {
						res.render('pages/index',{user:user, error: undefined,
						location: {
							latitude: undefined,
							longitude: undefined,
							address: undefined
						}})
					} else {
						Picture.init(id)
						fs.mkdirSync('./public/upload/' + id)
						res.render('pages/index',{user:user, error: undefined,
						location: {
							latitude: undefined,
							longitude: undefined,
							address: undefined
						}})
					}
				})
			} else {
				res.render('layout/index')
			}
		})
	})
})

app.get('/profil', (req, res) => {
	let User = require('./models/users')
	let View = require('./models/views')
	let Like = require('./models/like')
	let Picture = require('./models/picture')
	id = get_cookies(req)['uid']
	uid = ""
	likes = ""
	my_views= {}
	User.all((users) => {
		User.find(id, function (user) {
			if (user.birthday !== "0000-00-00") {
				let date = new Date(user.birthday).toISOString().replace(/T/, ' ').split(' ')
				date = date[0]
				date = date.split('-')
				to_i_jj = parseInt(date[2])
				jj = to_i_jj + 1
				jj.toString()
				mm = date[1]
				aa = date[0]
				bday = jj + '-' + mm + '-' + aa
			} else {
				bday = null
			}
			View.all((views) => {
				Picture.all((pictures) => {
					Like.all((likes) => {
						Picture.find(id, function (picture) {
							if (id) {
								res.render('pages/user/profil', {
									users: users,
									user: user,
									pictures: pictures,
									picture: picture,
									uid: uid,
									likes: likes,
									views: views})
							} else {
								res.render('layout/index')
							}
						})
					})
				})
			})
		})
	})
})
app.post('/profil/delete', (req, res) => {
	let Picture = require('./models/picture')
	id = get_cookies(req)['uid']
	Picture.find(id, function (picture) {
		if (req.body.picture == 'url_pic_1') {
			filePath = picture.url_pic_1
		} else if (req.body.picture == 'url_pic_2') {
			filePath = picture.url_pic_2
		} else if (req.body.picture == 'url_pic_3') {
			filePath = picture.url_pic_3
		} else if (req.body.picture == 'url_pic_4') {
			filePath = picture.url_pic_4
		} else if (req.body.picture == 'url_pic_5') {
			filePath = picture.url_pic_5
		}
		fileTemp = filePath.split('/')
		fileName = fileTemp[4]
		path = "./public/upload/" + id + "/" + fileName
		Picture.delete(id, req.body.picture, function (err) {
			if (err) throw err
		})
		fs.unlinkSync(path, function(err) {
			if (err) throw err
			console.log("File deleted: " + path)
		})
		res.redirect('/profil')
	})
})
app.get('/profil/editer', (req, res) => {
	let User = require('./models/users')
	User.find(get_cookies(req)['uid'], function (user) {
		if (user.birthday !== "0000-00-00") {
			let date = new Date(user.birthday).toISOString().replace(/T/, ' ').split(' ')
			date = date[0]
			date = date.split('-')
			to_i_jj = parseInt(date[2])
			jj = to_i_jj + 1
			jj.toString()
			mm = date[1]
			aa = date[0]
			bday = aa + '-' + mm + '-' + jj
		} else {
			bday = 0
		}
		if (get_cookies(req)['uid']) {
			res.render('pages/user/editer', {user: user})
		} else {
			res.render('layout/index')
		}
	})
})
app.get('/profil/biopic', (req, res) => {
	let User = require('./models/users')
	User.find(get_cookies(req)['uid'], function (user) {
		if (get_cookies(req)['uid']) {
			res.render('pages/user/biopic', {user: user})
		} else {
			res.render('layout/index')
		}
	})
})
app.post('/profil/biopic', (req, res) => {
	let User = require('./models/users')
	User.find(get_cookies(req)['uid'], function (user) {
		if (req.body.story !== undefined) {
			let new_type = req.body.story
			User.update_account(user.id, new_type, 'story', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde de la description !")
					res.redirect('/profil/biopic')
				}
			})
		}
		req.flash('success', "Félicitation tes informations ont bien étaient enregistées !")
		res.redirect('/profil')
	})

})
app.post('/profil/editer', (req, res) => {
	let regex = /^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])([a-zA-Z0-9<>@#$%^&+=*.\-_\(\)\\\!\{\}\[\]\`\~\|\"\'\;\:\/\?\,]){3,}$/
	let User = require('./models/users')
	let Tag = require('./models/tag')
	User.find(get_cookies(req)['uid'], function (user) {
		if (get_cookies(req)['connect.sid']) {
			let new_type = get_cookies(req)['connect.sid']
			User.update_account(user.id, new_type, 'token', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde du token !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.pseudo !== undefined && req.body.pseudo !== '' && req.body.pseudo !== user.pseudo) {
			let new_type = req.body.pseudo
			User.update_account(user.id, new_type, 'pseudo', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde du pseudo !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.first_name !== undefined && req.body.first_name !== '' && req.body.first_name !== user.first_name) {
			let new_type = req.body.first_name
			User.update_account(user.id, new_type, 'first_name', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde du prenom !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.last_name !== undefined && req.body.last_name !== '' && req.body.last_name !== user.last_name) {
			let new_type = req.body.last_name
			User.update_account(user.id, new_type, 'last_name', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde du nom !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.email !== undefined && req.body.email !== '' && req.body.email !== user.email) {
			let new_type = req.body.email
			User.update_account(user.id, new_type, 'email', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde du nom !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.bday !== undefined && req.body.bday !== '' && req.body.bday !== user.birthday) {
			let new_type = req.body.bday
			User.update_account(user.id, new_type, 'birthday', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde de ta date de naissance !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.sex !== undefined && req.body.sex !== '' && req.body.sex !== user.sex) {
			let new_type = req.body.sex
			User.update_account(user.id, new_type, 'sex', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde Homme ou Femme !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.like_sex !== undefined && req.body.like_sex !== '' && req.body.like_sex !== user.like_sex) {
			let new_type = req.body.like_sex
			User.update_account(user.id, new_type, 'like_sex', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la sauvegarde Homme ou Femme !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.locate !== undefined && req.body.locate !== '' && req.body.locate !== user.locate) {
			let new_type = req.body.locate
			User.update_account(user.id, new_type, 'locate', function (err) {
				if (err === 'error') {
					req.flash('error', "Erreur pendant la modification de localisation !")
					res.redirect('/profil/editer')
				}
			})
		}
		if (req.body.sport !== undefined || req.body.geek !== undefined || req.body.bio !== undefined || req.body.barbu !== undefined) {
			let sport = 0
			let geek = 0
			let bio = 0
			let barbu = 0
			if (req.body.sport !== undefined) {
				sport = 1
			}
			if (req.body.geek !== undefined) {
				geek = 1
			}
			if (req.body.bio !== undefined) {
				bio = 1
			}
			if (req.body.barbu !== undefined) {
				barbu = 1
			}
			Tag.find(user.id, function (tags) {
				let verify = tags
				if (verify.row !== undefined) {
					Tag.update(user.id, sport, geek, bio, barbu, function (err) {
						if (err === "error") {
							req.flash('error', "Erreur pendant la sauvegarde des tags !")
							res.redirect('/profil/editer')
						}
					})
				} else {
					Tag.create(user.id, sport, geek, bio, barbu, function (err) {
						if (err === "error") {
							req.flash('error', "Erreur pendant la sauvegarde des tags !")
							res.redirect('/profil/editer')
						}
					})
				}
			})
		}
		req.flash('success', "Félicitation tes informations ont bien étaient enregistées !")
		res.redirect('/profil')
	})

})
app.post('/profil/upload', function(req, res) {
	let Picture = require('./models/picture')
	let sampleFile
	if (!req.files) {
		res.send('No files were uploaded.')
		return
	}
	id = get_cookies(req)['uid'].toString()
	path = "./public/upload/" + id
	sampleFile = req.files.sampleFile
	tempFile = path + "/" + sampleFile.name
	file = "/assets/upload/" + id + "/" + sampleFile.name
	Picture.update(id, file, function (err) {
		if (err) {
			req.flash('error', "Erreur pendant la sauvegarde de l'url !")
			res.redirect('/profil/editer')
		} else {
			req.flash('success', "Félicitation ta photo a bien était enregisté !")
			res.redirect('/profil')
		}
	})
	fs.access(path, fs.F_OK, function(err) {
		if (!err) {
			if (tempFile) {
				sampleFile.mv(tempFile, function(err) {
					if (err) {
						req.flash('error', "Ta photo n'a bien était enregisté !")
						res.redirect('/profil/editer')
					}
					else {
						req.flash('success', "Félicitation ta photo a bien était enregisté !")
						res.redirect('/profil')
					}
				})
			} else {
				req.flash('error', "Ta photo n'a bien était enregisté !")
				res.redirect('/profil/editer')
			}
		} else {
			fs.mkdirSync('./public/upload/' + id)
			sampleFile.mv(tempFile, function(err) {
				if (err) {
					res.status(500).send(err)
					req.flash('error', "Ta photo n'a bien était enregisté !")
					res.redirect('/profil/editer')
				}
			})
		}
	})

})

app.get('/chat', (req, res) => {
	let User = require('./models/users')
	let Like = require('./models/like')
	let Picture = require('./models/picture')
	id = get_cookies(req)['uid']
	User.all(function (users) {
		User.find(id, function (user) {
			Like.all(function (likes) {
				Picture.all(function (picture) {
					Like.find_by_id(id, function (like) {
						if (id) {
							res.render('pages/chat', {user: user, like:like, likes:likes, users:users, picture:picture})
						} else {
							res.render('layout/index')
						}
					})
				})

			})
		})
	})
})
app.post('/chat', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	if (req.body.chat === undefined || req.body.chat === '') {
		req.flash("error", "Utilisateur introuvable :(")
		res.redirect('/coffee')
	} else {
		res.cookie('for_id', req.body.chat)
		id = get_cookies(req)['uid']
		for_id = req.body.chat
		User.all(function (users) {
			Picture.all(function (picture) {
				Like.all(function (likes) {
					User.find(id, function (user) {
						if (id) {
							res.render('pages/chat', {user: user, like:for_id, users:users, picture:picture, likes:likes, id:id})
						} else {
							res.render('layout/index')
						}
					})
				})
			})
		})
	}
})

app.get('/coffee', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	id = get_cookies(req)['uid']
	tag = ""
	tags = ""
	User.all(function (users) {
		User.find(id, function (me) {
			Picture.all(function (picture) {
				Like.all(function (likes) {
					if (id) {
						res.render('pages/coffee', {users: users, picture:picture, likes:likes, id:id, me: me, tag: tag, tags: tags})
					} else {
						res.render('layout/index')
					}
				})
			})
		})
	})
})
app.get('/coffee/all', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	id = get_cookies(req)['uid']
	me = "all"
	tag = ""
	tags = ""
	User.all(function (users) {
		Picture.all(function (picture) {
			Like.all(function (likes) {
				if (id) {
					res.render('pages/coffee', {users: users, picture:picture, likes:likes, id:id, me: me, tag: tag, tags: tags})
				} else {
					res.render('layout/index')
				}
			})
		})
	})
})
app.get('/coffee/populaire', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	id = get_cookies(req)['uid']
	me = "all"
	tag = "populaire"
	tags = ""
	User.all(function (users) {
		Picture.all(function (picture) {
			Like.all(function (likes) {
				if (id) {
					res.render('pages/coffee', {users: users, picture:picture, likes:likes, id:id, me: me, tag: tag, tags: tags})
				} else {
					res.render('layout/index')
				}
			})
		})
	})
})
app.get('/coffee/sport', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	let Tag = require('./models/tag')
	id = get_cookies(req)['uid']
	me = ""
	tag = "sport"
	User.all(function (users) {
		Picture.all(function (picture) {
			Tag.all(function (tags) {
				Like.all(function (likes) {
					if (id) {
						res.render('pages/coffee', {users: users, picture:picture, likes:likes, id:id, me: me, tag: tag, tags: tags})
					} else {
						res.render('layout/index')
					}
				})
			})

		})
	})
})
app.get('/coffee/geek', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	let Tag = require('./models/tag')
	id = get_cookies(req)['uid']
	me = ""
	tag = "geek"
	User.all(function (users) {
		Picture.all(function (picture) {
			Tag.all(function (tags) {
				Like.all(function (likes) {
					if (id) {
						res.render('pages/coffee', {users: users, picture:picture, likes:likes, id:id, me: me, tag: tag, tags: tags})
					} else {
						res.render('layout/index')
					}
				})
			})

		})
	})
})
app.get('/coffee/bio', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	let Tag = require('./models/tag')
	id = get_cookies(req)['uid']
	me = ""
	tag = "bio"
	User.all(function (users) {
		Picture.all(function (picture) {
			Tag.all(function (tags) {
				Like.all(function (likes) {
					if (id) {
						res.render('pages/coffee', {users: users, picture:picture, likes:likes, id:id, me: me, tag: tag, tags: tags})
					} else {
						res.render('layout/index')
					}
				})
			})

		})
	})
})
app.get('/coffee/barbu', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	let Tag = require('./models/tag')
	id = get_cookies(req)['uid']
	me = ""
	tag = "barbu"
	User.all(function (users) {
		Picture.all(function (picture) {
			Tag.all(function (tags) {
				Like.all(function (likes) {
					if (id) {
						res.render('pages/coffee', {users: users, picture:picture, likes:likes, id:id, me: me, tag: tag, tags: tags})
					} else {
						res.render('layout/index')
					}
				})
			})

		})
	})
})
app.get('/coffee/:id', (req, res) => {
	let User = require('./models/users')
	let View = require('./models/views')
	let Picture = require('./models/picture')
	let Like = require('./models/like')
	id = req.params.id
	uid = get_cookies(req)['uid']
	User.find(id, function (user) {
		if (user.birthday !== "0000-00-00") {
			let date = new Date(user.birthday).toISOString().replace(/T/, ' ').split(' ')
			date = date[0]
			date = date.split('-')
			to_i_jj = parseInt(date[2])
			jj = to_i_jj + 1
			jj.toString()
			mm = date[1]
			aa = date[0]
			bday = jj + '-' + mm + '-' + aa
		} else {
			bday = null
		}
		View.new(uid, id, (err) => {
			User.upscore(id, (err) => {
				Picture.find(id, function (picture) {
					Like.all(function (likes) {
						if (id) {
							res.render('pages/user/profil', {user: user, picture: picture, uid: uid, likes: likes})
						} else {
							res.render('layout/index')
						}
					})
				})
			})
		})
	})
})
app.post('/coffee/unlike/:id', (req, res) => {
	let User = require('./models/users')
	let Like = require('./models/like')
	let Notification = require('./models/notification')
	id = get_cookies(req)['uid']
	if (req.body.unlike.match(/[0-9]/)) {
		Like.delete(id, req.body.unlike, function (err) {
			Notification.create(req.body.unlike, "Tu n'es plus liké par ", id, function (err) {
				User.unlike(req.params.id, function (user) {
					if (err === 'error') {
						req.flash('error', "Tu ne peux pas unlike ce membre !")
						res.redirect(req.headers.referer)
					} else {
						req.flash('success', "Félicitation ton unlike a était pris en compte. Une notification a était envoyé à ce membre !")
						res.redirect(req.headers.referer)
					}
				})
			})
		})
	} else {
		req.flash('error', "Tu ne peux pas Liker ce membre !")
		res.redirect('/coffee')
	}
})
app.post('/coffee/like/:id', (req, res) => {
	let User = require('./models/users')
	let Like = require('./models/like')
	let Notification = require('./models/notification')
	id = get_cookies(req)['uid']
	if (req.body.like.match(/[0-9]/)) {
		Like.create(id, req.body.like, function (err) {
			Notification.create(req.body.like, "Tu as eu un like de ", id, function (err) {
				User.like(req.params.id, function (user) {
					if (err === 'error') {
						req.flash('error', "Tu ne peux pas Liker ce membre !")
						res.redirect(req.headers.referer)
					} else {
						req.flash('success', "Félicitation ton like a était pris en compte. Une notification a était envoyé à ce membre !")
						res.redirect(req.headers.referer)
					}
				})
			})
		})
	} else {
		req.flash('error', "Tu ne peux pas Liker ce membre !")
		res.redirect('/coffee')
	}
})

app.get('/logout', (req, res) => {
	res.cookie('uid', '')
	res.cookie('connect.sid', '')
	res.redirect('/')
})

app.get('/message', (req, res) => {
	let Message = require('./models/message')
	Message.all(function (messages) {
		res.render('layout/message', {messages: messages})
	})
})
app.post('/message', (req, res) => {
	if (req.body.message === undefined || req.body.message === '') {
		req.flash('error', "Vous n'avez pas posté de message")
		res.redirect('/')
	} else {
		let Message = require('./models/message')
		Message.create(req.body.message, function () {
			req.flash('success', "Merci !")
			res.redirect('/')
		})
	}
})

app.get('/signup', (req, res) => {
	res.render('layout/create')
})
app.post('/signup', (req, res) => {
	let regex = /^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])([a-zA-Z0-9<>@#$%^&+=*.\-_\(\)\\\!\{\}\[\]\`\~\|\"\'\;\:\/\?\,]){3,}$/
	let nodemailer = require('nodemailer')
	if (req.body.pseudo === undefined || req.body.pseudo === '' || req.body.email === undefined || req.body.email === '' || req.body.first_name === undefined || req.body.first_name === '' || req.body.last_name === undefined || req.body.last_name === '' || req.body.password === undefined || req.body.password === '') {
		req.flash("error", "Les champs ne peuvent être vide :(")
		res.redirect('/signup')
	} else if (req.body.password.match(regex)) {
		let Signup = require('./models/signup')
		let sha256 = require('sha256')
		let hash = sha256(req.body.password)
		Signup.create(req.body, hash, function (err) {
			if (err === 'error') {
				req.flash('error', "Cette email existe dejà en base de donnée !")
				res.redirect('/signup')
			} else {
				var transporter = nodemailer.createTransport('smtps://ylarbi.42%40gmail.com:Eiko0962@smtp.gmail.com')
				var mailOptions = {
					from: '"Matcha" <matcha@machat.com>', // sender address
					to: req.body.email, // list of receivers
					subject: 'Bienvenue', // Subject line
					text: "Félicitation ton compte vient d'être crée", // plaintext body
					html: "<b>Félicitation ton compte vient d'être crée.</b> Tu peux dès maintenant te connecter sur <a href='http://localhost:8080'>Matcha</a> http://localhost:8080 . En te souhaitant une agréable visite." // html body
				};
				transporter.sendMail(mailOptions, function(err, info) {
					if(err){
						return console.log(err)
					}
					console.log('Message sent: ' + mailOptions);
				})
				req.flash('success', "Félicitation votre compte est créer !")
				res.redirect('/')
			}
		})
	} else {
		req.flash('error', "Le mot de passe doit comporter au minimum une MAJUSCULE, une MINUSCULE et un CHRIFFRE !")
		res.redirect('/signup')
	}
})

app.get('/reset_password', (req, res) => {
	res.render('layout/reset_password')
})
app.get('/reset_password/:reset_password', (req, res) => {
	res.render('layout/new_password')
})
app.post('/reset_password', (req, res) => {
	let nodemailer = require('nodemailer')
	if (req.body.email === undefined || req.body.email === '') {
		req.flash("error", "Le champ email ne peut être vide :(")
		res.redirect('/reset_password')
	} else {
		let User = require('./models/users')
		let sha256 = require('sha256')
		let hash = sha256(req.body.email + "Matcha")
		let path = "http://localhost:8080/reset_password/id=" + hash
		User.find_by_email(req.body.email, function (user) {
			User.reset_password(user, hash, function (err) {
				var transporter = nodemailer.createTransport('smtps://ylarbi.42%40gmail.com:Eiko0962@smtp.gmail.com')
				var mailOptions = {
					from: '"Matcha" <matcha@machat.com>',
					to: user.email,
					subject: 'Reinitialisation mot de passe',
					text: "Une demande récente de reinitialisation de mot de passe à était demander. Si tu souhaites toujours, le modifier va a l'addresse : " + path,
					html: "Une demande récente de reinitialisation de mot de passe à était demander. Si tu souhaites toujours, le modifier va a l'addresse : " + path
				};
				transporter.sendMail(mailOptions, function(err, info) {
					if(err){
						return console.log(err)
					}
					console.log('Message sent: ' + mailOptions);
				})
				req.flash('success', "Tu as reçu un email, pour te permettre de modifier ton mot de passe.")
				res.cookie('reset_password', hash)
				res.redirect('/')
			})
		})
	}
})
app.post('/reset_password/new', (req, res) => {
	let regex = /^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])([a-zA-Z0-9<>@#$%^&+=*.\-_\(\)\\\!\{\}\[\]\`\~\|\"\'\;\:\/\?\,]){3,}$/
	let url = get_cookies(req)['reset_password']
	let nodemailer = require('nodemailer')
	let pw = req.body.password[0]
	if (req.body.password === undefined || req.body.password === '') {
		req.flash("error", "Le champ ne peut être vide :(")
		res.redirect('/reset_password/' + url)
	} else if (pw.match(regex)) {
		let User = require('./models/users')
		let sha256 = require('sha256')
		let hash = sha256(pw)
		User.find_by_path(url, function (user) {
			User.new_password(user.id, hash, function (err) {
				if (err === 'error') {
					req.flash('error', "Une erreur est survenue !")
					res.redirect('/reset_password/' + url)
				} else {
					req.flash('success', "Félicitation ton mot de passe à était modifier !")
					res.cookie('reset_password', '')
					res.redirect('/')
				}
			})
		})
	} else {
		req.flash('error', "Le mot de passe doit comporter au minimum une MAJUSCULE, une MINUSCULE et un CHRIFFRE !")
		res.redirect('/reset_password/' + url)
	}
})

app.get('/user/:id', (req, res) => {
	let User = require('./models/users')
	User.find(req.params.id, function (user) {
		res.render('pages/user', {user: user})
	})
})

app.listen(8080)
