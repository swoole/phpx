<?php

$q = new Queue();
var_dump($q->push(1));
var_dump($q->push([1,2]));
var_dump($q->push(12.11));
var_dump($q->push('string'));

var_dump($q->first());
var_dump($q->pull());
var_dump($q->first());


echo "count\n-----------------------------------\n";
var_dump($q->count());

var_dump($q->isEmpty());


echo "traverse\n-----------------------------------\n";
//var_dump($q->traverse());

while (!$q->isEmpty()) {
    var_dump($q->first());
    var_dump($q->pull());
}
