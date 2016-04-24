<?php
header('Location: index.html');
$_SESSION['login'] = $_POST['login'];
$_SESSION['newpw'] = $_POST['newpw'];
$_SESSION['oldpw'] = $_POST['oldpw'];
$_SESSION['submit'] = $_POST['submit'];
$path = "../private/passwd";
if ($_SESSION['submit'] === "OK")
{
	if (($_SESSION['login'] != NULL) && ($_SESSION['newpw'] != NULL) && ($_SESSION['oldpw'] != NULL))
	{
		$oldpw = hash("whirlpool", $_SESSION['oldpw']);
		$newpw = hash("whirlpool", $_SESSION['newpw']);
		$login = $_SESSION['login'];
		$listpw = file_get_contents($path);
		$db = unserialize($listpw);
		$i = -1;
		foreach ($db as $value)
		{
			$i++;
			if ($value[0] === $login)
			{
				if ($oldpw !== $value[1] || $oldpw === $newpw)
					exit("ERROR (En plus le mot de passe est incorrect !!!)\n");
				else
				{
					$db[$i][1] = $newpw;
					$listpw = serialize($db);
					file_put_contents($path, $listpw);
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
