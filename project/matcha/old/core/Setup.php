<?php
namespace Core;


class Setup
{

	private $db;
	private $db_table;
	private $db_name;

	public function __construct(Database $db){
		$db_table = array(
			"users",
			"pictures",
			"messages",
			"likes",
			"style"
		);
		$db_name = 'matcha';
		$this->db_name = $db_name;
		$this->db_table = $db_table;
		$this->db = $db;
		var_dump($this->db_name);
		var_dump($this->db_table);
		var_dump($this->db);
		$this->install();
	}

	public function install(){
		$db = $this->db->drop($this->db_name);
		$db = $this->db->create($this->db_table);
		echo "the database matcha is initialized";
	}

}
?>
