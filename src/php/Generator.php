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
        'define',
        'hash',
        'hash_hmac',
        'sizeof',
        'constant',
        'ini_get',
        'crc32',
        'md5',
        'sha1',
        'exec',
    ];

    const BUILTIN_CLASSES = [
        'ArrayIterator',
    ];

    const KEYWORDS = ['delete', 'auto', 'setbit', 'throw', 'getThis', 'namespace', 'class', 'default'];

    /**
     * @param $extension
     * @return void
     * @throws RuntimeException
     * @throws ReflectionException
     */
    public static function make($extension): void
    {
        if (self::$rootDir === '') {
            self::$rootDir = dirname(__DIR__, 2);
        }
        $generator = new self($extension);
        $generator->export();
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

        $functions = $this->getFunctions();
        if (!empty($functions)) {
            Tool::render(
                __DIR__ . '/templates/func-impl.tpl',
                self::$rootDir . '/src/func/' . $ext . '.cc',
                compact('functions')
            );

            Tool::render(
                __DIR__ . '/templates/func-declare.tpl',
                self::$rootDir . '/include/func/' . $ext . '.h',
                compact('functions')
            );
        }

        $classes = $this->getClasses();
        if (!empty($classes)) {
            Tool::render(
                __DIR__ . '/templates/class-impl.tpl',
                self::$rootDir . '/src/class/' . $ext . '.cc',
                compact('classes', 'ext')
            );

            Tool::render(
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
                    $args[] = "$type &$arg_name = " . Tool::valueToCppRepr($default_value);
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
                'class' => Tool::valueToCppRepr($ref->getName()),
            ];
        }
        return $classes;
    }
}
