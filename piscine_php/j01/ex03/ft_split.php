<?php
	function ft_split($input)
	{
		$input = preg_replace('/\s+/', ' ', $input);
		$input = trim($input);
		$tab = explode(' ', $input);
		sort($tab, SORT_STRING);
		return ($tab);
	}
?>
