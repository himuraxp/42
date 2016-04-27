<?php
session_start();
require ("database.php");
function auth($login, $passwd)
{
	if($db = new PDO('mysql:host=localhost;dbname=camagru', 'root', 'root', array(PDO::ATTR_ERRMODE=>PDO::ERRMODE_EXCEPTION)))
	{
		$query = $db->prepare("SET NAMES 'utf8'");
		$query->execute();
	}
	$query = $db->prepare('SELECT ID, Password FROM users WHERE (Login COLLATE utf8_general_ci = :login && active = 1)');
	$query->bindValue(":login", $login);
	$query->execute();
	$data = $query->fetch(PDO::FETCH_ASSOC);
	if (isset($data['ID']) && password_verify($passwd, $data['Password'])){
		echo "<div class='message'>Identification validée</div>";
		return (true);
	}
	else {
		echo "<div class='message'>Identifiants erronés <a href='../index.php'>Cliquez ici pour vous loger !</a></div>";
		return (false);
	}
}
?>
