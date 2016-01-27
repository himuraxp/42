#!/usr/bin/php
<?php
	$elem = $argv[1];
	$elem = preg_replace("/\s+/", " ", $elem);
	$elem = trim($elem);
	if ($elem)
		echo $elem."\n";
?>
