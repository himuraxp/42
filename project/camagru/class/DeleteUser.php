<?php
class DeleteAccount{

	private $_db;
	private $_pass;
	private $_id;

	public function __construct($id, $pass, $db){
		$this->setDb($db);
		$this->setPass($pass);
		$this->setId($id);
	}

	public function eraseAccount(){
		$db = $this->getDb();
		$query = $db->prepare('SELECT * FROM `users` WHERE `id` = :id');
		$query->bindValue(':id', $this->getId());
		$query->execute();
		$data = $query->fetch(PDO::FETCH_ASSOC);
		if (isset($data['id']) && password_verify($this->getPass(), $data['password'])){
			$query = $db->prepare('SELECT `images`.`url`, `users`.`img_dir` FROM `users` INNER JOIN `images` ON `images`.`id` = `users`.`id` WHERE `users`.`id` = :id');
			$query->bindValue(':id', $this->getId());
			$query->execute();
			while($data = $query->fetch(PDO::FETCH_ASSOC)){
				if (isset($data['img_dir']))
					$dir = $data['img_dir'];
				if (isset($data['url']) && file_exists($data['url']))
					unlink($data['url']);
			}
			if (isset($dir) && file_exists($dir))
			rmdir($dir);
			$query = $db->prepare('DELETE `users`, `images` FROM `users` INNER JOIN `images` ON `images`.`id` = `users`.`id` WHERE `users`.`id` = :id');
			$query->bindValue(':id', $this->getId());
			$query->execute();
			if (isset($_SESSION)){
				foreach ($_SESSION as $key => $value){
					unset($_SESSION[$key]);
				}
				session_unset($_SESSION);
			}
		}
		else {
			$message = array("Mot de passe incorrect !", "error");
			return ($message);
		}
	}

	public function setDb($value){
		if (isset($value))
			$this->_db = $value;
	}

	public function setPass($value){
		if (isset($value))
			$this->_pass = $value;
	}

	public function setId($value){
		if (isset($value))
			$this->_id = $value;
	}

	public function getDb(){
		return($this->_db);
	}

	public function getPass(){
		return($this->_pass);
	}

	public function getId(){
		return($this->_id);
	}
}
?>
