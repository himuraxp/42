<?php
session_start();
if (!isset($_SESSION['login'])){
	include('header.php');
?>
<div class="form-signin">
	<div class="header-log">
		<p><strong>Camagru</strong></p>
	</div>
	<form name="login" action="/server/login.php" method="post" accept-charset="utf-8">
		<p><i><label for="usermail">Identifiant</label></i><input type="text" name="login" required autofocus/></p>
		<p><i><label for="password">Mot de passe</label></i><input type="password" name="password" placeholder="password" required></p>
		<p><input class="button" type="submit" name="submit" value="Connection"></p>
	</form>
	<p class="link-sign"><a href="/client/views/signup.php" class="button login" name="submit" value="inscription">Créer mon compte</a></p>
	<p class="link-sign"><a href="/client/views/resetpassword.php" class="button login">Reinitialiser mon mot de passe</a></p>
	<p class="link-sign"><a href="/client/views/confirmed.php" class="button login">Enter le code d'activation code</a></p>
</div>
<?php
}
else{
	header('Location: /');
	exit;
}
?>
