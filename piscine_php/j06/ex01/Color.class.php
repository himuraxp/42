<?php
class Color
{
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	public static $verbose = False;

	static function doc() {
		return ( file_get_contents( "./Color.doc.txt" ));
	}

	function add( $instance ) {
		$array = get_object_vars( $instance );
		return ( new Color( array( 'red' => ( $this->red + $array['red'] ), 'green' => ( $this->green + $array['green'] ), 'blue' => ( $this->blue + $array['blue'] ))));
	}

	function sub( $instance ) {
		$array = get_object_vars( $instance );
		return ( new Color( array( 'red' => ( $this->red - $array['red'] ), 'green' => ( $this->green - $array['green'] ), 'blue' => ( $this->blue - $array['blue'] ))));
	}

	function mult( $factor ) {
		return ( new Color( array( 'red' => ( $this->red * $factor ), 'green' => ( $this->green * $factor ), 'blue' => ( $this->blue * $factor ))));
	}

	function hexa_rgb($hex) {
		if( strlen( $hex ) == 3 )
		{
			$r = hexdec( substr( $hex,0,1 ).substr( $hex,0,1 ));
			$g = hexdec( substr( $hex,1,1 ).substr( $hex,1,1 ));
			$b = hexdec( substr( $hex,2,1 ).substr( $hex,2,1 ));
		}
		else
		{
			$r = hexdec( substr( $hex,0,2 ));
			$g = hexdec( substr( $hex,2,2 ));
			$b = hexdec( substr( $hex,4,2 ));
		}
		$rgb = array( $r, $g, $b );
		return $rgb;
	}

	function __construct( array $kwargs )
	{
		if ( $kwargs['red'] !== null && $kwargs['green'] !== null && $kwargs['blue'] !== null )
		{
			foreach ( $kwargs as $key => $value )
				$value = intval( $value );
			$this->red = round( $kwargs['red'] );
			$this->green = round( $kwargs['green'] );
			$this->blue = round( $kwargs['blue'] );
		}
		if ( $kwargs['rgb'] !== null )
		{
			$tmp = intval( $kwargs['rgb'] );
			$tmp = dechex( $tmp );
			$len = 6 - strlen( $tmp );
			$i = 0;
			while ( $i < $len )
			{
				$hex = $hex."0";
				$i++;
			}
			$hex = $hex.$tmp;
			$rgb = $this->hexa_rgb( $hex );
			$this->red = $rgb['0'];
			$this->green = $rgb['1'];
			$this->blue = $rgb['2'];
		}
		if (self::$verbose === True)
			print( 'Color( red: '.$this->red.', green: '.$this->green.', blue: '.$this->blue.' ) constructed.'.PHP_EOL );
		return ;
	}
	function __destruct()
	{
		if (self::$verbose === True)
			print( 'Color( red: '.$this->red.', green: '.$this->green.', blue: '.$this->blue.' ) destructed.'.PHP_EOL );
		return ;
	}
	function __toString()
	{
		return ( 'Color( red: '.$this->red.', green: '.$this->green.', blue: '.$this->blue.' )' );
	}
}
?>
