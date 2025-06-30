<?php

namespace Phpx;


class Tool
{
    public static array $ignoreAttrs = [
        '__builtins__',
        '__all__',
        '__loader__',
        '__cached__',
        '__file__',
        '__spec__',
        '__weakref__',
        '__sizeof__',
    ];

    protected const KEYWORDS = [
        'and',
        'break',
        'continue',
        'for',
        'global',
        'if',
        'list',
        'match',
        'or',
        'return',
        'try',
        'while',
        'yield',
    ];

    public static function render($tplFile, $outFile, $vars, $prefix = ''): void
    {
        extract($vars);
        ob_start();
        include $tplFile;
        $out = $prefix . ob_get_clean();

        $dir = dirname($outFile);
        if (!is_dir($dir)) {
            mkdir($dir, 0777, true);
        }

        file_put_contents($outFile, $out);
    }

    public static function valueToCppRepr($v): ?string
    {
        if (is_string($v)) {
            $v = str_replace(
                ["\\", "\n", "\r", "\t", "\v", "\x00", "\""],
                ["\\\\", "\\n", "\\r", "\\t", "\\v", "\\x00", "\\\""],
                $v
            );
            return "\"$v\"";
        } elseif (is_numeric($v)) {
            if (is_infinite($v)) {
                return "std::INFINITY";
            } elseif (is_nan($v)) {
                return "std::NAN";
            } elseif ($v === PHP_INT_MIN) {
                return "LONG_MIN";
            } elseif ($v === PHP_INT_MAX) {
                return "LONG_MAX";
            } else {
                return $v;
            }
        } elseif (is_bool($v)) {
            return $v ? 'true' : 'false';
        } elseif (is_array($v)) {
            if (empty($v)) {
                return '{}';
            }
            if (array_is_list($v)) {
                return '{' . implode(', ', array_map([self::class, 'valueToCppRepr'], $v)) . '}';
            } else {
                return '{' . implode(', ', array_map(
                    function ($k, $v) {
                        '{ '. self::valueToCppRepr($k) . ', ' . self::valueToCppRepr($v) . ' }';
                    },
                    array_keys($v),
                    $v
                )) . '}';
            }
        } else {
            return '{}';
        }
    }
}
