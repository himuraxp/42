<?php
$path = "../private/passwd";
if ($_POST['submit'] === "OK")
{
	if (($_POST['login'] != NULL) && ($_POST['passwd'] != NULL))
	{
		$passwd = hash("whirlpool", $_POST['passwd']);
		$login = $_POST['login'];
		if (file_exists($path) == true)
		{
			$pw_list = file_get_contents($path);
			$pw_list = unserialize($pw_list);
			foreach ($pw_list as $key => $value)
			{
				if ($login === $key)
				{
					echo "ERROR (Ce login est deja enregisté !)\n";
					if ($passwd !== $value)
						echo "ERROR (En plus le mot de passe est incorrect !!!)\n";
				}
				else
				{
					$auth = array($_POST['login'] => $passwd);
					$serial = serialize($auth);
					file_put_contents("$path", $serial, FILE_APPEND | LOCK_EX);
					echo "OK\n";
				}
			}
		}
		else
		{
			mkdir("../private/");
			$auth = array($_POST['login'] => $passwd);
			$serial = serialize($auth);
			file_put_contents("$path", $serial, FILE_APPEND | LOCK_EX);
			echo "OK\n";
		}
	}
	else
		echo "ERROR (Vérifier que l'ensemble des données sont renseignées)\n";
}
else
echo "ERROR\n";
?>
