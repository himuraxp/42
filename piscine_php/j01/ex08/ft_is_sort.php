<?php
function ft_is_sort($tab)
{
	$buf = $tab;
	sort($buf);
	foreach($buf as $key => $elem)
	{
		if ($elem != $tab[$key])
			return 0;
	}
	return 1;
}
?>
