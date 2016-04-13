<?php
Class Exemple {

	private $_att = 0;

	public function getAtt() { return $this->_att; }
	public function setAtt( $value ) { $this->_att = $value; return; }

	public function __construct( array $kwargs ) {
		print( 'Constructor called' . PHP_EOL );
		$this->setAtt( $kwargs['arg'] );
		return;
	}

	public function __destruct() {
		print( 'Destructor called' . PHP_EOL );
		return;
	}

	public function __toString() {
		return 'Exemple ( $_att = '. $this->getAtt() . ' )';
	}

}

$instance1 = new Exemple( array( 'arg' => 42 ));
print( $instance1 . PHP_EOL );
?>
