/**
* AdminController
*
* @description :: Server-side logic for managing admins
* @help        :: See http://sailsjs.org/#!/documentation/concepts/Controllers
*/

module.exports = {
	listUsers: function(req, res) {
		var page = 1;
		var update = 0;
		if (req.url.match("page=")) {
			url = req.url.split("page=")
			if (url[1].match("OK=update")) {
				url = url[1].split("\?OK=update")
				url[1] = url[0]
				update = 1
			}
			if (url[1]) {
				if (Number(url[1])) {
					page = url[1]
					User.find().paginate({page: page, limit: 10}).exec(function(err, found){
						if (err)
							return res.serverError(err);
						return res.view('gestionUsers', {listUsers: found, page: page, update: update});
					});
				} else {
					User.find().paginate({page: page, limit: 10}).exec(function(err, found){
						if (err)
							return res.serverError(err);
						return res.view('gestionUsers', {listUsers: found, page: page, update: update});
					});
				}
			}
		} else {
			User.find().paginate({page: page, limit: 10}).exec(function(err, found){
				if (err)
					return res.serverError(err);
				return res.view('gestionUsers', {listUsers: found, page: page, update: update});
			});
		}
	},

	adminUpdateUser: function(req, res) {
		User.find({ email: req.param("email") }).exec(function(err, user){
			var temp = user.pop();
			var backURL=req.header('Referer') || '/';
			if (err) {
				return res.serverError(err);
			} else {
				if (req.param("firstName") !== "" && req.param("firstName") !== undefined)
				temp.firstName = req.param("firstName")
				if (req.param("lastName") !== "" && req.param("lastName") !== undefined)
				temp.lastName = req.param("lastName")
				if (req.param("pseudo") !== "" && req.param("pseudo") !== undefined)
				temp.pseudo = req.param("pseudo")
				if (req.param("active") !== "" && req.param("active") !== undefined)
				user.active = req.param("active")
				if (req.param("codeActive") !== "" && req.param("codeActive") !== undefined)
				temp.codeActive = req.param("codeActive")
				if (req.param("admin") !== "" && req.param("admin") !== undefined)
				user.admin = req.param("admin")
				if (req.param("googleId") !== "" && req.param("googleId") !== undefined)
				temp.googleId = req.param("googleId")
				if (req.param("facebookId") !== "" && req.param("facebookId") !== undefined)
				user.facebookId = req.param("facebookId")
				if (req.param("twitterId") !== "" && req.param("twitterId") !== undefined)
				temp.twitterId = req.param("twitterId")
				if (req.param("id_42") !== "" && req.param("id_42") !== undefined)
				temp.id_42 = req.param("id_42")
				if (req.param("language") !== "" && req.param("language") !== undefined)
				temp.language = req.param("language")
				temp.save(function(err){
					if (err)
						return res.serverError(err);
					if (backURL.match("OK=update")) {
						return res.redirect(backURL)
					} else {
						return res.redirect(backURL + "?OK=update")
					}
				});
			}

		});
	},
};
