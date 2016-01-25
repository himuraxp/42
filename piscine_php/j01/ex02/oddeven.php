#!/usr/bin/php
<?php
		while (1)
		{
			echo "Entrez un nombre: ";
			$fd = fopen("php://stdin", 'r');
			$buffer = fgets($fd);
			$buffer = substr($buffer, 0, -1);
			if ($buffer == NULL)
				break ;
			if (is_numeric($buffer))
			{
				if ($buffer % 2 == 0)
					echo "Le chiffre $buffer est Pair\n";
				else
					echo "Le chiffre $buffer est Impair\n";
			}
			else
				echo "'$buffer' n'est pas un chiffre\n";
		}
		fclose($fd);
?>
