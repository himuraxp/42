<?php

class Color {
	function __construct(array $kwargs) {
		if (array_key_exists('red', $kwargs))
			$this->red = $kwargs['red'];
		else
			$this->red = 0;
		if (array_key_exists('green', $kwargs))
			$this->green = $kwargs['green'];
		else
			$this->green = 0;
		if (array_key_exists('blue', $kwargs))
			$this->blue = $kwargs['blue'];
		else
			$this->blue = 0;
		print("red = ".$this->red."\ngreen = ".$this->green."\nblue = ".$this->blue."\n");
		return;
	}
	function __destruct() {
		echo "destructeur\n";
		return;
	}
}

$instance = new Color(array('red' => 255, 'green' => 255, 'blue' => 255));
?>
