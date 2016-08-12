let connection = require('../config/db')

class Picture {

	constructor (row) {
		this.row = row
	}

	get id () {
		return this.row.id
	}

	get user_id () {
		return this.row.user_id
	}

	get url_pic_1 () {
		return this.row.url_pic_1
	}

	get url_pic_2 () {
		return this.row.url_pic_2
	}

	get url_pic_3 () {
		return this.row.url_pic_3
	}

	get url_pic_4 () {
		return this.row.url_pic_4
	}

	get url_pic_5 () {
		return this.row.url_pic_5
	}

	static init (user_id) {
		connection.query('INSERT INTO pictures SET user_id = ?', [user_id])
	}

	static all (cb) {
		let query = 'SELECT * FROM pictures'
		connection.query(query, (err, rows) => {
			if (err) throw err
			cb(rows.map((row) => new Picture(row)))
		})
	}

	static find (user_id, cb) {
		let query = 'SELECT * FROM pictures WHERE user_id = ? LIMIT 1'
		connection.query(query, [user_id], (err, rows) => {
			if (err) throw err
			cb(new Picture(rows[0]))
		})
	}

	static delete (user_id, picture, cb) {
		if (picture == 'url_pic_1') {
			let query = 'UPDATE pictures SET url_pic_1 = ? WHERE user_id = ?'
			connection.query(query, [null, user_id])
		} else if (picture == 'url_pic_2') {
			let query = 'UPDATE pictures SET url_pic_2 = ? WHERE user_id = ?'
			connection.query(query, [null, user_id])
		} else if (picture == 'url_pic_3') {
			let query = 'UPDATE pictures SET url_pic_3 = ? WHERE user_id = ?'
			connection.query(query, [null, user_id])
		} else if (picture == 'url_pic_4') {
			let query = 'UPDATE pictures SET url_pic_4 = ? WHERE user_id = ?'
			connection.query(query, [null, user_id])
		} else if (picture == 'url_pic_5') {
			let query = 'UPDATE pictures SET url_pic_5 = ? WHERE user_id = ?'
			connection.query(query, [null, user_id])
		} else {
			cb("error")
		}
	}

	static update (user_id, url, cb) {
		Picture.find(user_id, function (picture) {
			if (!picture.url_pic_1) {
				let query = 'UPDATE pictures SET url_pic_1 = ? WHERE user_id = ?'
				connection.query(query, [url, user_id])
			} else if (!picture.url_pic_2) {
				let query = 'UPDATE pictures SET url_pic_2 = ? WHERE user_id = ?'
				connection.query(query, [url, user_id])
			} else if (!picture.url_pic_3) {
				let query = 'UPDATE pictures SET url_pic_3 = ? WHERE user_id = ?'
				connection.query(query, [url, user_id])
			} else if (!picture.url_pic_4) {
				let query = 'UPDATE pictures SET url_pic_4 = ? WHERE user_id = ?'
				connection.query(query, [url, user_id])
			} else if (!picture.url_pic_5) {
				let query = 'UPDATE pictures SET url_pic_5 = ? WHERE user_id = ?'
				connection.query(query, [url, user_id])
			} else {
				cb("error")
			}
		})
	}
}
module.exports = Picture
