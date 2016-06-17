<?php
include '../config/database.php';
session_start();
if (!isset($_SESSION['login'])){
	try
	{
		$DB_DSNNAME = $DB_DSN.";dbname=".$DB_NAME;
		$pdo = new PDO($DB_DSNNAME , $DB_USER, $DB_PASSWORD);
	}
	catch(PDOException $e)
	{
		die("DB ERROR: ". $e->getMessage());
	}

	if (isset($_POST['reset'])){
		$mdp	= htmlspecialchars(hash('whirlpool', $_POST['password']));
		$salt = $_POST['reset'];
		$stmt = $pdo->prepare("UPDATE " . $DB_TABLE['users']." SET mdp=:mdp where reset=:salt");
		$stmt->bindValue(':mdp', $mdp);
		$stmt->bindValue(':salt', $salt);
		$stmt->execute();
		$stmt = $pdo->prepare("select login from ".$DB_TABLE['users']." where reset=:salt");
		$stmt->bindValue(':salt', $salt);
		$stmt->execute();
		$array =$stmt->fetch();
		$_SESSION['login']=$array['login'];
		$stmt = $pdo->prepare("UPDATE ".$DB_TABLE['users']." SET reset=NULL where reset=:salt");
		$stmt->bindValue(':salt', $salt);
		$stmt->execute();
	}
	else{
		$email = htmlspecialchars($_POST['email']);
		$headers  = 'MIME-Version: 1.0' . "\r\n";
		$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
		$headers .= 'From: Admin<admin@match42.paris>' . "\r\n";
		$headers .= 'Reply-To: <admin@match42.paris>' . "\r\n";
		$headers .= 'X-Mailer: PHP/' . phpversion();
		$salt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		$str = "";
		for ($i=0; $i <= strlen($salt)/2; $i++){
			$str .= $salt[rand() % strlen($salt)];
		}
		$hash = htmlspecialchars(hash('md5', $str.$email));
		$link = "https://localhost:8888/client/views/resetpassword.php?reset=".$hash;
		$msg = '<html><head><title>Reinitialisation mot de passe Matcha</title></head><body><a href="'.$link.'">Cliquez sur ce lien pour reinitialiser votre mot de passe Matcha.</a></body></html>';

		mail($email, "Reset Password", $msg, $headers);

		$stmt = $pdo->prepare("UPDATE ".$DB_TABLE['users']." SET reset='$hash' where email=:email");
		$stmt->bindValue(':email', $email);
		$stmt->execute();
	}
	$pdo = NULL;
}
header('Location: /');
exit;
?>
