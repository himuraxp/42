<?php
Class Exemple {

	public $foo = 0;

	function __construct() {
		print( 'Constructor called' . PHP_EOL );
		return;
	}

	function __destruct() {
		print( 'Destructor called' . PHP_EOL );
		return;
	}

	function bar() {
		print( 'Method bar called' . PHP_EOL );
		return;
	}
}

$instance = new Exemple();

print( '$instance->foo: ' . $instance->fou . PHP_EOL );
$instance->fou = 42;
print( '$instance->foo: ' . $instance->fou . PHP_EOL );

$instance->bar();
?>
