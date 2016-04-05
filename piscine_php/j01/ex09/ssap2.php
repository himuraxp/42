#!/usr/bin/php
<?php
function ft_isalpha($c){
	if (($c >= 'a' && $c <= 'z') || ($c >= 'A' && $c <= 'Z'))
		return (1);
	return (0);
}
function compare($c1, $c2){
	if (ft_isalpha($c1))
	{
		if (ft_isalpha($c2))
			return (strcmp(strtolower($c1),strtolower($c2)));
		else
			return (-1);
	}
	if (ft_isalpha($c2))
		return (1);
	if (is_numeric($c1))
	{
		if (is_numeric($c2))
			return (strcmp($c1,$c2));
		else
			return (-1);
	}
	if (is_numeric($c2))
		return (1);
	return (strcmp($c1,$c2));
}
$result = "";
array_shift($argv);
foreach($argv as  $elem)
{
	$result .= $elem." ";
}
$result = trim($result);
$result = explode(' ', $result);
$result = array_filter($result, 'strlen');
$tmp = $result;
$i = 0;
while ($result[$i + 1])
{
	$r = 0;
	$j = 0;
	$size = strlen($result[$i]) < strlen($result[$i + 1]) ? strlen($result[$i]) : strlen($result[$i + 1]);
	while ($j <= $size)
	{
		if (($r = compare($result[$i][$j], $result[$i + 1][$j])) == 0)
			$j++;
		else
		{
			if ($r > 0)
			{
				$temp = $result[$i];
				$result[$i] = $result[$i + 1];
				$result[$i + 1] = $temp;
				$i = -1;
				break ;
			}
			if ($r < 0)
				break ;
		}
	}
	$i++;
}
foreach($result as  $elem)
{
	echo $elem."\n";
}
?>
