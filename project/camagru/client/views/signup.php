<?php
session_start();
if (!isset($_SESSION['login'])){
	include('header.php');
	?>
	<script src="/client/scripts/verifypass.js"></script>
	<div class="form-signin">
		<div class="header-log">
			<p>Enregistrement</p>
		</div>
		<div class= "form">
			<form name="login" action="/server/register.php" method="post" accept-charset="utf-8">
				<p>
					<i><label for="login">Identifiant</label></i>
					<input name="login" placeholder="identifiant" required autofocus>
				</p>
				<p>
					<i><label for="email">Email</label></i>
					<input name="email" type="email" placeholder="email" required>
				</p>
				<p>
					<i><label for="password">Mot de passe</label></i>
					<input id="normalpass" type="password" name="password" placeholder="mot de passe" required>
				</p>
				<p>
					<i><label for="confpassword">Vérification mot de passe</label></i>
					<input id="repeatpass" type="password" name="confpassword" placeholder="confirmation" required>
				</p>
				<p><input type="submit" value="Enregistrer" id="SignupButton" enable  class="button"></p>
			</form>
			<p class="link-sign"><a href="/client/views/signin.php" class="button login" name="submit" value="inscription">J'ai deja un compte</a></p>
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
