
<?php
class Vector
{
	private $_x = 0.0;
	private $_y = 0.0;
	private $_z = 0.0;
	private $_w = 0.0;

	public static $verbose = False;
	function doc() { return ( file_get_contents("./Vector.doc.txt" )); }
	function getX() { return ( $this->_x ); }
	function getY() { return ( $this->_y ); }
	function getZ() { return ( $this->_z ); }
	function getW() { return ( $this->_w ); }

	function magnitude() {
		return ( sqrt( pow( $this->getX(), 2 ) + pow( $this->getY(), 2 ) + pow( $this->getZ(), 2 )));
	}

	function normalize() {
		$mag = $this->magnitude();

		if ( $mag == 1 ) {
			$array['x'] = $this->getX();
			$array['y'] = $this->getY();
			$array['z'] = $this->getZ();
			$array['w'] = $this->getW();
			return ( new Vector(array('dest' => $array )));
		}

		$x = $this->getX() / $mag;
		$y = $this->getY() / $mag;
		$z = $this->getZ() / $mag;
		$array['x'] = $x;
		$array['y'] = $y;
		$array['z'] = $z;
		$array['w'] = 0;
		return ( new Vector( array( 'dest'=> $array )));
	}
	function add( $rhs ) {
		$array = get_object_vars( $rhs );
		return ( new Vector( array( 'orig' => $this, 'dest' => $array )));
	}

	function sub( $rhs ) {
		$array = get_object_vars( $rhs );

		if ( $array['_x'] < 0 )
			$new['x'] = ( abs( $array['_x'] ) - abs( $this->getX() ));
		if ( $array['_x'] > 0 )
			$new['x'] = -( abs( $array['_x'] ) - abs( $this->getX() ));
		if ( $array['_y'] < 0 )
			$new['y'] = ( abs( $array['_y'] ) - abs( $this->getY() ));
		if ( $array['_y'] > 0 )
			$new['y'] = -( abs( $array['_y'] ) - abs( $this->getY() ));
		if ( $array['_z'] < 0 )
			$new['z'] = ( abs( $array['_z'] ) - abs( $this->getZ() ));
		if ( $array['_z'] > 0 )
			$new['z'] = -( abs( $array['_z'] ) - abs( $this->getZ() ));

		$new['w'] = 0;
		return ( new Vector( array('dest' => $new) ));
	}

	function opposite() {
		if ( $this->getX() < 0 )
			$array['x'] = abs( $this->getX() );
		if ( $this->getX() > 0 )
			$array['x'] = -( $this->getX() );
		if ( $this->getY() < 0 )
			$array['y'] = abs( $this->getY() );
		if ( $this->getY() > 0 )
			$array['y'] = -( $this->getY() );
		if ($this->getZ() < 0 )
			$array['z'] = abs( $this->getZ() );
		if ( $this->getZ() > 0 )
			$array['z'] = -( $this->getZ() );

		$array['w'] = 0;
		return ( new Vector( array( 'dest' => $array )));
	}
	function scalarProduct( $scal ) {
		$array['x'] = ( $this->getX() * $scal );
		$array['y'] = ( $this->getY() * $scal );
		$array['z'] = ( $this->getZ() * $scal );
		$array['w'] = 0;
		return (new Vector(array('dest' => $array)));
	}

	function dotProduct( $rhs ) {
		$array = get_object_vars( $rhs );
		$x = ( $this->getX() * $array['_x'] );
		$y = ( $this->getY() * $array['_y'] );
		$z = ( $this->getZ() * $array['_z'] );
		return ( $x + $y + $z );
	}

	function cos( $rhs ) {
		$array = get_object_vars( $rhs );
		$cos = ( $this->dotProduct( $rhs ) / sqrt(( pow( $this->getX(),2 ) + pow( $this->getY(),2 ) + pow( $this->getZ(),2 )) * ( pow( $array['_x'],2 ) + pow( $array['_y'],2 ) + pow( $array['_z'],2 ))));
		return ( $cos );
	}

	function crossProduct( $rhs ) {
		$array = get_object_vars( $rhs );
		$yz = $this->getY() * $array['_z'];
		$zy = $this->getZ() * $array['_y'];
		$zx = $this->getZ() * $array['_x'];
		$xz = $this->getX() * $array['_z'];
		$xy = $this->getX() * $array['_y'];
		$yx = $this->getY() * $array['_x'];
		$new['x'] = $yz - $zy;
		$new['y'] = $zx - $xz;
		$new['z'] = $xy - $yx;
		$new['w'] = 0;
		return ( new Vector( array( 'dest' => $new )));
	}

	function __construct ( array $kwargs ) {
		if ( $kwargs['orig'] === null )
			$kwargs['orig'] = new Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 0.0, 'w' => 1.0 ));
		else {
			$orig = (array)($kwargs['orig']);
			$i = 0;
			foreach ($orig as $key => $value ) {
				$array[$i] = $value;
				$i++;
			}
			$orig_x = $array[0];
			$orig_y = $array[1];
			$orig_z = $array[2];
			$orig_w = $array[3];
		}

		$dest = (array)($kwargs['dest']);
		$i = 0;

		foreach ( $dest as $key => $value ) {
			$array[$i] = $value ;
			$i++;
		}

		$dest_x = $array[0];
		$dest_y = $array[1];
		$dest_z = $array[2];
		$dest_w = $array[3];

		if ( $dest_x > 0 )
			$this->_x = ( abs( $orig_x ) + abs( $dest_x ));
		else if ($dest_x < 0)
			$this->_x = -( abs( $orig_x ) + abs( $dest_x ));
		if ( $dest_y > 0 )
			$this->_y = ( abs( $orig_y ) + abs( $dest_y ));
		else if ( $dest_y < 0 )
			$this->_y = -( abs( $orig_y ) + abs( $dest_y ));
		if ( $dest_z > 0 )
			$this->_z = ( abs( $orig_z ) + abs( $dest_z ));
		else if ( $dest_z < 0 )
			$this->_z = -( abs( $orig_z ) + abs( $dest_z ));
		if ( self::$verbose === True )
			print( 'Vector( x: '.number_format( $this->getX(),2 ).', y: '.number_format( $this->getY(),2 ).', z: '.number_format( $this->getZ(),2 ).', w: '.number_format( $this->getW(),2 ).' ) constructed'.PHP_EOL );
		return;
	}

	function __destruct() {
		if (self::$verbose === True)
			print('Vector( x: '.number_format($this->getX(),2).', y: '.number_format($this->getY(),2).', z: '.number_format($this->getZ(),2).', w: '.number_format($this->getW(),2).' ) destructed'.PHP_EOL);
		return;
	}

	function __toString() {
		return ('Vector( x: '.number_format($this->getX(),2).', y: '.number_format($this->getY(),2).', z: '.number_format($this->getZ(),2).', w: '.number_format($this->getW(),2).' )');
	}
}
?>
