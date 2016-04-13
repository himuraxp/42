<?php
Class Exemple {

	private $_att = 0;

	public function getAtt() { return $this->_att; }

	public function setAtt( $v ) {
		if ( $this->_att + $v > 50 )
			$this->_att = 50;
		else
				$this->_att = $v;
		return;
	}

	public function __get($att) {
		print( 'Attempt to access \'' . $att . '\' attribute, this script should die' . PHP_EOL );
		return 'Pas terrible !';
	}

	public function __set($att, $value) {
		print( 'Attempt to set \'' . $att . '\' attribute to \'' . $value . '\' this script should die' . PHP_EOL );
		return;
	}

	public function __construct( array $kwargs ) {
		print( 'Constructor called' . PHP_EOL );
		$this->setAtt( $kwargs['arg'] );
		print( '$this->getAtt: ' . $this->getAtt() . PHP_EOL );
		return;
	}

	public function __destruct() {
		print( 'Destructor called' . PHP_EOL );
		return;
	}

}

$instance1 = new Exemple( array( 'arg' => 42 ));

print( '$instance1->$foo: ' . $instance1->foo . PHP_EOL );
print( '$instance1->$_att: ' . $instance1->_att . PHP_EOL );
$instance1->foo = 21;
$instance1->_att = 84;
?>
