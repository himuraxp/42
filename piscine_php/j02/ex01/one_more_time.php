#!/usr/bin/php
<?php
date_default_timezone_set('EUROPE/PARIS');
$day = [
	"Lundi" => "1",
	"Mardi" => "2",
	"Mercredi" => "3",
	"Jeudi" => "4",
	"Vendredi" => "5",
	"Samedi" => "6",
	"Dimanche"=> "7",
];

$mount = [
	"Janvier" => "1",
	"Fevrier" => "2",
	"Mars" => "3",
	"Avril" => "4",
	"Mai" => "5",
	"Juin" => "6",
	"Juillet" => "7",
	"Aout" => "8",
	"Septembre" => "9",
	"Octobre" => "10",
	"Novembre" => "11",
	"Decembre" => "12",
];
function ft_error()
{
	echo "Wrong Format\n";
	exit;
}

if ($argv[1])
{
	$tmp = $argv[1];
	$hash = explode(" ", $tmp);
	$time = explode(":", $hash[4]);
	$hash[0] = ucfirst($hash[0]);
	$hash[2] = ucfirst($hash[2]);
	$date = $hash[1];
	$year = $hash[3];
	$hour = $time[0];
	$min = $time[1];
	$sec = $time[2];
	if (preg_match("/^[0-9]{1,2}$/", $hash[1]) === 0)
		ft_error();
	if (($hour == NULL) || ($sec == NULL) || ($min == NULL))
		ft_error();
	foreach ($day as $key => $value)
	{
		if (preg_match("/^$key$/", "$hash[0]") === 1)
		{
			$verif = 1;
			break ;
		}
		$verif = 0;
	}
	if ($verif == 0)
		ft_error();
	$verif = 0;
	foreach ($mount as $key => $value)
	{
		if (preg_match("/^$key$/", "$hash[2]") === 1)
		{
			$verif = 1;
			break ;
		}
		$verif = 0;
	}
	if ($verif == 0)
		ft_error();
	print(mktime($hour, $min, $sec, $mount[$key], $date, $year));
	echo "\n";
}

?>
