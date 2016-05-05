<?php
include '../config/database.php';
session_start();
if (!isset($_SESSION['login'])){
	try{
		$DB = $DB_DSN.";dbname=".$DB_NAME;
		$pdo = new PDO($DB , $DB_USER, $DB_PASSWORD);

	}
	catch(PDOException $e){
		$msg = 'ERREUR PDO dans '.$e->getFile().' ligne '.$e->getLine().' : '.$e->getMessage();
		die($msg);
	}
	if (isset($_GET['confirm'])){
		$stmt = $pdo->prepare("UPDATE ".$DB_TABLE['users']." SET confirmed='1' where confirm=:confirm");
		$stmt->bindValue(':confirm', $_GET['confirm']);
		$stmt->execute();
		$stmt = $pdo->prepare("UPDATE ".$DB_TABLE['users']." SET confirm=NULL where confirm=:confirm");
		$stmt->bindValue(':confirm', $_GET['confirm']);
		$stmt->execute();
		header('Location: /client/views/signin.php');
		exit;
	}
	else{
		$login	= htmlspecialchars($_POST['login']);
		$mdp	= htmlspecialchars(hash('whirlpool', $_POST['password']));
		$email =  htmlspecialchars($_POST['email']);
		$headers = 'From: Admin<admin@camagru.42.fr>' . "\r\n" .
			'Reply-To: <admin@camagru.42.fr>' . "\r\n" .
			'X-Mailer: PHP/' . phpversion();
		$salt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		$str = "";
		for ($i=0; $i <= strlen($salt)/2; $i++){
			$str .= $salt[rand() % strlen($salt)];
		}
		$hash = htmlspecialchars(hash('md5', $str.$email));
		$link = "http://localhost:8888/server/register.php?confirm=".$hash;
		$msg = "Cliquez sur le lien pour activer votre compte : ".$link. " Votre code : ".$hash;
		mail($email, "Activez votre comtpe", $msg, $headers);
		$stmt = $pdo->prepare("INSERT INTO ".$DB_TABLE['users']."(login, email, mdp, confirm)  VALUES(:login, :email, :mdp, '$hash')");
		$stmt->bindValue(':login', $login);
		$stmt->bindValue(':email', $email);
		$stmt->bindValue(':mdp', $mdp);
		$stmt->execute();
	}
	$pdo = NULL;
}
header('Location: /client/views/confirmed.php');
exit;
?>
