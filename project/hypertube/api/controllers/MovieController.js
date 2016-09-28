/**
 * MovieController
 *
 * @description :: Server-side logic for managing movies
 * @help        :: See http://sailsjs.org/#!/documentation/concepts/Controllers
 */

module.exports = {

        searchMovie: function(req, res){
                console.log("movie");
                var request = require('request');
                var cheerio = require('cheerio');
                var imdb = require('node-movie');
                var movie = [];
                var url = "http://www.legittorrents.info/index.php?page=torrents&search="+req.param("movie")+"&category=1&active=1";
                var url2 = "http://torrentsmovies.net/?s="+req.param("movie");

                request(url, function (error, response, html) {
                        if (!error && response.statusCode == 200) {
                           var $ = cheerio.load(html);
                           var i = 1;

                           $('.lista a').each(function() {
                                if ($(this).attr('title')){
                                        movie[i] = {
                                                        title : $(this).text(),
                                                        infos : "http://www.legittorrents.info/"+$(this).attr('href'),
                                                        rating : "",
                                                        prod : "",
                                                        img : "",
                                                        dl : ""
                                        };
                                }
                                else if ($(this).attr('href').match(/download/)) {
                                        movie[i].dl = "http://www.legittorrents.info/"+$(this).attr('href');
                                        i++;
                                }
                          });
                    }
                    sails.log(movie[1].title+" // "+movie[1].dl);
                });

                // for (var i = 1; i < movie.length; i++) {
                //         var title = movie[i].description.title.replace(/\(.*\)/, "");
                //         title = title.replace(/-.*/, "");
                //         imdb(title, function (err, data) {
                //             note[i]  = data.imdbRating;
                //             console.log(note[i]);
                //             });
                // }
                // console.log(note[5]);

                request(url2, function(error, response, html){
                        if (!error && response.statusCode == 200) {
                           var $ = cheerio.load(html);
                           var movie2 = [];
                           var j = 1;
                           $('.search-item h4 a').each(function() {
                                if ($(this).attr('href')){
                                        console.log(movie2);
                                        request($(this).attr('href'), function(error, response, html2){
                                                var $2 = cheerio.load(html2);
                                                if ($2('.post-entry center a').text().match(/Download .torrent/)){
                                                        movie2[j] = {
                                                                title : $2('div h1').attr('class', 'post-header').text(),
                                                                infos : "",
                                                                rating : "",
                                                                prod : "",
                                                                img : "",
                                                                dl : $2('.post-entry center a').attr('href')
                                                        };
                                                        j++;
                                                }
                                        });
                                }
                        });
                        }
                });
        },
};
