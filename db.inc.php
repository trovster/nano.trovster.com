<?php
//connect db
$sql_url = 'trovster_nano_mysql';
$sql_username = 'nano';
$sql_password = 'password';
$sql_database = 'nano';

$dbase = mysqli_connect($sql_url, $sql_username, $sql_password, $sql_database);
mysqli_select_db($dbase, $sql_database);

function truncate($str, $len, $el='&#8230;')
{
	if (strlen($str) > $len)
	{
		$xl = strlen($el);
		if ($len < $xl)
		{
			return substr($str, 0, $len);
		}
		$str = substr($str, 0, $len-$xl);
		$spc = strrpos($str, ' ');

		if ($spc > 0)
		{
			$str = substr($str, 0, $spc);
		}
	return $str.$el;
	}
	return $str;
}
?>
