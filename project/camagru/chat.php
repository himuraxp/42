<?php
session_start();
$msgs = [];
if ($_SESSION['loggued_on_user'] && $_SESSION['loggued_on_user'] != "")
{
	if ($_POST && $_POST["submit"] === 'OK' && $_POST['msg'] !== "")
	{
		if (!file_exists('../private'))
			mkdir('../private');
		if (file_exists('../private/chat'))
		{
			date_default_timezone_set('Europe/Paris');
			$fd = fopen('../private/chat', 'r');
			if (flock($fd, LOCK_SH)) {
				$msgs = unserialize(file_get_contents('../private/chat'));
				foreach ($msgs as $tab) {
					echo "[".date("H:i", $tab['time'])."] ";
					echo "<b>".$tab['login']."</b>: ";
					echo $tab['msg']."<br />"."\n";
				}
				flock($fd, LOCK_UN);
			}
			fclose($fd);
		}
	}
}
?>
