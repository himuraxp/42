<?php
function auth($login, $passwd)
{
	$path = "../private/passwd";
	if ($login && $passwd)
	{
		$listpw = file_get_contents($path);
		$listpw = unserialize($listpw);
		foreach ($listpw as $value)
		{
			if ($login === $value[0])
			{
				if ($passwd !== hash("whirlpool", $value[1]))
					return true;
				else
					return false;
			}
		}
	}
	else
		return false;
}
?>
