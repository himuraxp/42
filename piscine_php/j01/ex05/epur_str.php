#!/usr/bin/php
<?php
$result = explode(' ', $argv[1]);
$result = array_filter($result, 'strlen');
$result = implode(' ', $result);
if ($argv[1] != NULL)
	print($result)."\n";
?>
