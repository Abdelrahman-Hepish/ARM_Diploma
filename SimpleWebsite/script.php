<?php

if ( isset($_GET['status']) )
{
	if ( $_GET['status'] == 'on' )
	{
		header ("Location: on.html");
	}
	
	elseif ( $_GET['status'] == 'off' )
	{
		header ("Location: off.html");
	}
}



?>