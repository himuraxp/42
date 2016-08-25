let connection = require('../config/db')

class Tag {

	constructor (row) {
		this.row = row
	}

	get user_id () {
		return this.row.user_id
	}

	get sport () {
		return this.row.sport
	}

	get geek () {
		return this.row.geek
	}

	get bio () {
		return this.row.bio
	}

	get barbu () {
		return this.row.barbu
	}

	static all (cb) {
		let query = 'SELECT * FROM tags'
		connection.query(query, (err, rows) => {
			if (err) throw err
			cb(rows.map((row) => new Tag(row)))
		})
	}

	static find (user_id, cb) {
		let query = 'SELECT * FROM tags WHERE user_id = ? LIMIT 1'
		connection.query(query, [user_id], (err, rows) => {
			if (err) {
				cb("error")
			} else {
				cb(new Tag(rows[0]))
			}
		})
	}

	static update (id, sport, geek, bio, barbu, cb) {
		let query_update = 'UPDATE tags SET sport = ?, geek = ?, bio = ?, barbu = ? WHERE user_id = ?'
		connection.query(query_update, [sport, geek, bio, barbu, id], (err, result) => {
			if (err) {
				cb("error")
			} else {
				cb(result)
			}
		})
	}

	static create (id, sport, geek, bio, barbu, cb) {
		connection.query('INSERT INTO tags SET sport = ?, geek = ?, bio = ?, barbu = ?, user_id = ?', [sport, geek, bio, barbu, id], (err, result) => {
			if (err) {
				cb("error")
			} else {
				cb(result)
			}
		})
	}
}

module.exports = Tag
