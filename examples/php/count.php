<?php
$o = new stdClass();
$o->name = "value";

$ref = & $o->name;

$ref = 'world';

unset($ref);

var_dump($o->name);
