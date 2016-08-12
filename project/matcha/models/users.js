let connection = require('../config/db')
let moment = require('../config/moment')

class User {

	constructor (row) {
		this.row = row
	}

	get id () {
		return this.row.id
	}

	get name () {
		return this.row.name
	}

	get first_name () {
		return this.row.first_name
	}

	get last_name () {
		return this.row.last_name
	}

	get pseudo () {
		return this.row.pseudo
	}

	get email () {
		return this.row.email
	}

	get sex () {
		return this.row.sex
	}

	get like_sex () {
		return this.row.like_sex
	}

	get birthday () {
		return this.row.birthday
	}

	get bday () {
		return moment(this.row.birthday)
	}

	get created_at () {
		return moment(this.row.created_at)
	}

	static all (cb) {
		let query = 'SELECT * FROM users'
		connection.query(query, (err, rows) => {
			if (err) throw err
			cb(rows.map((row) => new User(row)))
		})
	}

	static find (id, cb) {
		let query = 'SELECT * FROM users WHERE id = ? LIMIT 1'
		connection.query(query, [id], (err, rows) => {
			if (err) throw err
			cb(new User(rows[0]))
		})
	}

	static find_by_email (email, cb) {
		let query = 'SELECT * FROM users WHERE email = ? LIMIT 1'
		connection.query(query, [email], (err, rows) => {
			if (err) {
				return cb("error")
			} else {
				return cb(rows[0])
			}
		})
	}

	static find_account (user, cb) {
		let query = 'SELECT * FROM users WHERE email = ?, password = ?, LIMIT 1'
		connection.query(query, [user.email, user.password], (err, rows) => {
			if (err) {
				return cb("error")
			} else {
				return cb(rows[0])
			}
		})
	}


	static update_account (id, new_type, type, cb) {
		let query = 'UPDATE users SET ' + type + ' = ? WHERE id = ?'
		let user_type = undefined
		user_type = new_type
		if (type === 'sex') {
			if (user_type !== 'Homme' && user_type !== 'Femme') {
				user_type = 'Homme'
			}
		}
		if (user_type && user_type !== "error") {
			connection.query(query, [user_type, id], (err, result) => {
				if (err) throw err
				cb(result)
			})
		} else {
			cb("error")
		}
	}
}
module.exports = User
