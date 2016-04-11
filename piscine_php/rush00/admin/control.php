<div id="nav" class="nav-admin"></div>
	<div class="col-12">
		<div class="admin">
		<?php
			@session_start();
			if(isset($_SESSION['admin_state']) && $_SESSION['admin_state'] == 1 && isset($_SESSION['loggued_on_user']))
			{
				echo '<table>';
				echo '<tr>';
				echo '<td class="width-td"">';
				echo '<input style="height: 2vw;" class="button admin-button button-logout" id="user" value="Utilisateur" onclick="show_user_frame()" type="submit">';
				echo '</td>';
				echo '<td class="width-td">';
				echo '<input style="height: 2vw;" class="button admin-button button-logout" id="prod" value="Produit" onclick="show_produit_frame()" type="submit">';
				echo '</td>';
				echo '<td class="width-td">';
				echo '<input style="height: 2vw;" class="button admin-button button-logout" id="prod" value="Commandes" onclick="show_commande_frame()" type="submit">';
				echo '</td>';
				echo '<td class="width-td">';
				echo '<input style="height: 2vw;" class="button admin-button button-logout" id="cat" value="Catégories" onclick="show_cat_frame()" type="submit">';
				echo '</td>';
				echo '</tr>';
				echo '<tr>';
				echo '<td class="table" colspan=8 valign="top">';
				echo '<div class="wrap_admin" id="display_admin_zone"></div>';
				echo '</td>';
				echo '</tr>';
				echo '</table>';
			}
		?>
		</div>
	</div>
</div>
