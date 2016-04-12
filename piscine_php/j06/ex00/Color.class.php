<?php

class Color($reb, $green, $blue) {
	$color = array($red, $green, $blue);
	function __construct($color) {
		print_r($color);
		echo "constructeur\n";
		return;
	}
	function __destruct() {
		echo "destructeur\n";
		return;
	}
}

$instance = new Color(255, 255, 255);
?>
