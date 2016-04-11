<?php
	session_start();
	if(isset($_SESSION['admin_state']) && $_SESSION['admin_state'] == 1 && isset($_SESSION['loggued_on_user']))
	{
		$account_list = unserialize(file_get_contents("../data/user"));
		if (isset($_POST['login']) && isset($_POST['state']))
		{
			$new_list = array();
			$i = 0;
			foreach($account_list as $key => $value)
			{
				if ($value["type"] == 1)
					$i++;
				if ($value["login"] == $_POST["login"])
				{
					if ($_POST['state'] == 'true')
						$value["type"] = 1;
					else
						$value["type"] = 0;
				}
				$new_list[] = $value;
			}
			if ($i > 1 || $_POST['state'] == 'true')
				file_put_contents("../data/user", serialize($new_list));
		}
		else
		{
			if (isset($_POST['login']) && isset($_POST['delet']))
			{
				$new_list = array();
				$i = 0;
				foreach($account_list as $key => $value)
				{
					if ($value["login"] != $_POST["login"])
					{
						$new_list[] = $value;
						if ($value["type"] == 1)
							$i++;
					}
				}
				if ($i >= 1 || isset($_POST['delet']))
					file_put_contents("../data/user", serialize($new_list));
			}
			echo "<table align=center valign=top>";
			echo '<tr class="title-tr"><td><h1>User</h1></td><td><h1>Admin</h1></td><td><h1>Del</h1></td></tr>';
			foreach($account_list as $key => $value)
			{
				if ($value['type'] == 1)
				{
					echo '<tr class="title-tr"><td class="anti">'.$value['login'].'</td><td><input type="checkbox" checked="true" onchange="update_state_user(\''.$value['login'].'\', this)"></td><td onclick="admin_delet_user(\''.$value['login'].'\')">X</td></tr>';
				}
				else
				{
					echo '<tr class="title-tr"><td class="anti">'.$value['login'].'</td><td><input type="checkbox" onchange="update_state_user(\''.$value['login'].'\', this)"></td><td onclick="admin_delet_user(\''.$value['login'].'\')"><img class="trash" src="./img/trash.svg"/></td></tr>';
				}
			}
			echo "</table>";
		}
	}
?>