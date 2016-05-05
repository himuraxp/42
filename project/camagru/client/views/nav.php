<?php
$url = $_SERVER['REQUEST_URI'];
if (!isset($_SESSION['login'])){
?>
<body>
<?php
}
else {
	if ($url == "/") { ?>
		<script src="/client/scripts/addclip.js"></script>
		<script src="/client/scripts/take_picture.js"></script>
		<body onload="init();">
<?php }} ?>

	<header class="nav">
		<nav>
			<ul class="nav-left">
			<?php if (!isset($_SESSION['login'])){?>
				<li class="nav-bloc button">
					<p><b><a href="/client/views/galerie.php">Galerie</a></b></p>
				</li>
				<li class="nav-bloc button">
					<p><b><a href="/client/views/resetpassword.php">Mot de passe perdu ?</a></b></p>
				</li>
				<li class="nav-bloc button">
					<p><b><a href="/client/views/signup.php">Créer un compte</a></b></p>
				</li>
				<li class="nav-bloc button">
					<p><b><a href="/client/views/confirmed.php">Enter le code d'activation code</a></b></p>
				</li>
			<?php } else { ?>
				<li class="nav-bloc button">
					<p><b><a href="/client/views/galerie.php">Galerie</a></b></p>
				</li>
				<li class="nav-bloc button">
					<p><b><a href="/server/logout.php">Logout</a></b></p>
				</li>

			<?php } ?>
			</ul>
		</nav>
		<div class="logo"><a href="/"><h1>camagru</h1></a></div>
	</header>
