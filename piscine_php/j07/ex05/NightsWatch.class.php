<?php
class NightsWatch implements IFighter {
	public function fight() {}
	public function recruit( $att ) {
		$class = get_class( $att );
		if ( $class == "JonSnow" )
			JonSnow::fight();
		if ( $class == "SamwellTarly" )
			SamwellTarly::fight();
	}
}
?>
