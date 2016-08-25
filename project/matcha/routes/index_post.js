var request = require("request");
var User = require("../models/users.js");
var Picture = require("../models/picture.js");
var get_cookies = function(request) {
	var cookies = {};
	request.headers && request.headers.cookie.split(';').forEach(function(cookie) {
		var parts = cookie.match(/(.*?)=(.*)$/)
		cookies[ parts[1].trim() ] = (parts[2] || '').trim();
	});
	return cookies;
};
// Proxy through YQL.
var whereURL = 'https://query.yahooapis.com/v1/public/yql?format=json&q=select * from geo.placefinder where gflags="R" and text="{LAT},{LON}"';

// express extends the Node concept of request/response HTTP architecture,
// but also keeps true to the basic idea.
var revgeo = function(lat, lon, users, callback) {
	var url = whereURL.replace("{LAT}", lat).replace("{LON}", lon);

	request(url, function(error, response, contentBody) {
		// Attempt to build the interpoloated address, or fail.
		var address;
		try {
			address = JSON.parse(contentBody).query.results.Result;
			address = Array.isArray(address) ? address[0] : address;
			address = address.line1 + " " + address.line2;
		}
		catch(e) {
			callback("Could not retrieve the location at "+lat+", "+lon);
			return;
		}

		if (error || response.statusCode != 200) {
			callback("Error contacting the reverse geocoding service.");
		}
		else {
			callback(null, address);
		}
	});
};

module.exports = function(req, res) {
	if (req.body.latitude && req.body.longitude) {
		var latitude = req.body.latitude;
		var longitude = req.body.longitude;
	} else {
		var latitude = 48.866566;
		var longitude = 2.338023;
	}
	var id = get_cookies(req)['uid'];
	var lat = [];
	var lng = [];
	var tmp = [];
	var title = [];
	var latLon = [];
	User.all(function(users) {
		Picture.all(function(pic) {
			User.init_geo(id, latitude, longitude, function(cb) {
				revgeo(latitude, longitude, users, function(err, address) {
					for (var i = 0; i < users.length; i++) {
						lat[i] = JSON.parse(users[i].lat)
						lng[i] = JSON.parse(users[i].lon)
						tmp[i] = JSON.stringify(users[i].pseudo)
						latLon[i] = {lat: lat[i], lng: lng[i]}
						title[i] = {title: tmp[i]}
					}
					function jsFriendlyJSONStringify (s) {
						return JSON.stringify(s).
						replace(/\"/g, '').
						replace(/\\/g, '');
					}
					latLon = jsFriendlyJSONStringify(latLon)
					console.log(latLon);

					res.render('pages/geo', {
						latLon: latLon,
						title: title,
						error: err,
						location: {
							latitude: latitude,
							longitude: longitude,
							address: address
						}
					});
				});
			});
		})

	})

};
