<?php
namespace Core\Database;

use \PDO;

class MysqlDatabase extends Database
{
	private $db_name;
	private $db_user;
	private $db_pass;
	private $db_host;
	private $pdo;

	public function __construct($db_name, $db_user = 'root', $db_pass = 'root', $db_host = 'localhost')
	{
		$this->db_name = $db_name;
		$this->$db_user = $db_user;
		$this->$db_pass = $db_pass;
		$this->$db_host = $db_host;
	}

	private function getPDO()
	{
		if($this->pdo === null)
		{
			$pdo = new PDO('mysql:dbname=Blog;host=localhost:8889', 'root', 'root');
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$this->pdo = $pdo;
		}
		return $this->pdo;
	}

	private function getPDOinstall()
	{
		if($this->pdo === null)
		{
			$pdo = new PDO('mysql:host=localhost:8889', 'root', 'root');
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$this->pdo = $pdo;
		}
		return $this->pdo;
	}

	public function query($statement, $class_name = null, $one = false)
	{
		$req = $this->getPDO()->query($statement);
		if(	strpos($statement, 'UPDATE') === 0 ||
			strpos($statement, 'INSERT') === 0 ||
			strpos($statement, 'DELETE') === 0 )
			return $req;

		if($class_name === null)
			$req->setFetchMode(PDO::FETCH_OBJ);
		else
			$req->setFetchMode(PDO::FETCH_CLASS, $class_name);

		if($one)
			$datas = $req->fetch();
		else
			$datas = $req->fetchAll();
		return $datas;
	}

	public function prepare($statement, $attributes, $class_name = null, $one = false)
	{
		$req = $this->getPDO()->prepare($statement);
		$res = $req->execute($attributes);
		if(	strpos($statement, 'UPDATE') === 0 ||
			strpos($statement, 'INSERT') === 0 ||
			strpos($statement, 'DELETE') === 0 )
			return $res;

		if($class_name === null)
			$req->setFetchMode(PDO::FETCH_OBJ);
		else
			$req->setFetchMode(PDO::FETCH_CLASS, $class_name);

		if($one)
			$datas = $req->fetch();
		else
			$datas = $req->fetchAll();

		return $datas;
	}

	public function drop($database = null, $table = null){
		if (is_null($table))
		{
			$req = $this->getPDOinstall()->exec("DROP " . $database . " IF EXISTS ". $this->db_name);
			echo $this->db_name . " has was deleted !";
		}
		else if ($database === 'off')
			$req = $this->getPDO()->exec("DROP TABLE IF EXISTS " . $table);
	}

	public function create($db_table)
	{
		$req = $this->getPDOinstall()->exec("CREATE DATABASE IF NOT EXISTS ". $this->db_name);
		if ($req)
			echo "Database : ". $this->db_name . " created";
		else
			die(print_r($req->errorInfo(), true));

		$req = $this->getPDO()->drop('off', $db_table['users']);
		$req = $this->getPDO()->exec("
			CREATE TABLE IF NOT EXISTS " . $db_table['users'] . " (
			id int(11) AUTO_INCREMENT PRIMARY KEY NOT NULL,
			login varchar(255) UNIQUE NOT NULL,
			first_name varchar(255) NOT NULL,
			last_name varchar(255) NOT NULL,
			email varchar(255) NOT NULL UNIQUE,
			age DATE,
			password varchar(255) NOT NULL,
			sexe varchar(255),
			bio TEXT,
			reset varchar(255),
			code_confirmation varchar(255),
			confirmed BOOLEAN NOT NULL DEFAULT 0);
			");
		echo " Table: " . $db_table['users'] . " created";

		$req = $this->getPDO()->drop('off', $db_table['pictures']);
		$req = $this->getPDO()->exec("
			CREATE TABLE IF NOT EXISTS ". $db_table['pictures'] . " (
			id INT(11) AUTO_INCREMENT PRIMARY KEY NOT NULL,
			date TIMESTAMP NOT NULL,
			deleted BOOLEAN NOT NULL DEFAULT 0,
			createur VARCHAR(255) NOT NULL,
			link TEXT NOT NULL);
			");
		echo " Table: " . $db_table['pictures'] . " created";

		$req = $this->getPDO()->drop('off', $db_table['messages']);
		$req = $this->getPDO()->exec("
			CREATE TABLE IF NOT EXISTS ". $db_table['messages'] . " (
			id INT(11) AUTO_INCREMENT PRIMARY KEY NOT NULL,
			date TIMESTAMP NOT NULL,
			deleted BOOLEAN NOT NULL DEFAULT 0,
			created_by VARCHAR(255) NOT NULL,
			content TEXT NOT NULL);
			");
		echo " Table: " . $db_table['messages'] . " created";

		$req = $this->getPDO()->drop('off', $db_table['likes']);
		$req = $this->getPDO()->exec("
			CREATE TABLE IF NOT EXISTS ". $db_table['likes'] . " (
			id INT(11) AUTO_INCREMENT PRIMARY KEY NOT NULL,
			user_like_id INT(11) NOT NULL ,
			user_liker_id INT(11) NOT NULL);
			");
		echo " Table: " . $db_table['likes'] . " created";

		$req = $this->getPDO()->drop('off', $db_table['styles']);
		$req = $this->getPDO()->exec("
			CREATE TABLE IF NOT EXISTS ". $db_table['styles'] . " (
			id INT(11) AUTO_INCREMENT PRIMARY KEY NOT NULL,
			user_id INT(11) NOT NULL ,
			geek BOOLEAN NOT NULL DEFAULT 0,
			bio BOOLEAN NOT NULL DEFAULT 0,
			sport BOOLEAN NOT NULL DEFAULT 0,
			barbu BOOLEAN NOT NULL DEFAULT 0,
			maliceu BOOLEAN NOT NULL DEFAULT 0;
			");
		echo " Table: " . $db_table['styles'] . " created";
	}

	public function lastInsertId()
	{
		return $this->getPDO()->lastInsertId();
	}

}
