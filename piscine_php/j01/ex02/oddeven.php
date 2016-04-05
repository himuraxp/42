#!/usr/bin/php
<?php
while (42)
{
	echo "Entrez un nombre: ";
	$fd = fopen("php://stdin", 'r');
	$buf = fgets($fd);
	$buf = substr($buf, 0, -1);

	if ($buf == NULL)
		break;
	if (is_numeric($buf))
	{
		if ($buf % 2 == 0)
			echo "Le chiffre ".$buf." est Pair"."\n";
		else
			echo "Le chiffre ".$buf." est Impair"."\n";
	}
	else
		echo "'$buf' n'est pas un chiffre\n";
}
fclose($fd);
?>
