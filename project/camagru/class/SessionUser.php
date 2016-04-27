<?php
class SessionUser{

    private $_db;
    private $_login;

    public function __construct($db, $login){
        $this->setDb($db);
        $this->setLogin($login);
    }

    public function createSession(){
        $query = $this->getDb()->prepare('SELECT users.ID, users.Login, users.Mail, users.role, users.date_inscription, YEAR(users.date_inscription) AS ins_year, MONTH(users.date_inscription) AS ins_month, DAY(users.date_inscription) AS ins_day, HOUR(users.date_inscription) AS ins_hour, MINUTE(users.date_inscription) AS ins_min, SECOND(users.date_inscription) AS ins_sec, images.ID AS id_img, images.Filter, images.Webcam, images.Plus
        FROM users INNER JOIN images ON users.ID = images.ID
        WHERE users.login = :login');
        $query->bindValue(':login', $this->getLogin());
        $query->execute();
        $data = $query->fetch(PDO::FETCH_ASSOC);
        foreach($data as $key => $value){
            if ($key != 'password'){
                if (($key === 'ins_day' || $key === 'ins_month' || $key === 'ins_year' || $key === 'ins_hour' || $key === 'ins_min' || $key === 'ins_sec') && $value <= 9){
                    $value = "0".$value;
                }
                $_SESSION[$key] = $value;
            }
        }
    }

    public function setDb($value){
        if (isset($value))
            $this->_db = $value;
    }

    public function setLogin($value){
        if (isset($value))
            $this->_login = $value;
    }

    public function getDb(){
        return ($this->_db);
    }

    public function getLogin(){
        return ($this->_login);
    }
}
?>
