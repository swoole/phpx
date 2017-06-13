<?php
$dir = dirname(__DIR__).'/include';
define('SPACE_4', str_repeat(' ', 4));
define('SPACE_8', SPACE_4 . SPACE_4);
define('DELIMITER', '/*generator*/');

$src = file_get_contents($dir . '/phpx.h');
$r = preg_match('/\#define\s+PHPX_MAX_ARGC\s+(\d+)/', $src, $match);
if (!$r)
{
    exit("no PHPX_MAX_ARGC\n");
}

$maxArgc = $match[1];

//生成函数执行代码
$out = '';
for ($i = 1; $i <= $maxArgc; $i++)
{
    $out .= "\n".'static Variant exec(const char *func, ';
    $list = [];
    for ($j = 1; $j <= $i; $j++)
    {
        $list[] = 'Variant v' . $j;
    }
    $out .= implode(', ', $list);
    $out .= ")\n{\n";
    $out .= SPACE_4 . "Variant _func(func);\n" . SPACE_4 . "Args args;\n";
    for ($j = 1; $j <= $i; $j++)
    {
    	$out .= SPACE_4 . "v" . ($j) . ".addRef();\n";
        $out .= SPACE_4 . "args.append(v" . ($j) . ".ptr());\n";
    }
    $out .= SPACE_4 . "return _call(NULL, _func.ptr(), args);\n}";
}
$exec_function_code = $out;

//生成对象方法执行代码
$out = '';
for ($i = 1; $i <= $maxArgc; $i++)
{
    $out .= "\n".SPACE_4 . 'Variant exec(const char *func, ';
    $list = [];
    for ($j = 1; $j <= $i; $j++)
    {
        $list[] = 'Variant v' . $j;
    }
    $out .= implode(', ', $list);
    $out .= ")\n" . SPACE_4 . "{\n";
    $out .= SPACE_8 . "Variant _func(func);\n" . SPACE_8 . "Args args;\n";
    for ($j = 1; $j <= $i; $j++)
    {
    	$out .= SPACE_8. "v" . ($j) . ".addRef();\n";
        $out .= SPACE_8 . "args.append(v" . ($j) . ".ptr());\n";
    }
    $out .= SPACE_8 . "return _call(ptr(), _func.ptr(), args);\n" . SPACE_4 . "}";
}
$exec_method_code = $out."\n".SPACE_4;

//生成对象创建代码
$out = '';
for ($i = 1; $i <= $maxArgc; $i++)
{
    $out .= "\nstatic Object newObject(const char *name, ";
    $list = [];
    for ($j = 1; $j <= $i; $j++)
    {
        $list[] = 'Variant v' . $j;
    }
    $out .= implode(', ', $list);
    $out .= ")\n" . "{\n";
    $out .= <<<CODE
    Object object;
    zend_class_entry *ce = getClassEntry(name);
    if (ce == NULL)
    {
        error(E_WARNING, "class '%s' is undefined.", name);
        return object;
    }
    zval zobject;
    if (object_init_ex(&zobject, ce) == FAILURE)
    {
        return object;
    }
    object = Object(&zobject);
    Array args;\n
CODE;
    for ($j = 1; $j <= $i; $j++)
    {
        $out .= SPACE_4 . "v" . ($j) . ".addRef();\n";
        $out .= SPACE_4 . "args.append(v" . ($j) . ".ptr());\n";
    }
    $out .= SPACE_4 . "object.addRef();\n";
    $out .= SPACE_4 . "object.call(\"__construct\", args);\n";
    $out .= SPACE_4 . "return object;\n}";
}
$new_object_code = $out."\n";

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
file_put_contents($dir . '/phpx.h', $src);