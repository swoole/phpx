<?php

abstract class TestAbstract {
    abstract public function test(): string;
}

class TestClass
{
    static int $propInt = 1990018900;
    static string $propString = "Hello, World!";

    protected bool $propBool = true;

    public function test(): string
    {
        return 'parent test';
    }

    public function fun()
    {
        return pi();
    }
}

class TestClass2 extends TestClass
{
    public array $propArray = [1, 2, 3, 4, 5];

    public function test(): string
    {
        return 'child test';
    }
}
