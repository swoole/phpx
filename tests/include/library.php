<?php

class TestClass
{
    static int $propInt = 1990018900;
    static string $propString = "Hello, World!";

    public function test(): string
    {
        return 'parent test';
    }
}

class TestClass2 extends TestClass
{
    public function test(): string
    {
        return 'child test';
    }
}
