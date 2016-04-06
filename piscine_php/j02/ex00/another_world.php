#!/usr/bin/php
<?php

if ($argv[1])
{
	$tmp = $argv[1];
	$tmp = trim($tmp);
	$tmp = preg_replace("/\s+/", " ", $tmp);
	echo $tmp."\n";
}

?>
