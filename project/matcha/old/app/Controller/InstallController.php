<?php
namespace App\Controller;

use Core\Setup;
use Core\Config;
use \App;
require ROOT . '/core/Setup.php';

class InstallController extends AppController
{
	private $db_instance;
	private static $_instance;

	public function install()
	{
		echo "Install execute";
		$db = new App::getInstance();
		$install = new Setup($db);
		$install->install();
	}

	public function getDbinstall()
	{
		$config = Config::getInstance(ROOT . '/config/config.php');
		if(is_null($this->db_instance))
		{
			$this->db_instance = new MysqlDatabase($config->get('db_name'), $config->get('db_user'), $config->get('db_pass'), $config->get('db_host'));
		}
		return $this->db_instance;
	}
}
?>
