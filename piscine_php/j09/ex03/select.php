<?php
if (!file_exists("../private/"))
		if (!mkdir("../private"))
			$lol = "lol";
	if (file_exists("../private/todo"))
	{
		$tab = unserialize(file_get_contents("../private/todo"));
		$i = count($tab);
		while (--$i >= 0)
			echo '<div class="note" id="'.$i.'">'.htmlentities($tab[$i]).'</div>';
	}
?>
