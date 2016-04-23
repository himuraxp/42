<?php
	session_start();
	
	function ft_split($str, $av)
	{
		$ary = explode($av, $str);
		$output = array();
		$i = 0;
		$j = 0;
		while (isset($ary[$i]))
		{
			if ($ary[$i] != "")
			{
				$output[$j] = $ary[$i];
				$j++;
			}
			$i++;
		}
		sort($output);
		return $output;
	}
	if (file_exists("../data/produit") == 1 && file_exists("../data/user") == 1)
	{
		$i = 0;
		foreach($_POST as $key => $value)
		{
			if (($key == "login" && $value != "") || ($key == "passwd" && $value != ""))
				$i++;
		}
		$account_list = array();
		$is_set = false;
		if (file_exists("../data") == false)
		{
			mkdir("../data", 0777, true);
		}
		if (file_exists("../data/user") == false)
			file_put_contents("../data/user", serialize($account_list));
		$file = file_get_contents("../data/user");
		$account_list = unserialize($file);
		$key_tmp = 0;
		foreach($account_list as $key => $value)
		{
			$key_tmp = $key;
			if ($value["login"] == $_POST["login"])
				$is_set = true;
		}
		if ($is_set == false && $_POST["login"] != "" && $_POST["passwd"] != "")
		{
			$account_list[$key_tmp + 1]["login"] = $_POST["login"];
			$hash_tmp = hash("whirlpool", "salutlavache");
			$account_list[$key_tmp + 1]["passwd"] = hash("whirlpool", $hash_tmp.$_POST["passwd"]);
			$account_list[$key_tmp + 1]["type"] = 0;
			file_put_contents("../data/user", serialize($account_list));
		}
		if ($i == 2 && $is_set == false)
		{
			echo "OK;<div class='console'>Compte enregistré</p>";  
		}
		else
		{
			if ($is_set == true)
				echo "ERROR;<div class='console'>Cet identifiant existe déjà</div>";
			else if($_POST["login"] == "" && $_POST["passwd"] == "")
				echo "ERROR;<div class='console'>Identifiant et Mot de passe vide !!!</div>";
			else if($_POST["login"] == "")
				echo "ERROR;<div class='console'>Identifiant vide !!!</div>";
			else if($_POST["passwd"] == "")
				echo "ERROR;<div class='console'>Mot de passe vide !!!</div>";
		}
	}
	else
		echo "ERROR;<div class='console'>Base de donné dur non initialisé !!!</div>";
?>