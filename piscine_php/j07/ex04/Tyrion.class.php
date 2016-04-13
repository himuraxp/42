<?php
class Tyrion {
	public function sleepWith( $att ) {
		$class = get_class( $att );
		if ( $class == "Jaime" || $class == "Cersei" )
			print( "Not even if I'm drunk !" . PHP_EOL );
		if ( $class == "Sansa" )
			print( "Let's do this." . PHP_EOL );
	}
}
?>
