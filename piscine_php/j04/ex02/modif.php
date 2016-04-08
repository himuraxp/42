<?php
$path = "../private/passwd";
if ($_POST['submit'] === "OK")
{
	if (($_POST['login'] != NULL) && ($_POST['newpw'] != NULL) && ($_POST['oldpw'] != NULL))
	{
		$oldpw = hash("whirlpool", $_POST['oldpw']);
		$newpw = hash("whirlpool", $_POST['newpw']);
		$login = $_POST['login'];
		$pw_list = file_get_contents($path);
		$array = unserialize($pw_list);
		$i = -1;
		foreach ($array as $value)
		{
			$i++;
			if ($value[0] === $login)
			{
				if ($oldpw !== $value[1] || $oldpw === $newpw)
					exit("ERROR (En plus le mot de passe est incorrect !!!)\n");
				else
				{
					$array[$i][1] = $newpw;
					$pw_list = serialize($array);
					file_put_contents($path, $pw_list);
					echo "OK\n";
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
