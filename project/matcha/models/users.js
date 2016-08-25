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

	get likes () {
		return this.row.likes
	}

	get token () {
		return this.row.token
	}

	get birthday () {
		return this.row.birthday
	}

	get bday () {
		return moment(this.row.birthday)
	}

	get story () {
		return this.row.story
	}

	get lat () {
		return this.row.lat
	}

	get lon () {
		return this.row.lon
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
			if (err) {
				cb(err)
			} else {
				cb(new User(rows[0]))
			}
		})
	}

	static init_geo (id, lat, lon, cb) {
		if (lat && lon) {
			let query = 'UPDATE users SET lat = ?, lon = ? WHERE id = ?'
			connection.query(query, [lat, lon, id], (err, rows) => {
				if (err) {
					return cb("error")
				} else {
					return cb(rows[0])
				}
			})
		}
	}

	static init_token (id, token, cb) {
		let query = 'UPDATE users SET token = ? WHERE id = ?'
		connection.query(query, [token, id], (err, rows) => {
			if (err) {
				return cb("error")
			} else {
				return cb(rows[0])
			}
		})
	}

	static find_by_token (token, cb) {
		let query = 'SELECT * FROM users WHERE token = ? LIMIT 1'
		connection.query(query, [token], (err, rows) => {
			if (err) {
				return cb("error")
			} else {
				return cb(rows[0])
			}
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

	static find_by_path (path, cb) {
		let query = 'SELECT * FROM users WHERE reset_password = ? LIMIT 1'
		connection.query(query, [path], (err, rows) => {
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

	static reset_password (user, hash, cb) {
		let query = 'UPDATE users SET reset_password = ? WHERE id = ?'
		connection.query(query, [hash, user.id], (err, rows) => {
			if (err) {
				return cb("error")
			} else {
				return cb(rows[0])
			}
		})
	}

	static new_password (user, hash, cb) {
		let query = 'UPDATE users SET password = ?, reset_password = ? WHERE id = ?'
		connection.query(query, [hash, "", user], (err, result) => {
			if (err) throw err
			return cb(result)
		})

	}

	static like (id, cb) {
		let query = 'UPDATE users SET likes = ? WHERE id = ?'
		let likes = 0
		User.find(id, function (user) {
			id = user.id
			if (user.likes) {
				likes = user.likes + 1
			} else {
				likes = 1
			}
			connection.query(query, [likes, user.id], (err, result) => {
				if (err) throw err
				cb(result)
			})
		})
	}

	static unlike (id, cb) {
		let query = 'UPDATE users SET likes = ? WHERE id = ?'
		let likes = 0
		User.find(id, function (user) {
			id = user.id
			if (user.likes) {
				likes = user.likes - 1
			} else {
				likes = 0
			}
			connection.query(query, [likes, user.id], (err, result) => {
				if (err) throw err
				cb(result)
			})
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
