<?php
session_start();
function loadClass($name){
	require("../class/".$name.".php");
}
spl_autoload_register("loadClass");
if (!isset($_SESSION['id']))
{
	include("database.php");
// 	// Si on valide le formulaire
	if (isset($_POST['submit']) && $_POST['submit'] === "inscription")
	{
		$query = $db->prepare('SELECT * FROM users');
		$query->execute();
		$data = $query->fetch(PDO::FETCH_ASSOC);
		$pass = $_POST['passwd'];
		$pass_verif = $_POST['passwd_verif'];
		$login = $_POST['login'];
		$mail = $_POST['mail'];
		$mail_verif = $_POST['mail_verif'];
		$pattern = $data['pattern'];
		$pass_pattern = $data['pass_pattern'];
		// On vérifie que les deux mots de passes soient identiques
		if ($pass === $pass_verif && $pass != "") {
			// echo "pass ok<br>";
			// On vérifie que les deux mail soient identiques
			if ($mail === $mail_verif && filter_var($mail, FILTER_VALIDATE_EMAIL)){
				// echo "mail ok<br>";
				// On vérifié que le login est valide
				$tab = ['admin', 'adm', 'administrateur', 'administrator'];
				if ($login && !(in_array(strtolower($pass), $tab))){
					// echo "login != pass ok<br>";
					$query = $db->prepare('SELECT * FROM users WHERE (Login COLLATE utf8_general_ci = :login || Mail COLLATE utf8_general_ci = :mail)');
					$query->bindValue(":login", $login);
					$query->bindValue(":mail", $mail);
					$query->execute();
					$data = $query->fetch(PDO::FETCH_ASSOC);
					// echo "data ok<br>";
					/*
					Si il n'y a pas déjà un utilisateur ayant le même login ou la même adresse e-mail
					On enregistre un nouveau compte utilisateur avec le rôle user en base de données
					*/
					if (!(isset($data['ID']))){
						// echo "data id ok<br>\n";
						$pass = password_hash($pass, PASSWORD_DEFAULT);
						$clef = hash("whirlpool", (microtime()*42));
						$dir = $login;
						$dir = "img/".$dir;
						while (is_dir($dir)){
							$dir = $login;
							$dir = "img/".$dir;
						}
						// echo "pass = ( ".$pass." )<br>clef = ( ".$clef." )<br>dir = ( ".$dir." )<br>";
						mkdir("../".$dir);
						// $query = $db->prepare('INSERT INTO users (Login, Mail, Password, active, clef, role, id_icon, date_inscription, images_dir) VALUES (:login, :mail, :pass, 0, :clef, "standard", "user", 1, NOW(), :dir)');
						// $query->bindValue(":login", $login);
						// $query->bindValue(":mail", $mail);
						// $query->bindValue(":pass", $pass);
						// $query->bindValue(":clef", $clef);
						// $query->bindValue(":dir", $dir);
						// $query->execute();
						// Ici nous envoyons un e-mail à l'utilisateur afin qu'il puisse valider son compte
						// $text = "<html><head><meta charset = \"utf-8\"></head><body><h1>Bienvenue sur Camagru</h1>
						// <p>Compte créé sur l'adresse ".$mail." , avec le login ".$login.".</p>
						// <p>Pour finaliser votre inscription, cliquez sur le lien ci dessous.</p><p><a href = \"inscription.php?submit=validation&login=".$login."&clef=".$clef."\">Valider l'inscription</a></p>
						// <p>Ou copiez / collez le dans la barre d'adresse de votre navigateur.</p>
						// <p>http://www.camagru.fr/create.php?submit=validation&login=".$login."&clef=".$clef."</p></body></html>";
						//
						// $subject = "Camagru - Inscription";
						// $headers = "From : register@camagru42.fr"."\r\n"."Reply-To: noreply@camagru42.fr";
						// $tab = array("email" => $mail, "message" => $text, "subject" => $subject, "headers" => $headers);
						// $email = new Email($tab);
						// $email->sendEmail();

						// Le message que l'on affiche pour dire qu'on a envoyé un e-mail à l'utilisateur. (affiché en vert).

						$message = array("Bienvenue sur Camagru ! Pour valider votre inscription un mail vous a été envoyé a l'adresse suivante : ".$mail."", "ok");
						exit(0);
					}
					else
					$message = array("Ce login ou cette adresse e-mail est déjà enregistré", "error");
				}
				else
				$message = array("Le login n'est pas valide", "error");
			}
			else
			$message = array("L'adresses mail n'est pas valide", "error");
		}
		else
		$message = array("Le mot de passe n'est pas valide", "error");
	}
// 	/*
// 	En dessous sera le code de validation de l'inscription
// 	Après renvoie de l'e-mail par l'utilisateur
// 	*/
// 	if (isset($_GET['submit']) && $_GET['submit'] === "validation"){
// 		// On vérifie que login et clef sont présent
// 		if (isset($_GET['login']) && isset($_GET['clef'])){
// 			$query = $db->prepare('SELECT * FROM `users` WHERE (`Login` COLLATE utf8_bin = :login && `clef` COLLATE utf8_bin = :clef)');
// 			$query->bindValue(':login', $_GET['login']);
// 			$query->bindValue(':clef', $_GET['clef']);
// 			$query->execute();
// 			$data = $query->fetch(PDO::FETCH_ASSOC);
// 			// On vérifie qu'il y a bien un utilisateur avec ce login et la clef correspondante en BDD
// 			if (isset($data['id'])){
// 				/*
// 				Si actif = 0 on active le compte et on passe actif a 1
// 				Si actif vaut 2 c'est qu'il est suspendu
// 				Sinon c'est quele compte est déjà actif
// 				*/
// 				if (isset($data['active']) && $data['active'] === '0'){
// 					$query = $db->prepare('UPDATE `users` SET `active` = 1 WHERE (`Login` = :login && `clef` = :clef)');
// 					$query->bindValue(':login', $_GET['login']);
// 					$query->bindValue(':clef', $_GET['clef']);
// 					$query->execute();
// 					$message = array("Votre compte a été activé avec succès", "ok");
// 				}
// 				else if (isset($data['active']) && $data['active'] === '2')
// 				$message = array("Votre compte a été suspendu, pour plus d'informations veuillez contacter l'administrateur du site", "error");
// 				else
// 				$message = array("Votre compte est déjà actif", "ok");
// 			}
// 			else
// 			$message = array("Un erreur c'est produite, veuillez contacter l'administrateur du site.", "error");
// 		}
// 		else
// 		$message = array("Un erreur c'est produite, veuillez contacter l'administrateur du site.", "error");
}
?>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html">
	<meta charset="UTF-8">
	<title>*******CAMAGRU*******</title>
	<link rel="stylesheet" href="../css/style.css">
</head>
<body>
	<div class="form-signin">
		<div class="header-log">
			<p><strong>Enregistrement</strong></p>
		</div>
		<form action="create.php" method="post">
			<p><i>Login</i><input type="text" name="login"/></p>
			<p><i>eMail</i><input type="email" name="mail"/></p>
			<p><input type="email" name="mail_verif" placeholder="verification"/></p>
			<p><i>Mot de passe</i><input type="password" name="passwd"/></p>
			<p><input type="password" name="passwd_verif" placeholder="verification"/></p>
			<p><input class="button" type="submit" name="submit" value="inscription"></p>
		</form>
	</div>
</body>
</html>
