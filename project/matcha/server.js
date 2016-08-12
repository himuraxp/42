
let express		= require('express')
let bodyParser	= require('body-parser')
let session		= require('express-session')
let cookieParser= require('cookie-parser')
let moment		= require('./config/moment')
var fileUpload	= require('express-fileupload')
var fs 			= require('fs')
// var Promise		= require('promise')
let app			= express()

// Template
app.set('view engine', 'ejs')

// Middleware
app.use('/assets', express.static('public'))
app.use('/client', express.static('client'))
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
	if (get_cookies(req)['uid']) {
		res.redirect('/home')
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
		Signin.find_account(req.body, function (user) {
			let sha256 = require('sha256')
			let new_hash = sha256(req.body.password)
			if (new_hash === user.password) {
				req.flash('success', "Connexion réussi !")
				res.cookie('uid', user.id)
				res.redirect('/home')
			} else {
				req.flash('error', "Email ou mot de passe invalide !")
				res.removeCookie('id')
				res.redirect('/')
			}
		})
	}

})

app.get('/home', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	id = get_cookies(req)['uid']
	path = "./public/upload/" + id
	User.find(id, function (user) {
		if (id) {
			fs.access(path, fs.F_OK, function(err) {
				if (!err) {
					res.render('pages/index', {user: user})
				} else {
					Picture.init(id)
					fs.mkdirSync('./public/upload/' + id)
					res.render('pages/index', {user: user})
				}
			})
		} else {
			res.render('layout/index')
		}
	})
})

app.get('/profil', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	id = get_cookies(req)['uid']
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
		Picture.find(id, function (picture) {
			if (id) {
				res.render('pages/user/profil', {user: user, picture: picture})
			} else {
				res.render('layout/index')
			}
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
app.post('/profil/editer', (req, res) => {
	let regex = /^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])([a-zA-Z0-9<>@#$%^&+=*.\-_\(\)\\\!\{\}\[\]\`\~\|\"\'\;\:\/\?\,]){3,}$/
	let User = require('./models/users')
	User.find(get_cookies(req)['uid'], function (user) {
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
})


app.get('/coffee', (req, res) => {
	let User = require('./models/users')
	let Picture = require('./models/picture')
	id = get_cookies(req)['uid']
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
		Picture.find(id, function (picture) {
			if (id) {
				res.render('pages/coffee', {user: user, picture: picture})
			} else {
				res.render('layout/index')
			}
		})
	})
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
				req.flash('success', "Félicitation votre compte est créer !")
				res.redirect('/')
			}
		})
	} else {
		req.flash('error', "Le mot de passe doit comporter au minimum une MAJUSCULE, une MINUSCULE et un CHRIFFRE !")
		res.redirect('/signup')
	}
})


app.get('/user/:id', (req, res) => {
	let User = require('./models/users')
	User.find(req.params.id, function (user) {
		res.render('pages/user', {user: user})
	})
})

app.listen(8080)
