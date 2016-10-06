var passport = require('passport');

module.exports = {
	index: function (req, res) {
		var email = req.param('email');
		var password = req.param('password');
		if (!email || !password) {
			return res.json(401, {err: 'email and password required'});
		}
		User.findOne({email: email}, function (err, user) {
			if (!user) {
				return res.json(401, {err: 'invalid email or password'});
			}

			User.comparePassword(password, user, function (err, valid) {
				if (err) {
					return res.json(403, {err: 'forbidden'});
				}

				if (!valid) {
					return res.json(401, {err: 'invalid email or password'});
				} else {
					res.json({
						user: user,
						token: jwToken.issue({id : user.id })
					});
				}
			});
		})
	},
	login: function(req, res) {
		res.view('../views/login');
	},

	process: function(req, res) {
		User.find({pseudo: req.param('pseudo')}).exec(function(err, found){
			if (err){
				console.log("Error find pseudo login"+err);
				return res.send(err);
			}
			else if(found == ""){
				return res.view('login', {badmail: "pseudo"});
			}
			else {
				found.forEach(function(result){
					if (result.active != "1")
					return res.view('../views/login', {error: "notActive"});
					else {
						passport.authenticate('local', function(err, user, info) {
							if( (err)||(!user) ) {
								return res.view('../views/login', {error: "badlog"});
							}
							req.logIn(user, function(err) {
								if(err) res.send(err);
								req.session.etat = "connecté";
								req.session.user = user;
								req.session.me = req.param('pseudo');
								return res.view('../views/homepage');
							});
						}) (req, res);
					}
				});
			}
		});
	},

	logout: function(req, res) {
		req.logOut();
		req.session.etat = "déconnecté";
		req.session.me = "";
		req.session.user = "";
		res.redirect('/');
	},

	authenticate: function(req,res){
		passport.authenticate('google',{scope:['https://www.googleapis.com/auth/userinfo.profile', 'https://www.googleapis.com/auth/userinfo.email']},
		function (err, user) {
			req.logIn(user, function (err) {
				if(err) {
					console.log("test");
					req.session.flash = 'There was an error';
					res.redirect('login');
					// console.log(err);
				} else {
					console.log("test2");
					req.session.etat = "connecté";
					req.session.user = user;
					req.session.me = user.firstName;
					res.redirect('/');
				}
			});
		})(req,res);
	},
	authcallback: function(req,res){
		passport.authenticate('google', {failureRedirect: 'login',successRedirect:'/'},
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
		})(req,res);
	},

	// authRest: function(req,res){
	// 	auth.authenticateUser(function(pseudo, password, callback) {
	// 		User.findOne({ pseudo: pseudo }, function(err, user) {
	// 			if (err) {
	// 				return callback(err);
	// 			}
	// 			if (! user) {
	// 				return callback(null, false, 'User does not exists');
	// 			}
	// 			if (hash(password) !== user.password) {
	// 				return callback(null, false, 'Invalid password');
	// 			}
	// 			req.session.etat = "connecté";
	// 			req.session.user = user;
	// 			req.session.me = pseudo;
	// 			// The username and password should be given here
	// 			callback(null, {
	// 				pseudo: pseudo,
	// 				password: user.password
	// 			});
	// 		});
	// 	})(req,res);
	// }
};

module.exports.blueprints = {
	actions: true,
	rest: true,
	shortcuts: true
};
