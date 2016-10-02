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
		var error_msg = [
			"Format email incorrect !",
			"Format firstName incorrect !",
			"Le firstName ne peut possèder plus de 35 charactères"
		];
		if (req.url.match("page=")) {
			url = req.url.split("page=")
			if (url[1].match("OK=update")) {
				url = url[1].split("\?OK=update")
				url[1] = url[0]
				update = 1
			} else if (url[1].match("OFF=update")) {
				url = url[1].split("\?OFF=update")
				url[1] = url[0]
				update = 2
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
			if (req.url.match("OK=update")) {
				update = 1
			} else if (req.url.match("OFF=update")) {
				update = 2
			}
			User.find().paginate({page: page, limit: 10}).exec(function(err, found){
				if (err)
					return res.serverError(err);
				return res.view('gestionUsers', {listUsers: found, page: page, update: update});
			});
		}
	},

	adminUpdateUser: function(req, res) {
		User.find({ id: req.param("id_user") }).exec(function(err, user){
			var temp = user.pop();
			var backURL=req.header('Referer') || '/';
			if (err) {
				return res.serverError(err);
			} else {
				if (req.param("action") === "active") {
					temp.active = 1
				} else if (req.param("action") === "desactive") {
					temp.active = 0
				} else if (req.param("action") === "delete_pic") {
					temp.photo = null
				} else {
					var permit = 0
					if (req.param("permit") === "admin")
						permit = 1
					if (req.param("email") !== temp.email || req.param("firstName") !== temp.firstName || req.param("lastName") !== temp.lastName || req.param("pseudo") !== temp.pseudo || req.param("codeActive") !== temp.codeActive || permit !== temp.admin || req.param("language") !== temp.language) {
						if (req.param("email") !== "" && req.param("email") !== undefined) {
							if (req.param("email").match(/^[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]{2,}\.[a-z]{2,4}$/)) {
								temp.email = req.param("email")
							} else {
								if (backURL.match("OK=update")) {
									parseUrl = backURL.split("\?");
									if (parseUrl[1] && parseUrl[1] === "OK=update") {
										parseUrl[1] = "OFF=update-email"
										newUrl = parseUrl[0] + "?" + parseUrl[1]
									} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
										parseUrl[2] = "OFF=update-email"
										newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
									} else {
										newUrl = backURL
									}
									return res.redirect(newUrl)
								} else {
									return res.redirect(backURL + "?OFF=update-email")
								}
							}
						}
						if (req.param("firstName") !== "" && req.param("firstName") !== undefined) {
							count = req.param("firstName").length
							if (count > 1 && count < 35) {
								var check = req.param("firstName").match(/[A-z\- éèàç]/g).length
								if (check === count) {
									temp.firstName = req.param("firstName")
								} else {
									if (backURL.match("OK=update")) {
										parseUrl = backURL.split("\?");
										if (parseUrl[1] && parseUrl[1] === "OK=update") {
											parseUrl[1] = "OFF=update-firstName0"
											newUrl = parseUrl[0] + "?" + parseUrl[1]
										} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
											parseUrl[2] = "OFF=update-firstName0"
											newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
										} else {
											newUrl = backURL
										}
										return res.redirect(newUrl)
									} else {
										return res.redirect(backURL + "?OFF=update-firstName0")
									}
								}
							} else {
								if (backURL.match("OK=update")) {
									parseUrl = backURL.split("\?");
									if (parseUrl[1] && parseUrl[1] === "OK=update") {
										parseUrl[1] = "OFF=update-firstName1"
										newUrl = parseUrl[0] + "?" + parseUrl[1]
									} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
										parseUrl[2] = "OFF=update-firstName1"
										newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
									} else {
										newUrl = backURL
									}
									return res.redirect(newUrl)
								} else {
									return res.redirect(backURL + "?OFF=update-firstName1")
								}
							}
						}
						if (req.param("lastName") !== "" && req.param("lastName") !== undefined) {
							count = req.param("lastName").length
							if (count > 1 && count < 35) {
								var check = req.param("lastName").match(/[A-z\- éèàç]/g).length
								if (check === count) {
									temp.lastName = req.param("lastName")
								} else {
									if (backURL.match("OK=update")) {
										parseUrl = backURL.split("\?");
										if (parseUrl[1] && parseUrl[1] === "OK=update") {
											parseUrl[1] = "OFF=update"
											newUrl = parseUrl[0] + "?" + parseUrl[1]
										} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
											parseUrl[2] = "OFF=update"
											newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
										} else {
											newUrl = backURL
										}
										return res.redirect(newUrl)
									} else {
										return res.redirect(backURL + "?OFF=update")
									}
								}
							} else {
								if (backURL.match("OK=update")) {
									parseUrl = backURL.split("\?");
									if (parseUrl[1] && parseUrl[1] === "OK=update") {
										parseUrl[1] = "OFF=update"
										newUrl = parseUrl[0] + "?" + parseUrl[1]
									} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
										parseUrl[2] = "OFF=update"
										newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
									} else {
										newUrl = backURL
									}
									return res.redirect(newUrl)
								} else {
									return res.redirect(backURL + "?OFF=update")
								}
							}
						}
						if (req.param("pseudo") !== "" && req.param("pseudo") !== undefined) {
							count = req.param("pseudo").length
							if (count > 1 && count < 36) {
								var check = req.param("pseudo").match(/[A-z0-9\- éèàç]/g).length
								if (check === count) {
									temp.pseudo = req.param("pseudo")
								} else {
									if (backURL.match("OK=update")) {
										parseUrl = backURL.split("\?");
										if (parseUrl[1] && parseUrl[1] === "OK=update") {
											parseUrl[1] = "OFF=update"
											newUrl = parseUrl[0] + "?" + parseUrl[1]
										} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
											parseUrl[2] = "OFF=update"
											newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
										} else {
											newUrl = backURL
										}
										return res.redirect(newUrl)
									} else {
										return res.redirect(backURL + "?OFF=update")
									}
								}
							} else {
								if (backURL.match("OK=update")) {
									parseUrl = backURL.split("\?");
									if (parseUrl[1] && parseUrl[1] === "OK=update") {
										parseUrl[1] = "OFF=update"
										newUrl = parseUrl[0] + "?" + parseUrl[1]
									} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
										parseUrl[2] = "OFF=update"
										newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
									} else {
										newUrl = backURL
									}
									return res.redirect(newUrl)
								} else {
									return res.redirect(backURL + "?OFF=update")
								}
							}
						}
						if (req.param("codeActive") !== "" && req.param("codeActive") !== undefined) {
							temp.codeActive = req.param("codeActive")
						} else {
							temp.codeActive = null
						}
						if (req.param("permit") !== "" && req.param("permit") !== undefined) {
							if (req.param("permit") === "member") {
								temp.admin = 0
							} else if (req.param("permit") === "admin") {
								temp.admin = 1
							} else {
								if (backURL.match("OK=update")) {
									parseUrl = backURL.split("\?");
									if (parseUrl[1] && parseUrl[1] === "OK=update") {
										parseUrl[1] = "OFF=update"
										newUrl = parseUrl[0] + "?" + parseUrl[1]
									} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
										parseUrl[2] = "OFF=update"
										newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
									} else {
										newUrl = backURL
									}
									return res.redirect(newUrl)
								} else {
									return res.redirect(backURL + "?OFF=update")
								}
							}
						}
						if (req.param("language") !== "" && req.param("language") !== undefined) {
							if (req.param("language") === "English" || req.param("language") === "Français") {
								temp.language = req.param("language")
							} else {
								if (backURL.match("OK=update")) {
									parseUrl = backURL.split("\?");
									if (parseUrl[1] && parseUrl[1] === "OK=update") {
										parseUrl[1] = "OFF=update"
										newUrl = parseUrl[0] + "?" + parseUrl[1]
									} else if (parseUrl[2] && parseUrl[2] === "OK=update") {
										parseUrl[2] = "OFF=update"
										newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
									} else {
										newUrl = backURL
									}
									return res.redirect(newUrl)
								} else {
									return res.redirect(backURL + "?OFF=update")
								}
							}
						}
					} else {
						if (backURL.match("OK=update") || backURL.match("OFF=update")) {
							parseUrl = backURL.split("\?");
							if (parseUrl[1] && (parseUrl[1] === "OK=update" || parseUrl[1] === "OFF=update")) {
								newUrl = parseUrl[0]
							} else if (parseUrl[2] && (parseUrl[2] === "OK=update" || parseUrl[2] === "OFF=update")) {
									newUrl = parseUrl[0] + "?" + parseUrl[1]
							} else {
								newUrl = backURL
							}
							return res.redirect(newUrl)
						} else {
							return res.redirect(backURL)
						}
					}
				}
				temp.save(function(err){
					if (err)
						return res.serverError(err);
					if (backURL.match("OK=update")) {
						return res.redirect(backURL)
					} else if (backURL.match("OFF=update")){
						parseUrl = backURL.split("\?");
						if (parseUrl[1] && parseUrl[1] === "OFF=update") {
							parseUrl[1] = "OK=update"
							newUrl = parseUrl[0] + "?" + parseUrl[1]
						} else if (parseUrl[2] && parseUrl[2] === "OFF=update") {
							parseUrl[2] = "OK=update"
							newUrl = parseUrl[0] + "?" + parseUrl[1] + "?" + parseUrl[2]
						} else {
							newUrl = backURL
						}
						return res.redirect(newUrl)
					}  else {
						return res.redirect(backURL + "?OK=update")
					}
				});
			}

		});
	},

};
