<?php
session_start();
function loadClass($name){
	require("../class/".$name.".php");
}
spl_autoload_register("loadClass");
require("../auth/auth.php");
if (isset($_SESSION['id']) !== '')
{
	if (isset($_POST['submit']) && $_POST['submit'] === "connection")
	{
		if ($_POST['login'] && $_POST['passwd'])
		{
			$_SESSION['login'] = $_POST['login'];
			$_SESSION['passwd'] = $_POST['passwd'];
			if (auth($_SESSION['login'], $_SESSION['passwd']) == true)
			{
				$_SESSION['id'] = $_SESSION['login'];
				include('header.html');
				include('body.php');
				include('footer.html');
			}
			else
			{
				$_SESSION['id'] = '';
				exit(0);
			}
		}
		else
			exit("<div class='message'>Wrong Password<br>");
	}
	else
		exit("<div class='message'>ERROR Connection\n");
}
?>
