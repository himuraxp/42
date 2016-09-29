/**
 * AdminController
 *
 * @description :: Server-side logic for managing admins
 * @help        :: See http://sailsjs.org/#!/documentation/concepts/Controllers
 */

module.exports = {
	listUsers: function(req, res) {
		console.log("test");
		  User.find().exec(function(err, found){
				if (err)
					return res.serverError(err);
				return res.view('gestionUsers', {listUsers: found});
		  });
	},
};
