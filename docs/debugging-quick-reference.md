# 调试快速参考

## 快速开始

### Windows

```powershell
# 1. 配置 Debug 模式
cmake -DCMAKE_BUILD_TYPE=Debug .

# 2. 编译
cmake --build . --config Debug

# 3. 运行测试
.\bin\Debug\phpx-tests.exe

# 4. 使用 Visual Studio 调试
# 打开生成的 .sln 文件，按 F5 调试
```

### Linux/macOS

```bash
# 1. 配置 Debug 模式
cmake -DCMAKE_BUILD_TYPE=Debug .

# 2. 编译
make -j 4

# 3. 运行测试
./bin/phpx-tests

# 4. 使用 GDB 调试
gdb ./bin/phpx-tests
```

---

## 常用调试命令

### CMake 配置

```bash
# Debug 模式（包含调试符号）
cmake -DCMAKE_BUILD_TYPE=Debug .

# Release 模式（优化，用于发布）
cmake -DCMAKE_BUILD_TYPE=Release .

# RelWithDebInfo 模式（优化 + 调试符号）
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .

# 清理构建
cmake --build . --target clean
rm -rf CMakeCache.txt CMakeFiles/
```

### 编译

```bash
# 标准编译
make -j 4

# 详细输出（查看编译命令）
make VERBOSE=1

# 只编译测试
make phpx-tests

# 只编译库
make phpx
```

### 运行测试

```bash
# 运行所有测试
./bin/phpx-tests

# 运行特定测试套件
./bin/phpx-tests --gtest_filter="base.*"

# 运行单个测试
./bin/phpx-tests --gtest_filter="base.error"

# 列出所有测试
./bin/phpx-tests --gtest_list_tests

# XML 输出（用于 CI）
./bin/phpx-tests --gtest_output=xml:test_results.xml
```

---

## GDB 调试

### 基本命令

```bash
# 启动 GDB
gdb ./bin/phpx-tests

# 运行程序
(gdb) run

# 设置断点
(gdb) break main.cpp:42
(gdb) break function_name

# 条件断点
(gdb) break main.cpp:42 if x > 10

# 继续执行
(gdb) continue

# 单步执行
(gdb) next          # 跳过函数调用
(gdb) step          # 进入函数调用
(gdb) finish        # 完成当前函数

# 查看变量
(gdb) print variable_name
(gdb) info locals   # 查看所有局部变量
(gdb) info args     # 查看函数参数

# 查看调用堆栈
(gdb) bt            # backtrace
(gdb) frame 0       # 选择栈帧

# 检查内存
(gdb) x/10x ptr     # 查看指针指向的内存

# 退出
(gdb) quit
```

### GDB 高级用法

```bash
# 核心文件调试
gdb ./bin/phpx-tests core.dump

# 附加到运行中的进程
gdb -p <pid>

# 自动执行命令
echo "bt" > commands.txt
gdb -batch -x commands.txt ./bin/phpx-tests
```

---

## Valgrind 内存检查

```bash
# 基本内存检查
valgrind ./bin/phpx-tests

# 详细的泄漏检查
valgrind --leak-check=full ./bin/phpx-tests

# 最详细的检查
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./bin/phpx-tests

# 生成日志文件
valgrind --leak-check=full \
         --log-file=valgrind.log \
         ./bin/phpx-tests

# 只检查特定测试
valgrind --leak-check=full \
         ./bin/phpx-tests --gtest_filter="array.*"
```

### Valgrind 输出解读

```
==12345== 100 bytes in 1 blocks are definitely lost
==12345==    at 0x4C2DB8F: malloc (vg_replace_malloc.c:299)
==12345==    by 0x401234: my_function (main.cpp:42)
==12345==    by 0x401567: main (main.cpp:100)
```

**泄漏类型：**
- `definitely lost` - 明确的内存泄漏（需要修复）
- `indirectly lost` - 间接泄漏（由直接泄漏引起）
- `possibly lost` - 可能的泄漏（需要检查）
- `still reachable` - 程序结束时仍可访问（通常不是问题）

---

## AddressSanitizer (ASAN)

```bash
# 启用 ASAN
cmake -Denable_asan=ON .
make clean && make

# 运行（会自动检测内存错误）
./bin/phpx-tests

# 设置 ASAN 选项
export ASAN_OPTIONS=detect_leaks=1:abort_on_error=1
./bin/phpx-tests
```

### ASAN 检测的错误类型

- 堆缓冲区溢出
- 栈缓冲区溢出
- 全局缓冲区溢出
- 释放后使用 (use-after-free)
- 返回后使用 (use-after-return)
- 内存泄漏（如果启用）

---

## Visual Studio 调试

### 配置项目

```powershell
# 生成 Visual Studio 解决方案
cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug .

# 打开解决方案
phpx.sln
```

### 调试步骤

1. **设置断点**
   - 点击代码行号左侧
   - 或按 F9

2. **启动调试**
   - 按 F5
   - 或点击"调试" -> "开始调试"

3. **调试控制**
   - F10: 单步跳过
   - F11: 单步进入
   - Shift+F11: 跳出函数
   - F5: 继续

4. **查看变量**
   - 鼠标悬停在变量上
   - 或使用"监视"窗口

5. **查看调用堆栈**
   - "调试" -> "窗口" -> "调用堆栈"

### 加载符号

确保 `.dll` 和 `.pdb` 文件在同一目录：
```
bin/Debug/
├── phpx.dll
├── phpx.pdb      # 调试符号
├── phpx-tests.exe
└── phpx-tests.pdb
```

---

## 常见问题排查

### 段错误 (Segmentation Fault)

```bash
# 1. 使用 GDB 定位
gdb ./bin/phpx-tests
(gdb) run
# 崩溃后
(gdb) bt

# 2. 启用 ASAN
cmake -Denable_asan=ON .
make clean && make
./bin/phpx-tests
```

### 内存泄漏

```bash
# 使用 Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./bin/phpx-tests

# 查看泄漏摘要
valgrind --leak-check=full 2>&1 | grep "lost"
```

### 编译错误

```bash
# 查看详细编译命令
make VERBOSE=1

# 清理重新编译
make clean
rm -rf CMakeCache.txt CMakeFiles/
cmake .
make
```

### PHP 扩展加载失败

```bash
# 检查依赖
ldd phpx.so          # Linux
otool -L phpx.so     # macOS
dumpbin /dependents phpx.dll  # Windows

# 查看详细错误
php -d display_errors=1 -m | grep phpx
```

---

## 调试宏定义

在代码中使用条件编译：

```cpp
#ifdef DEBUG
    // 仅在 Debug 模式下编译
    std::cerr << "[DEBUG] Variable value: " << x << std::endl;
#endif

// 或者使用自定义宏
#if defined(DEBUG) && DEBUG >= 1
    // 调试级别 1
#endif

#if defined(DEBUG) && DEBUG >= 2
    // 调试级别 2（更详细）
#endif
```

---

## 性能分析

### Linux (perf)

```bash
# 记录性能数据
perf record -g ./bin/phpx-tests

# 查看报告
perf report

# 生成火焰图
perf script | stackcollapse-perf.pl | flamegraph.pl > flame.svg
```

### macOS (Instruments)

```bash
# 使用时间分析器
instruments -t "Time Profiler" ./bin/phpx-tests

# 使用内存分析器
instruments -t "Allocations" ./bin/phpx-tests
```

---

## 有用的环境变量

```bash
# GDB
export GDBHISTFILE=~/.gdb_history

# Valgrind
export VALGRIND_OPTS="--leak-check=full"

# ASAN
export ASAN_OPTIONS=detect_leaks=1:abort_on_error=1:print_stats=1

# PHP
export PHP_INI_SCAN_DIR=/path/to/custom/ini
```

---

## 快速诊断流程

### 程序崩溃

1. ✅ 使用 Debug 模式重新编译
2. ✅ 用 GDB 运行，获取堆栈跟踪
3. ✅ 检查崩溃位置的变量值
4. ✅ 启用 ASAN 检测内存错误
5. ✅ 修复问题并验证

### 内存泄漏

1. ✅ 使用 Valgrind 运行程序
2. ✅ 识别泄漏类型和位置
3. ✅ 检查资源管理代码
4. ✅ 添加适当的释放逻辑
5. ✅ 重新运行 Valgrind 验证修复

### 未定义行为

1. ✅ 启用 UBSAN (`-fsanitize=undefined`)
2. ✅ 运行测试套件
3. ✅ 查看 UBSAN 报告
4. ✅ 修复未定义行为
5. ✅ 重新测试

---

*本文档最后更新：2026-04-30*
