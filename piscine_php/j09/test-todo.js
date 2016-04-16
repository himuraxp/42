var i = 0;
var cook = document.cookie;

function ft_list() {
	var msg = prompt("Enter votre note: ")
	if (msg != "") {
		i++;
		var list = document.getElementById('ft_list');
		list.getAttribute('id');
		var note = document.createElement('div');
		var name = "note";
		note.setAttribute('class', 'note');
		note.setAttribute('id', i);
		note.setAttribute('name', name);
		note.setAttribute('onclick', 'remove(\'' + name + '\')');
		var_text = document.createTextNode(msg);
		note.appendChild(var_text);
		list.appendChild(note);
		list.insertBefore(note, list.firstChild);
		setCookie(i, note.innerHTML, 1);
		console.log(var_text);
	}
}

function add(todo) {
	if (todo != "") {
		i++;
		var list = document.getElementById('ft_list');
		list.getAttribute('id');
		var note = document.createElement('div');
		var name = "note" + i;
		note.setAttribute('class', 'note');
		note.setAttribute('id', 'i');
		note.setAttribute('name', name);
		note.setAttribute('onclick', 'remove(\'' + name + '\')');
		note.setAttribute('value', 'i');
		note.innerHTML = todo;
		list.appendChild(note);
		list.insertBefore(note, list.firstChild);
	}
}

function remove(name) {
	document.cookie = del_id + "=; expires=Thu, 01 Jan 1970 00:00:00 GMT";
	return (elem=document.getElementsByName(name)).parentNode.removeChild(elem);
}

function init() {
	for (var i = 0; i < 50; i++) { cook = getCookie(i).split(';'); }
	for (var i = 0; i < cook.length; i++) {
		add(cook[i]);
		console.log(cook[i]);
	}
}

function setCookie(id, cvalue, exdays) {
	var d = new Date();
	d.setTime(d.getTime() + (exdays*24*60*60*1000));
	var expires = "expires="+d.toUTCString();
	cook = document.cookie = id + "=" + cvalue + exdays;
}

function getCookie(cname) {
	var name = cname + "=";
	var ca = document.cookie.split(';');
	for(var i=0; i<ca.length; i++) {
		var c = ca[i];
		while (c.charAt(0)==' ')
			c = c.substring(1);
		if (c.indexOf(name) == 0)
			return c.substring(name.length, c.length);
	}
	return "";
}
