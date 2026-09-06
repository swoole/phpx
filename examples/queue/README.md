## Require

* `PHP-X`
* `PHP 8.4` or `PHP 8.5`

## 安装使用

```bash
cmake -S . -B build
cmake --build build -j 4
sudo cmake --install build

php run-tests.php tests
```
