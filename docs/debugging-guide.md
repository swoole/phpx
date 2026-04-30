# 调试指南

本文档介绍如何在 PHPX 项目中启用和使用调试功能来排查问题。

## 目录

- [启用 Debug 模式](#启用-debug-模式)
- [Debug 模式特性](#debug-模式特性)
- [Windows 平台调试](#windows-平台调试)
- [Linux/macOS 平台调试](#linuxmacos-平台调试)
- [常见问题排查](#常见问题排查)

---

## 启用 Debug 模式

### 方法 1: CMake 命令行参数

```bash
# 清理之前的构建
cmake --build . --target clean

# 配置 Debug 模式
cmake -DCMAKE_BUILD_TYPE=Debug .

# 编译
make -j 4
```

### 方法 2: 修改 CMakeLists.txt（不推荐）

在 `CMakeLists.txt` 开头添加：
```cmake
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
```

### 验证 Debug 模式已启用

编译时会看到以下输出：
```
-- Building in Debug mode with debug symbols
-- Debug Mode: Enabled with debug symbols and runtime checks
```

---

## Debug 模式特性

### 通用特性（所有平台）

1. **完整的调试符号**
   - 生成 `.pdb` (Windows) 或 DWARF (Linux/macOS) 调试信息
   - 支持断点调试和堆栈跟踪

2. **禁用优化**
   - `-O0` (Linux/macOS) 或 `/Od` (Windows)
   - 变量值在调试器中可见
   - 代码执行顺序与源代码一致

3. **详细的编译输出**
   - 显示包含的头文件路径
   - 更容易发现头文件依赖问题

### Windows 平台特有

1. **运行时错误检查 (/RTC1)**
   - 检测未初始化的变量
   - 检测栈帧损坏
   - 检测整数溢出

2. **显示头文件包含 (/showIncludes)**
   ```
   注意: 包含文件:  D:\workspace\phpx\include\phpx.h
   注意: 包含文件:  D:\workspace\phpx\include\phpx_types.h
   ...
   ```

3. **生成 PDB 文件**
   - `phpx.pdb` - 用于 Visual Studio 调试
   - `phpx-tests.pdb` - 测试程序调试符号

### Linux/macOS 平台特有

1. **GCC/GDB 调试支持**
   - 完整的 DWARF 调试信息
   - 支持 valgrind 内存检查

2. **定义 DEBUG 宏**
   ```cpp
   #ifdef DEBUG
       // 调试专用代码
   #endif
   ```

---

## Windows 平台调试

### 使用 Visual Studio 调试

1. **打开项目**
   ```bash
   cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug .
   ```

2. **加载 PDB 文件**
   - Visual Studio 会自动加载同目录下的 `.pdb` 文件
   - 确保 `.dll` 和 `.pdb` 在同一目录

3. **设置断点**
   - 在源代码中点击行号左侧设置断点
   - 按 F5 开始调试

4. **查看调用堆栈**
   - 崩溃时自动显示调用堆栈
   - 可以查看每个栈帧的局部变量

### 使用 GDB (MinGW)

```bash
# 启动 GDB
gdb bin/phpx-tests.exe

# 运行测试
(gdb) run --gtest_filter="base.error"

# 如果崩溃，查看堆栈
(gdb) bt

# 查看变量
(gdb) print variable_name

# 单步执行
(gdb) next
(gdb) step
```

### 运行时错误检查示例

当启用 `/RTC1` 时，以下错误会被捕获：

```cpp
// 错误：未初始化的变量
int x;
if (x > 0) {  // RTC1 会检测到 x 未初始化
    // ...
}

// 错误：栈缓冲区溢出
char buffer[10];
strcpy(buffer, "this string is too long");  // RTC1 会检测到溢出
```

---

## Linux/macOS 平台调试

### 使用 GDB

```bash
# 启动 GDB
gdb ./bin/phpx-tests

# 运行
(gdb) run

# 设置断点
(gdb) break main.cpp:42

# 查看变量
(gdb) print my_variable

# 单步执行
(gdb) next      # 跳过函数调用
(gdb) step      # 进入函数调用

# 查看调用堆栈
(gdb) bt

# 继续执行
(gdb) continue
```

### 使用 Valgrind 检查内存问题

```bash
# 安装 Valgrind
sudo apt-get install valgrind  # Ubuntu/Debian
brew install valgrind          # macOS

# 检查内存泄漏
valgrind --leak-check=full ./bin/phpx-tests

# 详细输出
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/phpx-tests

# 生成报告
valgrind --leak-check=full --log-file=valgrind.log ./bin/phpx-tests
```

### 使用 AddressSanitizer (ASAN)

```bash
# 配置时启用 ASAN
cmake -Denable_asan=ON .

# 编译
make -j 4

# 运行（ASAN 会自动检测内存错误）
./bin/phpx-tests
```

ASAN 可以检测：
- 堆缓冲区溢出
- 栈缓冲区溢出
- 全局缓冲区溢出
- 释放后使用 (use-after-free)
- 返回后使用 (use-after-return)

---

## 常见问题排查

### 问题 1: 段错误 (Segmentation Fault)

**症状：**
```
Segmentation fault (core dumped)
```

**排查步骤：**

1. **使用 GDB 定位崩溃位置**
   ```bash
   gdb ./bin/phpx-tests
   (gdb) run
   # 崩溃后
   (gdb) bt
   ```

2. **查看崩溃时的变量值**
   ```bash
   (gdb) frame 0        # 选择最内层栈帧
   (gdb) info locals    # 查看局部变量
   (gdb) print ptr      # 查看指针值
   ```

3. **启用 ASAN 重新编译**
   ```bash
   cmake -Denable_asan=ON .
   make clean && make
   ./bin/phpx-tests
   ```

### 问题 2: 内存泄漏

**症状：**
- 程序运行时间越长，内存占用越高
- Valgrind 报告内存泄漏

**排查步骤：**

1. **使用 Valgrind 检查**
   ```bash
   valgrind --leak-check=full --show-leak-kinds=all ./bin/phpx-tests
   ```

2. **查看泄漏报告**
   ```
   ==12345== 100 bytes in 1 blocks are definitely lost
   ==12345==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
   ==12345==    by 0x401234: my_function (main.cpp:42)
   ```

3. **修复泄漏**
   - 确保每个 `malloc/new` 都有对应的 `free/delete`
   - 使用智能指针管理资源
   - 检查循环中的内存分配

### 问题 3: 未定义行为

**症状：**
- 程序行为不一致
- 不同编译器结果不同
- Release 模式正常，Debug 模式异常

**排查步骤：**

1. **启用 UndefinedBehaviorSanitizer (UBSAN)**
   ```bash
   cmake -DCMAKE_CXX_FLAGS="-fsanitize=undefined" .
   make clean && make
   ./bin/phpx-tests
   ```

2. **常见未定义行为**
   - 有符号整数溢出
   - 空指针解引用
   - 数组越界访问
   - 类型双关 (type punning)

### 问题 4: 编译警告

**症状：**
- 大量编译警告
- 某些警告可能隐藏真正的问题

**解决方法：**

1. **查看所有警告**
   ```bash
   # Debug 模式下会显示更多警告
   cmake -DCMAKE_BUILD_TYPE=Debug .
   make VERBOSE=1
   ```

2. **修复常见警告**
   - 未使用的变量：删除或标记为 `[[maybe_unused]]`
   - 类型转换警告：使用显式类型转换
   - 未初始化变量：始终初始化变量

### 问题 5: PHP 扩展加载失败

**症状：**
```
PHP Warning: PHP Startup: Unable to load dynamic library 'phpx.so'
```

**排查步骤：**

1. **检查依赖库**
   ```bash
   # Linux
   ldd phpx.so
   
   # macOS
   otool -L phpx.so
   
   # Windows
   dumpbin /dependents phpx.dll
   ```

2. **检查符号导出**
   ```bash
   # Linux
   nm -D phpx.so | grep "T "
   
   # Windows
   dumpbin /exports phpx.dll
   ```

3. **查看详细错误信息**
   ```bash
   php -d display_startup_errors=1 -d display_errors=1 -m | grep phpx
   ```

---

## 调试技巧

### 1. 添加日志输出

```cpp
#include <iostream>

void my_function() {
    #ifdef DEBUG
    std::cerr << "[DEBUG] Entering my_function" << std::endl;
    #endif
    
    // 函数逻辑
    
    #ifdef DEBUG
    std::cerr << "[DEBUG] Exiting my_function" << std::endl;
    #endif
}
```

### 2. 使用断言

```cpp
#include <cassert>

void process_data(int* data, int size) {
    assert(data != nullptr);  // 检查指针有效性
    assert(size > 0);         // 检查参数范围
    
    // 处理数据
}
```

### 3. 条件编译调试代码

```cpp
#ifdef DEBUG
#define DEBUG_LOG(msg) std::cerr << "[DEBUG] " << msg << std::endl
#else
#define DEBUG_LOG(msg)
#endif

void my_function() {
    DEBUG_LOG("Function called");
    // ...
}
```

### 4. 性能分析

```bash
# Linux: 使用 perf
perf record ./bin/phpx-tests
perf report

# macOS: 使用 Instruments
instruments -t "Time Profiler" ./bin/phpx-tests
```

---

## 最佳实践

1. **开发时使用 Debug 模式**
   - 更容易发现问题
   - 更好的调试体验

2. **发布前切换到 Release 模式**
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Release .
   make clean && make
   ```

3. **定期运行内存检查**
   ```bash
   valgrind --leak-check=full ./bin/phpx-tests
   ```

4. **保持调试符号**
   - 不要剥离 Release 版本的符号（除非需要减小文件大小）
   - 保留 PDB/DWARF 文件用于事后调试

5. **使用版本控制**
   - 提交能复现问题的最小代码
   - 记录调试过程和解决方案

---

## 相关文档

- [测试指南](testing-guide.md) - 如何编写和运行测试
- [架构文档](architecture.md) - 项目架构说明
- [最佳实践](best-practices.md) - 开发最佳实践

---

*本文档最后更新：2026-04-30*
