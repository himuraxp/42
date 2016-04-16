var i = 0;
function new_str()
{
	var ft_list = document.getElementById('ft_list')
	var str = prompt('What\'s the new To do ?');
	if (str !== "" && str != null)
		add_one(str);
}

function add_one(str)
{
	var div = document.createElement('div');
	var text = document.createTextNode(str);

	div.setAttribute('id', i)
	div.setAttribute('class', 'note');
	div.setAttribute('onclick', 'del_str(id)')
	div.appendChild(text);
	ft_list.insertBefore(div, ft_list.firstChild);
	set_cookie(i, str, 1);
	i++;
}

function del_str(id)
{
	var ft_list = document.getElementById('ft_list')
	var del = document.getElementById(id);

	ft_list.removeChild(del);
	document.cookie = id + "=; expires=Thu, 01 Jan 1970 00:00:00 GMT";
}

function set_cookie(id, text, exdays)
{
	var d = new Date();
	d.setTime(d.getTime()+(exdays*24*60*60*1000));
	var expires = "expires="+d.toGMTString();
	document.cookie = id + "=" + text + "; " +expires;
}

function get_cookie(cname)
{
	var name = cname + "=";
	var ca = document.cookie.split(';');

	for(var i=0; i<ca.length; i++)
	{
		var c = ca[i].trim();
		if (c.indexOf(name)==0)
			return c.substring(name.length,c.length);
	}
	return "";
}

function init()
{
	var all = document.cookie.split(';');

	for (var x in all)
	{
		var id = all[x].split('=')[0];
		if (!isNaN(parseInt(id)))
		{
			var text = all[x].split('=')[1];

			add_one(text);
		}
	}
}
