#!/usr/bin/env php
<?php
require dirname(__DIR__) . '/vendor/autoload.php';

use Phpx\Generator;

$extensions = [
    'bcmath',
    'bz2',
    'calendar',
    'Core',
    'ctype',
    'curl',
    'date',
    'dom',
    'exif',
    'fileinfo',
    'filter',
    'gd',
    'gettext',
    'hash',
    'iconv',
    'json',
    'libxml',
    'mbstring',
    'mysqli',
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
    'shmop',
    'SimpleXML',
    'sockets',
    'sodium',
    'SPL',
    'sqlite3',
    'standard',
    'swoole',
    'tokenizer',
    'xml',
    'xmlreader',
    'xmlwriter',
    'xsl',
    'zip',
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

shell_exec('rm -rf ' . $rootDir . '/include/class/*');
shell_exec('rm -rf ' . $rootDir . '/include/const/*');
shell_exec('rm -rf ' . $rootDir . '/include/func/*');

shell_exec('rm -rf ' . $rootDir . '/src/class/*');
shell_exec('rm -rf ' . $rootDir . '/src/const/*');
shell_exec('rm -rf ' . $rootDir . '/src/func/*');

// Pre-scan: build facade class map and dependency graph for type resolution
Generator::buildFacadeClassMap($extensions);

// Collect generated includes during the extension loop
$funcIncludes = [];
$classIncludes = [];
$constIncludes = [];

foreach ($extensions as $extension) {
    Generator::make($extension);
    $name = strtolower($extension);
    $funcDeclarationFile = $rootDir . "/include/func/{$name}.h";
    if (is_file($funcDeclarationFile)) {
        $funcIncludes[] = $name;
    }

    $classDeclarationFile = $rootDir . "/include/class/{$name}.h";
    if (is_file($classDeclarationFile)) {
        $classIncludes[] = $name;
    }

    $constDeclarationFile = $rootDir . "/include/const/{$name}.h";
    if (is_file($constDeclarationFile)) {
        $constIncludes[] = $name;
    }

    echo "Generate C++ facade code for ext-{$extension} successfully.\n";
}

// Sort include entries by extension dependency order
$extOrder = Generator::getSortedExtensionOrder();
$byExtOrder = function ($a, $b) use ($extOrder) {
    $posA = array_search($a, $extOrder);
    $posB = array_search($b, $extOrder);
    if ($posA === false) $posA = PHP_INT_MAX;
    if ($posB === false) $posB = PHP_INT_MAX;
    return $posA - $posB;
};
usort($funcIncludes, $byExtOrder);
usort($classIncludes, $byExtOrder);
usort($constIncludes, $byExtOrder);

// Write phpx_func.h
$funcHeaderFile = fopen($rootDir . '/include/phpx_func.h', "w");
fwrite($funcHeaderFile, $header);
foreach ($funcIncludes as $name) {
    fwrite($funcHeaderFile, "#include \"func/{$name}.h\"\n");
}
fclose($funcHeaderFile);

// Write phpx_class.h — convenience header that includes all class headers
$classHeaderFile = fopen($rootDir . '/include/phpx_class.h', "w");
fwrite($classHeaderFile, $header);
fwrite($classHeaderFile, "\n");
foreach ($classIncludes as $name) {
    fwrite($classHeaderFile, "#include \"class/{$name}.h\"\n");
}
fclose($classHeaderFile);

// Write phpx_const.h
$constHeaderFile = fopen($rootDir . '/include/phpx_const.h', "w");
fwrite($constHeaderFile, $header);
foreach ($constIncludes as $name) {
    fwrite($constHeaderFile, "#include \"const/{$name}.h\"\n");
}
fclose($constHeaderFile);

Generator::makeLiteralString();
