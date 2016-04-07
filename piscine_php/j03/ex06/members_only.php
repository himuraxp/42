<?php
$img = file_get_contents("../img/42.png");
$pwd = ($_SERVER['PHP_AUTH_PW'] == null) ? null : $_SERVER['PHP_AUTH_PW'];
$name = ($_SERVER['PHP_AUTH_USER'] == null) ? null : $_SERVER['PHP_AUTH_USER'];
if ("zaz:jaimelespetitsponeys" === ( $name . ':' . $pwd ))
{
	echo "<html><body style='background: black;'>";
	echo "<h1 style='text-align: center; color: white;'>Bonjour Zaz<br>";
	echo "<img src='data:image/png;base64,".base64_encode($img)."'></h1>";
	echo "</body></html>";
}
else
{
	header("WWW-Authenticate: Basic realm=''Espace membres''");
	header("Connection: close");
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>"."\n";
}
?>
