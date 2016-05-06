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
	<div id="box" class="box">
		<div class="box-menu">
			<div class="stricky">
				<div id="picture" class="picture-cam">
					<img class="clipart" src="/client/images/42-logo.png" onclick="add('42-logo');"/>
				</div>
				<div id="picture" class="picture-cam">
					<img class="clipart" src="/client/images/punisher.png" onclick="add('punisher');"/>
				</div>
				<div id="picture" class="picture-cam">
					<img class="clipart" src="/client/images/fire2.png" onclick="add('fire2');"/>
				</div>
				<div id="picture" class="picture-cam">
					<img class="clipart" src="/client/images/glace.png" onclick="add('glace');"/>
				</div>
				<div id="picture" class="picture-cam">
					<img class="clipart" src="/client/images/poney.png" onclick="add('poney');"/>
				</div>
				<div id="picture" class="picture-cam">
					<img class="clipart" src="/client/images/hair.png" onclick="add('hair');"/>
				</div>
			</div>
		</div>
		<div id="box-cam" class="box-cam">
			<div class="image-cam">
				<img src="" class="tricky" id="upload-js"/>
				<img src="" class="tricky" id="clipart"/>
				<video id="video" class="webcam" autoplay></video>
			</div>
			<form action="/server/recpicture.php" name="uploadphoto" method="post" style="display:inline-table;" enctype="multipart/form-data">
				<div class="option">
					<h1 class="notice">Position du filtre
						<p class="notice-text">Indiquer la position avant de cliquer sur un filtre</p>
						<select name="coner" id="coner">
							<option value="tl">Top Left</option>
							<option value="tr">Top Right</option>
							<option value="bl">Bottom Left</option>
							<option value="br">Bottom Right</option>
							<option value="top" disabled>Top</option>
						</select>
					</h1>
					<h1 class="notice">Pas de webcam ?
						<p class="notice-text">Importer une photo</p>
						<input name="upload" type="file" accept="image/jpeg" onchange="loadFile(event);"></input>
						<canvas hidden id="canvas"></canvas>

					</h1>
				</div>
				<div class="action">
					<h1 id="title" class="notice">Shoot me <input class="save" disabled id="startbutton"></h1>
					<div style="display:none;">
						<input name="image" id="name" hidden/>
						<input name="login" value="<?php echo $_SESSION['login']?>" hidden/>
						<input name="clip"  id="clipprep" hidden/>
					</div>
				</div>
			</form>
		</div>
	</div>
	<div id="galerie" class="galerie">
		<h1 id="title" class="title-galerie">Ma galerie<br>
			<form name="restorephoto" action="/server/supppicture.php" method="post">
				<div style="display:none;">
					<input name="restore" value="1" hidden/>
				</div>
				<button type="submit" class="deleteButton">Restore pictures</button>
			</form>
		</h1>
		<?php include('server/picture.php'); ?>
	</div>
</div>
<?php include('client/views/footer.php'); } ?>
