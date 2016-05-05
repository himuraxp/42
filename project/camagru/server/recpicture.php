<?php
include '../config/database.php';
session_start();

header('Location: /');
if (isset($_SESSION['login'])){
	try{
		$DB_DSNNAME = $DB_DSN.";dbname=".$DB_NAME;
		$pdo = new PDO($DB_DSNNAME , $DB_USER, $DB_PASSWORD);
	}
	catch(PDOException $e){
		$msg = 'ERREUR PDO dans '.$e->getFile().' L '.$e->getLine().' : '.$e->getMessage();
		die($msg);
	}
	$login	= htmlspecialchars($_POST['login']);
	$target_dir = $_SERVER['DOCUMENT_ROOT'];
	$target_file = $target_dir.basename($_FILES["upload"]["name"]);
	$uploadOk = 1;
	$imageFileType = pathinfo($target_file, PATHINFO_EXTENSION);
	$check = getimagesize($_FILES["upload"]["tmp_name"]);
	if($check !== false) {
		if (move_uploaded_file($_FILES["upload"]["tmp_name"], $target_file)) {
			$dst = imagecreatefromjpeg($target_file);
		}
	}
	else {
		$img = $_POST['image'];
		$img = str_replace('data:image/jpeg;base64,', '', $img);
		$img = str_replace(' ', '+', $img);
		$dstim = base64_decode($img);
		$dst = imagecreatefromstring($dstim);
	}
	$image = imagecreatefrompng("../client/images/".$_POST['clip'].".png");

	imagealphablending($dst, true);
	imagesavealpha($dst, true);

	if (isset($_POST['coner'])){
		if ($_POST['coner'] == 'br'){
			imagecopy($dst, $image, imagesx($dst)-imagesx($image), imagesy($dst)-imagesy($image), 0, 0, imagesx($image), imagesy($image));
		}
		else if ($_POST['coner'] == 'bl'){
			imagecopy($dst, $image, 0, imagesy($dst)-imagesy($image), 0, 0, imagesx($image), imagesy($image));
		}
		else if ($_POST['coner'] == 'tl'){
			imagecopy($dst, $image, 0, 0, 0, 0, imagesx($image), imagesy($image));
		}
		else{
			imagecopy($dst, $image, imagesx($dst)-imagesx($image), 0, 0, 0, imagesx($image), imagesy($image));
		}
	}
	else{
		imagecopy($dst, $image, imagesx($dst)-imagesx($image), 0, 0, 0, imagesx($image), imagesy($image));
	}
	ob_start();
	imagejpeg($dst);
	$image_data = ob_get_contents();
	ob_end_clean();
	$link = "data:image/jpeg;base64,".base64_encode($image_data);
	$stmt = $pdo->prepare("INSERT INTO ".$DB_TABLE['pictures']."(createur, link, creation) VALUES(:login, :link, :creation)");
	$stmt->bindValue(':login', $login);
	$stmt->bindValue(':link', $link);
	$stmt->bindValue(':creation', date("Y-m-d H:i:s"));
	$stmt->execute();
	imagedstroy($image);
	imagedstroy($dst);
	$pdo = NULL;
}
exit;
?>
