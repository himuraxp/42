<?php
session_start();
$msgs = [];
if ($_SESSION['loggued_on_user'] && $_SESSION['loggued_on_user'] !== "")
{
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html">
		<meta charset="UTF-8">
		<style>
			body {background: grey;}
			.form-signin {
				background: -moz-linear-gradient(-45deg, rgba(215,215,215,1) 0%, rgba(240,240,240,1) 63%, rgba(255,255,255,0.2) 100%);
				background: -webkit-linear-gradient(-45deg, rgba(215,215,215,1) 0%,rgba(240,240,240,1) 63%,rgba(255,255,255,0.2) 100%);
				background: linear-gradient(135deg, rgba(215,215,215,1) 0%,rgba(240,240,240,1) 63%,rgba(255,255,255,0.2) 100%);
				display: block;
				border: 2px solid #333;
				border-radius: 5px;
				box-shadow: 2px 2px 4px #333;
				width: 250px;
				margin: auto;
				margin-top: 25%;
			}
			h1 {
				text-align: center;
				text-shadow: 1px 1px 2px #333;
				color: #333;
			}
			p {
				text-align: center;
				color: #333;
			}
			i { padding: 5px; }
			input {
				text-align: center;
				width: 80%;
				color: #333;
				font-size: 16px;
				border-radius: 3px;
			}
			a {
				display: block;
				margin: auto;
				text-align: center;
				padding: 5px;
				text-decoration: none;
				border-bottom: 2px solid #333;
				box-shadow: 2px 2px 4px #333;
			}
			.chat {
				display: block;
				background: -moz-linear-gradient(-45deg, rgba(215,215,215,1) 0%, rgba(240,240,240,1) 63%, rgba(255,255,255,0.2) 100%);
				background: -webkit-linear-gradient(-45deg, rgba(215,215,215,1) 0%,rgba(240,240,240,1) 63%,rgba(255,255,255,0.2) 100%);
				background: linear-gradient(135deg, rgba(215,215,215,1) 0%,rgba(240,240,240,1) 63%,rgba(255,255,255,0.2) 100%);
				position: absolute;
				top: 0;
				width: 90%;
				height: 300px;
				border: 2px solid #333;
				border-radius: 5px;
				box-shadow: 2px 2px 4px #333;
			}
			.button {
				color: white;
				background: rgba(157,213,58,1) ;
				background: -moz-linear-gradient(-45deg, rgba(157,213,58,1) 0%, rgba(161,213,79,1) 50%, rgba(128,194,23,1) 51%, rgba(124,188,10,1) 100%);
				background: -webkit-linear-gradient(-45deg, rgba(157,213,58,1) 0%,rgba(161,213,79,1) 50%,rgba(128,194,23,1) 51%,rgba(124,188,10,1) 100%);
				background: linear-gradient(135deg, rgba(157,213,58,1) 0%,rgba(161,213,79,1) 50%,rgba(128,194,23,1) 51%,rgba(124,188,10,1) 100%);
				border-color: #809164;
				box-shadow: 2px 2px 4px #333;
				font-weight: bolder;
				font-size: 18px;
				transition-duration: 0.4s;
			}
			.button:hover {
				background: rgb(252,234,187);
				background: -moz-linear-gradient(-45deg, rgba(252,234,187,1) 0%, rgba(252,205,77,1) 50%, rgba(248,181,0,1) 51%, rgba(251,223,147,1) 100%);
				background: -webkit-linear-gradient(-45deg, rgba(252,234,187,1) 0%,rgba(252,205,77,1) 50%,rgba(248,181,0,1) 51%,rgba(251,223,147,1) 100%);
				background: linear-gradient(135deg, rgba(252,234,187,1) 0%,rgba(252,205,77,1) 50%,rgba(248,181,0,1) 51%,rgba(251,223,147,1) 100%);
				border-color: #BFD49F;
				color: #717D5F;
				transition-duration: 0.4s;
			}
		</style>
	</head>
	<body>
		<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
		<div class="form-signin">
			<h1>42 Chat</h1>
			<form method="POST" action="speak.php">
				<p><i>Message</i><input type="text" name="msg" value="" />
				<p><input class="button" type="submit" name="submit" value="ENVOYER"></p>
			</form>
			<a href="logout.php" class="button">Déconnection</a>
		</div>
	</body>
</html>

<?php
  if ($_POST && $_POST["submit"] === 'OK')
  {
    if ($_POST['msg'] !== "")
    {
      date_default_timezone_set('Europe/Paris');
      if (!file_exists('../private'))
        mkdir('../private');
      if (file_exists('../private/chat')) {
        $fd = fopen('../private/chat', 'r+');
        if (flock($fd, LOCK_EX | LOCK_SH))
          $msgss = unserialize(file_get_contents('../private/chat'));
      }
      $msg = array('login' => $_SESSION['loggued_on_user'], 'time' => time(), 'msg' => $_POST['msg']);
      $msgs[] = $msg;
      file_put_contents('../private/chat', serialize($msgs));
      if (isset($fd))
      {
        flock($fd, LOCK_UN);
        fclose($fd);
      }
    }
  }
  return;
}
echo "ERROR\n"
?>
