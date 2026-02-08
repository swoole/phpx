<?php
$o = new stdClass();
$o->hello = 'world';
$ref = &$o->missing;

$ref = 'test';
var_dump($ref);
var_dump($o);
