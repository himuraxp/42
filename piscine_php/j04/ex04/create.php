<?php
header('Location: index.html');
session_start();
$_SESSION['login'] = $_POST['login'];
$_SESSION['passwd'] = $_POST['passwd'];
$_SESSION['submit'] = $_POST['submit'];
$path = "../private/passwd";
if ($_SESSION['submit'] === "OK")
{
	if (($_SESSION['login'] != NULL) && ($_SESSION['passwd'] != NULL))
	{
		$passwd = hash("whirlpool", $_SESSION['passwd']);
		$login = $_POST['login'];
		if (file_exists($path) == true)
		{
			$listpw = file_get_contents($path);
			$listpw = unserialize($listpw);
			foreach ($listpw as $value)
			{
				if ($login === $value[0])
					exit("ERROR\n");
					if ($passwd !== $value['passwd'])
						exit("ERROR\n");
				}
			}
		}
		else
		mkdir("../private/");
 		$listpw[] = array($_POST['login'], $passwd);
		$serial = serialize($listpw);
		file_put_contents("$path", $serial);
		echo "OK\n";
	}
	else
		exit("ERROR\n");
}
else
	exit("ERROR\n");
?>
