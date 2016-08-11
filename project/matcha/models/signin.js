let connection = require('../config/db')

class Signin {

	static find_account (user, cb) {
		connection.query('SELECT * FROM users WHERE email = ? LIMIT 1', [user.email], (err, rows) => {
			if (err) throw err
			cb(rows[0])
		})
	}
}

module.exports = Signin
