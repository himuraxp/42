<?php
include 'config/database.php';
session_start();
if (!isset($_SESSION['login'])){
	header('Location: /client/views/signin.php');
	exit;
}
else{
	include('header.php');
	include('nav.php');
?>
<div class="container">
	<div class="profil">
		<p>
			test
		</p>
	</div>
</div>
<?php include('footer.php'); } ?>
