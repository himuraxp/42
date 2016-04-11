<div class="form-signin panier">
	<div class="row">
		<a onclick="hide_pop_up()" class="close"></a>
	</div>
		<h1>Panier<br></h1>
		<div class="content-panier">
		<?php
			@session_start();
			$panier = "";
			$result = 0.00;
			if (isset($_SESSION['loggued_on_user']) && isset($_SESSION['panier']))
			{
				if (file_exists("../data/produit") == true)
				{
					$file = file_get_contents("../data/produit");
					$product_list = unserialize($file);
					foreach($product_list as $key1 => $value1)
					{
						foreach($_SESSION['panier'] as $key2 => $value2)
						{
							if ($value1['idProduit'] == $key2)
							{
								echo '<div>';
								echo '<img class="img_panier" src="data:image/png;base64,'.$value1['img_1'].'" class="images">';
								echo '<p><strong> '.$value1['nom'].' </strong><i class="descrip">'.$value1['cat'].'</i><br><strong class="prix">'.$value2.' x '.$value1['prix'].'€</strong></p>';								
								echo '</div>';
								$result += $value1['prix'] * $value2;
							}
						}
					}
				}
			}
		?>	
		<p><?php echo $panier?></p>
		</div>
		<h1>Total : <?php echo $result?> €<br></h1>
		<?php if ($result !== 0.00) 
		{ 			
			echo '<p><input class="button" type="submit" name="submit" value="Acheter" onclick="buy_order()"></p>';
		}
		?>
</div>
