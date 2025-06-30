<?php
define('BASE_DIR', dirname(__DIR__));
define('SPACE_4', str_repeat(' ', 4));
const SPACE_8 = SPACE_4 . SPACE_4;
const DELIMITER = '/* generator */';
const DELIMITER_2 = '/* generator-1 */';
const VARIANT_SRC_FILE = BASE_DIR . '/src/core/variant.cc';
const OBJECT_SRC_FILE = BASE_DIR . '/src/core/object.cc';
const HEADER_FILE = BASE_DIR . '/include/phpx.h';

$src = file_get_contents(HEADER_FILE);
$r = preg_match('/\#define\s+PHPX_MAX_ARGC\s+(\d+)/', $src, $match);
if (!$r) {
    exit("no PHPX_MAX_ARGC\n");
}

$maxArgc = $match[1];

// 生成函数执行代码
$out = '';
$code = '';

for ($i = 1; $i <= $maxArgc; $i++) {
    $func_define = 'Variant Variant::operator()(';
    $list = [];
    for ($j = 1; $j <= $i; $j++) {
        $list[] = 'const Variant &v' . $j;
    }
    $func_define .= implode(', ', $list);
    $func_define .= ") const ";

    $out .= "\n" . SPACE_4 . "Variant operator()(" . implode(', ', $list) . ') const;';

    $code .= "\n" . $func_define . " {\n";
    $code .= SPACE_4 . "Args args;\n";
    for ($j = 1; $j <= $i; $j++) {
        $code .= SPACE_4 . "args.append(v" . ($j) . ");\n";
    }
    $code .= SPACE_4 . "return _call(nullptr, const_ptr(), args);\n}\n";
}

$parts = explode(DELIMITER, file_get_contents(VARIANT_SRC_FILE));
file_put_contents(VARIANT_SRC_FILE, implode(DELIMITER, [
    $parts[0],
    $code,
    $parts[2],
]));

$exec_function_code = $out . SPACE_4 . "\n";

// 生成对象方法执行代码
$out = '';
$code = '';

for ($i = 1; $i <= $maxArgc; $i++) {
    $out .= "\n" . SPACE_4 . 'Variant exec(const char *func, ';
    $list = [];
    for ($j = 1; $j <= $i; $j++) {
        $list[] = 'const Variant &v' . $j;
    }
    $out .= implode(', ', $list) . ");";

    $code .= "\nVariant Object::exec(const char *func, ";
    $list = [];
    for ($j = 1; $j <= $i; $j++) {
        $list[] = 'const Variant &v' . $j;
    }
    $code .= implode(', ', $list) . ")\n{\n";
    $code .= SPACE_4 . "Variant _func(func);\n" . SPACE_4 . "Args args;\n";
    for ($j = 1; $j <= $i; $j++) {
        $code .= SPACE_4 . "args.append(v" . ($j) . ");\n";
    }
    $code .= SPACE_4 . "return _call(ptr(), _func.const_ptr(), args);\n}\n";
}

$parts = explode(DELIMITER_2, file_get_contents(OBJECT_SRC_FILE));
file_put_contents(OBJECT_SRC_FILE, implode(DELIMITER_2, [
    $parts[0],
    $code,
    $parts[2],
]));
$exec_method_code = $out . "\n" . SPACE_4;

// 生成对象创建代码
$out = '';
$code = '';

for ($i = 1; $i <= $maxArgc; $i++) {
    $func_define = "Object newObject(const char *name, ";
    $list = [];
    for ($j = 1; $j <= $i; $j++) {
        $list[] = 'const Variant &v' . $j;
    }
    $func_define .= implode(', ', $list) . ")";

    $out .= "\nextern " . $func_define . ";";

    $code .= "\n" . $func_define . "\n{\n";
    $code .= <<<CODE
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == nullptr) {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    if (object_init_ex(object.ptr(), ce) == FAILURE) {
        return object;
    }
    Args args;\n
CODE;
    for ($j = 1; $j <= $i; $j++) {
        $code .= SPACE_4 . "args.append(v" . ($j) . ");\n";
    }
    $code .= SPACE_4 . "object.call(\"__construct\", args);\n";
    $code .= SPACE_4 . "return object;\n}\n";
}
$parts = explode(DELIMITER, file_get_contents(OBJECT_SRC_FILE));
file_put_contents(OBJECT_SRC_FILE, implode(DELIMITER, [
    $parts[0],
    $code,
    $parts[2],
]));
$new_object_code = $out . "\n";

$parts = explode(DELIMITER, $src);

$src = implode(DELIMITER, [
    $parts[0],
    $exec_function_code,
    $parts[2],
    $exec_method_code,
    $parts[4],
    $new_object_code,
    $parts[6],
]);
file_put_contents(HEADER_FILE, $src);
