<?php
	session_start();
	if(isset($_SESSION['admin_state']) && $_SESSION['admin_state'] == 1 && isset($_SESSION['loggued_on_user']))
	{
		
		if (file_exists("../data/commandes") == 1)
		{
			$file_commandes = unserialize(file_get_contents("../data/commandes"));
			$file_produit = unserialize(file_get_contents("../data/produit"));
			$i = 0;
			$output = "";
			foreach($file_commandes as $key1 => $value1)
			{
			
				foreach($value1 as $key2 => $value2)
				{
					//echo $value2.' '.$key2;
					foreach($file_produit as $key3 => $value3)
					{
						if ($value3['idProduit'] == $key2)
						{
							$output .= '<tr><td class="anti">'.$value1['login'].'</td>';
							$output .= '<td class="anti">'.$value3['idProduit'].'</td>';
							$output .= '<td class="anti">'.$value3['nom'].'</td>';
							$output .= '<td class="anti">'.$value3['cat'].'</td>';
							$output .= '<td class="anti">'.$value3['prix'].'</td>';
							$output .= '<td class="anti" style="width: 200px;">'.date("Y-m-d H:i:s" ,$value1['date']).'</td>';
							$output .= '<td class="anti">'.$value2.'</td>';
							$output .= '<td><img class="img_panier img_commande" src="data:image/png;base64,'.$value3['img_1'].'" class="images"></td></tr>';
							$i++;
						}
					}
				}
				$output .= '<tr><td colspan=8 ><div class="border-commande"></div></td></tr>';
					
			}
			echo "<table align=center >";
			if ($i == 0)
				echo "<tr><td>Aucune commande disponible</td></tr>";
			else
				echo '<tr class="title-tr"><td><h1>USER</h1></td><td><h1>ID</h1></td><td><h1>NOM</h1></td><td><h1>CATERGORIES</h1></td><td><h1>PRIX</h1></td><td><h1>DATE</h1></td><td><h1>QUANTITE</h1></td></tr>'.$output;
			echo "</table>";
		}
		else
			echo "<table align=center valign=top><tr><td>Aucune commande disponible</td></tr></table>";
	}
?>