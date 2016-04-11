function load_admin()
{
	if (document.getElementById('admn'))
	{
		document.getElementById('account').value = "Boutique";
		document.getElementById('account').onclick = (function () {
		    return function() {
		    	document.getElementById('nav').setAttribute('style', '');
		    	document.getElementById('print_boutique').innerHTML = "";
		    	document.getElementById('menu').setAttribute('style', '');
		    	load_boutique();
		    };
		})();
	}
}

function show_admin_frame()
{
	document.getElementById('nav').setAttribute('style', 'display:none');
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('print_boutique').innerHTML = xhr.responseText;
        	document.getElementById('menu').setAttribute('style', 'display:none');
        	show_produit_frame();
        }
    };
    xhr.open("GET", "./admin/control.php", true);
    xhr.send(null);
}

function show_produit_frame()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        	
        }
    };
    xhr.open("GET", "./admin/prod.php", true);
    xhr.send(null);
}

function save_this_obj(obj)
{
	var line = obj.parentNode.parentNode;
	var id = line.children[0].innerHTML;
	var nom = line.children[1].children[0].value;
	var cat = line.children[2].children[0].value;
	var cat1 = line.children[3].children[0].value;
	var prix = line.children[4].children[0].value;
	var red = line.children[5].children[0].value;
	var stock = line.children[6].children[0].value;
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        }
    };
	xhr.open("POST", "./admin/prod.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&id="+id+"&nom="+nom+"&cat="+cat+"&cat1="+cat1+"&prix="+prix+"&red="+red+"&stock="+stock);
}

function del_this_obj(obj)
{
	var line = obj.parentNode.parentNode;
	var id = line.children[0].innerHTML;
	var nom = line.children[1].children[0].value;
	var cat = line.children[2].children[0].value;
	var cat1 = line.children[3].children[0].value;
	var prix = line.children[4].children[0].value;
	var red = line.children[5].children[0].value;
	var stock = line.children[6].children[0].value;
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        }
    };
	xhr.open("POST", "./admin/prod.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&id="+id+"&nom="+nom+"&cat="+cat+"&cat1="+cat1+"&prix="+prix+"&red="+red+"&stock="+stock+"&del=");
}

function add_this_obj(obj)
{
	var line = obj.parentNode.parentNode;
	var id = line.children[0].innerHTML;
	var nom = line.children[1].children[0].value;
	var cat = line.children[2].children[0].value;
	var cat1 = line.children[3].children[0].value;
	var prix = line.children[4].children[0].value;
	var red = line.children[5].children[0].value;
	var stock = line.children[6].children[0].value;
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        }
    };
	xhr.open("POST", "./admin/prod.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&id="+id+"&nom="+nom+"&cat="+cat+"&cat1="+cat1+"&prix="+prix+"&red="+red+"&stock="+stock+"&add=");
}

function show_user_frame()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        	
        }
    };
    xhr.open("GET", "./admin/user.php", true);
    xhr.send(null);
}

function update_state_user(login, box)
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	//document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        	
        }
    };
	xhr.open("POST", "./admin/user.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&login="+login+"&state="+box.checked);
}

function admin_delet_user(login)
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        }
    };
	xhr.open("POST", "./admin/user.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&login="+login+"&delet=");
}

function show_cat_frame()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        	
        }
    };
    xhr.open("GET", "./admin/cat.php", true);
    xhr.send(null);
}

function save_this_cat(obj, pos)
{
	var line = obj.parentNode.parentNode;
	var cat = line.children[0].children[0].value;
	console.log(cat);
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        }
    };
	xhr.open("POST", "./admin/cat.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&cat="+cat+"&pos="+pos);
}

function del_this_cat(obj, pos)
{
	var line = obj.parentNode.parentNode;
	var cat = line.children[0].children[0].value;
	console.log(cat);
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        }
    };
	xhr.open("POST", "./admin/cat.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&cat="+cat+"&pos="+pos+"&del=del");
}

function show_commande_frame()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	document.getElementById('display_admin_zone').innerHTML = xhr.responseText;
        }
    };
    xhr.open("GET", "./admin/commandes.php", true);
    xhr.send(null);
}