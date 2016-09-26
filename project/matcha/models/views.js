let connection = require('../config/db')
let moment = require('../config/moment')

class View {

	constructor (row) {
		this.row = row
	}

	get id () {
		return this.row.id
	}

	get user_id () {
		return this.row.user_id
	}

	get user_view () {
		return this.row.user_view
	}

	get created_at () {
		return moment(this.row.created_at, 'day').fromNow()
	}

	static find (id, cb) {
		let query = 'SELECT * FROM views WHERE user_id = ?'
		connection.query(query, [id], (err, rows) => {
			if (err) {
				cb(err)
			} else {
				cb(new View(rows[0]))
			}
		})
	}

	static all (cb) {
		let query = 'SELECT * FROM views'
		connection.query(query, (err, rows) => {
			if (err) throw err
			cb(rows.map((row) => new View(row)))
		})
	}

	static new (user_view, user_id, cb) {
		connection.query('INSERT INTO views SET user_id = ?, user_view = ?, created_at = ?', [
			user_id,
			user_view,
			new Date()
		], (err, result) => {
			if (err) throw err
			cb(result)
		})
	}
}
module.exports = View
