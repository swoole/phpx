<?php

declare(strict_types=1);

namespace Phpx;

use MJS\TopSort\CircularDependencyException;
use MJS\TopSort\Implementations\ArraySort;
use ReflectionClass;
use ReflectionException;
use ReflectionExtension;
use ReflectionMethod;
use ReflectionNamedType;
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
    /**
     * @var array<string, string> PHP class name => C++ facade class name (flat, with _)
     */
    static protected array $facadeClassMap = [];
    /**
     * @var array<string, array{ns: string[], short: string}> Flat C++ class name => namespace info
     */
    static protected array $facadeClassNamespace = [];

    /**
     * @return array<string, array{ns: string[], short: string}>
     */
    public static function getFacadeClassNamespace(): array
    {
        return self::$facadeClassNamespace;
    }
    /**
     * @var array<string, string[]> C++ facade class name => list of C++ facade classes it depends on
     */
    static protected array $classDependencies = [];
    /**
     * @var array<string> Topologically sorted C++ facade class names
     */
    static public array $sortedClasses = [];
    /**
     * @var array<string, string> C++ facade class name => PHP extension name
     */
    static protected array $classToExtension = [];
    /**
     * @var array<string, bool> C++ facade class name => has PHP __construct
     */
    static protected array $classHasCtor = [];

    /**
     * Method overrides for methods whose PHP reflection signatures are too
     * complex (e.g. multiple overloads with variadic). Key is "Class::method".
     *
     * Each entry may specify:
     *  - signature: array of param descriptors [{name, type, default?}, ...]
     *    where type is a PHP type hint (string, ?int, array, ClassName, etc.).
     *    When set, these params replace the reflection-based parameters entirely.
     */
    static protected array $methodOverrides = [
        'PDO::query' => [
            'signature' => [
                ['name' => 'query', 'type' => 'string'],
                ['name' => 'fetch_mode', 'type' => '?int', 'default' => 'null'],
            ],
        ],
        'Pdo_Mysql::query' => [
            'signature' => [
                ['name' => 'query', 'type' => 'string'],
                ['name' => 'fetch_mode', 'type' => '?int', 'default' => 'null'],
            ],
        ],
        'Pdo_Sqlite::query' => [
            'signature' => [
                ['name' => 'query', 'type' => 'string'],
                ['name' => 'fetch_mode', 'type' => '?int', 'default' => 'null'],
            ],
        ],
    ];

    const array BUILTIN_TYPES = [
        'int', 'string', 'float', 'bool', 'array', 'void', 'callable',
        'mixed', 'iterable', 'object', 'never', 'true', 'false', 'null',
    ];

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

    // PHP class constant names that collide with C preprocessor macros in PHP headers.
    // These must be suffixed with _ to avoid macro expansion at compile time.
    const array MACRO_CONFLICTS = [
        'IS_STATIC',
        'NULL', 'TRUE', 'FALSE',
        'STDIN', 'STDOUT', 'STDERR',
        'NAN',
    ];

    // Extensions whose constants are prone to macro conflicts.
    // All constants from these extensions get a _ suffix instead of per-name checks.
    const array HIGH_CONFLICT_EXTENSIONS = [
        'pcntl', 'standard', 'core', 'random', 'dom',
    ];

    /**
     * Returns '_' if all constants from this extension should be suffixed,
     * '' otherwise. High-conflict extensions always suffix; for others,
     * the caller may additionally check MACRO_CONFLICTS.
     */
    protected function constSuffix(string $name): string
    {
        if (str_ends_with($name, '_')) {
            return '';
        }
        $ext = strtolower($this->extension);
        if (in_array($ext, self::HIGH_CONFLICT_EXTENSIONS)) {
            return '_';
        }
        if ($ext === 'sockets' and !str_starts_with($name, 'SOCKET_')) {
            return '_';
        }
        if (in_array($name, self::MACRO_CONFLICTS)) {
            return '_';
        }
        return '';
    }

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

    /**
     * Pre-scan all extensions to build a map of PHP class names to C++ facade class names.
     * Also scans class dependencies for topological sorting.
     * Must be called before the generation loop.
     */
    public static function buildFacadeClassMap(array $extensions): void
    {
        // First pass: build class name map (no dependency scanning yet —
        // we need the full map populated before we can resolve type names)
        foreach ($extensions as $extension) {
            if (!extension_loaded($extension)) {
                continue;
            }
            $extRef = new ReflectionExtension($extension);
            foreach ($extRef->getClasses() as $className => $ref) {
                if ($ref->isAbstract() || $ref->isInterface() || $ref->isTrait()) {
                    continue;
                }
                $cppName = $className;
                if (in_array($cppName, self::BUILTIN_CLASSES)) {
                    $cppName = $cppName . '_';
                }
                $cppName = str_replace('\\', '_', $cppName);
                self::$facadeClassMap[$className] = $cppName;
                self::$classToExtension[$cppName] = $extension;
                $parts = explode('\\', $className);
                $shortName = array_pop($parts);
                if (in_array($className, self::BUILTIN_CLASSES)) {
                    $shortName = $shortName . '_';
                }
                self::$facadeClassNamespace[$cppName] = ['ns' => $parts, 'short' => $shortName];

                // Check if class has PHP __construct (no Object constructor)
                $hasCtor = false;
                foreach ($ref->getMethods() as $method) {
                    if ($method->isConstructor()) {
                        $hasCtor = true;
                        break;
                    }
                }
                self::$classHasCtor[$cppName] = $hasCtor;
            }
        }

        // Second pass: scan dependencies now that the full class map is available
        foreach ($extensions as $extension) {
            if (!extension_loaded($extension)) {
                continue;
            }
            $extRef = new ReflectionExtension($extension);
            foreach ($extRef->getClasses() as $className => $ref) {
                if ($ref->isAbstract() || $ref->isInterface() || $ref->isTrait()) {
                    continue;
                }
                $cppName = self::$facadeClassMap[$className] ?? null;
                if ($cppName === null) continue;
                $deps = self::scanClassDependencies($ref, $cppName);
                self::$classDependencies[$cppName] = $deps;
            }
        }

        // Topological sort classes by dependency order
        // Uses Kahn's algorithm (BFS) so circular dependencies are handled gracefully:
        // when cycles prevent progress, the remaining node with fewest deps goes next.
        self::$sortedClasses = self::topologicalSort(self::$classDependencies);
    }

    /**
     * Topological sort with graceful handling of circular dependencies.
     * When cycles are detected, the remaining node with fewest remaining dependencies
     * is emitted next, ensuring classes with zero deps always come first.
     *
     * @param array<string, string[]> $depsMap class => its dependencies
     * @return string[] Sorted class names
     */
    static protected function topologicalSort(array $depsMap): array
    {
        $result = [];
        $remaining = $depsMap;

        while (!empty($remaining)) {
            // Find a node with no remaining dependencies
            $next = null;
            foreach ($remaining as $class => $deps) {
                $unresolved = array_filter($deps, fn($d) => isset($remaining[$d]));
                if (empty($unresolved)) {
                    $next = $class;
                    break;
                }
            }

            if ($next === null) {
                // Circular dependency: pick the node with the fewest remaining deps
                $minCount = PHP_INT_MAX;
                foreach ($remaining as $class => $deps) {
                    $unresolved = array_filter($deps, fn($d) => isset($remaining[$d]));
                    $cnt = count($unresolved);
                    if ($cnt < $minCount) {
                        $minCount = $cnt;
                        $next = $class;
                    }
                }
            }

            $result[] = $next;
            unset($remaining[$next]);
        }

        return $result;
    }

    /**
     * Scan a class's public methods to find parameter/return type dependencies on other Facade classes.
     * @return string[] List of C++ Facade class names this class depends on
     */
    static protected function scanClassDependencies(ReflectionClass $ref, string $cppName): array
    {
        $deps = [];
        foreach ($ref->getMethods() as $method) {
            if (!$method->isPublic() || $method->isDestructor()) {
                continue;
            }

            // Return type dependency
            $rt = $method->getReturnType() ?? $method->getTentativeReturnType();
            if ($rt instanceof ReflectionNamedType) {
                $dep = self::resolveType($rt, $cppName);
                if ($dep !== 'Variant' && $dep !== $cppName) {
                    $deps[$dep] = true;
                }
            } elseif ($rt instanceof \ReflectionUnionType) {
                foreach ($rt->getTypes() as $unionType) {
                    if ($unionType instanceof ReflectionNamedType) {
                        $dep = self::resolveType($unionType, $cppName);
                        if ($dep !== 'Variant' && $dep !== $cppName) {
                            $deps[$dep] = true;
                        }
                    }
                }
            }

            // Parameter type dependencies
            foreach ($method->getParameters() as $param) {
                $pt = $param->getType();
                if ($pt instanceof ReflectionNamedType) {
                    $dep = self::resolveType($pt, $cppName);
                    if ($dep !== 'Variant' && $dep !== $cppName) {
                        $deps[$dep] = true;
                    }
                }
            }
        }
        return array_keys($deps);
    }

    /**
     * Check whether $selfClass referencing $depClass is a back-edge in the
     * topological sort (i.e. $selfClass is defined before $depClass, so the
     * type won't be visible when the compiler reaches $selfClass).
     *
     * Classes within the same extension are generated in the same header,
     * so ordering between them is irrelevant — only cross-extension edges
     * can be back-edges.
     */
    static protected function isBackEdge(string $selfClass, string $depClass): bool
    {
        // Same-extension classes share a header, so the order doesn't matter
        $selfExt = self::$classToExtension[$selfClass] ?? '';
        $depExt = self::$classToExtension[$depClass] ?? '';
        if ($selfExt !== '' && $selfExt === $depExt) {
            return false;
        }
        $selfPos = array_search($selfClass, self::$sortedClasses);
        $depPos = array_search($depClass, self::$sortedClasses);
        return $selfPos !== false && $depPos !== false && $selfPos < $depPos;
    }

    /**
     * Compute a topologically sorted list of extension names (lowercase).
     * Extensions whose classes depend on classes from other extensions come later.
     * @return string[]
     */
    public static function getSortedExtensionOrder(): array
    {
        $extDeps = [];
        foreach (self::$classToExtension as $class => $ext) {
            $extLower = strtolower($ext);
            if (!isset($extDeps[$extLower])) {
                $extDeps[$extLower] = [];
            }
        }

        foreach (self::$classDependencies as $class => $deps) {
            $extLower = strtolower(self::$classToExtension[$class] ?? '');
            if ($extLower === '') continue;
            foreach ($deps as $dep) {
                $depExt = strtolower(self::$classToExtension[$dep] ?? '');
                if ($depExt && $depExt !== $extLower && !in_array($depExt, $extDeps[$extLower])) {
                    $extDeps[$extLower][] = $depExt;
                }
            }
        }

        $graph = new ArraySort();
        foreach ($extDeps as $ext => $deps) {
            $graph->add($ext, $deps);
        }
        try {
            return $graph->sort();
        } catch (CircularDependencyException $e) {
            return array_keys($extDeps);
        }
    }

    /**
     * Resolve a PHP type to a C++ type string for code generation.
     * Returns null when no type info is available (caller falls back to 'Variant').
     * Returns the Facade class name for classes that have a generated Facade.
     * Returns 'Variant' for PHP built-in types.
     */
    public static function resolveType(?\ReflectionNamedType $type, string $selfClass = ''): string
    {
        if ($type === null) {
            return 'Variant';
        }

        $typeName = $type->getName();

        // `self` refers to the containing class; `static` is late-bound, can't resolve
        if ($typeName === 'static') {
            return 'Variant';
        }
        if ($typeName === 'self') {
            return $selfClass ?: 'Variant';
        }

        // Built-in PHP types always map to Variant
        if (in_array($typeName, self::BUILTIN_TYPES)) {
            return 'Variant';
        }

        // Check if it's a Facade class
        if (isset(self::$facadeClassMap[$typeName])) {
            return self::$facadeClassMap[$typeName];
        }

        return 'Variant';
    }

    /**
     * Resolve a method/function return type for code generation.
     * Handles `Type | false` union types by returning the Facade type with
     * a flag indicating the call must be wrapped with a false-check.
     *
     * @return array{return_type: string, check_false: bool}
     */
    static public function resolveReturnType(?\ReflectionType $type, string $selfClass = ''): array
    {
        if ($type === null) {
            return ['return_type' => 'Variant', 'check_false' => false];
        }

        if ($type instanceof \ReflectionNamedType) {
            return ['return_type' => self::resolveType($type, $selfClass), 'check_false' => false];
        }

        if ($type instanceof \ReflectionUnionType) {
            $types = $type->getTypes();
            // Only handle `T | false` (two-type union with exactly one false)
            if (count($types) === 2) {
                $hasFalse = false;
                $otherType = null;
                $valid = true;
                foreach ($types as $t) {
                    if (!$t instanceof \ReflectionNamedType) {
                        $valid = false;
                        break;
                    }
                    if ($t->getName() === 'false') {
                        $hasFalse = true;
                    } else {
                        $otherType = $t;
                    }
                }
                if ($valid && $hasFalse && $otherType !== null) {
                    $resolved = self::resolveType($otherType, $selfClass);
                    // Only enable false-check when the resolved type is a Facade class;
                    // built-in types like `array|false` should stay as Variant with no check.
                    $checkFalse = ($resolved !== 'Variant');
                    return ['return_type' => $resolved, 'check_false' => $checkFalse];
                }
            }
        }

        return ['return_type' => 'Variant', 'check_false' => false];
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

        // Compute cross-extension includes for class headers.
        // Each class header only needs to include headers for Facade types
        // referenced as return/param types that belong to OTHER extensions.
        $classIncludes = [];
        $extLower = strtolower($this->extension);
        foreach ($classes as $className => $info) {
            // Include parent class header when extending a Facade class from another extension
            if (!empty($info['extends'])) {
                $parentExt = strtolower(self::$classToExtension[$info['extends']] ?? '');
                if ($parentExt !== '' && $parentExt !== $extLower) {
                    $classIncludes[$parentExt] = true;
                }
            }
            foreach ($info['methods'] as $minfo) {
                $returnType = $minfo['return_type'] ?? 'Variant';
                if ($returnType !== 'Variant') {
                    $depExt = strtolower(self::$classToExtension[$returnType] ?? '');
                    if ($depExt !== '' && $depExt !== $extLower) {
                        $classIncludes[$depExt] = true;
                    }
                }
                if (!empty($minfo['has_facade_params'])) {
                    $argsV = $minfo['args_v'] ?? '';
                    // args_v contains "const ClassName &name" patterns
                    if (preg_match_all('/const\s+(\w+)\s*&/', $argsV, $matches)) {
                        foreach ($matches[1] as $facadeType) {
                            $depExt = strtolower(self::$classToExtension[$facadeType] ?? '');
                            if ($depExt !== '' && $depExt !== $extLower) {
                                $classIncludes[$depExt] = true;
                            }
                        }
                    }
                }
            }
        }

        // Group classes by namespace and shorten type references
        $groupedClasses = [];
        foreach ($classes as $flatName => &$info) {
            $nsInfo = $info['ns_info'];
            $nsKey = empty($nsInfo['ns']) ? '' : implode('::', $nsInfo['ns']);
            if (!isset($groupedClasses[$nsKey])) {
                $groupedClasses[$nsKey] = [];
            }
            // Shorten extends
            if (!empty($info['extends'])) {
                $extInfo = self::$facadeClassNamespace[$info['extends']] ?? null;
                if ($extInfo && $extInfo['ns'] === $nsInfo['ns']) {
                    $info['extends_short'] = $extInfo['short'];
                } else {
                    $info['extends_short'] = $info['extends'];
                }
            }
            // Shorten method types
            foreach ($info['methods'] as &$minfo) {
                $minfo['return_type'] = self::shortTypeInContext($minfo['return_type'] ?? null, $nsInfo['ns']);
                $minfo['args'] = self::shortTypesInString($minfo['args'] ?? '', $nsInfo['ns']);
                $minfo['args_impl'] = self::shortTypesInString($minfo['args_impl'] ?? '', $nsInfo['ns']);
                if (isset($minfo['args_v'])) {
                    $minfo['args_v'] = self::shortTypesInString($minfo['args_v'], $nsInfo['ns']);
                }
                if (isset($minfo['args_impl_v'])) {
                    $minfo['args_impl_v'] = self::shortTypesInString($minfo['args_impl_v'], $nsInfo['ns']);
                }
                if (isset($minfo['impl_code'])) {
                    $minfo['impl_code'] = self::shortTypesInString($minfo['impl_code'], $nsInfo['ns']);
                }
                if (isset($minfo['impl_code_v'])) {
                    $minfo['impl_code_v'] = self::shortTypesInString($minfo['impl_code_v'], $nsInfo['ns']);
                }
            }
            unset($minfo);
            $groupedClasses[$nsKey][$nsInfo['short']] = $info;
        }
        unset($info);

        // Group functions by namespace and shorten type references
        $groupedFunctions = [];
        foreach ($functions as $flatName => &$fnInfo) {
            $nsInfo = $fnInfo['ns_info'];
            $nsKey = empty($nsInfo['ns']) ? '' : implode('::', $nsInfo['ns']);
            if (!isset($groupedFunctions[$nsKey])) {
                $groupedFunctions[$nsKey] = [];
            }
            $fnInfo['return_type'] = self::shortTypeInContext($fnInfo['return_type'], $nsInfo['ns']);
            $fnInfo['args'] = self::shortTypesInString($fnInfo['args'], $nsInfo['ns']);
            $fnInfo['args_impl'] = self::shortTypesInString($fnInfo['args_impl'], $nsInfo['ns']);
            $fnInfo['args_v'] = self::shortTypesInString($fnInfo['args_v'], $nsInfo['ns']);
            $fnInfo['args_impl_v'] = self::shortTypesInString($fnInfo['args_impl_v'], $nsInfo['ns']);
            if (!empty($fnInfo['return_expr'])) {
                $fnInfo['return_expr'] = self::shortTypesInString($fnInfo['return_expr'], $nsInfo['ns']);
            }
            if (!empty($fnInfo['return_expr_v'])) {
                $fnInfo['return_expr_v'] = self::shortTypesInString($fnInfo['return_expr_v'], $nsInfo['ns']);
            }
            $groupedFunctions[$nsKey][$nsInfo['short']] = $fnInfo;
        }
        unset($fnInfo);

        // Group constants by namespace
        $groupedConstants = [];
        foreach ($constants as $shortName => $entry) {
            $nsInfo = $entry['ns_info'];
            $nsKey = empty($nsInfo['ns']) ? '' : implode('::', $nsInfo['ns']);
            if (!isset($groupedConstants[$nsKey])) {
                $groupedConstants[$nsKey] = [];
            }
            $groupedConstants[$nsKey][$shortName] = $entry['repr'];
        }

        if (!empty($constants)) {
            self::render(
                __DIR__ . '/templates/const-impl.tpl',
                self::$rootDir . '/src/const/' . $ext . '.cc',
                ['groupedConstants' => $groupedConstants, 'constants' => $constants]
            );

            self::render(
                __DIR__ . '/templates/const-decl.tpl',
                self::$rootDir . '/include/const/' . $ext . '.h',
                ['groupedConstants' => $groupedConstants, 'constants' => $constants]
            );
        }

        if (!empty($functions)) {
            self::render(
                __DIR__ . '/templates/func-impl.tpl',
                self::$rootDir . '/src/func/' . $ext . '.cc',
                ['groupedFunctions' => $groupedFunctions, 'functions' => $functions]
            );

            self::render(
                __DIR__ . '/templates/func-decl.tpl',
                self::$rootDir . '/include/func/' . $ext . '.h',
                ['groupedFunctions' => $groupedFunctions, 'functions' => $functions]
            );
        }

        if (!empty($classes)) {
            self::render(
                __DIR__ . '/templates/class-impl.tpl',
                self::$rootDir . '/src/class/' . $ext . '.cc',
                ['groupedClasses' => $groupedClasses, 'classes' => $classes, 'ext' => $ext]
            );

            $classIncludesSorted = array_keys($classIncludes);
            sort($classIncludesSorted);
            self::render(
                __DIR__ . '/templates/class-decl.tpl',
                self::$rootDir . '/include/class/' . $ext . '.h',
                ['groupedClasses' => $groupedClasses, 'classes' => $classes, 'classIncludes' => $classIncludesSorted]
            );
        }
    }

    protected function getFunctions(): array
    {
        $functions = [];
        foreach ($this->extRef->getFunctions() as $function) {
            $originalName = $function->getName();
            if (in_array($originalName, self::BUILTIN_FUNCTIONS)) {
                continue;
            }
            $name = $originalName;
            self::nameSafety($name);
            $nsInfo = self::parsePhpName($originalName);

            [$args, $call, $args_impl, $variadic, $hasFacade, $args_v, $call_v, $args_impl_v] = $this->getArgs($function->getParameters());
            $symbol = $originalName;

            $rt = $function->getReturnType() ?? $function->getTentativeReturnType();
            $returnInfo = self::resolveReturnType($rt);
            $returnType = $returnInfo['return_type'];
            // Fall back to Variant if the return-type class has PHP __construct
            // (no Object constructor exists, so we can't wrap the result)
            if ($returnType !== 'Variant' && !empty(self::$classHasCtor[$returnType])) {
                $returnType = 'Variant';
            }
            $returnBody = $returnExpr = $returnExprV = '';
            if ($returnType !== 'Variant') {
                $callArgs = $call ? '{' . implode(', ', $call) . '}' : '{}';
                $innerExpr = "call(fn, {$callArgs})";
                if ($returnInfo['check_false']) {
                    $funcName = $function->getName();
                    $returnBody = "auto _rv = {$innerExpr};\n"
                        . "\tif (!_rv.toBool()) {\n"
                        . "\t\tthrowException(String(\"RuntimeException\"), \"{$funcName}() returned false\");\n"
                        . "\t}";
                    $returnExpr = "{$returnType}(Object(std::move(_rv)))";
                } else {
                    $returnExpr = $returnType . '(Object(' . $innerExpr . '))';
                }
            }
            // Variant overload: uses Variant args without unwrapping, always returns Variant
            if ($hasFacade) {
                $callArgsV = $call_v ? '{' . implode(', ', $call_v) . '}' : '{}';
                $returnExprV = "call(fn, {$callArgsV})";
            }

            $functions[$name] = [
                'ns_info' => $nsInfo,
                'args' => $args ? implode(', ', $args) : '',
                'args_impl' => $args ? implode(', ', $args_impl) : '',
                'call' => $call ? '{' . implode(', ', $call) . '}' : '{}',
                'symbol' => self::addLiteralString($symbol),
                'variadic' => $variadic,
                'return_type' => $returnType,
                'return_body' => $returnBody,
                'return_expr' => $returnExpr,
                'has_facade_params' => $hasFacade,
                'args_v' => $args_v ? implode(', ', $args_v) : '',
                'args_impl_v' => $args_impl_v ? implode(', ', $args_impl_v) : '',
                'call_v' => $call_v ? '{' . implode(', ', $call_v) . '}' : '{}',
                'return_expr_v' => $returnExprV,
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
            $name = $name . '_';
        }
        // PHP namespace separators are handled at a higher level (see parsePhpName)
    }

    /**
     * Split a PHP fully-qualified name into namespace parts and the leaf short name.
     * e.g. "Dom\\import_simplexml" => ['ns' => ['Dom'], 'short' => 'import_simplexml']
     *      "DateTime" => ['ns' => [], 'short' => 'DateTime']
     */
    public static function parsePhpName(string $phpName): array
    {
        if (!str_contains($phpName, '\\')) {
            return ['ns' => [], 'short' => $phpName];
        }
        $parts = explode('\\', $phpName);
        $short = array_pop($parts);
        return ['ns' => $parts, 'short' => $short];
    }

    /**
     * Shorten a flat C++ type name when it belongs to the given namespace context.
     * Returns the short name if the type is in the same namespace, unchanged otherwise.
     */
    public static function shortTypeInContext(?string $flatType, array $nsContext): string
    {
        if ($flatType === null || $flatType === 'Variant' || $flatType === 'void' || $flatType === '') {
            return $flatType ?? 'Variant';
        }
        $nsInfo = self::$facadeClassNamespace[$flatType] ?? null;
        if ($nsInfo !== null && $nsInfo['ns'] === $nsContext) {
            return $nsInfo['short'];
        }
        return $flatType;
    }

    /**
     * Regex-replace flat facade class names with short names when they belong
     * to the given namespace context. Used for args strings which contain
     * multiple type references.
     */
    public static function shortTypesInString(?string $str, array $nsContext): string
    {
        if ($str === null || $str === '') return $str ?? '';
        foreach (self::$facadeClassNamespace as $flatName => $nsInfo) {
            if ($nsInfo['ns'] === $nsContext) {
                $str = preg_replace(
                    '/\b' . preg_quote($flatName, '/') . '\b/',
                    $nsInfo['short'],
                    $str
                );
            }
        }
        return $str;
    }

    /**
     * @param array<ReflectionParameter> $params
     * @return array  [args, call, args_impl, variadic, has_facade, args_v, call_v, args_impl_v]
     */
    protected function getArgs(array $params, string $selfClass = ''): array
    {
        $args_impl = $call = $args = [];
        $args_impl_v = $call_v = $args_v = [];
        $variadic = false;
        $hasFacade = false;
        foreach ($params as $param) {
            $arg_name = $param->name;
            self::nameSafety($arg_name);
            self::changeCasePascal2Snake($arg_name);

            $paramType = $param->getType();
            $cppType = 'Variant';
            $isFacade = false;
            if ($paramType instanceof \ReflectionNamedType) {
                $resolved = self::resolveType($paramType, $selfClass);
                if ($resolved !== 'Variant') {
                    // Only use Facade type for required params; optional params with scalar
                    // defaults cannot be implicitly converted from raw int/string literals
                    if ($param->isOptional()) {
                        $isFacade = false;
                    } elseif ($selfClass && self::isBackEdge($selfClass, $resolved)) {
                        // Circular dependency back-edge: this class is defined before
                        // the dependency, so the type won't be visible yet — use Variant
                        $isFacade = false;
                    } else {
                        $cppType = $resolved;
                        $isFacade = true;
                        $hasFacade = true;
                    }
                }
            }

            $byRef = $param->isPassedByReference();
            $type = 'const ' . ($byRef ? 'Reference' : $cppType);
            $typeV = 'const ' . ($byRef ? 'Reference' : 'Variant');

            if ($param->isVariadic()) {
                $variadic = true;
                $args[] = 'const Args&... ' . $arg_name;
                $call[] = $arg_name . '...';
                $args_impl[] = 'const Args&... ' . $arg_name;
                $args_v[] = 'const Args&... ' . $arg_name;
                $call_v[] = $arg_name . '...';
                $args_impl_v[] = 'const Args&... ' . $arg_name;
                break;
            } elseif ($param->isOptional()) {
                if ($param->isDefaultValueAvailable()) {
                    $default_value = $param->getDefaultValue();
                    $default_repr = self::valueToCppRepr($default_value, $param->isPassedByReference());
                    $args[] = "$type &$arg_name = " . $default_repr;
                    $args_v[] = "$typeV &$arg_name = " . $default_repr;
                } else {
                    $args[] = "$type &$arg_name = " . '{}';
                    $args_v[] = "$typeV &$arg_name = " . '{}';
                }
            } else {
                $args[] = "$type &$arg_name";
                $args_v[] = "$typeV &$arg_name";
            }
            $args_impl[] = "$type &$arg_name";
            $args_impl_v[] = "$typeV &$arg_name";
            $call[] = $byRef ? '&' . $arg_name : ($isFacade ? $arg_name . '.getObject()' : $arg_name);
            $call_v[] = $byRef ? '&' . $arg_name : $arg_name;
        }

        return [
            $args,
            $call,
            $args_impl,
            $variadic,
            $hasFacade,
            $args_v,
            $call_v,
            $args_impl_v,
        ];
    }

    /**
     * Build args arrays from an override signature (see $methodOverrides).
     * Each param descriptor: ['name' => ..., 'type' => ..., 'default'? => ...]
     * where type is a PHP type hint string (e.g. 'string', '?int', 'PDOStatement').
     *
     * @return array  [args, call, args_impl, variadic, has_facade, args_v, call_v, args_impl_v]
     */
    protected function buildOverrideArgs(array $signature, string $selfClass = ''): array
    {
        $args = $call = $args_impl = [];
        $args_v = $call_v = $args_impl_v = [];
        $hasFacade = false;

        foreach ($signature as $param) {
            $arg_name = $param['name'];
            self::nameSafety($arg_name);
            self::changeCasePascal2Snake($arg_name);

            $phpType = $param['type'] ?? 'mixed';
            // Strip leading '?' for nullable types
            $phpTypeClean = ltrim($phpType, '?');

            // Check if this is a Facade class type
            $cppType = 'Variant';
            $isFacade = false;
            if (isset(self::$facadeClassMap[$phpTypeClean])) {
                $resolved = self::$facadeClassMap[$phpTypeClean];
                if ($selfClass && self::isBackEdge($selfClass, $resolved)) {
                    // Don't use Facade type for back-edges
                } else {
                    $cppType = $resolved;
                    $isFacade = true;
                    $hasFacade = true;
                }
            }

            $type = $isFacade ? "const {$cppType} &" : 'const Variant &';
            $typeV = 'const Variant &';

            if (isset($param['default'])) {
                $defaultVal = $param['default'];
                if ($defaultVal === 'null') {
                    $args[] = "$type $arg_name = {}";
                    $args_v[] = "$typeV $arg_name = {}";
                } else {
                    $args[] = "$type $arg_name = $defaultVal";
                    $args_v[] = "$typeV $arg_name = $defaultVal";
                }
            } else {
                $args[] = "$type $arg_name";
                $args_v[] = "$typeV $arg_name";
            }
            $args_impl[] = "$type $arg_name";
            $args_impl_v[] = "$typeV $arg_name";
            $call[] = $isFacade ? $arg_name . '.getObject()' : $arg_name;
            $call_v[] = $arg_name;
        }

        return [
            $args,
            $call,
            $args_impl,
            false,      // variadic = false for overrides
            $hasFacade,
            $args_v,
            $call_v,
            $args_impl_v,
        ];
    }

    protected function getClasses(): array
    {
        $classes = [];
        $list = $this->extRef->getClasses();
        foreach ($list as $className => $ref) {
            $methods = [];
            if (in_array($className, self::BUILTIN_CLASSES)) {
                $className = $className . '_';
            }

            $classSymbol = $ref->getName();
            $nsInfo = self::parsePhpName($classSymbol);
            if (in_array($classSymbol, self::BUILTIN_CLASSES)) {
                $nsInfo['short'] = $nsInfo['short'] . '_';
            }
            $className = str_replace("\\", '_', $className);
            if ($ref->isAbstract() || $ref->isInterface() || $ref->isTrait()) {
                continue;
            }

            // Detect parent Facade class
            $extends = '';
            $parentRef = $ref->getParentClass();
            if ($parentRef !== false) {
                $parentPhpName = $parentRef->getName();
                if (isset(self::$facadeClassMap[$parentPhpName])) {
                    $extends = self::$facadeClassMap[$parentPhpName];
                }
            }

            $hasCtor = false;
            foreach ($ref->getMethods() as $method) {
                if ($method->isConstructor()) {
                    $hasCtor = true;
                }
            }

            // Check if the __construct has required params — if so, derived
            // classes need a protected default constructor to avoid implicit
            // base-class constructor calls.
            $needsProtectedCtor = false;
            if ($hasCtor) {
                $ctor = $ref->getConstructor();
                if ($ctor) {
                    $needsProtectedCtor = false;
                    foreach ($ctor->getParameters() as $p) {
                        if (!$p->isOptional()) {
                            $needsProtectedCtor = true;
                            break;
                        }
                    }
                }
            }

            if (!$hasCtor) {
                $classSymbolLiteralString = self::addLiteralString($classSymbol);
                $shortName = $nsInfo['short'];
                $code = "{$shortName}::{$shortName}() {\n";
                $code .= "\tthis_ = newObject({$classSymbolLiteralString});\n";
                $code .= "}\n";
                $methods[$shortName] = [
                    'args' => '',
                    'args_impl' => '',
                    'call' => '{}',
                    'variadic' => false,
                    'static' => false,
                    'ctor' => true,
                    'name' => $shortName,
                    'symbol' => self::addLiteralString($classSymbol),
                    'impl_code' => $code,
                ];
            }

            foreach ($ref->getMethods() as $method) {
                if (!$method->isPublic() || $method->isDestructor()) {
                    continue;
                }
                // Skip methods declared on parent when this class extends a Facade parent.
                // Constructors are never skipped — the child needs its own constructor
                // that creates the correct PHP object class.
                if ($extends && !$method->isConstructor()
                    && $method->getDeclaringClass()->getName() !== $ref->getName()) {
                    continue;
                }
                $params = $method->getParameters();
                $name = $method->getName();

                if ($method->isConstructor()) {
                    $name = $nsInfo['short'];
                }
                self::nameSafety($name);

                // Check for method override
                $overrideKey = $className . '::' . $method->getName();
                $override = self::$methodOverrides[$overrideKey] ?? null;
                if ($override !== null && isset($override['signature'])) {
                    [$args, $call, $args_impl, $variadic, $hasFacade, $args_v, $call_v, $args_impl_v] =
                        $this->buildOverrideArgs($override['signature'], $className);
                } else {
                    [$args, $call, $args_impl, $variadic, $hasFacade, $args_v, $call_v, $args_impl_v] =
                        $this->getArgs($params, $className);
                }
                $symbol = $method->isStatic() ? $className . '::' . $method->getName() : $method->getName();

                // Resolve return type
                $returnType = 'Variant';
                $checkFalse = false;
                $rt = $method->getReturnType() ?? $method->getTentativeReturnType();
                if ($rt !== null) {
                    $returnInfo = self::resolveReturnType($rt, $className);
                    $returnType = $returnInfo['return_type'];
                    $checkFalse = $returnInfo['check_false'];
                    // Circular dependency back-edge: if the return type is defined
                    // after this class in sorted order, fall back to Variant.
                    if ($returnType !== 'Variant' && self::isBackEdge($className, $returnType)) {
                        $returnType = 'Variant';
                        $checkFalse = false;
                    }
                    // Fall back to Variant if the return-type class has PHP __construct
                    // (no Object constructor exists, so we can't wrap the result as ClassName(Object(...)))
                    if ($returnType !== 'Variant' && !empty(self::$classHasCtor[$returnType])) {
                        $returnType = 'Variant';
                        $checkFalse = false;
                    }
                }

                $info =[
                    'args' => $args ? implode(', ', $args) : '',
                    'args_impl' => $args ? implode(', ', $args_impl) : '',
                    'call' => $call ? '{' . implode(', ', $call) . '}' : '{}',
                    'static' => $method->isStatic(),
                    'ctor' => $method->isConstructor(),
                    'symbol' => self::addLiteralString($symbol),
                    'variadic' => $variadic,
                    'return_type' => $returnType,
                    'has_facade_params' => $hasFacade,
                    'args_v' => $hasFacade ? ($args_v ? implode(', ', $args_v) : '') : '',
                    'args_impl_v' => $hasFacade ? ($args_impl_v ? implode(', ', $args_impl_v) : '') : '',
                    'call_v' => $hasFacade ? ($call_v ? '{' . implode(', ', $call_v) . '}' : '{}') : '',
                ];

                $code = '';
                if (!$info['ctor']) {
                    $code .= $returnType . ' ';
                }
                $code .= $variadic ? $name : $nsInfo['short'] . '::' . $name;
                $code .= "({$info['args_impl']}) {" . "\n";
                 if ($info['ctor']) {
                     $classSymbolLiteralString = self::addLiteralString($classSymbol);
                     $code .= "\tthis_ = newObject({$classSymbolLiteralString}, {$info['call']});\n";
                 } elseif ($info['static']) {
                     $classLiteralString = self::addLiteralString($classSymbol);
                     $methodLiteralString = self::addLiteralString($method->getName());
                     $code .= "\tstatic THREAD_LOCAL zend_function *_method_fn = nullptr;\n";
                     $code .= "\tif (UNEXPECTED(!_method_fn)) {\n";
                     $code .= "\t\t_method_fn = php::getMethod({$classLiteralString}, {$methodLiteralString});\n";
                     $code .= "\t}\n";
                     if ($checkFalse) {
                         $callExpr = "php::call(_method_fn, {$info['call']})";
                         $code .= "\tauto _rv = {$callExpr};\n";
                         $code .= "\tif (!_rv.toBool()) {\n";
                         $code .= "\t\tthrowException(String(\"RuntimeException\"), \"{$classSymbol}::{$method->getName()}() returned false\");\n";
                         $code .= "\t}\n";
                         $code .= "\treturn {$returnType}(Object(std::move(_rv)));\n";
                     } elseif ($returnType !== 'Variant') {
                         $code .= "\treturn {$returnType}(Object(php::call(_method_fn, {$info['call']})));\n";
                     } else {
                         $code .= "\treturn php::call(_method_fn, {$info['call']});\n";
                     }
                 } else {
                     $code .= "\tstatic THREAD_LOCAL zend_function *_method_fn = nullptr;\n";
                     $code .= "\tif (UNEXPECTED(!_method_fn)) {\n";
                     $code .= "\t\t_method_fn = php::getMethod(this_.ce(), {$info['symbol']});\n";
                     $code .= "\t}\n";
                     if ($checkFalse) {
                         $callExpr = "this_.call(_method_fn, {$info['call']})";
                         $code .= "\tauto _rv = {$callExpr};\n";
                         $code .= "\tif (!_rv.toBool()) {\n";
                         $code .= "\t\tthrowException(String(\"RuntimeException\"), \"{$classSymbol}::{$method->getName()}() returned false\");\n";
                         $code .= "\t}\n";
                         $code .= "\treturn {$returnType}(Object(std::move(_rv)));\n";
                     } elseif ($returnType !== 'Variant') {
                         $code .= "\treturn {$returnType}(Object(this_.call(_method_fn, {$info['call']})));\n";
                     } else {
                         $code .= "\treturn this_.call(_method_fn, {$info['call']});\n";
                     }
                 }
                $code .= "}\n";
                $info['impl_code'] = $code;

                // Generate Variant overload if method has Facade-typed parameters
                $info['impl_code_v'] = '';
                if ($hasFacade && !$variadic && !$info['ctor']) {
                    $codeV = "Variant ";
                    $codeV .= "{$nsInfo['short']}::{$name}({$info['args_impl_v']}) {" . "\n";
                    if ($info['static']) {
                        $codeV .= "\tstatic THREAD_LOCAL zend_function *_method_fn = nullptr;\n";
                        $codeV .= "\tif (UNEXPECTED(!_method_fn)) {\n";
                        $codeV .= "\t\t_method_fn = php::getMethod({$classLiteralString}, {$methodLiteralString});\n";
                        $codeV .= "\t}\n";
                        $codeV .= "\treturn php::call(_method_fn, {$info['call_v']});\n";
                    } else {
                        $codeV .= "\tstatic THREAD_LOCAL zend_function *_method_fn = nullptr;\n";
                        $codeV .= "\tif (UNEXPECTED(!_method_fn)) {\n";
                        $codeV .= "\t\t_method_fn = php::getMethod(this_.ce(), {$info['symbol']});\n";
                        $codeV .= "\t}\n";
                        $codeV .= "\treturn this_.call(_method_fn, {$info['call_v']});\n";
                    }
                    $codeV .= "}\n";
                    $info['impl_code_v'] = $codeV;
                }
                $methods[$name] = $info;
            }

            if (empty($constants) and empty($methods)) {
                continue;
            }

            // Collect class constants declared on this class
            $classConstants = [];
            foreach ($ref->getReflectionConstants() as $const) {
                if ($const->isPrivate() || $const->isProtected()) {
                    continue;
                }
                if ($const->getDeclaringClass()->getName() !== $ref->getName()) {
                    continue;
                }
                $val = $const->getValue();
                if (is_array($val) || is_object($val) || is_resource($val)) {
                    continue;
                }
                $name = $const->getName();
                self::nameSafety($name);
                $name = $name . $this->constSuffix($name);
                $repr = self::valueToCppRepr($val);
                if (is_string($val)) {
                    $classConstants[$name] = ['repr' => 'ZEND_STRL(' . $repr . '), true', 'inline_init' => true];
                } elseif (is_null($val)) {
                    $classConstants[$name] = ['repr' => '', 'inline_init' => true];
                } elseif (is_bool($val)) {
                    $classConstants[$name] = ['repr' => $repr, 'type' => 'bool'];
                } elseif (is_float($val)) {
                    $classConstants[$name] = ['repr' => $repr, 'type' => 'double'];
                } else {
                    $classConstants[$name] = ['repr' => $repr, 'type' => 'int'];
                }
            }

            $classes[$className] = [
                'ns_info' => $nsInfo,
                'methods' => $methods,
                'class' => self::addLiteralString($classSymbol),
                'has_ctor' => $hasCtor,
                'needs_protected_ctor' => $needsProtectedCtor,
                'extends' => $extends,
                'parent_has_ctor' => $extends ? !empty(self::$classHasCtor[$extends]) : false,
                'constants' => $classConstants,
            ];
        }

        // Sort classes topologically so dependent classes are declared first
        $sortedList = self::$sortedClasses;
        uksort($classes, function ($a, $b) use ($sortedList) {
            $posA = array_search($a, $sortedList);
            $posB = array_search($b, $sortedList);
            if ($posA === false) $posA = PHP_INT_MAX;
            if ($posB === false) $posB = PHP_INT_MAX;
            return $posA - $posB;
        });

        return $classes;
    }

    protected function getConstants(): array
    {
        $constants = [];
        if ($this->extRef->getConstants()) {
            foreach ($this->extRef->getConstants() as $name => $value) {
                if (is_array($value) or is_object($value) or is_resource($value)) {
                    $type = gettype($value);
                    echo "Skipping constant $name, unsupported type `{$type}`\n";
                    continue;
                }
                $originalName = $name;
                $nsInfo = self::parsePhpName($originalName);
                $shortName = $nsInfo['short'];
                self::nameSafety($shortName);
                $shortName = $shortName . $this->constSuffix($shortName);
                $repr = self::valueToCppRepr($value);
                if (is_string($value)) {
                    $constants[$shortName] = ['ns_info' => $nsInfo, 'repr' => 'ZEND_STRL(' . $repr . '), true'];
                } else {
                    $constants[$shortName] = ['ns_info' => $nsInfo, 'repr' => $repr];
                }
            }
        }
        return $constants;
    }
}
