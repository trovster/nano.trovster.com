<div id="content">

<div id="contact_form">
<?php
if(isset($_POST['submit']))
{
	$error_array = array();
	$input_array = array();
	if(!empty($_POST['name']))
	{
		$name = $_POST['name'];
		$input_array[] = htmlspecialchars($name);
		$name_output = ucwords(strtolower($name));
	}
	else
	{
		$error_array[] = 'Name';
		$input_array[] = 'empty';
	}
	
	if(!empty($_POST['company']))
	{
		$company = $_POST['company'];
		$company_output = $company;
	}
	
	if(!empty($_POST['email']))
	{
		$email = $_POST['email'];
		if(preg_match('/(?:^|\s)[-a-z0-9_.]+@([-a-z0-9]+\.)+[a-z]{2,6}(?:\s|$)/i',$email))
		{
			$email_output = $email;
			$input_array[] = htmlspecialchars($email);
		}
		else
		{
			$error_array[] = 'Invalid Email Address';
			$input_array[] = htmlspecialchars($email);
		}
	}
	else
	{
		$error_array[] = 'Email';
		$input_array[] = 'empty';
	}
	
	if(!empty($_POST['subject']))
	{
		$subject = $_POST['subject'];
		$input_array[] = htmlspecialchars($subject);
		$subject_output = ucwords(strtolower($subject));
	}
	else
	{
		$error_array[] = 'Subject';
		$input_array[] = 'empty';
	}
	
	if(!empty($_POST['message']))
	{
		$message = $_POST['message'];
		$input_array[] = htmlspecialchars($message);
		$message_output = strip_tags($message);
	}
	else
	{
		$error_array[] = 'Message';
		$input_array[] = 'empty';
	}
	
	if(empty($error_array))
	{
		echo '<p id="success"><strong>Thank you very much!</strong> We will respond to you as soon as possible.</p>';
		
		$my_email = 'info@nanosite.co.uk';

		$subject_output = 'Website Query: '.$subject;
		if(!is_null($company))
		{
			$subject_output = 'Website Query: '.$subject.' ['.$company.']';
		}
		
		/* To send plain text email, you can set the Content-type header. */
		$headers  = 'MIME-Version: 1.0'."\r\n";
		$headers .= 'Content-type: text/plain; charset=utf-8'."\r\n";
		
		/* additional headers */
		$headers .= 'X-Priority: 1'."\r\n";
		$headers .= 'X-MSMail-Priority: High'."\r\n";
		$headers .= 'X-Mailer: PHP'.phpversion()."\r\n";
		$headers .= 'To: Kuldeep Nazran <'.$my_email.'>'."\r\n";
		$headers .= 'From: '.$name.' <'.$email.'>'."\r\n";
		$headers .= 'Reply-to: '.$name.' <'.$email.'>'."\r\n";
		$headers .= 'Return-path: '.$name.' <'.$email.'>'."\r\n";
		
		$message_output = $message;

		/* and now mail it */
		mail($my_email, $subject_output, $message_output, $headers);
		
	}
}

if(!isset($error_array) || !empty($error_array))
{	
	$label_output_array = array();
	$missed_array = array();
	$label_array = array('Name','Email','Subject','Message','Company');
	
	if(!isset($company))
	{
		$error_array[] = 'Company';
		$input_array[] = 'empty';
	}
	else
	{
		$input_array[] = htmlspecialchars($company);
	}
	
	foreach($label_array as $label)
	{
		$label_output = $label;
		$missed = '';
		
		if(in_array($label,$error_array))
		{
			$title = 'This input is required';
			$label_output = '<strong>'.$label.'</strong>';
			$missed = ' class="missed" title="'.$title.'"';
		}
		$label_output_array[] = $label_output;
		$missed_array[] = $missed;
	}
	
	if($error_array)
	{
		$value_output_array = array();
		foreach($input_array as $input_label)
		{
			if($input_label=='empty')
			{
				$input_label = '';
			}
			$value_output_array[] = $input_label;
		}
	}
	
	if(in_array('Invalid Email Address',$error_array))
	{
		$title = 'Invalid Email Address';
		$label_output = '<strong>Email</strong>';
		$label_output_array[1] = $label_output;
		$missed_array[1] = ' class="missed" title="'.$title.'"';
		
	}
	
	if(!isset($_POST['submit']))
	{
		//$value_output_array = array('Full Name','Valid email address','Title of message','Message contents','Not required');
	}
	
	//onfocus="if(this.value==\'Full Name\'){this.value=\'\'}"
	
	echo '<form action="contact/" method="post">'."\n";
	echo '<fieldset>'."\n";
	echo '<legend>Contact Form</legend>'."\n";
	echo '<span'.$missed_array[0].' id="name_span"><label for="name">'.$label_output_array[0].'</label><input type="text" name="name" id="name" value="'.$value_output_array[0].'" tabindex="10"></span>'."\n";
	echo '<span><label for="company">Company</label><input type="text" name="company" id="company" value="'.$value_output_array[4].'" tabindex="11"></span>'."\n";
	echo '<span'.$missed_array[1].'><label for="email">'.$label_output_array[1].'</label><input type="text" name="email" id="email" value="'.$value_output_array[1].'" tabindex="12"></span>'."\n";
	echo '<span'.$missed_array[2].'><label for="subject">'.$label_output_array[2].'</label><input type="text" name="subject" id="subject" value="'.$value_output_array[2].'" tabindex="13"></span>'."\n";
	echo '<span'.$missed_array[3].'><label for="message">'.$label_output_array[3].'</label><textarea id="message" name="message" rows="13" cols="55" tabindex="14">'.$value_output_array[3].'</textarea></span>'."\n";
	echo '<input type="submit" id="submit" name="submit" value="send">'."\n";
	echo '</fieldset>'."\n";
	echo '</form>'."\n\n";
}
?>
</div>

<h3>Address</h3>
<address>
Richmond Road<br>
Bradford, BD7 1DP
</address>

<dl>
<dt><acronym title="Telephone">tel</acronym></dt>
<dd>(01274) 235133</dd>
<dt><acronym title="Facsimile">fax</acronym></dt>
<dd>(01274) 235133</dd>
<dt>mobile</dt>
<dd>07970 952573</dd>
</dl>


<h3>Manager</h3>
<dl id="manager">
<dt>Kuldeep Nazran</dt>
<dd>info@nanosite.co.uk</dd>
</dl>

<!-- end of div id #content -->
</div>