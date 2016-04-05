#!/usr/bin/php
<?php
	function do_op($a, $op, $b)
	{
		$op = trim($op, " \t");
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

	$nb_argv = count($argv);
	if ($nb_argv != 4)
	{
		print "Incorrect Parameters";
		return 0;
	}
	print do_op($argv[1], $argv[2], $argv[3]);
?>
