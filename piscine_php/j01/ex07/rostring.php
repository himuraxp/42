#!/usr/bin/php
<?php
$temp= "";
$result = explode(' ', $argv[1]);
$result = array_filter($result, 'strlen');
$temp = array_shift($result);
$result = implode(' ', $result);
print($result);
echo " ".$temp."\n";
?>
