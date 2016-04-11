<?php
	session_start();
	if(isset($_SESSION['admin_state']) && $_SESSION['admin_state'] == 1 && isset($_SESSION['loggued_on_user']))
	{
		$file = unserialize(file_get_contents("../data/category"));
		echo "<table align=center valign=top>";
		echo "<tr><td align=center colspan=3><h1>CATEGORIES</h1></td></tr>";
		$update_bdd = array();
		$i = 0;
		$old_cat = "";
		foreach($file as $key => $value)
		{
			if (isset($_POST["cat"]) && $_POST["cat"] != "" && isset($_POST["pos"]) && $_POST["pos"] == $i)
			{
				$old_cat = $key;
				$key = $_POST["cat"];
			}
			if (isset($_POST["del"]) && $_POST["pos"] == $i)
				$tmp = "";
			else
			{
				if ($key == "all")
				{
					echo '<tr><td><input type="text" value="'.$key.'" disabled=""></td>';
					echo '<td></td>';
					echo '<td></td></tr>';
				}
				else
				{
					echo '<tr><td><input type="text" value="'.$key.'"></td>';
					echo '<td><input class="button" type="submit" value="Save" onclick="save_this_cat(this,'.$i.')"></td>';
					echo '<td><input class="button" type="submit" value="Delete    " onclick="del_this_cat(this,'.$i.')"></td></tr>';
				}
				$update_bdd[$key] = "";
			}
			$i++;
		}
		if (isset($_POST["cat"]) && $_POST["cat"] != "" && isset($_POST["pos"]) && $_POST["pos"] == -1)
		{
			$update_bdd[$_POST["cat"]] = "";
			echo '<tr><td><input type="text" value="'.$_POST["cat"].'"></td>';
			echo '<td><input class="button" type="submit" value="Save" onclick="save_this_cat(this,'.$i.')"></td>';
			echo '<td><input class="button" type="submit" value="Delete    " onclick="del_this_cat(this,'.$i.')"></td></tr>';
		}
		echo '<tr><td><input type="text" value=""></td><td><input class="button" type="submit" value="Ajouter   " onclick="save_this_cat(this,-1)"></td></tr>';
		echo "</table>";
		if (isset($_POST["cat"]) && $_POST["cat"] != "" && isset($_POST["pos"]) && $_POST["pos"] >= -1)
		{
			file_put_contents("../data/category", serialize($update_bdd));
			$update_bdd = array();
			$file = unserialize(file_get_contents("../data/produit"));
			$update_bdd = array();
			foreach($file as $key => $value)
			{
				if ($value['cat'][0] == $old_cat)
					$value['cat'][0] = $_POST["cat"];
				if ($value['cat'][1] == $old_cat)
					$value['cat'][1] = $_POST["cat"];
				$update_bdd[] = $value;
			}
			file_put_contents("../data/produit", serialize($update_bdd));
		}
	}
?>