<?php

	$accepted_main_domains_with_tld = array('youtube.com', 'ytimg.com');
	$url_without_protocol = substr($_GET['url'], strpos($_GET['url'], '//') + 2);
	$url_without_protocol_start_position = strpos($url_without_protocol, '.') + 1;
	$main_domain_with_tld = substr($url_without_protocol, $url_without_protocol_start_position, strpos($url_without_protocol, '/') - $url_without_protocol_start_position);
	
	if (!in_array($main_domain_with_tld, $accepted_main_domains_with_tld)) {
		return;
	}	

	if (ini_get('allow_url_fopen')) {
		$handle = fopen($_GET['url'], 'rb');
		if (function_exists('stream_get_contents')) {
			$contents = stream_get_contents($handle);
		} else {
			$contents = '';
			while (!feof($handle)) {
				$contents .= fread($handle, 8192);
			}
		}
		fclose($handle);

		header('Content-Type: image/jpeg');
		echo $contents;
	}

?>