<?php

$q = new Queue();
var_dump($q->push(1));
var_dump($q->push([1,2]));
var_dump($q->push(12.11));
var_dump($q->push('string'));

var_dump($q->first());
var_dump($q->pull());
var_dump($q->first());

var_dump($q->count());
var_dump($q->isEmpty());

var_dump($q->traverse());

ReflectionClass::export("Queue");
