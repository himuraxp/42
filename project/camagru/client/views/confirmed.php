<?php
session_start();
if (!isset($_SESSION['login'])){
	include('header.php');
?>
<div class="form-signin">
	<div class="header-log">
		<p>Activation</p>
	</div>
	<div class= "form">
		<form name="login" action="/server/register.php" method="get" accept-charset="utf-8">
			<p>
				<i><label for="confirm">Code</label></i>
				<input name="confirm" placeholder="coller ici" required autofocus>
			<p>
				<input type="submit" class="button"></input>
			<p>
		</form>
	</div>
	<p class="link-sign">
		<a href="/client/views/signin.php" class="button login" name="submit" value="inscription">Me connecter</a>
	</p>
</div>
<?php
}
else{
	echo 'All ready login'.PHP_EOL;
}
?>
