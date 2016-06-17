<?php
include '../config/database.php';
session_start();
unset($_SESSION['login']);
if (isset($_POST['login'])){
	try{
		$DB_DSNNAME = $DB_DSN.";dbname=".$DB_NAME;
		$pdo = new PDO($DB_DSNNAME , $DB_USER, $DB_PASSWORD);
	}
	catch(PDOException $e){
		$msg = 'ERREUR PDO dans '.$e->getFile().' Ligne '.$e->getLine().' : '.$e->getMessage();
		die($msg);
	}
	if (ctype_alnum($_POST['login']) || filter_var($_POST['login'], FILTER_VALIDATE_EMAIL)) {
	$login = htmlspecialchars($_POST['login']);
	$mdp = htmlspecialchars(hash('whirlpool', $_POST['password']));
	$stmt = $pdo->prepare("SELECT mdp, login FROM ".$DB_TABLE['users']." where login=:login and confirmed='1'");
	$stmt->bindvalue(':login', $login, PDO::PARAM_STR);
	$stmt->execute();
	$arr = $stmt->fetch();
	if ($arr != NULL) {
		if ($arr["mdp"] == $mdp){
			$_SESSION['login'] = $arr["login"];
		}
		else {
			header("Content-Type: text/html");
			?>
			<div class="message-error-static">
				<p class="message-text">
					<strong class="message-type"> ERREUR : </strong>Le mot de passe est incorrect !
				</p>
			</div>
			<?php
			include '../client/views/signin.php';
			exit();
		}
	}
	else {
		$stmt = $pdo->prepare("SELECT mdp, login FROM ".$DB_TABLE['users']." where email=:email and confirmed='1'");
		$stmt->bindvalue(':email', $login, PDO::PARAM_STR);
		$stmt->execute();
		$arr = $stmt->fetch();
		if ($arr != NULL) {
			if ($arr["mdp"] == $mdp){
				$_SESSION['login'] = $arr["login"];
			}
			else {
				header("Content-Type: text/html");
				?>
				<div class="message-error-static">
					<p class="message-text">
						<strong class="message-type"> ERREUR : </strong>Le mot de passe est incorrect !
					</p>
				</div>
				<?php
				include '../client/views/signin.php';
				exit();
			}
		}
		else {
			header("Content-Type: text/html");
			?>
			<div class="message-error-static">
				<p class="message-text">
					<strong class="message-type"> ERREUR : </strong>Aucun compte n'est associé à <?php echo $login ?> !
				</p>
			</div>
			<?php
			include '../client/views/signin.php';
			exit();
		}
	}
	$pdo = null;
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
		include '../client/views/signin.php';
		exit();
	}
}
header('Location: /');
exit;
?>
