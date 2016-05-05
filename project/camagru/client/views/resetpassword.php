<?php
session_start();
if(!isset($_SESSION['login'])){
	if(isset($_GET['reset'])){
		include('header.php');
		include('nav.php');
?>
<h2 class="PageTitle">Reinitialiser mot de passe</h2>
<form name="resetlast" action="/server/resetpassword.php" method="post" accept-charset="utf-8">
	<input name="reset" value="<?php echo $_GET['reset']; ?>"/>
	<div class="password">
		<label for="password">Nouveau mot de passe</label>
		<input id="normalpass" type="password" name="password" placeholder="mot de passe" onkeyup="verifpass();" required>
	</div>
	<div class="password">
		<label for="confpassword">Confirmation</label>
		<input id="repeatpass" type="password" name="confpassword" placeholder="retappez le nouveau mot de passe" onkeyup="verifpass();" required>
	</div>
	<input type="submit" value="Login" id="SignupButton" disabled/>
</form>
<?php
		include('footer.php');
	}
	else{
		include('header.php');
		include('nav.php');
?>
<h2 class="PageTitle">Reinitialiser mon mot de passe</h2>
<div class= "form">
	<form name="reset" action="/server/resetpassword.php" method="post" accept-charset="utf-8">
		<div class="input">
			<label for="email">Email</label>
			<input name="email" type="email" placeholder="email" required autofocus>
		</div>
		<button type="Submit" class="FormButton">Valider</button>
	</form>
</div>
<?php
		include('footer.php');
	}
}
else{
	echo 'All ready login'.PHP_EOL;
}
?>
