<?php
session_start();
if(!isset($_SESSION['login'])){
	if(isset($_GET['reset'])){
		include('header.php');
		?>
		<div id="message-err" class="message-error-static" style="display:none">
			<p class="message-text" id="message-err-dif">
				Pas de correspondence entre les mots de passes !
			</p>
		</div>
		<div id="message-ok" class="message-valid-static" style="display:none">
			<p class="message-text">
				Les mots de passes sont identiques
			</p>
		</div>
		<div class="form-signin">
			<div class="header-log">
				<p><strong>Reinitialiser un mot de passe</strong></p>
			</div>
			<form name="resetlast" action="/server/resetpassword.php" method="post" accept-charset="utf-8">
				<div>
					<input type="text" name="reset" value="<?php echo $_GET['reset']; ?>" style="display:none;"/>
				</div>
				<p class="message-text" id="message-err-reg" style="display:none"><i>
					Le mot de passe doit contenir au minimum une <strong>minuscule</strong>, une <strong>majuscule</strong> et un <strong>chiffre</strong> !<br></i>
				</p>
				<p>
					<i>
						<label for="password">Mot de passe</label>
					</i>
					<input id="normalpass" type="password" name="password" placeholder="password" onkeyup="verifpass();" required>
				</p>
				<p>
					<i>
						<label for="confpassword">Confirmation</label>
					</i>
					<input id="repeatpass" type="password" name="confpassword" placeholder="retappez le nouveau mot de passe" onkeyup="verifpass();" required>
				</p>
				<p>
					<input class="button" type="submit" name="submit" value="Login" id="SignupButton" disabled>
				</p>
			</form>
			<p class="link-sign">
				<a href="/" class="button login" name="submit">Revenir à l'accueil</a>
			</p>
			<p class="link-sign">
				<a href="/client/views/signup.php" class="button login" name="submit" value="inscription">Créer mon compte</a>
			</p>
		</div>
		<script type="text/javascript" src="../scripts/verifypass.js">

		</script>
		<?php
	}
	else{
		include('header.php');
		?>
		<div class="form-signin">
			<div class="header-log">
				<p><strong>Reinitialiser un mot de passe</strong></p>
			</div>
			<form name="reset" action="/server/resetpassword.php" method="post" accept-charset="utf-8">
				<div class="input">
					<p>
						<i>
							<label for="email">Email</label>
						</i>
					</p>
					<p>
						<input name="email" type="email" placeholder="email" required autofocus>
					</p>
				</div>
				<p>
					<input class="button" type="Submit" class="FormButton" value="Valider"></button>
				</p>
			</form>
			<p class="link-sign">
				<a href="/" class="button login" name="submit">Revenir à l'accueil</a>
			</p>
			<p class="link-sign">
				<a href="/client/views/signup.php" class="button login" name="submit" value="inscription">Créer mon compte</a>
			</p>
		</div>
		<?php
	}
}
else{
	echo 'All ready login'.PHP_EOL;
}
?>
