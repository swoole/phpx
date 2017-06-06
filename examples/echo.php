<?php
var_dump(cpp_ext_test(1234, 42.33, "jjj"));
var_dump(cpp_ext_test2(["abc", "456"], false));
var_dump(myClass::test());

$o = new myClass;
$o->pset();
var_dump($o);
var_dump($o->pget());
