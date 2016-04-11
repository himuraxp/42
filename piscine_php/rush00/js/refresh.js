function getXMLHttpRequest() {
	var xhr = null;

	if (window.XMLHttpRequest || window.ActiveXObject) {
		if (window.ActiveXObject) {
			try {
				xhr = new ActiveXObject("Msxml2.XMLHTTP");
			} catch(e) {
				xhr = new ActiveXObject("Microsoft.XMLHTTP");
			}
		} else {
			xhr = new XMLHttpRequest();
		}
	} else {
		alert("Votre navigateur ne supporte pas l'objet XMLHTTPRequest...");
		return null;
	}

	return xhr;
}

function display_pop_up(action)
{
	var pop_up = document.getElementsByClassName("magic_pop_up")[0];
	pop_up.setAttribute("style", "display:block");
	document.getElementById("bg").setAttribute("style", "display:block");
	var print_zone = document.getElementById('display_pop_up_zone');
	if (action == "login")
	{
		affiche_login(print_zone);
	}
	if (action == "account")
	{
		affiche_account(print_zone);
	}

}

function affiche_account(print_zone)
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	print_zone.innerHTML = xhr.responseText
        }
    };
    xhr.open("GET", "./auth/frame_account.php", true);
    xhr.send(null);
}

function affiche_login(print_zone)
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	print_zone.innerHTML = xhr.responseText
        }
    };
    xhr.open("GET", "./auth/frame_log.php", true);
    xhr.send(null);
}

function hide_pop_up()
{
	document.getElementsByClassName("magic_pop_up")[0].setAttribute("style", "");
	document.getElementById("bg").setAttribute("style", "");
	document.getElementById("display_pop_up_zone").innerHTML = "";
}

function user_del_account()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	var rtn_opt = xhr.responseText.split(';');
			if (rtn_opt[0] == 'ERROR')
				frame_info('error', rtn_opt[1])
			else
			{
				frame_info('ok', rtn_opt[1]);
				shwo_order();
				setTimeout(function(){location.reload();}, 1000);
			}
			hide_pop_up();
        }
    };
    xhr.open("GET", "./auth/del_account.php", true);
    xhr.send(null);
}

function login_user()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	var pop_up = document.getElementsByClassName("magic_pop_up")[0];
			pop_up.setAttribute("style", "display:block");
			var print_zone = document.getElementById('display_pop_up_zone');
        	var obj_rtn = xhr.responseText.split(";");
        	if (obj_rtn[0] == 'ERROR')
        	{
				document.getElementsByClassName("close")[0].innerHTML = obj_rtn[0];
				frame_info('error', obj_rtn[1]);
				setTimeout(function(){
        			affiche_login(print_zone);
        		}, 2000);
        	}
        	else
			{
				frame_info('ok', obj_rtn[1]);
				setTimeout(function(){
	    			location.reload();
	    		}, 2000);
			}
        }
    };
    var login = document.getElementById("login").value;
    var passwd = document.getElementById("passwd").value;
    console.log(login, passwd);
    xhr.open("POST", "./auth/login.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&login="+login+"&passwd="+passwd);
}


function update_pwd_user()
{
	var pop_up = document.getElementsByClassName("magic_pop_up")[0];
	pop_up.setAttribute("style", "display:block");
	var print_zone = document.getElementById('display_pop_up_zone');
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	print_zone.innerHTML = xhr.responseText
        }
    };
    xhr.open("GET", "./auth/update_pw.php", true);
    xhr.send(null);
}

function sign_up_user()
{
	var pop_up = document.getElementsByClassName("magic_pop_up")[0];
	pop_up.setAttribute("style", "display:block");
	var print_zone = document.getElementById('display_pop_up_zone');
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function()
	{
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0))
   		{
        	print_zone.innerHTML = xhr.responseText;
        }
    };
    xhr.open("GET", "./auth/create.html", true);
    xhr.send(null);
}

function create_account()
{
	var pop_up = document.getElementsByClassName("magic_pop_up")[0];
	pop_up.setAttribute("style", "display:block");
	var print_zone = document.getElementById('display_pop_up_zone');
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0))
   		{
   			var obj_rtn = xhr.responseText.split(";");
        	console.log(obj_rtn);
        	if (obj_rtn[0] == 'ERROR')
        	{
	        	frame_info('error', obj_rtn[1]);
	        	document.getElementsByClassName("close")[0].innerHTML = obj_rtn[0];
	        	setTimeout(function(){
	    			sign_up_user();
	    		}, 1000);
        	}
	    	else
	    	{
		    	frame_info('ok', obj_rtn[1]);
		    	setTimeout(function(){
	    			display_pop_up("login");
	    		}, 1000);
	    	}	
        }
    };
	var login = document.getElementById("login").value;
    var passwd = document.getElementById("passwd").value;
    xhr.open("POST", "./auth/create.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&login="+login+"&passwd="+passwd);
}

function frame_info(type, message)
{
	if(type == 'error')
	{
		document.getElementById('message').innerHTML = message;
		document.getElementById('message').setAttribute("style", "display:block; background: linear-gradient(135deg, rgb(213, 58, 58) 0%,rgb(213, 140, 79) 50%,rgb(194, 53, 23) 51%,rgb(188, 154, 10) 100%);");
		document.getElementById('message').setAttribute("class", "message message-success");
	}
	else
	{
		document.getElementById('message').innerHTML = message;
		document.getElementById('message').setAttribute("style", "display:block");
		document.getElementById('message').setAttribute("class", "message message-success");
	}
	setTimeout(function(){
		document.getElementById('message').setAttribute("style", "");
		document.getElementById('message').setAttribute("class", "message");
	}, 5000);
}

function update_account()
{
	var xhr = getXMLHttpRequest();
	var pop_up = document.getElementsByClassName("magic_pop_up")[0];
	pop_up.setAttribute("style", "display:block");
	var print_zone = document.getElementById('display_pop_up_zone');
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	var obj_rtn = xhr.responseText.split(";");
        	if (obj_rtn[0] == "ERROR")
        	{
	        	document.getElementsByClassName("close")[0].innerHTML = obj_rtn[0];
	        	setTimeout(function(){update_pwd_user();}, 1000);
        	}
	    	else
	    		setTimeout(function(){
	    			display_pop_up("login");
	    		}, 1000);
        }
    };
	var login = document.getElementById("login").value;
    var oldpw = document.getElementById("oldpw").value;
    var newpw = document.getElementById("newpw").value;
    xhr.open("POST", "./auth/modif.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&login="+login+"&oldpw="+oldpw+"&newpw="+newpw);
}

function log_out()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
   		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
        	location.reload();
        }
    };
    xhr.open("GET", "./auth/logout.php", true);
    xhr.send(null);
}

function load_boutique()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
			document.getElementById('print_boutique').innerHTML = xhr.responseText;
		}
	};
	xhr.open("POST", "./boutique/load_boutique.php", true);
	xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&cat=all&cat1=all");
}

function select_item()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
			document.getElementById('print_boutique').innerHTML = xhr.responseText;
		}
	};
	var x = document.getElementById("cat1").selectedIndex;
    var y = document.getElementById("cat1").options;
    var cat1 = y[x].text;
    x = document.getElementById("cat2").selectedIndex;
    y = document.getElementById("cat2").options;
	var cat2 = y[x].text;
	xhr.open("POST", "./boutique/load_boutique.php", true);
	xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&cat="+cat1+"&cat1="+cat2);
}

function shwo_order()
{
	var pop_up = document.getElementsByClassName("magic_pop_up")[0];
	pop_up.setAttribute("style", "display:block");
	document.getElementById("bg").setAttribute("style", "display:block");
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
			document.getElementById('display_pop_up_zone').innerHTML = xhr.responseText;
		}
	};
	xhr.open("GET", "./boutique/load_order.php", true);
	xhr.send(null);
}

function add_to_order(id)
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
			//console.log(xhr.responseText);
		}
	};
	xhr.open("POST", "./boutique/add_order.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&id="+id);
}

function buy_order()
{
	var xhr = getXMLHttpRequest();
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
			var rtn_opt = xhr.responseText.split(';');
			if (rtn_opt[0] == 'ERROR')
				frame_info('error', rtn_opt[1])
			else
			{
				frame_info('ok', rtn_opt[1]);
				shwo_order();
			}				
		}
	};
	xhr.open("POST", "./boutique/buy_order.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("&cmd=");
}