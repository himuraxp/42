/**
* MovieController
*
* @description :: Server-side logic for managing movies
* @help        :: See http://sailsjs.org/#!/documentation/concepts/Controllers
*/

module.exports = {
	dbMovie: function(req, res){
		console.log("start DB");
		var request = require('request');
		var cheerio = require('cheerio');
		var imdb = require('node-movie');
		var page = 1;
		var $;
		var $2;
		var dataMovie;
		var title;
		var url1 = "https://yts.ag/api/v2/list_movies.json?limit=50&page=";
		var url2 = "https://www.yify-torrent.org/search/mp4/t-";

		search(url1+page);

		function search(url){
			console.log(url);
			request(url, {headers: { 'Content-Type': 'application/json' }},function(error, response, html){
				if (!error && response.statusCode == 200) {
					dataMovie = JSON.parse(html);
					for (let i = 0; i < dataMovie.data.movies.length; i++) {
						request(dataMovie.data.movies[i].url, function(error, response, html){
							if (!error && response.statusCode == 200) {
								$ = cheerio.load(html);
								if (!$('.magnet-download').attr('href') || !dataMovie.data.movies[i])
								return ;
								Movie.create({
									title : dataMovie.data.movies[i].title,
									year: dataMovie.data.movies[i].year,
									note: dataMovie.data.movies[i].rating,
									poster: dataMovie.data.movies[i].medium_cover_image,
									magnet: $('.magnet-download').attr('href'),
									genre: dataMovie.data.movies[i].genres},
									function(err, created){
										if (err)
										{
											console.log("error dbMovie");
											console.log(err);
											return res.redirect("/");
										}
									})
								}
							})
						}
					}
					page++;
					if (page == 117)
					{
						console.log("2eme partie");
						page = 2;
						search2(url2+page+"/");
					}
					else
					search(url1+page);

				})
			}
			function search2(url){
				console.log(url);
				if (page == 255){
					console.log("end");
					return res.redirect("/");
				}
				else{
					request(url, function(error, response, html){
						if (!error && response.statusCode == 200) {
							$ = cheerio.load(html);
							fill_movie2($('.mdif a'), 0);
						}
						else {
							page++;
							search2(url2+page+"/");
						}
					})
				}
			}

			function fill_movie2(url, j){
				if (j == url.length)
				{
					page++;
					search2(url2+page+"/");
				}else {
					request("https://www.yify-torrent.org"+url[j].attribs.href, function(error, response, html){
						if (!error && response.statusCode == 200) {
							$2 = cheerio.load(html);
							dataMovie2();
							fill_movie2(url, j + 1);
							return ;
						}else {
							fill_movie2(url, j + 1);
						}

					})
				}
			}

			function dataMovie2() {
				title = $2('.name h1').text().replace(/\(.*\).+/, "");
				title = title.replace(/(rar|mp4|EXTENDED|UNRATED)/g, "");
				imdb(title, function (err, data) {
					if (data.Actors == "N/A"){
						title = $2('.name h1').text().replace(/(and)/, "&");
						dataMovie2();
					}
					else {
						Movie.create({
							title : $2('.name h1').text(),
							year: data.Year ? data.Year : 'N/A',
							note: data.imdbRating ? data.imdbRating : 'N/A',
							poster: data.Poster ? data.Poster : 'https:'+$2('.cover img').attr('src'),
							magnet: $2('.large.button.orange').attr('href'),
							genre: data.Genre ? data.Genre : $2('.inattr li a').text()},
							function(err, created){
								if (err)
								{
									console.log("error dbMovie");
									console.log(err);
									return res.redirect("/");
								}
							})
						}
					});
				}
			},

			download: function(req, res){
				if (!req.isSocket) {
					console.log("error");
					return res.badRequest();
				}
				console.log('DL');
				////////////////////////////////////////////////////////////////
				var Torrent = require('torrent-xiv');
				var prog = [];
				var path = 0;
				console.log(req.param('magnet_link'));
				console.log(req.param('title_movie'));
				var torrent = new Torrent(req.param('magnet_link'), { connections: 100,      // Max number of connections
					uploads: 10,           // Max number of upload slots
					path: 'assets/videos-xiv',     // Directory to save files to
					mkdir: true,           // Make a directory in opts.path? Name will be the info hash
					seed: false,           // NYI - Seed the torrent when done instead of quitting?
					start: true,           // Auto-start the download?
					statFrequency: 2000 });
					torrent.on('metadata', function(data) {
						stringify = JSON.stringify(data);
						split = stringify.split('"path":')
						console.log(split[2]);
						if (split[2].match(/.mp4/)) {
							path = 1;
						}
					});
					torrent.on('progress', emitProg);
					torrent.on('complete', emitMovie);
					function emitMovie(value){
						console.log('Download complete');
						sails.sockets.join(req, req.session.user.id);
						sails.sockets.broadcast(req.session.user.id,
							"stream_"+req.param('eventpop'),torrent.metadata.files[path].path.replace("assets", ""));
						}

						function emitProg(value){
							sails.sockets.join(req, req.session.user.id);
							sails.sockets.broadcast(req.session.user.id, "load_"+req.param('loadpop'),Math.floor(value.percentage));
							console.log(value.percentage + '%');
						}
					},

					searchMovie: function(req, res){
						if (req.session.etat === "connecté") {
							sails.sockets.join(req, req.session.user.id);
							if (req.param("movie") === "" || !req.param("movie") || req.param('movie') == "populate"){
								console.log("default Page => Populate");
							}else {
								Movie.find({title: {'like': '%'+req.param("movie")+'%'}}).exec(function(err, records){
									sails.sockets.broadcast(req.session.user.id, 'video', JSON.stringify(records));
								});
							}
						}
					},

					populate: function(req, res){
						console.log("faire requete SQL");
					},

				};
