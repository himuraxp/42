<?php
session_start();
if (!isset($_SESSION['login'])){
	include('header.php');
?>
<div class="form">
	<div class="form-init">
		<div class="form-header">
			<h1><strong>MATCHA</strong></h1>
		</div>
			<form name="login" action="/server/login.php" method="post" accept-charset="utf-8">
				<p><label for="usermail"></label><input type="text" name="login" placeholder="Identifiant" required autofocus/></p>
				<p><label for="password"></label><input type="password" name="password" placeholder="Mot de passe" required></p>
				<p><input class="button" type="submit" name="submit" value="Connection"></p>
			</form>
		<p class="form-link"><a href="/client/views/signup.php" class="button login" name="submit" value="inscription">Créer mon compte</a></p>
		<p class="form-link"><a href="/client/views/resetpassword.php" class="button login">Reinitialiser mon mot de passe</a></p>
	</div>
</div>
<?php
}
else{
	header('Location: /');
	exit;
}
?>
