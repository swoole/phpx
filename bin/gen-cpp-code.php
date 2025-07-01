#!/usr/bin/env php
<?php
require dirname(__DIR__) . '/vendor/autoload.php';

use Phpx\Generator;

$extensions = [
    'Core',
    'ctype',
    'curl',
    'date',
    'dom',
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
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
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

foreach ($extensions as $extension) {
    Generator::make($extension);
    $name = strtolower($extension);
    $funcDeclarationFile = $rootDir . "/include/func/{$name}.h";
    if (is_file($funcDeclarationFile)) {
        fwrite($funcHeaderFile, "\n/** extension $extension */\n" . file_get_contents($funcDeclarationFile));
        unlink($funcDeclarationFile);
    }

    $classDeclarationFile = $rootDir . "/include/class/{$name}.h";
    if (is_file($classDeclarationFile)) {
        fwrite($classHeaderFile, "#include \"class/{$name}.h\"\n");
    }

    echo "Generate C++ facade code for ext-{$extension} successfully.\n";
}
