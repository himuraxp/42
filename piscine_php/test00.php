#!/usr/bin/php

<?php

function my_add($p1, $p2)
{
	return $p1 + $p2;
}

print("Cours PHP !!!\n\n");

$my_var = 42;
$my_str = "World";
$my_tab = array("zero", "un", "deux");
$my_hash = array("key1" => "val1", key2 => "val2");

//echo "$my_var\n$my_str\n";
$result = $my_var - "63";
echo $result."\n";

$my_tab[0] = "Coucou";

echo $my_tab[0]."\n";
echo $my_hash["key1"]."\n";

echo $my_tab."\n";
print_r($my_tab);
echo my_add("36", "6")."\n";

if ($my_tab[1] == "un")
echo "OK\n";
else
echo "KO\n";
echo "$argc\n";
print_r($argv)."\n";

foreach ($argv as $elem)
{
	echo $elem."\n";
}

$my_tab = explode(";", "zero;un;deux");
print_r($my_tab);
?>
