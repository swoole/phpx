<?php
$b = new BloomFilter(1024);
echo "key hello\n";

$b->add("hello");
$b->add("world");
$b->add("rango");

var_dump($b->has("test"));
var_dump($b->has("hello"));
var_dump($b->has("world"));
var_dump($b->has(" world "));
var_dump($b->has("rango"));
var_dump($b->has("xxxxxxxxxxxxxxxxxxxxxxx"));
var_dump($b->has("rango12"));
var_dump($b->has("me"));

$b->dump(__DIR__."/bf.data");
