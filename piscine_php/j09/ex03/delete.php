<?php
if (isset($_GET['todo']) && strlen($_GET['todo'])) {
	$var = $_GET['todo'];
	if (!file_exists("../private/"))
		if (!mkdir("../private"))
			$lol = "lol";
	if (file_exists("../private/todo"))
	{
		$tab = unserialize(file_get_contents("../private/todo"));
		unset($tab[$var]);
		$tab = array_values($tab);
		if (file_put_contents("../private/todo", serialize($tab)))
			include("select.php");
	}
}
?>