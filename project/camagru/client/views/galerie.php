<?php
include '../../config/database.php';
session_start();
if (!isset($_SESSION['login'])){
	header('Location: /client/views/signin.php');
	exit;
}
else{
	include('header.php');
	include('nav.php');
?>
<div class="box-full" style="">
<?php
	try{
		$DB_DSNNAME = $DB_DSN.";dbname=".$DB_NAME;
		$pdo = new PDO($DB_DSNNAME , $DB_USER, $DB_PASSWORD);
	}
	catch(PDOException $e){
		$msg = 'ERREUR PDO dans ' . $e->getFile() . ' L.' . $e->getLine() . ' : ' . $e->getMessage();
		die($msg);
	}
	$q = $pdo->prepare("SELECT refphotoid FROM ".$DB_TABLE['likes']." WHERE LOGIN=:login;");
	$q->bindvalue(':login', $_SESSION['login']);
	$qq = $q->execute();
	$liketab = $q->fetchAll();
	$querry = "SELECT link,id,createur,creation,deleted FROM ".$DB_TABLE['pictures']." WHERE deleted=0 ORDER BY creation DESC;";
	$arr = $pdo->query($querry)->fetchAll();
	if (isset($arr)){
		$max = sizeof($arr);
		for($i = 0; $i < $max; $i++){
?>

	<div class="box-min" style="">
<?php if (isset($_SESSION['login'])){
?>
		<h1 class="auteur"> Posté par <?php echo $arr[$i]['createur']; ?></h1>
		<div class="picture-gal">
			<img class="pics-gal" src="<?php echo $arr[$i]['link'];?>"/>
		</div>
		<div class="commented">
<?php
	$querry = "SELECT comment, auteur FROM ".$DB_TABLE['comments']." where photonum=".$arr[$i]['id'].";";
	$array = $pdo->query($querry)->fetchAll();
	for ($j = 0; $j < sizeof($array); $j++){
?>
		<div class="comments">
			<p>
				<div class="comments-autor">
					<?php echo $array[$j]['auteur'];?>
				</div>
				<div class="comments-text">
					<?php echo $array[$j]['comment'];?>
				</div>
			</p>
		</div>
<?php
	}
?>
<?php if (isset($_SESSION['login'])){ ?>
		<form action="/server/comment.php" method="post" class="formcomment">
			<div style="display:none;">
				<input hidden name="id" value="<?php echo $arr[$i]['id'];?>"/>
				<input hidden name="login" value="<?php echo $_SESSION['login'];?>"/>
			</div>
			<textarea name="comment" class="commentzone" placeholder="lache ton commentaire..."></textarea>
			<button type="submit" class="send-button">Envoyer</button>
		</form>
<?php }
if (isset($liketab)){
	$maxlike = sizeof($liketab);
	$flag = 0;
	for($j = 0; $j < $maxlike; $j++){
		if ($liketab[$j]['refphotoid'] == $arr[$i]['id']){
			$flag = 1;
		}
	}
	if ($flag == 1){?>
			<form action="/server/unlike.php" method="post" class="love">
				<div style="display:none;">
					<input hidden name="id" value="<?php echo $arr[$i]['id'];?>"/>
					<input hidden name="login" value="<?php echo $_SESSION['login'];?>"/>
				</div>
				<button type="submit" class="love fa fa-thumbs-down"></button>
			</form>
<?php 	}
	else {?>
			<form action="/server/like.php" method="post" class="love">
				<div style="display:none;">
					<input hidden name="id" value="<?php echo $arr[$i]['id'];?>"/>
					<input hidden name="login" value="<?php echo $_SESSION['login'];?>"/>
				</div>
				<button type="submit" class="love fa fa-thumbs-up"></button>
			</form>
<?php 	}
}
if (!isset($liketab)){?>
			<form action="/server/like.php" method="post" class="love">
				<div style="display:none;">
					<input hidden name="id" value="<?php echo $arr[$i]['id'];?>"/>
					<input hidden name="login" value="<?php echo $_SESSION['login'];?>"/>
				</div>
				<button type="submit" class="love fa fa-thumbs-up"></button>
			</form>
<?php }} ?>
		</div>
	</div>

<?php }}
	$pdo=NULL;
}
?>
</div>
<?php include('footer.php'); ?>
