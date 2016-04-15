var i = 0;

function ft_list()
{
	i++;
	var list = document.getElementById('ft_list');
	list.getAttribute('id');
	var note = document.createElement('div');
	var name = "note" + i;
	note.setAttribute('class', 'note');
	note.setAttribute('id', name);
	note.setAttribute('onclick', 'del_note(name)');
	note.setAttribute('value', 'i');
	var_text = document.createTextNode('test' + ' ' + i);
	note.appendChild(var_text);
	list.appendChild(note);
}

function del_note(name)
{
	var list = document.getElementById('ft_list');
	list.getAttribute('id');
	var note = document.getElementById(name);
	list.removeChild(note);
}
