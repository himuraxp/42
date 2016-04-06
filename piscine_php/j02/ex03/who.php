#!/usr/bin/php
<?php
date_default_timezone_set('EUROPE/PARIS');
$filename = "/var/run/utmpx";
$handle = fopen($filename, "rb");
while ($utmp = fread($handle, 628))
{
	$tmp = unpack("a256user/a4id/a32line/ipid/itype/I2time/a256host/i16pad", $utmp);
	if ($tmp["type"] == 7)
	{
		$user[$tmp["line"]] = array("user" => $tmp["user"], "time" => $tmp["time1"]);
	}
}
ksort($user);
foreach($user as $key => $value)
{
		printf("% -7s  % -7s  %s \n", $value["user"], $key, date("M  j H:i", $value["time"]));
}
echo $count;
?>
