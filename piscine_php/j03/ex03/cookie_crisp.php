<?php
	if ($_GET['action'] == 'set')
		setcookie($_GET['name'], $_GET['value']);
	elseif ($_GET['action'] == 'del')
		setcookie($_GET['name'], "");
	elseif ($_GET['action'] == 'get')
		print($_GET['name']."\n");
?>
