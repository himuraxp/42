<?php
header('Location: speak.php');
require('auth.php');
session_start();
if ($_POST['login'] && $_POST['passwd'])
{
	$_SESSION['login'] = $_POST['login'];
	$_SESSION['passwd'] = $_POST['passwd'];
	if (auth($_SESSION['login'], $_SESSION['passwd']))
	{
		$_SESSION['loggued_on_user'] = $_SESSION['login'];
		echo "OK\n";
	}
	else
	{
		$_SESSION['loggued_on_user'] = '';
		exit("ERREUR\n");
	}
}
else
	exit("ERROR\n");
?>
