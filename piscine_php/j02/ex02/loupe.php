#!/usr/bin/php
<?php

if ($argv[1])
{
	$str = file_get_contents($argv[1]);
	$tab = explode("<a", $str);
	$count = 1;
	while ($count < count($tab))
	{
		$parse = explode("\"", $tab[$count]);
		$i = 1;
		while ($i < count($parse) - 1)
		{
			$parse[$i] = strtoupper($parse[$i]);
			$i++;
		}
		$tab[$count] = implode("\"", $parse);
		$parse = explode(">", $tab[$count]);
		$i = 1;
		while ($i < count($parse) - 1)
		{
			$end = explode("<", $parse[$i]);
			$end[0] = strtoupper($end[0]);
			$parse[$i] = implode("<", $end);
			$i++;
		}
		$tab[$count] = implode(">", $parse);
		$count++;
	}
	$str = implode("<a", $tab);
	echo "$str\n";
}
?>
