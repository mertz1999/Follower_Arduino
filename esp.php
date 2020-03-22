<?php

require './Json.php';

function scrape_insta($username) {
	$insta_source = file_get_contents('http://instagram.com/'.$username);
	$shards = explode('window._sharedData = ', $insta_source);
	$insta_json = explode(';</script>', $shards[1]); 
	$insta_array = json_decode($insta_json[0], TRUE);
	return $insta_array;
}

//Supply a username
if(isset($_GET["reza"])){
$my_account =  $_GET["reza"];
$insta_source = scrape_insta((string)$my_account);
Json::encode($insta_source);
echo $insta_source['entry_data']['ProfilePage']['0']['graphql']['user']['edge_followed_by']['count'];
}else{
    "eror";
}
?>
