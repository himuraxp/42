let http = require('http')

httpServer = http.createServer(function(res, res) {
	console.log('User connected')
})

httpServer.listen(1337)

let io = require('socket.io').listen(httpServer)
