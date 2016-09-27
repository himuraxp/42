let connection = require('../config/db')

class Signin {

	static find_account (user, cb) {
		connection.query('SELECT * FROM users WHERE email = ? LIMIT 1', [user.email], (err, rows) => {
			if (err) throw err
			cb(rows[0])
		})
	}

	static connected (id, cb) {
		let query = 'UPDATE users SET connected = ? WHERE id = ?'
		connection.query(query, ["on", id], (err, result) => {
			if (err) throw err
			return cb(result)
		})
	}

	static disconnect (id, cb) {
		let query = 'UPDATE users SET connected = ?, last_connect = ? WHERE id = ?'
		connection.query(query, ["off", new Date(), id], (err, result) => {
			if (err) throw err
			return cb(result)
		})
	}
}

module.exports = Signin
