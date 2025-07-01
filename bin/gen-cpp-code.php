#!/usr/bin/env php
<?php
require dirname(__DIR__) . '/vendor/autoload.php';

use Phpx\Generator;

$extensions = [
    'bcmath',
    'Core',
    'ctype',
    'curl',
    'date',
    'dom',
    'exif',
    'fileinfo',
    'filter',
    'gd',
    'hash',
    'iconv',
    'json',
    'libxml',
    'mbstring',
    'mysqlnd',
    'openssl',
    'pcntl',
    'pcre',
    'PDO',
    'pdo_mysql',
    'pdo_sqlite',
    'Phar',
    'posix',
    'random',
    'redis',
    'Reflection',
    'session',
    'SimpleXML',
    'sockets',
    'SPL',
    'sqlite3',
    'standard',
    'tokenizer',
    'xml',
    'xmlreader',
    'xmlwriter',
    'xsl',
    'zlib',
];

$header = <<<HEADER
/*
  +----------------------------------------------------------------------+
  | PHP-X                                                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <rango@swoole.com>                             |
  +----------------------------------------------------------------------+
*/

#pragma once

#include "phpx.h"

HEADER;

$rootDir = dirname(__DIR__);

$funcHeaderFile = fopen($rootDir . '/include/phpx_func.h', "w");
fwrite($funcHeaderFile, $header);

$classHeaderFile = fopen($rootDir . '/include/phpx_class.h', "w");
fwrite($classHeaderFile, $header);

$constHeaderFile = fopen($rootDir . '/include/phpx_const.h', "w");
fwrite($constHeaderFile, $header);

shell_exec('rm -rf ' . $rootDir . '/include/class/*');
shell_exec('rm -rf ' . $rootDir . '/include/const/*');
shell_exec('rm -rf ' . $rootDir . '/include/func/*');

shell_exec('rm -rf ' . $rootDir . '/src/class/*');
shell_exec('rm -rf ' . $rootDir . '/src/const/*');
shell_exec('rm -rf ' . $rootDir . '/src/func/*');

foreach ($extensions as $extension) {
    Generator::make($extension);
    $name = strtolower($extension);
    $funcDeclarationFile = $rootDir . "/include/func/{$name}.h";
    if (is_file($funcDeclarationFile)) {
        fwrite($classHeaderFile, "#include \"func/{$name}.h\"\n");
    }

    $classDeclarationFile = $rootDir . "/include/class/{$name}.h";
    if (is_file($classDeclarationFile)) {
        fwrite($classHeaderFile, "#include \"class/{$name}.h\"\n");
    }

    $constDeclarationFile = $rootDir . "/include/const/{$name}.h";
    if (is_file($constDeclarationFile)) {
        fwrite($constHeaderFile, "#include \"const/{$name}.h\"\n");
    }

    echo "Generate C++ facade code for ext-{$extension} successfully.\n";
}
