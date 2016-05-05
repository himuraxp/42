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
		<p><input class="button" type="submit" name="submit" value="connection"></p>
	</form>
	<a href="/client/views/signup.php" class="button login" name="submit" value="inscription">Créer mon compte</a>
	<a href="/client/views/confirmed.php" class="button login">Enter le code d'activation code</a>
</div>
<script src="/client/scripts/take_picture.js"></script>
<?php
}
else{
	header('Location: /');
	exit;
}
?>
