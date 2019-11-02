<?php
echo '<div id="content">'."\n\n";

$services_search = str_replace('-',' ',$services);

// this is the headline...
$portfolio_title = mysqli_query($dbase, "SELECT id,headline FROM portfolio WHERE headline LIKE '$services_search'");
while($portfolio_title_row = mysqli_fetch_assoc($portfolio_title))
{
	extract($portfolio_title_row);
	echo '<h3>'.$id.'. '.ucwords($headline).'.</h3>'."\n\n";
}


// this is the list of portfolio...
echo '<ul id="portfolio_navigation">'."\n";
$i=0;
$portfolio_list = mysqli_query($dbase, "SELECT id,headline FROM portfolio ORDER BY id");
while($portfolio_list_row = mysqli_fetch_assoc($portfolio_list))
{
	$i++;
	extract($portfolio_list_row);
	$active = '';
	
	$headline_url = strtolower(str_replace(array(' ','.'),array('-',''),$headline));
	if($headline_url==$services)
	{
		$active = ' id="active"';
	}
	
	echo '<li'.$active.'><a href="portfolio/'.$headline_url.'/" title="'.ucwords($headline).'"><span></span>'.$id.'</a></li>'."\n";
}
echo '</ul>'."\n\n";


// this is the main content...
$portfolio = mysqli_query($dbase, "SELECT id,headline,description,features,image,alt,url FROM portfolio WHERE headline LIKE '$services_search'");
while($portfolio_row = mysqli_fetch_assoc($portfolio))
{
	extract($portfolio_row);
	
	$description_output = truncate(htmlentities($description),'350');
	echo '<p id="main_text">'.$description_output.'</p>'."\n\n";
	
	$features_array = explode(',',$features);
	
	echo '<div id="extra_text">'."\n";
	echo '<h4>Features.</h4>';
	
	echo '<ul>'."\n";
	for($i=0; $i<3; $i++)
	{
		$feature_output = ucwords(trim($features_array[$i]));
		echo '<li>'.$feature_output.'</li>'."\n";
	}
	echo '</ul>'."\n\n";
	echo '</div>'."\n\n";
	
	if(!empty($image) && !empty($alt))
	{
		$image_url = 'images/portfolio/'.$image;
		list($width, $height) = getimagesize($image_url);
		
		if(!empty($url)) 
		{
			if(substr($url,0,7)!='http://')
			{
				$url  = 'http://'.$url;
			}
			$link = '<a href="'.$url.'" title="'.ucwords($headline).'">';
			$link_end = '</a>';
		}
		else {
			$link = '';
			$link_end = '';
		}
		echo $link.'<img src="'.$image_url.'" alt="'.$alt.'" height="'.$height.'px" width="'.$width.'px">'.$link_end."\n";
	}
}

?>

<!-- end of div id #content -->
</div>