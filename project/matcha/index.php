<?php
include 'config/database.php';
session_start();
if (!isset($_SESSION['login'])){
	header('Location: /client/views/signin.php');
	exit;
}
else{
	include('client/views/header.php');
	include('client/views/nav.php');
?>
<div id="container" class="container">

</div>
<?php include('client/views/footer.php'); } ?>
