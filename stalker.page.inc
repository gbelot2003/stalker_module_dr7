<?php


function staker_user_page($account){

	$query = db_select('stalker', 's')
	 ->fields('s', array('stalker_uid', 'view_count'))
	 ->condition('profile_uid', $account->uid, '=')
	 ->execute();

	$list = array(
  		'#theme' => 'links',
  		'#links' => array(),
	);

	foreach($query->fetchAll() as $record):
		$viewer = user_load($record->stalker_uid);
		$count = $record->view_count;
		$name = t($viewer->name . " has see your profile " . $count ." times");
		$list['#links'][] = array('title' => $name, 'href' => 'user/'. $record->stalker_uid); // Pasamos por theme una lista
	 endforeach;

	return drupal_render($list);

}