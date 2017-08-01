<?php
//var_dump(cpp_hello_world2(1234, "test"));
echo "hello world\n";

#cpp_ext_test(1234, 42.33, "jjj");
#cpp_ext_test2(["abc"]);
#myClass::test();


//ReflectionClass::export("CppClass");
// exit;
//var_dump($r);

//CppClass::test("xxx");


$obj = new \CppClass;
$obj->name[] = "value";
var_dump($obj->name);
var_dump($obj->test2());
echo "Countable interface: ".count($obj)."\n";

$obj2 = new \CppClass;
var_dump($obj2->name);
var_dump($obj2->test2());
