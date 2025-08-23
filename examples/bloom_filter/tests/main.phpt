--TEST--
BloomFilter: basic usage
--SKIPIF--
--FILE--
<?php
if (!is_file(__DIR__."/bf.data")) {
    $b->add("hello");
    $b->add("world");
    $b->add("rango");
    $b = new BloomFilter(1024);
    assert($b->dump(__DIR__."/bf.data"));
} else {
    $b = BloomFilter::load(__DIR__."/bf.data");
}

assert(!$b->has("test"));
assert($b->has("hello"));
assert($b->has("world"));
assert(!$b->has(" world "));
assert($b->has("rango"));
assert(!$b->has("xxxxxxxxxxxxxxxxxxxxxxx"));
assert(!$b->has("rango12"));
assert(!$b->has("me"));

echo "DONE\n";
?>
--EXPECT--
DONE
