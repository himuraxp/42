var getHttpResquest = function () {
	var httpRequest = false;

	if (window.XMLHttpRequest) { // Mozilla, Safari,...
		httpRequest = new XMLHttpRequest();
		if (httpRequest.overrideMimeType) {
			httpRequest.overrideMimeType('text/xml');
			// Voir la note ci-dessous à propos de cette ligne
		}
	}
	else if (window.ActiveXObject) { // IE
		try {
			httpRequest = new ActiveXObject("Msxml2.XMLHTTP");
		}
		catch (e) {
			try {
				httpRequest = new ActiveXObject("Microsoft.XMLHTTP");
			}
			catch (e) {}
		}
	}

	if (!httpRequest) {
		console.log('Abandon :( Impossible de créer une instance XMLHTTP');
		return false;
	}
	return httpRequest;
}

var httpRequest = getHttpResquest()
httpRequest.open('GET', '/notif/', true)
httpRequest.onreadystatechange = function () {
	if (httpRequest.readyState === 4) {
		httpRequest.responseText
		document.getElementById('result').innerHTML = httpRequest.responseText
	}
}
httpRequest.send()
