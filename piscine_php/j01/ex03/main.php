#!/usr/bin/php
<?php
	include("ft_split.php");
	echo "Entrez votre chaine: ";
	$fd = fopen("php://stdin", 'r');
	$buffer = fgets($fd);
	print_r(ft_split($buffer));
?>
