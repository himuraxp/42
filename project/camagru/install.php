<meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
<script type="text/javascript">
	function redirect_page()
	{
		$pass = window.location.href.substr(0, window.location.href.length - 11);
		setTimeout(function(){
			window.location=$pass + "index.php";
		}, 2000)
	}
</script>

<?php
	function echo_install_fram($state)
	{
		echo '<html>';
		echo '<head>';
		echo '<meta http-equiv="Content-Type" content="text/html">';
		echo '<meta charset="UTF-8">';
		echo '<meta name="viewport" content="width=device-width, initial-scale=1">';
		echo '<link href="css/style.css" rel="stylesheet">';
		echo '</head>';
		echo '<body onload="redirect_page();">';
		echo '<div class="form-signin">';
		echo '<div class="row">';
		echo '<a class="close"></a>';
		echo '</div>';
		echo '<h1>42 Boutique<br></h1>';
		if ($state == true)
		{
			echo '<p id="redirect_index">Installation Réussie</p>';
		}
		else
		{
			echo '<p>Echec Installation</p>';
			echo '<p>Base de donné déjà presente</p>';
		}
		echo '</div>';
		echo '</div>';
		echo '</body>';
		echo '</html>';
	}

	if (isset($_POST['install']) && $_POST['install'] == 'OK' && isset($_POST['login']) && $_POST['login'] != '' && isset($_POST['passwd']) && $_POST['passwd'] != '' && file_exists("./data/produit") != 1)
	{
		if (file_exists("./data") == false)
		{
			mkdir("./data", 0777, true);
		}
		$produit = array();
		if (file_exists("./data/produit") == false)
			file_put_contents("./data/produit", serialize($produit));
		$file = file_get_contents("./data/produit");
		$link = mysql_connect("localhost", "userterroir", "tRcDlB")
	    	or die("Impossible de se connecter : " . mysql_error());
		mysql_select_db("terroir");
		$result = mysql_query("SELECT P.idProduit, nomproduit, P.categories, P.info, P.prix, P.reduction, P.stock, P.notemoyenne, I.image_1_valid FROM Produits P, ImagesProduit I WHERE P.idProduit = I.idproduit AND P.idclient=31 ORDER BY P.idProduit ASC");
		$category = array();
		$category['all'] = "";
		while ($row = mysql_fetch_array($result))
		{
			if ($row['image_1_valid'] != "")
			{
				$produit[] = array(
					"idProduit" => $row['idProduit'],
					"nom" => mb_convert_encoding($row['nomproduit'], 'utf-8', 'iso-8859-1'),
					"cat" => array($row['categories'], 'all'),
					"info" => $row['info'],
					"prix" => $row['prix'],
					"reduction" => $row['reduction'],
					"stock" => $row['stock'],
					"n_moy" => $row['notemoyenne'],
					"img_1" => $row['image_1_valid']
				);
				$category[$row['categories']] = "";
			}
		}
		file_put_contents("./data/category", serialize($category));
		$account_list = array();
		$is_set = false;
		if (file_exists("./data/user") != 1)
		{
			$is_set2 = true;
			file_put_contents("./data/user", serialize($account_list));
		}
		else
			$is_set2 = false;
		$key_tmp = 0;
		foreach($account_list as $key => $value)
		{
			$key_tmp = $key;
			if ($value["login"] == $_POST["login"])
				$is_set = true;
		}
		if ($is_set == false && $is_set2 == true && $_POST["login"] != "" && $_POST["passwd"] != "")
		{
			$account_list[$key_tmp + 1]["login"] = $_POST["login"];
			$hash_tmp = hash("whirlpool", "salutlavache");
			$account_list[$key_tmp + 1]["passwd"] = hash("whirlpool", $hash_tmp.$_POST["passwd"]);
			$account_list[$key_tmp + 1]["type"] = 1;
			file_put_contents("./data/user", serialize($account_list));
		}
		file_put_contents("./data/produit", serialize($produit));
		mysql_close($link);
		echo_install_fram($is_set2);
	}
	else
	{
		if (file_exists("./data/produit") == 1 || file_exists("./data/user") == 1)
		{
			echo_install_fram(false);
		}
		else
		{
			echo '<html>';
			echo '<head>';
			echo '<meta http-equiv="Content-Type" content="text/html">';
			echo '<meta charset="UTF-8">';
			echo '<meta name="viewport" content="width=device-width, initial-scale=1">';
			echo '<link href="css/style.css" rel="stylesheet">';
			echo '</head>';
			echo '<body>';
			echo '<div class="form-signin">';
			echo '<div class="row">';
			if (isset($_POST['install']) && $_POST['install'] == 'OK')
				echo '<a class="close"><i>Erreur</i></a>';
			else
				echo '<a class="close"></a>';
			echo '</div>';
			echo '<h1>42 Boutique<br>Installation</h1>';
			echo '<form action="install.php" method="post">';
			echo '<p><i>Identifiant (admin)</i><input name="login" id="login" type="text"></p>';
			echo '<p><i>Mot de passe</i><input name="passwd" id="passwd" type="password"></p>';
			echo '<p><input class="button" name="install" value="OK" type="submit"></p>';
			echo '</form>';
			echo '</div>';
			echo '</div>';
			echo '</body>';
			echo '</html>';
		}
	}
?>