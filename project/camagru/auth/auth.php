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
?>
	<html>
	<?php
		include('head.html');
	?>
		<div class='message-error'>Identifiants erronés ou compte non activé</div>
		<body>
			<div class="form-signin">
				<div class="header-log">
					<p>Camagru</p>
				</div>
				<form action="/main/camagru.php" method="post">
					<p><i>Identifiant</i><input type="text" name="login"/></p>
					<p><i>Mot de passe</i><input type="password" name="passwd"/></p>
					<p><input class="button" type="submit" name="submit" value="connection"></p>
				</form>
				<a href="../auth/create.php" class="button login" name="submit" value="inscription">Créer mon compte</a>
			</div>
		</body>
	</html>
<?php
		return (false);
	}
}
?>
