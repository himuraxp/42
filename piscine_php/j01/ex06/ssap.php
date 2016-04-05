#!/usr/bin/php
<?php
$result = "";
array_shift($argv);
foreach($argv as $elem)
{
	$result .= $elem." ";
}
$result = trim($result);
$result = explode(' ', $result);
$result = array_filter($result, 'strlen');
sort($result);
print_r($result);
?>
