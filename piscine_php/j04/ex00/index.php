<?php
session_start();
if (isset($_GET['login']) && isset($_GET['passwd'])
	&& ($_GET['submit'] == "OK"))
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html">
		<style>
			body {background: grey;}
			.form-signin {
				background: white;
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
				color: #333;
			}
			p { text-align: center; }
			input {
				width: 50%;
				color: #333;
				border-radius: 2px;
			}
			.button {
				color: white;
				background-color: green;
				border-color: green;
				font-weight: bolder;
				transition-duration: 0.4s;
			}
			.button:hover {
				background-color: cyan;
				border-color: cyan;
				color: #333;
				transition-duration: 0.4s;
			}
		</style>
	</head>
	<body>
		<div class="form-signin">
			<h1>42 Connect</h1>
			<form action="index.php" method="get">
				<p>Login : <input type="text" name="login"/></p>
				<p>Passw : <input type="password" name="passwd"/></p>
				<p><input class="button" type="submit" value="OK"></p>
			</form>
		</div>
	</body>
</html>
