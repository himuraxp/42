<?php
	session_start();
	include("./auth.php");
	include("./auth_admin.php");
	$i = 0;
	foreach($_POST as $key => $value)
	{
		if ($key == "login" || $key == "passwd")
			$i++;
	}
	if ($i == 2)
	{
		
		$auth = auth($_POST["login"], $_POST["passwd"]);
		$auth_admin = auth_admin($_POST["login"], $_POST["passwd"]);
		if ($auth == true || $auth_admin == true)
		{
			if ($auth_admin == true)
				$_SESSION['admin_state'] = 1;
			else
				$_SESSION['admin_state'] = 0;
			$_SESSION['loggued_on_user'] = $_POST["login"];
			echo "OK;<div class='console'>Vous êtes connecté</div>";
		}
		else
		{
			$_SESSION['loggued_on_user'] = "";
			print "ERROR;<div class='console'>Identifiant ou Mot de passe incorrecte</div>";
		}
	}
?>