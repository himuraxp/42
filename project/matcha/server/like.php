<?php

include '../config/database.php';
session_start();
if (isset($_POST['login'])){
	try{
		$DB_DSNNAME = $DB_DSN.";dbname=".$DB_NAME;
		$pdo = new PDO($DB_DSNNAME , $DB_USER, $DB_PASSWORD);
	}
	catch(PDOException $e){
		$msg = 'ERREUR PDO dans ' . $e->getFile() . ' L.' . $e->getLine() . ' : ' . $e->getMessage();
		die($msg);
	}
	$login	= htmlspecialchars($_POST['login']);
	$stmt = $pdo->prepare("INSERT INTO ".$DB_TABLE['likes']."(refphotoid, LOGIN) values(:photoid,:login);");
	$stmt->bindvalue(':photoid', $_POST['id']);
	$stmt->bindvalue(':login', $login, PDO::PARAM_STR);
	$stmt->execute();
}

header('Location: /client/views/galerie.php');
exit;
?>
