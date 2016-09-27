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

	get score () {
		return this.row.score
	}

	get locate () {
		return this.row.locate
	}

	get connected () {
		return this.row.connected
	}

	get ban () {
		return this.row.ban
	}

	get created_at () {
		return moment(this.row.created_at)
	}

	get last_connect () {
		return moment(this.row.last_connect).fromNow()
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

	static filter(tag, agemin, agemax, popmin, popmax, cb) {
		let query = 'SELECT * FROM users '
		let query2 = 'SELECT users.* FROM users RIGHT OUTER JOIN tags ON users.id = tags.user_id WHERE '
		let query_tag = ''
		let final_query = ''
		let parse = []
		let where = 'WHERE'
		let and = 'AND'
		let union = 'UNION'
		let score = ' score BETWEEN '
		let age = ' birthday <= '
		let len = 0
		let geek = 0
		let sport = 0
		let barbu = 0
		let bio = 0

		console.log("tag = " + tag);
		console.log("agemax = " + agemax);

		if (popmin !== "j%3Anull" && popmax !== "j%3Anull") {
			score += popmin+' AND '+popmax+' '
			len = 2
		}
		if (agemin !== "j%3Anull" && agemax !== "j%3Anull") {
			agemin = 2016 - agemin
			agemax = 2016 - agemax
			agemin += "-01-01"
			agemax += "-01-01"
			age += "DATE('"+agemin+"') AND birthday >= DATE('"+agemax+"') "
			len = 2
		}
		if (tag !== "j%3Anull") {
			if (tag.match("%23")) {
				parse = tag.split("%23")
				if (tag.match("geek") !== null) {
					console.log(tag.match("geek"));
					query_tag = ' tags.geek = 1 '
				}
				if (tag.match("sport") !== null) {
					console.log(tag.match("sport"));
					if (query_tag === '') {
						query_tag = 'tags.sport = 1 '
					} else {
						query_tag += 'OR tags.sport = 1 '
					}
				}
				if (tag.match("barbu") !== null) {
					console.log(tag.match("barbu"));
					if (query_tag === '') {
						query_tag = 'tags.barbu = 1 '
					} else {
						query_tag += 'OR tags.barbu = 1 '
					}
				}
				if (tag.match("bio") !== null) {
					console.log(tag.match("bio"));
					if (query_tag === '') {
						query_tag = 'tags.bio = 1'
					} else {
						query_tag += 'OR tags.bio = 1'
					}
				}
			}
			if (popmax !== "j%3Anull" && agemax !== "NaN-01-01" && agemax !== "j%3Anull") {
				final_query = '('+query+where+score+and+age+') '+union+' ('+query2 + query_tag+')'
				console.log(final_query);
				connection.query(final_query, [popmin, popmax, agemin, agemax], (err, rows) => {
					if (err) {
						final_query = ""
						return cb("error")
					} else {
						final_query = ""
						return cb(rows.map((row) => new User(row)))
					}
				})
			} else if (len === 2 && popmax !== "j%3Anull") {
				final_query = '('+query+where+score+') '+union+' ('+query2+query_tag+')'
				console.log(final_query);
				connection.query(final_query, [popmin, popmax], (err, rows) => {
					if (err) {
						final_query = ""
						return cb("error")
					} else {
						final_query = ""
						return cb(rows.map((row) => new User(row)))
					}
				})
			} else if (len === 2 && agemax !== "NaN-01-01"  && agemax !== "j%3Anull") {
				final_query = '('+query+where+age+') '+union+' ('+query2+query_tag+')'
				console.log(final_query);
				connection.query(query + where + age, [agemin, agemax], (err, rows) => {
					if (err) {
						final_query = ""
						return cb("error")
					} else {
						final_query = ""
						return cb(rows.map((row) => new User(row)))
					}
				})
			} else {
				final_query = query2 + query_tag
				console.log(final_query);
				connection.query(final_query, (err, rows) => {
					if (err) {
						final_query = ""
						return cb("error")
					} else {
						final_query = ""
						return cb(rows.map((row) => new User(row)))
					}
				})
			}
		} else {
			if (popmax !== "j%3Anull" && agemax !== "j%3Anull" && agemax !== "j%3Anull") {
				final_query = query + where + score + and + age
				console.log(final_query);
				connection.query(final_query, [popmin, popmax, agemin, agemax], (err, rows) => {
					if (err) {
						final_query = ""
						return cb("error")
					} else {
						final_query = ""
						return cb(rows.map((row) => new User(row)))
					}
				})
			} else if (len === 2 && popmax !== "j%3Anull") {
				final_query = query + where + score
				console.log(final_query);
				connection.query(final_query, [popmin, popmax], (err, rows) => {
					if (err) {
						final_query = ""
						return cb("error")
					} else {
						final_query = ""
						return cb(rows.map((row) => new User(row)))
					}
				})
			} else if (len === 2 && agemax !== "j%3Anull" && agemax !== "j%3Anull") {
				final_query = query + where + age
				console.log(final_query);
				connection.query(query + where + age, [agemin, agemax], (err, rows) => {
					if (err) {
						final_query = ""
						return cb("error")
					} else {
						final_query = ""
						return cb(rows.map((row) => new User(row)))
					}
				})
			}
		}
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

	static ban (id, cb) {
		let query = 'UPDATE users SET ban = ? WHERE id = ?'
		let ban = 0
		User.find(id, function (user) {
			id = user.id
			if (user.ban) {
				ban = user.ban + 1
			} else {
				ban = 1
			}
			connection.query(query, [ban, user.id], (err, result) => {
				if (err) throw err
				cb(result)
			})
		})
	}

	static upscore (id, cb) {
		let query = 'UPDATE users SET score = ? WHERE id = ?'
		let score = 0
		User.find(id, function (user) {
			id = user.id
			if (user.score) {
				score = user.score + 1
			} else {
				score = 1
			}
			connection.query(query, [score, user.id], (err, result) => {
				if (err) throw err
				cb(result)
			})
		})
	}

	static locate (id, cb) {
		let query = 'UPDATE users SET locate = ? WHERE id = ?'
		let locate = 0
		User.find(id, function (user) {
			id = user.id
			if (user.locate) {
				locate = 0
			} else {
				locate = 1
			}
			connection.query(query, [locate, user.id], (err, result) => {
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
			if (user_type !== 'Homme' && user_type !== 'Femme' && user_type !== 'Bisexuel') {
				user_type = 'Bisexuel'
			}
		}
		if (type === 'locate') {
			if (user_type.match("oui")) {
				user_type = "oui"
			} else if (user_type.match("non")) {
				user_type = "non"
			} else {
				user_type = "oui"
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
