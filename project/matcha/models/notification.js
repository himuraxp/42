let connection = require('../config/db')

class Notification {

	constructor (row) {
		this.row = row
	}

	get id () {
		return this.row.id
	}

	get user_id () {
		return this.row.user_id
	}

	get like_you () {
		return this.row.like_you
	}

	get content () {
		return this.row.content
	}

	get active () {
		return this.row.active
	}

	static find_by_id (id, cb) {
		let query = 'SELECT * FROM notifications WHERE notifications.user_id = ?'
		connection.query(query, [id], (err, rows) => {
			if (err) {
				cb("error")
			} else {
			cb(rows.map((row) => new Notification(row)))
			}
		})
	}

	static false_notif (id, cb) {
		connection.query('UPDATE notifications SET active = 0 WHERE id = ?', [id], (err, result) => {
			if (err) {
				cb("error")
			} else {
				cb(result)
			}
		})
	}

	static create (user_id, content, like_you, cb) {
		connection.query('INSERT INTO notifications SET user_id = ?, like_you = ?, content = ?, active = true', [user_id, like_you, content], (err, result) => {
			if (err) throw err
			cb(result)
		})
	}
}
module.exports = Notification
