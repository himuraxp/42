<?php
try
{
	$DB_USER = 'root';
	$DB_PASSWORD = 'root';
	$DB_DSN = new PDO('mysql:host=localhost;dbname=gamagru;charset=utf8', $DB_USER, $DB_PASSWORD);
}
catch (Exception $e)
{
	die('Erreur : ' . $e->getMessage());
}
?>
