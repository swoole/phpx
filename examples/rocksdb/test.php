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
$ttl = 3;
$time = 5;
$db_name = __DIR__."/xxxxdb/test6";
$r = new RocksDB($db_name, $config['options'], $config['readoptions'], $config['writeoptions']);

// $res = $r->get("7Lfu2yqkPa_0");
// echo "get {$key} res:".var_export($res,1)."\n";

// $res = $r->get("7Lfu2yqkPa_0.2");
// echo "get {$key} res:".var_export($res,1)."\n";

// $res = $r->get("index_7Lfu2yqkPa");
// echo "get {$key} res:".var_export($res,1)."\n";
// $res = $r->delete($key);
// echo "delete {$key} res:".var_export($res,1)."\n";
// $key = "key";
// $val = "val";
// $res = $r->put($key,$val);
// echo "put {$key}:{$val} res:".var_export($res,1)."\n";
// $res = $r->get($key);
// echo "get {$key} res:".var_export($res,1)."\n";

// $val1 = "val1";
// $res = $r->merge($key,"1111111");
// echo "merge {$key} :{$val1} res:".var_export($res,1)."\n";
// $res = $r->get($key);
// echo "after merge get {$key} res:".var_export($res,1)."\n";
// var_dump(RocksDB::$version);

$key = "key";
$val = "111";
// $res = $r->put($key,$val);
// echo "put {$key}:{$val} res:".var_export($res,1)."\n";
// $res = $r->get($key);
// echo "get {$key} res:".var_export($res,1)."\n";
// $res = $r->delete($key);
// echo "delete {$key} res:".var_export($res,1)."\n";
$res = $r->merge($key, "v1");
echo "get {$key} res:".$r->get($key)."\n";
$res = $r->merge($key, "v2");
echo "get {$key} res:".$r->get($key)."\n";
$res = $r->merge($key, "v3");
echo "get {$key} res:".$r->get($key)."\n";
