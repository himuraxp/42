var i = 0;

function ft_list()
{
    var msg = prompt("Enter votre note: ")
    if (msg != "")
    {
    	i++;
    	var list = document.getElementById('ft_list');
    	list.getAttribute('id');
    	var note = document.createElement('div');
    	var name = "note" + i;
    	note.setAttribute('class', 'note');
    	note.setAttribute('id', 'note');
        note.setAttribute('name', name);
    	note.setAttribute('onclick', 'remove(\'' + name + '\')');
    	note.setAttribute('value', 'i');
    	var_text = document.createTextNode(msg);
    	note.appendChild(var_text);
    	list.appendChild(note);
        list.insertBefore(note, list.firstChild);
    }
}

function confirmation() {
    var txt;
    var r = confirm("Press a button!");
    if (r == true) {
        txt = "OK";
    } else {
        txt = "Cancel";
    }
    return txt;
}

function remove(name) {
    var txt;
    var r = confirm("Press a button!");
    if (r == true) {
        return (elem=document.getElementsByName(name)).parentNode.removeChild(elem);
    } else {
        txt = "Cancel";
    }
    return txt;
}
