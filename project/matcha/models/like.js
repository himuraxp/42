let connection = require('../config/db')
let moment = require('../config/moment')

class Like {

	constructor (row) {
		this.row = row
	}

	get user_id () {
		return this.row.user_id
	}

	get you_like () {
		return this.row.you_like
	}

	get like_you () {
		return this.row.like_you
	}

	static all (cb) {
		let query = 'SELECT * FROM likes'
		connection.query(query, (err, rows) => {
			if (err) throw err
			cb(rows.map((row) => new Like(row)))
		})
	}

	static find (you_like, like_you, cb) {
		let query = 'SELECT users.id, likes.like_you FROM users RIGHT JOIN likes ON users.id = likes.user_id'
		connection.query(query, (err, rows) => {
			if (err) {
				cb("error")
			} else {
			cb(rows.map((row) => new Like(row)))
			}
		})
	}

	static find_by_id (id, cb) {
		let query = 'SELECT * FROM likes WHERE likes.user_id = ?'
		connection.query(query, [id], (err, rows) => {
			if (err) {
				cb("error")
			} else {
			cb(rows.map((row) => new Like(row)))
			}
		})
	}

	static delete (id, you_like, cb) {
		connection.query('DELETE FROM likes WHERE user_id = ? AND you_like = ? AND like_you = ?', [id, id, you_like], (err, result) => {
			if (err) throw err
			cb(result)
		})
	}

	static create (id, like_you, cb) {
		connection.query('INSERT INTO likes SET user_id = ?, you_like = ?, like_you = ?', [id, id, like_you], (err, result) => {
			if (err) throw err
			cb(result)
		})
	}
}
module.exports = Like
