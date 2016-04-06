#!/usr/bin/php
<?php
$path = $argv[1];
$new = explode("/", $argv[1]);
if ($new[0] !== "http:")
{
	$dir = $path;
	if (substr($new[0], 0, 4) === "www.")
		$protocol = "http://".$path;
	else
		$protocol = "http://www.".$path;
}
else
{
	$dir = $new[2];
	if (substr($new[2], 0, 4) === "www.")
		$protocol = $path;
	else
		$protocol = "http://www.".$new[2];
}
$content = file_get_contents($protocol);
preg_match_all("/<img.*(?<=src=\")(.*)\"/iUs", $content, $links);
foreach ($links[1] as $elem)
{
	$new = explode("/", $elem);
	if ($new[0] === "http:")
		$tmp = $elem;
	else
	{
		if ($new[0] !== "..")
			$tmp = $protocol."/".$elem;
		else
			exit;
	}
	$img = $new[count($new) - 1];
	@mkdir($dir);
	$handle = fopen($dir."/".$img, "w");
	$img = file_get_contents($tmp);
	fwrite($handle, $img);
	fclose($handle);
}
?>
