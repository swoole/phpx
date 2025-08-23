<?php
/**
 * @generate-function-entries
 */

class rocksDB
{
    public function __construct(string $path, array $options = [], array $_readoption = [], array $_writeoption = [], int $mode =0, int $ttl = 0,  string $secondary_path = '')
    {
    }

    public function put(string $key, string $value): bool
    {
    }

    public function merge(string $key, string $value): bool
    {
    }

    public function get(string $key): string
    {
    }

    public function delete(string $key): bool
    {
    }

    public function syncWAL(): bool
    {
    }
}