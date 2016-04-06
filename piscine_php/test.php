#!/usr/bin/php
<?php
$nb = preg_match("/t[oi]t[oi]/", "titi");
echo "$nb\n";

$nom = "key";
$$nom = "val";
echo "$key\n";

$my_tab = array("zero", "un", "deux");
if (array_search("zero", $my_tab) !== false)
	echo "Found\n";
?>
