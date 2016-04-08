<?php
$path = "../private/passwd";
if ($_POST['submit'] === "OK")
{
	if (($_POST['login'] != NULL) && ($_POST['newpw'] != NULL) && ($_POST['oldpw'] != NULL))
	{
		$oldpw = hash("whirlpool", $_POST['oldpw']);
		$newpw = hash("whirlpool", $_POST['newpw']);
		$login = $_POST['login'];
		if (file_exists($path) == true)
		{
			$i = -1;
			$pw_list = file_get_contents($path);
			$pw_list = unserialize($pw_list);
			foreach ($pw_list as $key => $value)
			{
				$i++;
				if ($login === $key)
				{
					if ($oldpw !== $value)
						echo "ERROR (En plus le mot de passe est incorrect !!!)\n";
					else
					{
						$pw_list[$login] = $newpw;
						$pw_list = serialize($pw_list);
						file_put_contents($path, $pw_list);
						echo "OK\n";
					}
				}
			}
		}
	}
	else
		echo "ERROR (Vérifier que l'ensemble des données sont renseignées)\n";
}
else
echo "ERROR\n";
?>
