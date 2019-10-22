# BloomFilter
基于共享内存的 `BloomFilter` 库。

* 部分代码借鉴自 <https://github.com/armon/bloomd> 项目
* 参考资料
  * <https://my.oschina.net/kiwivip/blog/133498>
  * <http://blog.csdn.net/jiaomeng/article/details/1495500>
  * <http://blog.csdn.net/hguisu/article/details/7866173>

## Require

* `SWOOLE`
* `PHP-X`
* `PHP >= 7.0`

## 安装使用

```bash
make && make install
```

到`php.ini`添加`extension=BloomFilter.so`

## 示例

```php
<?php
$b = new BloomFilter(1024);
echo "key hello\n";
$b->add("hello");
$b->add("world");
$b->add("rango");
var_dump($b->has("test"));
var_dump($b->has("hello"));
var_dump($b->has("world"));
var_dump($b->has(" world "));
var_dump($b->has("rango"));
var_dump($b->has("xxxxxxxxxxxxxxxxxxxxxxx"));
var_dump($b->has("rango12"));
var_dump($b->has("me"));
$b->dump(__DIR__."/bf.data");
```
