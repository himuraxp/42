<?php

namespace Core;


class Setup
{

	private $db;
	private $db_table[
		'users',
		'pictures',
		'messages',
		'likes',
		'style'
	];

	public function __construct(Database $db){
		$this->db = $db;
	}

	public function install(){
		$db = $this->db->drop($this->db_name);
		$db = $this->db->create($this->db_table);
		return echo "the database " . $this->db_name . " is initialized" . PHP_EOL;
	}

}
?>
