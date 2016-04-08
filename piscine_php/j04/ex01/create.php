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
			foreach ($pw_list as $value)
			{
				if ($login === $value[0])
				{
					exit("ERROR (Ce login est deja enregisté !)\n");
					if ($passwd !== $value['passwd'])
						exit("ERROR (En plus le mot de passe est incorrect !!!)\n");
				}
			}
		}
		else
			mkdir("../private/");
 		$pw_list[] = array($_POST['login'], $passwd);
		$serial = serialize($pw_list);
		file_put_contents("$path", $serial);
		echo "OK\n";
	}
	else
		echo "ERROR (Vérifier que l'ensemble des données sont renseignées)\n";
}
else
echo "ERROR\n";
?>
