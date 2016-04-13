<?php
Class Exemple {

	public static function doc() {
		return 'This is a sample class with no real purpose.';
	}

	public function __construct( array $kwargs ) {
		print( 'Constructor called' . PHP_EOL );
		return;
	}

	public function __destruct() {
		print( 'Destructor called' . PHP_EOL );
		return;
	}
}

print( 'Exemple doc: ' . Exemple::doc() . PHP_EOL);
?>
