<?php 
if(isset($_GET['status'])
{
	if($_GET['status'] == 'on')
	{
		echo("Led On ") ; 
		header("Location : on.html") ; 
	}else if ($_GET['status'] == 'off')
    {
		echo ("Led Off") ; 
	    header("Location : off.html") ; 
	}
}	
?>