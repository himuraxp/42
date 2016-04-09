<?php
$msgs = [];
if (!file_exists('../private'))
  mkdir('../private');
if (file_exists('../private/chat'))
{
  date_default_timezone_set('Europe/Paris');
  $fd = fopen('../private/chat', 'r');
  if (flock($fd, LOCK_SH)) {
      $msgs = unserialize(file_get_contents('../private/chat'));
?>
<div class="chat">
<?php
      foreach ($msgs as $tab) {
?>
<p class="history">
<?php
        echo "[".date("H:i", $tab['time'])."] ";
        echo "<b>".$tab['login']."</b>: ";
        echo $tab['msg']."<br />"."\n";
?>
</p>
<?php
      }
?>
</div>
<?php
      flock($fd, LOCK_UN);
  }
  fclose($fd);
}
?>
