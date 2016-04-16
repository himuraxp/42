function del(id) {
		if (confirm("Voulez vous vraiment supprimer cet element ?"))
		{
			var list = document.getElementById('ft_list');
			list.removeChild(id);
			setCookie('todo', list.innerHTML, 1);
		}
	}
$(document).ready( function() {
	var list = document.getElementById('ft_list');
		list.innerHTML = getCookie('todo');
	var nb_todo = 0;

	 $.ajax({
	  	type : 'GET',
		url : 'select.php' ,
		success : function(data){
			$('#ft_list').html(data);
		}
	});
	$( "#ft_list" ).on( "click", "div", function(e) {
		idTodo = $(this).attr('id');
		$.ajax({
		  	type : 'GET',
			url : 'delete.php' ,
			data: { todo: idTodo } ,
			success : function(data){
				$('#ft_list').html(data);
			}
		});
	});
	$('#new').click( function(){
	    var persson = prompt("Ajouter un element dans la liste");
	    if (persson.length)
		{
		    $.ajax({
			  	type : 'GET',
				url : 'insert.php' ,
				data: { todo: persson } ,
				success : function(data){
					$('#ft_list').html(data);
				}
			});
		}
    });



	function getCookie(cname) {
		var name = cname + "=";
		var ca = document.cookie.split(';');
		for(var i=0; i<ca.length; i++)
		{
			var c = ca[i];
			while (c.charAt(0)==' ') c = c.substring(1);
			if (c.indexOf(name) == 0) return c.substring(name.length,c.length);
		}

		return "";
	}

	function setCookie(cname, cvalue, exdays) {
		var d = new Date();
		d.setTime(d.getTime() + (exdays*24*60*60*1000));
		var expires = "expires="+d.toUTCString();
		document.cookie = cname + "=" + cvalue + "; " + expires;
	}
});
