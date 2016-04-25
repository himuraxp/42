<?php
session_start();
if ($_POST['submit'] === "OK")
{
	if (($_POST['mail'] != NULL) && ($_POST['passwd'] != NULL))
	{
		$passwd = hash("whirlpool", $_POST['passwd']);
		$login = $_POST['mail'];
		$link = new  mysqli("localhost", "camagru", "camagru", "camagru");
		if ($link->connect_error) {
		    die("Connection failed: " . $link->connect_error);
		}

		// $result = mysqli_query("SELECT Mail FROM users WHERE mail == $login");
		// if ($login === $result[0])
		// 	exit("ERROR\n");
		// $test = "INSERT INTO users (LastName, FirstName, Mail, Password, active) VALUES ($_POST['lastname'], $_POST['firstname'], $login, $passwd, 'true')";
		// mysqli_query($link, "INSERT INTO users (LastName, FirstName, Mail, Password, active) VALUES ($_POST['lastname'], $_POST['firstname'], $login, $passwd, 'true')");
		// mysqli_close($link);
		$_SESSION['current_user'] = $login;
		// header('Location: ../main/camagru.php');
		exit(0);
	}
	else
	{
		header('Location: ../index.html');
		exit(0);
	}
}
else
{
	header('Location: ../index.html');
	exit(0);
}

?>
