<?php error_reporting(0);
header("Content-Type: text/html; charset=utf-8");
require_once('db.inc.php');

$section = 'news';
if(isset($_GET['section']))
{
	$section = $_GET['section'];
}

$products = '';
$products_title = '';
$products_output = '';
if(isset($_GET['products']))
{
	$products = $_GET['products'];
	$products_output = ucwords($products);
	$products_title = '-'.$products;
}
$section_output = ucwords($section);

$line = '';
if(isset($_GET['line']))
{
	$line = $_GET['line'];
}

if(isset($_GET['date']))
{
	$date = $_GET['date'];
}

$services = 'web-solution-for-alpha-moisture-systems';
if(isset($_GET['services']))
{
	$services = $_GET['services'];
}
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html lang="en">
<head>

<?php
$page_title = 'Nano - Innovators in 3D internet.';
$at = ' ';
if(isset($_GET['section']))
{
	if($section=='products' || $section=='services')
	{
		$at .= 'at ';
	}
	$page_title = $section_output.$at.$page_title;
}
echo '<title>'.$page_title.'</title>'."\n\n";

if(stristr($_SERVER['HTTP_HOST'],'trov.ath.cx') || stristr($_SERVER['HTTP_HOST'],'trovster.ath.cx')) {
	echo '<base href="http://'.$_SERVER['HTTP_HOST'].'/nano/">'."\n\n";
}
else {
	echo '<base href="http://'.$_SERVER['HTTP_HOST'].'/">'."\n\n";
}
?>
<link rel="stylesheet" type="text/css" media="screen" href="styles/screen.css">

<!-- fix for Internet Explorer's lack of support for alpha transparency -->
<!--[if IE]>
<style type="text/css" media="screen">
body {
behavior: url(scripts/csshover.htc);	
}
img {
behavior: url(scripts/pngbehavior.htc);
}
</style>
<![endif]-->
<script type="text/javascript" src="scripts/productmouseover.js"></script>

<link rel="shortcut icon" href="favicon.ico">

</head>

<?php
echo '<body id="page-'.$section.$products_title.'">'."\n\n";
?>
<div id="container">

<h1><span></span>Nano</h1>

<div id="navigation">
<ul>
<li id="news"><a href="" title="Hello, nice to meet you at NANO"><span></span>News</a></li>
<li id="about"><a href="about/" title="Specialists in 3D internet"><span></span>About Us</a></li>
<li id="products"><a href="products/" title="How can we help you?"><span></span>Products</a></li>
<li id="portfolio"><a href="portfolio/" title="We work for your success"><span></span>Portfolio</a></li>
<li id="contact"><a href="contact/" title="We are happy to see you"><span></span>Contact</a></li>
</ul>
</div>

<div id="content_container">

<?php
$h2 = '<h2><span></span>'.$products_output.'</h2>';
if(empty($products))
{
	$h2 = '<h2><span></span>'.$section_output.'</h2>'."\n\n";
}
echo $h2;
?>