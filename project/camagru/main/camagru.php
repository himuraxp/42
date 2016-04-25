<?php
require('../auth/auth.php');
session_start();
if ($_SESSION['current_user'] || ($_POST['login'] && $_POST['passwd']))
{
	$_SESSION['login'] = $_POST['login'];
	$_SESSION['passwd'] = $_POST['passwd'];
	if ($_SESSION['current_user'] || auth($_SESSION['login'], $_SESSION['passwd']))
	{
		$_SESSION['current_user'] = $_SESSION['login'];
		include('header.html');
		include('body.php');
		include('footer.html');
	}
	else
	{
		$_SESSION['current_user'] = '';
		exit("ERREUR\n");
	}
}
else
	exit("ERROR\n");
?>
