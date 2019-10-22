<?php
$b = BloomFilter::load(__DIR__."/bf.data");

var_dump($b->has("test"));
var_dump($b->has("hello"));
var_dump($b->has("world"));
var_dump($b->has(" world "));
var_dump($b->has("rango"));
var_dump($b->has("xxxxxxxxxxxxxxxxxxxxxxx"));
var_dump($b->has("rango12"));
var_dump($b->has("me"));

