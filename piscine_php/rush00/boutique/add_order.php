<?php
	session_start();
	if (isset($_SESSION['loggued_on_user']) && isset($_SESSION['panier']) && isset($_POST['id']))
	{
		$is_add = false;
		$new_panier = array();
		foreach($_SESSION['panier'] as $key => $value)
		{
			if ($key == $_POST['id'])
			{
				$value++;
				$is_add = true;
			}
			$new_panier[$key] = $value;
		}
		$_SESSION['panier'] = $new_panier;
		if ($is_add == false)
		{
			$_SESSION['panier'][$_POST['id']] = 1;
		}
	}
?>