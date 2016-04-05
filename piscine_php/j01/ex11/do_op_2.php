#!/usr/bin/php
<?php
function do_op($a, $op, $b)
{
	if ($op == "+")
	return $a + $b;
	elseif ($op == "-")
	return $a - $b;
	elseif ($op == "/")
	return $a / $b;
	elseif ($op == "*")
	return $a * $b;
	elseif ($op == "%")
	return $a % $b;
	else
	return 0;
}

function ft_operator($str)
{
	if ((strcmp($str, "+") == 0) || (strcmp($str, "-") == 0)
	|| (strcmp($str, "*") == 0) || (strcmp($str, "%") == 0)
	|| (strcmp($str, "/") == 0))
		return ($str === "+"
		|| $str === "-"
		|| $str === "*"
		|| $str === "/"
		|| $str === "%");
	else
		return false;
}

$nb_argv = count($argv);
if ($nb_argv != 2)
{
	print "Incorrect Parameters\n";
	return 0;
}
$tmp = trim($argv[1], " \t");
$len = strlen($tmp);
$i = 0;
while (substr($tmp, $i, 1) === "-")
	$i++;
while ($i < $len && is_numeric($tmp_a .= substr($tmp, $i, 1)))
	$i++;
if ($i < 1 || $i == $len)
{
	print "Syntax Error\n";
	return 0;
}
while (ft_operator($tmp[$i]) == false)
	$i++;
if (ft_operator($op = substr($tmp, $i, 1)))
	$i++;
while (substr($tmp, $i, 1) === " ")
	$i++;
while ($i < $len && is_numeric($b .= substr($tmp, $i, 1)))
	$i++;
$i = 0;
$tmp_a = trim($tmp_a, " \t");
$len_a = strlen($tmp_a);
if ($tmp_a[$len_a] == $op || $tmp_a[$len_a - 1] == $op)
	$len_a--;
while ($i < $len_a)
{
	if ($tmp_a[$i] !== (ft_operator($op) != false))
		$a .= $tmp_a[$i];
	$i++;
}
$a = trim($a, " \t");
$b = trim($b, " \t");
if (is_numeric($a) && is_numeric($b))
	print do_op($a, $op, $b)."\n";
else
	print "Syntax Error\n";
?>
