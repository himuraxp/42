<?php
session_start();
function loadClass($file){
	require("class/".$file.".php");
}
spl_autoload_register("loadClass");
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html">
		<meta charset="UTF-8">
		<title>*******CAMAGRU*******</title>
		<link rel="stylesheet" href="css/style.css">
	</head>
	<body>
		<div class="form-signin">
			<div class="header-log">
				<p><strong>Camagru</strong></p>
			</div>
			<form action="/main/camagru.php" method="post">
				<p><i>Identifiant</i><input type="text" name="login"/></p>
				<p><i>Mot de passe</i><input type="password" name="passwd"/></p>
				<p><input class="button" type="submit" name="submit" value="connection"></p>
			</form>
			<a href="/auth/create.php" class="button login" name="submit" value="inscription">Créer mon compte</a>
		</div>
	</body>
</html>
