<?php
abstract class House {
	abstract public function getHouseName();
	abstract public function getHouseMotto();
	abstract public function getHouseSeat();
	public function introduce() {
		print( 'House ' . static::getHouseName() . ' of ' . static::getHouseSeat() . ' : "' . static::getHouseMotto() . '"' . PHP_EOL );
	}
}
?>
