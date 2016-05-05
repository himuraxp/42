var add = function(name){

	document.getElementById('coner').disabled = false;
	document.getElementById('clipart').src="/client/images/"+name+".png";
	document.getElementById('clipprep').value= name;
	document.getElementById('startbutton').disabled = false;
	console.log(name);
	if (name == "42-logo"){
		document.getElementById('coner').value = "top";
		document.getElementById('coner').disabled = true;
		document.getElementById('clipart').style.width = "100%";
		document.getElementById('clipart').style.margin = "0";
	}
	else if (name == "hair"){
		document.getElementById('coner').value = "top";
		document.getElementById('coner').disabled = true;
		document.getElementById('clipart').style.width = "100%";
		document.getElementById('clipart').style.margin = "0";
	}
	else if (document.getElementById('coner').value == "tr") {
		document.getElementById('clipart').style.width = "30%";
		document.getElementById('clipart').style.margin = "4% 0 0 71%";
	}
	else if (document.getElementById('coner').value == "br") {
		document.getElementById('clipart').style.width = "30%";
		document.getElementById('clipart').style.margin = "49% 0 0 67%";
	}
	else if (document.getElementById('coner').value == "bl") {
		document.getElementById('clipart').style.width = "30%";
		document.getElementById('clipart').style.margin = "41% 0 0 -3%";
	}
	else {
		document.getElementById('coner').value = "tl";
		document.getElementById('clipart').style.width = "30%";
		document.getElementById('clipart').style.margin = "-3% 0 0 2%";
	}
};
