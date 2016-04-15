function ft_list()
{
    var list = document.getElementById('ft_list');
    list.getAttribute('id');
    var note = document.createElement('div');
    note.setAttribute('style', 'background: red;');
    var_text = document.createTextNode('test');
    note.appendChild(var_text);
    list.appendChild(note);
}
