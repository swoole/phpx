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
        $this->assertTrue(defined('PHPX_TEST_EXT_VERSION'));
    }
}
