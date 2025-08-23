--TEST--
queue: basic usage
--SKIPIF--
--FILE--
<?php

$q = new Queue();
assert($q->push(1));
assert($q->push([1,2]));
assert($q->push(12.11));
assert($q->push('string'));

assert($q->first() == 1);
assert($q->pull() == 1);
assert($q->first() == [1,2]);

assert($q->count() == 3);
assert(!$q->isEmpty());

while (!$q->isEmpty()) {
    $first = $q->first();
    assert($q->pull() == $first);
}

echo "DONE\n";
?>
--EXPECT--
DONE
