<?php

declare(strict_types=1);

namespace PhpxTool;

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
    protected const KEYWORDS = [
        'assert' => 1,
        'del' => 1,
        'yield' => 1,
        'import' => 1,
        'from' => 1,
        'and' => 1,
        'or' => 1,
        'is' => 1,
    ];

    public static string $rootDir = '';

    /**
     * @param $extension
     * @return void
     * @throws RuntimeException
     * @throws ReflectionException
     */
    public static function make($extension): void
    {
        if (self::$rootDir === '') {
            self::$rootDir = dirname(__DIR__) . '/output/';
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
        $constants = $this->getConstants();
        $functions = $this->getFunctions();
        $classes = $this->getClasses();

        $mod = strtolower($this->extension);
        $mod = $mod === 'standard' ? 'std' : $mod;

        Tool::render(
            dirname(__DIR__) . '/templates/py-mod.tpl',
            self::$rootDir . '/' . $mod . '.py',
            compact('constants', 'functions', 'classes')
        );
    }

    /**
     * @return string
     */
    public function getVersion(): string
    {
        return $this->rf_ext->getVersion();
    }

    protected function getConstants(): array
    {
        $constants = [];
        if ($this->rf_ext->getConstants()) {
            foreach ($this->rf_ext->getConstants() as $name => $value) {
                // Duplicates the module name and should be deleted.
                $py_name = $name;
                if (str_starts_with(strtolower($py_name), $this->extension . '_')) {
                    $py_name = substr($py_name, strlen($this->extension) + 1);
                    // After replacement, it starts with a number, which is not a valid symbol name. Abandon replacement.
                    if (is_numeric($py_name[0])) {
                        $py_name = $name;
                    }
                }
                $constants[$py_name] = Tool::valueToRepr($value, true);
            }
        }
        return $constants;
    }

    /**
     * @param ReflectionParameter $parameter
     * @return string|null
     */
    protected function getDefaultValue(ReflectionParameter $parameter): ?string
    {
        if ($parameter->isDefaultValueAvailable()) {
            $default_value = $parameter->getDefaultValue();
            return Tool::valueToRepr($default_value, true);
        } else {
            return 'None';
        }
    }

    public static function changeCasePascal2Snake(string $name): string
    {
        return strtolower(preg_replace('/(?<!^)[A-Z]/', '_$0', $name));
    }

    protected function getArgs($params): array
    {
        $call = $args = [];
        foreach ($params as $param) {
            $arg_name = '_' . self::changeCasePascal2Snake($param->name);
            if ($param->isOptional()) {
                $args[] = "$arg_name=" . $this->getDefaultValue($param);
            } else {
                $args[] = $arg_name;
            }
            $call[] = $arg_name;
        }

        return [
            $args,
            $call,
        ];
    }

    protected function getFunctions(): array
    {
        $functions = [];
        foreach ($this->rf_ext->getFunctions() as $function) {
            $params = $function->getParameters();
            $fn_name = $function->getName();
            $fn_name_safe = $fn_name;
            // Duplicates the module name and should be deleted.
            if (str_starts_with($fn_name_safe, $this->extension . '_')) {
                $fn_name_safe = substr($fn_name_safe, strlen($this->extension) + 1);
            }
            // namespace function
            if (str_contains($fn_name_safe, '\\')) {
                $ns = explode('\\', strtolower($fn_name_safe));
                $fn_name_safe = implode('_', array_slice($ns, 1));
                $fn_name = str_replace('\\', '\\\\', $fn_name);
            }
            if (array_key_exists($fn_name_safe, self::KEYWORDS)) {
                $fn_name_safe = '_' . $fn_name_safe;
            }
            [$args, $call] = $this->getArgs($params);
            $functions[$fn_name_safe] = [
                'args' => implode(', ', $args),
                'call' => "return phpy.call('$fn_name', " . implode(', ', $call) . ")\n",
            ];
        }
        return $functions;
    }

    protected function getClasses(): array
    {
        $classes = [];
        $list = $this->rf_ext->getClasses();
        foreach ($list as $className => $ref) {
            $constants = [];
            $methods = [];
            $classNameSafe = str_replace('\\', '\\\\', $className);
            foreach ($ref->getConstants() as $name => $value) {
                $constants[$name] = Tool::valueToRepr($value, true);
            }
            foreach ($ref->getMethods(ReflectionMethod::IS_STATIC | ReflectionMethod::IS_PUBLIC) as $method) {
                $params = $method->getParameters();
                $fn_name = $method->getName();
                if (array_key_exists($fn_name, self::KEYWORDS)) {
                    $py_name = '_' . $fn_name;
                } else {
                    $py_name = $fn_name;
                }
                [$args, $call] = $this->getArgs($params);
                if (!$method->isStatic()) {
                    array_unshift($args, 'self');
                }
                $args_call = implode(', ', $call);
                if ($fn_name == '__construct') {
                    $py_name = '__init__';
                    $call = "self.__this = phpy.Object(f'$classNameSafe', $args_call)";
                } elseif ($fn_name == '__destruct') {
                    continue;
                } elseif ($method->isStatic()) {
                    $call = 'return phpy.call(f"' . $classNameSafe . '::' . $fn_name . '", ' . $args_call . ")";
                } else {
                    if ($fn_name == '__toString') {
                        $py_name = '__str__';
                    }
                    $call = 'return self.__this.call(f"' . $fn_name . '", ' . $args_call . ")";
                }
                $methods[$py_name] = [
                    'args' => implode(', ', $args),
                    'call' => $call,
                ];
            }
            // default ctor
            if (!isset($methods['__init__'])) {
                $methods['__init__'] = [
                    'args' => 'self',
                    'call' => "self.__this = phpy.Object(f'$classNameSafe')",
                ];
            }

            $ns = explode('\\', $className);
            if (count($ns) > 1) {
                $className = implode('', array_slice($ns, 1));
            }

            if (empty($constants) and empty($methods)) {
                continue;
            }

            $classes[$className] = [
                'constants' => $constants,
                'methods' => $methods,
            ];
        }
        return $classes;
    }

    protected function getProperties(ReflectionClass $class): array
    {
        $properties = [];
        foreach ($class->getProperties(ReflectionMethod::IS_PUBLIC) as $property) {
            $name = $property->getName();
            if ($property->hasDefaultValue()) {
                $default_value = Tool::valueToRepr($property->getDefaultValue(), true);
            } else {
                $default_value = 'None';
            }
            $properties[$name] = $default_value;
        }
        return $properties;
    }
}
