<?php
	session_start();
	
	function make_select($option)
	{
		$file = unserialize(file_get_contents("../data/category"));
		$output = "<select id='cat'>";
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
	
	if(isset($_SESSION['admin_state']) && $_SESSION['admin_state'] == 1 && isset($_SESSION['loggued_on_user']))
	{
		$file = unserialize(file_get_contents("../data/produit"));
		$update_bdd = array();
		echo "<table align=center valign=top>";
		echo '<tr class="title-tr"><td><h1>ID</h1></td><td><h1>NOM</h1></td><td colspan=2><h1>CATEGORIES</h1></td><td><h1>PRIX</h1></td><td><h1>REDUCTION</h1></td><td><h1>STOCK</h1></td></tr>';
		$i = 0;
		foreach($file as $key => $value)
		{
			$i = intval($value['idProduit']);
			if (isset($_POST['id']) && isset($_POST['nom']) && isset($_POST['cat']) && isset($_POST['prix']) && isset($_POST['red']) && isset($_POST['stock']) && $value['idProduit'] == $_POST['id'])
			{
				$value['nom'] = $_POST['nom'];
				$value['cat'] = array($_POST['cat'],$_POST['cat1']);
				$value['prix'] = $_POST['prix'];
				$value['reduction'] = $_POST['red'];
				$value['stock'] = $_POST['stock'];
			}
			
			if (isset($_POST['del']) && $value['idProduit'] == $_POST['id'])
			{
				$tmp = "";
			}
			else
			{
				$update_bdd[] = $value;
				echo '<tr><td class="title-tr">'.$value['idProduit'].'</td>';
				echo '<td class="anti"><input class="inp-admin" id="nom" type="text" value="'.$value['nom'].'"></td>';
				echo '<td class="anti">'.make_select($value['cat'][0]).'</td>';
				echo '<td class="anti">'.make_select($value['cat'][1]).'</td>';
				echo '<td class="anti"><input class="inp-admin" id="prix" type="text" value="'.$value['prix'].'"></td>';
				echo '<td class="anti"><input class="inp-admin" id="red" type="text" value="'.$value['reduction'].'"></td>';
				echo '<td class="anti"><input class="inp-admin" id="stock" type="text" value="'.$value['stock'].'"></td>';
				echo '<td class="anti"><input class="button" type="submit" value="Save" onclick="save_this_obj(this)"></td>';
				echo '<td class="anti"><input class="button" type="submit" value="Delete      " onclick="del_this_obj(this)"></td></tr>';
			}
		}
		$i++;
		if (isset($_POST['add']) && $_POST['nom'] != "" && $_POST['cat'] != "" && $_POST['prix'] != "" && $_POST['red'] != "" && $_POST['stock'] != "")
		{
			$update_bdd[] = array('idProduit' => $i,'nom' => $_POST['nom'],'cat' => $_POST['cat'],'prix' => $_POST['prix'],'reduction' => $_POST['red'],'stock' => $_POST['stock']);
			echo '<tr><td class="title-tr">'.$i.'</td>';
			echo '<td class="anti"><input class="inp-admin" id="nom" type="text" value="'.$_POST['nom'].'"></td>';
			echo '<td class="anti">'.make_select($_POST['cat'][0]).'</td>';
			echo '<td class="anti">'.make_select($_POST['cat'][1]).'</td>';
			echo '<td class="anti"><input class="inp-admin" id="prix" type="text" value="'.$_POST['prix'].'"></td>';
			echo '<td class="anti"><input class="inp-admin" id="red" type="text" value="'.$_POST['red'].'"></td>';
			echo '<td class="anti"><input class="inp-admin" id="stock" type="text" value="'.$_POST['stock'].'"></td>';
			echo '<td class="anti"><input class="button" type="submit" value="Save" onclick="save_this_obj(this)"></td>';
			echo '<td class="anti"><input class="button" type="submit" value="Delete      " onclick="del_this_obj(this)"></td></tr>';
			$i++;
		}
		echo '<tr class="title-tr"><td>'.$i.'</td>';
		echo '<td><input class="inp-admin" id="nom" type="text" value=""></td>';
		echo '<td>'.make_select("").'</td>';
		echo '<td>'.make_select("").'</td>';
		echo '<td><input class="inp-admin" id="prix" type="text" value=""></td>';
		echo '<td><input class="inp-admin" id="red" type="text" value=""></td>';
		echo '<td><input class="inp-admin" id="stock" type="text" value=""></td>';
		echo '<td><input type="submit" class="button" value="Add    " onclick="add_this_obj(this)"></td></tr>';
		if (isset($_POST['id']) && isset($_POST['nom']) && isset($_POST['cat']) && isset($_POST['prix']) && isset($_POST['red']) && isset($_POST['stock']))
		{
			file_put_contents("../data/produit", serialize($update_bdd));
		}
		echo "</table>";
	}
?>