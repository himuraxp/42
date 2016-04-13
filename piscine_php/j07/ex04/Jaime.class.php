<?php
class Jaime {
	public function sleepWith( $att ) {
		$class = get_class( $att );
		if ( $class == "Tyrion" )
			print( "Not even if I'm drunk !" . PHP_EOL );
		if ( $class == "Sansa" )
			print( "Let's do this." . PHP_EOL );
		if ( $class == "Cersei" )
			print( "With pleasure, but only in a tower in Winterfell, then." . PHP_EOL );
	}
}
?>
