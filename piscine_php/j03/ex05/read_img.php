<?php
$name = "../img/42.png";
$img = file_get_contents($name);
header("content-type: images/png");
?>
