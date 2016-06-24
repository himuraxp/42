<?php
include '../../config/database.php';
session_start();
if (!isset($_SESSION['login'])){
	header('Location: /client/views/signin.php');
	exit;
}
else{
	try{
		$DB_DSNNAME = $DB_DSN.";dbname=".$DB_NAME;
		$pdo = new PDO($DB_DSNNAME , $DB_USER, $DB_PASSWORD);
	}
	catch(PDOException $e){
		$msg = 'ERREUR PDO dans ' . $e->getFile() . ' L.' . $e->getLine() . ' : ' . $e->getMessage();
		die($msg);
	}
	include('header.php');
	include('nav.php');
	$pagin = "SELECT COUNT(id) as nbPics FROM ".$DB_TABLE['pictures']." WHERE deleted=0";
	$data = $pdo->query($pagin)->fetch();
	$nbPics = $data['nbPics'];
	$perPage = 6;
	$nbPage = ceil($nbPics/$perPage);
	if (isset($_GET['p']) && $_GET['p'] > 0 && $_GET['p'] <= $nbPage)
		$curPage = $_GET['p'];
	else
		$curPage = 1;
?>
	<div class="pagin">
<?php
	for ($i = 1; $i <= $nbPage; $i++) {
		if ($i == $curPage)
			echo '<div class="button-off pagin"> '.$i.' </div>';
		else
			echo '<a class="button pagin" href="galerie.php?p='.$i.'"> '.$i.' </a>';
	}
?>
</div>
<div class="box-full" style="">
<?php


	$q = $pdo->prepare("SELECT refphotoid FROM ".$DB_TABLE['likes']." WHERE LOGIN=:login;");
	$q->bindvalue(':login', $_SESSION['login']);
	$qq = $q->execute();
	$liketab = $q->fetchAll();
	$querry = "SELECT link,id,createur,creation,deleted FROM ".$DB_TABLE['pictures']." WHERE deleted=0 ORDER BY creation DESC LIMIT ".(($curPage-1)*$perPage).",$perPage";
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
		if ($array[$j]['auteur'] === $_SESSION['login']){ ?>
		<div class="active-comments comments">
<?php 	} else { ?>
		<div class="comments">
<?php 	} ?>
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
			<div>
				<input hidden name="id" value="<?php echo $arr[$i]['id'];?>" style="display:none;"/>
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
	if ($flag == 1){
		?>
			<form action="/server/unlike.php" method="post" class="love">
				<div style="display:none;">
					<input hidden name="id" value="<?php echo $arr[$i]['id'];?>" style="display:none;"/>
					<input hidden name="login" value="<?php echo $_SESSION['login'];?>" style="display:none;"/>
				</div>
				<button type="submit" class="love fa fa-thumbs-down"></button>
			</form>
		</div>
<?php
	}
	else {?>
			<form action="/server/like.php" method="post" class="love">
				<div>
					<input hidden name="id" value="<?php echo $arr[$i]['id'];?>"  style="display:none;"/>
					<input hidden name="login" value="<?php echo $_SESSION['login'];?>"  style="display:none;"/>
				</div>
				<button type="submit" class="love fa fa-thumbs-up"></button>
			</form>
		</div>
<?php 	}
}
if (!isset($liketab)){
	?>
			<form action="/server/like.php" method="post" class="love">
				<div>
					<input hidden name="id" value="<?php echo $arr[$i]['id'];?>" style="display:none;"/>
					<input hidden name="login" value="<?php echo $_SESSION['login'];?>" style="display:none;"/>
				</div>
				<button type="submit" class="love fa fa-thumbs-up"></button>
			</form>
		</div>
<?php }} ?>
	</div>

<?php }}
	$pdo=NULL;
}
?>
</div>
<?php include('footer.php'); ?>
