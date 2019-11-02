<?php
if(!empty($products))
{
	$onclick_js = "onclick=\"window.open(this.href, '".ucwords($products)."Demo', config='menubar=0,location=0,resizable=0,scrollbars=0,status=0,height=350px,width=750px,left=265px,top=330px');return false;\"";
	
	echo "\n\n".'<ul id="product_navigation">'."\n";
	echo '<li><a href="products/'.$products.'/product" title="About '.ucwords($products).' Products"><span></span>Product</a></li>'."\n";
	echo '<li id="demo"><a href="pages/products/'.$products.'/demo.html" '.$onclick_js.' title="'.ucwords($products).' Demo"><span></span>Demo</a></li>'."\n";
	echo '</ul>'."\n";
	
	$filler_text = 'Knight Rider, a shadowy fight into the dangerous world of a man who does not exist. Michael Knight,
	a young loner on a crusade to champion the cause of the innocent, the helpless in a world of criminals who operate above the law.';
}

$class = '';
if(!empty($line))
{
	$class = ' class="products_page"';
}

echo '<div id="content"'.$class.'>'."\n\n";

if(!empty($products))
{
	if(!empty($line))
	{
		$line_output = ucwords($line);
		echo '<h3>'.$line_output.'</h3>';
		require_once('pages/products/'.$products.'.inc');
	}
}
else
{
	$product_description_array = array(
	'tera' => 'Fully interactive true 3D content',
	'nova' => 'Experience your product in the most attractive way',
	'giga' => '3D without plugin',
	'peta' => 'Do you wanna play, baby?'
	);
	
	foreach($product_description_array as $product_name => $product_description)
	{
		$product_name_output = ucwords($product_name);
		$img_url = 'images/products_'.$product_name.'.png';
		list($width, $height) = getimagesize($img_url);
	
		echo '<dl id="'.$product_name.'">'."\n";
		echo '<dt><a href="products/'.$product_name.'/" title="'.$product_description.'"><img src="'.$img_url.'" alt="'.$product_name_output.'" height="'.$height.'px" width="'.$width.'px"></a></dt>'."\n";
		echo '<dd><a href="products/'.$product_name.'/" title="'.$product_description.'"><span></span>'.$product_name_output.'</a></dd>'."\n";
		echo '<dd class="description">'.$product_description.'.</dd>';
		echo '</dl>'."\n\n";
	}
}
?>

<!-- end of div id #content -->
</div>