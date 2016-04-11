<?php
	if (file_exists("../data/produit") == true)
	{
		$file = file_get_contents("../data/produit");
		$product_list = unserialize($file);
		$i = 0;
		echo "<table align=center>";
		$cat1 = "";
		$cat2 = "";
		if (isset($_POST['cat']) && isset($_POST['cat1']))
		{
			$cat1 = $_POST['cat'];
			$cat2 = $_POST['cat1'];
		}
		foreach($product_list as $key => $value)
		{
			if ($cat1 == $value['cat'][0] || $cat2 == $value['cat'][1])
			{
				if (isset($value['img_1']))
				$img = $value['img_1'];
				else
					$img = "";
				if ($i % 4 == 0)
					echo '<tr>';
				echo "<td>";
				echo '<div class="produit">';
				echo '<div class="row bg-head">';
				echo '<h1>'.$value['nom'].'</h1>';
				if ($value['cat'][1] == 'all' || $value['cat'][0] == $value['cat'][1])
					$categ = $value['cat'][0];
				else
					$categ = $value['cat'][0].', '.$value['cat'][1];
	
				echo '<p>'.$categ.'</p>';
				echo '</div>';
	//			echo '<p>'.$value['info'].'</p>';
	//			echo '<p>'.$value['reduction'].'</p>';
	//			echo '<p>'.$value['stock'].'</p>';
	//			echo '<p>'.$value['n_moy'].'</p>';
	//			echo '<p><i>'.$value['info'].'</i></p>';
				echo '<img src="data:image/png;base64,'.$img.'" class="images">';	
				echo '<p class="prix"><strong>'.$value['prix'].'€</strong></p>';
				echo '<p><input class="button" type="submit" name="submit" value="Ajouter au Panier" onclick="add_to_order(\''.$value['idProduit'].'\')"></p>';
				echo '</div>';
				echo "<td>";
				$i++;
				if ($i % 4 == 0)
					echo '</tr>';
			}
		}
	}
?>