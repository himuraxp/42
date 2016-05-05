<?php
	try{
		$DB_DSNNAME = $DB_DSN.";dbname=".$DB_NAME;
		$pdo = new PDO($DB_DSNNAME , $DB_USER, $DB_PASSWORD);
	}
	catch(PDOException $e){
		$msg = 'ERREUR PDO dans ' . $e->getFile() . ' L.' . $e->getLine() . ' : ' . $e->getMessage();
		die($msg);
	}
	$querry = "SELECT link, id FROM ".$DB_TABLE['pictures']." WHERE createur='".$_SESSION['login']."' and deleted=0";
	$arr = $pdo->query($querry)->fetchAll();
	if (isset($arr)){
		$max = sizeof($arr);
		for($i = 0; $i < $max; $i++){
?>

<form name="deletphoto" action="/server/supppicture.php" method="post">
	<input style="display:none;" name="photoid" value="<?php echo $arr[$i]['id']; ?>" hidden/>
	<div id="picture" class="picture">
		<img class="pics-lib" src="<?php echo $arr[$i]['link'];?>"/>
	</div>
	<button type="submit" class="del-button">Delete</button>
</form>
<?php
		}
	}
	$pdo=NULL;

?>
