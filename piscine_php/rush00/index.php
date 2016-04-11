<?php
	session_start();
	$username = "";
	$deconnection = "";
	$admin_button = "";
	$admin_script = "";
	$action_script = "";
	function make_select($option, $name)
	{
		$file = unserialize(file_get_contents("./data/category"));
		$output = "<select id='".$name."' onchange='select_item()'>";
		foreach($file as $key => $value)
		{
			if ($option == $key)
				$output .= '<option selected>'.$key.'</option>';
			else
				$output .= '<option>'.$key.'</option>';
		}
		$output .= "</select>";
		return $output;
	}
	
	if (isset($_SESSION['loggued_on_user']))
		$tmp = "";
	else
	{
		$_SESSION['loggued_on_user'] = "";
		$_SESSION['panier'] = array();
	}
	if ($_SESSION['loggued_on_user'] != "")
	{
		$username = $_SESSION['loggued_on_user'];
		if ($_SESSION['admin_state'] == 1)
		{
			$admin_button = '<input class="button button-logout" id="admn" type="submit" value="Admin" onclick="show_admin_frame()">';
			$admin_script = '<script src="./js/admin.js" type="text/javascript" media="javascript"></script>';
			$action_script = "load_admin()";
		}
		$deconnection = '<input class="button button-logout" type="submit" value="Déconnection" onclick="log_out()">';
		$action_compte = "<input class='button button-logout' id='account' type='submit' value='Mon compte' onclick=\"display_pop_up('account')\">";
	}
	else
		$action_compte = "<input class='button button-logout' id='account' type='submit' value='Mon compte' onclick=\"display_pop_up('login')\">";

?>

<html>
<head>
	<meta http-equiv="Content-Type" content="text/html">
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link href="css/style.css" rel="stylesheet">
	<link href="css/admin.css" rel="stylesheet">
	<link href="css/menu.css" rel="stylesheet">
	<script src="./js/refresh.js" type="text/javascript" media="javascript"></script>
	<?php echo $admin_script?>
</head>
<body onload="load_boutique(); <?php echo $action_script?>">
	<div class="bg" id="bg"><div class="magic_pop_up" id="display_pop_up_zone"></div></div>
		<div class="message" id="message"></div>
			<div class="container">
				<div class="header" id="header">
					<div class="col-2">
					</div>
					<div class="col-8-norm">
						<p>
							<?php echo $action_compte?>
							<?php echo $admin_button?>
							<?php echo $deconnection?>
							<img class="logo" src="./img/logo.png" onclick="shwo_order()"/>
						</p>
					</div>
				</div>
			</div>
		</div>
		<div class="row">
			<div id="nav" class="nav"></div>
				<ul id="menu">
					<li><a href="#"><strong>FILTRE</strong></a>
						<ul>
							<li>
								<?php echo make_select("", "cat1")?>
							</li>
							<li>
								<?php echo make_select("", "cat2")?>
							</li>
						</ul>
					</li>
				</ul>
			</div>
		</div>
		<div class="row">
			<div class="col-2">
			</div>
			<div class="col-8">
				<div class="boutique" id="print_boutique"></div>
			</div>
		</div>
	</div>
</div>
</body>
</html>
