## Require

* `PHP-X`
* `PHP >= 7.2`

## 安装使用

```bash
cmake -S . -B build
cmake --build build -j 4
sudo cmake --install build

php ../run-tests.php tests
```
