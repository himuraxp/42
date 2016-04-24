<?php
require('auth.php');
session_start();
if ($_POST['login'] && $_POST['passwd'])
{
	$_SESSION['login'] = $_POST['login'];
	$_SESSION['passwd'] = $_POST['passwd'];
	if (auth($_SESSION['login'], $_SESSION['passwd']))
	{
		$_SESSION['loggued_on_user'] = $_SESSION['login'];
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html">
		<meta charset="UTF-8">
		<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
		<style>
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
	<div >
		<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>
		<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>
	</div>
</body>
</html>
<?php
	}
	else
	{
		$_SESSION['loggued_on_user'] = '';
		exit("ERREUR\n");
	}
}
else
	exit("ERROR\n");
?>
