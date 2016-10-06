/**
* UserController
*
* @description :: Server-side logic for managing users
* @help        :: See http://sailsjs.org/#!/documentation/concepts/Controllers
*/
var passport = require('passport');
module.exports = {
	///////////////////////login////////////////////////////
	login: function (req, res) {
		res.view();
	},

	///////////////////////logout////////////////////////////
	logout: function (req, res){
		req.session.user = null;
		req.session.flash = 'You have logged out';
		req.logOut();
		req.session.etat = "déconnecté";
		res.redirect('/');

	},

	///////////////////////twitter////////////////////////////
	'twitter': function(req, res, next){
		passport.authenticate('twitter',
		function (err, user) {
			req.logIn(user, function (err) {
				if(err) {
					req.session.flash = 'There was an error';
					res.redirect('login');
					console.log(err);
				} else {
					req.session.etat = "connecté";
					req.session.user = user;
					req.session.me = user.firstName;
					res.redirect('/');
				}
			});
		})(req, res, next);
	},

	///////////////////////twitter/callback////////////////////////////
	'twitter/callback': function(req, res, next){
		passport.authenticate('twitter',
		function(req, res) {
			res.redirect('/');
		})(req, res, next);
	},

	///////////////////////facebook////////////////////////////
	'facebook': function (req, res, next) {
		passport.authenticate('facebook', { scope: ['email', 'user_about_me']},
		function (err, user) {
			req.logIn(user, function (err) {
				if(err) {
					req.session.flash = 'There was an error';
					res.redirect('login');
					// console.log(err);
				} else {
					req.session.etat = "connecté";
					req.session.user = user;
					req.session.me = user.firstName;
					res.redirect('/');
				}
			});
		})(req, res, next);
	},

	///////////////////////facebook/callback////////////////////////////
	'facebook/callback': function (req, res, next) {
		passport.authenticate('facebook',
		function (req, res) {
			res.redirect('/');
		})(req, res, next);
	},

	///////////////////////42////////////////////////////
	'auth_42': function(req, res, next){

		passport.authenticate('oauth2',
		function (err, user) {
			req.logIn(user, function (err) {
				if(err) {
					console.log(err);
					req.session.flash = 'There was an error';
					res.redirect('login');
				} else {
					req.session.etat = "connecté";
					req.session.user = user;
					req.session.me = user.firstName;
					res.redirect('/');
				}
			});
		})(req, res, next);
	},

	///////////////////////42/callback////////////////////////////
	'auth_42/callback': function(req, res, next){
		passport.authenticate('oauth2',
		function(req, res) {
			res.redirect('/');
		})(req, res, next);
	},

	///////////////////////getUsers////////////////////////////
	getUsers: function(req, res) {
		User.find().exec(function(err, found){
			if (err)
			return res.serverError(err);
			return res.view('listUsers', {listUsers: found});
		});
	},

	///////////////////////activedAccount////////////////////////////
	activedAccount: function(req, res){
		User.find({where : {email: req.param("email"), codeActive: req.param("codeActive")}}).exec(function(err){
			if (err){
				console.log("ERROR find update=> "+err);
				return;
			}else {
				User.update({active: "0"}, {active: "1"}, {where : {email: req.param("email")}}).exec(function afterwards(err){
					if (err){
						console.log("ERROR update=> "+err);
						return;
					}
				})
			}
			req.session.actived = "actived";
			return res.redirect("/");
		});
	},

	///////////////////////modify////////////////////////////
	modify: function (req, res) {
		var mail = !req.param('Email') ? req.session.user.email : req.param('Email');
		var regexpMaj = /[A-Z]/g;
		var regexpMin = /[a-z]/g;
		var regexpNum = /[0-9]/gi;
		var regexpMail = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]{2,}\.[a-z]{2,4}$/;
		if (!req.param('firstName') || !req.param('lastName') || !mail ||
		!req.param('pseudo') || !req.param('languageSelect'))
		{
			req.session.errSignup = "signupIncomplete";
			return res.redirect("/Users/me");
		}
		else if (!req.session.user.facebookId.match(/facebookId-/) && !req.session.user.twitterId.match(/twitterId-/) && !req.session.user.googleId.match(/googleId-/) && !req.session.user.googleId.match(/id_42-/) && !mail.match(regexpMail)) {
			req.session.errSignup = "badFormatMail";
			return res.redirect("/Users/me");
		}else {
			req.file('userPhoto').upload({
				dirname: process.cwd() +'/assets/images',
				maxBytes: 10000000
			},function whenDone(err,files){
				sails.log.debug('file is :: ', +files);
				if (err)
				return res.serverError(err);
				else if (files.length === 0 && !req.session.user.photo){
					req.session.errSignup = "signupIncomplete";
					return res.redirect("/Users/me");
				}
				else {
					if (req.session.user.photo && files.length === 0)
					{
						User.query("update user set firstName = '"+req.param('firstName')+"', lastName = '"+req.param('lastName')+"', email = '"+mail+"',"+
						" pseudo = '"+req.param('pseudo')+"', language = '"+req.param('languageSelect')+"' where id = '"+req.session.user.id+"'"
						, function(err, updated){
							if (!err){
								req.session.errSignup = "updated";
								User.find().where({id: req.session.user.id}).exec(function(err, found){
									req.session.user = found[0];
									return res.redirect("/Users/me");
								});
							}
							else {
								console.log("error update"+err);
								var re =  new RegExp('\\bemail\\b','i');
								var match = [];
								match[0] = re.exec(err);
								match[1] = mail;
								if (match && match[0] == "email"){
									req.session.match = match;
									return res.redirect("/Users/me");
								}
								else {
									match[0] = "pseudo";
									match[2] = req.param('pseudo');
									req.session.match = match;
									return res.redirect("/Users/me");
								}
							}
						});
					}else {
						const fs = require('fs');
						var filename = files[0].fd.substring(files[0].fd.lastIndexOf('/')+1);
						var uploadLocation = process.cwd() +'/assets/images/' + filename;
						var tempLocation = process.cwd() + '/.tmp/public/images/' + filename;
						//Copy the file to the temp folder so that it becomes available immediately
						fs.createReadStream(uploadLocation).pipe(fs.createWriteStream(tempLocation));

						files.forEach(function(path){
							path = path.fd.replace(/.*assets/, "");
							User.query("update user set firstName = '"+req.param('firstName')+"', lastName = '"+req.param('lastName')+"', email = '"+mail+"',"+
							" pseudo = '"+req.param('pseudo')+"', language = '"+req.param('languageSelect')+"', photo = '"+path+"' where id = '"+req.session.user.id+"'"
							, function(err, updated){
								if (!err){
									if (req.session.user.photo){
										fs.unlink("assets"+req.session.user.photo, function(err){
											if (err){
												console.log(err);
												return res.redirect("/Users/me");
											}else {
												req.session.errSignup = "updated";
												User.find().where({id: req.session.user.id}).exec(function(err, found){
													req.session.user = found[0];
													return res.redirect("/Users/me");
												});
											}
										});
									}else {
										req.session.errSignup = "updated";
										User.find().where({id: req.session.user.id}).exec(function(err, found){
											req.session.user = found[0];
											return res.redirect("/Users/me");
										});
									}
								}
								else {
									console.log("error update"+err);
									var re =  new RegExp('\\bemail\\b','i');
									var match = [];
									match[0] = re.exec(err);
									match[1] = mail;
									if (match && match[0] == "email"){
										req.session.match = match;
										return res.redirect("/Users/me");
									}
									else {
										match[0] = "pseudo";
										match[2] = req.param('pseudo');
										req.session.match = match;
										return res.redirect("/Users/me");
									}
								}
							});
						});
					}
				}
			});
		}
	},
	///////////////////////createUserByApi////////////////////////////

	createApi: function (req, res) {
		if (req.body.password !== req.body.confirmPassword) {
			return res.json(401, {err: 'Password doesn\'t match, What a shame!'});
		}
		Users.create(req.body).exec(function (err, user) {
			if (err) {
				return res.json(err.status, {err: err});
			}
			// If user created successfuly we return user and token as response
			if (user) {
				// NOTE: payload is { id: user.id}
				res.json(200, {user: user, token: jwToken.issue({id: user.id})});
			}
		});
	},
	///////////////////////createUser////////////////////////////
	createUser: function (req, res) {
		var str = req.param('password');
		var mail = req.param('Email');
		var regexpMaj = /[A-Z]/g;
		var regexpMin = /[a-z]/g;
		var regexpNum = /[0-9]/gi;
		var regexpMail = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]{2,}\.[a-z]{2,4}$/;
		if (!req.param('firstName') || !req.param('lastName') || !req.param('Email') || !req.param('pseudo') ||
		!req.param('password') || !req.param('languageSelect'))
		{
			req.session.errSignup = "signupIncomplete";
			return res.redirect("/");
		}
		else if (!mail.match(regexpMail)) {
			req.session.errSignup = "badFormatMail";
			return res.redirect("/");
		}
		else if (str.length <= 7 || !str.match(regexpMaj) || !str.match(regexpMin) || !str.match(regexpNum)){
			req.session.errSignup = "badFormatPwd";
			return res.redirect("/");
		}else {
			req.file('userPhoto').upload({
				dirname: process.cwd() +'/assets/images',
				maxBytes: 10000000
			},function whenDone(err,files){
				sails.log.debug('file is :: ', +files);
				if (err)
				return res.serverError(err);
				if (files.length === 0){
					req.session.errSignup = "signupIncomplete";
					return res.redirect("/");
				}
				const fs = require('fs');
				var filename = files[0].fd.substring(files[0].fd.lastIndexOf('/')+1);
				var uploadLocation = process.cwd() +'/assets/images/' + filename;
				var tempLocation = process.cwd() + '/.tmp/public/images/' + filename;
				//Copy the file to the temp folder so that it becomes available immediately
				fs.createReadStream(uploadLocation).pipe(fs.createWriteStream(tempLocation));

				files.forEach(function(path){

					var bcrypt = require('bcrypt');
					bcrypt.genSalt(12, function(err, salt) {
						bcrypt.hash(req.param('firstName')+req.param('lastName'), salt, function(err, hash) {
							if(err) {
								console.log(err);
							} else {
								var code = hash.replace(/\\/g, "");
								code = code.replace(/\//g, "");
								path = path.fd.replace(/.*assets/, "");
								User.create( {facebookId : "fb_Id"+code,
								twitterId: "tw_Id"+code,
								googleId: "g+_eId"+code,
								id_42: "42_id"+code,
								firstName: req.param('firstName'),
								lastName: req.param('lastName'),
								email: req.param('Email'),
								pseudo: req.param('pseudo'),
								password: req.param('password'),
								language: req.param('languageSelect'),
								codeActive: code,
								photo: path}, function(err, created){
									if (!err){
										var nodemailer = require('nodemailer');
										var transporter = nodemailer.createTransport({
											service: 'Gmail',
											auth: {
												user: 'michaelbouhier66@gmail.com',
												pass: 'bikernumber13'
											}
										});

										// setup e-mail data with unicode symbols
										var mailOptions = {
											from: '"Admin Hyper" <no-reply@hypertube.com>', // sender address
											to: req.param('Email'), // list of receivers
											subject: 'Inscription', // Subject line
											//     text: 'Hello world ?', // plaintext body
											html: '<b>Cliquez sur ce lien pour activez votre compte :</b>'+
											'<a href="http://localhost:1337/Users/activedAccount/'+req.param('Email')+'&'+code+'">Activez votre compte</a>'// html body
										};
										// send mail with defined transport object
										transporter.sendMail(mailOptions, function(error, info){
											if(error){
												return console.log(error);
											}
											console.log('Message sent: ' + info.response);
										});
										return res.view('homepage',  {created: "created"});
									}
									else {
										console.log(err);
										var re =  new RegExp('\\bemail\\b','i');
										var match = [];
										match[0] = re.exec(err);
										match[1] = req.param('Email');
										if (match && match[0] == "email"){
											req.session.match = match;
											return res.redirect("/");
											//     return res.view("../views/homepage", {match :match});
										}
										else {
											match[0] = "pseudo";
											match[2] = req.param('pseudo');
											req.session.match = match;
											return res.redirect("/");
											//     return res.view("../views/homepage", {match :match});
										}
									}
								});

							}
						});
					});
				});
			});
		}
	},

	///////////////////////forget////////////////////////////
	forget: function(req, res) {
		var rand = require("generate-key");
		var newPass = rand.generateKey(); // => wexO23UXGezfTKHc
		// console.log("New pass: "+newPass);

		var bcrypt = require('bcrypt');
		bcrypt.genSalt(10, function(err, salt) {
			bcrypt.hash(newPass, salt, function(err, hash) {
				if(err) {
					console.log(err);
				} else {
					//     console.log("hash: "+hash);
					//     update
					User.find({where : {email: req.param("email")}}).exec(function(err, found){
						if (err){
							console.log("Error of find forget !!"+err);
							return res.serverError(err);
						}
						else if (found == "") {
							console.log("forget bad mail");
							return res.view("login", {forget: "forget"});
						}
						else {
							found.forEach(function(user){
								var pass = user.password;
								//   console.log("pass online = "+pass);
								User.update({password: pass}, {password: hash}, {where : {email: req.param("email")}}).exec(function afterwards(err){
									if (err){
										console.log("ERROR update=> "+err);
										return;
									}
									//     email
									var nodemailer = require('nodemailer');
									var transporter = nodemailer.createTransport({
										service: 'Gmail',
										auth: {
											user: 'michaelbouhier66@gmail.com',
											pass: 'bikernumber13'
										}
									});
									// console.log("email = "+req.param('email'));

									// setup e-mail data with unicode symbols
									var mailOptions = {
										from: '"Admin Hyper" <no-reply@hypertube.com>', // sender address
										to: req.param('email'), // list of receivers
										subject: 'New password', // Subject line
										//     text: 'Hello world ?', // plaintext body
										html: 'Voici votre nouveau mot de passe : '+newPass// html body
									};
									// send mail with defined transport object
									transporter.sendMail(mailOptions, function(error, info){
										if(error){
											return console.log(error);
										}
										console.log('Message sent new pass: ' + info.response);
									});
									return res.redirect("/");
								});
							});
						}
					});
				}
			});
		});
	},
};
