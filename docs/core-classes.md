# 核心类型与所有权

## Variant

`Variant` 是 PHPX 的基础值类型，封装一个 `zval` 并通过 RAII 管理其生命
周期。默认复制构造会取得独立的 PHP 值所有权；析构时释放自己的引用。

```cpp
Variant integer = 42;
Variant string = "phpx";
Variant array = Array{1, 2, 3};
```

### owned、reference 与 indirect

- 普通 `Variant`：拥有自己的 zval 值；
- `Reference`：持有 PHP `zend_reference`；
- Indirect `Variant`：借用数组元素、对象属性或其他外部 zval 地址。

Indirect 只适合单个同步操作。数组结构变化、属性删除或 request 结束后，
原地址可能失效。需要跨操作保存时，通过普通赋值或 `copyValue()` 物化值。

```cpp
Variant owned = copyValue(container.item("key"));
```

`takeValue()` 只用于已经证明为最后一次使用的 owned 值；普通扩展代码通常
不需要主动使用它。

### Zend 指针

`ptr()`、`unwrap_ptr()`、`direct_ptr()`、`array()`、`object()`、`ce()` 等
是 Zend 适配接口。它们不自动延长底层存储生命周期。能够使用
`offsetGet()`、`getProperty()`、`call()` 等高级接口时，不应保存裸指针。

## String

`String` 继承 `Variant`，构造后保证其值是 PHP string：

```cpp
String name = "PHPX";
String normalized = name.lower().trim();
```

`data()` 返回的字符指针只在该 Zend string 存活且未被替换时有效。
`toStdString()` 创建独立的 `std::string`，适合跨 PHPX 值修改保存。

字符串写操作遵循 PHP 的 copy-on-write；不要直接修改 `data()`。

## Array

`Array` 封装 Zend `HashTable` 并处理 copy-on-write：

```cpp
Array data;
data.set("name", "PHPX");
data.appendValue(1);
Variant name = data.get("name");
```

### 普通写入与引用写入

- `setValue()` / `appendValue()`：普通 PHP 赋值语义，输入引用被解引用；
- `set()` / `append()`：允许保留显式引用，供 `=&` 等低层语义使用。

新扩展的普通数组写入优先使用 Value 版本。只有明确需要 PHP 引用传播时
才使用非 Value 版本。

### 读取

`get()` 返回 owned 值，适合保存。`item()` 返回可写的间接槽位，具有更
严格的生命周期要求：

```cpp
Variant snapshot = data.get("name");
Variant slot = data.item("name", true); // 仅在确定槽位稳定时使用
```

对数组增删元素后，不得继续使用先前取得的间接槽位。

### 遍历

```cpp
for (const auto &item : data) {
    php::echo(item.key, " => ", item.value, "\n");
}
```

需要修改引用值时使用明确的引用接口，不要从普通遍历值推断可写地址。

## Object

`Object` 构造后保证值为 object、null 或 undef。通常通过 `newObject()`
创建：

```cpp
Object object = newObject("ArrayObject", {Array{1, 2}});
object.set("name", "demo");
Variant result = object.call("count");
```

属性访问最终调用对象 handlers，因此支持魔术属性和 Property Hooks。
`getProperties()` 返回标准属性表视图，不能替代 handler 语义。

`Object::clone()` 通过对象 clone handler 执行，与简单复制 `Variant` 不同。

## Reference

`Reference` 表示 PHP 引用容器：

```cpp
Reference ref = newReference(10);
Variant current = ref.getRefValue();
ref = 20;
```

复制 `Reference` 会继续指向同一个 PHP reference；将它作为普通值写入时
是否保留引用，由目标 API 的 Value/非 Value 语义决定。

## Args、VarList 与 FixedArgs

`Args` 拥有动态、连续的 Zend 参数数组，适合运行时构造或 unpack：

```cpp
Args args;
args.append("first");
args.append(2);
Variant result = php::call("some_function", args);
```

`VarList<N>` 和 `FixedArgs` 是 TypePHP 固定参数调用的无动态分配路径。
普通扩展调用优先直接写初始化列表；不要为了微优化依赖其内部布局。

## Box 与 Resource

`newResource()` / `Variant::toResource()` 用于传统 Zend resource。
`Box` 用于将受 PHPX 管理的 C++ 对象放入专用资源，并提供运行时类型检查。

```cpp
class State final : public Box {
  public:
    int value = 0;
};
```

`Box` 的析构由 PHPX 资源生命周期触发，不能同时由外部 `delete`。资源名、
类型注册和 request 生命周期必须保持一致。

## 跨请求规则

普通 `Variant`、`String`、`Array`、`Object` 和 `Reference` 通常使用 request
内存，不能存入进程级静态表并跨 RSHUTDOWN。持久字符串使用专门的
`PersistentZendString`，持久类/函数指针也必须来自 MINIT 可见的 internal
表。脚本类和脚本函数只能在所属 request 内缓存。
