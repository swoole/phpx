# 编译调试信息功能说明

## 概述

本次更新为 PHPX 项目添加了完整的调试支持，方便在开发和排查问题时使用。

## 主要改进

### 1. CMakeLists.txt 增强

#### Debug 模式配置
- ✅ Windows 平台：`/Zi` (调试符号), `/Od` (禁用优化), `/RTC1` (运行时检查)
- ✅ Linux/macOS 平台：`-g` (调试符号), `-O0` (禁用优化), `-DDEBUG=1`
- ✅ 自动生成 PDB 文件 (Windows) 或 DWARF 信息 (Linux/macOS)

#### 详细编译输出
- ✅ Windows Debug 模式下启用 `/showIncludes` 显示头文件包含信息
- ✅ 配置摘要中显示详细的调试模式信息

### 2. 文档更新

#### 新增文档
1. **debugging-guide.md** - 完整的调试指南
   - 如何启用 Debug 模式
   - 各平台调试工具使用说明
   - 常见问题排查方法
   - 调试技巧和最佳实践

2. **debugging-quick-reference.md** - 调试快速参考
   - 常用调试命令速查
   - GDB/Valgrind/ASAN 使用方法
   - 问题诊断流程

3. **README.md** - 添加 Debug 模式说明
   - 快速开始部分增加 Debug 构建说明
   - Debug 模式特性列表

4. **testing-guide.md** - 更新测试指南
   - 添加 Debug 模式编译说明
   - Debug 模式优势说明

5. **docs/README.md** - 更新文档索引
   - 添加调试相关文档链接

#### 示例代码
- **examples/test/debug_example.cpp** - 调试功能示例
  - 条件编译调试输出
  - 断言使用
  - 资源跟踪
  - 性能计时
  - 调试宏定义

### 3. 构建脚本

#### Windows (debug-build.bat)
交互式批处理脚本，支持：
- Debug 模式构建
- Release 模式构建
- RelWithDebInfo 模式构建
- 清理构建文件

#### Linux/macOS (debug-build.sh)
交互式 shell 脚本，支持：
- Debug 模式构建
- Release 模式构建
- RelWithDebInfo 模式构建
- AddressSanitizer 构建
- 清理构建文件

## 使用方法

### 方法 1: 使用构建脚本（推荐）

**Windows:**
```powershell
.\debug-build.bat
# 选择选项 1 (Debug)
```

**Linux/macOS:**
```bash
chmod +x debug-build.sh
./debug-build.sh
# 选择选项 1 (Debug)
```

### 方法 2: 手动配置

**Windows:**
```powershell
cmake -DCMAKE_BUILD_TYPE=Debug .
cmake --build . --config Debug
```

**Linux/macOS:**
```bash
cmake -DCMAKE_BUILD_TYPE=Debug .
make -j 4
```

### 方法 3: 使用 IDE

**Visual Studio:**
```powershell
cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Debug .
# 打开生成的 .sln 文件
# 选择 Debug 配置
# 按 F5 调试
```

## Debug 模式特性

### 通用特性
- ✅ 完整的调试符号（支持断点调试和堆栈跟踪）
- ✅ 禁用编译器优化（变量值可见，代码执行顺序一致）
- ✅ 详细的编译输出信息

### Windows 特有
- ✅ 运行时错误检查 (`/RTC1`)
  - 检测未初始化的变量
  - 检测栈帧损坏
  - 检测整数溢出
- ✅ 显示头文件包含信息 (`/showIncludes`)
- ✅ 生成 PDB 文件（用于 Visual Studio 调试）

### Linux/macOS 特有
- ✅ GCC/GDB 完整调试支持
- ✅ Valgrind 内存检查支持
- ✅ AddressSanitizer 支持
- ✅ 定义 DEBUG 宏（可用于条件编译）

## 调试工具

### GDB (Linux/macOS)
```bash
gdb ./bin/phpx-tests
(gdb) run
(gdb) bt          # 查看堆栈
(gdb) print var   # 查看变量
```

### Visual Studio (Windows)
1. 打开 .sln 文件
2. 设置断点
3. 按 F5 调试
4. 查看调用堆栈和变量

### Valgrind (Linux/macOS)
```bash
valgrind --leak-check=full ./bin/phpx-tests
```

### AddressSanitizer
```bash
cmake -Denable_asan=ON -DCMAKE_BUILD_TYPE=Debug .
make
./bin/phpx-tests  # ASAN 自动检测内存错误
```

## 常见问题排查

### 段错误
```bash
# 1. 使用 Debug 模式重新编译
cmake -DCMAKE_BUILD_TYPE=Debug .
make

# 2. 用 GDB 定位
gdb ./bin/phpx-tests
(gdb) run
(gdb) bt
```

### 内存泄漏
```bash
# 使用 Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./bin/phpx-tests
```

### 未定义行为
```bash
# 启用 UBSAN
cmake -DCMAKE_CXX_FLAGS="-fsanitize=undefined" .
make
./bin/phpx-tests
```

## 代码中的调试技巧

### 条件编译
```cpp
#ifdef DEBUG
    std::cerr << "[DEBUG] Variable value: " << x << std::endl;
#endif
```

### 断言
```cpp
#include <cassert>
assert(pointer != nullptr);
assert(size > 0);
```

### 自定义调试宏
```cpp
#define DEBUG_LOG(msg) \
    do { \
        #ifdef DEBUG \
        std::cerr << "[DEBUG] " << __FILE__ << ":" << __LINE__ \
                  << ": " << msg << std::endl; \
        #endif \
    } while(0)
```

## 性能考虑

- **Debug 模式**: 适合开发和调试，但性能较低
- **Release 模式**: 适合生产环境，性能最优
- **RelWithDebInfo**: 平衡性能和调试能力

建议在开发过程中使用 Debug 模式，发布前切换到 Release 模式。

## 相关文件

- `CMakeLists.txt` - 构建配置
- `debug-build.bat` - Windows 构建脚本
- `debug-build.sh` - Linux/macOS 构建脚本
- `docs/debugging-guide.md` - 详细调试指南
- `docs/debugging-quick-reference.md` - 快速参考
- `examples/test/debug_example.cpp` - 调试示例代码

## 下一步

1. 尝试使用 Debug 模式编译项目
2. 阅读调试指南了解更多信息
3. 在代码中添加调试输出和断言
4. 使用调试工具排查问题

---

*文档创建时间：2026-04-30*
