var verifpass = function(){
	var normalpass = document.getElementById('normalpass').value;
	var repeatpass = document.getElementById('repeatpass').value;
	var test = normalpass;
	var ok = 0;
	if (normalpass && /^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])([a-zA-Z0-9<>@#$%^&+=*.\-_\(\)\\\!\{\}\[\]\`\~\|\"\'\;\:\/\?\,]){3,}$/.test(normalpass)) {
		document.getElementById('message-err-reg').style = "display:none";
		if (normalpass !== repeatpass){
			document.getElementById('SignupButton').disabled = true;
			if (repeatpass !== '') {
				document.getElementById('message-ok').style = "display:none";
				document.getElementById('message-err').style = "display:block";
				document.getElementById('message-err-dif').style = "display:block";
			}
		}
		else if (normalpass === repeatpass) {
			document.getElementById('SignupButton').disabled = false;
			if (repeatpass !== '') {
				document.getElementById('message-ok').style = "display:block";
				document.getElementById('message-err').style = "display:none";
			}
		}
	}
	else {
		if (normalpass !== ''){
			document.getElementById('message-err-reg').style = "display:block; font-size:1em;";
		}
	}
}
