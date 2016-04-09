<?php
require('auth.php');
session_start();
if ($_GET['login'] && $_GET['passwd'])
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
	if (auth($_SESSION['login'], $_SESSION['passwd']))
	{
		$_SESSION['loggued_on_user'] = $_SESSION['login'];
		echo "OK\n";
	}
	else
	{
		$_SESSION['loggued_on_user'] = '';
		exit("ERREUR1\n");
	}
}
else
	exit("ERROR2\n");
?>
