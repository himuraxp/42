let connection = require('../config/db')
let moment = require('../config/moment')

class Message {

	constructor (row) {
		this.row = row
	}

	get id () {
		return this.row.id
	}

	get content () {
		return this.row.content
	}

	get message () {
		return this.row.message
	}

	get user_id () {
		return this.row.user_id
	}

	get like_you () {
		return this.row.like_you
	}

	get pseudo () {
		return this.row.pseudo
	}

	get email () {
		return this.row.email
	}

	get created_at () {
		return moment(this.row.created_at)
	}


	static connect_messages (cb) {
		let query = 'SELECT users.id as user_id, users.pseudo, users.email, messages.message, UNIX_TIMESTAMP(messages.created_at) as created_at FROM messages LEFT JOIN users ON users.id = messages.user_id ORDER BY messages.created_at DESC LIMIT 10'
		connection.query(query, function(err, rows){
			if (err) {
				cb("error")
			} else {
				cb(rows.map((row) => new Message(row)))
			}
		})
	}

	static get_message_id (id, for_id, cb) {
		let query = 'SELECT messages.user_id, users.pseudo, messages.for_user_id, messages.message, messages.created_at FROM messages, users WHERE messages.user_id = ? AND messages.for_user_id = ? OR messages.user_id = ? AND messages.for_user_id = ? GROUP BY messages.message ORDER BY messages.created_at DESC'
		connection.query(query, [id, for_id, for_id, id], function(err, rows){
			if (err) {
				cb("error")
			} else {
				cb(rows.map((row) => new Message(row)))
			}
		})
	}

	static push (id, message, for_id, cb) {
		connection.query('INSERT INTO messages SET user_id = ?, message = ?, for_user_id = ?, created_at = ?', [
			id,
			message,
			for_id,
			new Date()
		], (err, result) => {
			if (err) {
				cb("error")
			} else {
				cb(result)
			}
		})
	}

	static create (content, cb) {
		connection.query('INSERT INTO messages SET content = ?, created_at = ?', [content, new Date()], (err, result) => {
			if (err) throw err
			cb(result)
		})
	}

	static all (cb) {
		connection.query('SELECT * FROM messages', (err, rows) => {
			if (err) throw err
			cb(rows.map((row) => new Message(row)))
		})
	}

	static find (id, cb) {
		connection.query('SELECT * FROM messages WHERE id = ? LIMIT 1', [id], (err, rows) => {
			if (err) {
				cb('error')
			} else {
				cb(new Message(rows[0]))
			}
		})
	}

}

module.exports = Message
