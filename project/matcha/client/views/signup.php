<?php
session_start();
if (!isset($_SESSION['login'])){
	include('header.php');
?>
<script src="/client/scripts/verifypass.js"></script>
<div class="form">
	<div class="form-init">
		<div class="form-header">
			<h1>Enregistrement</h1>
		</div>

		<form name="login" action="/server/register.php" method="post" accept-charset="utf-8">
			<p>
				<i><label for="login"></label></i>
				<input name="login" placeholder="Identifiant" required autofocus>
			</p>
			<p>
				<i><label for="nom"></label></i>
				<input name="nom" placeholder="Nom" required autofocus>
			</p>
			<p>
				<i><label for="prenom"></label></i>
				<input name="prenom" placeholder="Prenom" required autofocus>
			</p>
			<p>
				<i><label for="email"></label></i>
				<input name="email" type="email" placeholder="Email" required>
			</p>
			<p>
				<i><label for="password"></label></i>
				<input id="normalpass" type="password" name="password" placeholder="Mot De Passe" required>
			</p>
			<p>
				<i><label for="confpassword"></label></i>
				<input id="repeatpass" type="password" name="confpassword" placeholder="Confirme MDP" required>
			</p>
			<p><input type="submit" value="Enregistrer" id="SignupButton" enable  class="button"></p>
		</form>
		<p class="form-link"><a href="/client/views/signin.php" class="button login" name="submit" value="inscription">J'ai deja un compte</a></p>
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
