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
    protected ReflectionExtension $extRef;
    public static string $rootDir = '';
    /**
     * @var array<string, int>
     */
    static protected array $literalString = [];
    static protected int $literalStringIndex = 0;

    const array BUILTIN_FUNCTIONS = [
        'sizeof',
        'exit',
        'constant',
        'assert',
        'strlen',
        'strnatcmp',
        'strnatcasecmp',
    ];

    const array BUILTIN_CLASSES = [
        'ArrayIterator',
    ];

    const array KEYWORDS = [
        'delete', 'auto', 'setbit', 'throw', 'getThis', 'namespace', 'class', 'default', 'case', 'break', 'continue',
        'return',
        'enum',
        'char',
        'operator',
    ];

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

    public static function makeLiteralString(): void
    {

        $code = "#include <phpx.h>\n";
        $code .= "extern php::Variant LITERAL_STRING[".count(self::$literalString). "];\n";

        file_put_contents(self::getRootDir() . '/include/phpx_literal_string.h', $code);

        $code = "#include <phpx.h>\n";
        $code .= "php::Variant LITERAL_STRING[" . count(self::$literalString) . "] = {\n";
        foreach (self::$literalString as $symbol => $index) {
            $code .= "\t{ ZEND_STRL(\"" . self::escapeString($symbol) . "\"), true }, // [$index]\n";
        }
        $code .= "};\n";

        file_put_contents(self::getRootDir() . '/src/core/literal_string.cc', $code);
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
        shell_exec("clang-format -i " . $outFile);
    }

    public static function escapeString(string $string): string
    {
        return addcslashes($string, "\\\"\n\r\t\v\f\0\x01..\x1f\x7f..\xff");
    }

    public static function valueToCppRepr($v, bool $byRef = false): ?string
    {
        if (is_string($v)) {
            $v = self::escapeString($v);
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
                if ($byRef) {
                    return 'getEmptyArrayRef()';
                } else {
                    return 'Array{}';
                }
            }
            if (array_is_list($v)) {
                return 'Array{' . implode(', ', array_map([self::class, 'valueToCppRepr'], $v)) . '}';
            } else {
                return 'Array{' . implode(', ', array_map(
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
        $this->extRef = new ReflectionExtension($this->extension);
    }

    static public function addLiteralString(string $symbol): string
    {
        if (!isset(self::$literalString[$symbol])) {
            self::$literalString[$symbol] = self::$literalStringIndex++;
        }
        return 'LITERAL_STRING[' . self::$literalString[$symbol] . ']';
    }

    public function export(): void
    {
        $ext = strtolower($this->extension);

        $functions = $this->getFunctions();
        $constants = $this->getConstants();
        $classes = $this->getClasses();

        if (!empty($constants)) {
            self::render(
                __DIR__ . '/templates/const-impl.tpl',
                self::$rootDir . '/src/const/' . $ext . '.cc',
                compact('constants')
            );

            self::render(
                __DIR__ . '/templates/const-decl.tpl',
                self::$rootDir . '/include/const/' . $ext . '.h',
                compact('constants')
            );
        }

        if (!empty($functions)) {
            self::render(
                __DIR__ . '/templates/func-impl.tpl',
                self::$rootDir . '/src/func/' . $ext . '.cc',
                compact('functions')
            );

            self::render(
                __DIR__ . '/templates/func-decl.tpl',
                self::$rootDir . '/include/func/' . $ext . '.h',
                compact('functions')
            );
        }

        if (!empty($classes)) {
            self::render(
                __DIR__ . '/templates/class-impl.tpl',
                self::$rootDir . '/src/class/' . $ext . '.cc',
                compact('classes', 'ext')
            );

            self::render(
                __DIR__ . '/templates/class-decl.tpl',
                self::$rootDir . '/include/class/' . $ext . '.h',
                compact('classes', 'ext')
            );
        }
    }

    protected function getFunctions(): array
    {
        $functions = [];
        foreach ($this->extRef->getFunctions() as $function) {
            $name = $function->getName();
            if (in_array($name, self::BUILTIN_FUNCTIONS)) {
                continue;
            }
            self::nameSafety($name);

            [$args, $call, $args_impl, $variadic] = $this->getArgs($function->getParameters());
            $symbol = $function->getName();
            $functions[$name] = [
                'args' => $args ? implode(', ', $args) : '',
                'args_impl' => $args ? implode(', ', $args_impl) : '',
                'call' => $call ? '{' . implode(', ', $call) . '}' : '{}',
                'symbol' => self::addLiteralString($symbol),
                'variadic' => $variadic,
            ];
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
        $name = str_replace('\\', '_', $name);
    }

    /**
     * @param array<ReflectionParameter> $params
     * @return array
     */
    protected function getArgs(array $params): array
    {
        $args_impl = $call = $args = [];
        $variadic = false;
        foreach ($params as $param) {
            $arg_name = $param->name;
            self::nameSafety($arg_name);
            self::changeCasePascal2Snake($arg_name);
            $type = 'const ' . ($param->isPassedByReference() ? 'Reference' : 'Variant');

            if ($param->isVariadic()) {
                $variadic = true;
                $args[] = 'const Args&... ' . $arg_name;
                $call[] = $arg_name . '...';
                $args_impl[] = 'const Args&... ' . $arg_name;
                break;
            } elseif ($param->isOptional()) {
                if ($param->isDefaultValueAvailable()) {
                    $default_value = $param->getDefaultValue();
                    $args[] = "$type &$arg_name = " . self::valueToCppRepr($default_value, $param->isPassedByReference());
                } else {
                    $args[] = "$type &$arg_name = " . '{}';
                }
            } else {
                $args[] = "$type &$arg_name";
            }
            $args_impl[] = "$type &$arg_name";
            $call[] = $param->isPassedByReference() ? '&' . $arg_name : $arg_name;
        }

        return [
            $args,
            $call,
            $args_impl,
            $variadic,
        ];
    }

    protected function getClasses(): array
    {
        $classes = [];
        $list = $this->extRef->getClasses();
        foreach ($list as $className => $ref) {
            $methods = [];
            if (in_array($className, self::BUILTIN_CLASSES)) {
                $className = '_' . $className;
            }

            $classSymbol = $ref->getName();
            $className = str_replace("\\", '_', $className);
            if ($ref->isAbstract() || $ref->isInterface() || $ref->isTrait()) {
                continue;
            }

            foreach ($ref->getMethods() as $method) {
                if (!$method->isPublic() || $method->isDestructor()) {
                    continue;
                }
                $params = $method->getParameters();
                $name = $method->getName();

                if ($method->isConstructor()) {
                    $name = $className;
                }
                self::nameSafety($name);

                [$args, $call, $args_impl, $variadic] = $this->getArgs($params);
                $symbol = $method->isStatic() ? $className . '::' . $method->getName() : $method->getName();

                $info =[
                    'args' => $args ? implode(', ', $args) : '',
                    'args_impl' => $args ? implode(', ', $args_impl) : '',
                    'call' => $call ? '{' . implode(', ', $call) . '}' : '{}',
                    'static' => $method->isStatic(),
                    'ctor' => $method->isConstructor(),
                    'symbol' => self::addLiteralString($symbol),
                    'variadic' => $variadic,
                ];

                $code = '';
                if (!$info['ctor']) {
                    $code .= 'Variant ';
                }
                $code .= $variadic ? $name : $className . '::' . $name;
                $code .= "({$info['args_impl']}) {" . "\n";
                 if ($info['ctor']) {
                    $classSymbolLiteralString = self::addLiteralString($classSymbol);
                     $code .= "\tthis_ = newObject({$classSymbolLiteralString}, {$info['call']});\n";
                 } elseif ($info['static']) {
                     $code .= "\treturn php::call({$info['symbol']}, {$info['call']});\n";
                 } else {
                     $code .= "\treturn this_.exec({$info['symbol']}, {$info['call']});\n";
                 }
                $code .= "}\n";
                 $info['impl_code'] = $code;
                $methods[$name] = $info;
            }

            if (empty($constants) and empty($methods)) {
                continue;
            }

            $classes[$className] = [
                'methods' => $methods,
                'class' => self::addLiteralString($classSymbol),
            ];
        }
        return $classes;
    }

    protected function getConstants(): array
    {
        $constants = [];
        if ($this->extRef->getConstants()) {
            foreach ($this->extRef->getConstants() as $name => $value) {
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
