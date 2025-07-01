<?php

use PHPUnit\Framework\TestCase;

class BaseTest extends TestCase
{
    public function testBase()
    {
        $extensions = get_loaded_extensions();
        $this->assertContains('phpx_test', $extensions, 'phpx_test extension is not loaded');
        $this->assertTrue(class_exists('MyClass', false));
        $this->assertTrue(interface_exists('MyInterface', false));
        $this->assertTrue(defined('PHPX_CONST_INT'));
        $this->assertEquals(PHPX_CONST_LONG, 10002);
        $this->assertEquals(PHPX_CONST_FLOAT, 199.188);
        $this->assertEquals(PHPX_CONST_BOOL, true);
        $this->assertEquals(PHPX_CONST_CSTR, "hello world");
        $this->assertEquals(PHPX_CONST_STR, "hello world");
    }

    public function testObject() {
        $o = new myClass;
        $o->pset();
        $this->assertEquals('MyClass', get_class($o), 'Object is not an instance of MyClass');
        $str = $o->pget();
        $this->assertTrue(is_string($str), 'pget did not return a string');
        $this->assertTrue(strlen($str) > 20, 'pget returned an empty string');

        $this->assertEquals(MyClass::TEST_CONSTANT, 8888);
        $this->assertEquals($o->testProperty, 'hello world');
        $this->assertEquals($o->testPropertyInt, 9988);

        $this->assertEquals(count($o), 100);
    }

    public function testExtensionInfo() {
        $ext = new ReflectionExtension(EXT_NAME);
        ob_start();
        $ext->info();
        $info = ob_get_clean();
        $this->assertNotEmpty($info, 'Extension info is empty');
        $this->assertStringContainsString('phpx_test support', $info, 'Extension info does not contain expected string');
    }

    public function testFunction() {
        $result = cpp_ext_test(1234, 42.33, "jjj");
        $this->assertEquals($result, 1234);

        $result = cpp_ext_test2(["abc", "456"], false);
        $this->assertIsArray($result);
        $this->assertCount(2, $result);
        $this->assertEquals("abc", $result[0]);
        $this->assertEquals("efg", $result[1]);

        $result = myClass::test();
        $this->assertEquals($result, 1234.56);
    }

    public function testIniConfig() {
        $this->assertEquals(ini_get('phpx.test_val'), '9999', 'INI setting is not set correctly');
    }

    public function testClass()
    {
        $this->assertTrue(class_exists('MyClass', false));
        $this->assertTrue(class_exists('MyClassAlias', false));
        $this->assertTrue(class_exists('MyException', false));
        $this->assertTrue(class_exists('MyRuntimeException', false));
        $this->assertEquals(MyClass::TEST_CONSTANT, 8888);
        $this->assertEquals(MyClass::TEST_CONSTANT_STR, "hello world");
    }
}
