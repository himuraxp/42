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
		echo coucou;
		if (ctype_alnum($_POST['login'])) {
			$login	= htmlspecialchars($_POST['login']);
			$querry = $pdo->prepare("SELECT id, login, email FROM ".$DB_TABLE['users']."");
			echo coucou;
			$arr = $pdo->query($querry)->fetchAll();
			if (isset($arr)){
				$max = sizeof($arr);
				for($i = 0; $i < $max; $i++) {
					if ($login === $arr[1][$i]) {
						header("Content-Type: text/html");
						?>
						<div class="message-error-static">
							<p class="message-text">
								<strong class="message-type"> ERREUR : </strong>Cet identifiant correspondent déja à un compte existant !
							</p>
						</div>
						<?php
						include '../client/views/signup.php';
					}
				}
			}
			if ($_POST['password'] === $_POST['confpassword']) {
				$mdp	= htmlspecialchars(hash('whirlpool', $_POST['password']));
				$email =  htmlspecialchars($_POST['email']);

				$headers  = 'MIME-Version: 1.0' . "\r\n";
				$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
				$headers .= 'From: Admin<admin@camagru42.paris>' . "\r\n" .
				$headers .= 'Reply-To: <admin@camagru42.paris>' . "\r\n" .
				$headers .= 'X-Mailer: PHP/' . phpversion();
				$salt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
				$str = "";
				for ($i=0; $i <= strlen($salt)/2; $i++){
					$str .= $salt[rand() % strlen($salt)];
				}
				$hash = htmlspecialchars(hash('md5', $str.$email));
				$link = "http://localhost:8888/server/register.php?confirm=".$hash;
				$msg = '<html>
							<head>
								<title>Confirmation de compte Camagru42</title>
							</head>
							<body>
						<a href="'.$link.'">Cliquez sur ce lien pour activer votre compte</a>
						<p>Puis copier le code " <strong>'.$hash'</strong> " pour confirmer votre enregistrement avec le bouton "Enregistrer le code d\'activation" sur <a href="https://camagru42.paris">Camagru42</a>.</p>
						</body>
						</html>';
				mail($email, "Activez votre comtpe", $msg, $headers);
				$stmt = $pdo->prepare("INSERT INTO ".$DB_TABLE['users']."(login, email, mdp, confirm)  VALUES(:login, :email, :mdp, '$hash')");
				$stmt->bindValue(':login', $login);
				$stmt->bindValue(':email', $email);
				$stmt->bindValue(':mdp', $mdp);
				$stmt->execute();
			}
			else {
				header("Content-Type: text/html");
			?>
				<div class="message-error-static">
					<p class="message-text">
						<strong class="message-type"> ATTENTION : </strong>Les deux mots de passe ne correspondent pas !
					</p>
				</div>
			<?php
				include '../client/views/signup.php';
			}
		}
		else {
			header("Content-Type: text/html");
		?>
			<div class="message-error-static">
				<p class="message-text">
					<strong class="message-type"> ATTENTION : </strong>Les chiffres et les lettres sont les seuls charactères accepté dans le champs identifiant !
				</p>
			</div>
		<?php
			include '../client/views/signup.php';
		}
	}
	$pdo = NULL;
}
header('Location: /');
exit;
?>
