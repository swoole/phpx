<?php
/**
 * @generate-legacy-arginfo
 * @generate-function-entries
 */

namespace Gtk;

class Application
{
    public function __construct(string $glade_file, string $window_name)
    {
    }

    public function find(string $object): mixed
    {
    }

    public function run(): void
    {
    }

    public function setTitle(mixed $value): void
    {
    }

    public function setIcon(string $icon): mixed
    {
    }

    public function quit(): mixed
    {
    }
}

class Widget
{
    public function on(string $event, callable $fn): void
    {
    }
}

class Entry
{
    public function getText(): string
    {
    }

    public function setText(string $text): void
    {
    }

}

class Label
{
    public function getText(): string
    {
    }

    public function setText(string $text): void
    {
    }
}
