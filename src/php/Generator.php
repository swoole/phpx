<?php

declare(strict_types=1);

namespace Phpx;

use ReflectionClass;
use ReflectionException;
use ReflectionExtension;
use ReflectionMethod;
use ReflectionParameter;
use RuntimeException;

class Generator
{
    protected string $extension;
    protected ReflectionExtension $rf_ext;
    public static string $rootDir = '';

    const BUILTIN_FUNCTIONS = [
        'sizeof',
    ];

    const BUILTIN_CLASSES = [
        'ArrayIterator',
    ];

    const KEYWORDS = ['delete', 'auto', 'setbit', 'throw', 'getThis', 'namespace', 'class', 'default'];

    public static function getRootDir(): string
    {
        if (self::$rootDir === '') {
            self::$rootDir = dirname(__DIR__, 2);
        }
        return self::$rootDir;
    }

    /**
     * @param $extension
     * @return void
     * @throws RuntimeException
     * @throws ReflectionException
     */
    public static function make($extension): void
    {
        self::getRootDir();
        $generator = new self($extension);
        $generator->export();
    }

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

    public static function makeArgs(int $n): string
    {
        $code = '';
        for ($j = 1; $j <= $n; $j++) {
            $code .= 'const Variant &v' . ($j == $n ? $j : $j . ', ');
        }
        return $code;
    }

    public static function makeCaller(): void
    {
        $DELIMITER = '/* generator */';
        $header_file = self::getRootDir() . '/include/phpx.h';
        $src = file_get_contents($header_file);
        $r = preg_match('/\#define\s+PHPX_MAX_ARGC\s+(\d+)/', $src, $match);
        if (!$r) {
            exit("no PHPX_MAX_ARGC\n");
        }

        $maxArgc = $match[1];
        self::render(__DIR__ . '/templates/caller.tpl', self::getRootDir() . '/src/core/caller.cc', compact('maxArgc'));

        $exec_function_code = PHP_EOL;
        $exec_method_code = PHP_EOL;
        $new_object_code = PHP_EOL;
        for ($i = 1; $i <= $maxArgc; $i++) {
            $exec_function_code .= 'Variant operator()(' . self::makeArgs($i) . ') const;' . PHP_EOL;
            $exec_method_code .= 'Variant exec(const Variant &fn, ' . self::makeArgs($i) . ');' . PHP_EOL;
            $new_object_code .= "extern Object newObject(const char *name, " . self::makeArgs($i) . ");" . PHP_EOL;
        }

        $parts = explode($DELIMITER, $src);
        $src = implode($DELIMITER, [
            $parts[0],
            $exec_function_code,
            $parts[2],
            $exec_method_code,
            $parts[4],
            $new_object_code,
            $parts[6],
        ]);
        file_put_contents($header_file, $src);
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
                return strval($v);
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

    /**
     * AbstractStubGenerator constructor.
     *
     * @throws RuntimeException
     * @throws ReflectionException
     */
    private function __construct($extension)
    {
        if (!extension_loaded($extension)) {
            throw new RuntimeException("Extension $extension not enabled or not installed.");
        }

        $this->extension = $extension;
        $this->rf_ext = new ReflectionExtension($this->extension);
    }

    public function export(): void
    {
        $ext = strtolower($this->extension);

        $constants = $this->getConstants();
        if (!empty($constants)) {
            self::render(
                __DIR__ . '/templates/const-impl.tpl',
                self::$rootDir . '/src/const/' . $ext . '.cc',
                compact('constants')
            );

            self::render(
                __DIR__ . '/templates/const-declare.tpl',
                self::$rootDir . '/include/const/' . $ext . '.h',
                compact('constants')
            );
        }

        $functions = $this->getFunctions();
        if (!empty($functions)) {
            self::render(
                __DIR__ . '/templates/func-impl.tpl',
                self::$rootDir . '/src/func/' . $ext . '.cc',
                compact('functions')
            );

            self::render(
                __DIR__ . '/templates/func-declare.tpl',
                self::$rootDir . '/include/func/' . $ext . '.h',
                compact('functions')
            );
        }

        $classes = $this->getClasses();
        if (!empty($classes)) {
            self::render(
                __DIR__ . '/templates/class-impl.tpl',
                self::$rootDir . '/src/class/' . $ext . '.cc',
                compact('classes', 'ext')
            );

            self::render(
                __DIR__ . '/templates/class-declare.tpl',
                self::$rootDir . '/include/class/' . $ext . '.h',
                compact('classes', 'ext')
            );
        }
    }

    protected function getFunctions(): array
    {
        $functions = [];
        foreach ($this->rf_ext->getFunctions() as $function) {
            $fn_name = $function->getName();
            if (in_array($fn_name, self::BUILTIN_FUNCTIONS)) {
                continue;
            }
            $functions[] = $fn_name;
        }
        return $functions;
    }

    public static function changeCasePascal2Snake(string &$name): void
    {
        $name = strtolower(preg_replace('/(?<!^)[A-Z]/', '_$0', $name));
    }

    public static function nameSafety(string &$name): void
    {
        if (in_array($name, self::KEYWORDS)) {
            $name = '_' . $name;
        }
    }

    protected function getArgs($params): array
    {
        $args_impl = $call = $args = [];
        foreach ($params as $param) {
            $arg_name = $param->name;
            self::nameSafety($arg_name);
            self::changeCasePascal2Snake($arg_name);
            $type = 'const Variant';

            if ($param->isOptional()) {
                if ($param->isDefaultValueAvailable()) {
                    $default_value = $param->getDefaultValue();
                    if (is_array($default_value)) {
                        $type = 'const Array';
                    } elseif (is_object($default_value)) {
                        $type = 'const Object';
                    }
                    $args[] = "$type &$arg_name = " . self::valueToCppRepr($default_value);
                } else {
                    $args[] = "$type &$arg_name = " . '{}';
                }
            } else {
                $args[] = "$type &$arg_name";
            }
            $args_impl[] = "$type &$arg_name";
            $call[] = $arg_name;
        }

        return [
            $args,
            $call,
            $args_impl,
        ];
    }

    protected function getClasses(): array
    {
        $classes = [];
        $list = $this->rf_ext->getClasses();
        foreach ($list as $className => $ref) {
            $methods = [];
            $className = str_replace("\\", '_', $className);
            if (in_array($className, self::BUILTIN_CLASSES)) {
                $className = '_' . $className;
            }

            if ($ref->isAbstract() || $ref->isInterface() || $ref->isTrait()) {
                continue;
            }

            foreach ($ref->getMethods() as $method) {
                if (!$method->isPublic() || $method->isDestructor()) {
                    continue;
                }
                $params = $method->getParameters();
                $fn_name = $method->getName();

                if ($method->isConstructor()) {
                    $fn_name = $className;
                }
                self::nameSafety($fn_name);

                [$args, $call, $args_impl] = $this->getArgs($params);
                $static = $method->isStatic();
                if (!$static) {
                    array_unshift($call, '');
                }
                $methods[$fn_name] = [
                    'args' => $args ? implode(', ', $args) : '',
                    'args_impl' => $args ? implode(', ', $args_impl) : '',
                    'call' => $call ? implode(', ', $call) : '',
                    'static' => $method->isStatic(),
                    'ctor' => $method->isConstructor(),
                    'name' => $method->getName(),
                ];
            }

            if (empty($constants) and empty($methods)) {
                continue;
            }

            $classes[$className] = [
                'methods' => $methods,
                'class' => self::valueToCppRepr($ref->getName()),
            ];
        }
        return $classes;
    }

    protected function getConstants(): array
    {
        $constants = [];
        if ($this->rf_ext->getConstants()) {
            foreach ($this->rf_ext->getConstants() as $name => $value) {
                if (is_array($value) or is_object($value) or is_resource($value)) {
                    continue;
                }
                $ext = strtolower($this->extension);
                if ($ext === 'pcntl' or $ext === 'standard' or $ext === 'core' or $ext === 'random') {
                    continue;
                }
                if ($ext === 'sockets' and !str_starts_with($name, 'SOCKET_')) {
                    continue;
                }
                self::nameSafety($name);
                $repr = self::valueToCppRepr($value);
                if (is_string($value)) {
                    $constants[$name] = "ZEND_STRL(" . $repr . "), true";
                } else {
                    $constants[$name] = $repr;
                }
            }
        }
        return $constants;
    }
}
