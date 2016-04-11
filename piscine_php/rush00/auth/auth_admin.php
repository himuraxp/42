<?php
	function auth_admin($login, $passwd)
	{
		$account_list = array();
		$is_set = false;
		if (file_exists("../data") == false)
		{
			mkdir("../data", 0777, true);
		}
		$file = file_get_contents("../data/user");
		if ($file != "")
		{
			$account_list = unserialize($file);
			foreach($account_list as $key => $value)
			{
				if ($value["login"] == $login && $value["passwd"] == hash("whirlpool", hash("whirlpool", "salutlavache").$passwd) && $value["type"] == 1)
					$is_set = true;
			}
		}
		if ($is_set == true && $login != "Visiteur")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
?>