# 函数手册

本文档列出 PHPX 封装的所有内置函数。

## 目录

- [字符串函数](#字符串函数)
- [数组函数](#数组函数)
- [数学函数](#数学函数)
- [日期时间函数](#日期时间函数)
- [文件系统函数](#文件系统函数)
- [网络函数](#网络函数)
- [加密哈希函数](#加密哈希函数)
- [多字节字符串函数](#多字节字符串函数)

---

## 字符串函数

### strlen

获取字符串长度

```cpp
PHPX_FUNCTION(strlen) {
    String str = args[0].toString();
    return (Int)str.length();
}
```

**PHP 使用示例：**
```php
$length = strlen("Hello");  // 5
```

### strpos

查找字符串首次出现的位置

```cpp
PHPX_FUNCTION(strpos) {
    String haystack = args[0].toString();
    String needle = args[1].toString();
    
    const char *pos = strstr(haystack.data(), needle.data());
    if (pos) {
        return (Int)(pos - haystack.data());
    } else {
        return false;
    }
}
```

**PHP 使用示例：**
```php
$pos = strpos("Hello World", "World");  // 6
```

### substr

返回字符串的子串

```cpp
PHPX_FUNCTION(substr) {
    String str = args[0].toString();
    Int start = args[1].toInt();
    
    Int length = 0;
    if (args.size() > 2) {
        length = args[2].toInt();
    }
    
    return str.substr(start, length);
}
```

**PHP 使用示例：**
```php
$sub = substr("Hello World", 0, 5);  // "Hello"
```

### strtoupper

转换为大写

```cpp
PHPX_FUNCTION(strtoupper) {
    String str = args[0].toString();
    zend_string *upper = zend_string_init(
        str.data(), 
        str.length(), 
        0
    );
    
    php_strtoupper(ZSTR_VAL(upper), ZSTR_LEN(upper));
    return String(upper, Ctor::Move);
}
```

**PHP 使用示例：**
```php
$upper = strtoupper("hello");  // "HELLO"
```

### strtolower

转换为小写

```cpp
PHPX_FUNCTION(strtolower) {
    String str = args[0].toString();
    zend_string *lower = zend_string_init(
        str.data(), 
        str.length(), 
        0
    );
    
    php_strtolower(ZSTR_VAL(lower), ZSTR_LEN(lower));
    return String(lower, Ctor::Move);
}
```

**PHP 使用示例：**
```php
$lower = strtolower("HELLO");  // "hello"
```

### trim

去除字符串首尾空白

```cpp
PHPX_FUNCTION(trim) {
    String str = args[0].toString();
    String character_mask = " \t\n\r\0\x0B";
    
    if (args.size() > 1) {
        character_mask = args[1].toString();
    }
    
    // 实现修剪逻辑
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && 
           strchr(character_mask.data(), str.data()[start])) {
        start++;
    }
    
    while (end > start && 
           strchr(character_mask.data(), str.data()[end - 1])) {
        end--;
    }
    
    return str.substr(start, end - start);
}
```

**PHP 使用示例：**
```php
$trimmed = trim("  Hello  ");  // "Hello"
```

### explode

分割字符串为数组

```cpp
PHPX_FUNCTION(explode) {
    String delimiter = args[0].toString();
    String str = args[1].toString();
    
    Array result;
    size_t start = 0;
    size_t pos;
    
    while ((pos = str.strpos(delimiter, start)) != -1) {
        result.append(str.substr(start, pos - start));
        start = pos + delimiter.length();
    }
    
    result.append(str.substr(start));
    return result;
}
```

**PHP 使用示例：**
```php
$arr = explode(",", "a,b,c");  // ["a", "b", "c"]
```

### implode

数组合并为字符串

```cpp
PHPX_FUNCTION(implode) {
    String glue = args[0].toString();
    Array pieces = args[1].toArray();
    
    String result;
    bool first = true;
    
    pieces.foreach([&result, &glue, &first](Variant &key, Variant &value) {
        if (!first) {
            result = result.concat(glue);
        }
        result = result.concat(value.toString());
        first = false;
    });
    
    return result;
}
```

**PHP 使用示例：**
```php
$str = implode("-", ["a", "b", "c"]);  // "a-b-c"
```

### str_replace

替换子串

```cpp
PHPX_FUNCTION(str_replace) {
    String search = args[0].toString();
    String replace = args[1].toString();
    String subject = args[2].toString();
    
    String result;
    size_t start = 0;
    size_t pos;
    
    while ((pos = subject.strpos(search, start)) != -1) {
        result = result.concat(subject.substr(start, pos - start));
        result = result.concat(replace);
        start = pos + search.length();
    }
    
    result = result.concat(subject.substr(start));
    return result;
}
```

**PHP 使用示例：**
```php
$result = str_replace("World", "PHPX", "Hello World");  
// "Hello PHPX"
```

### sprintf

格式化字符串

```cpp
PHPX_FUNCTION(sprintf) {
    String format = args[0].toString();
    
    std::vector<zval*> params;
    for (size_t i = 1; i < args.size(); i++) {
        params.push_back(args[i].ptr());
    }
    
    char *buffer;
    vspprintf(&buffer, 0, format.data(), params.data());
    return buffer;
    efree(buffer);
}
```

**PHP 使用示例：**
```php
$str = sprintf("Name: %s, Age: %d", "John", 25);
// "Name: John, Age: 25"
```

---

## 数组函数

### count

计算数组元素个数

```cpp
PHPX_FUNCTION(count) {
    Array array = args[0].toArray();
    return (Int)array.count();
}
```

**PHP 使用示例：**
```php
$count = count([1, 2, 3]);  // 3
```

### array_push

压入元素到数组末尾

```cpp
PHPX_FUNCTION(array_push) {
    Array array = args[0].toArray();
    
    for (size_t i = 1; i < args.size(); i++) {
        array.append(args[i]);
    }
    
    return array.count();
}
```

**PHP 使用示例：**
```php
$count = array_push($arr, "item1", "item2");
```

### array_pop

弹出数组最后一个元素

```cpp
PHPX_FUNCTION(array_pop) {
    Array array = args[0].toArray();
    
    if (array.count() == 0) {
        return null;
        return;
    }
    
    // 获取最后一个元素
    Variant last;
    array.foreach([&last](Variant &key, Variant &value) {
        last = value;
    });
    
    // 删除最后一个元素
    // ... 实现删除逻辑
    
    return last;
}
```

**PHP 使用示例：**
```php
$last = array_pop($arr);
```

### array_merge

合并数组

```cpp
PHPX_FUNCTION(array_merge) {
    Array result;
    
    for (size_t i = 0; i < args.size(); i++) {
        Array arr = args[i].toArray();
        result = result.merge(arr);
    }
    
    return result;
}
```

**PHP 使用示例：**
```php
$merged = array_merge([1, 2], [3, 4]);  // [1, 2, 3, 4]
```

### array_keys

返回数组所有键名

```cpp
PHPX_FUNCTION(array_keys) {
    Array array = args[0].toArray();
    Array keys;
    
    array.foreach([&keys](Variant &key, Variant &value) {
        keys.append(key);
    });
    
    return keys;
}
```

**PHP 使用示例：**
```php
$keys = array_keys(["a" => 1, "b" => 2]);  // ["a", "b"]
```

### array_values

返回数组所有值

```cpp
PHPX_FUNCTION(array_values) {
    Array array = args[0].toArray();
    Array values;
    
    array.foreach([&values](Variant &key, Variant &value) {
        values.append(value);
    });
    
    return values;
}
```

**PHP 使用示例：**
```php
$values = array_values(["a" => 1, "b" => 2]);  // [1, 2]
```

### in_array

检查数组中是否存在某个值

```cpp
PHPX_FUNCTION(in_array) {
    Variant needle = args[0];
    Array haystack = args[1].toArray();
    
    bool strict = false;
    if (args.size() > 2) {
        strict = args[2].toBool();
    }
    
    bool found = false;
    haystack.foreach([&needle, &strict, &found](
        Variant &key, 
        Variant &value
    ) {
        if (strict) {
            if (value === needle) {
                found = true;
            }
        } else {
            if (value == needle) {
                found = true;
            }
        }
    });
    
    return found;
}
```

**PHP 使用示例：**
```php
$exists = in_array("apple", ["apple", "banana"]);  // true
```

### array_key_exists

检查数组键名是否存在

```cpp
PHPX_FUNCTION(array_key_exists) {
    Variant key = args[0];
    Array array = args[1].toArray();
    
    return array.exists(key);
}
```

**PHP 使用示例：**
```php
$exists = array_key_exists("name", ["name" => "John"]);  // true
```

### sort

对数组排序

```cpp
PHPX_FUNCTION(sort) {
    Array array = args[0].toArray();
    
    // 转换为 C++ 向量进行排序
    std::vector<std::pair<Variant, Variant>> items;
    
    array.foreach([&items](Variant &key, Variant &value) {
        items.push_back({key, value});
    });
    
    // 排序
    std::sort(items.begin(), items.end(), 
        [](const auto &a, const auto &b) {
            return compare(a.second, b.second) < 0;
        });
    
    // 重建数组
    Array result;
    for (const auto &item : items) {
        result.append(item.second);
    }
    
    return result;
}
```

**PHP 使用示例：**
```php
sort($arr);  // [3, 1, 2] -> [1, 2, 3]
```

### array_reverse

反转数组

```cpp
PHPX_FUNCTION(array_reverse) {
    Array array = args[0].toArray();
    Array result;
    
    std::vector<Variant> values;
    array.foreach([&values](Variant &key, Variant &value) {
        values.push_back(value);
    });
    
    // 反向添加
    for (auto it = values.rbegin(); it != values.rend(); ++it) {
        result.append(*it);
    }
    
    return result;
}
```

**PHP 使用示例：**
```php
$reversed = array_reverse([1, 2, 3]);  // [3, 2, 1]
```

---

## 数学函数

### abs

绝对值

```cpp
PHPX_FUNCTION(abs) {
    Variant num = args[0];
    
    if (num.isInt()) {
        return std::abs(num.toInt());
    } else if (num.isFloat()) {
        return std::fabs(num.toFloat());
    } else {
        throwError("Parameter must be number");
    }
}
```

**PHP 使用示例：**
```php
$abs = abs(-5);  // 5
```

### round

四舍五入

```cpp
PHPX_FUNCTION(round) {
    Float num = args[0].toFloat();
    Int precision = 0;
    
    if (args.size() > 1) {
        precision = args[1].toInt();
    }
    
    double multiplier = pow(10.0, precision);
    return round(num * multiplier) / multiplier;
}
```

**PHP 使用示例：**
```php
$rounded = round(3.14159, 2);  // 3.14
```

### ceil

向上取整

```cpp
PHPX_FUNCTION(ceil) {
    Float num = args[0].toFloat();
    return (Int)std::ceil(num);
}
```

**PHP 使用示例：**
```php
$ceil = ceil(3.2);  // 4
```

### floor

向下取整

```cpp
PHPX_FUNCTION(floor) {
    Float num = args[0].toFloat();
    return (Int)std::floor(num);
}
```

**PHP 使用示例：**
```php
$floor = floor(3.8);  // 3
```

### rand

生成随机整数

```cpp
PHPX_FUNCTION(rand) {
    Int min = 0;
    Int max = RAND_MAX;
    
    if (args.size() >= 2) {
        min = args[0].toInt();
        max = args[1].toInt();
    }
    
    return random_int(min, max);
}
```

**PHP 使用示例：**
```php
$rand = rand(1, 100);  // 随机数 1-100
```

### max

最大值

```cpp
PHPX_FUNCTION(max) {
    if (args.size() == 1 && args[0].isArray()) {
        Array array = args[0].toArray();
        Variant max_val;
        
        array.foreach([&max_val](Variant &key, Variant &value) {
            if (max_val.isNull() || compare(value, max_val) > 0) {
                max_val = value;
            }
        });
        
        return max_val;
    } else {
        Variant max_val = args[0];
        for (size_t i = 1; i < args.size(); i++) {
            if (compare(args[i], max_val) > 0) {
                max_val = args[i];
            }
        }
        return max_val;
    }
}
```

**PHP 使用示例：**
```php
$max = max(1, 5, 3);  // 5
$max = max([1, 5, 3]);  // 5
```

### min

最小值

```cpp
PHPX_FUNCTION(min) {
    if (args.size() == 1 && args[0].isArray()) {
        Array array = args[0].toArray();
        Variant min_val;
        
        array.foreach([&min_val](Variant &key, Variant &value) {
            if (min_val.isNull() || compare(value, min_val) < 0) {
                min_val = value;
            }
        });
        
        return min_val;
    } else {
        Variant min_val = args[0];
        for (size_t i = 1; i < args.size(); i++) {
            if (compare(args[i], min_val) < 0) {
                min_val = args[i];
            }
        }
        return min_val;
    }
}
```

**PHP 使用示例：**
```php
$min = min(1, 5, 3);  // 1
```

### pow

幂运算

```cpp
PHPX_FUNCTION(pow) {
    Float base = args[0].toFloat();
    Float exp = args[1].toFloat();
    return pow(base, exp);
}
```

**PHP 使用示例：**
```php
$result = pow(2, 3);  // 8
```

### sqrt

平方根

```cpp
PHPX_FUNCTION(sqrt) {
    Float num = args[0].toFloat();
    return sqrt(num);
}
```

**PHP 使用示例：**
```php
$sqrt = sqrt(16);  // 4
```

---

## 日期时间函数

### time

返回当前时间戳

```cpp
PHPX_FUNCTION(time) {
    return (Int)time(nullptr);
}
```

**PHP 使用示例：**
```php
$timestamp = time();  // 当前 Unix 时间戳
```

### date

格式化日期

```cpp
PHPX_FUNCTION(date) {
    String format = args[0].toString();
    Int timestamp = time(nullptr);
    
    if (args.size() > 1) {
        timestamp = args[1].toInt();
    }
    
    time_t t = timestamp;
    struct tm *tm_info = localtime(&t);
    
    char buffer[256];
    strftime(buffer, sizeof(buffer), format.data(), tm_info);
    return buffer;
}
```

**PHP 使用示例：**
```php
$date = date("Y-m-d H:i:s");  // "2026-03-27 10:30:00"
```

### mktime

创建 Unix 时间戳

```cpp
PHPX_FUNCTION(mktime) {
    int hour = args[0].toInt();
    int minute = args[1].toInt();
    int second = args[2].toInt();
    int month = args[3].toInt();
    int day = args[4].toInt();
    int year = args[5].toInt();
    
    struct tm tm = {};
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_year = year - 1900;
    
    return (Int)mktime(&tm);
}
```

**PHP 使用示例：**
```php
$timestamp = mktime(10, 30, 0, 3, 27, 2026);
```

### strtotime

解析日期时间为时间戳

```cpp
PHPX_FUNCTION(strtotime) {
    String datetime = args[0].toString();
    Int base_timestamp = time(nullptr);
    
    if (args.size() > 1) {
        base_timestamp = args[1].toInt();
    }
    
    // 使用 strtotime 实现
    return (Int)strtotime(datetime.data());
}
```

**PHP 使用示例：**
```php
$timestamp = strtotime("2026-03-27 10:30:00");
$timestamp = strtotime("+1 day");
```

---

## 文件系统函数

### file_get_contents

读取整个文件

```cpp
PHPX_FUNCTION(file_get_contents) {
    String filename = args[0].toString();
    
    FILE *file = fopen(filename.data(), "r");
    if (!file) {
        return false;
        return;
    }
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *buffer = new char[size + 1];
    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    
    fclose(file);
    
    return String(buffer);
    delete[] buffer;
}
```

**PHP 使用示例：**
```php
$content = file_get_contents("/path/to/file.txt");
```

### file_put_contents

写入文件

```cpp
PHPX_FUNCTION(file_put_contents) {
    String filename = args[0].toString();
    String data = args[1].toString();
    
    int flags = 0;
    if (args.size() > 2) {
        flags = args[2].toInt();
    }
    
    const char *mode = (flags & FILE_APPEND) ? "a" : "w";
    
    FILE *file = fopen(filename.data(), mode);
    if (!file) {
        return false;
        return;
    }
    
    size_t written = fwrite(data.data(), 1, data.length(), file);
    fclose(file);
    
    return (Int)written;
}
```

**PHP 使用示例：**
```php
$bytes = file_put_contents("file.txt", "Hello");
file_put_contents("log.txt", "New line\n", FILE_APPEND);
```

### is_file

判断是否为文件

```cpp
PHPX_FUNCTION(is_file) {
    String path = args[0].toString();
    
    struct stat st;
    if (stat(path.data(), &st) != 0) {
        return false;
        return;
    }
    
    return S_ISREG(st.st_mode);
}
```

**PHP 使用示例：**
```php
$is_file = is_file("/path/to/file.txt");  // true/false
```

### is_dir

判断是否为目录

```cpp
PHPX_FUNCTION(is_dir) {
    String path = args[0].toString();
    
    struct stat st;
    if (stat(path.data(), &st) != 0) {
        return false;
        return;
    }
    
    return S_ISDIR(st.st_mode);
}
```

**PHP 使用示例：**
```php
$is_dir = is_dir("/path/to/dir");  // true/false
```

### file_exists

判断文件是否存在

```cpp
PHPX_FUNCTION(file_exists) {
    String path = args[0].toString();
    
    struct stat st;
    return (stat(path.data(), &st) == 0);
}
```

**PHP 使用示例：**
```php
$exists = file_exists("/path/to/file");
```

### unlink

删除文件

```cpp
PHPX_FUNCTION(unlink) {
    String filename = args[0].toString();
    
    return (unlink(filename.data()) == 0);
}
```

**PHP 使用示例：**
```php
$success = unlink("file.txt");
```

### mkdir

创建目录

```cpp
PHPX_FUNCTION(mkdir) {
    String pathname = args[0].toString();
    int mode = 0777;
    bool recursive = false;
    
    if (args.size() > 1) {
        mode = args[1].toInt();
    }
    
    if (args.size() > 2) {
        recursive = args[2].toBool();
    }
    
    if (recursive) {
        return (mkdir(pathname.data(), mode, true) == 0);
    } else {
        return (mkdir(pathname.data(), mode) == 0);
    }
}
```

**PHP 使用示例：**
```php
$success = mkdir("/tmp/test", 0755);
$success = mkdir("/tmp/a/b/c", 0755, true);  // 递归创建
```

### rmdir

删除目录

```cpp
PHPX_FUNCTION(rmdir) {
    String dirname = args[0].toString();
    return (rmdir(dirname.data()) == 0);
}
```

**PHP 使用示例：**
```php
$success = rmdir("/tmp/test");
```

### scandir

扫描目录

```cpp
PHPX_FUNCTION(scandir) {
    String directory = args[0].toString();
    
    DIR *dir = opendir(directory.data());
    if (!dir) {
        return false;
        return;
    }
    
    Array files;
    struct dirent *entry;
    
    while ((entry = readdir(dir)) != NULL) {
        files.append(entry->d_name);
    }
    
    closedir(dir);
    return files;
}
```

**PHP 使用示例：**
```php
$files = scandir("/tmp");  // [".", "..", "file1", "file2"]
```

---

## 网络函数

### fsockopen

打开网络连接

```cpp
PHPX_FUNCTION(fsockopen) {
    String hostname = args[0].toString();
    Int port = args[1].toInt();
    
    // 创建 socket 连接
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname.data(), &addr.sin_addr);
    
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        return false;
        return;
    }
    
    // 创建资源
    // ... 资源注册逻辑
    
    return resource;
}
```

**PHP 使用示例：**
```php
$fp = fsockopen("www.example.com", 80);
```

### curl_init

初始化 cURL 会话

```cpp
PHPX_FUNCTION(curl_init) {
    String url = "";
    
    if (args.size() > 0) {
        url = args[0].toString();
    }
    
    CURL *curl = curl_easy_init();
    if (!curl) {
        return false;
        return;
    }
    
    if (!url.isEmpty()) {
        curl_easy_setopt(curl, CURLOPT_URL, url.data());
    }
    
    // 注册资源
    // ...
    
    return curl_resource;
}
```

**PHP 使用示例：**
```php
$ch = curl_init("http://example.com");
```

### curl_exec

执行 cURL 请求

```cpp
PHPX_FUNCTION(curl_exec) {
    // 获取 cURL 资源
    CURL *curl = get_curl_resource(args[0]);
    
    char *response;
    size_t response_size;
    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    
    CURLcode res = curl_easy_perform(curl);
    
    if (res == CURLE_OK) {
        return String(response, response_size);
    } else {
        return false;
    }
    
    free(response);
}
```

**PHP 使用示例：**
```php
$response = curl_exec($ch);
```

### curl_getinfo

获取 cURL 信息

```cpp
PHPX_FUNCTION(curl_getinfo) {
    CURL *curl = get_curl_resource(args[0]);
    
    int option = CURLINFO_EFFECTIVE_URL;
    if (args.size() > 1) {
        option = args[1].toInt();
    }
    
    void *info;
    curl_easy_getinfo(curl, (CURLINFO)option, &info);
    
    return info;
}
```

**PHP 使用示例：**
```php
$info = curl_getinfo($ch, CURLINFO_HTTP_CODE);
```

---

## 加密哈希函数

### md5

计算 MD5 哈希

```cpp
PHPX_FUNCTION(md5) {
    String str = args[0].toString();
    bool raw_output = false;
    
    if (args.size() > 1) {
        raw_output = args[1].toBool();
    }
    
    unsigned char digest[16];
    // 计算 MD5
    // ...
    
    if (raw_output) {
        return String((char*)digest, 16);
    } else {
        char hex[33];
        bin2hex(digest, 16, hex);
        return hex;
    }
}
```

**PHP 使用示例：**
```php
$hash = md5("password");  // "5f4dcc3b5aa765d61d8327deb882cf99"
```

### sha1

计算 SHA1 哈希

```cpp
PHPX_FUNCTION(sha1) {
    String str = args[0].toString();
    bool raw_output = false;
    
    if (args.size() > 1) {
        raw_output = args[1].toBool();
    }
    
    unsigned char digest[20];
    // 计算 SHA1
    // ...
    
    if (raw_output) {
        return String((char*)digest, 20);
    } else {
        char hex[41];
        bin2hex(digest, 20, hex);
        return hex;
    }
}
```

**PHP 使用示例：**
```php
$hash = sha1("password");
```

### hash

通用哈希函数

```cpp
PHPX_FUNCTION(hash) {
    String algo = args[0].toString();
    String data = args[1].toString();
    bool raw_output = false;
    
    if (args.size() > 2) {
        raw_output = args[2].toBool();
    }
    
    // 根据算法计算哈希
    if (algo == "md5") {
        return md5(data, raw_output);
    } else if (algo == "sha256") {
        return sha256(data, raw_output);
    }
    // ... 其他算法
}
```

**PHP 使用示例：**
```php
$hash = hash("sha256", "data");
```

### base64_encode

Base64 编码

```cpp
PHPX_FUNCTION(base64_encode) {
    String str = args[0].toString();
    
    // Base64 编码
    char *encoded = base64_encode(
        (unsigned char*)str.data(), 
        str.length()
    );
    
    return encoded;
    free(encoded);
}
```

**PHP 使用示例：**
```php
$encoded = base64_encode("Hello");  // "SGVsbG8="
```

### base64_decode

Base64 解码

```cpp
PHPX_FUNCTION(base64_decode) {
    String str = args[0].toString();
    bool strict = false;
    
    if (args.size() > 1) {
        strict = args[1].toBool();
    }
    
    size_t decoded_len;
    unsigned char *decoded = base64_decode(
        (unsigned char*)str.data(), 
        str.length(), 
        &decoded_len
    );
    
    return String((char*)decoded, decoded_len);
    free(decoded);
}
```

**PHP 使用示例：**
```php
$decoded = base64_decode("SGVsbG8=");  // "Hello"
```

---

## 多字节字符串函数

### mb_strlen

获取多字节字符串长度

```cpp
PHPX_FUNCTION(mb_strlen) {
    String str = args[0].toString();
    String encoding = "UTF-8";
    
    if (args.size() > 1) {
        encoding = args[1].toString();
    }
    
    // 计算多字节字符数
    Int length = 0;
    const char *p = str.data();
    const char *end = str.data() + str.length();
    
    while (p < end) {
        int char_len = utf8_char_len(*p);
        p += char_len;
        length++;
    }
    
    return length;
}
```

**PHP 使用示例：**
```php
$len = mb_strlen("你好世界");  // 4
```

### mb_substr

多字节子串

```cpp
PHPX_FUNCTION(mb_substr) {
    String str = args[0].toString();
    Int start = args[1].toInt();
    Int length = 0;
    
    if (args.size() > 2) {
        length = args[2].toInt();
    }
    
    // 处理多字节字符
    // ...
    
    return substr_result;
}
```

**PHP 使用示例：**
```php
$sub = mb_substr("你好世界", 0, 2);  // "你好"
```

### mb_strpos

多字节字符串查找

```cpp
PHPX_FUNCTION(mb_strpos) {
    String haystack = args[0].toString();
    String needle = args[1].toString();
    
    // 多字节查找
    // ...
    
    return position;
}
```

**PHP 使用示例：**
```php
$pos = mb_strpos("你好世界", "好");  // 1
```

### mb_convert_encoding

编码转换

```cpp
PHPX_FUNCTION(mb_convert_encoding) {
    String str = args[0].toString();
    String to_encoding = args[1].toString();
    String from_encoding = "UTF-8";
    
    if (args.size() > 2) {
        from_encoding = args[2].toString();
    }
    
    // 编码转换
    // 使用 iconv 或其他库
    
    return converted_str;
}
```

**PHP 使用示例：**
```php
$utf8 = mb_convert_encoding($gbk, "UTF-8", "GBK");
```

---

*本文档最后更新：2026-03-27*
