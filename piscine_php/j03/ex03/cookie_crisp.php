<?php
$action = ($_GET['action'] == null ) ? null : $_GET['action'];
$name = ($_GET['name'] == null ) ? null : $_GET['name'];
$value = ($_GET['value'] == null ) ? null : $_GET['value'];

if ($action === "set" && $name != null)
{
	if (!setcookie( $name, $value, time() + 3600))
		echo "Failed to create cookie";
}
elseif ($action === "get" && $name != null && $_COOKIE[$name])
{
	echo $_COOKIE[$name]."\n";
}
elseif ($action === "del" && $name != null)
{
	setcookie($name);
}
?>
