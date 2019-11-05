<div id="content">

<?php
if(isset($date))
{
	$archive = TRUE;
	$sql_news = mysqli_query($dbase, "SELECT id,title,entry,date,image,alt FROM news WHERE date LIKE '$date%'");
}
else
{
	$sql_news = mysqli_query($dbase, "SELECT id,title,entry,date,image,alt FROM news ORDER BY date DESC LIMIT 0, 2");
}

if($sql_news && mysqli_num_rows($sql_news) != 0)
{
	while($news_row = mysqli_fetch_assoc($sql_news))
	{
		extract($news_row);
		$date_format = date('d.m.y',strtotime($date));
		$title_output = ucwords($title);
		
		echo '<div>'."\n";
		echo '<p class="date">'.$date_format.'</p>'."\n";
		echo '<h3>'.$title_output.'.</h3>'."\n";
	
		if(!empty($image) && !empty($alt))
		{
			$image_url = 'images/news/'.$image;
			list($width, $height) = getimagesize($image_url);
			echo '<img src="/'.$image_url.'" alt="'.$alt.'" height="'.$height.'px" width="'.$width.'px">'."\n";
		}
		echo '<p>'.$entry.'</p>'."\n";
		echo '</div>'."\n\n";
	}
}
else
{
	echo '<p id="no_news">Sorry, no news available for this date.</p>';
}
?>

<!-- end of div id #content -->
</div>

<?php
if($section=='news')
{
	echo "\n\n".'<div id="popup">'."\n";
	
	echo '<h3>News Archives</h3>'."\n";
	
	echo '<ul id="menu">'."\n";
	
	$sql_news_archives = mysqli_query($dbase, "SELECT id,title,entry,date,image,alt FROM news ORDER BY date DESC LIMIT 2, 6");
	while($news_archives_row = mysqli_fetch_assoc($sql_news_archives))
	{
		extract($news_archives_row);
		$date = date('Y-m-d',strtotime($date));
		$title_output = ucwords($title);
		echo '<li><a href="/'.$date.'" title="View the '.$title_output.' article">'.$title_output.' <span>'.$date.'</span></a></li>'."\n";
	}

	echo '</ul>'."\n";
	echo '</div>'."\n";
}
?>