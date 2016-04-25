<?php
function auth($login, $passwd)
{
	$link = mysql_connect("localhost", "root", "Eiko0962!")
		or die("Impossible de se connecter : " . mysql_error());
	mysql_select_db("camagru");
	$result = mysql_query("SELECT Mail, Password, active FROM users WHERE mail == $login");

	if ($login && $passwd)
	{
		if ($result[1] === hash("whirlpool", $passwd))
		{
			if ($result[2] === true)
				return true;
			else
				return false;
				// faire une page pour redemander l envoi de mail de confirmation
		}
		else
			return false;
	}
	else
		return false;
}
?>
