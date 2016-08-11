let mysql      = require('mysql');
let connection = mysql.createConnection({
	host     : 'localhost',
	user     : 'root',
	password : 'root',
	database : 'matcha',
	port     : '8889'
});
connection.connect()

module.exports = connection
