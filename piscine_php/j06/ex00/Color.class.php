<?php

class Color {

	public $red = 0;
	public $green = 0;
	public $blue = 0;
	public $rbg = 0;

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
		print($this->red."\n".$this->green."\n".$this->blue."\n");
		return;
	}
	function __destruct() {
		print( 'Destructeur called' . PHP_EOL );
		return;
	}
	public function __toString()
	{
		return $this->rgb;
	}
}

function hexa_rgb($hex) {
	$hex = str_replace("#", "", $hex);

if(strlen($hex) == 3) {
	$red = hexdec(substr($hex,0,1).substr($hex,0,1));
	$green = hexdec(substr($hex,1,1).substr($hex,1,1));
	$blue = hexdec(substr($hex,2,1).substr($hex,2,1));
} else {
	$red = hexdec(substr($hex,0,2));
	$green = hexdec(substr($hex,2,2));
	$blue = hexdec(substr($hex,4,2));
}
$rgb = array($red, $green, $blue);
return $rgb;
}
	$instance = new Color(array('red' => 168, 'green' => 15, 'blue' => 118));
	$rgb = hexa_rgb("FFF");
	$instance = new Color(array('red' => $rgb[0], 'green' => $rgb[1], 'blue' => $rgb[2]));
?>
