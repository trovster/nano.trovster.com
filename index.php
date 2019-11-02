<?php
require_once('header.inc.php');

if(isset($section))
{
	require_once('pages/'.$section.'.inc');
}
else
{
	echo '<p>No section</p>';
}

require_once('footer.inc.php');
?>