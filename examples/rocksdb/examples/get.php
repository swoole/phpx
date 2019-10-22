<?php
$config = array(
		'options' => array(
				'create_if_missing' => true,    // if the specified database didn't exist will create a new one
				'error_if_exists' => false,   // if the opened database exsits will throw exception
				'paranoid_checks' => false,
				'paranoid_checks' => false,
				'merge_operator' => ',',
		),
		/* default readoptions */
		'readoptions' => array(
				'verify_check_sum' => false,
				'fill_cache' => true,
		),
		/* default write options */
		'writeoptions' => array(
				'sync' => false
		),
);
$db_name = dirname(__DIR__)."/db/test6";
$r = new RocksDB($db_name, $config['options'], $config['readoptions'], $config['writeoptions']);

$key = "key_test";
$r->put($key, "hello world");
$res = $r->get($key);
echo "get {$key} res:".var_export($res,1)."\n";
