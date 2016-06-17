<?php
$url = $_SERVER['REQUEST_URI'];
if (!isset($_SESSION['login'])){
?>
<body>
<?php
}
else {
	if ($url == "/profil") { ?>
		<script src="/client/scripts/take_picture.js"></script>
		<body onload="init();">
<?php }} ?>

	<header id="header">
		<a href="/"><h1>matcha</h1></a>
		<nav class="links">
			<ul>
				<li>
					<a href="/client/views/profil.php">Profil</a>
				</li>
				<li>
					<a href="/server/logout.php">Logout</a>
				</li>
			</ul>
			<ul class="main">
				<li>
					<a href="#search"><div class="fa fa-search"></div></a>
				</li>
			</ul>
		</nav>
	</header>
