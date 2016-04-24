<?php
require('auth.php');
session_start();
if ($_POST['login'] && $_POST['passwd'])
{
	$_SESSION['login'] = $_POST['login'];
	$_SESSION['passwd'] = $_POST['passwd'];
	if (auth($_SESSION['login'], $_SESSION['passwd']))
	{
		$_SESSION['loggued_on_user'] = $_SESSION['login'];
?>
<html>
	<head>
		<title>*******CAMAGRU*******</title>
		<link rel="stylesheet" href="css/style.css">
		<link rel="stylesheet" href="css/header.css">
		<link rel="stylesheet" href="css/body.css">
		<link rel="stylesheet" href="css/footer.css">
		<link rel="stylesheet" href="css/keyframes.css">
		<link href='https://fonts.googleapis.com/css?family=Lobster' rel='stylesheet' type='text/css'>
		<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>
		<script type="text/javascript" src="js/javascript.js" media="javascript"></script>
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.6.1/css/font-awesome.min.css">
	</head>
	<body>
		<div id="nav" class="nav">
			<ul class="nav-left">
				<li class="nav-bloc button">
					<p><b><a href="/" class="link" alt="Accueil">Shoot me</a></b></p>
				</li>
				<li class="nav-bloc button">
					<p><b><a href="/" class="link" alt="Galerie">Galerie</a></b></p>
				</li>
				<li class="nav-bloc button">
					<p><b><a href="modif.html" class="link-right" alt="Mon compte">Mon compte</a></b></p>
				</li>
				<li class="nav-bloc button" id="out" >
					<p><a id="logout" href="/" class="link fa fa-sign-out" aria-hidden="true" alt="logout"></a></p>
				</li>
			</ul>
			<div class="logo"><a href="camagru.php"><h1>camagru</h1></a></div>
		</div>
		<div id="container" class="container">
			<div id="box" class="box">
				<div class="box-menu">
					<h1 id="title" class="title">Shoot me</h1>
					<div class="save"></div>
				</div>
				<div id="box-cam" class="box-cam">
					<img src="/img/ab.jpg" class="image-cam"/>
				</div>
			</div>
			<div id="galerie" class="galerie">
				<h1 id="title" class="title">Ma galerie</h1>
				<div id="picture" class="picture">
				</div>
				<div id="picture" class="picture">
				</div>
				<div id="picture" class="picture">
				</div>
			</div>
		</div>
		<div id="footer" class="footer">
			<div class="logo"><h1>camagru @ ylarbi 42 school</h1></div>
		</div>
	</body>
</html>
<?php
	}
	else
	{
		$_SESSION['loggued_on_user'] = '';
		exit("ERREUR\n");
	}
}
else
	exit("ERROR\n");
?>
