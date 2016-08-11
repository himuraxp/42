let connection = require('../config/db')

class Signup {

	static create (body, hash, cb) {
		let User = require('./users')
		let email_db = ''
		User.find_by_email(body.email, function (email_db) {
			let verify = email_db
			let pseudo = body.pseudo
			let first_name = body.first_name
			let last_name = body.last_name
			let email = body.email
			let password = hash
			let name = first_name + " " + last_name
			if (verify) {
				return cb('error')
			}
			else {
				connection.query('INSERT INTO users SET pseudo = ?, first_name = ?, last_name = ?, name = ?, email = ?, password = ?, created_at = ?', [
					pseudo,
					first_name,
					last_name,
					name,
					email,
					password,
					new Date()
				], (err, result) => {
					if (err) throw err
					cb(result)
				})
			}
		})
	}
}

module.exports = Signup
