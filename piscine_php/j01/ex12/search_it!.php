#!/usr/bin/php
<?
if ($argv[2])
{
	$buf = $argv;
	foreach ($buf as $value)
	{
		if ($value == $buf[0] || $value == $buf[1])
			continue ;
		$elem = explode(":", $value);
		if (count($elem) > 2)
			$key[$elem[0]] = substr($value, strlen($elem[0]) + 1);
		else
			$key[$elem[0]] = $elem[1];
	}
	if ($key[$argv[1]])
		echo $key[$argv[1]]."\n";
}
?>
