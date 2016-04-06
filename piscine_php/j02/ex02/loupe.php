#!/usr/bin/php
<?php

if ($argv[1])
	$tmp = fopen($argv[1], "r");
	$tmp = preg_match("/title=/", $tmp);
	echo = $tmp;
?>
